// This program remaps orientation and velocity to make the robot move
#include <ros/ros.h>
#include <std_msgs/Float32.h>
#include <stdlib.h>
#include <termios.h>
#include <conveyor_description_pkg/conveyor_state.h>
#include <conveyor_description_pkg/desired_conf.h>
#include <cmath>

ros::Publisher pub;

float last_angle = 0;
int changed = 0;
int count = 0; // stop wheel for tn when changing configuration (omni)
int tn = 10; 

void subCallback(const conveyor_description_pkg::desired_conf msg)
{
  float ang_vel, vl, vr, ang, r, phi, phi_l, phi_r;
  float l = 0.255; // cm
  float w = l;     // cm
  conveyor_description_pkg::conveyor_state state;
  float vlc = msg.velocity;
  switch (msg.conf)
  {
  case 0: // OMNI

    if (msg.angle >= -180 && msg.angle <= 180)
    {
      if ((msg.angle < 45 && msg.angle > -45) || ((msg.angle == 45 && last_angle <= 45) || (msg.angle == -45 && last_angle >= -45)))
      {
        float ang = msg.angle + 180;

        state.wheel_lr = -vlc;
        state.wheel_rr = vlc;
        state.wheel_lf = -vlc;
        state.wheel_rf = vlc;

        if (!(last_angle < 45 && last_angle > -45) )
        {
          changed = 1;
        }

        if (changed == 1) 
        {
          state.wheel_lr = 0;
          state.wheel_rr = 0;
          state.wheel_lf = 0;
          state.wheel_rf = 0;
          count = count+1;
          if (count > tn)
          {
            count = 0;
            changed = 0;
          }
        }

        state.joint_lr = ang - 45;
        state.joint_rr = ang + 45;
        state.joint_lf = ang + 45;
        state.joint_rf = ang - 45;
      }
      else if ((msg.angle < 135 && msg.angle > 45) || ((msg.angle == 135 && last_angle <= 135) || (msg.angle == 45 && last_angle >= 45)))
      {
        float ang = msg.angle + 90;

        state.wheel_lr = -vlc;
        state.wheel_rr = -vlc;
        state.wheel_lf = vlc;
        state.wheel_rf = vlc;

        if (!(last_angle < 135 && last_angle > 45) )
        {
          changed = 1;
        }
        
        if (changed == 1) 
        {
          state.wheel_lr = 0;
          state.wheel_rr = 0;
          state.wheel_lf = 0;
          state.wheel_rf = 0;
          count = count+1;
          if (count > tn)
          {
            count = 0;
            changed = 0;
          }
        }

        state.joint_lr = ang + 45;
        state.joint_rr = ang - 45;
        state.joint_lf = ang - 45;
        state.joint_rf = ang + 45;
      }
      else if ((msg.angle > 135 && msg.angle < 180) || ((msg.angle == 180 && last_angle <= 180) || (msg.angle == 135 && last_angle >= 135)))
      {
        float ang = abs(msg.angle);

        state.wheel_lr = vlc;
        state.wheel_rr = -vlc;
        state.wheel_lf = vlc;
        state.wheel_rf = -vlc;

        if (!(last_angle > 135 && last_angle < 180) )
        {
          changed = 1;
        }
        
        if (changed == 1) 
        {
          state.wheel_lr = 0;
          state.wheel_rr = 0;
          state.wheel_lf = 0;
          state.wheel_rf = 0;
          count = count+1;
          if (count > tn)
          {
            count = 0;
            changed = 0;
          }
        }

        state.joint_lr = ang - 45;
        state.joint_rr = ang + 45;
        state.joint_lf = ang + 45;
        state.joint_rf = ang - 45;
      }
      else if ((msg.angle > -180 && msg.angle < -135) || ((msg.angle == -135 && last_angle <= -135) || (msg.angle == -180 && last_angle >= -180)))
      {
        float ang = msg.angle + 360;

        state.wheel_lr = vlc;
        state.wheel_rr = -vlc;
        state.wheel_lf = vlc;
        state.wheel_rf = -vlc;

        if (!(last_angle > -180 && last_angle < -135) )
        {
          changed = 1;
        }
        
        if (changed == 1) 
        {
          state.wheel_lr = 0;
          state.wheel_rr = 0;
          state.wheel_lf = 0;
          state.wheel_rf = 0;
          count = count+1;
          if (count > tn)
          {
            count = 0;
            changed = 0;
          }
        }

        state.joint_lr = ang - 45;
        state.joint_rr = ang + 45;
        state.joint_lf = ang + 45;
        state.joint_rf = ang - 45;
      }
      else if ((msg.angle > -135 && msg.angle < -45) || ((msg.angle == -45 && last_angle <= -45) || (msg.angle == -135 && last_angle >= -135)))
      {
        float ang = msg.angle + 270;

        state.wheel_lr = vlc;
        state.wheel_rr = vlc;
        state.wheel_lf = -vlc;
        state.wheel_rf = -vlc;

        if (!(last_angle > -135 && last_angle < -45) )
        {
          changed = 1;
        }
        
        if (changed == 1) 
        {
          state.wheel_lr = 0;
          state.wheel_rr = 0;
          state.wheel_lf = 0;
          state.wheel_rf = 0;
          count = count+1;
          if (count > tn)
          {
            count = 0;
            changed = 0;
          }
        }

        state.joint_lr = ang + 45;
        state.joint_rr = ang - 45;
        state.joint_lf = ang - 45;
        state.joint_rf = ang + 45;
      }
    }

    break;

  case 1: // differential |||| NOT WORKING ||||

    state.joint_lr = 135;
    state.joint_rr = 225;
    state.joint_lf = 225;
    state.joint_rf = 135;

    ang_vel = msg.angular_velocity;

    vr = (vlc + ang_vel * 0.255 / 2); // / 0.03;
    vl = (vlc - ang_vel * 0.255 / 2); // / 0.03;

    state.wheel_lr = -vl;
    state.wheel_rr = vr;
    state.wheel_lf = -vl;
    state.wheel_rf = vr;

    break;

  case 2: // ackerman

    state.joint_lr = 135;
    state.joint_rr = 225;

    phi = msg.angle;

    if (phi > -2 && phi < 2)
    {
      state.joint_lf = 225;
      state.joint_rf = 135;
    }
    else if ((msg.angle < 45 && msg.angle > -45) || ((msg.angle == 45 && last_angle <= 45) || (msg.angle == -45 && last_angle >= -45)))
    {
      // ang = msg.angle + 180;

      r = l / tan(phi * M_PI / 180.0);

      phi_l = (atan(l / (r - w / 2)) * 180 / M_PI) + 180;
      phi_r = (atan(l / (r + w / 2)) * 180 / M_PI) + 180;
      ROS_INFO("----------");
      ROS_INFO("left: %f", phi_l);
      ROS_INFO("right: %f", phi_r);
      ROS_INFO("----------");

      state.joint_lf = phi_l + 45;
      state.joint_rf = phi_r - 45;
    }

    state.wheel_lr = -vlc;
    state.wheel_rr = vlc;
    state.wheel_lf = -vlc;
    state.wheel_rf = vlc;

    break;

  case 3:

    ang = 180;
    ang_vel = msg.angular_velocity;

    state.wheel_lr = ang_vel;
    state.wheel_rr = ang_vel;
    state.wheel_lf = ang_vel;
    state.wheel_rf = ang_vel;

    state.joint_lr = ang;
    state.joint_rr = ang;
    state.joint_lf = ang;
    state.joint_rf = ang;

    break;

  default:
    state.joint_lr = 0;
    state.joint_rr = 0;
    state.joint_lf = 0;
    state.joint_rf = 0;
    state.wheel_lr = 0;
    state.wheel_rr = 0;
    state.wheel_lf = 0;
    state.wheel_rf = 0;
    break;
  }

  last_angle = msg.angle;

  // Publish the message.
  pub.publish(state);
}

int main(int argc, char **argv)
{

  // Initialize the ROS system and become a node.
  ros::init(argc, argv, "model_mapping");
  ros::NodeHandle nh;

  std::string name_space = "robot1";
  // nh.getParam("namespace", name_space);

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