#pragma once
#include <pcl/point_types.h>
#include <ros/ros.h>

#include <pcl_conversions/pcl_conversions.h>
#include <pcl_ros/point_cloud.h>
#include <sensor_msgs/PointCloud2.h>

#include <vector>

namespace set_pc_for_planning_node {
class Set_PC_For_Planning {
public:
  Set_PC_For_Planning();
  ~Set_PC_For_Planning();
  void pc_publish();

private:
  ros::NodeHandle nh_;
  // Publisher
  ros::Publisher pub_;

  // Point Cloud for planning
  pcl::PointCloud<pcl::PointXYZRGB> planning_pc;
};
} // namespace set_pc_for_planning_node
