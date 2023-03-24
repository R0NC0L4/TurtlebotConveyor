// This program makes the robot move forward. If the robot sees an obstacles it will rotate.
#include <ros/ros.h>
#include <std_msgs/Float64.h> 
#include <stdlib.h>
#include <conveyor_description_pkg/desired_conf.h>
#include <sensor_msgs/LaserScan.h>

ros::Publisher pub;

int getCollision(const sensor_msgs::LaserScan msg, int window, float distance)
{
   int c = 0;
   int middle = msg.ranges.size() / 2;
   for (int i = 0; i < window; i++)
   {
      c = c || (msg.ranges[middle - (window / 2) + i] <= distance);
   }
   return c;
}

void subCallback(const sensor_msgs::LaserScan msg)
{
   int collision = getCollision(msg, 700, 0.3);

   conveyor_description_pkg::desired_conf state;

   if (collision == 0)
   {
      state.velocity = 100;
      state.angle = 0;
      state.rotate = false;
      pub.publish(state);
   }
   else
   {
      state.velocity = 100;
      state.angle = 180;
      state.rotate = true;

      pub.publish(state);
   }
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

   float const_vel = 50;
   float orientation = 180;

   while (ros::ok())
   {
      ros::spin();
      // rate.sleep();
   }
}