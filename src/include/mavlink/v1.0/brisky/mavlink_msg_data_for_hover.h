// MESSAGE DATA_FOR_HOVER PACKING

#define MAVLINK_MSG_ID_DATA_FOR_HOVER 152
#if MAVLINK_MULTI_DIALECT
#define MAVLINK_MSG_ID_DATA_FOR_HOVER_TUPLE 0, MAVLINK_MSG_ID_DATA_FOR_HOVER
#else
#define MAVLINK_MSG_ID_DATA_FOR_HOVER_TUPLE MAVLINK_MSG_ID_DATA_FOR_HOVER
#endif

typedef struct __mavlink_data_for_hover_t
{
 uint64_t timestamp; /*< Timestamp of the component clock since boot time in milliseconds.*/
 float current_distance; /*< Downward infrared distance.*/
 float q0; /*< Attitude q0.*/
 float q1; /*< Attitude q1.*/
 float q2; /*< Attitude q2.*/
 float q3; /*< Attitude q3.*/
 float R; /*< Atti R(3,3).*/
 float x; /*< Local position x.*/
 float y; /*< Local position y.*/
 float z; /*< Local position z.*/
} mavlink_data_for_hover_t;

#define MAVLINK_MSG_ID_DATA_FOR_HOVER_LEN 44
#define MAVLINK_MSG_ID_152_LEN 44

#define MAVLINK_MSG_ID_DATA_FOR_HOVER_CRC 27
#define MAVLINK_MSG_ID_152_CRC 27



#if MAVLINK_MULTI_DIALECT
#define MAVLINK_MESSAGE_INFO_DATA_FOR_HOVER { \
	152, 0, \
	"DATA_FOR_HOVER", \
	10, \
	{  { "timestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_data_for_hover_t, timestamp) }, \
         { "current_distance", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_data_for_hover_t, current_distance) }, \
         { "q0", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_data_for_hover_t, q0) }, \
         { "q1", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_data_for_hover_t, q1) }, \
         { "q2", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_data_for_hover_t, q2) }, \
         { "q3", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_data_for_hover_t, q3) }, \
         { "R", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_data_for_hover_t, R) }, \
         { "x", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_data_for_hover_t, x) }, \
         { "y", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_data_for_hover_t, y) }, \
         { "z", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_data_for_hover_t, z) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_DATA_FOR_HOVER { \
	"DATA_FOR_HOVER", \
	10, \
	{  { "timestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_data_for_hover_t, timestamp) }, \
         { "current_distance", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_data_for_hover_t, current_distance) }, \
         { "q0", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_data_for_hover_t, q0) }, \
         { "q1", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_data_for_hover_t, q1) }, \
         { "q2", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_data_for_hover_t, q2) }, \
         { "q3", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_data_for_hover_t, q3) }, \
         { "R", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_data_for_hover_t, R) }, \
         { "x", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_data_for_hover_t, x) }, \
         { "y", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_data_for_hover_t, y) }, \
         { "z", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_data_for_hover_t, z) }, \
         } \
}
#endif

