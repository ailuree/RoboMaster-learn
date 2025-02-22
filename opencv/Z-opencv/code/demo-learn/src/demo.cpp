#include "demo.h"

void hello()
{
	cout << "hello" << endl;
}

// 显示图片
void demo_imgShow()
{
	Mat image;							   // 创建一个空图像image
	image = imread("../image/test01.png"); // 读取文件夹中的图像

	// 检测图像是否加载成功
	if (image.empty()) // 检测image有无数据，无数据 image.empty()返回 真
	{
		cout << "Could not open or find the image" << endl;
		return;
	}

	// namedWindow("IMAGE");  //创建显示窗口，不加这行代码，也能显示，默认窗口大小不能改变
	namedWindow("IMAGE", WINDOW_NORMAL);
	imshow("IMAGE", image); // 在窗口显示图像

	imwrite("1.png", image); // 保存图像为png格式，文件名称为1
}
// 截取ROI  以及显示图像行数列数通道数
void demo_imgGet(string str)
{

	// Mat image(100, 100, CV_8U, 100);
	// Mat image(100, 100, CV_8U, Scalar(100));
	Mat image0(100, 100, CV_8U); // 未指定灰度图的像素值时，默认各点为0

	imshow("image0", image0);

	Mat imageROI0(image0, Rect(0, 0, 50, 50)); // 定义感兴趣区域

	imshow("imageROI0", imageROI0); // 显示感兴趣区域

	cout << "image0的行数为： " << image0.rows << "\t" << "imageROI0的行数为：" << imageROI0.rows << endl;											  // 获取图像的高度，行数；
	cout << "image0的列数为： " << image0.cols << "\t" << "imageROI0的列数为：" << imageROI0.cols << endl;											  // 获取图像的宽度，列数；
	cout << "image0的通道数为： " << image0.channels() << "\t" << "imageROI0的通道数为：" << imageROI0.channels() << endl;							  // 获取图像的通道数，彩色图=3，灰度图=1；
	cout << "image0的尺寸为： " << image0.size << "\t" << "imageROI0的尺寸为：" << imageROI0.size << endl;											  // 获取图像的尺寸，行*列；
	cout << "image0的各点像素值为：" << int(image0.at<uchar>(0, 0)) << "\t" << "imageROI0的各点像素值为：" << int(imageROI0.at<uchar>(0, 0)) << endl; // 获取图像的各点像素值；

	Mat image1(100, 100, CV_8UC3, Scalar(0, 0, 255));
	imshow("image1", image1);

	Mat imageROI1(image1, Rect(0, 0, 50, 50)); // 定义感兴趣区域

	imshow("imageROI1", imageROI1); // 显示感兴趣区域

	cout << "image1的行数为： " << image1.rows << "\t" << "imageROI1的行数为：" << imageROI1.rows << endl;													// 获取图像的高度，行数；
	cout << "image1的列数为： " << image1.cols << "\t" << "imageROI1的列数为：" << imageROI1.cols << endl;													// 获取图像的宽度，列数；
	cout << "image1的通道数为： " << image1.channels() << "\t" << "imageROI1的通道数为：" << imageROI1.channels() << endl;									// 获取图像的通道数，彩色图=3，灰度图=1；
	cout << "image1的尺寸为： " << image1.size << "\t" << "imageROI1的尺寸为：" << imageROI1.size << endl;													// 获取图像的尺寸，行*列；
	cout << "image1的各点像素值为：" << int(image1.at<Vec3b>(0, 0)[0]) << "\t" << "imageROI1的各点像素值为：" << int(imageROI1.at<Vec3b>(0, 0)[0]) << endl; // 获取图像的各点像素值；

	Mat image2 = imread(str); // 读取图像；
	if (image2.empty())
	{
		cout << "读取错误" << endl;
		return;
	}

	imshow("image2", image2); // 显示图像；

	Mat imageROI2(image2, Rect(0, 0, 1000, 1000)); // 定义感兴趣区域  这个1000，1000是指的是行数列数，对应区域大小  每一个点对应一个像素点（像素点的位置，行、列号）
	// 只不过3通道图的每个像素点对应3个通道，每个通道的值是0-255之间的数值 对应不同的位深（0-255 8位）就能使像素点显示彩色

	imshow("imageROI2", imageROI2); // 显示感兴趣区域

	cout << "image2的行数为： " << image2.rows << "\t" << "imageROI2的行数为：" << imageROI2.rows << endl;				   // 获取图像的高度，行数；
	cout << "image2的列数为： " << image2.cols << "\t" << "imageROI2的列数为：" << imageROI2.cols << endl;				   // 获取图像的宽度，列数；
	cout << "image2的通道数为： " << image2.channels() << "\t" << "imageROI2的通道数为：" << imageROI2.channels() << endl; // 获取图像的通道数，彩色图=3，灰度图=1；
	cout << "image2的尺寸为： " << image2.size << "\t" << "imageROI2的尺寸为：" << imageROI2.size << endl;				   // 获取图像的尺寸，行*列；
}
// 鼠标事件
void onMouse(int event, int x, int y, int flags, void *param) // evnet:鼠标事件类型 x,y:鼠标坐标 flags：鼠标哪个键
{
	Mat *im = reinterpret_cast<Mat *>(param);
	switch (event)
	{

	case EVENT_LBUTTONDOWN:
		// 显示图像像素值

		if (static_cast<int>(im->channels()) == 1)
		{
			// 若图像为单通道图像，则显示鼠标点击的坐标以及灰度值
			switch (im->type())
			{
			case 0:
				cout << "at (" << x << ", " << y << " ) value is: " << static_cast<int>(im->at<uchar>(Point(x, y))) << endl;
				break;
			case 1:
				cout << "at (" << x << ", " << y << " ) value is: " << static_cast<int>(im->at<char>(Point(x, y))) << endl;
				break;
			case 2:
				cout << "at (" << x << ", " << y << " ) value is: " << static_cast<int>(im->at<ushort>(Point(x, y))) << endl;
				break;
			case 3:
				cout << "at (" << x << ", " << y << " ) value is: " << static_cast<int>(im->at<short>(Point(x, y))) << endl;
				break;
			case 4:
				cout << "at (" << x << ", " << y << " ) value is: " << static_cast<int>(im->at<int>(Point(x, y))) << endl;
				break;
			case 5:
				cout << "at (" << x << ", " << y << " ) value is: " << static_cast<int>(im->at<float>(Point(x, y))) << endl;
				break;
			case 6:
				cout << "at (" << x << ", " << y << " ) value is: " << static_cast<int>(im->at<double>(Point(x, y))) << endl;
				break;
			}
		}
		else
		{
			// 若图像为彩色图像，则显示鼠标点击坐标以及对应的B, G, R值
			cout << "at (" << x << ", " << y << ")"
				 << "  B value is: " << static_cast<int>(im->at<Vec3b>(Point(x, y))[0])
				 << "  G value is: " << static_cast<int>(im->at<Vec3b>(Point(x, y))[1])
				 << "  R value is: " << static_cast<int>(im->at<Vec3b>(Point(x, y))[2])
				 << endl;
		}

		break;
	}
}
void demo_setMouse(Mat &image)
{
	imshow("image", image);
	setMouseCallback("image", onMouse, reinterpret_cast<void *>(&image)); // 关联图像显示窗口和onMouse函数
}
// 椒盐噪声
void demo_salt(Mat &image, int n)
{
	// 随机数生成器
	default_random_engine generater;
	uniform_int_distribution<int> randomRow(0, image.rows - 1);
	uniform_int_distribution<int> randomCol(0, image.cols - 1);

	int i, j;
	for (int k = 0; k < n; k++)
	{
		i = randomCol(generater);
		j = randomRow(generater);
		if (image.channels() == 1)
		{
			image.at<uchar>(j, i) = 255;
		}
		else if (image.channels() == 3)
		{
			image.at<Vec3b>(j, i)[0] = 255;
			image.at<Vec3b>(j, i)[1] = 255;
			image.at<Vec3b>(j, i)[2] = 255;
		}
	}
}
// 图像复制
void demo_copy(Mat &img)
{
	Mat output_image; // 定义输出图像

	output_image = Mat(img.size(), img.type()); // 定义输出图像大小
	output_image = img.clone();					// 克隆原图像素值

	int rows = img.rows;					// 原图行数
	int stepx = img.channels();				// 原图通道数
	int cols = (img.cols) * img.channels(); // 矩阵总列数，在BGR彩色图像中，每个像素的BGR通道按顺序排列，因此总列数=像素宽度*通道数
	// 若单通道，则是乘1

	for (int row = 1; row < (rows - 1); row++) // 对行遍历
	{
		const uchar *previous = img.ptr<uchar>(row - 1); // 原图上一行指针
		const uchar *current = img.ptr<uchar>(row);		 // 原图当前行指针
		const uchar *next = img.ptr<uchar>(row + 1);	 // 原图下一行指针
		uchar *output = output_image.ptr<uchar>(row);	 // 输出图像当前行指针

		for (int col = stepx; col < (cols - stepx); col++) // 对列遍历
		{
			output[col] = saturate_cast<uchar>(5 * current[col] - (previous[col] + current[col - stepx] + current[col + stepx] + next[col]));
			// saturate_cast<uchar>(a)，当a在0—255时输出a，当a小于0输出0，当a大于255输出255，保证a的值在0~255之间
		}
	}
	imshow("img", img);
	imshow("output_image", output_image);
}

