#include <set_pc_for_planning/set_pc_for_planning.h>

#define grid_size 0.03

namespace set_pc_for_planning_node {
Set_PC_For_Planning::Set_PC_For_Planning() {

  // Fill in the planning_pc data
  planning_pc.width = 50;
  planning_pc.height = 100;
  planning_pc.is_dense = true;
  planning_pc.points.resize(planning_pc.width * planning_pc.height);
  planning_pc.header.frame_id = "tf_for_planning";

  // std::vector<double> grid_start = {0, -grid_size * planning_pc.width / 2};

  // for (size_t i = 0; i < planning_pc.height; i++) {
  //   for (size_t j = 0; j < planning_pc.width; j++) {
  //     int index = j + i * planning_pc.width;
  //     planning_pc.points[index].x = grid_start[0] + grid_size * i;
  //     planning_pc.points[index].y = grid_start[1] + grid_size * j;
  //     planning_pc.points[index].z = 0;
  //     planning_pc.points[index].a = 1;
  //     planning_pc.points[index].r = 200;
  //     planning_pc.points[index].g = 0;
  //     planning_pc.points[index].b = 0;
  //   }
  // }

  std::vector<double> grid_start = {-grid_size * planning_pc.width / 2, 0};

  for (size_t i = 0; i < planning_pc.height; i++) {
    for (size_t j = 0; j < planning_pc.width; j++) {
      int index = j + i * planning_pc.width;
      planning_pc.points[index].x = grid_start[0] + grid_size * j;
      planning_pc.points[index].y = grid_start[1] + grid_size * i;
      planning_pc.points[index].z = 0;
      planning_pc.points[index].a = 1;
      planning_pc.points[index].r = 200;
      planning_pc.points[index].g = 0;
      planning_pc.points[index].b = 0;
    }
  }

  // pcl_conversions::toPCL(ros::Time::now(), planning_pc.header.stamp);

  //   pcl::io::savePCDFileASCII("test_pcd.pcd", cloud);
  //   std::cerr << "Saved " << cloud.points.size()
  //             << " data points to test_pcd.pcd." << std::endl;

  pub_ = nh_.advertise<sensor_msgs::PointCloud2>(
      "/set_pc_for_planning_node/pc_for_planning", 10);
}
Set_PC_For_Planning::~Set_PC_For_Planning() {}

void Set_PC_For_Planning::pc_publish() { pub_.publish(planning_pc); }
} // namespace set_pc_for_planning_node