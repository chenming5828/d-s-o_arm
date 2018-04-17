#pragma once
// MESSAGE ESC_STATUS PACKING

#define MAVLINK_MSG_ID_ESC_STATUS 160

MAVPACKED(
typedef struct __mavlink_esc_status_t {
 uint8_t link_break_fault; /*< User mode UART link break fault.*/
 uint8_t over_temperatuer_fault; /*< Over temperature fault.*/
 uint8_t dc_voltage_fault; /*< DC bus undervoltage fault and DC bus Critical overvoltage fault.*/
 uint8_t motor_gatekill_fault; /*< Motor gatekill fault.*/
 uint8_t locked_rotor_fault; /*< Locked rotor.*/
 uint8_t power_limit_warning; /*< Motor power reach limit.*/
}) mavlink_esc_status_t;

#define MAVLINK_MSG_ID_ESC_STATUS_LEN 6
#define MAVLINK_MSG_ID_ESC_STATUS_MIN_LEN 6
#define MAVLINK_MSG_ID_160_LEN 6
#define MAVLINK_MSG_ID_160_MIN_LEN 6

#define MAVLINK_MSG_ID_ESC_STATUS_CRC 107
#define MAVLINK_MSG_ID_160_CRC 107



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_ESC_STATUS { \
    160, \
    "ESC_STATUS", \
    6, \
    {  { "link_break_fault", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_esc_status_t, link_break_fault) }, \
         { "over_temperatuer_fault", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_esc_status_t, over_temperatuer_fault) }, \
         { "dc_voltage_fault", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_esc_status_t, dc_voltage_fault) }, \
         { "motor_gatekill_fault", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_esc_status_t, motor_gatekill_fault) }, \
         { "locked_rotor_fault", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_esc_status_t, locked_rotor_fault) }, \
         { "power_limit_warning", NULL, MAVLINK_TYPE_UINT8_T, 0, 5, offsetof(mavlink_esc_status_t, power_limit_warning) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_ESC_STATUS { \
    "ESC_STATUS", \
    6, \
    {  { "link_break_fault", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_esc_status_t, link_break_fault) }, \
         { "over_temperatuer_fault", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_esc_status_t, over_temperatuer_fault) }, \
         { "dc_voltage_fault", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_esc_status_t, dc_voltage_fault) }, \
         { "motor_gatekill_fault", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_esc_status_t, motor_gatekill_fault) }, \
         { "locked_rotor_fault", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_esc_status_t, locked_rotor_fault) }, \
         { "power_limit_warning", NULL, MAVLINK_TYPE_UINT8_T, 0, 5, offsetof(mavlink_esc_status_t, power_limit_warning) }, \
         } \
}
#endif

