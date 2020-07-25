#include <yaml-cpp/yaml.h>
#include <iostream>
#include <ros/ros.h>
#include <geometry_msgs/TransformStamped.h>
#include <tf2_ros/static_transform_broadcaster.h>

//link https://github.com/jbeder/yaml-cpp/wiki/Tutorial

int main(int argc, char** argv){
std::cout<<"deneme"<<std::endl;
ros::init(argc,  argv,"tf2publisher");
ros::NodeHandle node;
tf2_ros::StaticTransformBroadcaster fb;
YAML::Node config = YAML::LoadFile("/home/clepz/python_workspace/ros_tf2/static_transforms.yaml");

std::vector<geometry_msgs::TransformStamped> l;

for (YAML::const_iterator i = config.begin(); i != config.end(); i++) {
    geometry_msgs::TransformStamped temp;
    temp.header.stamp = ros::Time::now();
    temp.header.frame_id = i->second["parent_frame"].as<std::string>();
    temp.child_frame_id = i->second["child_frame"].as<std::string>();
    temp.transform.translation.x = i->second["translation"]["x"].as<float>();
    temp.transform.translation.y = i->second["translation"]["y"].as<float>();
    temp.transform.translation.z = i->second["translation"]["z"].as<float>();
    temp.transform.rotation.x = i->second["rotation"]["x"].as<float>();
    temp.transform.rotation.y = i->second["rotation"]["y"].as<float>();
    temp.transform.rotation.z = i->second["rotation"]["z"].as<float>();
    temp.transform.rotation.w = i->second["rotation"]["w"].as<float>();
    l.push_back(temp);
}
fb.sendTransform(l);
ros::spin();

}