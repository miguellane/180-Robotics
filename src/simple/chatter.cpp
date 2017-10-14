#include <ros/ros.h>
#include <std_msgs/String.h>
#include <std_msgs/Int32.h>

int main(int argc, char **argv){
  ros::init(argc, argv, "chatter");
  ros::NodeHandle nh;
  int i = 0;

  ros::Publisher pub1 = nh.advertise
    <std_msgs::Int32>("integers", 1000);
  ros::Publisher pub2 = nh.advertise
    <std_msgs::String>("strings", 1000);

  ros::Rate rate(1);
  while (ros::ok()){
    std_msgs::String str;
    std_msgs::Int32 in32;

    str.data = "Miguel";
    in32.data = i++;

    pub1.publish(in32);
    pub2.publish(str);
    rate.sleep();
  }
}