/**
 * @brief Pack a esc_status message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param link_break_fault User mode UART link break fault.
 * @param over_temperatuer_fault Over temperature fault.
 * @param dc_voltage_fault DC bus undervoltage fault and DC bus Critical overvoltage fault.
 * @param motor_gatekill_fault Motor gatekill fault.
 * @param locked_rotor_fault Locked rotor.
 * @param power_limit_warning Motor power reach limit.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_esc_status_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t link_break_fault, uint8_t over_temperatuer_fault, uint8_t dc_voltage_fault, uint8_t motor_gatekill_fault, uint8_t locked_rotor_fault, uint8_t power_limit_warning)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ESC_STATUS_LEN];
    _mav_put_uint8_t(buf, 0, link_break_fault);
    _mav_put_uint8_t(buf, 1, over_temperatuer_fault);
    _mav_put_uint8_t(buf, 2, dc_voltage_fault);
    _mav_put_uint8_t(buf, 3, motor_gatekill_fault);
    _mav_put_uint8_t(buf, 4, locked_rotor_fault);
    _mav_put_uint8_t(buf, 5, power_limit_warning);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ESC_STATUS_LEN);
#else
    mavlink_esc_status_t packet;
    packet.link_break_fault = link_break_fault;
    packet.over_temperatuer_fault = over_temperatuer_fault;
    packet.dc_voltage_fault = dc_voltage_fault;
    packet.motor_gatekill_fault = motor_gatekill_fault;
    packet.locked_rotor_fault = locked_rotor_fault;
    packet.power_limit_warning = power_limit_warning;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ESC_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_ESC_STATUS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_ESC_STATUS_MIN_LEN, MAVLINK_MSG_ID_ESC_STATUS_LEN, MAVLINK_MSG_ID_ESC_STATUS_CRC);
}

/**
 * @brief Pack a esc_status message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param link_break_fault User mode UART link break fault.
 * @param over_temperatuer_fault Over temperature fault.
 * @param dc_voltage_fault DC bus undervoltage fault and DC bus Critical overvoltage fault.
 * @param motor_gatekill_fault Motor gatekill fault.
 * @param locked_rotor_fault Locked rotor.
 * @param power_limit_warning Motor power reach limit.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_esc_status_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t link_break_fault,uint8_t over_temperatuer_fault,uint8_t dc_voltage_fault,uint8_t motor_gatekill_fault,uint8_t locked_rotor_fault,uint8_t power_limit_warning)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ESC_STATUS_LEN];
    _mav_put_uint8_t(buf, 0, link_break_fault);
    _mav_put_uint8_t(buf, 1, over_temperatuer_fault);
    _mav_put_uint8_t(buf, 2, dc_voltage_fault);
    _mav_put_uint8_t(buf, 3, motor_gatekill_fault);
    _mav_put_uint8_t(buf, 4, locked_rotor_fault);
    _mav_put_uint8_t(buf, 5, power_limit_warning);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ESC_STATUS_LEN);
#else
    mavlink_esc_status_t packet;
    packet.link_break_fault = link_break_fault;
    packet.over_temperatuer_fault = over_temperatuer_fault;
    packet.dc_voltage_fault = dc_voltage_fault;
    packet.motor_gatekill_fault = motor_gatekill_fault;
    packet.locked_rotor_fault = locked_rotor_fault;
    packet.power_limit_warning = power_limit_warning;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ESC_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_ESC_STATUS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_ESC_STATUS_MIN_LEN, MAVLINK_MSG_ID_ESC_STATUS_LEN, MAVLINK_MSG_ID_ESC_STATUS_CRC);
}

/**
 * @brief Encode a esc_status struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param esc_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_esc_status_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_esc_status_t* esc_status)
{
    return mavlink_msg_esc_status_pack(system_id, component_id, msg, esc_status->link_break_fault, esc_status->over_temperatuer_fault, esc_status->dc_voltage_fault, esc_status->motor_gatekill_fault, esc_status->locked_rotor_fault, esc_status->power_limit_warning);
}

/**
 * @brief Encode a esc_status struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param esc_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_esc_status_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_esc_status_t* esc_status)
{
    return mavlink_msg_esc_status_pack_chan(system_id, component_id, chan, msg, esc_status->link_break_fault, esc_status->over_temperatuer_fault, esc_status->dc_voltage_fault, esc_status->motor_gatekill_fault, esc_status->locked_rotor_fault, esc_status->power_limit_warning);
}

/**
 * @brief Send a esc_status message
 * @param chan MAVLink channel to send the message
 *
 * @param link_break_fault User mode UART link break fault.
 * @param over_temperatuer_fault Over temperature fault.
 * @param dc_voltage_fault DC bus undervoltage fault and DC bus Critical overvoltage fault.
 * @param motor_gatekill_fault Motor gatekill fault.
 * @param locked_rotor_fault Locked rotor.
 * @param power_limit_warning Motor power reach limit.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_esc_status_send(mavlink_channel_t chan, uint8_t link_break_fault, uint8_t over_temperatuer_fault, uint8_t dc_voltage_fault, uint8_t motor_gatekill_fault, uint8_t locked_rotor_fault, uint8_t power_limit_warning)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ESC_STATUS_LEN];
    _mav_put_uint8_t(buf, 0, link_break_fault);
    _mav_put_uint8_t(buf, 1, over_temperatuer_fault);
    _mav_put_uint8_t(buf, 2, dc_voltage_fault);
    _mav_put_uint8_t(buf, 3, motor_gatekill_fault);
    _mav_put_uint8_t(buf, 4, locked_rotor_fault);
    _mav_put_uint8_t(buf, 5, power_limit_warning);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ESC_STATUS, buf, MAVLINK_MSG_ID_ESC_STATUS_MIN_LEN, MAVLINK_MSG_ID_ESC_STATUS_LEN, MAVLINK_MSG_ID_ESC_STATUS_CRC);
#else
    mavlink_esc_status_t packet;
    packet.link_break_fault = link_break_fault;
    packet.over_temperatuer_fault = over_temperatuer_fault;
    packet.dc_voltage_fault = dc_voltage_fault;
    packet.motor_gatekill_fault = motor_gatekill_fault;
    packet.locked_rotor_fault = locked_rotor_fault;
    packet.power_limit_warning = power_limit_warning;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ESC_STATUS, (const char *)&packet, MAVLINK_MSG_ID_ESC_STATUS_MIN_LEN, MAVLINK_MSG_ID_ESC_STATUS_LEN, MAVLINK_MSG_ID_ESC_STATUS_CRC);
#endif
}

/**
 * @brief Send a esc_status message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_esc_status_send_struct(mavlink_channel_t chan, const mavlink_esc_status_t* esc_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_esc_status_send(chan, esc_status->link_break_fault, esc_status->over_temperatuer_fault, esc_status->dc_voltage_fault, esc_status->motor_gatekill_fault, esc_status->locked_rotor_fault, esc_status->power_limit_warning);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ESC_STATUS, (const char *)esc_status, MAVLINK_MSG_ID_ESC_STATUS_MIN_LEN, MAVLINK_MSG_ID_ESC_STATUS_LEN, MAVLINK_MSG_ID_ESC_STATUS_CRC);
#endif
}

#if MAVLINK_MSG_ID_ESC_STATUS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_esc_status_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t link_break_fault, uint8_t over_temperatuer_fault, uint8_t dc_voltage_fault, uint8_t motor_gatekill_fault, uint8_t locked_rotor_fault, uint8_t power_limit_warning)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 0, link_break_fault);
    _mav_put_uint8_t(buf, 1, over_temperatuer_fault);
    _mav_put_uint8_t(buf, 2, dc_voltage_fault);
    _mav_put_uint8_t(buf, 3, motor_gatekill_fault);
    _mav_put_uint8_t(buf, 4, locked_rotor_fault);
    _mav_put_uint8_t(buf, 5, power_limit_warning);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ESC_STATUS, buf, MAVLINK_MSG_ID_ESC_STATUS_MIN_LEN, MAVLINK_MSG_ID_ESC_STATUS_LEN, MAVLINK_MSG_ID_ESC_STATUS_CRC);
#else
    mavlink_esc_status_t *packet = (mavlink_esc_status_t *)msgbuf;
    packet->link_break_fault = link_break_fault;
    packet->over_temperatuer_fault = over_temperatuer_fault;
    packet->dc_voltage_fault = dc_voltage_fault;
    packet->motor_gatekill_fault = motor_gatekill_fault;
    packet->locked_rotor_fault = locked_rotor_fault;
    packet->power_limit_warning = power_limit_warning;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ESC_STATUS, (const char *)packet, MAVLINK_MSG_ID_ESC_STATUS_MIN_LEN, MAVLINK_MSG_ID_ESC_STATUS_LEN, MAVLINK_MSG_ID_ESC_STATUS_CRC);
#endif
}
#endif

#endif

// MESSAGE ESC_STATUS UNPACKING


/**
 * @brief Get field link_break_fault from esc_status message
 *
 * @return User mode UART link break fault.
 */
