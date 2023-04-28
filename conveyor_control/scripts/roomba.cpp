// This program makes the robot move forward. If the robot sees an obstacles it will change direction.
#include <ros/ros.h>
#include <std_msgs/Float64.h>
#include <stdlib.h>
#include <conveyor_description_pkg/desired_conf.h>
#include <sensor_msgs/LaserScan.h>
#include <cmath>
#include <ros/console.h>

ros::Publisher pub;

class Listener
{
public:
   int changed = 0;
   float prev_angle = 0;

   void subCallback(const sensor_msgs::LaserScan msg);

   bool getCollision(const sensor_msgs::LaserScan msg, float distance);
};

bool Listener::getCollision(const sensor_msgs::LaserScan msg, float distance)
{
   int c = 0;
      
   for (int i = 0; i < msg.ranges.size(); i++)
   {
      c = c || (msg.ranges[i] <= distance && msg.ranges[i] > 0.11);
   }
   return c;
}

void Listener::subCallback(const sensor_msgs::LaserScan msg)
{
   bool collision = getCollision(msg, 0.3);

   conveyor_description_pkg::desired_conf state;
   float curr_vel = 10;
   float curr_angle = prev_angle;

   if (changed != 1)
   {
      if (collision == false)
      {
         state.velocity = curr_vel;
         state.angle = curr_angle;
      }
      else
      {
         changed = 1;
         state.velocity = curr_vel;
         int random_num = rand() % 100000;
         float change = 90 + ((double)random_num / 100000) * (180 - 90); // VEDI QUESTO PROBABILE ERRORE
         state.angle = (fmod(curr_angle + change, 360) - 180);
         // ROS_INFO("Collision. ANGLE: %f", state.angle);
      }
      prev_angle = state.angle;
      state.rotate = false;
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
   Listener listener;
   ros::Subscriber sub = nh.subscribe("scan", 1, &Listener::subCallback, &listener);

   ros::Rate rate(0.5);

   srand(time(NULL));

   while (ros::ok())
   {
      ros::spinOnce();
      // ROS_INFO("%d", listener.changed);
      if (listener.changed == 1)
      {
         rate.sleep();
         listener.changed = 0;
      }
   }
}