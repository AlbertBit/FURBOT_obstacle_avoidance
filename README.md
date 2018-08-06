# FURBOT_obstacle_avoidance

** 0) go into teb-planner_ws and compile everything
catkin_make *

open a terminal for each step

** 1) open stage ros simulator with the car like robot in the world **
roslaunch teb_planner robot_carlike_in_stage.launch

** 2) launch laser scan merger **
roslaunch ira_laser_tools laserscan_multi_merger.launch

** 3) rviz to visualize costmaps **
rosrun rviz rviz

** 4) publish a goal position for the planner like **
rostopic pub /move_base_simple/goal geometry_msgs/PoseStamped '{header: {stamp: now, frame_id: "map"}, pose: {position: {x: 5.0, y: 4.8, z: 0.0}, orientation: {x: 0.0, y: 0.0, z: 0.707, w: 0.707}}}'

** 5) run the obstacle files to see the obstacle in rviz (OPTIONAL)**
rosrun teb_planner publish_test_obstacles.py
