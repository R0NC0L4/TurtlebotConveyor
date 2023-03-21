// This program publishes randomly-generated velocity
// messages for turtlesim.
#include <ros/ros.h>
#include <std_msgs/Float64.h> // For geometry_msgs::Twist
#include <stdlib.h>           // For rand() and RAND_MAX
#include <termios.h>
#include <conveyor_description_pkg/conveyor_state.h>
#include <sensor_msgs/JointState.h>

// Create a publisher object (to gazebo simulation)
ros::Publisher pub;

void subCallback(const conveyor_description_pkg::conveyor_state state)
{

  //  DEVI CREARE UN PACCHETTO PER IL JOINT STATES
  float pi = 3.14159265359;

  sensor_msgs::JointState joint_msg;
  // joint_msg.name[0] = "coxa_joint_r1";
  // joint_msg.position[0] = q_out(0);
  // joint_msg_pub.publish(joint_msg);

  float wheel_lr = state.wheel_lr * pi / 180;
  float wheel_rr = state.wheel_rr * pi / 180;
  float wheel_lf = state.wheel_lf * pi / 180;
  float wheel_rf = state.wheel_rf * pi / 180;
  float joint_lr = state.joint_lr * pi / 180;
  float joint_rr = state.joint_rr * pi / 180;
  float joint_lf = state.joint_lf * pi / 180;
  float joint_rf = state.joint_rf * pi / 180;

  float pos[] = {wheel_lr, wheel_rr, wheel_lf, wheel_rf, joint_lr, joint_rr, joint_lf, joint_rf};
  float vel[] = {0, 0, 0, 0, 0, 0, 0, 0};
  float eff[] = {0, 0, 0, 0, 0, 0, 0, 0};

  joint_msg.position = pos;
  joint_msg.velocity = vel;
  joint_msg.effort = eff;

  // Publish the message.
  pub.publish(joint_msg);
}

int main(int argc, char **argv)
{

  // Initialize the ROS system and become a node.
  ros::init(argc, argv, "arduino2rviz");
  ros::NodeHandle nh;

  // Create a publisher object (to gazebo simulation)
  pub = nh.advertise<sensor_msgs::JointState>("joint_states", 1000);

  // Create a subscriber object.
  ros::Subscriber sub = nh.subscribe("joint_state", 1000, subCallback);

  // Loop at 2Hz until the node is shut down.
  ros::Rate rate(2);

  while (ros::ok())
  {
    // Wait until it's time for another iteration.
    ros::spin();
  }
}