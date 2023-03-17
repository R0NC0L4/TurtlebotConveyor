// This program publishes randomly-generated velocity
// messages for turtlesim.
#include <ros/ros.h>
#include <std_msgs/Float64.h> // For geometry_msgs::Twist
#include <stdlib.h>           // For rand() and RAND_MAX
#include <termios.h>
#include <conveyor_description_pkg/conveyor_state.h>

// Create a publisher object (to gazebo simulation)
ros::Publisher pub_fr;
ros::Publisher pub_fl;
ros::Publisher pub_br;
ros::Publisher pub_bl;

ros::Publisher pub_fr_w;
ros::Publisher pub_fl_w;
ros::Publisher pub_br_w;
ros::Publisher pub_bl_w;

void subCallback(const conveyor_description_pkg::conveyor_state state)
{  
  float pi = 3.14159265359;

  std_msgs::Float64 wheel_lr;
  std_msgs::Float64 wheel_rr;
  std_msgs::Float64 wheel_lf;
  std_msgs::Float64 wheel_rf;

  std_msgs::Float64 joint_lr;
  std_msgs::Float64 joint_rr;
  std_msgs::Float64 joint_lf;
  std_msgs::Float64 joint_rf;

  wheel_lr.data = -state.wheel_lr/10;
  wheel_rr.data = state.wheel_rr/10;
  wheel_lf.data = -state.wheel_lf/10;
  wheel_rf.data = state.wheel_rf/10;

  joint_lr.data = -(state.joint_lr-180)*pi/180;
  joint_rr.data = -(state.joint_rr-180)*pi/180;
  joint_lf.data = -(state.joint_lf-180)*pi/180;
  joint_rf.data = -(state.joint_rf-180)*pi/180;

  // Publish the message.
  pub_bl_w.publish(wheel_lr);
  pub_br_w.publish(wheel_rr);
  pub_fl_w.publish(wheel_lf);
  pub_fr_w.publish(wheel_rf);

  pub_bl.publish(joint_lr);
  pub_br.publish(joint_rr);
  pub_fl.publish(joint_lf);
  pub_fr.publish(joint_rf);

}

int main(int argc, char **argv)
{

  // Initialize the ROS system and become a node.
  ros::init(argc, argv, "control2gazebo");
  ros::NodeHandle nh;

  // Create a publisher object (to gazebo simulation)
  pub_fr = nh.advertise<std_msgs::Float64>("conveyor/servo_front_right_position_controller/command", 1000);
  pub_fl = nh.advertise<std_msgs::Float64>("conveyor/servo_front_left_position_controller/command", 1000);
  pub_br = nh.advertise<std_msgs::Float64>("conveyor/servo_back_right_position_controller/command", 1000);
  pub_bl = nh.advertise<std_msgs::Float64>("conveyor/servo_back_left_position_controller/command", 1000);

  pub_fr_w = nh.advertise<std_msgs::Float64>("conveyor/front_right_wheel_velocity_controller/command", 1000);
  pub_fl_w = nh.advertise<std_msgs::Float64>("conveyor/front_left_wheel_velocity_controller/command", 1000);
  pub_br_w = nh.advertise<std_msgs::Float64>("conveyor/back_right_wheel_velocity_controller/command", 1000);
  pub_bl_w = nh.advertise<std_msgs::Float64>("conveyor/back_left_wheel_velocity_controller/command", 1000);

  // Create a subscriber object.
  ros::Subscriber sub = nh.subscribe("conveyor_state", 1000, subCallback);

  // Loop at 2Hz until the node is shut down.
  ros::Rate rate(2);

  while (ros::ok())
  {
    // Wait until it's time for another iteration.
    ros::spin();
  }
}