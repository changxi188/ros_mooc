#include <ros/ros.h>
#include <ros_mooc/Pose.h>
#include <iostream>

using namespace std;
ros::Publisher pub1, pub2, pub3;
ros_mooc::Pose pose1, pose2, pose3;

void MsgInit()
{
    pose1.name = "pose1";
    pose2.name = "pose2";
    pose3.name = "pose3";
}

///*
void PublisherInit(ros::NodeHandle& n)
{
    pub1 = n.advertise<ros_mooc::Pose>("pose1", 1);
    pub2 = n.advertise<ros_mooc::Pose>("pose2", 1);
    pub3 = n.advertise<ros_mooc::Pose>("pose3", 1);
}
//*/

int main(int argc, char** argv)
{
    // 注册节点
    ros::init(argc, argv, "ros_mooc_pub");
    ros::NodeHandle n;

    // message initialization
    MsgInit();
    std::cout << pose1.name << std::endl;

    // publisher initialization
    // PublisherInit(n);
    pub1 = n.advertise<ros_mooc::Pose>("pose1", 1);
    pub2 = n.advertise<ros_mooc::Pose>("pose2", 1);
    pub3 = n.advertise<ros_mooc::Pose>("pose3", 1);

    // 发布频率
    ros::Rate loop_rate(1);

    // publish pose
    while (ros::ok())
    {
        pub1.publish(pose1);
        pub2.publish(pose2);
        pub3.publish(pose3);
        std::cout << "Publisher publishing msgs" << std::endl;
        loop_rate.sleep();
    }
    return 0;
}
