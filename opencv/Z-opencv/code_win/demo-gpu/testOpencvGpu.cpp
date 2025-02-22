#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

using namespace cv::cuda;

void opencv_test()
{
    Mat image;
    image = imread("../test01.png");
    namedWindow("Display Image", WINDOW_AUTOSIZE );
    imshow("Display Image", image);
    waitKey(0);
}

void cuda_test()
{
    cout << "CUDA-opencv test" << endl;

    int num_devices = getCudaEnabledDeviceCount();
        if (num_devices == 0 )
        {
            std::cout << "OpenCV is compiled without CUDA support" << endl;
            return;
        }
        else if (num_devices == -1)
        {
            std::cout << "CUDA driver is not installed" << endl;
            return;
        }
        else if (num_devices >= 1)
        {
            std::cout << "CUDA-Opencv can be used and the number of GPU is :" << num_devices << endl;
            return;
        }
}

int main(int argc, char** argv )
{
    opencv_test();
    
    cuda_test();
    return 0;
}