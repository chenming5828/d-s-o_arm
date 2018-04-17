#include "sender_receiver.h"


briMavlink* pbriMavlink;
void init_send_receive()
{
	//char ID_table[BRI_MAX_IDNUM]={(char)MAVLINK_MSG_ID_ATTITUDE,(char)MAVLINK_MSG_ID_LOCAL_POSITION_NED};
    char ID_table[BRI_MAX_IDNUM]={(char)MAVLINK_MSG_ID_ATTITUDE,(char)MAVLINK_MSG_ID_HEARTBEAT};
	pbriMavlink=new briMavlink(ID_table,BRI_MAX_IDNUM,BRI_MAX_BUFSIZE,UDP_LOCAL_PORT_DEFAULT,UDP_REMOTE_PORT_DEFAULT);

	usleep(1e5);
	if(pbriMavlink->start_mavlink()==false)
	{
		imprlog("zpbriMavlink->start_mavlink() false");
		exit(-1);
	}
}

bool update_end;
void get_data(SVO_ATTITUDE* attitude_ptr, bool *armed, SVO_DATA* svo_info)
{
	pbriMavlink->update();

	if(pbriMavlink->getrefreshnum(MAVLINK_MSG_ID_ATTITUDE)>0)
	{
		mavlink_attitude_t* patt=(mavlink_attitude_t*)malloc(sizeof(mavlink_attitude_t));
		pbriMavlink->getnewvalue(MAVLINK_MSG_ID_ATTITUDE,(char*)patt);
		Euler_rads rads(patt->roll,patt->pitch,patt->yaw);
		Quaternion3d q(1,0,0,0);
		rads_to_quat(rads, q);
		attitude_ptr->timestamp=patt->time_boot_ms;
		attitude_ptr->q0=q.w;
		attitude_ptr->q1=q.x;
		attitude_ptr->q2=q.y;
		attitude_ptr->q3=q.z;
		attitude_ptr->alfa=cos(rads.x)*cos(rads.y);
		free(patt);
		svo_info->svo_valid = (svo_info->svo_valid) | (1 << RECEIVE_ATTITUDE_BIT);
        svo_info->svo_valid = (svo_info->svo_valid) & ~(1 << CAMERA_UPDATE_ABNORMAL_BIT);
    } else {
		svo_info->svo_valid = (svo_info->svo_valid) & ~(1 << RECEIVE_ATTITUDE_BIT);
	}

    if(pbriMavlink->getrefreshnum(MAVLINK_MSG_ID_HEARTBEAT)>0)
	{
        mavlink_heartbeat_t heartbeat;
        pbriMavlink->getnewvalue(MAVLINK_MSG_ID_HEARTBEAT,(char*)&heartbeat);
        *armed = heartbeat.base_mode & MAV_MODE_FLAG_DECODE_POSITION_SAFETY;;
        update_end = *armed;
        //imprlog("suke:: get_data armed = %d", *armed);
        svo_info->svo_valid = (svo_info->svo_valid) | (1 << RECEIVE_ARMED_BIT);
        svo_info->svo_valid = (svo_info->svo_valid) & ~(1 << CAMERA_UPDATE_ABNORMAL_BIT);
    } else {
    	*armed = update_end;
        svo_info->svo_valid = (svo_info->svo_valid) & ~(1 << RECEIVE_ARMED_BIT);
    }
}

void send_svo_data(const void *msg)
{
	pbriMavlink->send_mavlink_message(MAVLINK_MSG_ID_SVO_POSITION_RAW,msg,0);	
}

//Added by ZEKE, Beijing, 0619. Send Optical Flow info to Mavlink.
void send_optical_flow_data(const void *msg)
{
	pbriMavlink->send_mavlink_message(MAVLINK_MSG_ID_OPTICAL_FLOW_RAD,msg,0);	
}






