#!/usr/bin/env python

# Author: christoph.roesmann@tu-dortmund.de

import rospy, math, os
from costmap_converter.msg import ObstacleArrayMsg, ObstacleMsg
from geometry_msgs.msg import PolygonStamped, Point32


def publish_obstacle_msg():
    rospy.init_node("test_obstacle_msg")

    obstacle_list = []; #list of obstacles
    pub_list = []; #list of publishers
    topic_list = []; #for debugging


    file = open(os.path.join(os.path.dirname(__file__),'./files','obstacles.txt'), 'r');

    for line in file:
        #extract line from file
        obstacle_msg = line.strip('\n').split(',')

        #prepare the publisher for a certain polygon topic
        topic = obstacle_msg[0]
        topic_list.append(topic)
        pub = rospy.Publisher('/'+topic, PolygonStamped, queue_size=1)

        point_list = [];

        for i in range(1, len(obstacle_msg)):
            point_i = Point32();
            point_i.x = float(obstacle_msg[i].strip().split(' ')[0])
            point_i.y = float(obstacle_msg[i].strip().split(' ')[1])
            point_list.append(point_i)

        obstacle = PolygonStamped()
        obstacle.header.stamp = rospy.Time.now()
        obstacle.header.frame_id = "map" # CHANGE HERE: odom/map
        obstacle.polygon.points = point_list

        obstacle_list.append(obstacle)
        pub_list.append(pub)



    file.close();

    r = rospy.Rate(10) # 10hz

    while not rospy.is_shutdown():

        for i in range(0, len(obstacle_list)):
            pub_list[i].publish(obstacle_list[i])
            print(topic_list[i])
            print(obstacle_list[i])

        r.sleep()

if __name__ == '__main__':
    try:
        publish_obstacle_msg()
    except rospy.ROSInterruptException:
        pass
