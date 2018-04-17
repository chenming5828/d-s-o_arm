// MESSAGE SOS_CMD PACKING

#define MAVLINK_MSG_ID_SOS_CMD 156
#if MAVLINK_MULTI_DIALECT
#define MAVLINK_MSG_ID_SOS_CMD_TUPLE 0, MAVLINK_MSG_ID_SOS_CMD
#else
#define MAVLINK_MSG_ID_SOS_CMD_TUPLE MAVLINK_MSG_ID_SOS_CMD
#endif

typedef struct __mavlink_sos_cmd_t
{
 uint8_t command; /*< command.*/
 uint8_t state; /*< state.*/
 uint8_t body[100]; /*< body.*/
} mavlink_sos_cmd_t;

#define MAVLINK_MSG_ID_SOS_CMD_LEN 102
#define MAVLINK_MSG_ID_156_LEN 102

#define MAVLINK_MSG_ID_SOS_CMD_CRC 186
#define MAVLINK_MSG_ID_156_CRC 186

#define MAVLINK_MSG_SOS_CMD_FIELD_BODY_LEN 100

#if MAVLINK_MULTI_DIALECT
#define MAVLINK_MESSAGE_INFO_SOS_CMD { \
	156, 0, \
	"SOS_CMD", \
	3, \
	{  { "command", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_sos_cmd_t, command) }, \
         { "state", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_sos_cmd_t, state) }, \
         { "body", NULL, MAVLINK_TYPE_UINT8_T, 100, 2, offsetof(mavlink_sos_cmd_t, body) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_SOS_CMD { \
	"SOS_CMD", \
	3, \
	{  { "command", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_sos_cmd_t, command) }, \
         { "state", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_sos_cmd_t, state) }, \
         { "body", NULL, MAVLINK_TYPE_UINT8_T, 100, 2, offsetof(mavlink_sos_cmd_t, body) }, \
         } \
}
#endif

/**
 * @brief Pack a sos_cmd message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param command command.
 * @param state state.
 * @param body body.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_sos_cmd_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint8_t command, uint8_t state, const uint8_t *body)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_SOS_CMD_LEN];
	_mav_put_uint8_t(buf, 0, command);
	_mav_put_uint8_t(buf, 1, state);
	_mav_put_uint8_t_array(buf, 2, body, 100);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SOS_CMD_LEN);
#else
	mavlink_sos_cmd_t packet;
	packet.command = command;
	packet.state = state;
	mav_array_memcpy(packet.body, body, sizeof(uint8_t)*100);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SOS_CMD_LEN);
#endif

#if MAVLINK_MULTI_DIALECT
	msg->dialect = 0;
#endif
	msg->msgid = MAVLINK_MSG_ID_SOS_CMD;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SOS_CMD_LEN, MAVLINK_MSG_ID_SOS_CMD_CRC);
}

/**
 * @brief Pack a sos_cmd message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param command command.
 * @param state state.
 * @param body body.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_sos_cmd_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint8_t command,uint8_t state,const uint8_t *body)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_SOS_CMD_LEN];
	_mav_put_uint8_t(buf, 0, command);
	_mav_put_uint8_t(buf, 1, state);
	_mav_put_uint8_t_array(buf, 2, body, 100);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SOS_CMD_LEN);
#else
	mavlink_sos_cmd_t packet;
	packet.command = command;
	packet.state = state;
	mav_array_memcpy(packet.body, body, sizeof(uint8_t)*100);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SOS_CMD_LEN);
#endif

#if MAVLINK_MULTI_DIALECT
	msg->dialect = 0;
#endif
	msg->msgid = MAVLINK_MSG_ID_SOS_CMD;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SOS_CMD_LEN, MAVLINK_MSG_ID_SOS_CMD_CRC);
}

/**
 * @brief Encode a sos_cmd struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param sos_cmd C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_sos_cmd_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_sos_cmd_t* sos_cmd)
{
	return mavlink_msg_sos_cmd_pack(system_id, component_id, msg, sos_cmd->command, sos_cmd->state, sos_cmd->body);
}

/**
 * @brief Encode a sos_cmd struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param sos_cmd C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_sos_cmd_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_sos_cmd_t* sos_cmd)
{
	return mavlink_msg_sos_cmd_pack_chan(system_id, component_id, chan, msg, sos_cmd->command, sos_cmd->state, sos_cmd->body);
}

/**
 * @brief Send a sos_cmd message
 * @param chan MAVLink channel to send the message
 *
 * @param command command.
 * @param state state.
 * @param body body.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_sos_cmd_send(mavlink_channel_t chan, uint8_t command, uint8_t state, const uint8_t *body)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_SOS_CMD_LEN];
	_mav_put_uint8_t(buf, 0, command);
	_mav_put_uint8_t(buf, 1, state);
	_mav_put_uint8_t_array(buf, 2, body, 100);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SOS_CMD, buf, MAVLINK_MSG_ID_SOS_CMD_LEN, MAVLINK_MSG_ID_SOS_CMD_CRC);
#else
	mavlink_sos_cmd_t packet;
	packet.command = command;
	packet.state = state;
	mav_array_memcpy(packet.body, body, sizeof(uint8_t)*100);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SOS_CMD_TUPLE, (const char *)&packet, MAVLINK_MSG_ID_SOS_CMD_LEN, MAVLINK_MSG_ID_SOS_CMD_CRC);
#endif
}

#if MAVLINK_MSG_ID_SOS_CMD_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_sos_cmd_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t command, uint8_t state, const uint8_t *body)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint8_t(buf, 0, command);
	_mav_put_uint8_t(buf, 1, state);
	_mav_put_uint8_t_array(buf, 2, body, 100);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SOS_CMD_TUPLE, buf, MAVLINK_MSG_ID_SOS_CMD_LEN, MAVLINK_MSG_ID_SOS_CMD_CRC);
#else
	mavlink_sos_cmd_t *packet = (mavlink_sos_cmd_t *)msgbuf;
	packet->command = command;
	packet->state = state;
	mav_array_memcpy(packet->body, body, sizeof(uint8_t)*100);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SOS_CMD_TUPLE, (const char *)packet, MAVLINK_MSG_ID_SOS_CMD_LEN, MAVLINK_MSG_ID_SOS_CMD_CRC);
#endif
}
#endif

#endif

// MESSAGE SOS_CMD UNPACKING


/**
 * @brief Get field command from sos_cmd message
 *
 * @return command.
 */
static inline uint8_t mavlink_msg_sos_cmd_get_command(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field state from sos_cmd message
 *
 * @return state.
 */
static inline uint8_t mavlink_msg_sos_cmd_get_state(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Get field body from sos_cmd message
 *
 * @return body.
 */
static inline uint16_t mavlink_msg_sos_cmd_get_body(const mavlink_message_t* msg, uint8_t *body)
{
	return _MAV_RETURN_uint8_t_array(msg, body, 100,  2);
}

/**
 * @brief Decode a sos_cmd message into a struct
 *
 * @param msg The message to decode
 * @param sos_cmd C-struct to decode the message contents into
 */
static inline void mavlink_msg_sos_cmd_decode(const mavlink_message_t* msg, mavlink_sos_cmd_t* sos_cmd)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	sos_cmd->command = mavlink_msg_sos_cmd_get_command(msg);
	sos_cmd->state = mavlink_msg_sos_cmd_get_state(msg);
	mavlink_msg_sos_cmd_get_body(msg, sos_cmd->body);
#else
	memcpy(sos_cmd, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_SOS_CMD_LEN);
#endif
}
