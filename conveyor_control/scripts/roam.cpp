// This program publishes randomly-generated velocity
// messages for turtlesim.
#include <ros/ros.h>
#include <std_msgs/Float64.h> // For geometry_msgs::Twist
#include <stdlib.h>           // For rand() and RAND_MAX
#include <conveyor_description_pkg/desired_conf.h>
#include <sensor_msgs/LaserScan.h>

ros::Publisher pub;

int collision = 0;

void subCallback(const sensor_msgs::LaserScan msg)
{
   collision = (msg.ranges[msg.ranges.size() / 2] < 0.3);

   conveyor_description_pkg::desired_conf state;

   if (collision == 0)
   {
      state.velocity = 100;
      state.angle = 0;
      state.rotate = false;
   }
   else
   {
      state.velocity = 100;
      state.angle = 180;
      state.rotate = true;
      // TROVA UN MODO PER ASPETTARE TEMPO PER FARLO RUOTARE
   }

   // Publish the message.
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

   // Loop at 2Hz until the node is shut down.
   ros::Rate rate(2);

   float const_vel = 50;
   float orientation = 180;

   while (ros::ok())
   {

      ros::spin();

      // Wait until it's time for another iteration.
      // rate.sleep(); // Wait until it's time for another iteration.
   }
}