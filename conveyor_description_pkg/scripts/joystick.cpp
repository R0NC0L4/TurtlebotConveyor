// This program publishes randomly-generated velocity
 // messages for turtlesim.
 #include <ros/ros.h>
 #include <std_msgs/Float32.h>  // For geometry_msgs::Twist
 #include <stdlib.h> // For rand() and RAND_MAX
 #include <termios.h>
 #include <conveyor_description_pkg/conveyor_state.h>

 ros::Publisher pub;

   void subCallback(const std_msgs::Float32 msg) {
      conveyor_description_pkg::conveyor_state state;  
      if (msg.data <= 45 && msg.data >= -45) {
         float ang = msg.data+180;

         state.wheel_lr = 0;
         state.wheel_rr = 0;
         state.wheel_lf = 0;
         state.wheel_rf = 0;


         state.joint_lr = ang-45;
         state.joint_rr = ang+45;
         state.joint_lf = ang+45;
         state.joint_rf = ang-45;
         // Publish the message.
         pub.publish(state);  
      }
   }

 int main(int argc, char **argv) {

   // Initialize the ROS system and become a node.
   ros::init(argc, argv, "control_node");
   ros::NodeHandle nh;
   
   // Create a publisher object.
   pub = nh.advertise<conveyor_description_pkg::conveyor_state>("conveyor_state", 1000);

   // Create a subscriber object.
   ros::Subscriber sub = nh.subscribe("angle", 1000, subCallback);

   // Loop at 2Hz until the node is shut down.
   ros::Rate rate(2);

   while(ros::ok()) {  
     // Wait until it's time for another iteration.
     ros::spin();
   }
 }