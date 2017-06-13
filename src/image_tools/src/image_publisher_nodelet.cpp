#include "ros/ros.h"
#include "nodelet/nodelet.h"

#include <image_transport/image_transport.h>
#include <opencv2/highgui/highgui.hpp>
#include <cv_bridge/cv_bridge.h>

#include <sensor_msgs/CameraInfo.h>

//dynamic reconfiguration
//#include <image_tools/TutorialsConfig.h>
#include <pluginlib/class_list_macros.h>

namespace example_pkg
{

  class nodelet_class : public nodelet::Nodelet
  {
  public:
  nodelet_class(){}

  private:
  virtual void onInit(){
  nh = getNodeHandle();
  private_nh = getPrivateNodeHandle();

  // important !! use timer to keep trigger 
  timer_ = nh.createTimer(ros::Duration(0.1), boost::bind(& nodelet_class::timerCb, this, _1));
  
  //sub_ = nh.subscribe("incoming_chatter", 10, boost::bind(& @(NodeletClass)::messageCb, this, _1));
  image_transport::ImageTransport it(nh);
  pub = it.advertise("camera/image_raw", 1);
  cv::Mat image = cv::imread("/home/haunyanc/Downloads/testChart_1.tif", CV_LOAD_IMAGE_UNCHANGED);
  msg = cv_bridge::CvImage(std_msgs::Header(), "bayer_rggb8", image).toImageMsg();

  info_pub = nh.advertise<sensor_msgs::CameraInfo>("camera/camera_info", 5);
  c_info.height = msg->height;
  c_info.width = msg->width;

  };

  void timerCb(const ros::TimerEvent& event){
  // Using timers is the preferred 'ROS way' to manual threading
  NODELET_INFO_STREAM("The time is now " << event.current_real);
  ROS_INFO("UPUP\n");
    pub.publish(msg);
    info_pub.publish(c_info);
  }

  /* must use a ConstPtr callback to use zero-copy transport
  void messageCb(const std_msgs::StringConstPtr message){

  // can republish the old message no problem, since we're not modifying it
  pub_.publish(message);

  std_msgs::String new_message;
  new_message.data = message.data + " fizz buzz";
  pub_.publish(new_message);

  // we can't modify any messages after they've been published, unless we want our subscribers to get VERY confused
  // new_message.data = "can't do this!";
   }*/

  //ros::Subscriber sub_;
  //ros::Publisher pub_;
  ros::Timer timer_;
  ros::NodeHandle nh;
  ros::NodeHandle private_nh;
  image_transport::Publisher pub;
  ros::Publisher info_pub;
  sensor_msgs::ImagePtr msg;
  sensor_msgs::CameraInfo c_info;
  double value_;
  };
 // namespace @(namespace)
//PLUGINLIB_DECLARE_CLASS(@(package), @(NodeletClass), @(namespace)::@(NamespaceClass), nodelet::Nodelet);
PLUGINLIB_DECLARE_CLASS(example_pkg, nodelet_class, example_pkg::nodelet_class, nodelet::Nodelet);
//PLUGINLIB_EXPORT_CLASS(image_tools::nodelet_class, nodelet::Nodelet)
}