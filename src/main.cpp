#include <ros/ros.h>
#include <set_pc_for_planning/set_pc_for_planning.h>

// Main Loop
int main(int argc, char **argv) {
  ros::init(argc, argv, "set_pc_for_planning_node");
  ROS_INFO("start");
  set_pc_for_planning_node::Set_PC_For_Planning set_pc;
  ROS_INFO("start");
  ros::Rate loop_rate(10);
  while (ros::ok()) {
    ros::spinOnce();
    set_pc.pc_publish();
    loop_rate.sleep();
    // ROS_INFO("loop");
  }
  return 0;
}
