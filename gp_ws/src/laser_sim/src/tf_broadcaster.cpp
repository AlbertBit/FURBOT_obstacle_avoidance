#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
int main(int argc, char** argv){
    ros::init(argc, argv, "tf_laser_publisher");
    ros::NodeHandle n;
    ros::Rate r(100);
    tf::Transform baseLink;
    tf::Transform rearLidar;
    tf::Transform frontLidar;
    tf::TransformBroadcaster broadcaster;
    //rear laser
    tf::Quaternion q_rear;
    q_rear.setEuler(0.1, 0.1, -1.57);
    q_rear.normalize();
    //front laser
    tf::Quaternion q_front;
    q_front.setEuler(-0.1,0.1, -1.57);
    q_front.normalize();

    tf::Vector3 base_pos(1, 0, 0);
    tf::Vector3 laser_pos_rear(1, -1, 2);
    tf::Vector3 laser_pos_front(-3, -1, 2);
    while(n.ok()){

        baseLink.setOrigin(base_pos);

        rearLidar.setRotation(q_rear);
        rearLidar.setOrigin(laser_pos_rear);

        frontLidar.setRotation(q_front);
        frontLidar.setOrigin(laser_pos_front);

        broadcaster.sendTransform(
            tf::StampedTransform(baseLink, ros::Time::now(), "world", "base_link"));

        broadcaster.sendTransform(
            tf::StampedTransform(rearLidar, ros::Time::now(), "base_link", "laser_front"));

        broadcaster.sendTransform(
            tf::StampedTransform(frontLidar, ros::Time::now(), "base_link", "laser_rear"));

        r.sleep();
    }
}
