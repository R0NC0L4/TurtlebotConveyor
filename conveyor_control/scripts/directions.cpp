// This program makes the robot move forward. If the robot sees an obstacles it will rotate.
#include <ros/ros.h>
#include <std_msgs/Float64.h>
#include <stdlib.h>
#include <conveyor_description_pkg/desired_conf.h>
#include <sensor_msgs/LaserScan.h>

ros::Publisher pub;

int main(int argc, char **argv)
{
   // Initialize the ROS system and become a node.
   ros::init(argc, argv, "algorithm");
   ros::NodeHandle nh;

   // Create a publisher object.
   pub = nh.advertise<conveyor_description_pkg::desired_conf>("desired_configuration", 1000);

   ros::Rate rate(10);

   int i = -180;
   int rot = 0;
   while (ros::ok())
   {
      conveyor_description_pkg::desired_conf state;

      state.velocity = 20;
      state.angle = i;
      state.conf = 0;

      pub.publish(state);

      if (rot==0)
         i = i + 1;
      else
         i = i - 1;

      if (i >= 180 && rot == 0)    
         rot = 1;      
      if (i <= -180 && rot == 1)    
         rot = 0;   

      rate.sleep();
   }
}