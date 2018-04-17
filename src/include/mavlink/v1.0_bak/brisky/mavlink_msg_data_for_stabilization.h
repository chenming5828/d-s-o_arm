// MESSAGE DATA_FOR_STABILIZATION PACKING

#define MAVLINK_MSG_ID_DATA_FOR_STABILIZATION 153
#if MAVLINK_MULTI_DIALECT
#define MAVLINK_MSG_ID_DATA_FOR_STABILIZATION_TUPLE 0, MAVLINK_MSG_ID_DATA_FOR_STABILIZATION
#else
#define MAVLINK_MSG_ID_DATA_FOR_STABILIZATION_TUPLE MAVLINK_MSG_ID_DATA_FOR_STABILIZATION
#endif

typedef struct __mavlink_data_for_stabilization_t
{
 uint64_t timestamp; /*< Timestamp of the component clock since boot time in milliseconds.*/
 float yaw; /*< Yaw.*/
 float acc_ned_0; /*< Dynamic acceleration ned x.*/
 float acc_ned_1; /*< Dynamic acceleration ned y.*/
 float acc_ned_2; /*< Dynamic acceleration ned z.*/
} mavlink_data_for_stabilization_t;

#define MAVLINK_MSG_ID_DATA_FOR_STABILIZATION_LEN 24
#define MAVLINK_MSG_ID_153_LEN 24

#define MAVLINK_MSG_ID_DATA_FOR_STABILIZATION_CRC 181
#define MAVLINK_MSG_ID_153_CRC 181



#if MAVLINK_MULTI_DIALECT
#define MAVLINK_MESSAGE_INFO_DATA_FOR_STABILIZATION { \
	153, 0, \
	"DATA_FOR_STABILIZATION", \
	5, \
	{  { "timestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_data_for_stabilization_t, timestamp) }, \
         { "yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_data_for_stabilization_t, yaw) }, \
         { "acc_ned_0", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_data_for_stabilization_t, acc_ned_0) }, \
         { "acc_ned_1", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_data_for_stabilization_t, acc_ned_1) }, \
         { "acc_ned_2", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_data_for_stabilization_t, acc_ned_2) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_DATA_FOR_STABILIZATION { \
	"DATA_FOR_STABILIZATION", \
	5, \
	{  { "timestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_data_for_stabilization_t, timestamp) }, \
         { "yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_data_for_stabilization_t, yaw) }, \
         { "acc_ned_0", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_data_for_stabilization_t, acc_ned_0) }, \
         { "acc_ned_1", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_data_for_stabilization_t, acc_ned_1) }, \
         { "acc_ned_2", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_data_for_stabilization_t, acc_ned_2) }, \
         } \
}
#endif

