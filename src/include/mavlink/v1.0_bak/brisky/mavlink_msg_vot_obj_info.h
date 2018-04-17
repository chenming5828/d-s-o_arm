// MESSAGE VOT_OBJ_INFO PACKING

#define MAVLINK_MSG_ID_VOT_OBJ_INFO 155
#if MAVLINK_MULTI_DIALECT
#define MAVLINK_MSG_ID_VOT_OBJ_INFO_TUPLE 0, MAVLINK_MSG_ID_VOT_OBJ_INFO
#else
#define MAVLINK_MSG_ID_VOT_OBJ_INFO_TUPLE MAVLINK_MSG_ID_VOT_OBJ_INFO
#endif

typedef struct __mavlink_vot_obj_info_t
{
 float pitch_relative; /*< relative pitch.*/
 int16_t top_left_x; /*< origin x.*/
 int16_t top_left_y; /*< origin y.*/
 int16_t width; /*< width.*/
 int16_t height; /*< height.*/
 uint8_t state; /*< information state.*/
} mavlink_vot_obj_info_t;

#define MAVLINK_MSG_ID_VOT_OBJ_INFO_LEN 13
#define MAVLINK_MSG_ID_155_LEN 13

#define MAVLINK_MSG_ID_VOT_OBJ_INFO_CRC 75
#define MAVLINK_MSG_ID_155_CRC 75



#if MAVLINK_MULTI_DIALECT
#define MAVLINK_MESSAGE_INFO_VOT_OBJ_INFO { \
	155, 0, \
	"VOT_OBJ_INFO", \
	6, \
	{  { "pitch_relative", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_vot_obj_info_t, pitch_relative) }, \
         { "top_left_x", NULL, MAVLINK_TYPE_INT16_T, 0, 4, offsetof(mavlink_vot_obj_info_t, top_left_x) }, \
         { "top_left_y", NULL, MAVLINK_TYPE_INT16_T, 0, 6, offsetof(mavlink_vot_obj_info_t, top_left_y) }, \
         { "width", NULL, MAVLINK_TYPE_INT16_T, 0, 8, offsetof(mavlink_vot_obj_info_t, width) }, \
         { "height", NULL, MAVLINK_TYPE_INT16_T, 0, 10, offsetof(mavlink_vot_obj_info_t, height) }, \
         { "state", NULL, MAVLINK_TYPE_UINT8_T, 0, 12, offsetof(mavlink_vot_obj_info_t, state) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_VOT_OBJ_INFO { \
	"VOT_OBJ_INFO", \
	6, \
	{  { "pitch_relative", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_vot_obj_info_t, pitch_relative) }, \
         { "top_left_x", NULL, MAVLINK_TYPE_INT16_T, 0, 4, offsetof(mavlink_vot_obj_info_t, top_left_x) }, \
         { "top_left_y", NULL, MAVLINK_TYPE_INT16_T, 0, 6, offsetof(mavlink_vot_obj_info_t, top_left_y) }, \
         { "width", NULL, MAVLINK_TYPE_INT16_T, 0, 8, offsetof(mavlink_vot_obj_info_t, width) }, \
         { "height", NULL, MAVLINK_TYPE_INT16_T, 0, 10, offsetof(mavlink_vot_obj_info_t, height) }, \
         { "state", NULL, MAVLINK_TYPE_UINT8_T, 0, 12, offsetof(mavlink_vot_obj_info_t, state) }, \
         } \
}
#endif

