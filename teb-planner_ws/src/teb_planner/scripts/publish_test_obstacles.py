#!/usr/bin/env python

# Author: christoph.roesmann@tu-dortmund.de

import rospy, math
from costmap_converter.msg import ObstacleArrayMsg, ObstacleMsg
from geometry_msgs.msg import PolygonStamped, Point32


def publish_obstacle_msg():

  rospy.init_node("test_obstacle_msg")
  pub_0 = rospy.Publisher('/obstacle_0', PolygonStamped, queue_size=1)
  pub_1 = rospy.Publisher('/obstacle_1', PolygonStamped, queue_size=1)
  pub_pallet = rospy.Publisher('/pallet', PolygonStamped, queue_size=1)

  obstacle_0 = PolygonStamped()
  obstacle_0.header.stamp = rospy.Time.now()
  obstacle_0.header.frame_id = "map" # CHANGE HERE: odom/map

  obstacle_1 = PolygonStamped()
  obstacle_1.header.stamp = rospy.Time.now()
  obstacle_1.header.frame_id = "map" # CHANGE HERE: odom/map

  pallet = PolygonStamped()
  pallet.header.stamp = rospy.Time.now()
  pallet.header.frame_id = "map" # CHANGE HERE: odom/map

  v1 = Point32()
  v1.x = 4.875
  v1.y = 4.3
  v2 = Point32()
  v2.x = 4.875
  v2.y = 3.7
  v3 = Point32()
  v3.x = 5.125
  v3.y = 3.7
  v4 = Point32()
  v4.x = 5.125
  v4.y = 4.3
  obstacle_0.polygon.points = [v1, v2, v3, v4]


  v5 = Point32()
  v5.x = 4.875
  v5.y = 6.3
  v6 = Point32()
  v6.x = 4.875
  v6.y = 5.7
  v7 = Point32()
  v7.x = 5.125
  v7.y = 5.7
  v8 = Point32()
  v8.x = 5.125
  v8.y = 6.3
  obstacle_1.polygon.points = [v5, v6, v7, v8]


  p1 = Point32()
  p1.x = 5.51
  p1.y = 5.15
  p2 = Point32()
  p2.x = 5.69
  p2.y = 5.15
  p3 = Point32()
  p3.x = 5.69
  p3.y = 4.85
  p4 = Point32()
  p4.x = 5.51
  p4.y = 4.85
  pallet.polygon.points = [p1, p2, p3, p4]




  r = rospy.Rate(10) # 10hz

  while not rospy.is_shutdown():

    pub_0.publish(obstacle_0)
    pub_1.publish(obstacle_1)
    pub_pallet.publish(pallet)

    r.sleep()



if __name__ == '__main__':
  try:
    publish_obstacle_msg()
  except rospy.ROSInterruptException:
    pass
