#ifndef SENDER_RECEIVER_H
#define SENDER_RECEIVER_H

#include <stdint.h>
#include <sys/time.h>
#include <time.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>
#include "quat_euler.h"
#include "briMavlink.h"

#define SVO_VALID_BIT 0
#define RECEIVE_ATTITUDE_BIT 1
#define RECEIVE_ARMED_BIT 2
#define CAMERA_UPDATE_ABNORMAL_BIT 3

#define BRI_MAX_BUFSIZE 100
#define BRI_MAX_IDNUM   4
#define UDP_LOCAL_PORT_DEFAULT  14560
#define UDP_REMOTE_PORT_DEFAULT 14559

typedef struct
{
    uint64_t          timestamp;
    
    float       position_x;
    float       position_y;
    float       position_z;

    float       q0;
    float       q1;
    float       q2;
    float       q3;
	unsigned char 		svo_valid;
} SVO_DATA;

typedef struct
{
	uint64_t	timestamp;
	float	q0;
	float	q1;
	float	q2;
	float	q3;
	float	alfa;
} SVO_ATTITUDE;

/*typedef struct 
{
	uint64_t	timestamp;
	double	v_x;
	double	v_y;
}OPTICAL_FLOW_DATA;*/


void send_svo_data(const void *msg);
void send_optical_flow_data(const void *msg);
void get_data(SVO_ATTITUDE* attitude_ptr, bool *armed, SVO_DATA* svo_pose);
void init_send_receive();
#endif