// 图像复制、卷积处理
void demo_copy2(Mat &img)
{

	Mat output_image; // 定义输入图像和输出图像

	Mat kernel0 = (Mat_<char>(3, 3) << 0, 0, 0, 0, 1, 0, 0, 0, 0);	  // 这个滤波器是和原图一样
	Mat kernel = (Mat_<char>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0); // 创建滤波器 这个滤波器内核是实现了锐化效果
	// filter2D滤波器更适用于黑白2d图像
	// 对彩色图像可能3D滤波器更加适用
	filter2D(img, output_image, img.depth(), kernel0); // 卷积

	imshow("img", img);
	imshow("output_image", output_image);
}
// 灰度化、二值化
void demo_binarization(Mat &img)
{

	if (img.empty())
	{
		std::cout << "error!" << std::endl;
		return;
	}

	// 对原图进行灰度化
	// BGR的图像可以直接用opencv自带的库进行二值化
	Mat gray;
	cv::cvtColor(img, gray, COLOR_BGR2GRAY);
	imshow("img", gray);

	// 灰度图像二值化
	//  灰度图中，图像灰度值的范围是0~255
	// THRESH_BINARY_INV--灰度大于阈值125则设为0, 其他值为最大  这是图像二值化方法的标志
	cv::Mat gray_binary;
	cv::Mat gray_binary2;
	// 对先灰度化的图进行二值化
	// cv::threshold(gray, gray_binary, 125, 255, cv::THRESH_BINARY_INV);
	// cv::threshold(gray, gray_binary2, 125, 255, cv::THRESH_BINARY);//这个是灰度大于阈值为最大值，其他为0

	// 对原图进行二值化

	int height = img.rows;
	int width = img.cols;

	// 灰度值总和
	int px_t = 0;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			px_t += int(gray.at<uchar>(i, j)); // 像素点的灰度值
		}
	}
	// 求像素平均值
	int avg_thresh = px_t / (height * width);

	cout << "阈值:" << avg_thresh << endl;

	cv::threshold(gray, gray_binary, avg_thresh, 255, cv::THRESH_BINARY_INV);
	cv::threshold(gray, gray_binary2, avg_thresh, 255, cv::THRESH_BINARY); // 这个是灰度大于阈值为最大值，其他为0

	cv::imshow("gray_binary", gray_binary); // grar_binary为二值化后图片
	cv::imshow("gray_binary2", gray_binary2);
}