/**
 * @brief Pack a data_for_hover message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param timestamp Timestamp of the component clock since boot time in milliseconds.
 * @param current_distance Downward infrared distance.
 * @param q0 Attitude q0.
 * @param q1 Attitude q1.
 * @param q2 Attitude q2.
 * @param q3 Attitude q3.
 * @param R Atti R(3,3).
 * @param x Local position x.
 * @param y Local position y.
 * @param z Local position z.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_data_for_hover_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint64_t timestamp, float current_distance, float q0, float q1, float q2, float q3, float R, float x, float y, float z)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_DATA_FOR_HOVER_LEN];
	_mav_put_uint64_t(buf, 0, timestamp);
	_mav_put_float(buf, 8, current_distance);
	_mav_put_float(buf, 12, q0);
	_mav_put_float(buf, 16, q1);
	_mav_put_float(buf, 20, q2);
	_mav_put_float(buf, 24, q3);
	_mav_put_float(buf, 28, R);
	_mav_put_float(buf, 32, x);
	_mav_put_float(buf, 36, y);
	_mav_put_float(buf, 40, z);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_DATA_FOR_HOVER_LEN);
#else
	mavlink_data_for_hover_t packet;
	packet.timestamp = timestamp;
	packet.current_distance = current_distance;
	packet.q0 = q0;
	packet.q1 = q1;
	packet.q2 = q2;
	packet.q3 = q3;
	packet.R = R;
	packet.x = x;
	packet.y = y;
	packet.z = z;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_DATA_FOR_HOVER_LEN);
#endif

#if MAVLINK_MULTI_DIALECT
	msg->dialect = 0;
#endif
	msg->msgid = MAVLINK_MSG_ID_DATA_FOR_HOVER;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_DATA_FOR_HOVER_LEN, MAVLINK_MSG_ID_DATA_FOR_HOVER_CRC);
}

/**
 * @brief Pack a data_for_hover message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param timestamp Timestamp of the component clock since boot time in milliseconds.
 * @param current_distance Downward infrared distance.
 * @param q0 Attitude q0.
 * @param q1 Attitude q1.
 * @param q2 Attitude q2.
 * @param q3 Attitude q3.
 * @param R Atti R(3,3).
 * @param x Local position x.
 * @param y Local position y.
 * @param z Local position z.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_data_for_hover_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint64_t timestamp,float current_distance,float q0,float q1,float q2,float q3,float R,float x,float y,float z)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_DATA_FOR_HOVER_LEN];
	_mav_put_uint64_t(buf, 0, timestamp);
	_mav_put_float(buf, 8, current_distance);
	_mav_put_float(buf, 12, q0);
	_mav_put_float(buf, 16, q1);
	_mav_put_float(buf, 20, q2);
	_mav_put_float(buf, 24, q3);
	_mav_put_float(buf, 28, R);
	_mav_put_float(buf, 32, x);
	_mav_put_float(buf, 36, y);
	_mav_put_float(buf, 40, z);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_DATA_FOR_HOVER_LEN);
#else
	mavlink_data_for_hover_t packet;
	packet.timestamp = timestamp;
	packet.current_distance = current_distance;
	packet.q0 = q0;
	packet.q1 = q1;
	packet.q2 = q2;
	packet.q3 = q3;
	packet.R = R;
	packet.x = x;
	packet.y = y;
	packet.z = z;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_DATA_FOR_HOVER_LEN);
#endif

#if MAVLINK_MULTI_DIALECT
	msg->dialect = 0;
#endif
	msg->msgid = MAVLINK_MSG_ID_DATA_FOR_HOVER;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_DATA_FOR_HOVER_LEN, MAVLINK_MSG_ID_DATA_FOR_HOVER_CRC);
}

/**
 * @brief Encode a data_for_hover struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param data_for_hover C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_data_for_hover_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_data_for_hover_t* data_for_hover)
{
	return mavlink_msg_data_for_hover_pack(system_id, component_id, msg, data_for_hover->timestamp, data_for_hover->current_distance, data_for_hover->q0, data_for_hover->q1, data_for_hover->q2, data_for_hover->q3, data_for_hover->R, data_for_hover->x, data_for_hover->y, data_for_hover->z);
}

/**
 * @brief Encode a data_for_hover struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param data_for_hover C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_data_for_hover_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_data_for_hover_t* data_for_hover)
{
	return mavlink_msg_data_for_hover_pack_chan(system_id, component_id, chan, msg, data_for_hover->timestamp, data_for_hover->current_distance, data_for_hover->q0, data_for_hover->q1, data_for_hover->q2, data_for_hover->q3, data_for_hover->R, data_for_hover->x, data_for_hover->y, data_for_hover->z);
}

/**
 * @brief Send a data_for_hover message
 * @param chan MAVLink channel to send the message
 *
 * @param timestamp Timestamp of the component clock since boot time in milliseconds.
 * @param current_distance Downward infrared distance.
 * @param q0 Attitude q0.
 * @param q1 Attitude q1.
 * @param q2 Attitude q2.
 * @param q3 Attitude q3.
 * @param R Atti R(3,3).
 * @param x Local position x.
 * @param y Local position y.
 * @param z Local position z.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_data_for_hover_send(mavlink_channel_t chan, uint64_t timestamp, float current_distance, float q0, float q1, float q2, float q3, float R, float x, float y, float z)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_DATA_FOR_HOVER_LEN];
	_mav_put_uint64_t(buf, 0, timestamp);
	_mav_put_float(buf, 8, current_distance);
	_mav_put_float(buf, 12, q0);
	_mav_put_float(buf, 16, q1);
	_mav_put_float(buf, 20, q2);
	_mav_put_float(buf, 24, q3);
	_mav_put_float(buf, 28, R);
	_mav_put_float(buf, 32, x);
	_mav_put_float(buf, 36, y);
	_mav_put_float(buf, 40, z);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DATA_FOR_HOVER, buf, MAVLINK_MSG_ID_DATA_FOR_HOVER_LEN, MAVLINK_MSG_ID_DATA_FOR_HOVER_CRC);
#else
	mavlink_data_for_hover_t packet;
	packet.timestamp = timestamp;
	packet.current_distance = current_distance;
	packet.q0 = q0;
	packet.q1 = q1;
	packet.q2 = q2;
	packet.q3 = q3;
	packet.R = R;
	packet.x = x;
	packet.y = y;
	packet.z = z;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DATA_FOR_HOVER_TUPLE, (const char *)&packet, MAVLINK_MSG_ID_DATA_FOR_HOVER_LEN, MAVLINK_MSG_ID_DATA_FOR_HOVER_CRC);
#endif
}

#if MAVLINK_MSG_ID_DATA_FOR_HOVER_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_data_for_hover_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t timestamp, float current_distance, float q0, float q1, float q2, float q3, float R, float x, float y, float z)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint64_t(buf, 0, timestamp);
	_mav_put_float(buf, 8, current_distance);
	_mav_put_float(buf, 12, q0);
	_mav_put_float(buf, 16, q1);
	_mav_put_float(buf, 20, q2);
	_mav_put_float(buf, 24, q3);
	_mav_put_float(buf, 28, R);
	_mav_put_float(buf, 32, x);
	_mav_put_float(buf, 36, y);
	_mav_put_float(buf, 40, z);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DATA_FOR_HOVER_TUPLE, buf, MAVLINK_MSG_ID_DATA_FOR_HOVER_LEN, MAVLINK_MSG_ID_DATA_FOR_HOVER_CRC);
#else
	mavlink_data_for_hover_t *packet = (mavlink_data_for_hover_t *)msgbuf;
	packet->timestamp = timestamp;
	packet->current_distance = current_distance;
	packet->q0 = q0;
	packet->q1 = q1;
	packet->q2 = q2;
	packet->q3 = q3;
	packet->R = R;
	packet->x = x;
	packet->y = y;
	packet->z = z;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DATA_FOR_HOVER_TUPLE, (const char *)packet, MAVLINK_MSG_ID_DATA_FOR_HOVER_LEN, MAVLINK_MSG_ID_DATA_FOR_HOVER_CRC);
#endif
}
#endif

#endif

// MESSAGE DATA_FOR_HOVER UNPACKING


/**
 * @brief Get field timestamp from data_for_hover message
 *
 * @return Timestamp of the component clock since boot time in milliseconds.
 */
