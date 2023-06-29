// This program publishes control commands into gazebo topics
#include <ros/ros.h>
#include <std_msgs/Float64.h> 
#include <stdlib.h>           
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

  wheel_lr.data = state.wheel_lr;
  wheel_rr.data = state.wheel_rr;
  wheel_lf.data = state.wheel_lf;
  wheel_rf.data = state.wheel_rf;

  joint_lr.data = (state.joint_lr)*pi/180;
  joint_rr.data = (state.joint_rr)*pi/180;
  joint_lf.data = (state.joint_lf)*pi/180;
  joint_rf.data = (state.joint_rf)*pi/180;

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

  std::string param;
  // nh.getParam("namespace", param);
  ros::param::get("~namespace", param);
  // nh.getParam("namespace", name_space);
  // ROS_INFO_STREAM( "NAME : " << name_space);

  // Create a publisher object (to gazebo simulation)
  pub_fr = nh.advertise<std_msgs::Float64>("/" + param + "/servo_front_right_position_controller/command", 1000);
  pub_fl = nh.advertise<std_msgs::Float64>("/" + param + "/servo_front_left_position_controller/command", 1000);
  pub_br = nh.advertise<std_msgs::Float64>("/" + param + "/servo_back_right_position_controller/command", 1000);
  pub_bl = nh.advertise<std_msgs::Float64>("/" + param + "/servo_back_left_position_controller/command", 1000);

  pub_fr_w = nh.advertise<std_msgs::Float64>("/" + param + "/front_right_wheel_velocity_controller/command", 1000);
  pub_fl_w = nh.advertise<std_msgs::Float64>("/" + param + "/front_left_wheel_velocity_controller/command", 1000);
  pub_br_w = nh.advertise<std_msgs::Float64>("/" + param + "/back_right_wheel_velocity_controller/command", 1000);
  pub_bl_w = nh.advertise<std_msgs::Float64>("/" + param + "/back_left_wheel_velocity_controller/command", 1000);

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