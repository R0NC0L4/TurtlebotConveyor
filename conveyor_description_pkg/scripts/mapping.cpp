// This program publishes randomly-generated velocity
// messages for turtlesim.
#include <ros/ros.h>
#include <std_msgs/Float32.h> // For geometry_msgs::Twist
#include <stdlib.h>           // For rand() and RAND_MAX
#include <termios.h>
#include <conveyor_description_pkg/conveyor_state.h>
#include <conveyor_description_pkg/desired_conf.h>
#include <cmath>

ros::Publisher pub;

void subCallback(const conveyor_description_pkg::desired_conf msg)
{
  conveyor_description_pkg::conveyor_state state;
  float vlc = msg.velocity;
  if (msg.rotate == false)
  {
    if (msg.angle <= 45 && msg.angle >= -45)
    {
      float ang = msg.angle + 180;

      state.wheel_lr = -vlc;
      state.wheel_rr = vlc;
      state.wheel_lf = -vlc;
      state.wheel_rf = vlc;

      state.joint_lr = ang - 45;
      state.joint_rr = ang + 45;
      state.joint_lf = ang + 45;
      state.joint_rf = ang - 45;
    }
    else if ((msg.angle < 135 && msg.angle > 45))
    {
      float ang = msg.angle + 90;

      state.wheel_lr = -vlc;
      state.wheel_rr = -vlc;
      state.wheel_lf = vlc;
      state.wheel_rf = vlc;

      state.joint_lr = ang + 45;
      state.joint_rr = ang - 45;
      state.joint_lf = ang - 45;
      state.joint_rf = ang + 45;
    }
    else if ((msg.angle >= 135 && msg.angle <= 180))
    {
      float ang = abs(msg.angle);

      state.wheel_lr = vlc;
      state.wheel_rr = -vlc;
      state.wheel_lf = vlc;
      state.wheel_rf = -vlc;

      state.joint_lr = ang - 45;
      state.joint_rr = ang + 45;
      state.joint_lf = ang + 45;
      state.joint_rf = ang - 45;
    }
    else if ((msg.angle >= -180 && msg.angle <= -135))
    {
      float ang = msg.angle + 360;

      state.wheel_lr = vlc;
      state.wheel_rr = -vlc;
      state.wheel_lf = vlc;
      state.wheel_rf = -vlc;

      state.joint_lr = ang - 45;
      state.joint_rr = ang + 45;
      state.joint_lf = ang + 45;
      state.joint_rf = ang - 45;
    }
    else if (msg.angle > -135 && msg.angle < -45)
    {
      float ang = msg.angle + 270;

      state.wheel_lr = vlc;
      state.wheel_rr = vlc;
      state.wheel_lf = -vlc;
      state.wheel_rf = -vlc;

      state.joint_lr = ang + 45;
      state.joint_rr = ang - 45;
      state.joint_lf = ang - 45;
      state.joint_rf = ang + 45;
    }
  }
  else
  {
      float ang = 180;

      state.wheel_lr = vlc;
      state.wheel_rr = vlc;
      state.wheel_lf = vlc;
      state.wheel_rf = vlc;

      state.joint_lr = ang;
      state.joint_rr = ang;
      state.joint_lf = ang;
      state.joint_rf = ang;
  }

  // Publish the message.
  pub.publish(state);
}

int main(int argc, char **argv)
{

  // Initialize the ROS system and become a node.
  ros::init(argc, argv, "model_mapping");
  ros::NodeHandle nh;

  // Create a publisher object.
  pub = nh.advertise<conveyor_description_pkg::conveyor_state>("conveyor_state", 1000);

  // Create a subscriber object.
  ros::Subscriber sub = nh.subscribe("desired_configuration", 1000, subCallback);

  // Loop at 2Hz until the node is shut down.
  ros::Rate rate(2);

  while (ros::ok())
  {
    // Wait until it's time for another iteration.
    ros::spin();
  }
}