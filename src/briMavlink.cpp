#include "briMavlink.h"

static const uint8_t mavlink_message_lengths[256] = MAVLINK_MESSAGE_LENGTHS;
static const uint8_t mavlink_message_crcs[256] = MAVLINK_MESSAGE_CRCS;

#define Mav_member_default    {\
                                {MAVLINK_MSG_ID_HEARTBEAT,      handle_message_heartbeat,           0,0,0,0, sizeof(mavlink_heartbeat_t)},                       \
                                {MAVLINK_MSG_ID_HIGHRES_IMU,    handle_message_highres_imu,         0,0,0,0, sizeof(mavlink_highres_imu_t)},                     \
                                {MAVLINK_MSG_ID_ATTITUDE,       handle_message_attitude,            0,0,0,0, sizeof(mavlink_attitude_t)},                             \
                                {MAVLINK_MSG_ID_DISTANCE_SENSOR,handle_message_distance_sensor_t,   0,0,0,0, sizeof(mavlink_distance_sensor_t)},        \
				{MAVLINK_MSG_ID_LOCAL_POSITION_NED,handle_message_local_position_ned_t,   0,0,0,0, sizeof(mavlink_local_position_ned_t)}        \
                            };


void handle_message_local_position_ned_t(mavlink_message_t *msg,struct _Mav_member* pMav_member,int maxbuf)
{
    int queuesize;
    //imprlog("handle_message_highres_imu ");
    queuesize=pMav_member->queue_mav->size();
    if(queuesize>=maxbuf)
    {
        imprlog("handle_message_highres_imu over maxbuf:%d",queuesize);
        return;
    }

    mavlink_local_position_ned_t* pdata=new mavlink_local_position_ned_t;
    mavlink_msg_local_position_ned_decode(msg, pdata);

    //imprlog("handle  time_usec:%llu,xacc:%f,yacc:%f,zacc:%f\n", \
                phighres_imu->time_usec,phighres_imu->xacc,phighres_imu->yacc,phighres_imu->zacc);

    pMav_member->queue_mav->push((void*)pdata);
}


void handle_message_highres_imu(mavlink_message_t *msg,struct _Mav_member* pMav_member,int maxbuf)
{
    int queuesize;
    //imprlog("handle_message_highres_imu ");
    queuesize=pMav_member->queue_mav->size();
    if(queuesize>=maxbuf)
    {
        imprlog("handle_message_highres_imu over maxbuf:%d",queuesize);
        return;
    }

    mavlink_highres_imu_t* pdata=new mavlink_highres_imu_t;
    mavlink_msg_highres_imu_decode(msg, pdata);

    //imprlog("handle  time_usec:%llu,xacc:%f,yacc:%f,zacc:%f\n", \
                phighres_imu->time_usec,phighres_imu->xacc,phighres_imu->yacc,phighres_imu->zacc);

    pMav_member->queue_mav->push((void*)pdata);
}
void handle_message_heartbeat(mavlink_message_t *msg,struct _Mav_member* pMav_member,int maxbuf)
{
    int queuesize;
    //imprlog("handle_message_heartbeat ");
    queuesize=pMav_member->queue_mav->size();
    if(queuesize>=maxbuf)
    {
        imprlog("handle_message_heartbeat over maxbuf:%d",queuesize);
        return;
    }

    mavlink_heartbeat_t* pdata=new mavlink_heartbeat_t;
    mavlink_msg_heartbeat_decode(msg, pdata);

    pMav_member->queue_mav->push((void*)pdata);
}
void handle_message_attitude(mavlink_message_t *msg,struct _Mav_member* pMav_member,int maxbuf)
{
    int queuesize;
    queuesize=pMav_member->queue_mav->size();
    if(queuesize>=maxbuf)
    {
        imprlog("handle_message_attitude over maxbuf:%d",queuesize);
        return;
    }
    mavlink_attitude_t* pdata=new mavlink_attitude_t;
    mavlink_msg_attitude_decode(msg, pdata);

    //imprlog("MAVLINK_MSG_ID_ATTITUDE  getnewvalue pitch:%f,pitchspeed:%f,roll:%f,rollspeed:%f,time_boot_ms:%u,yaw:%f,roll:%f,yawspeed:%f\n", \
                pdata->pitch,pdata->pitchspeed,pdata->roll,pdata->rollspeed,pdata->time_boot_ms,pdata->yaw,pdata->yawspeed);

    pMav_member->queue_mav->push((void*)pdata);
}
void handle_message_distance_sensor_t(mavlink_message_t *msg,struct _Mav_member* pMav_member,int maxbuf)
{
    int queuesize;
    queuesize=pMav_member->queue_mav->size();
    if(queuesize>=maxbuf)
    {
        imprlog("handle_message_distance_sensor_t over maxbuf:%d",queuesize);
        return;
    }

    mavlink_distance_sensor_t* heartbeat=new mavlink_distance_sensor_t;
    mavlink_msg_distance_sensor_decode(msg, heartbeat);

    pMav_member->queue_mav->push((void*)heartbeat);
}

