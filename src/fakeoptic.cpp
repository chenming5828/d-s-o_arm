#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <semaphore.h>
#include <errno.h>
#include <string.h>
#include <map>
#include <mutex>
#include <thread>
#include <queue>

#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <Eigen/Core>


#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>


#include <sys/types.h>         
#include <sys/socket.h>
#include <netinet/in.h>


extern "C" {
#include "imgproc_balloon.h"
}

#include "FullSystem/FullSystem.h"
#include "util/settings.h"
#include "util/Undistort.h"

// #include "IOWrapper/Pangolin/PangolinDSOViewer.h"
#include "IOWrapper/OutputWrapper/SampleOutputWrapper.h"

// #include "sender_receiver.h"

#define QVGA
#ifdef VGA
static const int ROW = 640;
static const int COL = 480;
#endif
#ifdef QVGA
static const int ROW = 240;
static const int COL = 320;
#endif

#ifdef BIT10
static uint8_t image_cache[ROW*COL];
#endif

int frameID = 0;
struct frame_info {
    char *   data;
    int      size;
    uint64_t timestamp;
};


struct impr_data {
    struct impr_res        res_in;
    void *                 usrdata;
    impr_pfn_complete_cb_t comp_cb;
    impr_pfn_free_cb_t     free_cb;
    sem_t                  sem_event;
    std::thread *          work_thrd;
    bool                   bquit;
    // the following are C++ members, need to new and delete.
    std::queue<struct frame_info*> * input_queue; // to keep input buffers
    std::queue<struct frame_info*> * inner_queue; // to keep using buffers
};


//==================================================
static const int ev_min = 1;
volatile static int ev_max = 250;
static const int ev_default = 250;
static const int gain_min = 1;
static const int gain_max = 250;
static const int gain_default = 1;

static const int ev_times = 2;
static const int gain_times = 5;

static int ev = ev_default; //1~284 // 1~1010
static int gain = gain_default; //1~250

static int count = 0;
static int times = gain_times;

volatile static int msv; //mean_sample_value

volatile static int desired_msv = 100;
volatile static float kp_e_max = 0.25;
static float kp_e = 0.25;
volatile static float kp_g = 0.2;

volatile static bool ae_enabled = true;
volatile static bool shading_enabled = true;
volatile static bool show_points = true;
volatile static bool show_label = true;

cv::VideoWriter writer;


volatile static bool klt_enabled = true;
volatile static bool svo_enabled = true;
volatile static bool calibrated = false;



//=====================================dso=========================

using namespace dso;

std::string calib = "/mnt/persist/camera.txt";
std::string vignetteFile = "";
std::string gammaFile = "";
bool useSampleOutput=false;

static uint8_t dso_img_data[ROW*COL];
static uint8_t dso_data[ROW*COL];
static uint64_t dso_timestamp;
static sem_t dso_data_ready;
static std::thread *dso_thread = nullptr;
FullSystem* fullSystem = nullptr;
Undistort* undistorter = nullptr;
int frameID_dso = 0;
bool dso_done = true;

static std::thread *dso_send_thread = nullptr;
sem_t dso_send;
// std::queue< Eigen::Matrix<double,3,4> *>();

//=========================udp_thread=================================

static std::thread *udp_thread_rcv = nullptr;
static std::thread *udp_thread_snd = nullptr;
static bool udp_connected = false;
static struct sockaddr_in addr_client;
static socklen_t client_len;
static int sock_fd;
static sem_t sem_data_ready;
volatile static bool udp_ready = true;
static uint8_t udp_data[ROW*COL];
volatile static bool snap = false;
volatile static bool record = false;
volatile static int jpg_quality = 80;

static bool sender_running = false;

static uint64_t curr_time_ms() {
    struct timespec spec;
    clock_gettime(CLOCK_MONOTONIC, &spec);
    return spec.tv_sec * 1e3 + spec.tv_nsec / 1e6;
}

static uint64_t curr_time_us() {
    struct timespec spec;
    clock_gettime(CLOCK_MONOTONIC, &spec);
    return spec.tv_sec * 1e6 + spec.tv_nsec / 1e3;
}