/**
 * @brief Pack a data_for_stabilization message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param timestamp Timestamp of the component clock since boot time in milliseconds.
 * @param yaw Yaw.
 * @param acc_ned_0 Dynamic acceleration ned x.
 * @param acc_ned_1 Dynamic acceleration ned y.
 * @param acc_ned_2 Dynamic acceleration ned z.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_data_for_stabilization_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint64_t timestamp, float yaw, float acc_ned_0, float acc_ned_1, float acc_ned_2)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_DATA_FOR_STABILIZATION_LEN];
	_mav_put_uint64_t(buf, 0, timestamp);
	_mav_put_float(buf, 8, yaw);
	_mav_put_float(buf, 12, acc_ned_0);
	_mav_put_float(buf, 16, acc_ned_1);
	_mav_put_float(buf, 20, acc_ned_2);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_DATA_FOR_STABILIZATION_LEN);
#else
	mavlink_data_for_stabilization_t packet;
	packet.timestamp = timestamp;
	packet.yaw = yaw;
	packet.acc_ned_0 = acc_ned_0;
	packet.acc_ned_1 = acc_ned_1;
	packet.acc_ned_2 = acc_ned_2;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_DATA_FOR_STABILIZATION_LEN);
#endif

#if MAVLINK_MULTI_DIALECT
	msg->dialect = 0;
#endif
	msg->msgid = MAVLINK_MSG_ID_DATA_FOR_STABILIZATION;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_DATA_FOR_STABILIZATION_LEN, MAVLINK_MSG_ID_DATA_FOR_STABILIZATION_CRC);
}

/**
 * @brief Pack a data_for_stabilization message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param timestamp Timestamp of the component clock since boot time in milliseconds.
 * @param yaw Yaw.
 * @param acc_ned_0 Dynamic acceleration ned x.
 * @param acc_ned_1 Dynamic acceleration ned y.
 * @param acc_ned_2 Dynamic acceleration ned z.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_data_for_stabilization_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint64_t timestamp,float yaw,float acc_ned_0,float acc_ned_1,float acc_ned_2)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_DATA_FOR_STABILIZATION_LEN];
	_mav_put_uint64_t(buf, 0, timestamp);
	_mav_put_float(buf, 8, yaw);
	_mav_put_float(buf, 12, acc_ned_0);
	_mav_put_float(buf, 16, acc_ned_1);
	_mav_put_float(buf, 20, acc_ned_2);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_DATA_FOR_STABILIZATION_LEN);
#else
	mavlink_data_for_stabilization_t packet;
	packet.timestamp = timestamp;
	packet.yaw = yaw;
	packet.acc_ned_0 = acc_ned_0;
	packet.acc_ned_1 = acc_ned_1;
	packet.acc_ned_2 = acc_ned_2;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_DATA_FOR_STABILIZATION_LEN);
#endif

#if MAVLINK_MULTI_DIALECT
	msg->dialect = 0;
#endif
	msg->msgid = MAVLINK_MSG_ID_DATA_FOR_STABILIZATION;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_DATA_FOR_STABILIZATION_LEN, MAVLINK_MSG_ID_DATA_FOR_STABILIZATION_CRC);
}

/**
 * @brief Encode a data_for_stabilization struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param data_for_stabilization C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_data_for_stabilization_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_data_for_stabilization_t* data_for_stabilization)
{
	return mavlink_msg_data_for_stabilization_pack(system_id, component_id, msg, data_for_stabilization->timestamp, data_for_stabilization->yaw, data_for_stabilization->acc_ned_0, data_for_stabilization->acc_ned_1, data_for_stabilization->acc_ned_2);
}

/**
 * @brief Encode a data_for_stabilization struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param data_for_stabilization C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_data_for_stabilization_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_data_for_stabilization_t* data_for_stabilization)
{
	return mavlink_msg_data_for_stabilization_pack_chan(system_id, component_id, chan, msg, data_for_stabilization->timestamp, data_for_stabilization->yaw, data_for_stabilization->acc_ned_0, data_for_stabilization->acc_ned_1, data_for_stabilization->acc_ned_2);
}

/**
 * @brief Send a data_for_stabilization message
 * @param chan MAVLink channel to send the message
 *
 * @param timestamp Timestamp of the component clock since boot time in milliseconds.
 * @param yaw Yaw.
 * @param acc_ned_0 Dynamic acceleration ned x.
 * @param acc_ned_1 Dynamic acceleration ned y.
 * @param acc_ned_2 Dynamic acceleration ned z.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_data_for_stabilization_send(mavlink_channel_t chan, uint64_t timestamp, float yaw, float acc_ned_0, float acc_ned_1, float acc_ned_2)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_DATA_FOR_STABILIZATION_LEN];
	_mav_put_uint64_t(buf, 0, timestamp);
	_mav_put_float(buf, 8, yaw);
	_mav_put_float(buf, 12, acc_ned_0);
	_mav_put_float(buf, 16, acc_ned_1);
	_mav_put_float(buf, 20, acc_ned_2);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DATA_FOR_STABILIZATION, buf, MAVLINK_MSG_ID_DATA_FOR_STABILIZATION_LEN, MAVLINK_MSG_ID_DATA_FOR_STABILIZATION_CRC);
#else
	mavlink_data_for_stabilization_t packet;
	packet.timestamp = timestamp;
	packet.yaw = yaw;
	packet.acc_ned_0 = acc_ned_0;
	packet.acc_ned_1 = acc_ned_1;
	packet.acc_ned_2 = acc_ned_2;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DATA_FOR_STABILIZATION_TUPLE, (const char *)&packet, MAVLINK_MSG_ID_DATA_FOR_STABILIZATION_LEN, MAVLINK_MSG_ID_DATA_FOR_STABILIZATION_CRC);
#endif
}

#if MAVLINK_MSG_ID_DATA_FOR_STABILIZATION_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_data_for_stabilization_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t timestamp, float yaw, float acc_ned_0, float acc_ned_1, float acc_ned_2)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint64_t(buf, 0, timestamp);
	_mav_put_float(buf, 8, yaw);
	_mav_put_float(buf, 12, acc_ned_0);
	_mav_put_float(buf, 16, acc_ned_1);
	_mav_put_float(buf, 20, acc_ned_2);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DATA_FOR_STABILIZATION_TUPLE, buf, MAVLINK_MSG_ID_DATA_FOR_STABILIZATION_LEN, MAVLINK_MSG_ID_DATA_FOR_STABILIZATION_CRC);
#else
	mavlink_data_for_stabilization_t *packet = (mavlink_data_for_stabilization_t *)msgbuf;
	packet->timestamp = timestamp;
	packet->yaw = yaw;
	packet->acc_ned_0 = acc_ned_0;
	packet->acc_ned_1 = acc_ned_1;
	packet->acc_ned_2 = acc_ned_2;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DATA_FOR_STABILIZATION_TUPLE, (const char *)packet, MAVLINK_MSG_ID_DATA_FOR_STABILIZATION_LEN, MAVLINK_MSG_ID_DATA_FOR_STABILIZATION_CRC);
#endif
}
#endif

#endif

// MESSAGE DATA_FOR_STABILIZATION UNPACKING


/**
 * @brief Get field timestamp from data_for_stabilization message
 *
 * @return Timestamp of the component clock since boot time in milliseconds.
 */