ssize_t briMavlink::send_mavlink_message(const uint8_t msgid, const void *msg, uint8_t component_ID)
{
    component_ID = 0;
    uint8_t payload_len = mavlink_message_lengths[msgid];
    unsigned packet_len = payload_len + MAVLINK_NUM_NON_PAYLOAD_BYTES;

    uint8_t buf[MAVLINK_MAX_PACKET_LEN];

    /* header */
    buf[0] = MAVLINK_STX;
    buf[1] = payload_len;
    /* no idea which numbers should be here*/
    buf[2] = 100;
    buf[3] = 0;
    buf[4] = component_ID;
    buf[5] = msgid;

    /* payload */
    memcpy(&buf[MAVLINK_NUM_HEADER_BYTES], msg, payload_len);

    /* checksum */
    uint16_t checksum;
    crc_init(&checksum);
    crc_accumulate_buffer(&checksum, (const char *) &buf[1], MAVLINK_CORE_HEADER_LEN + payload_len);
    crc_accumulate(mavlink_message_crcs[msgid], &checksum);

    buf[MAVLINK_NUM_HEADER_BYTES + payload_len] = (uint8_t)(checksum & 0xFF);
    buf[MAVLINK_NUM_HEADER_BYTES + payload_len + 1] = (uint8_t)(checksum >> 8);

    ssize_t len = sendto(sock, buf, packet_len, 0, (struct sockaddr *)&theirAddrSend, sizeof(struct sockaddr_in));
    if (len <= 0)
    {
        imprlog("Failed sending mavlink message\n");
    }
    return len;
}


briMavlink::briMavlink(char* ID_table,int mavnum,int maxbuf,uint16_t udplocalport,uint16_t udpremoteport):
    udp_local_port(udplocalport),
    udp_remote_port(udpremoteport),
    brirunning(false)
{

    int err;
    imprlog("briMavlink create begin!");

    mav_num=mavnum;
    max_buf=maxbuf;
    sock=0;

    struct _Mav_member Mav_member[MAVLINK_ALL_ID_NUM]= Mav_member_default;

    pMav_member=new struct _Mav_member[mavnum];

    for(int i=0;i<mav_num;i++)
    {
        for(int j=0;j<MAVLINK_ALL_ID_NUM;j++)
        {
            if(ID_table[i]==Mav_member[j].ID)
            {
                pMav_member[i].ID=Mav_member[j].ID;
                pMav_member[i].fun_mav=Mav_member[j].fun_mav;
                pMav_member[i].sizevalue=Mav_member[j].sizevalue;
                break;
            }
        }
        pMav_member[i].newvalue=new char[pMav_member[i].sizevalue];
        pMav_member[i].valuebuf=new char[pMav_member[i].sizevalue*max_buf];
        pMav_member[i].queue_mav=new std::queue<void*>;
        pMav_member[i].newnum=0;
    }
    imprlog("briMavlink create success!");
}

briMavlink::~briMavlink()
{
    imprlog("~briMavlink  begin!");
    for(int i=0;i<mav_num;i++)
    {
        //if((*pMav_member[i]).queue_mav)
        {
            while(pMav_member[i].queue_mav->empty())
            {
                void* pdata=pMav_member[i].queue_mav->front();
//need to  Confirm
                delete pdata;
                pMav_member[i].queue_mav->pop();
            }
            delete pMav_member[i].queue_mav;
        }
        if(pMav_member[i].newvalue)
            delete pMav_member[i].newvalue;
        if(pMav_member[i].valuebuf)
            delete pMav_member[i].valuebuf;
    }
    delete pMav_member;
    imprlog("briMavlink delete success!");
}

