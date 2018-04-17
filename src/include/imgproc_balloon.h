#ifndef _IMGPROC_BALLOON_H
#define _IMGPROC_BALLOON_H

//------------------------------------------------------------------------------
// log utilities
//------------------------------------------------------------------------------
#include <stdio.h>
#include <sys/time.h>
#define imprlog(fmt, args...) \
	do { \
		struct timeval now; \
		gettimeofday(&now, NULL); \
		fprintf(stderr, "[%5lu.%06lu] %s() %d: " fmt "\n", \
				now.tv_sec, now.tv_usec, __FUNCTION__, __LINE__, ##args); \
	} while (0)



//------------------------------------------------------------------------------
// IMage PRocessing API.
//------------------------------------------------------------------------------

#define MAX_BUF_NUM       10
#define MAX_TRACKING_OBJS 10
#define MAX_FACE_NUM      10
#define MAX_GESTURE_NUM   10
#define MAX_PROCESS_NUM   36
struct impr_res {
	int w;
	int h;
};

struct impr_cfg {
	struct impr_res res_in;
	struct impr_res res_out;
	int    outbufs_num;
	char * outbufs[MAX_BUF_NUM];
	int    outbuf_fds[MAX_BUF_NUM];
	char * pic_name;
	char * pic_thm_name;
	int8_t fly_status;//0x00:fly arround an object; 0x01:fly to an object;
        int    target_luma;
};

struct impr_cfg_get {
	int target_luma; //0-255
};

typedef struct {
	float exp_time;
	float real_gain;
	int settled;
	uint32_t line_count;
}cam_metadata_t;

struct impr_gps {
	float longitude;
	float latitude;
	float altitude;
};

struct	gesture_postion {
	int16_t topLeft_x;
	int16_t topLeft_y;
	int16_t bottomRight_x;
	int16_t bottomRight_y;
};
struct impr_fc_param{
	int16_t x;
	int16_t y;
	int16_t z;
	int16_t r;
};
struct impr_rect {
	unsigned short x;
	unsigned short y;
	unsigned short w;
	unsigned short h;
};

struct impr_angle {
	unsigned short angle;
	unsigned short orientation;
};

struct impr_gcs_input_data {
	int              frame_id;
	int 			 status;//0xe0:tracking;0xe1:finshed;0xe2:lost object;0xe3 detect object again
	struct impr_rect obj;
};

struct gimbal_attitude_t {
	int16_t gimbal_yaw; /*< current gimbal yaw, -45~ 45*/
	int16_t gimbal_roll; /*< current gimbal roll, -128~ 127*/
	int16_t gimbal_pitch; /*< current gimbal pitch, 0 ~ 36*/
 	uint8_t camera_connected_state; /*< camera connected state*/
};
struct uav_attitude_t {
	float roll; /*< Roll*/
	float pitch; /*< Pitch*/
	float yaw; /*< Yaw*/
	int16_t vx; /*x velocity in meter/s*/
	int16_t vy; /*x velocity in meter/s*/
	int16_t vz; /*x velocity in meter/s*/
	int16_t height;
};

struct gimbal_control_t {
	int16_t gimbal_angle; /*< Set gimbal angle*/
    uint16_t gimbal_period; /*< Set gimbal move period (ms)*/
};

struct impr_event_data_imu {
	int64_t time_usec; /*< Timestamp */
	float roll; /*< Roll*/
	float pitch; /*< Pitch*/
	float yaw; /*< Yaw*/ 
	float xacc; /*< X acceleration (m/s^2)*/
	float yacc; /*< Y acceleration (m/s^2)*/
	float zacc; /*< Z acceleration (m/s^2)*/
	float xgyro; /*< Angular speed around X axis (rad / sec)*/
	float ygyro; /*< Angular speed around Y axis (rad / sec)*/
	float zgyro; /*< Angular speed around Z axis (rad / sec)*/
};

typedef enum {
	IMPR_DT_COMP_OPTIC = 1, // Optical camera algorithm
	IMPR_DT_COMP_EIS,       // Electronic Image Stabilization
	IMPR_DT_COMP_OT,        // Object Tracking
	IMPR_DT_COMP_FD,        // Face Detection
	IMPR_DT_COMP_MD,        // Motion Detection
	IMPR_DT_COMP_GR,        // Hand Gesture Recognition
	IMPR_DT_COMP_FB,        // Face Beauty
	IMPR_DT_COMP_PP,		// Panorama Picture
	IMPR_DT_COMP_OA,        // Obstale Avoid
	IMPR_DT_COMP_SF,        // Surround Flight
	IMPR_DT_COMP_OPTICAE,   // Optic AE
} impr_data_type_comp_t;

typedef enum {
	IMPR_PANORAMA_RESULT_OK = 0,
	IMPR_PANORAMA_RESULT_IN_PROGRESS,
	IMPR_PANORAMA_RESULT_NG,
} impr_panorama_picture_result_type_t;

struct impr_cb_comp_data_pp {
	char*  main_pic_name;
	char*  thumb_pic_name;
	impr_panorama_picture_result_type_t	ret;
};

typedef enum {
	IMPR_PANORAMA_STATUS_START = 0,
	IMPR_PANORAMA_STATUS_STOP,
	IMPR_PANORAMA_STATUS_IN_PROGRESS,
	IMPR_PANORAMA_STATUS_END,
} impr_panorama_status_type_t;

struct impr_cb_comp_data_opticae {
	int exposure_time;
	int gain;
    int change;
	char dbg_str[80];
};

struct impr_cb_comp_data_optic {
	int exposure_time;
	int gain;
};

struct impr_cb_comp_data_oa {
};

struct impr_cb_comp_data_eis {
	int buf_idx;
	int frame_id;
};

struct impr_cb_comp_data_fb {
	int buf_idx;
	int frame_id;
};

struct impr_cb_comp_data_ot {
	int    frame_id;
	int    objs_num;
	int	   status;//0xe0:tracking;0xe1:tracking finshed;0xe2:lost object;0xe3 detect object again; 0xe4 detecting object success;0xe5 detecting object failure
	struct impr_rect objs[MAX_TRACKING_OBJS];
	struct impr_fc_param fc_param;
	struct gimbal_control_t gb_control;
};

struct impr_cb_comp_data_fd {
	int    frame_id;
	int    face_num;
	struct impr_rect face[MAX_FACE_NUM];
};

struct impr_cb_comp_data_sf {
	impr_fc_param fc_param;
	struct impr_rect sf_obj_rect;
	struct gimbal_control_t gb_control;
};

struct event_cb_t {
};

struct impr_cb_comp_data_md {
	int                 event_num;
	struct event_cb_t * events;
};

typedef enum {
	IMPR_HAND_GESTURE_V = 1,
	IMPR_HAND_GESTURE_OK,
	IMPR_HAND_GESTURE_FIST,
	IMPR_HAND_GESTURE_FIVE,
	IMPR_HAND_GESTURE_UP,
	IMPR_HAND_GESTURE_DOWN,
	IMPR_HAND_GESTURE_RIGHT,
	IMPR_HAND_GESTURE_LEFT,
	IMPR_HAND_GESTURE_FLY_CLOSE,
	IMPR_HAND_GESTURE_FLY_AWAY,
	IMPR_HAND_GESTURE_OPEN,
	IMPR_HAND_GESTURE_CLOSE,
	IMPR_HAND_GESTURE_FACE,
	IMPR_HAND_GESTURE_THUMBS_UP,
	IMPR_HAND_GESTURE_PINCH_SIGN,
	IMPR_HAND_GESTURE_UNKNOW,
} impr_hand_gesture_type_t;

typedef enum {
	IMPR_HAND_GESTURE_ACTION_TAKE_PIC = 1,
	IMPR_HAND_GESTURE_ACTION_TAKE_REC,
	IMPR_HAND_GESTURE_ACTION_FLYING_UP,
	IMPR_HAND_GESTURE_ACTION_FLYING_DOWN,
	IMPR_HAND_GESTURE_ACTION_FLYING_LEFT,
	IMPR_HAND_GESTURE_ACTION_FLYING_RIGHT,
	IMPR_HAND_GESTURE_ACTION_FLYING_CLOSE,
	IMPR_HAND_GESTURE_ACTION_FLYING_AWAY,
} impr_hand_gesture_action_t;

struct impr_cb_comp_data_gr {
	impr_fc_param            	fc_param;
	impr_hand_gesture_type_t 	gesture;
	impr_hand_gesture_action_t 	action;
	gesture_postion				postion;
	int	   						status;//0xe0 success;0xe1 failure	
	int							frameId;
};

struct impr_cb_comp_data {
	impr_data_type_comp_t type;
	union {
		struct impr_cb_comp_data_optic optic;
		struct impr_cb_comp_data_eis eis;
		struct impr_cb_comp_data_ot ot;
		struct impr_cb_comp_data_fd fd;
		struct impr_cb_comp_data_md md;
		struct impr_cb_comp_data_gr gr;
		struct impr_cb_comp_data_fb fb;
		struct impr_cb_comp_data_pp pp;
		struct impr_cb_comp_data_oa oa;
		struct impr_cb_comp_data_sf sf;
		struct impr_cb_comp_data_opticae opticae;
	} u;
};

struct impr_cb_free_data {
	char * inbuf;
};

typedef enum {
	IMPR_DT_FRAME_OPTIC = 1,
	IMPR_DT_FRAME_EIS,
	IMPR_DT_FRAME_OT,
	IMPR_DT_FRAME_FD,
	IMPR_DT_FRAME_MD,
	IMPR_DT_FRAME_GR,
	IMPR_DT_FRAME_FB,
	IMPR_DT_FRAME_PP,
	IMPR_DT_FRAME_OA,
	IMPR_DT_FRAME_SF,
} impr_data_type_frame_t;

struct impr_frame_data_optic {
	char *   inbuf;
	int      buf_size;
	uint64_t timestamp;
};

struct impr_frame_data_sf {
	char *   inbuf;
	int      buf_size;
	uint64_t timestamp;
	uint64_t height; 
	bool	first_frame;
	struct impr_rect  obj_rect;
	struct impr_angle  obj_angle;
	struct gimbal_attitude_t gimbal_attitude;
	struct impr_event_data_imu imu_data;
};

struct impr_frame_data_eis {
	char *   inbuf;
	int      buf_size;
	int      inbuf_fd;
	uint64_t timestamp;
	float    exp_time;
	struct gimbal_attitude_t gimbal_attitude;
};

struct impr_frame_data_oa {
	char *   inbuf;
	int      buf_size;
	int      frame_id;
	uint64_t timestamp;
};
struct impr_frame_data_fb {
	char *   inbuf;
	int      buf_size;
	int      inbuf_fd;
	uint64_t timestamp;
};

struct impr_frame_data_pp {
	char *   inbuf;
	int      buf_size;
	int      frame_id;
	cam_metadata_t* cam_metadata;
	impr_panorama_status_type_t	status;
	uint64_t timestamp;
};

struct impr_frame_data_ot {
	char *						inbuf;
	int 						buf_size;
	int 						frame_id;
	struct impr_rect			obj_rect;
	struct impr_gps 			obj_gps;
	struct	gimbal_attitude_t	gimbale_attitude;
	struct	uav_attitude_t		uav_attitude;
	int 						algorithm_type;//0x01:start object detecting; 0x02:stop object detecting;0x03:start object tracking; 0x04 stop object tracking; 0x05 stop object surrneding; 0x06 stop object surrneding
};

struct impr_frame_data_fd {
	char * inbuf;
	int    buf_size;
	int    inbuf_fd;
	int    frame_id;
};

struct impr_frame_data_md {
	char *   inbuf;
	int      buf_size;
	uint64_t timestamp;
};

struct impr_frame_data_gr {
	char * inbuf;
	int    frame_id;
	int    buf_size;
};

struct impr_frame_data {
	impr_data_type_frame_t type;
	union {
		struct impr_frame_data_optic optic;
		struct impr_frame_data_eis eis;
		struct impr_frame_data_ot ot;
		struct impr_frame_data_fd fd;
		struct impr_frame_data_md md;
		struct impr_frame_data_gr gr;
		struct impr_frame_data_fb fb;
		struct impr_frame_data_pp pp;
		struct impr_frame_data_oa oa;
		struct impr_frame_data_sf sf;
	} u;
};

typedef void (*impr_pfn_complete_cb_t)(void *priv, struct impr_cb_comp_data *d);
typedef void (*impr_pfn_free_cb_t)(void *priv, struct impr_cb_free_data *d);

void * impr_create_instance();

int impr_destroy_instance(void *phandle);

int impr_configure(void *phandle, struct impr_cfg * cfg);
int impr_getconfigure(void *phandle, struct impr_cfg_get * cfg);

int impr_set_callback_data(void *phandle, void *priv);

int impr_set_complete_callback(void *phandle, impr_pfn_complete_cb_t pfn_cb);

int impr_set_free_callback(void *phandle, impr_pfn_free_cb_t pfn_cb);

/*
  This function should return quickly, leaving the heavy work to another
  private thread, which will call free_cb() and completion_cb() later.
*/
int impr_process_image(void *phandle, struct impr_frame_data *frame_data, struct impr_cb_comp_data *comp_data, bool *is_complete);

typedef void * (*impr_create_instance_fn)();
typedef int (*impr_destroy_instance_fn)(void *phandle);
typedef int (*impr_configure_fn)(void *phandle, struct impr_cfg *cfg);
typedef int (*impr_getconfigure_fn)(void *phandle, struct impr_cfg_get *cfg);
typedef int (*impr_set_callback_data_fn)(void *phandle, void *priv);
typedef int (*impr_set_complete_callback_fn)(void *phandle, impr_pfn_complete_cb_t pfn_cb);
typedef int (*impr_set_free_callback_fn)(void *phandle, impr_pfn_free_cb_t pfn_cb);
typedef int (*impr_process_image_fn)(void *phandle, struct impr_frame_data *frame_data, struct impr_cb_comp_data *comp_data, bool *is_complete);

struct impr_intf {
	void *                        handle;
	impr_create_instance_fn       fn_create_instance;
	impr_destroy_instance_fn      fn_destroy_instance;
	impr_configure_fn             fn_configure;
	impr_getconfigure_fn          fn_getconfigure;
	impr_set_complete_callback_fn fn_set_completion_callback;
	impr_set_free_callback_fn     fn_set_free_callback;
	impr_set_callback_data_fn     fn_set_callback_data;
	impr_process_image_fn         fn_process_image;
};


#endif //_IMGPROC_BALLOON_H
