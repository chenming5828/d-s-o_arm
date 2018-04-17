// MESSAGE ESC_RAW PACKING

#define MAVLINK_MSG_ID_ESC_RAW 157
#if MAVLINK_MULTI_DIALECT
#define MAVLINK_MSG_ID_ESC_RAW_TUPLE 0, MAVLINK_MSG_ID_ESC_RAW
#else
#define MAVLINK_MSG_ID_ESC_RAW_TUPLE MAVLINK_MSG_ID_ESC_RAW
#endif

typedef struct __mavlink_esc_raw_t
{
 uint16_t esc_rpm[4]; /*< esc rpm.*/
 uint16_t esc_rpm_cmd[4]; /*< esc rpm cmd.*/
} mavlink_esc_raw_t;

#define MAVLINK_MSG_ID_ESC_RAW_LEN 16
#define MAVLINK_MSG_ID_157_LEN 16

#define MAVLINK_MSG_ID_ESC_RAW_CRC 79
#define MAVLINK_MSG_ID_157_CRC 79

#define MAVLINK_MSG_ESC_RAW_FIELD_ESC_RPM_LEN 4
#define MAVLINK_MSG_ESC_RAW_FIELD_ESC_RPM_CMD_LEN 4

#if MAVLINK_MULTI_DIALECT
#define MAVLINK_MESSAGE_INFO_ESC_RAW { \
	157, 0, \
	"ESC_RAW", \
	2, \
	{  { "esc_rpm", NULL, MAVLINK_TYPE_UINT16_T, 4, 0, offsetof(mavlink_esc_raw_t, esc_rpm) }, \
         { "esc_rpm_cmd", NULL, MAVLINK_TYPE_UINT16_T, 4, 8, offsetof(mavlink_esc_raw_t, esc_rpm_cmd) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_ESC_RAW { \
	"ESC_RAW", \
	2, \
	{  { "esc_rpm", NULL, MAVLINK_TYPE_UINT16_T, 4, 0, offsetof(mavlink_esc_raw_t, esc_rpm) }, \
         { "esc_rpm_cmd", NULL, MAVLINK_TYPE_UINT16_T, 4, 8, offsetof(mavlink_esc_raw_t, esc_rpm_cmd) }, \
         } \
}
#endif

/**
 * @brief Pack a esc_raw message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param esc_rpm esc rpm.
 * @param esc_rpm_cmd esc rpm cmd.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_esc_raw_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       const uint16_t *esc_rpm, const uint16_t *esc_rpm_cmd)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_ESC_RAW_LEN];

	_mav_put_uint16_t_array(buf, 0, esc_rpm, 4);
	_mav_put_uint16_t_array(buf, 8, esc_rpm_cmd, 4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ESC_RAW_LEN);
#else
	mavlink_esc_raw_t packet;

	mav_array_memcpy(packet.esc_rpm, esc_rpm, sizeof(uint16_t)*4);
	mav_array_memcpy(packet.esc_rpm_cmd, esc_rpm_cmd, sizeof(uint16_t)*4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ESC_RAW_LEN);
#endif

#if MAVLINK_MULTI_DIALECT
	msg->dialect = 0;
#endif
	msg->msgid = MAVLINK_MSG_ID_ESC_RAW;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_ESC_RAW_LEN, MAVLINK_MSG_ID_ESC_RAW_CRC);
}

/**
 * @brief Pack a esc_raw message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param esc_rpm esc rpm.
 * @param esc_rpm_cmd esc rpm cmd.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_esc_raw_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           const uint16_t *esc_rpm,const uint16_t *esc_rpm_cmd)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_ESC_RAW_LEN];

	_mav_put_uint16_t_array(buf, 0, esc_rpm, 4);
	_mav_put_uint16_t_array(buf, 8, esc_rpm_cmd, 4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ESC_RAW_LEN);
#else
	mavlink_esc_raw_t packet;

	mav_array_memcpy(packet.esc_rpm, esc_rpm, sizeof(uint16_t)*4);
	mav_array_memcpy(packet.esc_rpm_cmd, esc_rpm_cmd, sizeof(uint16_t)*4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ESC_RAW_LEN);
#endif

#if MAVLINK_MULTI_DIALECT
	msg->dialect = 0;
#endif
	msg->msgid = MAVLINK_MSG_ID_ESC_RAW;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_ESC_RAW_LEN, MAVLINK_MSG_ID_ESC_RAW_CRC);
}

/**
 * @brief Encode a esc_raw struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param esc_raw C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_esc_raw_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_esc_raw_t* esc_raw)
{
	return mavlink_msg_esc_raw_pack(system_id, component_id, msg, esc_raw->esc_rpm, esc_raw->esc_rpm_cmd);
}

/**
 * @brief Encode a esc_raw struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param esc_raw C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_esc_raw_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_esc_raw_t* esc_raw)
{
	return mavlink_msg_esc_raw_pack_chan(system_id, component_id, chan, msg, esc_raw->esc_rpm, esc_raw->esc_rpm_cmd);
}

/**
 * @brief Send a esc_raw message
 * @param chan MAVLink channel to send the message
 *
 * @param esc_rpm esc rpm.
 * @param esc_rpm_cmd esc rpm cmd.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_esc_raw_send(mavlink_channel_t chan, const uint16_t *esc_rpm, const uint16_t *esc_rpm_cmd)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_ESC_RAW_LEN];

	_mav_put_uint16_t_array(buf, 0, esc_rpm, 4);
	_mav_put_uint16_t_array(buf, 8, esc_rpm_cmd, 4);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ESC_RAW, buf, MAVLINK_MSG_ID_ESC_RAW_LEN, MAVLINK_MSG_ID_ESC_RAW_CRC);
#else
	mavlink_esc_raw_t packet;

	mav_array_memcpy(packet.esc_rpm, esc_rpm, sizeof(uint16_t)*4);
	mav_array_memcpy(packet.esc_rpm_cmd, esc_rpm_cmd, sizeof(uint16_t)*4);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ESC_RAW_TUPLE, (const char *)&packet, MAVLINK_MSG_ID_ESC_RAW_LEN, MAVLINK_MSG_ID_ESC_RAW_CRC);
#endif
}

#if MAVLINK_MSG_ID_ESC_RAW_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_esc_raw_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  const uint16_t *esc_rpm, const uint16_t *esc_rpm_cmd)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;

	_mav_put_uint16_t_array(buf, 0, esc_rpm, 4);
	_mav_put_uint16_t_array(buf, 8, esc_rpm_cmd, 4);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ESC_RAW_TUPLE, buf, MAVLINK_MSG_ID_ESC_RAW_LEN, MAVLINK_MSG_ID_ESC_RAW_CRC);
#else
	mavlink_esc_raw_t *packet = (mavlink_esc_raw_t *)msgbuf;

	mav_array_memcpy(packet->esc_rpm, esc_rpm, sizeof(uint16_t)*4);
	mav_array_memcpy(packet->esc_rpm_cmd, esc_rpm_cmd, sizeof(uint16_t)*4);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ESC_RAW_TUPLE, (const char *)packet, MAVLINK_MSG_ID_ESC_RAW_LEN, MAVLINK_MSG_ID_ESC_RAW_CRC);
#endif
}
#endif

#endif

// MESSAGE ESC_RAW UNPACKING


/**
 * @brief Get field esc_rpm from esc_raw message
 *
 * @return esc rpm.
 */
static inline uint16_t mavlink_msg_esc_raw_get_esc_rpm(const mavlink_message_t* msg, uint16_t *esc_rpm)
{
	return _MAV_RETURN_uint16_t_array(msg, esc_rpm, 4,  0);
}

/**
 * @brief Get field esc_rpm_cmd from esc_raw message
 *
 * @return esc rpm cmd.
 */
static inline uint16_t mavlink_msg_esc_raw_get_esc_rpm_cmd(const mavlink_message_t* msg, uint16_t *esc_rpm_cmd)
{
	return _MAV_RETURN_uint16_t_array(msg, esc_rpm_cmd, 4,  8);
}

/**
 * @brief Decode a esc_raw message into a struct
 *
 * @param msg The message to decode
 * @param esc_raw C-struct to decode the message contents into
 */
static inline void mavlink_msg_esc_raw_decode(const mavlink_message_t* msg, mavlink_esc_raw_t* esc_raw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	mavlink_msg_esc_raw_get_esc_rpm(msg, esc_raw->esc_rpm);
	mavlink_msg_esc_raw_get_esc_rpm_cmd(msg, esc_raw->esc_rpm_cmd);
#else
	memcpy(esc_raw, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_ESC_RAW_LEN);
#endif
}
