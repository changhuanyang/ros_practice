cmake_minimum_required(VERSION 2.8.3)
project(tusimple_driver_msgs)

find_package(catkin REQUIRED COMPONENTS
  statistics_msgs
  std_msgs
  sensor_msgs
  message_generation
)

add_message_files(FILES
  StereoImage.msg
  ImageExposure.msg
  USBCanData.msg
  GPSIMUData.msg
  ImageRoi.msg
  CameraTrigger.msg
)

generate_messages(DEPENDENCIES
  std_msgs
  sensor_msgs
  statistics_msgs
)

catkin_package(
  CATKIN_DEPENDS statistics_msgs std_msgs sensor_msgs
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)
