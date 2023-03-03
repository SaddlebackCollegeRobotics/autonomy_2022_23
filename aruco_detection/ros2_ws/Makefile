all:
	colcon build --symlink-install

detection:
	colcon build --symlink-install --packages-select tag_detetion

interface:
	colcon build --packages-select tag_interface

clean:
	rm -rf build install log

camera:
	ros2 run tag_detection dummy_camera

detector:
	ros2 run tag_detection detect_tag

autonomy: 
	ros2 run tag_detection move_to_tag

drive:
	ros2 run tag_detection dummy_driver

visualize:
	ros2 run tag_detection tag_visualizer

copy:
	scp -r /home/jasper/dev/autonomy_2022_23/aruco_detection/ros2_ws / ubuntu@nyx.local:/home/ubuntu/autonomy_2022_23/aruco_detection