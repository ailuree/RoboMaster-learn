#include "demo.h"

int main()
{
	// hello(); // ���Ժ���
	//  demo_imgShow(); // ��ȡ����ʾ������ͼ��

	// string str = "../image/test01.png"; // ��������ȡͼ�񡢸���Ȥ����
	// demo_imgGet(str);

	// Mat img = imread("./test01.png");
	// demo_setMouse(img);//ͨ���ӿڹ�������¼���ָ��ͼ��

	// Mat img = imread("./test01.png");
	// demo_salt(img, 5000);//���ʱ���ͼ������ ���ӽ������� ��������ֲ���
	// imshow("image", img);

	// Mat img = imread("./test01.png");
	// demo_copy(img);//��������ͼ�����أ�����ʵ��ͼƬ�ĸ������

	// Mat img = imread("./test01.png");
	// demo_copy2(img);//��������ͼ�񣬲����� ����ͨ��filter2Dʵ�֣����Ҹ�ͼ�񸽼Ӵ���Ч��

	// Mat img = imread("./test01.png");
	// demo_binarization(img);//��ԭͼ���лҶȴ���Ȼ���ֵ��

	// demo_opencamera(); // ������ͷ

	// demo_openVideo(); // ����Ƶ

	// demo_readFps();//ʵʱ��ʾ֡��

	// openCamera2();   //������ͷ�����һҶȻ�

	// �����ǻ�ͼ����

	Mat bgImage = imread("./image/p1.jpeg");
	// Mat dst = bgImage(Rect(0, 0, 100, 100));
	MyLines();
	MyRectangle();
	MyEllipse();
	MyCircle();
	MyPolygon();
	// �˸�������Ŀ��ͼ�����֣��ı������½�λ�ã����壬�ֺ�(���ű���)����ɫ���߿�������
	putText(bgImage, "hello opencv", Point(300, 300), FONT_HERSHEY_COMPLEX, 1.0, Scalar(0, 255, 211), 1, 8);
	namedWindow("output", WINDOW_AUTOSIZE);
	imshow("output", bgImage);
	RandomLineDemo();

	waitKey(0); // ��ͣ������ͼ����ʾ���ȴ���������

	return 0;
}