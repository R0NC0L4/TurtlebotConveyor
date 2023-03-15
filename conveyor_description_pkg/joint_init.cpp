// This program publishes randomly-generated velocity
 // messages for turtlesim.
 #include <ros/ros.h>
 #include <std_msgs/Float64.h>  // For geometry_msgs::Twist
 #include <stdlib.h> // For rand() and RAND_MAX
 #include <conveyor_description_pkg/conveyor_state.h>

 int main(int argc, char **argv) {
   // Initialize the ROS system and become a node.
   ros::init(argc, argv, "control_node");
   ros::NodeHandle nh;

   // Create a publisher object.
   ros::Publisher pub = nh.advertise<conveyor_description_pkg::conveyor_state>("conveyor_state", 1000);

   // Loop at 2Hz until the node is shut down.
   ros::Rate rate(2);

   while(ros::ok()) {
     // Create and fill in the message.  The other four
     // fields, which are ignored by turtlesim, default to 0.
     conveyor_description_pkg::conveyor_state state;   

     state.wheel_lr = 0.0;
     state.wheel_rr = 0.0;
     state.wheel_lf = 0.0;
     state.wheel_rf = 0.0;

     state.joint_lr = 180.0;
     state.joint_rr = 180.0;
     state.joint_lf = 180.0;
     state.joint_rf = 180.0;

     pub.publish(state);

     // Wait until it's time for another iteration.
     rate.sleep();
   }
 }