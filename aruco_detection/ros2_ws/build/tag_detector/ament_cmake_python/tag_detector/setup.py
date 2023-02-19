from setuptools import find_packages
from setuptools import setup

setup(
    name='tag_detector',
    version='0.0.0',
    packages=find_packages(
        include=('tag_detector', 'tag_detector.*')),
)
