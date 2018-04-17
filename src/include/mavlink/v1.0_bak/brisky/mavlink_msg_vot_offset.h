// MESSAGE VOT_OFFSET PACKING

#define MAVLINK_MSG_ID_VOT_OFFSET 154
#if MAVLINK_MULTI_DIALECT
#define MAVLINK_MSG_ID_VOT_OFFSET_TUPLE 0, MAVLINK_MSG_ID_VOT_OFFSET
#else
#define MAVLINK_MSG_ID_VOT_OFFSET_TUPLE MAVLINK_MSG_ID_VOT_OFFSET
#endif

typedef struct __mavlink_vot_offset_t
{
 uint64_t timestamp; /*< Timestamp of the component clock since boot time in milliseconds.*/
 float xoffset; /*< xoffset.*/
 float yoffset; /*< yoffset.*/
 float pitch_relative; /*< relative pitch.*/
 uint8_t tracking_enabled; /*< visual tracking enabled.*/
} mavlink_vot_offset_t;

#define MAVLINK_MSG_ID_VOT_OFFSET_LEN 21
#define MAVLINK_MSG_ID_154_LEN 21

#define MAVLINK_MSG_ID_VOT_OFFSET_CRC 52
#define MAVLINK_MSG_ID_154_CRC 52



#if MAVLINK_MULTI_DIALECT
#define MAVLINK_MESSAGE_INFO_VOT_OFFSET { \
	154, 0, \
	"VOT_OFFSET", \
	5, \
	{  { "timestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_vot_offset_t, timestamp) }, \
         { "xoffset", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_vot_offset_t, xoffset) }, \
         { "yoffset", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_vot_offset_t, yoffset) }, \
         { "pitch_relative", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_vot_offset_t, pitch_relative) }, \
         { "tracking_enabled", NULL, MAVLINK_TYPE_UINT8_T, 0, 20, offsetof(mavlink_vot_offset_t, tracking_enabled) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_VOT_OFFSET { \
	"VOT_OFFSET", \
	5, \
	{  { "timestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_vot_offset_t, timestamp) }, \
         { "xoffset", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_vot_offset_t, xoffset) }, \
         { "yoffset", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_vot_offset_t, yoffset) }, \
         { "pitch_relative", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_vot_offset_t, pitch_relative) }, \
         { "tracking_enabled", NULL, MAVLINK_TYPE_UINT8_T, 0, 20, offsetof(mavlink_vot_offset_t, tracking_enabled) }, \
         } \
}
#endif