/**
 * @brief Pack a vot_obj_info message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param top_left_x origin x.
 * @param top_left_y origin y.
 * @param width width.
 * @param height height.
 * @param pitch_relative relative pitch.
 * @param state information state.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_vot_obj_info_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       int16_t top_left_x, int16_t top_left_y, int16_t width, int16_t height, float pitch_relative, uint8_t state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_VOT_OBJ_INFO_LEN];
	_mav_put_float(buf, 0, pitch_relative);
	_mav_put_int16_t(buf, 4, top_left_x);
	_mav_put_int16_t(buf, 6, top_left_y);
	_mav_put_int16_t(buf, 8, width);
	_mav_put_int16_t(buf, 10, height);
	_mav_put_uint8_t(buf, 12, state);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_VOT_OBJ_INFO_LEN);
#else
	mavlink_vot_obj_info_t packet;
	packet.pitch_relative = pitch_relative;
	packet.top_left_x = top_left_x;
	packet.top_left_y = top_left_y;
	packet.width = width;
	packet.height = height;
	packet.state = state;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_VOT_OBJ_INFO_LEN);
#endif

#if MAVLINK_MULTI_DIALECT
	msg->dialect = 0;
#endif
	msg->msgid = MAVLINK_MSG_ID_VOT_OBJ_INFO;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_VOT_OBJ_INFO_LEN, MAVLINK_MSG_ID_VOT_OBJ_INFO_CRC);
}

/**
 * @brief Pack a vot_obj_info message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param top_left_x origin x.
 * @param top_left_y origin y.
 * @param width width.
 * @param height height.
 * @param pitch_relative relative pitch.
 * @param state information state.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_vot_obj_info_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           int16_t top_left_x,int16_t top_left_y,int16_t width,int16_t height,float pitch_relative,uint8_t state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_VOT_OBJ_INFO_LEN];
	_mav_put_float(buf, 0, pitch_relative);
	_mav_put_int16_t(buf, 4, top_left_x);
	_mav_put_int16_t(buf, 6, top_left_y);
	_mav_put_int16_t(buf, 8, width);
	_mav_put_int16_t(buf, 10, height);
	_mav_put_uint8_t(buf, 12, state);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_VOT_OBJ_INFO_LEN);
#else
	mavlink_vot_obj_info_t packet;
	packet.pitch_relative = pitch_relative;
	packet.top_left_x = top_left_x;
	packet.top_left_y = top_left_y;
	packet.width = width;
	packet.height = height;
	packet.state = state;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_VOT_OBJ_INFO_LEN);
#endif

#if MAVLINK_MULTI_DIALECT
	msg->dialect = 0;
#endif
	msg->msgid = MAVLINK_MSG_ID_VOT_OBJ_INFO;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_VOT_OBJ_INFO_LEN, MAVLINK_MSG_ID_VOT_OBJ_INFO_CRC);
}

/**
 * @brief Encode a vot_obj_info struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param vot_obj_info C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_vot_obj_info_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_vot_obj_info_t* vot_obj_info)
{
	return mavlink_msg_vot_obj_info_pack(system_id, component_id, msg, vot_obj_info->top_left_x, vot_obj_info->top_left_y, vot_obj_info->width, vot_obj_info->height, vot_obj_info->pitch_relative, vot_obj_info->state);
}

/**
 * @brief Encode a vot_obj_info struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param vot_obj_info C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_vot_obj_info_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_vot_obj_info_t* vot_obj_info)
{
	return mavlink_msg_vot_obj_info_pack_chan(system_id, component_id, chan, msg, vot_obj_info->top_left_x, vot_obj_info->top_left_y, vot_obj_info->width, vot_obj_info->height, vot_obj_info->pitch_relative, vot_obj_info->state);
}

/**
 * @brief Send a vot_obj_info message
 * @param chan MAVLink channel to send the message
 *
 * @param top_left_x origin x.
 * @param top_left_y origin y.
 * @param width width.
 * @param height height.
 * @param pitch_relative relative pitch.
 * @param state information state.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_vot_obj_info_send(mavlink_channel_t chan, int16_t top_left_x, int16_t top_left_y, int16_t width, int16_t height, float pitch_relative, uint8_t state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_VOT_OBJ_INFO_LEN];
	_mav_put_float(buf, 0, pitch_relative);
	_mav_put_int16_t(buf, 4, top_left_x);
	_mav_put_int16_t(buf, 6, top_left_y);
	_mav_put_int16_t(buf, 8, width);
	_mav_put_int16_t(buf, 10, height);
	_mav_put_uint8_t(buf, 12, state);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VOT_OBJ_INFO, buf, MAVLINK_MSG_ID_VOT_OBJ_INFO_LEN, MAVLINK_MSG_ID_VOT_OBJ_INFO_CRC);
#else
	mavlink_vot_obj_info_t packet;
	packet.pitch_relative = pitch_relative;
	packet.top_left_x = top_left_x;
	packet.top_left_y = top_left_y;
	packet.width = width;
	packet.height = height;
	packet.state = state;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VOT_OBJ_INFO_TUPLE, (const char *)&packet, MAVLINK_MSG_ID_VOT_OBJ_INFO_LEN, MAVLINK_MSG_ID_VOT_OBJ_INFO_CRC);
#endif
}

#if MAVLINK_MSG_ID_VOT_OBJ_INFO_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_vot_obj_info_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  int16_t top_left_x, int16_t top_left_y, int16_t width, int16_t height, float pitch_relative, uint8_t state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_float(buf, 0, pitch_relative);
	_mav_put_int16_t(buf, 4, top_left_x);
	_mav_put_int16_t(buf, 6, top_left_y);
	_mav_put_int16_t(buf, 8, width);
	_mav_put_int16_t(buf, 10, height);
	_mav_put_uint8_t(buf, 12, state);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VOT_OBJ_INFO_TUPLE, buf, MAVLINK_MSG_ID_VOT_OBJ_INFO_LEN, MAVLINK_MSG_ID_VOT_OBJ_INFO_CRC);
#else
	mavlink_vot_obj_info_t *packet = (mavlink_vot_obj_info_t *)msgbuf;
	packet->pitch_relative = pitch_relative;
	packet->top_left_x = top_left_x;
	packet->top_left_y = top_left_y;
	packet->width = width;
	packet->height = height;
	packet->state = state;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VOT_OBJ_INFO_TUPLE, (const char *)packet, MAVLINK_MSG_ID_VOT_OBJ_INFO_LEN, MAVLINK_MSG_ID_VOT_OBJ_INFO_CRC);
#endif
}
#endif

#endif

// MESSAGE VOT_OBJ_INFO UNPACKING


/**
 * @brief Get field top_left_x from vot_obj_info message
 *
 * @return origin x.
 */
