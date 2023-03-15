#include <ros.h>
#include <std_msgs/Float32.h>
#include <Dynamixel2Arduino.h>
#include <conveyor_description_pkg/conveyor_state.h>

// Please modify it to suit your hardware.
#if defined(ARDUINO_AVR_UNO) || defined(ARDUINO_AVR_MEGA2560) // When using DynamixelShield
  #include <SoftwareSerial.h>
  SoftwareSerial soft_serial(7, 8); // DYNAMIXELShield UART RX/TX
  #define DXL_SERIAL   Serial
  #define DEBUG_SERIAL soft_serial
  const int DXL_DIR_PIN = 2; // DYNAMIXEL Shield DIR PIN
#elif defined(ARDUINO_SAM_DUE) // When using DynamixelShield
  #define DXL_SERIAL   Serial
  #define DEBUG_SERIAL SerialUSB
  const int DXL_DIR_PIN = 2; // DYNAMIXEL Shield DIR PIN
#elif defined(ARDUINO_SAM_ZERO) // When using DynamixelShield
  #define DXL_SERIAL   Serial1
  #define DEBUG_SERIAL SerialUSB
  const int DXL_DIR_PIN = 2; // DYNAMIXEL Shield DIR PIN
#elif defined(ARDUINO_OpenCM904) // When using official ROBOTIS board with DXL circuit.
  #define DXL_SERIAL   Serial3 //OpenCM9.04 EXP Board's DXL port Serial. (Serial1 for the DXL port on the OpenCM 9.04 board)
  #define DEBUG_SERIAL Serial
  const int DXL_DIR_PIN = 22; //OpenCM9.04 EXP Board's DIR PIN. (28 for the DXL port on the OpenCM 9.04 board)
#elif defined(ARDUINO_OpenCR) // When using official ROBOTIS board with DXL circuit.
  // For OpenCR, there is a DXL Power Enable pin, so you must initialize and control it.
  // Reference link : https://github.com/ROBOTIS-GIT/OpenCR/blob/master/arduino/opencr_arduino/opencr/libraries/DynamixelSDK/src/dynamixel_sdk/port_handler_arduino.cpp#L78
  #define DXL_SERIAL   Serial3
  #define DEBUG_SERIAL Serial
  const int DXL_DIR_PIN = 84; // OpenCR Board's DIR PIN.
#elif defined(ARDUINO_OpenRB)  // When using OpenRB-150
  //OpenRB does not require the DIR control pin.
  #define DXL_SERIAL Serial1
  #define DEBUG_SERIAL Serial
  const int DXL_DIR_PIN = -1;
#else // Other boards when using DynamixelShield
  #define DXL_SERIAL   Serial1
  #define DEBUG_SERIAL Serial
  const int DXL_DIR_PIN = 2; // DYNAMIXEL Shield DIR PIN
#endif

// Dynamixel info
const uint8_t DXL_ID[] = {1, 2, 3, 4, 5, 6, 7, 8 };
const float DXL_PROTOCOL_VERSION = 2.0;
Dynamixel2Arduino dxl(DXL_SERIAL, DXL_DIR_PIN);

// ROS Node
ros::NodeHandle  nh;

// Set position/velocity
void messageCb( const conveyor_description_pkg::conveyor_state& toggle_msg){
   dxl.setGoalVelocity(DXL_ID[0], toggle_msg.wheel_lr);
   dxl.setGoalVelocity(DXL_ID[1], toggle_msg.wheel_rr);
   dxl.setGoalVelocity(DXL_ID[2], toggle_msg.wheel_lf);
   dxl.setGoalVelocity(DXL_ID[3], toggle_msg.wheel_rf);
   dxl.setGoalPosition(DXL_ID[4], toggle_msg.joint_lr, UNIT_DEGREE);
   dxl.setGoalPosition(DXL_ID[5], toggle_msg.joint_rr, UNIT_DEGREE);
   dxl.setGoalPosition(DXL_ID[6], toggle_msg.joint_lf, UNIT_DEGREE);
   dxl.setGoalPosition(DXL_ID[7], toggle_msg.joint_rf, UNIT_DEGREE);
}

// Subscribers
ros::Subscriber<conveyor_description_pkg::conveyor_state> sub("conveyor_state", &messageCb );

void setup()
{ 
  // Dynamixel setup //
  // Set Port baudrate to 1Mbps. This has to match with DYNAMIXEL baudrate.
  dxl.begin(1000000);
  // Set Port Protocol Version. This has to match with DYNAMIXEL protocol version.
  dxl.setPortProtocolVersion(DXL_PROTOCOL_VERSION);
  // Wheels
  for (int i = 0; i < 4; i++) {
    // Get DYNAMIXEL information
    dxl.ping(DXL_ID[i]);
    // Turn off torque when configuring items in EEPROM area
    dxl.torqueOff(DXL_ID[i]);
    dxl.setOperatingMode(DXL_ID[i], OP_VELOCITY);
    dxl.torqueOn(DXL_ID[i]);  
  }
  // Joints
  for (int i = 4; i < 8; i++) {
    // Get DYNAMIXEL information
    dxl.ping(DXL_ID[i]);
    // Turn off torque when configuring items in EEPROM area
    dxl.torqueOff(DXL_ID[i]);
    dxl.setOperatingMode(DXL_ID[i], OP_POSITION);
    dxl.torqueOn(DXL_ID[i]);  
  }
  
  // ROS Node setup
  nh.initNode();
  nh.subscribe(sub);
}

void loop()
{  
  nh.spinOnce();
  delay(1);
}
