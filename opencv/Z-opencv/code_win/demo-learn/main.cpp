#include "demo.h"

int main()
{
	// hello(); // 测试函数
	//  demo_imgShow(); // 读取、显示、保存图像

	// string str = "../image/test01.png"; // 创建、获取图像、感兴趣区域
	// demo_imgGet(str);

	// Mat img = imread("./test01.png");
	// demo_setMouse(img);//通过接口关联鼠标事件和指定图像

	// Mat img = imread("./test01.png");
	// demo_salt(img, 5000);//访问遍历图像像素 增加椒盐噪声 这是随机分布的
	// imshow("image", img);

	// Mat img = imread("./test01.png");
	// demo_copy(img);//遍历访问图像像素，并且实现图片的复制输出

	// Mat img = imread("./test01.png");
	// demo_copy2(img);//遍历访问图像，并复制 但是通过filter2D实现，并且给图像附加处理效果

	// Mat img = imread("./test01.png");
	// demo_binarization(img);//对原图进行灰度处理，然后二值化

	// demo_opencamera(); // 打开摄像头

	// demo_openVideo(); // 打开视频

	// demo_readFps();//实时显示帧率

	// openCamera2();   //打开摄像头，并且灰度化

	// 下面是绘图操作

	Mat bgImage = imread("./image/p1.jpeg");
	// Mat dst = bgImage(Rect(0, 0, 100, 100));
	MyLines();
	MyRectangle();
	MyEllipse();
	MyCircle();
	MyPolygon();
	// 八个参数：目标图像，文字，文本框左下角位置，字体，字号(缩放比例)，颜色，线宽，线类型
	putText(bgImage, "hello opencv", Point(300, 300), FONT_HERSHEY_COMPLEX, 1.0, Scalar(0, 255, 211), 1, 8);
	namedWindow("output", WINDOW_AUTOSIZE);
	imshow("output", bgImage);
	RandomLineDemo();

	waitKey(0); // 暂停，保持图像显示，等待按键结束

	return 0;
}