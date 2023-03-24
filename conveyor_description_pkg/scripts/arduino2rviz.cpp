#include <ros/ros.h>
#include <std_msgs/Float64.h> 
#include <stdlib.h>           
#include <termios.h>
#include <conveyor_description_pkg/conveyor_state.h>
#include <sensor_msgs/JointState.h>

// Create a publisher object (to gazebo simulation)
ros::Publisher pub;

void subCallback(const conveyor_description_pkg::conveyor_state state)
{
  float pi = 3.14159265359;

  sensor_msgs::JointState msg;

  msg.header.frame_id = ""; // Empty frame ID
  msg.name.resize(8);       // A 8 unit size vector
  msg.position.resize(8);   // A 8 unit size vector
  msg.name = {"servo_front_left_joint",
              "front_left_wheel_joint",
              "servo_front_right_joint",
              "front_right_wheel_joint",
              "servo_back_left_joint",
              "back_left_wheel_joint",
              "servo_back_right_joint",
              "back_right_wheel_joint"};

  float wheel_lr = state.wheel_lr * pi / 180;
  float wheel_rr = state.wheel_rr * pi / 180;
  float wheel_lf = state.wheel_lf * pi / 180;
  float wheel_rf = state.wheel_rf * pi / 180;
  float joint_lr = state.joint_lr * pi / 180;
  float joint_rr = state.joint_rr * pi / 180;
  float joint_lf = state.joint_lf * pi / 180;
  float joint_rf = state.joint_rf * pi / 180;
  float pos[] = {joint_lf, wheel_lf, joint_rf, wheel_rf, joint_lr, wheel_lr, joint_rr, wheel_rr};

  for (int i = 0; i < 8; i++)
  {
    msg.position[i] = pos[i];
  }

  // Publish the message.
  pub.publish(msg);
}

int main(int argc, char **argv)
{

  // Initialize the ROS system and become a node.
  ros::init(argc, argv, "arduino2rviz");
  ros::NodeHandle nh;

  // Create a publisher object (to gazebo simulation)
  pub = nh.advertise<sensor_msgs::JointState>("to_joint_states", 1000);

  // Create a subscriber object.
  ros::Subscriber sub = nh.subscribe("joint_state", 1000, subCallback);

  ros::Rate rateController = ros::Rate(20);

  // Main iterative code
  while (ros::ok())
  {
    // Control rate
    ros::spin();
    rateController.sleep();
  }
}