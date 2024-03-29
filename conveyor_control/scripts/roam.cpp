// This program makes the robot move forward. If the robot sees an obstacles it will change direction.
#include <ros/ros.h>
#include <std_msgs/Float64.h>
#include <stdlib.h>
#include <conveyor_description_pkg/desired_conf.h>
#include <sensor_msgs/LaserScan.h>

ros::Publisher pub;

class Listener
{
public:
   int changed = 0;
   float prev_angle = 0;

   void subCallback(const sensor_msgs::LaserScan msg);

   int getCollision(const sensor_msgs::LaserScan msg, float distance);
};

int Listener::getCollision(const sensor_msgs::LaserScan msg, float distance) // return collision angle
{
   // ROS_INFO("%ld", msg.ranges.size());
   int dim = msg.ranges.size();
   for (int i = 0; i < dim; i++)
   {
      if (msg.ranges[i] < distance && msg.ranges[i] > 0.15)
      {
         return i * 360 / dim; // return collision angle
      }
   }
   // ROS_INFO("%d", 255);
   return 2555; // out of range value (no collision)
}

void Listener::subCallback(const sensor_msgs::LaserScan msg)
{
   int collisionAng = getCollision(msg, 0.3);
   ROS_INFO("%d", collisionAng);

   conveyor_description_pkg::desired_conf state;

   if (collisionAng == 2555) // no collsion
   {
      state.velocity = 100;
      state.angle = prev_angle;
   }
   else // collision
   {
      state.velocity = 100;

      // change direction
      int random = -10 + (rand() % 21);
      float newDir = (float)collisionAng + random;
      if (newDir > 180)
         newDir = newDir - 360;
      if (newDir < -180)
         newDir = -180;
      ROS_INFO("-->%f", newDir);
      state.angle = newDir;
   }
   prev_angle = state.angle;
   // ROS_INFO("%f", prev_angle);
   state.conf = 0;
   pub.publish(state);
}

int main(int argc, char **argv)
{
   srand(time(NULL));

   // Initialize the ROS system and become a node.
   ros::init(argc, argv, "algorithm");
   ros::NodeHandle nh;

   // Create a publisher object.
   pub = nh.advertise<conveyor_description_pkg::desired_conf>("desired_configuration", 1000);

   // Create a subscriber object for scanner data.
   Listener listener;
   ros::Subscriber sub = nh.subscribe("scan", 1, &Listener::subCallback, &listener);

   ros::Rate rate(2);

   listener.prev_angle = 0;

   while (ros::ok())
   {
      ros::spin();
      ROS_INFO("%d", listener.changed);
   }
}