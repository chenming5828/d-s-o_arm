/** @file
 *	@brief MAVLink comm protocol testsuite generated from brisky.xml
 *	@see http://qgroundcontrol.org/mavlink/
 */
#ifndef BRISKY_TESTSUITE_H
#define BRISKY_TESTSUITE_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef MAVLINK_TEST_ALL
#define MAVLINK_TEST_ALL
static void mavlink_test_common(uint8_t, uint8_t, mavlink_message_t *last_msg);
static void mavlink_test_brisky(uint8_t, uint8_t, mavlink_message_t *last_msg);

static void mavlink_test_all(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_test_common(system_id, component_id, last_msg);
	mavlink_test_brisky(system_id, component_id, last_msg);
}
#endif

#include "../common/testsuite.h"


static void mavlink_test_infrared_distance(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_infrared_distance_t packet_in = {
		17.0,45.0,73.0,101.0
    };
	mavlink_infrared_distance_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.distance_x_p = packet_in.distance_x_p;
        packet1.distance_x_n = packet_in.distance_x_n;
        packet1.distance_y_p = packet_in.distance_y_p;
        packet1.distance_y_n = packet_in.distance_y_n;
        
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_infrared_distance_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_infrared_distance_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_infrared_distance_pack(system_id, component_id, &msg , packet1.distance_x_p , packet1.distance_x_n , packet1.distance_y_p , packet1.distance_y_n );
	mavlink_msg_infrared_distance_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_infrared_distance_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.distance_x_p , packet1.distance_x_n , packet1.distance_y_p , packet1.distance_y_n );
	mavlink_msg_infrared_distance_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_infrared_distance_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_infrared_distance_send(MAVLINK_COMM_1 , packet1.distance_x_p , packet1.distance_x_n , packet1.distance_y_p , packet1.distance_y_n );
	mavlink_msg_infrared_distance_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_svo_position_raw(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_svo_position_raw_t packet_in = {
		93372036854775807ULL,73.0,101.0,129.0,157.0,185.0,213.0,241.0,113
    };
	mavlink_svo_position_raw_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.timestamp = packet_in.timestamp;
        packet1.position_x = packet_in.position_x;
        packet1.position_y = packet_in.position_y;
        packet1.position_z = packet_in.position_z;
        packet1.q0 = packet_in.q0;
        packet1.q1 = packet_in.q1;
        packet1.q2 = packet_in.q2;
        packet1.q3 = packet_in.q3;
        packet1.svo_valid = packet_in.svo_valid;
        
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_svo_position_raw_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_svo_position_raw_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_svo_position_raw_pack(system_id, component_id, &msg , packet1.timestamp , packet1.position_x , packet1.position_y , packet1.position_z , packet1.q0 , packet1.q1 , packet1.q2 , packet1.q3 , packet1.svo_valid );
	mavlink_msg_svo_position_raw_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_svo_position_raw_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.timestamp , packet1.position_x , packet1.position_y , packet1.position_z , packet1.q0 , packet1.q1 , packet1.q2 , packet1.q3 , packet1.svo_valid );
	mavlink_msg_svo_position_raw_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_svo_position_raw_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_svo_position_raw_send(MAVLINK_COMM_1 , packet1.timestamp , packet1.position_x , packet1.position_y , packet1.position_z , packet1.q0 , packet1.q1 , packet1.q2 , packet1.q3 , packet1.svo_valid );
	mavlink_msg_svo_position_raw_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_data_for_hover(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_data_for_hover_t packet_in = {
		93372036854775807ULL,73.0,101.0,129.0,157.0,185.0,213.0,241.0,269.0,297.0
    };
	mavlink_data_for_hover_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.timestamp = packet_in.timestamp;
        packet1.current_distance = packet_in.current_distance;
        packet1.q0 = packet_in.q0;
        packet1.q1 = packet_in.q1;
        packet1.q2 = packet_in.q2;
        packet1.q3 = packet_in.q3;
        packet1.R = packet_in.R;
        packet1.x = packet_in.x;
        packet1.y = packet_in.y;
        packet1.z = packet_in.z;
        
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_data_for_hover_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_data_for_hover_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_data_for_hover_pack(system_id, component_id, &msg , packet1.timestamp , packet1.current_distance , packet1.q0 , packet1.q1 , packet1.q2 , packet1.q3 , packet1.R , packet1.x , packet1.y , packet1.z );
	mavlink_msg_data_for_hover_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_data_for_hover_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.timestamp , packet1.current_distance , packet1.q0 , packet1.q1 , packet1.q2 , packet1.q3 , packet1.R , packet1.x , packet1.y , packet1.z );
	mavlink_msg_data_for_hover_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_data_for_hover_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_data_for_hover_send(MAVLINK_COMM_1 , packet1.timestamp , packet1.current_distance , packet1.q0 , packet1.q1 , packet1.q2 , packet1.q3 , packet1.R , packet1.x , packet1.y , packet1.z );
	mavlink_msg_data_for_hover_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_data_for_stabilization(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_data_for_stabilization_t packet_in = {
		93372036854775807ULL,73.0,101.0,129.0,157.0
    };
	mavlink_data_for_stabilization_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.timestamp = packet_in.timestamp;
        packet1.yaw = packet_in.yaw;
        packet1.acc_ned_0 = packet_in.acc_ned_0;
        packet1.acc_ned_1 = packet_in.acc_ned_1;
        packet1.acc_ned_2 = packet_in.acc_ned_2;
        
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_data_for_stabilization_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_data_for_stabilization_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_data_for_stabilization_pack(system_id, component_id, &msg , packet1.timestamp , packet1.yaw , packet1.acc_ned_0 , packet1.acc_ned_1 , packet1.acc_ned_2 );
	mavlink_msg_data_for_stabilization_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_data_for_stabilization_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.timestamp , packet1.yaw , packet1.acc_ned_0 , packet1.acc_ned_1 , packet1.acc_ned_2 );
	mavlink_msg_data_for_stabilization_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_data_for_stabilization_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_data_for_stabilization_send(MAVLINK_COMM_1 , packet1.timestamp , packet1.yaw , packet1.acc_ned_0 , packet1.acc_ned_1 , packet1.acc_ned_2 );
	mavlink_msg_data_for_stabilization_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_vot_offset(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_vot_offset_t packet_in = {
		93372036854775807ULL,73.0,101.0,129.0,65
    };
	mavlink_vot_offset_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.timestamp = packet_in.timestamp;
        packet1.xoffset = packet_in.xoffset;
        packet1.yoffset = packet_in.yoffset;
        packet1.pitch_relative = packet_in.pitch_relative;
        packet1.tracking_enabled = packet_in.tracking_enabled;
        
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_vot_offset_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_vot_offset_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_vot_offset_pack(system_id, component_id, &msg , packet1.timestamp , packet1.xoffset , packet1.yoffset , packet1.pitch_relative , packet1.tracking_enabled );
	mavlink_msg_vot_offset_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_vot_offset_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.timestamp , packet1.xoffset , packet1.yoffset , packet1.pitch_relative , packet1.tracking_enabled );
	mavlink_msg_vot_offset_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_vot_offset_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_vot_offset_send(MAVLINK_COMM_1 , packet1.timestamp , packet1.xoffset , packet1.yoffset , packet1.pitch_relative , packet1.tracking_enabled );
	mavlink_msg_vot_offset_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_vot_obj_info(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_vot_obj_info_t packet_in = {
		17.0,17443,17547,17651,17755,41
    };
	mavlink_vot_obj_info_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.pitch_relative = packet_in.pitch_relative;
        packet1.top_left_x = packet_in.top_left_x;
        packet1.top_left_y = packet_in.top_left_y;
        packet1.width = packet_in.width;
        packet1.height = packet_in.height;
        packet1.state = packet_in.state;
        
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_vot_obj_info_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_vot_obj_info_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_vot_obj_info_pack(system_id, component_id, &msg , packet1.top_left_x , packet1.top_left_y , packet1.width , packet1.height , packet1.pitch_relative , packet1.state );
	mavlink_msg_vot_obj_info_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_vot_obj_info_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.top_left_x , packet1.top_left_y , packet1.width , packet1.height , packet1.pitch_relative , packet1.state );
	mavlink_msg_vot_obj_info_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_vot_obj_info_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_vot_obj_info_send(MAVLINK_COMM_1 , packet1.top_left_x , packet1.top_left_y , packet1.width , packet1.height , packet1.pitch_relative , packet1.state );
	mavlink_msg_vot_obj_info_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_sos_cmd(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_sos_cmd_t packet_in = {
		5,72,{ 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238 }
    };
	mavlink_sos_cmd_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.command = packet_in.command;
        packet1.state = packet_in.state;
        
        mav_array_memcpy(packet1.body, packet_in.body, sizeof(uint8_t)*100);
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_sos_cmd_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_sos_cmd_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_sos_cmd_pack(system_id, component_id, &msg , packet1.command , packet1.state , packet1.body );
	mavlink_msg_sos_cmd_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_sos_cmd_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.command , packet1.state , packet1.body );
	mavlink_msg_sos_cmd_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_sos_cmd_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_sos_cmd_send(MAVLINK_COMM_1 , packet1.command , packet1.state , packet1.body );
	mavlink_msg_sos_cmd_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_esc_raw(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_esc_raw_t packet_in = {
		{ 17235, 17236, 17237, 17238 },{ 17651, 17652, 17653, 17654 }
    };
	mavlink_esc_raw_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        
        mav_array_memcpy(packet1.esc_rpm, packet_in.esc_rpm, sizeof(uint16_t)*4);
        mav_array_memcpy(packet1.esc_rpm_cmd, packet_in.esc_rpm_cmd, sizeof(uint16_t)*4);
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_esc_raw_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_esc_raw_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_esc_raw_pack(system_id, component_id, &msg , packet1.esc_rpm , packet1.esc_rpm_cmd );
	mavlink_msg_esc_raw_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_esc_raw_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.esc_rpm , packet1.esc_rpm_cmd );
	mavlink_msg_esc_raw_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_esc_raw_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_esc_raw_send(MAVLINK_COMM_1 , packet1.esc_rpm , packet1.esc_rpm_cmd );
	mavlink_msg_esc_raw_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_peripheral_error_state(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_peripheral_error_state_t packet_in = {
		17235,17339,17443
    };
	mavlink_peripheral_error_state_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.errors_state1 = packet_in.errors_state1;
        packet1.errors_state2 = packet_in.errors_state2;
        packet1.errors_state3 = packet_in.errors_state3;
        
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_peripheral_error_state_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_peripheral_error_state_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_peripheral_error_state_pack(system_id, component_id, &msg , packet1.errors_state1 , packet1.errors_state2 , packet1.errors_state3 );
	mavlink_msg_peripheral_error_state_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_peripheral_error_state_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.errors_state1 , packet1.errors_state2 , packet1.errors_state3 );
	mavlink_msg_peripheral_error_state_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_peripheral_error_state_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_peripheral_error_state_send(MAVLINK_COMM_1 , packet1.errors_state1 , packet1.errors_state2 , packet1.errors_state3 );
	mavlink_msg_peripheral_error_state_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_brisky(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_test_infrared_distance(system_id, component_id, last_msg);
	mavlink_test_svo_position_raw(system_id, component_id, last_msg);
	mavlink_test_data_for_hover(system_id, component_id, last_msg);
	mavlink_test_data_for_stabilization(system_id, component_id, last_msg);
	mavlink_test_vot_offset(system_id, component_id, last_msg);
	mavlink_test_vot_obj_info(system_id, component_id, last_msg);
	mavlink_test_sos_cmd(system_id, component_id, last_msg);
	mavlink_test_esc_raw(system_id, component_id, last_msg);
	mavlink_test_peripheral_error_state(system_id, component_id, last_msg);
}

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // BRISKY_TESTSUITE_H
