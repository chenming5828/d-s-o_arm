// MESSAGE PERIPHERAL_ERROR_STATE PACKING

#define MAVLINK_MSG_ID_PERIPHERAL_ERROR_STATE 158
#if MAVLINK_MULTI_DIALECT
#define MAVLINK_MSG_ID_PERIPHERAL_ERROR_STATE_TUPLE 0, MAVLINK_MSG_ID_PERIPHERAL_ERROR_STATE
#else
#define MAVLINK_MSG_ID_PERIPHERAL_ERROR_STATE_TUPLE MAVLINK_MSG_ID_PERIPHERAL_ERROR_STATE
#endif

typedef struct __mavlink_peripheral_error_state_t
{
 uint16_t errors_state1; /*< errors state 1.*/
 uint16_t errors_state2; /*< errors state 2.*/
 uint16_t errors_state3; /*< errors state 3.*/
} mavlink_peripheral_error_state_t;

#define MAVLINK_MSG_ID_PERIPHERAL_ERROR_STATE_LEN 6
#define MAVLINK_MSG_ID_158_LEN 6

#define MAVLINK_MSG_ID_PERIPHERAL_ERROR_STATE_CRC 211
#define MAVLINK_MSG_ID_158_CRC 211



#if MAVLINK_MULTI_DIALECT
#define MAVLINK_MESSAGE_INFO_PERIPHERAL_ERROR_STATE { \
	158, 0, \
	"PERIPHERAL_ERROR_STATE", \
	3, \
	{  { "errors_state1", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_peripheral_error_state_t, errors_state1) }, \
         { "errors_state2", NULL, MAVLINK_TYPE_UINT16_T, 0, 2, offsetof(mavlink_peripheral_error_state_t, errors_state2) }, \
         { "errors_state3", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_peripheral_error_state_t, errors_state3) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_PERIPHERAL_ERROR_STATE { \
	"PERIPHERAL_ERROR_STATE", \
	3, \
	{  { "errors_state1", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_peripheral_error_state_t, errors_state1) }, \
         { "errors_state2", NULL, MAVLINK_TYPE_UINT16_T, 0, 2, offsetof(mavlink_peripheral_error_state_t, errors_state2) }, \
         { "errors_state3", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_peripheral_error_state_t, errors_state3) }, \
         } \
}
#endif

