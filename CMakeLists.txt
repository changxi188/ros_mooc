cmake_minimum_required(VERSION 2.9)
project(ros_mooc)


# 配置第三方库
find_package(catkin REQUIRED 
    COMPONENTS roscpp std_msgs message_generation) 
include_directories(${catkin_INCLUDE_DIRS})
include_directories("/usr/include/Eigen")


set(third_sup
    ${catkin_LIBRARIES}
)

# 生成msg消息
add_message_files(
    DIRECTORY msg
    FILES Pose.msg
)
generate_messages(DEPENDENCIES std_msgs)


# catkin宏命令，用于配置ROS的package配置文件和CMake文件，供依赖本包额其他软件包调用
catkin_package(
    CATKIN_DEPENDS std_msgs
)


add_executable(sub src/sub.cpp)
add_dependencies(sub ros_mooc_generate_messages_cpp)
target_link_libraries(sub ${third_sup})

add_executable(pub src/pub1.cpp)
add_dependencies(pub ros_mooc_generate_messages_cpp)
target_link_libraries(pub ${third_sup})


