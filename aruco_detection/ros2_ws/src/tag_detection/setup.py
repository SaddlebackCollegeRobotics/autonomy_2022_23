import os
from glob import glob
from setuptools import setup

package_name = 'tag_detection'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        (os.path.join('share', package_name), glob('launch/*launch.[pyx][yma]*'))  # addef for launch file
    ],
    install_requires=['setuptools', 'rclpy'],
    zip_safe=True,
    maintainer='cam',
    maintainer_email='camwolff@email.com',
    description='TODO: Package description',
    license='Apache-2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'detect_tag = tag_detection.tag_detector:main',
            'subscribe_tag = tag_detection.tag_subscriber:main',
            'move_to_tag = tag_detection.move_to_tag:main',
            'dummy_driver = tag_detection.dummy_driver:main',
            'dummy_camera = tag_detection.dummy_camera:main',
            'tag_visualizer = tag_detection.tag_visualizer:main'
        ],
    },
)