static void do_image_processing(struct frame_info *finfo, struct impr_data *ip) {

    uint8_t *image_ptr;
#ifdef BIT10
    for(int i=0; i<ROW*COL; ++i) {
        image_cache[i] = (uint16_t *)finfo->data >> 2;
    }
    image_ptr = image_cache;
#else
    image_ptr = (uint8_t *)finfo->data;
#endif

    struct impr_cb_comp_data comp_data;
    memset(&comp_data,0,sizeof(impr_cb_comp_data));
    comp_data.type = IMPR_DT_COMP_OPTIC;
    //ev = ceil(ev/2);
    comp_data.u.optic.exposure_time = 250;
    comp_data.u.optic.gain = 100;
    ip->comp_cb(ip->usrdata, &comp_data); 

    memcpy(dso_img_data, image_ptr, ROW*COL);
    dso_timestamp = finfo->timestamp;
    // std::cout <<"|||||||||||||||||||||||||||||||do_image_processing|||||||||||||||||||||" << std::endl;
    sem_post(&dso_data_ready);

    if(udp_connected && udp_ready)
    {
        memcpy(udp_data, image_ptr, ROW*COL);
        sem_post(&sem_data_ready);
    }
}


static void image_udp_sender()
{

    while(sender_running) 
    {

//         udp_ready = true;
//         sem_wait(&sem_data_ready);
//         udp_ready = false;

//         cv::Mat img = cv::Mat(ROW, COL, CV_8UC1, udp_data);
//         cv::Mat colorFrame;
//         cv::cvtColor(img, colorFrame, CV_GRAY2BGR);


//     // std::cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n";
//     // std::cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n";
//     // std::cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n";
//         static int len = 0;



//         uchar *_data = NULL;

// #define COMPRESS
// #ifdef COMPRESS
//         // encode image to jpeg
//         std::vector<uchar> buff; //buffer for coding
//         std::vector<int> param(2);
//         param[0] = cv::IMWRITE_JPEG_QUALITY;
//         param[1] = jpg_quality; //default(95) 0-100
//         cv::imencode(".jpg", colorFrame, buff, param);
//         len = buff.size();
//         _data = buff.data();
//         //printf("airbee Image data size: %lu bytes (%d kB), origin size %d KB\n", buff.size(), (int) (buff.size() / 1024), ROW*COL/1024);
// #else
//         len = ROW * COL;
//         _data = colorFrame.data;
// #endif
//         char header[18];
//         memcpy(header, "HEADER", 6);
//         int h = ROW, w = COL;
//         memcpy(header+6, (char*)&len, 4);
//         memcpy(header+10, (char*)&w, 4);
//         memcpy(header+14, (char*)&h, 4);
//         int send_num = sendto(sock_fd, header, sizeof(header), 0, (struct sockaddr *)&addr_client, client_len);
//         int sent = 0;

//         while (sent < len) {
//             int block = (len - sent) < 1024 ? (len - sent) : 1024;
//             send_num = sendto(sock_fd, _data + sent, block, 0,
//                               (struct sockaddr *)&addr_client, client_len);
//             if(send_num < 0){
//                 perror("Airbee");
//                 printf("--Airbee: ERROR send udp failed\n");
//                 break;
//             }
//             sent += block;
//         }

//         usleep(50*1000);
    }
}

