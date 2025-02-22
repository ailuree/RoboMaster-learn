#include "demo.h"

Mat bgImage;//定义一个全局变量

int main()
{
	//demo_imgShow(); // 读取、显示、保存图像

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

	//Mat img = imread("../image/test01.png");
	//demo_binarization(img);//对原图进行灰度处理，然后二值化

	//demo_opencamera(); // 打开摄像头

	//demo_openVideo(); // 打开视频

	// demo_readFps();//实时显示帧率

	//openCamera2();   //打开摄像头，并且灰度化

	// 下面是绘图操作

	// bgImage = imread("../image/test01.png");
	// // Mat dst = bgImage(Rect(0, 0, 100, 100));
	// MyLines();
	// MyRectangle();
	// MyEllipse();
	// MyCircle();
	// MyPolygon();
	// // 八个参数：目标图像，文字，文本框左下角位置，字体，字号(缩放比例)，颜色，线宽，线类型
	// putText(bgImage, "hello opencv", Point(300, 300), FONT_HERSHEY_COMPLEX, 1.0, Scalar(0, 255, 211), 1, 8);
	// namedWindow("output", WINDOW_AUTOSIZE);
	// imshow("output", bgImage);

	waitKey(0); // 暂停，保持图像显示，等待按键结束

	return 0;
}


void MyLines(){
    Point p1 = Point(20, 30);
    Point p2;
    p2.x = 300;
    p2.y = 300;
    Scalar color = Scalar(0, 0, 255);
    //六个参数分别是：原图，起始点，结束点，颜色，线宽，线类型
    line(bgImage, p1, p2, color, 1, 8);//该opencv版本不支持LINE_8，直接写8就行
}
void MyRectangle(){
    Rect rect = Rect(200, 100, 300, 300);
    Scalar color = Scalar(255, 0, 0);
    //空心矩形
    rectangle(bgImage, rect, color, 2, 8);//五个参数分别是：原图，矩形大小，颜色，线宽，线类型
}
void MyEllipse(){
    Scalar color = Scalar(0, 255, 0);
    //九个参数：原图，圆心，大小（width和height），椭圆的摆放角度，起始角度，结束角度，颜色，线宽，线类型
    ellipse(bgImage, Point(bgImage.cols / 2, bgImage.rows / 2), Size(100,200), 0, 0, 360, color, 2, 8);
}
void MyCircle(){
    Scalar color = Scalar(0, 255, 255);
    Point center = Point(bgImage.cols / 2, bgImage.rows / 2);
    circle(bgImage, center, 150,color,2,8);//六个参数：原图，圆心，半径，颜色，线宽，线类型
}
void MyPolygon(){
    Point pts[1][5];
    pts[0][0] = Point(100, 100);
    pts[0][1] = Point(100, 200);
    pts[0][2] = Point(200, 200);
    pts[0][3] = Point(200, 100);
    pts[0][4] = Point(100, 100);
    const Point* ppts[] = { pts[0] };//指向指针的指针
    int npt[] = { 5 };//定义一个整形数组
    Scalar color = Scalar(255, 12, 255);
    //六个参数：目标图像，多边形的顶点集合（指针数组），多边形顶点的数目（整型数组），要绘制的多边形的数量，颜色，线宽
    fillPoly(bgImage, ppts, npt, 1, color, 8);

}