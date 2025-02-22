#pragma once

#include <iostream>
#include <opencv2/opencv.hpp>
#include <string>
#include <random>

using namespace cv;
using namespace std;

void hello(); // 测试函数

void demo_imgShow(); // 读取、显示、保存图像

void demo_imgGet(string str); // 创建、获取图像、感兴趣区域

void onMouse(int event, int x, int y, int flags, void *param); // evnet:鼠标事件类型 x,y:鼠标坐标 flags：鼠标哪个键
void demo_setMouse(Mat &str);                                  // 通过接口关联鼠标事件和指定图像

void demo_salt(Mat &image, int n); // 访问遍历图像像素 增加椒盐噪声 这是随机分布的

void demo_copy(Mat &img);  // 遍历访问图像像素，并且实现图片的复制输出
void demo_copy2(Mat &img); // 遍历访问图像，并复制 但是通过filter2D实现，并且给图像附加处理效果

void demo_binarization(Mat &img); // 对原图进行灰度处理，然后二值化

void demo_openVideo(); // 打开视频

void demo_opencamera(); // 打开摄像头

void demo_readFps(); // 实时显示帧率

int pixAve(Mat &img); // 封装函数返回平均阈值

Mat ExpansionBina(Mat &img); // 膨胀二值化

void openCamera2(); // 打开摄像头，并且灰度化

// Mat每个格子内的数据格式---------- - Mat定义
// Mat_<uchar>-------- - CV_8U（0-255）
// Mat<char>---------- - CV_8S（-128-127）
// Nat_<short>-------- - CV_16S（-32768-32767）
// Mat_<ushort>--------CV_16U（0-65535）
// Mat_<int>---------- - CV_32S（-2147483648-2147483647）
// Mat_<float>----------CV_32F（-FLT_MAX…FLT_MAX，INF，NAN）
// Mat_<double>--------CV_64F（-DBL_MAX…DBL_MAX，INF，NAN）

// Mat数据类型和通道对应的type()
//               C1          C2          C3          C4
// CV_8U         0           8           16          24
// CV_8S         1           9           17          25
// CV_16U        2          10           18          26
// CV_16S        3          11           19          27
// CV_32S        4          12           20          28
// CV_32F        5          13           21          29
// CV_64F        6          14           22          30

void MyLines();
void MyRectangle();
void MyEllipse();
void MyCircle();
void MyPolygon();
void RandomLineDemo();