static void image_udp_receiver()
{
    struct sockaddr_in addr_serv;
    sock_fd = socket(AF_INET, SOCK_DGRAM, 0);

    if(sock_fd < 0) {
        printf("--Airbee ERROR image server socket init failed\n");
        return;
    }
    memset(&addr_serv, 0, sizeof(struct sockaddr_in));
    addr_serv.sin_family = AF_INET;
    addr_serv.sin_port = htons(20175);
    addr_serv.sin_addr.s_addr = htonl(INADDR_ANY);
    client_len = sizeof(struct sockaddr_in);
    if(bind(sock_fd, (struct sockaddr *)&addr_serv, sizeof(struct sockaddr_in)) < 0) {
        printf("--Airbee ERROR image server socket bink failed\n");
        close(sock_fd);
        return;
    }
    sem_init(&sem_data_ready, 0, 0);
    printf("--Airbee INFO image server ready\n");
    while(1) {
        char recv_buf[1024];
        int recv_num = recvfrom(sock_fd, recv_buf, sizeof(recv_buf), 0,
                                (struct sockaddr *)&addr_client, &client_len);
        if(recv_num < 0) {
            perror("Airbee");
            printf("--Airbee WARN image server recv error\n");
            continue;
        } else {
            recv_buf[recv_num] = '\0';
            printf("--Airbee DEBUG image client got message: %s\n", recv_buf);
            if(strcmp(recv_buf, "airbee") == 0) {
                sender_running = true;
                if(udp_thread_snd == NULL) {
                    udp_thread_snd = new std::thread(image_udp_sender);
                }
                printf("--Airbee INFO image client connected\n");
                udp_connected = true;
            } else if(strcmp(recv_buf, "disconnect") == 0) {
                sender_running = false;
                if(udp_thread_snd != NULL) {
                    sender_running = false;
                    udp_thread_snd->join();
                    udp_thread_snd = NULL;
                }
                printf("--Airbee INFO image client disconnected\n");
                udp_connected = false;
            } else if(strcmp(recv_buf, "snap") == 0) {
                snap = true;
            } else if(strcmp(recv_buf, "recon") == 0) {
                if(writer.isOpened()) {
                    writer.release();
                }
                static int n = 0;
                char name[128];
                sprintf(name, "/home/linaro/airbee_ae_%d_%llu.avi", n, curr_time_ms());
                writer.open(name, CV_FOURCC('M', 'J', 'P', 'G'), 20.0, cv::Size(COL, ROW));
                n++;
                record = true;
            } else if(strcmp(recv_buf, "recoff") == 0) {
                record = false;
                if(writer.isOpened()) {
                    writer.release();
                }
            } else if(strcmp(recv_buf, "aeon") == 0) {
                ev = -1;
                gain = -1;
                ae_enabled = true;
            } else if(strcmp(recv_buf, "aeoff") == 0) {
                ae_enabled = false;
            } else if(strcmp(recv_buf, "shadeon") == 0) {
                shading_enabled = true;
            } else if(strcmp(recv_buf, "shadeoff") == 0) {
                shading_enabled = false;
            } else if(strcmp(recv_buf, "pointson") == 0) {
                show_points = true;
            } else if(strcmp(recv_buf, "pointsoff") == 0) {
                show_points = false;
            } else if(strcmp(recv_buf, "labelon") == 0) {
                show_label = true;
            } else if(strcmp(recv_buf, "labeloff") == 0) {
                show_label = false;
            } else if(strcmp(recv_buf, "klton") == 0) {
                klt_enabled = true;
            } else if(strcmp(recv_buf, "kltoff") == 0) {
                klt_enabled = false;
            } else if(strcmp(recv_buf, "svoon") == 0) {
                svo_enabled = true;
            } else if(strcmp(recv_buf, "svooff") == 0) {
                svo_enabled = false;
            } else if(strcmp(recv_buf, "calon") == 0) {
                klt_enabled = false;
                svo_enabled = false;
                show_points = false;
                show_label = false;
                jpg_quality = 100;
                ev_max = 1010;
            } else if(strcmp(recv_buf, "caloff") == 0) {
                klt_enabled = true;
                svo_enabled = true;
                show_points = true;
                show_label = true;
                jpg_quality = 80;
                ev_max = 250;
            } else if(strncmp(recv_buf, "kpe", 3) == 0) {
                char buf[16];
                strncpy(buf, recv_buf+4, 16);
                if(ae_enabled) {
                    kp_e_max = atof(buf);
                } else {
                    ev = atoi(buf);
                }
                printf("--airbee: get kpe: %.3f %s\n", kp_e_max, buf);
            } else if(strncmp(recv_buf, "kpg", 3) == 0) {
                char buf[16];
                strncpy(buf, recv_buf+4, 16);
                if(ae_enabled) {
                    kp_g = atof(buf);
                } else {
                    gain = atoi(buf);
                }
                printf("--airbee: get kpg: %.3f %s\n", kp_g, buf);
            } else if(strncmp(recv_buf, "msv", 3) == 0) {
                char buf[16];
                strncpy(buf, recv_buf+4, 16);
                desired_msv = atoi(buf);
                printf("--airbee: change desired_msv to: %d %s\n", desired_msv, buf);
            } else if(strncmp(recv_buf, "jpg", 3) == 0) {
                char buf[16];
                strncpy(buf, recv_buf+4, 16);
                jpg_quality = atoi(buf);
                printf("--airbee: change jpg quality to: %d %s\n", jpg_quality, buf);
            } else if(strncmp(recv_buf, "emx", 3) == 0) {
                char buf[16];
                strncpy(buf, recv_buf+4, 16);
                ev_max = atoi(buf);
            }  
        }
    }
}


//image:=/mono_image calib=/home/sam/dso_root/camera_120.txt 


static void send_dso_data()
{
    sem_init(&dso_send, 0, 0);
    while(1)
    {
        sem_wait(&dso_send);

        // mavlink_svo_position_raw_t sendmsg = position.front();
        // position.pop();

        // send_svo_data(&sendmsg);

        // std::cout << "+++++++++++++have data++++++++++++  \n";
        

    }
}

