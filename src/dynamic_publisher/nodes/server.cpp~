#include <ros/ros.h>

#include <dynamic_reconfigure/server.h>
#include <dynamic_publisher/spk_gainwbexpConfig.h>
#include <tusimple_driver_msgs/ImageExposure.h>



tusimple_driver_msgs::ImageExposure imgexp;
bool changeflag;
void callback(dynamic_publisher::spk_gainwbexpConfig &config, uint32_t level) {
imgexp.camera_number = config.camera_number;
imgexp.exposure_auto = config.exposure_auto;
imgexp.exposure_time = config.exposure_time;
imgexp.gain_auto = config.gain_auto;
imgexp.gain = config.gain;
imgexp.white_balance_auto = config.white_balance_auto;
imgexp.white_balance_blue = config.white_balance_blue;
imgexp.white_balance_red = config.white_balance_red;
changeflag = true;
}

int main(int argc, char **argv) {
  ros::init(argc, argv, "dynamic_publisher");
  ros::NodeHandle n;
  dynamic_reconfigure::Server<dynamic_publisher::spk_gainwbexpConfig> server;
  dynamic_reconfigure::Server<dynamic_publisher::spk_gainwbexpConfig>::CallbackType f;

  f = boost::bind(&callback, _1, _2);
  server.setCallback(f);
  ros::Publisher chatter_pub = n.advertise<tusimple_driver_msgs::ImageExposure>("/GainWBExp_sequence", 1000);
  ros::Rate loop_rate(10);

  while ( ros::ok())
  {
    if(changeflag) 
    {
      chatter_pub.publish(imgexp);
      changeflag = false;
    }
    ros::spinOnce();

    loop_rate.sleep();
  }
  return 0;
}
