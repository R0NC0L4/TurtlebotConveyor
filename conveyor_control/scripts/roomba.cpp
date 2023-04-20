// This program makes the robot move forward. If the robot sees an obstacles it will rotate.
#include <ros/ros.h>
#include <std_msgs/Float64.h>
#include <stdlib.h>
#include <conveyor_description_pkg/desired_conf.h>
#include <sensor_msgs/LaserScan.h>
#include <cmath>
#include <ros/console.h>

ros::Publisher pub;

int getCollision(const sensor_msgs::LaserScan msg, int window, float distance)
{
   int c = 0;
   for (int i = 0; i < msg.ranges.size(); i++)
   {
      c = c || (msg.ranges[i] <= distance);
   }
   return c;
}

void subCallback(const sensor_msgs::LaserScan msg)
{
   //int collision = getCollision(msg, 700, 50);
   bool collision = msg.range_min <= 0.5 && msg.range_min >= 0.05;
   
   conveyor_description_pkg::desired_conf state;
   float curr_vel = 10;
   float curr_angle = state.angle;

   if (collision == false)
   {
   state.velocity = curr_vel;
   state.angle = curr_angle;
   }
   else
   {
      state.velocity = curr_vel;
      // int random_num = rand() % 100000;
      // float change = M_PI / 2 + ((double)random_num / 100000) * (M_PI - M_PI / 2);
      // state.angle = (fmod(curr_angle + change + M_PI, 2*M_PI) - M_PI)*180/3.1459;
      state.angle = 90;
   }
   state.rotate = false;
   pub.publish(state);
}

int main(int argc, char **argv)
{
   // Initialize the ROS system and become a node.
   ros::init(argc, argv, "algorithm");
   ros::NodeHandle nh;

   // Create a publisher object.
   pub = nh.advertise<conveyor_description_pkg::desired_conf>("desired_configuration", 1000);

   // Create a subscriber object for scanner data.
   ros::Subscriber sub = nh.subscribe("scan", 1000, subCallback);

   ros::Rate rate(2);

   while (ros::ok())
   {
      ros::spin();
      // rate.sleep();
   }
}