static void dso_main()
{
    disableAllDisplay = true;   

    setting_desiredImmatureDensity = 1000;
	setting_desiredPointDensity = 1200;
	setting_minFrames = 5;
	setting_maxFrames = 7;
	setting_maxOptIterations=4;
	setting_minOptIterations=1;
	setting_logStuff = false;
	setting_kfGlobalWeight = 1.3;


	
	setting_photometricCalibration = 2;
	setting_affineOptModeA = 0;
	setting_affineOptModeB = 0;

    // multiThreading = false;
    setting_logStuff = false;
    setting_debugout_runquiet = true;
    useSampleOutput = true;

    undistorter = Undistort::getUndistorterForFile(calib, gammaFile, vignetteFile);

    setGlobalCalib(
            (int)undistorter->getSize()[0],
            (int)undistorter->getSize()[1],
            undistorter->getK().cast<float>());

    fullSystem = new FullSystem();
    fullSystem->linearizeOperation=false;

    // if(useSampleOutput)
    fullSystem->outputWrapper.push_back(new IOWrap::SampleOutputWrapper());

    if(undistorter->photometricUndist != 0)
        fullSystem->setGammaFunction(undistorter->photometricUndist->getG());

    
    dso_send_thread = new std::thread(send_dso_data);
    

    struct timeval tv0, tv1;

    while(1)
    {
        sem_wait(&dso_data_ready);
        // std::cout <<"|||||||||||||||||||||||||||||||dso_main|||||||||||||||||||||" << std::endl;
        if(dso_done)
        {
            dso_done = false;

            memcpy(dso_data, dso_img_data, ROW*COL);

            MinimalImageB minImg(COL, ROW,dso_data);
            // std::cout << "----dso---frame id :" << frameID_dso << std::endl;
            ImageAndExposure* undistImg = undistorter->undistort<unsigned char>(&minImg, 1,0, 1.0f);
            
            gettimeofday(&tv0, NULL);

            fullSystem->addActiveFrame(undistImg, frameID_dso);

            gettimeofday(&tv1, NULL);
            timersub(&tv1, &tv0, &tv1);
            // imprlog("dso_main() takes %lu.%06lu  : %d ", tv1.tv_sec, tv1.tv_usec,frameID_dso);
            // std::cout << " "<< frameID_dso << std::endl;

            frameID_dso++;
            delete undistImg;
            dso_done = true;
        }
        if(fullSystem->isLost)
        {
            std::cout << "xxxxxxxxxxxxxxxxxx LOST XXXXXXXXXXXXXXXXXXXXXXXXX" << std::endl;

            std::vector<IOWrap::Output3DWrapper*> wraps = fullSystem->outputWrapper;
            delete fullSystem;
            for(IOWrap::Output3DWrapper* ow : wraps) ow->reset();
            fullSystem = new FullSystem();
            fullSystem->linearizeOperation=false;
            fullSystem->outputWrapper = wraps;
            if(undistorter->photometricUndist != 0)
                fullSystem->setGammaFunction(undistorter->photometricUndist->getG());

        }
     
    }
}

static void main_thread(struct impr_data *ip) {
   

    while (1) {
        sem_wait(&ip->sem_event);
        // see if we are going to quit.
        if (ip->bquit) break;
            //printf("ZEKE::STOP AT LINE 861\n");
        // see if the input buf queue has something.
        if (!ip->input_queue->empty()) {
            // fetch next buffer to deal with.

            int queuesize=0;
            queuesize=ip->input_queue->size();
            if(queuesize>1)
            {
                //imprlog("vo queue size :%d", queuesize);
                for(int itmp=(queuesize-1);itmp>0;itmp--)
                {
                    //imprlog("vo queue delete itmp :%d", itmp);
                    struct frame_info *finfo = ip->input_queue->front();
                    ip->input_queue->pop();
                    struct impr_cb_free_data d = { finfo->data };
                    // tell the caller that we have done with the input buffer at right time.
                    ip->free_cb(ip->usrdata, &d);
                    delete finfo;
                }
            }
            struct frame_info *finfo = ip->input_queue->front();

            ip->input_queue->pop();

            ip->inner_queue->push(finfo); // we are using these buffers

            struct timeval tv0, tv1;
            gettimeofday(&tv0, NULL);
            //printf("ZEKE::STOP AT LINE 890\n");
            //imprlog("ZEKE:: svo has been intern do_image_processing..........................\n");
            do_image_processing(finfo, ip);

            gettimeofday(&tv1, NULL);
            timersub(&tv1, &tv0, &tv1);
            if (tv1.tv_sec || tv1.tv_usec >= 30000)
            {
                // show warn log if the operation takes very long time.
                imprlog("vo do_image_processing() takes %lu.%06lu", tv1.tv_sec, tv1.tv_usec);
            }

            // std::cout <<"|||||||||||||||||||||||||||||||main_thread|||||||||||||||||||||" << std::endl;

            finfo = ip->inner_queue->front();
            ip->inner_queue->pop();
            struct impr_cb_free_data d = { finfo->data };
            // tell the caller that we have done with the input buffer at right time.
            ip->free_cb(ip->usrdata, &d);
            delete finfo;
        }
    }
}