// 视频操作
void demo_openVideo()
{
	VideoCapture capture("../image/test.mp4"); // 打开视频文件

	if (!capture.isOpened()) // 检测视频是否打开
	{
		cout << "Could not open or find the video" << endl;
		return;
	}

	Mat frame; // 定义一个Mat类型的变量，用于存储每一帧的图像

	while (1)
	{
		capture >> frame; // 读取视频的每一帧

		if (frame.empty()) // 检测视频是否读取完毧
		{
			cout << "Could not open or find the video" << endl;
			break;
		}

		imshow("frame", frame); // 显示每一帧的图像

		if (waitKey(30) == 27) // 每30ms显示一帧，若按下ESC键则退出
		{
			break;
		}
	}
}

// 相机操作
void demo_opencamera()
{
	// 1.创建视频采集对象;
	// VideoCapture cap;

	// 2.打开默认相机;
	// cap.open(0);

	VideoCapture cap(0);
	// cap.open(1);

	// 3.判断相机是否打开成功;
	if (!cap.isOpened())
		return;
	// 4.显示窗口命名;

	// With webcam get(CV_CAP_PROP_FPS) does not work.
	// Let's see for ourselves.
	namedWindow("Video", 1);
	while (1)
	{
		// 获取新的一帧;
		Mat frame;
		cap >> frame;
		if (frame.empty())
			return;
		// 显示新的帧;
		imshow("Video", frame);
		// 按键退出显示;
		if (waitKey(30) >= 0)
			break;
	}
	// 5.释放视频采集对象;
	cap.release();
}