/**
 * @brief Pack a vot_offset message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param timestamp Timestamp of the component clock since boot time in milliseconds.
 * @param xoffset xoffset.
 * @param yoffset yoffset.
 * @param pitch_relative relative pitch.
 * @param tracking_enabled visual tracking enabled.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_vot_offset_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint64_t timestamp, float xoffset, float yoffset, float pitch_relative, uint8_t tracking_enabled)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_VOT_OFFSET_LEN];
	_mav_put_uint64_t(buf, 0, timestamp);
	_mav_put_float(buf, 8, xoffset);
	_mav_put_float(buf, 12, yoffset);
	_mav_put_float(buf, 16, pitch_relative);
	_mav_put_uint8_t(buf, 20, tracking_enabled);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_VOT_OFFSET_LEN);
#else
	mavlink_vot_offset_t packet;
	packet.timestamp = timestamp;
	packet.xoffset = xoffset;
	packet.yoffset = yoffset;
	packet.pitch_relative = pitch_relative;
	packet.tracking_enabled = tracking_enabled;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_VOT_OFFSET_LEN);
#endif

#if MAVLINK_MULTI_DIALECT
	msg->dialect = 0;
#endif
	msg->msgid = MAVLINK_MSG_ID_VOT_OFFSET;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_VOT_OFFSET_LEN, MAVLINK_MSG_ID_VOT_OFFSET_CRC);
}

/**
 * @brief Pack a vot_offset message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param timestamp Timestamp of the component clock since boot time in milliseconds.
 * @param xoffset xoffset.
 * @param yoffset yoffset.
 * @param pitch_relative relative pitch.
 * @param tracking_enabled visual tracking enabled.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_vot_offset_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint64_t timestamp,float xoffset,float yoffset,float pitch_relative,uint8_t tracking_enabled)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_VOT_OFFSET_LEN];
	_mav_put_uint64_t(buf, 0, timestamp);
	_mav_put_float(buf, 8, xoffset);
	_mav_put_float(buf, 12, yoffset);
	_mav_put_float(buf, 16, pitch_relative);
	_mav_put_uint8_t(buf, 20, tracking_enabled);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_VOT_OFFSET_LEN);
#else
	mavlink_vot_offset_t packet;
	packet.timestamp = timestamp;
	packet.xoffset = xoffset;
	packet.yoffset = yoffset;
	packet.pitch_relative = pitch_relative;
	packet.tracking_enabled = tracking_enabled;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_VOT_OFFSET_LEN);
#endif

#if MAVLINK_MULTI_DIALECT
	msg->dialect = 0;
#endif
	msg->msgid = MAVLINK_MSG_ID_VOT_OFFSET;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_VOT_OFFSET_LEN, MAVLINK_MSG_ID_VOT_OFFSET_CRC);
}

/**
 * @brief Encode a vot_offset struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param vot_offset C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_vot_offset_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_vot_offset_t* vot_offset)
{
	return mavlink_msg_vot_offset_pack(system_id, component_id, msg, vot_offset->timestamp, vot_offset->xoffset, vot_offset->yoffset, vot_offset->pitch_relative, vot_offset->tracking_enabled);
}

/**
 * @brief Encode a vot_offset struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param vot_offset C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_vot_offset_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_vot_offset_t* vot_offset)
{
	return mavlink_msg_vot_offset_pack_chan(system_id, component_id, chan, msg, vot_offset->timestamp, vot_offset->xoffset, vot_offset->yoffset, vot_offset->pitch_relative, vot_offset->tracking_enabled);
}

/**
 * @brief Send a vot_offset message
 * @param chan MAVLink channel to send the message
 *
 * @param timestamp Timestamp of the component clock since boot time in milliseconds.
 * @param xoffset xoffset.
 * @param yoffset yoffset.
 * @param pitch_relative relative pitch.
 * @param tracking_enabled visual tracking enabled.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_vot_offset_send(mavlink_channel_t chan, uint64_t timestamp, float xoffset, float yoffset, float pitch_relative, uint8_t tracking_enabled)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_VOT_OFFSET_LEN];
	_mav_put_uint64_t(buf, 0, timestamp);
	_mav_put_float(buf, 8, xoffset);
	_mav_put_float(buf, 12, yoffset);
	_mav_put_float(buf, 16, pitch_relative);
	_mav_put_uint8_t(buf, 20, tracking_enabled);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VOT_OFFSET, buf, MAVLINK_MSG_ID_VOT_OFFSET_LEN, MAVLINK_MSG_ID_VOT_OFFSET_CRC);
#else
	mavlink_vot_offset_t packet;
	packet.timestamp = timestamp;
	packet.xoffset = xoffset;
	packet.yoffset = yoffset;
	packet.pitch_relative = pitch_relative;
	packet.tracking_enabled = tracking_enabled;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VOT_OFFSET_TUPLE, (const char *)&packet, MAVLINK_MSG_ID_VOT_OFFSET_LEN, MAVLINK_MSG_ID_VOT_OFFSET_CRC);
#endif
}

#if MAVLINK_MSG_ID_VOT_OFFSET_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_vot_offset_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t timestamp, float xoffset, float yoffset, float pitch_relative, uint8_t tracking_enabled)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint64_t(buf, 0, timestamp);
	_mav_put_float(buf, 8, xoffset);
	_mav_put_float(buf, 12, yoffset);
	_mav_put_float(buf, 16, pitch_relative);
	_mav_put_uint8_t(buf, 20, tracking_enabled);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VOT_OFFSET_TUPLE, buf, MAVLINK_MSG_ID_VOT_OFFSET_LEN, MAVLINK_MSG_ID_VOT_OFFSET_CRC);
#else
	mavlink_vot_offset_t *packet = (mavlink_vot_offset_t *)msgbuf;
	packet->timestamp = timestamp;
	packet->xoffset = xoffset;
	packet->yoffset = yoffset;
	packet->pitch_relative = pitch_relative;
	packet->tracking_enabled = tracking_enabled;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VOT_OFFSET_TUPLE, (const char *)packet, MAVLINK_MSG_ID_VOT_OFFSET_LEN, MAVLINK_MSG_ID_VOT_OFFSET_CRC);
#endif
}
#endif

#endif

// MESSAGE VOT_OFFSET UNPACKING


/**
 * @brief Get field timestamp from vot_offset message
 *
 * @return Timestamp of the component clock since boot time in milliseconds.
 */
static inline uint64_t mavlink_msg_vot_offset_get_timestamp(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field xoffset from vot_offset message
 *
 * @return xoffset.
 */
static inline float mavlink_msg_vot_offset_get_xoffset(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field yoffset from vot_offset message
 *
 * @return yoffset.
 */
static inline float mavlink_msg_vot_offset_get_yoffset(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field pitch_relative from vot_offset message
 *
 * @return relative pitch.
 */
static inline float mavlink_msg_vot_offset_get_pitch_relative(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field tracking_enabled from vot_offset message
 *
 * @return visual tracking enabled.
 */
static inline uint8_t mavlink_msg_vot_offset_get_tracking_enabled(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  20);
}

/**
 * @brief Decode a vot_offset message into a struct
 *
 * @param msg The message to decode
 * @param vot_offset C-struct to decode the message contents into
 */
static inline void mavlink_msg_vot_offset_decode(const mavlink_message_t* msg, mavlink_vot_offset_t* vot_offset)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	vot_offset->timestamp = mavlink_msg_vot_offset_get_timestamp(msg);
	vot_offset->xoffset = mavlink_msg_vot_offset_get_xoffset(msg);
	vot_offset->yoffset = mavlink_msg_vot_offset_get_yoffset(msg);
	vot_offset->pitch_relative = mavlink_msg_vot_offset_get_pitch_relative(msg);
	vot_offset->tracking_enabled = mavlink_msg_vot_offset_get_tracking_enabled(msg);
#else
	memcpy(vot_offset, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_VOT_OFFSET_LEN);
#endif
}
