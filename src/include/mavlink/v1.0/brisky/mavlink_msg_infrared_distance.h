// MESSAGE INFRARED_DISTANCE PACKING

#define MAVLINK_MSG_ID_INFRARED_DISTANCE 150
#if MAVLINK_MULTI_DIALECT
#define MAVLINK_MSG_ID_INFRARED_DISTANCE_TUPLE 0, MAVLINK_MSG_ID_INFRARED_DISTANCE
#else
#define MAVLINK_MSG_ID_INFRARED_DISTANCE_TUPLE MAVLINK_MSG_ID_INFRARED_DISTANCE
#endif

typedef struct __mavlink_infrared_distance_t
{
 float distance_x_p; /*< Distance of axis x positive.*/
 float distance_x_n; /*< Distance of axis x negative.*/
 float distance_y_p; /*< Distance of axis y positive.*/
 float distance_y_n; /*< Distance of axis y negative.*/
} mavlink_infrared_distance_t;

#define MAVLINK_MSG_ID_INFRARED_DISTANCE_LEN 16
#define MAVLINK_MSG_ID_150_LEN 16

#define MAVLINK_MSG_ID_INFRARED_DISTANCE_CRC 96
#define MAVLINK_MSG_ID_150_CRC 96



#if MAVLINK_MULTI_DIALECT
#define MAVLINK_MESSAGE_INFO_INFRARED_DISTANCE { \
	150, 0, \
	"INFRARED_DISTANCE", \
	4, \
	{  { "distance_x_p", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_infrared_distance_t, distance_x_p) }, \
         { "distance_x_n", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_infrared_distance_t, distance_x_n) }, \
         { "distance_y_p", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_infrared_distance_t, distance_y_p) }, \
         { "distance_y_n", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_infrared_distance_t, distance_y_n) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_INFRARED_DISTANCE { \
	"INFRARED_DISTANCE", \
	4, \
	{  { "distance_x_p", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_infrared_distance_t, distance_x_p) }, \
         { "distance_x_n", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_infrared_distance_t, distance_x_n) }, \
         { "distance_y_p", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_infrared_distance_t, distance_y_p) }, \
         { "distance_y_n", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_infrared_distance_t, distance_y_n) }, \
         } \
}
#endif

