cmake_minimum_required(VERSION 3.17)

set(CMAKE_CXX_STANDARD 17)

SET(PROJECT_NAME otest)
project(${PROJECT_NAME})

include_directories(
    ${PROJECT_SOURCE_DIR}/include/
    )                                                   #包含源路径下的所有的头文件

#包含opencv绝对路径
# SET(OpenCV_DIR D:/opencv-4.5.2/opencv/MingwBuild/install)##这里标明编译好的opencv目录  

find_package( OpenCV REQUIRED )                         ##找寻路径下的所需文件
include_directories( ${OpenCV_INCLUDE_DIRS})            #包含opencv库目录

#打印调试信息
MESSAGE(STATUS "Project: ${PROJECT_NAME}")
MESSAGE(STATUS "OpenCV library status:")
MESSAGE(STATUS "    version: ${OpenCV_VERSION}")
MESSAGE(STATUS "    libraries: ${OpenCV_LIBS}")
MESSAGE(STATUS "    include path: ${OpenCV_INCLUDE_DIRS}")

aux_source_directory(src DIR_SRCS)                       ##自动搜寻指定目录下的所有需要的文件（.h .cpp)都可 

#打印调试src获取的文件
MESSAGE(STATUS "Src file: ${DIR_SRCS}")

#编译添加可执行程序，命名为project name
add_executable(${PROJECT_NAME}
                 main.cpp
                ${DIR_SRCS}
                )                                        ##添加可执行目标

target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS} )   ##链接opencv库