bool briMavlink::start_mavlink()
{
    imprlog("start_mavlink begin!");
    int err;
    if(brirunning==true)
    {
        imprlog("briMavlink pthread is brirunning,do not rede!");
        return 0;
    }

    if ((sock = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        imprlog("briMavlink create socket failed\n");
        return false;
    }

    memset(&theirAddr, 0, sizeof(theirAddr));

    memset(&myAddr, 0, sizeof(myAddr));
    myAddr.sin_family = AF_INET;
    //myAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    myAddr.sin_addr.s_addr=inet_addr("127.0.0.1");
    myAddr.sin_port = htons(udp_local_port);
    imprlog("briMavlink local port: %d\n", udp_local_port);

    theirAddrSend.sin_family = AF_INET;
    //theirAddrSend.sin_addr.s_addr = htonl(INADDR_ANY);
    myAddr.sin_addr.s_addr=inet_addr("127.0.0.1");
    theirAddrSend.sin_port = htons(udp_remote_port);

    /* Bind the socket to port - necessary to receive packets */
    if (-1 == bind(sock, (struct sockaddr *)&myAddr, sizeof(struct sockaddr)))
    {
        imprlog("error bind failed");
        close(sock);
        return false;
    }

/*
    // Attempt to make it non blocking
    if (fcntl(sock, F_SETFL, O_NONBLOCK ) < 0) {
        imprlog("error setting nonblocking: %s\n", strerror(errno));
        close(sock);
        return false;
    }
*/

    err = pthread_create(&thread_ID, NULL, mavlink_server,(void*)this);
    if(err != 0)
    {
        imprlog("briMavlink can't create thread: %s\n", strerror(err));
        return false;
    }
    brirunning=true;
    imprlog("briMavlink create thread\n");
    return true;
}
void briMavlink::stop_mavlink()
{
    brirunning=false;
    pthread_join(thread_ID,NULL);
}

bool briMavlink::read_mavlink_messages()
{
    bool ret = false;
    ssize_t recsize;
    socklen_t fromlen;
    uint8_t buf[BUFFER_LENGTH]={0};

    recsize = recvfrom(sock, (void *)buf, BUFFER_LENGTH, 0, (struct sockaddr *)&theirAddr, &fromlen);


    //imprlog("Received a string from client %s\n",inet_ntoa(theirAddr.sin_addr));
    //imprlog("port:%d\n",ntohs(theirAddr.sin_port));

    //imprlog("read_mavlink_messages udp recsize :%d",recsize);
    if(recsize<=0)
    {
        imprlog("read_mavlink_messages udp err,%d: %s", errno, strerror(errno));
    }
    if (recsize > 0)
    {
        //imprlog("udp recsize > 0 :%d",recsize);
        // Something received
        mavlink_message_t msg;
        mavlink_status_t status;
        unsigned int temp = 0;
        temp=temp;

        for (int i = 0; i < recsize; ++i)
        {
            temp = buf[i];

            if (mavlink_parse_char(MAVLINK_COMM_0, buf[i], &msg, &status))
            {
                //imprlog("mavlink_parse_char");
                for(int i=0;i<mav_num;i++)
                {
                    if(msg.msgid==pMav_member[i].ID)
                    {
                        //imprlog("fun_mav ID:%d\n",pMav_member[i].ID);
                        pMav_member[i].fun_mav(&msg,&pMav_member[i],max_buf);
                        ret = true;
                        break;
                    }
                }
            }
        }
    }

    return ret;
}
void* briMavlink::mavlink_server(void *arg)
{
    briMavlink* ptr=(briMavlink*)arg;
    while (ptr->brirunning)
    {
        //imprlog("mavlink_server doing");
        ptr->read_mavlink_messages();
        usleep(1e3);
    }
}
void briMavlink::update()
{
    int queuesize;
    int datasize;
    int tmpindex;


    for(int i=0;i<mav_num;i++)
    {
        queuesize=pMav_member[i].queue_mav->size();
        //imprlog("queuesize:%d,i:%d",queuesize,i);
        if(queuesize>max_buf)
            queuesize=max_buf;
        if(queuesize>0)
        {
            pMav_member[i].newnum=queuesize;
            tmpindex=0;
            datasize=pMav_member[i].sizevalue;
            memset(pMav_member[i].valuebuf,0,datasize*max_buf);
            memset(pMav_member[i].newvalue,0,datasize);
            for(int j=0;j<queuesize;j++)
            {
                void *pdata = pMav_member[i].queue_mav->front();
                pMav_member[i].queue_mav->pop();

                memcpy(&(pMav_member[i].valuebuf[tmpindex]),(char*)pdata,datasize);
                tmpindex+=datasize;
                if(j==(queuesize-1))
                {
                    memcpy(pMav_member[i].newvalue,(char*)pdata,datasize);
                }
                delete pdata;
            }
        }
        else
            pMav_member[i].newnum=0;
    }
}
void briMavlink::getnewvalue(uint8_t ID,char* data)
{
    for(int i=0;i<mav_num;i++)
    {
        if(ID==pMav_member[i].ID)
        {
            memcpy(data,pMav_member[i].newvalue,pMav_member[i].sizevalue);
            break;
        }
    }
}
void briMavlink::getvaluebuf(uint8_t ID,char* data)
{
    for(int i=0;i<mav_num;i++)
    {
        if(ID==pMav_member[i].ID)
        {
            memcpy(data,pMav_member[i].valuebuf,pMav_member[i].sizevalue*max_buf);
            break;
        }
    }
}
int briMavlink::getsizevalue(uint8_t ID)
{
    for(int i=0;i<mav_num;i++)
    {
        if(ID==pMav_member[i].ID)
        {
            return pMav_member[i].sizevalue;
        }
    }
}


int briMavlink::getrefreshnum(uint8_t ID)
{
    for(int i=0;i<mav_num;i++)
    {
        if(ID==pMav_member[i].ID)
        {
            return pMav_member[i].newnum;
        }
    }
    return 0;
}









