// MESSAGE SVO_POSITION_RAW PACKING

#define MAVLINK_MSG_ID_SVO_POSITION_RAW 151
#if MAVLINK_MULTI_DIALECT
#define MAVLINK_MSG_ID_SVO_POSITION_RAW_TUPLE 0, MAVLINK_MSG_ID_SVO_POSITION_RAW
#else
#define MAVLINK_MSG_ID_SVO_POSITION_RAW_TUPLE MAVLINK_MSG_ID_SVO_POSITION_RAW
#endif

typedef struct __mavlink_svo_position_raw_t
{
 uint64_t timestamp; /*< Timestamp of the component clock since boot time in milliseconds.*/
 float position_x; /*< position x.*/
 float position_y; /*< position y.*/
 float position_z; /*< position z.*/
 float q0; /*< q0.*/
 float q1; /*< q1.*/
 float q2; /*< q2.*/
 float q3; /*< q3.*/
 uint8_t svo_valid; /*< Current svo state.*/
} mavlink_svo_position_raw_t;

#define MAVLINK_MSG_ID_SVO_POSITION_RAW_LEN 37
#define MAVLINK_MSG_ID_151_LEN 37

#define MAVLINK_MSG_ID_SVO_POSITION_RAW_CRC 8
#define MAVLINK_MSG_ID_151_CRC 8



#if MAVLINK_MULTI_DIALECT
#define MAVLINK_MESSAGE_INFO_SVO_POSITION_RAW { \
	151, 0, \
	"SVO_POSITION_RAW", \
	9, \
	{  { "timestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_svo_position_raw_t, timestamp) }, \
         { "position_x", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_svo_position_raw_t, position_x) }, \
         { "position_y", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_svo_position_raw_t, position_y) }, \
         { "position_z", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_svo_position_raw_t, position_z) }, \
         { "q0", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_svo_position_raw_t, q0) }, \
         { "q1", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_svo_position_raw_t, q1) }, \
         { "q2", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_svo_position_raw_t, q2) }, \
         { "q3", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_svo_position_raw_t, q3) }, \
         { "svo_valid", NULL, MAVLINK_TYPE_UINT8_T, 0, 36, offsetof(mavlink_svo_position_raw_t, svo_valid) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_SVO_POSITION_RAW { \
	"SVO_POSITION_RAW", \
	9, \
	{  { "timestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_svo_position_raw_t, timestamp) }, \
         { "position_x", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_svo_position_raw_t, position_x) }, \
         { "position_y", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_svo_position_raw_t, position_y) }, \
         { "position_z", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_svo_position_raw_t, position_z) }, \
         { "q0", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_svo_position_raw_t, q0) }, \
         { "q1", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_svo_position_raw_t, q1) }, \
         { "q2", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_svo_position_raw_t, q2) }, \
         { "q3", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_svo_position_raw_t, q3) }, \
         { "svo_valid", NULL, MAVLINK_TYPE_UINT8_T, 0, 36, offsetof(mavlink_svo_position_raw_t, svo_valid) }, \
         } \
}
#endif