static inline uint64_t mavlink_msg_data_for_hover_get_timestamp(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field current_distance from data_for_hover message
 *
 * @return Downward infrared distance.
 */
static inline float mavlink_msg_data_for_hover_get_current_distance(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field q0 from data_for_hover message
 *
 * @return Attitude q0.
 */
static inline float mavlink_msg_data_for_hover_get_q0(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field q1 from data_for_hover message
 *
 * @return Attitude q1.
 */
static inline float mavlink_msg_data_for_hover_get_q1(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field q2 from data_for_hover message
 *
 * @return Attitude q2.
 */
static inline float mavlink_msg_data_for_hover_get_q2(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field q3 from data_for_hover message
 *
 * @return Attitude q3.
 */
static inline float mavlink_msg_data_for_hover_get_q3(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Get field R from data_for_hover message
 *
 * @return Atti R(3,3).
 */
static inline float mavlink_msg_data_for_hover_get_R(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  28);
}

/**
 * @brief Get field x from data_for_hover message
 *
 * @return Local position x.
 */
static inline float mavlink_msg_data_for_hover_get_x(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  32);
}

/**
 * @brief Get field y from data_for_hover message
 *
 * @return Local position y.
 */
static inline float mavlink_msg_data_for_hover_get_y(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  36);
}

/**
 * @brief Get field z from data_for_hover message
 *
 * @return Local position z.
 */
static inline float mavlink_msg_data_for_hover_get_z(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  40);
}

/**
 * @brief Decode a data_for_hover message into a struct
 *
 * @param msg The message to decode
 * @param data_for_hover C-struct to decode the message contents into
 */
static inline void mavlink_msg_data_for_hover_decode(const mavlink_message_t* msg, mavlink_data_for_hover_t* data_for_hover)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	data_for_hover->timestamp = mavlink_msg_data_for_hover_get_timestamp(msg);
	data_for_hover->current_distance = mavlink_msg_data_for_hover_get_current_distance(msg);
	data_for_hover->q0 = mavlink_msg_data_for_hover_get_q0(msg);
	data_for_hover->q1 = mavlink_msg_data_for_hover_get_q1(msg);
	data_for_hover->q2 = mavlink_msg_data_for_hover_get_q2(msg);
	data_for_hover->q3 = mavlink_msg_data_for_hover_get_q3(msg);
	data_for_hover->R = mavlink_msg_data_for_hover_get_R(msg);
	data_for_hover->x = mavlink_msg_data_for_hover_get_x(msg);
	data_for_hover->y = mavlink_msg_data_for_hover_get_y(msg);
	data_for_hover->z = mavlink_msg_data_for_hover_get_z(msg);
#else
	memcpy(data_for_hover, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_DATA_FOR_HOVER_LEN);
#endif
}