/**
 * @brief Pack a infrared_distance message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param distance_x_p Distance of axis x positive.
 * @param distance_x_n Distance of axis x negative.
 * @param distance_y_p Distance of axis y positive.
 * @param distance_y_n Distance of axis y negative.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_infrared_distance_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       float distance_x_p, float distance_x_n, float distance_y_p, float distance_y_n)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_INFRARED_DISTANCE_LEN];
	_mav_put_float(buf, 0, distance_x_p);
	_mav_put_float(buf, 4, distance_x_n);
	_mav_put_float(buf, 8, distance_y_p);
	_mav_put_float(buf, 12, distance_y_n);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_INFRARED_DISTANCE_LEN);
#else
	mavlink_infrared_distance_t packet;
	packet.distance_x_p = distance_x_p;
	packet.distance_x_n = distance_x_n;
	packet.distance_y_p = distance_y_p;
	packet.distance_y_n = distance_y_n;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_INFRARED_DISTANCE_LEN);
#endif

#if MAVLINK_MULTI_DIALECT
	msg->dialect = 0;
#endif
	msg->msgid = MAVLINK_MSG_ID_INFRARED_DISTANCE;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_INFRARED_DISTANCE_LEN, MAVLINK_MSG_ID_INFRARED_DISTANCE_CRC);
}

/**
 * @brief Pack a infrared_distance message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param distance_x_p Distance of axis x positive.
 * @param distance_x_n Distance of axis x negative.
 * @param distance_y_p Distance of axis y positive.
 * @param distance_y_n Distance of axis y negative.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_infrared_distance_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           float distance_x_p,float distance_x_n,float distance_y_p,float distance_y_n)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_INFRARED_DISTANCE_LEN];
	_mav_put_float(buf, 0, distance_x_p);
	_mav_put_float(buf, 4, distance_x_n);
	_mav_put_float(buf, 8, distance_y_p);
	_mav_put_float(buf, 12, distance_y_n);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_INFRARED_DISTANCE_LEN);
#else
	mavlink_infrared_distance_t packet;
	packet.distance_x_p = distance_x_p;
	packet.distance_x_n = distance_x_n;
	packet.distance_y_p = distance_y_p;
	packet.distance_y_n = distance_y_n;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_INFRARED_DISTANCE_LEN);
#endif

#if MAVLINK_MULTI_DIALECT
	msg->dialect = 0;
#endif
	msg->msgid = MAVLINK_MSG_ID_INFRARED_DISTANCE;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_INFRARED_DISTANCE_LEN, MAVLINK_MSG_ID_INFRARED_DISTANCE_CRC);
}

/**
 * @brief Encode a infrared_distance struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param infrared_distance C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_infrared_distance_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_infrared_distance_t* infrared_distance)
{
	return mavlink_msg_infrared_distance_pack(system_id, component_id, msg, infrared_distance->distance_x_p, infrared_distance->distance_x_n, infrared_distance->distance_y_p, infrared_distance->distance_y_n);
}

/**
 * @brief Encode a infrared_distance struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param infrared_distance C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_infrared_distance_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_infrared_distance_t* infrared_distance)
{
	return mavlink_msg_infrared_distance_pack_chan(system_id, component_id, chan, msg, infrared_distance->distance_x_p, infrared_distance->distance_x_n, infrared_distance->distance_y_p, infrared_distance->distance_y_n);
}

/**
 * @brief Send a infrared_distance message
 * @param chan MAVLink channel to send the message
 *
 * @param distance_x_p Distance of axis x positive.
 * @param distance_x_n Distance of axis x negative.
 * @param distance_y_p Distance of axis y positive.
 * @param distance_y_n Distance of axis y negative.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_infrared_distance_send(mavlink_channel_t chan, float distance_x_p, float distance_x_n, float distance_y_p, float distance_y_n)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_INFRARED_DISTANCE_LEN];
	_mav_put_float(buf, 0, distance_x_p);
	_mav_put_float(buf, 4, distance_x_n);
	_mav_put_float(buf, 8, distance_y_p);
	_mav_put_float(buf, 12, distance_y_n);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_INFRARED_DISTANCE, buf, MAVLINK_MSG_ID_INFRARED_DISTANCE_LEN, MAVLINK_MSG_ID_INFRARED_DISTANCE_CRC);
#else
	mavlink_infrared_distance_t packet;
	packet.distance_x_p = distance_x_p;
	packet.distance_x_n = distance_x_n;
	packet.distance_y_p = distance_y_p;
	packet.distance_y_n = distance_y_n;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_INFRARED_DISTANCE_TUPLE, (const char *)&packet, MAVLINK_MSG_ID_INFRARED_DISTANCE_LEN, MAVLINK_MSG_ID_INFRARED_DISTANCE_CRC);
#endif
}

#if MAVLINK_MSG_ID_INFRARED_DISTANCE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_infrared_distance_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  float distance_x_p, float distance_x_n, float distance_y_p, float distance_y_n)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_float(buf, 0, distance_x_p);
	_mav_put_float(buf, 4, distance_x_n);
	_mav_put_float(buf, 8, distance_y_p);
	_mav_put_float(buf, 12, distance_y_n);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_INFRARED_DISTANCE_TUPLE, buf, MAVLINK_MSG_ID_INFRARED_DISTANCE_LEN, MAVLINK_MSG_ID_INFRARED_DISTANCE_CRC);
#else
	mavlink_infrared_distance_t *packet = (mavlink_infrared_distance_t *)msgbuf;
	packet->distance_x_p = distance_x_p;
	packet->distance_x_n = distance_x_n;
	packet->distance_y_p = distance_y_p;
	packet->distance_y_n = distance_y_n;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_INFRARED_DISTANCE_TUPLE, (const char *)packet, MAVLINK_MSG_ID_INFRARED_DISTANCE_LEN, MAVLINK_MSG_ID_INFRARED_DISTANCE_CRC);
#endif
}
#endif

#endif

// MESSAGE INFRARED_DISTANCE UNPACKING


/**
 * @brief Get field distance_x_p from infrared_distance message
 *
 * @return Distance of axis x positive.
 */
static inline float mavlink_msg_infrared_distance_get_distance_x_p(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field distance_x_n from infrared_distance message
 *
 * @return Distance of axis x negative.
 */
static inline float mavlink_msg_infrared_distance_get_distance_x_n(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field distance_y_p from infrared_distance message
 *
 * @return Distance of axis y positive.
 */
static inline float mavlink_msg_infrared_distance_get_distance_y_p(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field distance_y_n from infrared_distance message
 *
 * @return Distance of axis y negative.
 */
static inline float mavlink_msg_infrared_distance_get_distance_y_n(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Decode a infrared_distance message into a struct
 *
 * @param msg The message to decode
 * @param infrared_distance C-struct to decode the message contents into
 */
static inline void mavlink_msg_infrared_distance_decode(const mavlink_message_t* msg, mavlink_infrared_distance_t* infrared_distance)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	infrared_distance->distance_x_p = mavlink_msg_infrared_distance_get_distance_x_p(msg);
	infrared_distance->distance_x_n = mavlink_msg_infrared_distance_get_distance_x_n(msg);
	infrared_distance->distance_y_p = mavlink_msg_infrared_distance_get_distance_y_p(msg);
	infrared_distance->distance_y_n = mavlink_msg_infrared_distance_get_distance_y_n(msg);
#else
	memcpy(infrared_distance, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_INFRARED_DISTANCE_LEN);
#endif
}