static inline uint64_t mavlink_msg_data_for_stabilization_get_timestamp(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field yaw from data_for_stabilization message
 *
 * @return Yaw.
 */
static inline float mavlink_msg_data_for_stabilization_get_yaw(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field acc_ned_0 from data_for_stabilization message
 *
 * @return Dynamic acceleration ned x.
 */
static inline float mavlink_msg_data_for_stabilization_get_acc_ned_0(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field acc_ned_1 from data_for_stabilization message
 *
 * @return Dynamic acceleration ned y.
 */
static inline float mavlink_msg_data_for_stabilization_get_acc_ned_1(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field acc_ned_2 from data_for_stabilization message
 *
 * @return Dynamic acceleration ned z.
 */
static inline float mavlink_msg_data_for_stabilization_get_acc_ned_2(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Decode a data_for_stabilization message into a struct
 *
 * @param msg The message to decode
 * @param data_for_stabilization C-struct to decode the message contents into
 */
static inline void mavlink_msg_data_for_stabilization_decode(const mavlink_message_t* msg, mavlink_data_for_stabilization_t* data_for_stabilization)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	data_for_stabilization->timestamp = mavlink_msg_data_for_stabilization_get_timestamp(msg);
	data_for_stabilization->yaw = mavlink_msg_data_for_stabilization_get_yaw(msg);
	data_for_stabilization->acc_ned_0 = mavlink_msg_data_for_stabilization_get_acc_ned_0(msg);
	data_for_stabilization->acc_ned_1 = mavlink_msg_data_for_stabilization_get_acc_ned_1(msg);
	data_for_stabilization->acc_ned_2 = mavlink_msg_data_for_stabilization_get_acc_ned_2(msg);
#else
	memcpy(data_for_stabilization, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_DATA_FOR_STABILIZATION_LEN);
#endif
}