/**
 * @brief Pack a svo_position_raw message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param timestamp Timestamp of the component clock since boot time in milliseconds.
 * @param position_x position x.
 * @param position_y position y.
 * @param position_z position z.
 * @param q0 q0.
 * @param q1 q1.
 * @param q2 q2.
 * @param q3 q3.
 * @param svo_valid Current svo state.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_svo_position_raw_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint64_t timestamp, float position_x, float position_y, float position_z, float q0, float q1, float q2, float q3, uint8_t svo_valid)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_SVO_POSITION_RAW_LEN];
	_mav_put_uint64_t(buf, 0, timestamp);
	_mav_put_float(buf, 8, position_x);
	_mav_put_float(buf, 12, position_y);
	_mav_put_float(buf, 16, position_z);
	_mav_put_float(buf, 20, q0);
	_mav_put_float(buf, 24, q1);
	_mav_put_float(buf, 28, q2);
	_mav_put_float(buf, 32, q3);
	_mav_put_uint8_t(buf, 36, svo_valid);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SVO_POSITION_RAW_LEN);
#else
	mavlink_svo_position_raw_t packet;
	packet.timestamp = timestamp;
	packet.position_x = position_x;
	packet.position_y = position_y;
	packet.position_z = position_z;
	packet.q0 = q0;
	packet.q1 = q1;
	packet.q2 = q2;
	packet.q3 = q3;
	packet.svo_valid = svo_valid;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SVO_POSITION_RAW_LEN);
#endif

#if MAVLINK_MULTI_DIALECT
	msg->dialect = 0;
#endif
	msg->msgid = MAVLINK_MSG_ID_SVO_POSITION_RAW;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SVO_POSITION_RAW_LEN, MAVLINK_MSG_ID_SVO_POSITION_RAW_CRC);
}

/**
 * @brief Pack a svo_position_raw message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param timestamp Timestamp of the component clock since boot time in milliseconds.
 * @param position_x position x.
 * @param position_y position y.
 * @param position_z position z.
 * @param q0 q0.
 * @param q1 q1.
 * @param q2 q2.
 * @param q3 q3.
 * @param svo_valid Current svo state.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_svo_position_raw_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint64_t timestamp,float position_x,float position_y,float position_z,float q0,float q1,float q2,float q3,uint8_t svo_valid)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_SVO_POSITION_RAW_LEN];
	_mav_put_uint64_t(buf, 0, timestamp);
	_mav_put_float(buf, 8, position_x);
	_mav_put_float(buf, 12, position_y);
	_mav_put_float(buf, 16, position_z);
	_mav_put_float(buf, 20, q0);
	_mav_put_float(buf, 24, q1);
	_mav_put_float(buf, 28, q2);
	_mav_put_float(buf, 32, q3);
	_mav_put_uint8_t(buf, 36, svo_valid);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SVO_POSITION_RAW_LEN);
#else
	mavlink_svo_position_raw_t packet;
	packet.timestamp = timestamp;
	packet.position_x = position_x;
	packet.position_y = position_y;
	packet.position_z = position_z;
	packet.q0 = q0;
	packet.q1 = q1;
	packet.q2 = q2;
	packet.q3 = q3;
	packet.svo_valid = svo_valid;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SVO_POSITION_RAW_LEN);
#endif

#if MAVLINK_MULTI_DIALECT
	msg->dialect = 0;
#endif
	msg->msgid = MAVLINK_MSG_ID_SVO_POSITION_RAW;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SVO_POSITION_RAW_LEN, MAVLINK_MSG_ID_SVO_POSITION_RAW_CRC);
}

/**
 * @brief Encode a svo_position_raw struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param svo_position_raw C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_svo_position_raw_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_svo_position_raw_t* svo_position_raw)
{
	return mavlink_msg_svo_position_raw_pack(system_id, component_id, msg, svo_position_raw->timestamp, svo_position_raw->position_x, svo_position_raw->position_y, svo_position_raw->position_z, svo_position_raw->q0, svo_position_raw->q1, svo_position_raw->q2, svo_position_raw->q3, svo_position_raw->svo_valid);
}

/**
 * @brief Encode a svo_position_raw struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param svo_position_raw C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_svo_position_raw_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_svo_position_raw_t* svo_position_raw)
{
	return mavlink_msg_svo_position_raw_pack_chan(system_id, component_id, chan, msg, svo_position_raw->timestamp, svo_position_raw->position_x, svo_position_raw->position_y, svo_position_raw->position_z, svo_position_raw->q0, svo_position_raw->q1, svo_position_raw->q2, svo_position_raw->q3, svo_position_raw->svo_valid);
}

/**
 * @brief Send a svo_position_raw message
 * @param chan MAVLink channel to send the message
 *
 * @param timestamp Timestamp of the component clock since boot time in milliseconds.
 * @param position_x position x.
 * @param position_y position y.
 * @param position_z position z.
 * @param q0 q0.
 * @param q1 q1.
 * @param q2 q2.
 * @param q3 q3.
 * @param svo_valid Current svo state.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_svo_position_raw_send(mavlink_channel_t chan, uint64_t timestamp, float position_x, float position_y, float position_z, float q0, float q1, float q2, float q3, uint8_t svo_valid)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_SVO_POSITION_RAW_LEN];
	_mav_put_uint64_t(buf, 0, timestamp);
	_mav_put_float(buf, 8, position_x);
	_mav_put_float(buf, 12, position_y);
	_mav_put_float(buf, 16, position_z);
	_mav_put_float(buf, 20, q0);
	_mav_put_float(buf, 24, q1);
	_mav_put_float(buf, 28, q2);
	_mav_put_float(buf, 32, q3);
	_mav_put_uint8_t(buf, 36, svo_valid);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SVO_POSITION_RAW, buf, MAVLINK_MSG_ID_SVO_POSITION_RAW_LEN, MAVLINK_MSG_ID_SVO_POSITION_RAW_CRC);
#else
	mavlink_svo_position_raw_t packet;
	packet.timestamp = timestamp;
	packet.position_x = position_x;
	packet.position_y = position_y;
	packet.position_z = position_z;
	packet.q0 = q0;
	packet.q1 = q1;
	packet.q2 = q2;
	packet.q3 = q3;
	packet.svo_valid = svo_valid;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SVO_POSITION_RAW_TUPLE, (const char *)&packet, MAVLINK_MSG_ID_SVO_POSITION_RAW_LEN, MAVLINK_MSG_ID_SVO_POSITION_RAW_CRC);
#endif
}

#if MAVLINK_MSG_ID_SVO_POSITION_RAW_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_svo_position_raw_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t timestamp, float position_x, float position_y, float position_z, float q0, float q1, float q2, float q3, uint8_t svo_valid)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint64_t(buf, 0, timestamp);
	_mav_put_float(buf, 8, position_x);
	_mav_put_float(buf, 12, position_y);
	_mav_put_float(buf, 16, position_z);
	_mav_put_float(buf, 20, q0);
	_mav_put_float(buf, 24, q1);
	_mav_put_float(buf, 28, q2);
	_mav_put_float(buf, 32, q3);
	_mav_put_uint8_t(buf, 36, svo_valid);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SVO_POSITION_RAW_TUPLE, buf, MAVLINK_MSG_ID_SVO_POSITION_RAW_LEN, MAVLINK_MSG_ID_SVO_POSITION_RAW_CRC);
#else
	mavlink_svo_position_raw_t *packet = (mavlink_svo_position_raw_t *)msgbuf;
	packet->timestamp = timestamp;
	packet->position_x = position_x;
	packet->position_y = position_y;
	packet->position_z = position_z;
	packet->q0 = q0;
	packet->q1 = q1;
	packet->q2 = q2;
	packet->q3 = q3;
	packet->svo_valid = svo_valid;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SVO_POSITION_RAW_TUPLE, (const char *)packet, MAVLINK_MSG_ID_SVO_POSITION_RAW_LEN, MAVLINK_MSG_ID_SVO_POSITION_RAW_CRC);
#endif
}
#endif

#endif

// MESSAGE SVO_POSITION_RAW UNPACKING


/**
 * @brief Get field timestamp from svo_position_raw message
 *
 * @return Timestamp of the component clock since boot time in milliseconds.
 */
