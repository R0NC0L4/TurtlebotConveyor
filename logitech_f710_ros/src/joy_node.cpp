#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <std_msgs/Float32.h>
#include <sensor_msgs/Joy.h>
#include <ros/console.h>
#include <conveyor_description_pkg/buttons.h>
#include <string>
#include <math.h>

class TeleopJoy
{
public:
    TeleopJoy();

private:
    void joyCallback(const sensor_msgs::Joy::ConstPtr &joy);

    ros::NodeHandle nh_;

    int linear_x_{3}, linear_y_{2}, angular_z_{0};
    double lin_x_slow_{0.1}, lin_y_slow_{0.1}, ang_z_slow_{0.1};
    double lin_x_normal_{0.5}, lin_y_normal_{0.5}, ang_z_normal_{0.5};
    double lin_x_fast_{2.0}, lin_y_fast_{2.0}, ang_z_fast_{2.0};

    ros::Publisher vel_pub_;
    ros::Subscriber joy_sub_;
    ros::Publisher gpad;
};

TeleopJoy::TeleopJoy()
{
    nh_.param("axis_linear_x", linear_x_, linear_x_);
    nh_.param("axis_linear_y", linear_y_, linear_y_);
    nh_.param("axis_angular_z", angular_z_, angular_z_);

    nh_.param("slow_linear_x", lin_x_slow_, lin_x_slow_);
    nh_.param("slow_linear_y", lin_y_slow_, lin_y_slow_);
    nh_.param("slow_angular_z", ang_z_slow_, ang_z_slow_);

    nh_.param("normal_linear_x", lin_x_normal_, lin_x_normal_);
    nh_.param("normal_linear_y", lin_y_normal_, lin_y_normal_);
    nh_.param("normal_angular_z", ang_z_normal_, ang_z_normal_);

    nh_.param("fast_linear_x", lin_x_fast_, lin_x_fast_);
    nh_.param("fast_linear_y", lin_y_fast_, lin_y_fast_);
    nh_.param("fast_angular_z", ang_z_fast_, ang_z_fast_);

    vel_pub_ = nh_.advertise<geometry_msgs::Twist>("/cmd_vel", 1);
    joy_sub_ = nh_.subscribe<sensor_msgs::Joy>("joy", 1, &TeleopJoy::joyCallback, this);
    gpad = nh_.advertise<conveyor_description_pkg::buttons>("gamepad", 1000);
}

void TeleopJoy::joyCallback(const sensor_msgs::Joy::ConstPtr &joy)
{
    geometry_msgs::Twist twist;

    // fast
    twist.linear.x = lin_x_normal_ * joy->axes[linear_x_];
    twist.linear.y = lin_y_normal_ * joy->axes[linear_y_];
    twist.angular.z = ang_z_normal_ * joy->axes[angular_z_];

    float pi = 3.14159265;
    vel_pub_.publish(twist);
    conveyor_description_pkg::buttons message;
    message.angle = atan2(twist.linear.y, twist.linear.x) * 180 / pi;
    message.rb = (joy->buttons[5] == 1);
    gpad.publish(message);
}

int main(int argc, char **argv)
{
    ROS_INFO("Init Node");
    ros::init(argc, argv, "f710_teleop_joy_node");
    TeleopJoy teleop_joy;
    ros::spin();
}
