#include <ros.h>
#include <std_msgs/Float32.h>
#include <Dynamixel2Arduino.h>

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
const uint8_t DXL_ID_talker = 2;    // talker sends its positions
const uint8_t DXL_ID_listener = 1;  // listener follows that position
const float DXL_PROTOCOL_VERSION = 2.0;
Dynamixel2Arduino dxl(DXL_SERIAL, DXL_DIR_PIN);

// ROS Node
ros::NodeHandle  nh;

void messageCb( const std_msgs::Float32& toggle_msg){
    dxl.setGoalPosition(DXL_ID_listener, toggle_msg.data, UNIT_DEGREE);
}

// publisher
std_msgs::Float32 deg_msg;
ros::Publisher pub("wheel", &deg_msg);
// subscriber
ros::Subscriber<std_msgs::Float32> sub("wheel", &messageCb );

//This namespace is required to use Control table item names
using namespace ControlTableItem;

void setup()
{ 
  // Dynamixel setup //
  // Set Port baudrate to 1Mbps. This has to match with DYNAMIXEL baudrate.
  dxl.begin(1000000);
  // Set Port Protocol Version. This has to match with DYNAMIXEL protocol version.
  dxl.setPortProtocolVersion(DXL_PROTOCOL_VERSION);
  // Get DYNAMIXEL information
  dxl.ping(DXL_ID_talker);
  dxl.ping(DXL_ID_listener);

  // Turn off torque when configuring items in EEPROM area
  dxl.torqueOff(DXL_ID_talker);
  dxl.setOperatingMode(DXL_ID_talker, OP_CURRENT_BASED_POSITION);
  dxl.torqueOn(DXL_ID_talker);
  
  dxl.torqueOff(DXL_ID_listener);
  dxl.setOperatingMode(DXL_ID_listener, OP_POSITION);
  dxl.torqueOn(DXL_ID_listener);

  // Limit the maximum velocity in Position Control Mode. Use 0 for Max speed
  dxl.writeControlTableItem(PROFILE_VELOCITY, DXL_ID_talker, 0);
  dxl.writeControlTableItem(PROFILE_VELOCITY, DXL_ID_listener, 0);
  
  // ROS Node setup
  nh.initNode();
  nh.advertise(pub);
  nh.subscribe(sub);
}

void loop()
{  
  // get and publish talker position
  deg_msg.data = dxl.getPresentPosition(DXL_ID_talker, UNIT_DEGREE);
  pub.publish(&deg_msg);
  Serial.println(deg_msg.data);
  
  nh.spinOnce();
  delay(10);
}