// 读取帧率
void demo_readFps()
{
	cv::Mat frame;
	// 可从摄像头输入视频流或直接播放视频文件
	cv::VideoCapture capture(1);
	// cv::VideoCapture capture("vedio1.avi");
	double fps;
	char string[10]; // 帧率字符串
	cv::namedWindow("Camera FPS");
	double t = 0;
	while (1)
	{
		t = (double)cv::getTickCount(); // 计数器
		if (cv::waitKey(1) == 1)
		{
			break;
		}
		if (capture.isOpened())
		{
			capture >> frame;
			// getTickcount函数：返回从操作系统启动到当前所经过的毫秒数
			// getTickFrequency函数：返回每秒的计时周期数
			// t为该处代码执行所耗的时间,单位为秒,fps为其倒数
			t = ((double)cv::getTickCount() - t) / cv::getTickFrequency();
			fps = 1.0 / t;
			sprintf(string, "%.2f", fps); // 帧率保留两位小数
			std::string fpsString("FPS:");
			fpsString += string; // 在"FPS:"后加入帧率数值字符串
			printf("fps: %.2f width:%d height:%d fps:%.2f\n", fps, frame.cols, frame.rows, capture.get(CAP_PROP_FPS));
			// 将帧率信息写在输出帧上
			cv::putText(frame,					  // 图像矩阵
						fpsString,				  // string型文字内容
						cv::Point(5, 20),		  // 文字坐标，以 左上角 为原点
						cv::FONT_HERSHEY_SIMPLEX, // 字体类型
						0.5,					  // 字体大小
						cv::Scalar(0, 0, 0));	  // 字体颜色
			cv::imshow("Camera FPS", frame);
			char c = cv::waitKey(30); // 延时30毫秒
			// 注：waitKey延时越长 fps越小 出现跳帧 摄像头显示变卡
			if (c == 27) // 按ESC键退出
				break;
		}
		else
		{
			std::cout << "No Camera Input!" << std::endl;
			break;
		}
	}
}

// 膨胀
int pixAve(Mat &img)
{
	int height = img.rows;
	int width = img.cols;
	// 灰度值总和
	int px_t = 0;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			px_t += int(img.at<uchar>(i, j)); // 像素点的灰度值
		}
	}
	// 求像素平均值
	int avg_thresh = px_t / (height * width);
	return avg_thresh;
}

Mat ExpansionBina(Mat &img)
{
	Mat dst = img;
	blur(dst, dst, Size(1, 3)); // 沿垂直方向模糊目标图像
	int ave = pixAve(img);
	threshold(dst, dst, ave, 255, THRESH_BINARY); // 二值化目标图像

	Mat kernel = getStructuringElement(MORPH_ELLIPSE, Size(3, 3), Point(-1, -1)); // 创建椭圆结构元素
	dilate(dst, dst, kernel);													  // 膨胀
	return dst;
}

// 视频二值化、膨胀
void openCamera2()
{

	VideoCapture cap(0);

	if (!cap.isOpened())
		return;
	namedWindow("original", 1);
	namedWindow("gray", 1);
	namedWindow("end", 1);
	while (1)
	{
		// 获取新的一帧;
		Mat frame;
		cap >> frame;
		if (frame.empty())
			return;
		// 显示新的帧;
		imshow("original", frame);

		// 对每帧图像进行灰度化
		Mat gray;
		cv::cvtColor(frame, gray, COLOR_BGR2GRAY);
		imshow("gray", gray);

		// 对每帧图像膨胀二值化
		Mat dst = ExpansionBina(gray);
		imshow("end", dst);
		// 按键退出显示;
		if (waitKey(30) >= 0)
			break;
	}
	cap.release();
}