/**
 * @brief Pack a peripheral_error_state message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param errors_state1 errors state 1.
 * @param errors_state2 errors state 2.
 * @param errors_state3 errors state 3.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_peripheral_error_state_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint16_t errors_state1, uint16_t errors_state2, uint16_t errors_state3)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_PERIPHERAL_ERROR_STATE_LEN];
	_mav_put_uint16_t(buf, 0, errors_state1);
	_mav_put_uint16_t(buf, 2, errors_state2);
	_mav_put_uint16_t(buf, 4, errors_state3);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_PERIPHERAL_ERROR_STATE_LEN);
#else
	mavlink_peripheral_error_state_t packet;
	packet.errors_state1 = errors_state1;
	packet.errors_state2 = errors_state2;
	packet.errors_state3 = errors_state3;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_PERIPHERAL_ERROR_STATE_LEN);
#endif

#if MAVLINK_MULTI_DIALECT
	msg->dialect = 0;
#endif
	msg->msgid = MAVLINK_MSG_ID_PERIPHERAL_ERROR_STATE;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_PERIPHERAL_ERROR_STATE_LEN, MAVLINK_MSG_ID_PERIPHERAL_ERROR_STATE_CRC);
}

/**
 * @brief Pack a peripheral_error_state message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param errors_state1 errors state 1.
 * @param errors_state2 errors state 2.
 * @param errors_state3 errors state 3.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_peripheral_error_state_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint16_t errors_state1,uint16_t errors_state2,uint16_t errors_state3)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_PERIPHERAL_ERROR_STATE_LEN];
	_mav_put_uint16_t(buf, 0, errors_state1);
	_mav_put_uint16_t(buf, 2, errors_state2);
	_mav_put_uint16_t(buf, 4, errors_state3);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_PERIPHERAL_ERROR_STATE_LEN);
#else
	mavlink_peripheral_error_state_t packet;
	packet.errors_state1 = errors_state1;
	packet.errors_state2 = errors_state2;
	packet.errors_state3 = errors_state3;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_PERIPHERAL_ERROR_STATE_LEN);
#endif

#if MAVLINK_MULTI_DIALECT
	msg->dialect = 0;
#endif
	msg->msgid = MAVLINK_MSG_ID_PERIPHERAL_ERROR_STATE;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_PERIPHERAL_ERROR_STATE_LEN, MAVLINK_MSG_ID_PERIPHERAL_ERROR_STATE_CRC);
}

/**
 * @brief Encode a peripheral_error_state struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param peripheral_error_state C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_peripheral_error_state_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_peripheral_error_state_t* peripheral_error_state)
{
	return mavlink_msg_peripheral_error_state_pack(system_id, component_id, msg, peripheral_error_state->errors_state1, peripheral_error_state->errors_state2, peripheral_error_state->errors_state3);
}

/**
 * @brief Encode a peripheral_error_state struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param peripheral_error_state C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_peripheral_error_state_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_peripheral_error_state_t* peripheral_error_state)
{
	return mavlink_msg_peripheral_error_state_pack_chan(system_id, component_id, chan, msg, peripheral_error_state->errors_state1, peripheral_error_state->errors_state2, peripheral_error_state->errors_state3);
}

/**
 * @brief Send a peripheral_error_state message
 * @param chan MAVLink channel to send the message
 *
 * @param errors_state1 errors state 1.
 * @param errors_state2 errors state 2.
 * @param errors_state3 errors state 3.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_peripheral_error_state_send(mavlink_channel_t chan, uint16_t errors_state1, uint16_t errors_state2, uint16_t errors_state3)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_PERIPHERAL_ERROR_STATE_LEN];
	_mav_put_uint16_t(buf, 0, errors_state1);
	_mav_put_uint16_t(buf, 2, errors_state2);
	_mav_put_uint16_t(buf, 4, errors_state3);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PERIPHERAL_ERROR_STATE, buf, MAVLINK_MSG_ID_PERIPHERAL_ERROR_STATE_LEN, MAVLINK_MSG_ID_PERIPHERAL_ERROR_STATE_CRC);
#else
	mavlink_peripheral_error_state_t packet;
	packet.errors_state1 = errors_state1;
	packet.errors_state2 = errors_state2;
	packet.errors_state3 = errors_state3;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PERIPHERAL_ERROR_STATE_TUPLE, (const char *)&packet, MAVLINK_MSG_ID_PERIPHERAL_ERROR_STATE_LEN, MAVLINK_MSG_ID_PERIPHERAL_ERROR_STATE_CRC);
#endif
}

#if MAVLINK_MSG_ID_PERIPHERAL_ERROR_STATE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_peripheral_error_state_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint16_t errors_state1, uint16_t errors_state2, uint16_t errors_state3)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint16_t(buf, 0, errors_state1);
	_mav_put_uint16_t(buf, 2, errors_state2);
	_mav_put_uint16_t(buf, 4, errors_state3);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PERIPHERAL_ERROR_STATE_TUPLE, buf, MAVLINK_MSG_ID_PERIPHERAL_ERROR_STATE_LEN, MAVLINK_MSG_ID_PERIPHERAL_ERROR_STATE_CRC);
#else
	mavlink_peripheral_error_state_t *packet = (mavlink_peripheral_error_state_t *)msgbuf;
	packet->errors_state1 = errors_state1;
	packet->errors_state2 = errors_state2;
	packet->errors_state3 = errors_state3;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PERIPHERAL_ERROR_STATE_TUPLE, (const char *)packet, MAVLINK_MSG_ID_PERIPHERAL_ERROR_STATE_LEN, MAVLINK_MSG_ID_PERIPHERAL_ERROR_STATE_CRC);
#endif
}
#endif

#endif

// MESSAGE PERIPHERAL_ERROR_STATE UNPACKING


/**
 * @brief Get field errors_state1 from peripheral_error_state message
 *
 * @return errors state 1.
 */
static inline uint16_t mavlink_msg_peripheral_error_state_get_errors_state1(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  0);
}

/**
 * @brief Get field errors_state2 from peripheral_error_state message
 *
 * @return errors state 2.
 */
static inline uint16_t mavlink_msg_peripheral_error_state_get_errors_state2(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  2);
}

/**
 * @brief Get field errors_state3 from peripheral_error_state message
 *
 * @return errors state 3.
 */
static inline uint16_t mavlink_msg_peripheral_error_state_get_errors_state3(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  4);
}

/**
 * @brief Decode a peripheral_error_state message into a struct
 *
 * @param msg The message to decode
 * @param peripheral_error_state C-struct to decode the message contents into
 */
static inline void mavlink_msg_peripheral_error_state_decode(const mavlink_message_t* msg, mavlink_peripheral_error_state_t* peripheral_error_state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	peripheral_error_state->errors_state1 = mavlink_msg_peripheral_error_state_get_errors_state1(msg);
	peripheral_error_state->errors_state2 = mavlink_msg_peripheral_error_state_get_errors_state2(msg);
	peripheral_error_state->errors_state3 = mavlink_msg_peripheral_error_state_get_errors_state3(msg);
#else
	memcpy(peripheral_error_state, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_PERIPHERAL_ERROR_STATE_LEN);
#endif
}
