#include "ros/ros.h"
#include "math.h"
#include "ros/time.h"
#include "sensor_msgs/JointState.h"

int main(int argv, char **argc)
{
  // Initialize node
  ros::init(argv, argc, "CPP_Joint_State_Controller");
  // Node handler
  ros::NodeHandle nodeHandler;
  // Publisher
  ros::Publisher publisherObject = nodeHandler.advertise<sensor_msgs::JointState>("joint_states", 10);
  // Rate controller 5 Hz
  ros::Rate rateController = ros::Rate(20);
  // Variables
  float angle = 3.14; // Angle
  bool increment = true;
  sensor_msgs::JointState msg; // Message to be published
  msg.header.frame_id = "";    // Empty frame ID
  msg.name.resize(8);          // A 1 unit size vector
  msg.position.resize(8);      // A 1 unit size vector
  msg.name = {"servo_front_left_joint",
              "front_left_wheel_joint",
              "servo_front_right_joint",
              "front_right_wheel_joint",
              "servo_back_left_joint",
              "back_left_wheel_joint",
              "servo_back_right_joint",
              "back_right_wheel_joint"};
  // Main iterative code
  while (ros::ok())
  {
    // Update header
    msg.header.stamp = ros::Time::now(); // Assign time
    for (int i = 0; i < 8; i++)
    {
      msg.position[i] = angle;
    }
    publisherObject.publish(msg);
    // Control rate
    rateController.sleep();
  }
  // End code
  return 0;
}
