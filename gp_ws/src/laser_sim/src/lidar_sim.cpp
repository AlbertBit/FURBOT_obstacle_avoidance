#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>


int main(int argc, char** argv){

    ros::init(argc, argv, "laser_scan_publisher");
    ros::NodeHandle n_front;
    ros::Publisher scan_pub_front = n_front.advertise<sensor_msgs::LaserScan>("base_scan_front", 50);

    ros::NodeHandle n_rear;
    ros::Publisher scan_pub_rear = n_rear.advertise<sensor_msgs::LaserScan>("base_scan_rear", 50);


    unsigned int num_readings = 100;
    double laser_frequency = 40;
    double ranges[num_readings];
    double intensities[num_readings];
    int count = 0;
    ros::Rate r(1.0);
    while(n_front.ok() && n_rear.ok()){


        //generate some fake data for our laser scan
        for(unsigned int i = 0; i < num_readings; ++i){
            ranges[i] = count;
            intensities[i] = 100 + count;
        }
        ros::Time scan_time = ros::Time::now();
        //populate the LaserScan message
        sensor_msgs::LaserScan scanFrontMsg;
        scanFrontMsg.header.stamp = scan_time;
        scanFrontMsg.header.frame_id = "laser_front";
        scanFrontMsg.angle_min = -1.57;
        scanFrontMsg.angle_max = 1.57;
        scanFrontMsg.angle_increment = 3.14 / num_readings;
        scanFrontMsg.time_increment = (1 / laser_frequency) / (num_readings);
        scanFrontMsg.range_min = 0.0;
        scanFrontMsg.range_max = 10.0;
        scanFrontMsg.ranges.resize(num_readings);
        scanFrontMsg.intensities.resize(num_readings);
        for(unsigned int i = 0; i < num_readings; ++i){
            scanFrontMsg.ranges[i] = ranges[i];
            scanFrontMsg.intensities[i] = intensities[i]/2;
        }
        scan_pub_front.publish(scanFrontMsg);


        sensor_msgs::LaserScan scanRearMsg;
        scanRearMsg.header.stamp = scan_time;
        scanRearMsg.header.frame_id = "laser_rear";
        scanRearMsg.angle_min = -1.57;
        scanRearMsg.angle_max = 1.57;
        scanRearMsg.angle_increment = 3.14 / num_readings;
        scanRearMsg.time_increment = (1 / laser_frequency) / (num_readings);
        scanRearMsg.range_min = 0.0;
        scanRearMsg.range_max = 10.0;
        scanRearMsg.ranges.resize(num_readings);
        scanRearMsg.intensities.resize(num_readings);
        for(unsigned int i = 0; i < num_readings; ++i){
            scanRearMsg.ranges[i] = ranges[i];
            scanRearMsg.intensities[i] = intensities[i];
        }
        scan_pub_rear.publish(scanRearMsg);


        ++count;
        if( count > scanFrontMsg.range_max) {
            count = 0;
        }

        r.sleep();
    }
}
