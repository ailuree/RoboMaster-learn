#pragma once

#include <iostream>
#include <opencv2/opencv.hpp>
#include <string>
#include <random>

using namespace cv;
using namespace std;

void hello(); // ���Ժ���

void demo_imgShow(); // ��ȡ����ʾ������ͼ��

void demo_imgGet(string str); // ��������ȡͼ�񡢸���Ȥ����

void onMouse(int event, int x, int y, int flags, void *param); // evnet:����¼����� x,y:������� flags������ĸ���
void demo_setMouse(Mat &str);                                  // ͨ���ӿڹ�������¼���ָ��ͼ��

void demo_salt(Mat &image, int n); // ���ʱ���ͼ������ ���ӽ������� ��������ֲ���

void demo_copy(Mat &img);  // ��������ͼ�����أ�����ʵ��ͼƬ�ĸ������
void demo_copy2(Mat &img); // ��������ͼ�񣬲����� ����ͨ��filter2Dʵ�֣����Ҹ�ͼ�񸽼Ӵ���Ч��

void demo_binarization(Mat &img); // ��ԭͼ���лҶȴ���Ȼ���ֵ��

void demo_openVideo(); // ����Ƶ

void demo_opencamera(); // ������ͷ

void demo_readFps(); // ʵʱ��ʾ֡��

int pixAve(Mat &img); // ��װ��������ƽ����ֵ

Mat ExpansionBina(Mat &img); // ���Ͷ�ֵ��

void openCamera2(); // ������ͷ�����һҶȻ�

// Matÿ�������ڵ����ݸ�ʽ---------- - Mat����
// Mat_<uchar>-------- - CV_8U��0-255��
// Mat<char>---------- - CV_8S��-128-127��
// Nat_<short>-------- - CV_16S��-32768-32767��
// Mat_<ushort>--------CV_16U��0-65535��
// Mat_<int>---------- - CV_32S��-2147483648-2147483647��
// Mat_<float>----------CV_32F��-FLT_MAX��FLT_MAX��INF��NAN��
// Mat_<double>--------CV_64F��-DBL_MAX��DBL_MAX��INF��NAN��

// Mat�������ͺ�ͨ����Ӧ��type()
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