static inline int16_t mavlink_msg_vot_obj_info_get_top_left_x(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  4);
}

/**
 * @brief Get field top_left_y from vot_obj_info message
 *
 * @return origin y.
 */
static inline int16_t mavlink_msg_vot_obj_info_get_top_left_y(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  6);
}

/**
 * @brief Get field width from vot_obj_info message
 *
 * @return width.
 */
static inline int16_t mavlink_msg_vot_obj_info_get_width(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  8);
}

/**
 * @brief Get field height from vot_obj_info message
 *
 * @return height.
 */
static inline int16_t mavlink_msg_vot_obj_info_get_height(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  10);
}

/**
 * @brief Get field pitch_relative from vot_obj_info message
 *
 * @return relative pitch.
 */
static inline float mavlink_msg_vot_obj_info_get_pitch_relative(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field state from vot_obj_info message
 *
 * @return information state.
 */
static inline uint8_t mavlink_msg_vot_obj_info_get_state(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  12);
}

/**
 * @brief Decode a vot_obj_info message into a struct
 *
 * @param msg The message to decode
 * @param vot_obj_info C-struct to decode the message contents into
 */
static inline void mavlink_msg_vot_obj_info_decode(const mavlink_message_t* msg, mavlink_vot_obj_info_t* vot_obj_info)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	vot_obj_info->pitch_relative = mavlink_msg_vot_obj_info_get_pitch_relative(msg);
	vot_obj_info->top_left_x = mavlink_msg_vot_obj_info_get_top_left_x(msg);
	vot_obj_info->top_left_y = mavlink_msg_vot_obj_info_get_top_left_y(msg);
	vot_obj_info->width = mavlink_msg_vot_obj_info_get_width(msg);
	vot_obj_info->height = mavlink_msg_vot_obj_info_get_height(msg);
	vot_obj_info->state = mavlink_msg_vot_obj_info_get_state(msg);
#else
	memcpy(vot_obj_info, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_VOT_OBJ_INFO_LEN);
#endif
}
