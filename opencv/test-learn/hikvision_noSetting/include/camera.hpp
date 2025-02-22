#ifndef CAMERA_CLASS_H_INCLUDED
#define CAMERA_CLASS_H_INCLUDED
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "MvCameraControl.h"
#include <iostream>
#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <opencv2/video/video.hpp>
using namespace std;
using namespace cv;

namespace hik{
    class camera{
    private:
        void* handle;
        bool g_bExit;
        int nRet;
        unsigned int g_nPayloadSize;
        unsigned char *pDataForRGB;
        MV_CC_DEVICE_INFO* pDeviceInfo;
        MV_CC_DEVICE_INFO_LIST stDeviceList;
        MVCC_INTVALUE stParam;
        MV_FRAME_OUT stOutFrame;
        MV_CC_PIXEL_CONVERT_PARAM CvtParam;
    public:
        camera();
        void PrintDeviceInfo();
        void close_cam();
        void start_cam();
        void get_pic(Mat * srcimg);
        void re_iso();
    };

}

#endif // CAMERA_CLASS_H_INCLUDED