static inline uint64_t mavlink_msg_svo_position_raw_get_timestamp(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field position_x from svo_position_raw message
 *
 * @return position x.
 */
static inline float mavlink_msg_svo_position_raw_get_position_x(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field position_y from svo_position_raw message
 *
 * @return position y.
 */
static inline float mavlink_msg_svo_position_raw_get_position_y(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field position_z from svo_position_raw message
 *
 * @return position z.
 */
static inline float mavlink_msg_svo_position_raw_get_position_z(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field q0 from svo_position_raw message
 *
 * @return q0.
 */
static inline float mavlink_msg_svo_position_raw_get_q0(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field q1 from svo_position_raw message
 *
 * @return q1.
 */
static inline float mavlink_msg_svo_position_raw_get_q1(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Get field q2 from svo_position_raw message
 *
 * @return q2.
 */
static inline float mavlink_msg_svo_position_raw_get_q2(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  28);
}

/**
 * @brief Get field q3 from svo_position_raw message
 *
 * @return q3.
 */
static inline float mavlink_msg_svo_position_raw_get_q3(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  32);
}

/**
 * @brief Get field svo_valid from svo_position_raw message
 *
 * @return Current svo state.
 */
static inline uint8_t mavlink_msg_svo_position_raw_get_svo_valid(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  36);
}

/**
 * @brief Decode a svo_position_raw message into a struct
 *
 * @param msg The message to decode
 * @param svo_position_raw C-struct to decode the message contents into
 */
static inline void mavlink_msg_svo_position_raw_decode(const mavlink_message_t* msg, mavlink_svo_position_raw_t* svo_position_raw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	svo_position_raw->timestamp = mavlink_msg_svo_position_raw_get_timestamp(msg);
	svo_position_raw->position_x = mavlink_msg_svo_position_raw_get_position_x(msg);
	svo_position_raw->position_y = mavlink_msg_svo_position_raw_get_position_y(msg);
	svo_position_raw->position_z = mavlink_msg_svo_position_raw_get_position_z(msg);
	svo_position_raw->q0 = mavlink_msg_svo_position_raw_get_q0(msg);
	svo_position_raw->q1 = mavlink_msg_svo_position_raw_get_q1(msg);
	svo_position_raw->q2 = mavlink_msg_svo_position_raw_get_q2(msg);
	svo_position_raw->q3 = mavlink_msg_svo_position_raw_get_q3(msg);
	svo_position_raw->svo_valid = mavlink_msg_svo_position_raw_get_svo_valid(msg);
#else
	memcpy(svo_position_raw, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_SVO_POSITION_RAW_LEN);
#endif
}
