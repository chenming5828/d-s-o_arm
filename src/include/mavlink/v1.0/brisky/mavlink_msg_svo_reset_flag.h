#pragma once
// MESSAGE SVO_RESET_FLAG PACKING

#define MAVLINK_MSG_ID_SVO_RESET_FLAG 161

MAVPACKED(
typedef struct __mavlink_svo_reset_flag_t {
 uint8_t svo_reset_flag; /*< svo reset flag.*/
}) mavlink_svo_reset_flag_t;

#define MAVLINK_MSG_ID_SVO_RESET_FLAG_LEN 1
#define MAVLINK_MSG_ID_SVO_RESET_FLAG_MIN_LEN 1
#define MAVLINK_MSG_ID_161_LEN 1
#define MAVLINK_MSG_ID_161_MIN_LEN 1

#define MAVLINK_MSG_ID_SVO_RESET_FLAG_CRC 85
#define MAVLINK_MSG_ID_161_CRC 85



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_SVO_RESET_FLAG { \
    161, \
    "SVO_RESET_FLAG", \
    1, \
    {  { "svo_reset_flag", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_svo_reset_flag_t, svo_reset_flag) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_SVO_RESET_FLAG { \
    "SVO_RESET_FLAG", \
    1, \
    {  { "svo_reset_flag", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_svo_reset_flag_t, svo_reset_flag) }, \
         } \
}
#endif

/**
 * @brief Pack a svo_reset_flag message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param svo_reset_flag svo reset flag.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_svo_reset_flag_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t svo_reset_flag)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SVO_RESET_FLAG_LEN];
    _mav_put_uint8_t(buf, 0, svo_reset_flag);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SVO_RESET_FLAG_LEN);
#else
    mavlink_svo_reset_flag_t packet;
    packet.svo_reset_flag = svo_reset_flag;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SVO_RESET_FLAG_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SVO_RESET_FLAG;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SVO_RESET_FLAG_MIN_LEN, MAVLINK_MSG_ID_SVO_RESET_FLAG_LEN, MAVLINK_MSG_ID_SVO_RESET_FLAG_CRC);
}

/**
 * @brief Pack a svo_reset_flag message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param svo_reset_flag svo reset flag.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_svo_reset_flag_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t svo_reset_flag)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SVO_RESET_FLAG_LEN];
    _mav_put_uint8_t(buf, 0, svo_reset_flag);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SVO_RESET_FLAG_LEN);
#else
    mavlink_svo_reset_flag_t packet;
    packet.svo_reset_flag = svo_reset_flag;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SVO_RESET_FLAG_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SVO_RESET_FLAG;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SVO_RESET_FLAG_MIN_LEN, MAVLINK_MSG_ID_SVO_RESET_FLAG_LEN, MAVLINK_MSG_ID_SVO_RESET_FLAG_CRC);
}

/**
 * @brief Encode a svo_reset_flag struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param svo_reset_flag C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_svo_reset_flag_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_svo_reset_flag_t* svo_reset_flag)
{
    return mavlink_msg_svo_reset_flag_pack(system_id, component_id, msg, svo_reset_flag->svo_reset_flag);
}

/**
 * @brief Encode a svo_reset_flag struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param svo_reset_flag C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_svo_reset_flag_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_svo_reset_flag_t* svo_reset_flag)
{
    return mavlink_msg_svo_reset_flag_pack_chan(system_id, component_id, chan, msg, svo_reset_flag->svo_reset_flag);
}

/**
 * @brief Send a svo_reset_flag message
 * @param chan MAVLink channel to send the message
 *
 * @param svo_reset_flag svo reset flag.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_svo_reset_flag_send(mavlink_channel_t chan, uint8_t svo_reset_flag)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SVO_RESET_FLAG_LEN];
    _mav_put_uint8_t(buf, 0, svo_reset_flag);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SVO_RESET_FLAG, buf, MAVLINK_MSG_ID_SVO_RESET_FLAG_MIN_LEN, MAVLINK_MSG_ID_SVO_RESET_FLAG_LEN, MAVLINK_MSG_ID_SVO_RESET_FLAG_CRC);
#else
    mavlink_svo_reset_flag_t packet;
    packet.svo_reset_flag = svo_reset_flag;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SVO_RESET_FLAG, (const char *)&packet, MAVLINK_MSG_ID_SVO_RESET_FLAG_MIN_LEN, MAVLINK_MSG_ID_SVO_RESET_FLAG_LEN, MAVLINK_MSG_ID_SVO_RESET_FLAG_CRC);
#endif
}

/**
 * @brief Send a svo_reset_flag message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_svo_reset_flag_send_struct(mavlink_channel_t chan, const mavlink_svo_reset_flag_t* svo_reset_flag)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_svo_reset_flag_send(chan, svo_reset_flag->svo_reset_flag);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SVO_RESET_FLAG, (const char *)svo_reset_flag, MAVLINK_MSG_ID_SVO_RESET_FLAG_MIN_LEN, MAVLINK_MSG_ID_SVO_RESET_FLAG_LEN, MAVLINK_MSG_ID_SVO_RESET_FLAG_CRC);
#endif
}

#if MAVLINK_MSG_ID_SVO_RESET_FLAG_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_svo_reset_flag_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t svo_reset_flag)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 0, svo_reset_flag);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SVO_RESET_FLAG, buf, MAVLINK_MSG_ID_SVO_RESET_FLAG_MIN_LEN, MAVLINK_MSG_ID_SVO_RESET_FLAG_LEN, MAVLINK_MSG_ID_SVO_RESET_FLAG_CRC);
#else
    mavlink_svo_reset_flag_t *packet = (mavlink_svo_reset_flag_t *)msgbuf;
    packet->svo_reset_flag = svo_reset_flag;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SVO_RESET_FLAG, (const char *)packet, MAVLINK_MSG_ID_SVO_RESET_FLAG_MIN_LEN, MAVLINK_MSG_ID_SVO_RESET_FLAG_LEN, MAVLINK_MSG_ID_SVO_RESET_FLAG_CRC);
#endif
}
#endif

#endif

// MESSAGE SVO_RESET_FLAG UNPACKING


/**
 * @brief Get field svo_reset_flag from svo_reset_flag message
 *
 * @return svo reset flag.
 */
static inline uint8_t mavlink_msg_svo_reset_flag_get_svo_reset_flag(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Decode a svo_reset_flag message into a struct
 *
 * @param msg The message to decode
 * @param svo_reset_flag C-struct to decode the message contents into
 */
static inline void mavlink_msg_svo_reset_flag_decode(const mavlink_message_t* msg, mavlink_svo_reset_flag_t* svo_reset_flag)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    svo_reset_flag->svo_reset_flag = mavlink_msg_svo_reset_flag_get_svo_reset_flag(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_SVO_RESET_FLAG_LEN? msg->len : MAVLINK_MSG_ID_SVO_RESET_FLAG_LEN;
        memset(svo_reset_flag, 0, MAVLINK_MSG_ID_SVO_RESET_FLAG_LEN);
    memcpy(svo_reset_flag, _MAV_PAYLOAD(msg), len);
#endif
}
