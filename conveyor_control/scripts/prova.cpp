// This program publishes randomly-generated velocity
 // messages for turtlesim.
 #include <ros/ros.h>
 #include <std_msgs/Float64.h>  // For geometry_msgs::Twist
 #include <stdlib.h> // For rand() and RAND_MAX

 int main(int argc, char **argv) {
   // Initialize the ROS system and become a node.
   ros::init(argc, argv, "prova");
   ros::NodeHandle nh;

   // Create a publisher object.
   ros::Publisher pub_fr = nh.advertise<std_msgs::Float64>("conveyor/servo_front_right_position_controller/command", 1000);
   ros::Publisher pub_fl = nh.advertise<std_msgs::Float64>("conveyor/servo_front_left_position_controller/command", 1000);
   ros::Publisher pub_br = nh.advertise<std_msgs::Float64>("conveyor/servo_back_right_position_controller/command", 1000);
   ros::Publisher pub_bl = nh.advertise<std_msgs::Float64>("conveyor/servo_back_left_position_controller/command", 1000);
   // Loop at 2Hz until the node is shut down.
   ros::Rate rate(2);
   while(ros::ok()) {
     // Create and fill in the message.  The other four
     // fields, which are ignored by turtlesim, default to 0.
     std_msgs::Float64 msg_fr;
     std_msgs::Float64 msg_fl;
     std_msgs::Float64 msg_br;
     std_msgs::Float64 msg_bl;

     msg_fr.data = 0.785;
     msg_fl.data = -0.785;
     msg_br.data = -0.785;
     msg_bl.data = 0.785;

     // Publish the message.
     pub_fr.publish(msg_fr);
     pub_fl.publish(msg_fl);
     pub_br.publish(msg_br);
     pub_bl.publish(msg_bl);

     // Send a message to rosout with the details.
     ROS_INFO_STREAM("Sending random velocity command:"
       << " front right=" << msg_fr
       << " front left=" << msg_fl
       << " back right=" << msg_br
       << " back left=" << msg_bl);

     // Wait until it's time for another iteration.
     rate.sleep();
   }
 }