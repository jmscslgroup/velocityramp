#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "velocityramp";

// For Block velocityramp/Subscribe
SimulinkSubscriber<geometry_msgs::Twist, SL_Bus_velocityramp_geometry_msgs_Twist> Sub_velocityramp_10;

// For Block velocityramp/Publish
SimulinkPublisher<geometry_msgs::Twist, SL_Bus_velocityramp_geometry_msgs_Twist> Pub_velocityramp_3;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

