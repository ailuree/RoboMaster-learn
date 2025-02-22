#include "otest.h"

void demo_imgShow()
{
	Mat image;						 // 创建一个空图像image
	image = imread("../test01.png"); // 读取文件夹中的图像

	// 检测图像是否加载成功
	if (image.empty()) // 检测image有无数据，无数据 image.empty()返回 真
	{
		cout << "Could not open or find the image" << endl;
		return;
	}

	// namedWindow("IMAGE");  //创建显示窗口，不加这行代码，也能显示，默认窗口大小不能改变
	namedWindow("IMAGE", WINDOW_NORMAL);
	imshow("IMAGE", image); // 在窗口显示图像
	waitKey(0);
	// imwrite("1.png", image); //保存图像为png格式，文件名称为1
}
void hello()
{
	cout << "hello" << endl;
}