extern "C"
void * impr_create_instance() {
    //  init_send_receive();
    struct impr_data *ip = (struct impr_data *)calloc(1, sizeof(*ip));
    if (sem_init(&ip->sem_event, 0, 0)) {
        imprlog("sem_init() failed, %d: %s", errno, strerror(errno));
        return NULL;
    }
    ip->input_queue = new std::queue<struct frame_info *>();
    ip->inner_queue = new std::queue<struct frame_info *>();
    ip->work_thrd = new std::thread(main_thread, ip);
 
    udp_thread_rcv = new std::thread(image_udp_receiver);


    sem_init(&dso_data_ready, 0, 0);
    dso_thread = new std::thread(dso_main); //Start SVO thread;
    return (void*)ip;
}

extern "C"
int impr_destroy_instance(void *phandle) {
    struct impr_data *ip = (struct impr_data *)phandle;

    if (!phandle) return -1;

    if (ip->work_thrd) {
        // notify the work thread that we are going to quit.
        ip->bquit = true;
        sem_post(&ip->sem_event);
        // wait for end of the work thread.
        ip->work_thrd->join();
        // finally delete the std::thread object.
        delete ip->work_thrd;
    }

    // tell the caller to free all input buffers
    if (ip->inner_queue) {
        while (!ip->inner_queue->empty()) {
            struct frame_info *finfo = ip->inner_queue->front();
            ip->inner_queue->pop();
            struct impr_cb_free_data d = { finfo->data };
            ip->free_cb(ip->usrdata, &d);
            delete finfo;
        }
        delete ip->inner_queue;
    }

    // tell the caller to free all input buffers
    if (ip->input_queue) {
        while (!ip->input_queue->empty()) {
            struct frame_info *finfo = ip->input_queue->front();
            ip->input_queue->pop();
            struct impr_cb_free_data d = { finfo->data };
            ip->free_cb(ip->usrdata, &d);
            delete finfo;
        }
        delete ip->input_queue;
    }
    free(phandle);
    return 0;

}

extern "C"
int impr_configure(void *phandle, struct impr_cfg * cfg) {
    struct impr_data *ip = (struct impr_data *)phandle;
    ip->res_in  = cfg->res_in;
    return 0;
}

extern "C"
int impr_getconfigure(void *phandle, struct impr_cfg_get * cfg) {
    cfg->target_luma = 100;
    return 0;
}

extern "C"
int impr_set_callback_data(void *phandle, void *priv) {
    struct impr_data *ip = (struct impr_data *)phandle;
    ip->usrdata = priv;
    return 0;
}

extern "C"
int impr_set_complete_callback(void *phandle, impr_pfn_complete_cb_t pfn_cb) {
    struct impr_data *ip = (struct impr_data *)phandle;
    ip->comp_cb = pfn_cb;
    return 0;
}


extern "C"
int impr_set_free_callback(void *phandle, impr_pfn_free_cb_t pfn_cb) {

    struct impr_data *ip = (struct impr_data *)phandle;
    ip->free_cb = pfn_cb;
    return 0;
}


extern "C"
int impr_process_image(void *phandle, struct impr_frame_data *frame_data, struct impr_cb_comp_data *comp_data, bool *is_complete) {
    if (frame_data->type != IMPR_DT_FRAME_OPTIC) return -1;
    frameID++;
    // std::cout << "-----------------come in image---------------" << frameID <<std::endl;
    struct impr_data *ip = (struct impr_data *)phandle;
    struct frame_info * finfo = new struct frame_info;
    finfo->data = frame_data->u.optic.inbuf;
    finfo->size = frame_data->u.ot.buf_size;
    finfo->timestamp = frame_data->u.optic.timestamp;
    ip->input_queue->push(finfo);
    *is_complete = false;
    sem_post(&ip->sem_event); //notify the work thread.
    return 0;
}


