#pragma once
// MESSAGE SYSTEM_STATUS_FLAGS PACKING

#define MAVLINK_MSG_ID_SYSTEM_STATUS_FLAGS 159

MAVPACKED(
typedef struct __mavlink_system_status_flags_t {
 uint64_t flags; /*< status flags.*/
}) mavlink_system_status_flags_t;

#define MAVLINK_MSG_ID_SYSTEM_STATUS_FLAGS_LEN 8
#define MAVLINK_MSG_ID_SYSTEM_STATUS_FLAGS_MIN_LEN 8
#define MAVLINK_MSG_ID_159_LEN 8
#define MAVLINK_MSG_ID_159_MIN_LEN 8

#define MAVLINK_MSG_ID_SYSTEM_STATUS_FLAGS_CRC 28
#define MAVLINK_MSG_ID_159_CRC 28



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_SYSTEM_STATUS_FLAGS { \
    159, \
    "SYSTEM_STATUS_FLAGS", \
    1, \
    {  { "flags", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_system_status_flags_t, flags) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_SYSTEM_STATUS_FLAGS { \
    "SYSTEM_STATUS_FLAGS", \
    1, \
    {  { "flags", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_system_status_flags_t, flags) }, \
         } \
}
#endif

/**
 * @brief Pack a system_status_flags message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param flags status flags.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_system_status_flags_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t flags)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SYSTEM_STATUS_FLAGS_LEN];
    _mav_put_uint64_t(buf, 0, flags);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SYSTEM_STATUS_FLAGS_LEN);
#else
    mavlink_system_status_flags_t packet;
    packet.flags = flags;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SYSTEM_STATUS_FLAGS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SYSTEM_STATUS_FLAGS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SYSTEM_STATUS_FLAGS_MIN_LEN, MAVLINK_MSG_ID_SYSTEM_STATUS_FLAGS_LEN, MAVLINK_MSG_ID_SYSTEM_STATUS_FLAGS_CRC);
}

/**
 * @brief Pack a system_status_flags message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param flags status flags.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_system_status_flags_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t flags)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SYSTEM_STATUS_FLAGS_LEN];
    _mav_put_uint64_t(buf, 0, flags);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SYSTEM_STATUS_FLAGS_LEN);
#else
    mavlink_system_status_flags_t packet;
    packet.flags = flags;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SYSTEM_STATUS_FLAGS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SYSTEM_STATUS_FLAGS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SYSTEM_STATUS_FLAGS_MIN_LEN, MAVLINK_MSG_ID_SYSTEM_STATUS_FLAGS_LEN, MAVLINK_MSG_ID_SYSTEM_STATUS_FLAGS_CRC);
}

/**
 * @brief Encode a system_status_flags struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param system_status_flags C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_system_status_flags_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_system_status_flags_t* system_status_flags)
{
    return mavlink_msg_system_status_flags_pack(system_id, component_id, msg, system_status_flags->flags);
}

/**
 * @brief Encode a system_status_flags struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param system_status_flags C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_system_status_flags_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_system_status_flags_t* system_status_flags)
{
    return mavlink_msg_system_status_flags_pack_chan(system_id, component_id, chan, msg, system_status_flags->flags);
}

/**
 * @brief Send a system_status_flags message
 * @param chan MAVLink channel to send the message
 *
 * @param flags status flags.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_system_status_flags_send(mavlink_channel_t chan, uint64_t flags)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SYSTEM_STATUS_FLAGS_LEN];
    _mav_put_uint64_t(buf, 0, flags);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SYSTEM_STATUS_FLAGS, buf, MAVLINK_MSG_ID_SYSTEM_STATUS_FLAGS_MIN_LEN, MAVLINK_MSG_ID_SYSTEM_STATUS_FLAGS_LEN, MAVLINK_MSG_ID_SYSTEM_STATUS_FLAGS_CRC);
#else
    mavlink_system_status_flags_t packet;
    packet.flags = flags;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SYSTEM_STATUS_FLAGS, (const char *)&packet, MAVLINK_MSG_ID_SYSTEM_STATUS_FLAGS_MIN_LEN, MAVLINK_MSG_ID_SYSTEM_STATUS_FLAGS_LEN, MAVLINK_MSG_ID_SYSTEM_STATUS_FLAGS_CRC);
#endif
}

/**
 * @brief Send a system_status_flags message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_system_status_flags_send_struct(mavlink_channel_t chan, const mavlink_system_status_flags_t* system_status_flags)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_system_status_flags_send(chan, system_status_flags->flags);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SYSTEM_STATUS_FLAGS, (const char *)system_status_flags, MAVLINK_MSG_ID_SYSTEM_STATUS_FLAGS_MIN_LEN, MAVLINK_MSG_ID_SYSTEM_STATUS_FLAGS_LEN, MAVLINK_MSG_ID_SYSTEM_STATUS_FLAGS_CRC);
#endif
}

#if MAVLINK_MSG_ID_SYSTEM_STATUS_FLAGS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_system_status_flags_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t flags)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, flags);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SYSTEM_STATUS_FLAGS, buf, MAVLINK_MSG_ID_SYSTEM_STATUS_FLAGS_MIN_LEN, MAVLINK_MSG_ID_SYSTEM_STATUS_FLAGS_LEN, MAVLINK_MSG_ID_SYSTEM_STATUS_FLAGS_CRC);
#else
    mavlink_system_status_flags_t *packet = (mavlink_system_status_flags_t *)msgbuf;
    packet->flags = flags;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SYSTEM_STATUS_FLAGS, (const char *)packet, MAVLINK_MSG_ID_SYSTEM_STATUS_FLAGS_MIN_LEN, MAVLINK_MSG_ID_SYSTEM_STATUS_FLAGS_LEN, MAVLINK_MSG_ID_SYSTEM_STATUS_FLAGS_CRC);
#endif
}
#endif

#endif

// MESSAGE SYSTEM_STATUS_FLAGS UNPACKING


/**
 * @brief Get field flags from system_status_flags message
 *
 * @return status flags.
 */
static inline uint64_t mavlink_msg_system_status_flags_get_flags(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Decode a system_status_flags message into a struct
 *
 * @param msg The message to decode
 * @param system_status_flags C-struct to decode the message contents into
 */
static inline void mavlink_msg_system_status_flags_decode(const mavlink_message_t* msg, mavlink_system_status_flags_t* system_status_flags)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    system_status_flags->flags = mavlink_msg_system_status_flags_get_flags(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_SYSTEM_STATUS_FLAGS_LEN? msg->len : MAVLINK_MSG_ID_SYSTEM_STATUS_FLAGS_LEN;
        memset(system_status_flags, 0, MAVLINK_MSG_ID_SYSTEM_STATUS_FLAGS_LEN);
    memcpy(system_status_flags, _MAV_PAYLOAD(msg), len);
#endif
}