static inline uint8_t mavlink_msg_esc_status_get_link_break_fault(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field over_temperatuer_fault from esc_status message
 *
 * @return Over temperature fault.
 */
static inline uint8_t mavlink_msg_esc_status_get_over_temperatuer_fault(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Get field dc_voltage_fault from esc_status message
 *
 * @return DC bus undervoltage fault and DC bus Critical overvoltage fault.
 */
static inline uint8_t mavlink_msg_esc_status_get_dc_voltage_fault(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  2);
}

/**
 * @brief Get field motor_gatekill_fault from esc_status message
 *
 * @return Motor gatekill fault.
 */
static inline uint8_t mavlink_msg_esc_status_get_motor_gatekill_fault(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  3);
}

/**
 * @brief Get field locked_rotor_fault from esc_status message
 *
 * @return Locked rotor.
 */
static inline uint8_t mavlink_msg_esc_status_get_locked_rotor_fault(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  4);
}

/**
 * @brief Get field power_limit_warning from esc_status message
 *
 * @return Motor power reach limit.
 */
static inline uint8_t mavlink_msg_esc_status_get_power_limit_warning(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  5);
}

/**
 * @brief Decode a esc_status message into a struct
 *
 * @param msg The message to decode
 * @param esc_status C-struct to decode the message contents into
 */
static inline void mavlink_msg_esc_status_decode(const mavlink_message_t* msg, mavlink_esc_status_t* esc_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    esc_status->link_break_fault = mavlink_msg_esc_status_get_link_break_fault(msg);
    esc_status->over_temperatuer_fault = mavlink_msg_esc_status_get_over_temperatuer_fault(msg);
    esc_status->dc_voltage_fault = mavlink_msg_esc_status_get_dc_voltage_fault(msg);
    esc_status->motor_gatekill_fault = mavlink_msg_esc_status_get_motor_gatekill_fault(msg);
    esc_status->locked_rotor_fault = mavlink_msg_esc_status_get_locked_rotor_fault(msg);
    esc_status->power_limit_warning = mavlink_msg_esc_status_get_power_limit_warning(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_ESC_STATUS_LEN? msg->len : MAVLINK_MSG_ID_ESC_STATUS_LEN;
        memset(esc_status, 0, MAVLINK_MSG_ID_ESC_STATUS_LEN);
    memcpy(esc_status, _MAV_PAYLOAD(msg), len);
#endif
}
