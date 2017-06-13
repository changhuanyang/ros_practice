#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <opencv2/highgui/highgui.hpp>
#include <cv_bridge/cv_bridge.h>

#include <sensor_msgs/CameraInfo.h>

int main(int argc, char** argv)
{
  ros::init(argc, argv, "image_publisher");
  ros::NodeHandle nh;
  image_transport::ImageTransport it(nh);
  image_transport::Publisher pub = it.advertise("camera/image_raw", 1);
  
  cv::Mat image = cv::imread(argv[1], CV_LOAD_IMAGE_UNCHANGED);
  cv::waitKey(10);
  sensor_msgs::ImagePtr msg = cv_bridge::CvImage(std_msgs::Header(), "bayer_rggb8", image).toImageMsg();

  //for image_info
  ros::NodeHandle nh2;
  ros::Publisher info_pub = nh2.advertise<sensor_msgs::CameraInfo>("camera/camera_info", 5);
  sensor_msgs::CameraInfo c_info;
  c_info.height = msg->height;
  c_info.width = msg->width;

  ros::Rate loop_rate(5);
  while (nh.ok()) {
    pub.publish(msg);
    info_pub.publish(c_info);
    ros::spinOnce();
    loop_rate.sleep();
  }
}