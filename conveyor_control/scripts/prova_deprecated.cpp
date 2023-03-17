// This program makes conveyor move by using position controllers
// DEPRECATED SCRIPT
 #include <ros/ros.h>
 #include <std_msgs/Float64.h>  // For geometry_msgs::Twist
 #include <stdlib.h> // For rand() and RAND_MAX
 #include <termios.h>

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
   ros::init(argc, argv, "prova");
   ros::NodeHandle nh;

   // Create a publisher object.
   ros::Publisher pub_fr = nh.advertise<std_msgs::Float64>("conveyor/servo_front_right_position_controller/command", 1000);
   ros::Publisher pub_fl = nh.advertise<std_msgs::Float64>("conveyor/servo_front_left_position_controller/command", 1000);
   ros::Publisher pub_br = nh.advertise<std_msgs::Float64>("conveyor/servo_back_right_position_controller/command", 1000);
   ros::Publisher pub_bl = nh.advertise<std_msgs::Float64>("conveyor/servo_back_left_position_controller/command", 1000);
   
   ros::Publisher pub_fr_w = nh.advertise<std_msgs::Float64>("conveyor/front_right_wheel_position_controller/command", 1000);
   ros::Publisher pub_fl_w = nh.advertise<std_msgs::Float64>("conveyor/front_left_wheel_position_controller/command", 1000);
   ros::Publisher pub_br_w = nh.advertise<std_msgs::Float64>("conveyor/back_right_wheel_position_controller/command", 1000);
   ros::Publisher pub_bl_w = nh.advertise<std_msgs::Float64>("conveyor/back_left_wheel_position_controller/command", 1000);

   float a = 0;
   float b = 0;
   char conf = ' ';

   // Loop at 2Hz until the node is shut down.
   ros::Rate rate(2);

   ROS_INFO_STREAM("Commands:");
   ROS_INFO_STREAM("- a: configuration forward/backward");
   ROS_INFO_STREAM("- s: configuration rightward/leftward");
   ROS_INFO_STREAM("- w: forward/rightward");
   ROS_INFO_STREAM("- q: backward/leftward");
   while(ros::ok()) {
     // Create and fill in the message.  The other four
     // fields, which are ignored by turtlesim, default to 0.
     std_msgs::Float64 msg_fr;
     std_msgs::Float64 msg_fl;
     std_msgs::Float64 msg_br;
     std_msgs::Float64 msg_bl;

     std_msgs::Float64 msg_fr_w;
     std_msgs::Float64 msg_fl_w;
     std_msgs::Float64 msg_br_w;
     std_msgs::Float64 msg_bl_w;     

     int c = getch();   // call your non-blocking input function
     if (c == 'a' ) { 
        conf = 'a';

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
        ROS_INFO_STREAM("Command:"
          << " front right=" << msg_fr
          << " front left=" << msg_fl
          << " back right=" << msg_br
          << " back left=" << msg_bl);
          
     }
     else if (c == 's' ) { 
        conf = 's';

        msg_fr.data = -0.785;
        msg_fl.data = 0.785;
        msg_br.data = 0.785;
        msg_bl.data = -0.785;

        // Publish the message.
        pub_fr.publish(msg_fr);
        pub_fl.publish(msg_fl);
        pub_br.publish(msg_br);
        pub_bl.publish(msg_bl);

        // Send a message to rosout with the details.
        ROS_INFO_STREAM("Command:"
          << " front right=" << msg_fr
          << " front left=" << msg_fl
          << " back right=" << msg_br
          << " back left=" << msg_bl);
          
     }
     else if (c =='w'){
        if (conf == 'a') {
          a=a+1;
          b=b+1;
          msg_fr_w.data = a;
          msg_fl_w.data = b;
          msg_br_w.data = b;
          msg_bl_w.data = a;
          pub_fr_w.publish(msg_fr_w);
          pub_fl_w.publish(msg_fl_w);
          pub_br_w.publish(msg_br_w);
          pub_bl_w.publish(msg_bl_w);
          ROS_INFO_STREAM("Moving forward");
        }
        else if (conf == 's') {
          a=a+1;
          b=b-1;
          msg_fr_w.data = a;
          msg_fl_w.data = b;
          msg_br_w.data = b;
          msg_bl_w.data = a;
          pub_fr_w.publish(msg_fr_w);
          pub_fl_w.publish(msg_fl_w);
          pub_br_w.publish(msg_br_w);
          pub_bl_w.publish(msg_bl_w);
          ROS_INFO_STREAM("Moving rightward");
        }
     }
     else if (c =='q'){
        if (conf == 'a') {
          a=a-1;
          b=b-1;
          msg_fr_w.data = a;
          msg_fl_w.data = b;
          msg_br_w.data = b;
          msg_bl_w.data = a;
          pub_fr_w.publish(msg_fr_w);
          pub_fl_w.publish(msg_fl_w);
          pub_br_w.publish(msg_br_w);
          pub_bl_w.publish(msg_bl_w);
          ROS_INFO_STREAM("Moving backward");
        }
        else if (conf == 's') {
          a=a-1;
          b=b+1;
          msg_fr_w.data = a;
          msg_fl_w.data = b;
          msg_br_w.data = b;
          msg_bl_w.data = a;
          pub_fr_w.publish(msg_fr_w);
          pub_fl_w.publish(msg_fl_w);
          pub_br_w.publish(msg_br_w);
          pub_bl_w.publish(msg_bl_w);
          ROS_INFO_STREAM("Moving leftward");
        }
     }

     // Wait until it's time for another iteration.
     rate.sleep();
   }
 }