#include <ros/ros.h>
#include <ros_mooc/Pose.h>
#include <unistd.h>
#include <Eigen/Core>
#include <iostream>

using namespace std;

void Sub1CB(const ros_mooc::Pose::ConstPtr& msg)
{
    std::cout << "Sub1CB : " << msg->name << std::endl;
}

void Sub2CB(const ros_mooc::Pose::ConstPtr& msg)
{
    std::cout << "Sub2CB : " << msg->name << std::endl;
}

void Sub3CB(const ros_mooc::Pose::ConstPtr& msg)
{
    std::cout << "Sub3CB : " << msg->name << std::endl;
    /*
    while (true)
    {
        sleep(10);
    }
    */
    sleep(5);
}

int main(int argc, char** argv)
{
    // 注册节点
    ros::init(argc, argv, "ros_mooc_sub");
    ros::NodeHandle n;

    // 订阅消息
    std::cout << "sub start " << std::endl;
    ros::Subscriber sub3 = n.subscribe("pose3", 1, Sub3CB);
    ros::Subscriber sub1 = n.subscribe("pose1", 1, Sub1CB);
    ros::Subscriber sub2 = n.subscribe("pose2", 1, Sub2CB);

    ros::spin();
    // ros::MultiThreadedSpinner spinner(3);
    // spinner.spin();

    /*
    ros::AsyncSpinner spinner(3);
    spinner.start();
    ros::waitForShutdown();
    */
    std::cout << "end sub " << std::endl;
    return 0;
}
