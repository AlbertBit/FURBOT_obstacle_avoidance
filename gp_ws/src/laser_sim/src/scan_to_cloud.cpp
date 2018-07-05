#include <ros/ros.h>
#include <iostream>
#include <sensor_msgs/PointCloud.h>
#include <sensor_msgs/LaserScan.h>
#include <laser_geometry/laser_geometry.h>

using namespace std;

bool frontLaserMsgReceived = false;
bool rearLaserMsgReceived = false;
sensor_msgs::PointCloud cloud_front;
sensor_msgs::PointCloud cloud_rear;

void scanCallback (const sensor_msgs::LaserScan::ConstPtr& scan_in) {

	laser_geometry::LaserProjection projector_;
	if(scan_in->header.frame_id == "laser_front") {
		projector_.projectLaser(*scan_in, cloud_front);
		frontLaserMsgReceived = true;
		cout << "front laser message received" << endl;
	}
	else if (scan_in->header.frame_id == "laser_rear"){
		projector_.projectLaser(*scan_in, cloud_rear);
		rearLaserMsgReceived = true;
		cout << "rear laser message received" << endl;
	}



}


int main(int argc, char** argv){

  ros::init(argc, argv, "laserToCloud");
  ros::NodeHandle n;

  ros::Rate r(5.0);

  ros::Subscriber sub_front = n.subscribe("/base_scan_front", 1000, scanCallback);
	ros::Subscriber sub_rear = n.subscribe("/base_scan_rear", 1000, scanCallback);
  ros::Publisher pub_front =  n.advertise<sensor_msgs::PointCloud>("laser_cloud_front", 1);
	ros::Publisher pub_rear =  n.advertise<sensor_msgs::PointCloud>("laser_cloud_rear", 1);

  while(n.ok()){

	if(frontLaserMsgReceived) {
		pub_front.publish(cloud_front);
		frontLaserMsgReceived = false;
	}

	if(rearLaserMsgReceived) {
		pub_rear.publish(cloud_rear);
		rearLaserMsgReceived = false;
	}

	ros::spinOnce();
    r.sleep();
  }
}
