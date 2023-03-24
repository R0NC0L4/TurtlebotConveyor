 #include <ros/ros.h>
 #include <std_msgs/Float64.h>  
 #include <stdlib.h> 
 #include <termios.h>
 #include <conveyor_description_pkg/conveyor_state.h>

 int getch()
{
  static struct termios oldt, newt;
  tcgetattr( STDIN_FILENO, &oldt);           // save old settings
  newt = oldt;
  newt.c_lflag &= ~(ICANON);                 // disable buffering      
  tcsetattr( STDIN_FILENO, TCSANOW, &newt);  // apply new settings

  int c = getchar();  // read character (non-blocking)

  tcsetattr( STDIN_FILENO, TCSANOW, &oldt);  // restore old settings
  return c;
}

 int main(int argc, char **argv) {
   // Initialize the ROS system and become a node.
   ros::init(argc, argv, "control_node");
   ros::NodeHandle nh;
   
   // Create a publisher object.
   ros::Publisher pub = nh.advertise<conveyor_description_pkg::conveyor_state>("conveyor_state", 1000);

   // Loop at 2Hz until the node is shut down.
   ros::Rate rate(2);

   float const_vel = 50;
   float current_vel = 0;
   float current_pos1 = 180;
   float current_pos2 = 180;

   int profile = 0;

   ROS_INFO_STREAM("Commands:");
   ROS_INFO_STREAM("- a: configuration forward/backward");
   ROS_INFO_STREAM("- s: configuration rightward/leftward");
   ROS_INFO_STREAM("- d: rotation");
   ROS_INFO_STREAM("- w: forward/rightward");
   ROS_INFO_STREAM("- q: backward/leftward");
   ROS_INFO_STREAM("- e: stop");
   while(ros::ok()) {  

      conveyor_description_pkg::conveyor_state state;  

     int c = getch();   // call your non-blocking input function
     if (c == 'a' ) {
        profile = 1;
        current_pos1 = 135;
        current_pos2 = 225;
     }
     else if (c == 's' ) { 
        profile = 2;
        current_pos1 = 225;
        current_pos2 = 135;
     }
     else if (c == 'd' ) { 
        profile = 3;
        current_pos1 = 180;
        current_pos2 = 180;
     }
     else if (c =='w'){
        current_vel = const_vel;
     }
     else if (c =='q'){
        current_vel = -const_vel;
     }
     else if (c == 'e') {
        current_vel = 0.0;
     }

      if (profile == 1 && (c == 'w' || c == 'q')) {
         state.wheel_lr = -current_vel;
         state.wheel_rr = current_vel;
         state.wheel_lf = -current_vel;
         state.wheel_rf = current_vel;
      }
      if (profile == 2 && (c == 'w' || c == 'q')) {
         state.wheel_lr = current_vel;
         state.wheel_rr = current_vel;
         state.wheel_lf = -current_vel;
         state.wheel_rf = -current_vel;
      }
      if (profile == 3 && (c == 'w' || c == 'q')) {
         state.wheel_lr = current_vel;
         state.wheel_rr = current_vel;
         state.wheel_lf = current_vel;
         state.wheel_rf = current_vel;
      }
      state.joint_lr = current_pos1;
      state.joint_rr = current_pos2;
      state.joint_lf = current_pos2;
      state.joint_rf = current_pos1;
      // Publish the message.
      pub.publish(state);   

     // Wait until it's time for another iteration.
     rate.sleep();
   }
 }