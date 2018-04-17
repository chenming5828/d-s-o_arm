#ifndef _BRIMAVLINK_H
#define _BRIMAVLINK_H


#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <semaphore.h>
#include <errno.h>
#include <string.h>
#include <thread>
#include <fcntl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/time.h>
#include <stdbool.h>
#include <arpa/inet.h>

#include <queue>

extern "C" {
#include "mavlink/v1.0/mavlink_types.h"
#include "mavlink/v1.0/brisky/mavlink.h"
//#include "mavlink/v1.0/brisky/mavlink_msg_svo_position_raw.h"
#include "imgproc_balloon.h"
}



#define BUFFER_LENGTH 2041 // minimum buffer size that can be used with qnx (I don't know why)

#define MAVLINK_ALL_ID_NUM 2041








struct _Mav_member
{
    uint8_t ID;
    void (*fun_mav)(mavlink_message_t *msg,struct _Mav_member* pMav_member,int maxbuf);
    std::queue<void*>* queue_mav;
    int  newnum;
    char* newvalue;
    char* valuebuf;
    int   sizevalue;
};




class briMavlink
{
public:
    briMavlink(char* IDtable,int mavnum,int maxbuf,uint16_t udplocalport,uint16_t udpremoteport);
    ~briMavlink();
    bool start_mavlink();
    void stop_mavlink();
    void update();
    void getnewvalue(uint8_t ID,char* data);        //size must == sizevalue
    void getvaluebuf(uint8_t ID,char* data);        //size must == sizevalue
    int  getsizevalue(uint8_t ID);
    ssize_t  send_mavlink_message(const uint8_t msgid, const void *msg, uint8_t component_ID);
    int getrefreshnum(uint8_t ID);



private:
    pthread_t   thread_ID;
    int brirunning;
    int mav_num;
    int max_buf;
    struct _Mav_member* pMav_member;
    uint16_t udp_local_port;
    uint16_t udp_remote_port;
    int sock;
    struct sockaddr_in myAddr;
    struct sockaddr_in theirAddr;
    struct sockaddr_in theirAddrSend;

private:
    static void* mavlink_server(void *arg);
    bool read_mavlink_messages();


};



#endif //_IMGPROC_H
