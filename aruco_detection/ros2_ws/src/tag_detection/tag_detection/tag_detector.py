import rclpy
from rclpy.node import Node

from tag_interface.msg import Tag as Tag_msg
from tag_interface.msg import Coordinate

from .aruco_detector import *


PATH_TO_DATA = 'src/tag_detection/tag_detection'
DATA_NAME = 'logitech_webcam_data.npz'

class TagDetector(Node):
    
    def __init__(self):
        # ROS2 NODE 
        # Tune timer until tag detection does not lag behind camera
        super().__init__('tag_detector')

        self.publisher_ = self.create_publisher(Tag_msg, 'autonomy/tag_data', 10)
        # timer_period = 0.01  # seconds
        timer_period = 0.1
        self.timer = self.create_timer(timer_period, self.timer_callback)
        self.detector = Aruco_Detector(DATA_NAME, PATH_TO_DATA)       

    def timer_callback(self):
        tag_msg = Tag_msg()
        tags, tag_msg.img_length = self.detector.detect_tags() 

        for tag in tags:
            coords = [Coordinate() for x in range(4)]
            
            for coord, tag_coord in zip(coords, tag[1:5]):
                coord.row, coord.col = tuple([int(x) for x in tag_coord])
            
            tag_msg.id.append(tag[0])
            tag_msg.top_right.append(coords[0])
            tag_msg.top_left.append(coords[1])
            tag_msg.bottom_right.append(coords[2])
            tag_msg.bottom_left.append(coords[3])
            tag_msg.position.append(tag[5])
            tag_msg.distance.append(tag[6])
            

        self.get_logger().info(f"tags found: {len(tags)}")
        self.publisher_.publish(tag_msg)



def main(args=None):
    rclpy.init(args=args)

    tag_detector = TagDetector()

    rclpy.spin(tag_detector)

    # Destroy the node emplicitly, otherwise garbage collected
    tag_detector.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()



