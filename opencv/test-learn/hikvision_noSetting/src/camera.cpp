#include "../include/camera.hpp"
#include <cstdio>
namespace hik{
    camera::camera()
    {
        nRet = MV_OK;
        handle = NULL;
        g_bExit = false;
        g_nPayloadSize = 0;
        pDataForRGB  = (unsigned char*)malloc(1440 * 1080 * 4 + 2048);
        memset(&stParam, 0, sizeof(MVCC_INTVALUE));
        CvtParam={0};
        stOutFrame = {0};
        memset(&stOutFrame, 0, sizeof(MV_FRAME_OUT));
    }
    void camera::start_cam()
    {

        memset(&stDeviceList, 0, sizeof(MV_CC_DEVICE_INFO_LIST));
        nRet = MV_CC_EnumDevices(MV_USB_DEVICE, &stDeviceList);
	if(nRet == MV_OK)
	{
		std::cout << "Enum Devices success!" << std::endl;
		if (stDeviceList.nDeviceNum > 0)
		{
		    for (unsigned int i = 0; i < stDeviceList.nDeviceNum; i++)
		    {
		        pDeviceInfo = stDeviceList.pDeviceInfo[i];
		        if (NULL == pDeviceInfo)
		        {
		            break;
		        }
		        PrintDeviceInfo();
		    }
		}else{
		    cout<<"Find no Device"<<endl;
		}
	}
	else{
		printf("Enum Device fail! nRet = 0x%x\n",nRet);
	}
        unsigned int nIndex = 0;
        MV_CC_CreateHandle(&handle, stDeviceList.pDeviceInfo[nIndex]);
        MV_CC_OpenDevice(handle);
        if (stDeviceList.pDeviceInfo[nIndex]->nTLayerType == MV_GIGE_DEVICE)
        {
            int nPacketSize = MV_CC_GetOptimalPacketSize(handle);
            if (nPacketSize > 0)
            {
                MV_CC_SetIntValue(handle,"GevSCPSPacketSize",nPacketSize);
            }else{
                cout<<"Warning: Get Packet Size fail"<<endl;
            }
        }
        MVCC_ENUMVALUE  p={0};
        MVCC_STRINGVALUE st;
        MV_CC_GetStringValue(handle,"DeviceModelName",&st);
        cout<<"DeviceModelName: "<<st.chCurValue<<endl;
        MV_CC_GetStringValue(handle,"DeviceVersion",&st);
        cout<<"DeviceVersion:\t"<<st.chCurValue<<endl;
        MV_CC_GetEnumValue(handle,"DeviceScanType",&p);
        if(p.nCurValue==0)
        {
            cout<<"DeviceScanType:\t"<<"Areascan"<<endl;

        }else{
            cout<<"DeviceScanType:\t"<<"Linescan"<<endl;
        }
//        MV_CC_SetIntValueEx(handle, "Height", 540);
//        MV_CC_SetIntValueEx(handle, "Width", 720);
        MVCC_INTVALUE_EX inh,inw;
        MV_CC_GetIntValueEx(handle, "Height", &inh);
        MV_CC_GetIntValueEx(handle, "Width", &inw);
        cout << "Height: " << inh.nCurValue << "  Width: " << inw.nCurValue<< endl;

        MV_CC_SetEnumValue(handle, "TriggerMode", 0);
        MV_CC_SetEnumValue(handle, "PixelFormat", 0x0210001F);
        MV_CC_SetEnumValue(handle, "GainAuto", 1);
        MV_CC_SetFloatValue(handle, "Gamma", 0.8);
        MV_CC_SetBoolValue(handle, "GammaEnable", 1);
        MV_CC_SetEnumValue(handle, "BalanceWhiteAuto", 2);
        MV_CC_SetEnumValue(handle, "ExposureAuto", 1);
        MV_CC_GetIntValue(handle, "PayloadSize", &stParam);
        MV_CC_SetAcquisitionLineRate(handle, 300);
        g_nPayloadSize = stParam.nCurValue;
        nRet = MV_CC_StartGrabbing(handle);
        if (MV_OK == nRet)
            cout<<"Start Grabbing !"<<endl;
        cout<<"\nPress ESC to exit.\n";
    }
    void camera::PrintDeviceInfo()
    {
        if (NULL == pDeviceInfo)
        {
            cout<<"null point"<<endl;
        }
        if (pDeviceInfo->nTLayerType == MV_GIGE_DEVICE)
        {
            int nIp1 = ((pDeviceInfo->SpecialInfo.stGigEInfo.nCurrentIp & 0xff000000) >> 24);
            int nIp2 = ((pDeviceInfo->SpecialInfo.stGigEInfo.nCurrentIp & 0x00ff0000) >> 16);
            int nIp3 = ((pDeviceInfo->SpecialInfo.stGigEInfo.nCurrentIp & 0x0000ff00) >> 8);
            int nIp4 = (pDeviceInfo->SpecialInfo.stGigEInfo.nCurrentIp & 0x000000ff);
            cout<<"IP:"<<nIp1<<"."<<nIp2<<"."<<nIp3<<"."<<nIp4<<endl;
        }
    }
    void camera::close_cam()
    {
        int nRet;
        nRet = MV_OK;
        handle = NULL;
        g_bExit = false;
        g_nPayloadSize = 0;
        pDataForRGB  = (unsigned char*)malloc(1440 * 1080 * 4 + 2048);//1280 960
        memset(&stParam, 0, sizeof(MVCC_INTVALUE));
        CvtParam={0};
        stOutFrame = {0};
        memset(&stOutFrame, 0, sizeof(MV_FRAME_OUT));
        nRet = MV_CC_StopGrabbing(handle);
        // 停止取流
        nRet = MV_CC_StopGrabbing(handle);
        if (MV_OK != nRet) {
            printf("MV_CC_StopGrabbing fail! nRet [%x]\n", nRet);
            exit(-1);
        }
        printf("MV_CC_StopGrabbing succeed.\n");

        // 关闭设备
        nRet = MV_CC_CloseDevice(handle);
        if (MV_OK != nRet) {
            printf("MV_CC_CloseDevice fail! nRet [%x]\n", nRet);
            exit(-1);
        }
        printf("MV_CC_CloseDevice succeed.\n");

        // 销毁句柄
        nRet = MV_CC_DestroyHandle(handle);
        if (MV_OK != nRet) {
            printf("MV_CC_DestroyHandle fail! nRet [%x]\n", nRet);
            exit(-1);
        }
        printf("MV_CC_DestroyHandle succeed.\n");


    }
    void camera::get_pic(cv::Mat* srcimg)
    {
        int nRet = 0;
        nRet = MV_CC_GetImageBuffer(handle, &stOutFrame, 1000);
        if(nRet == MV_OK)
        {
            CvtParam.enSrcPixelType=stOutFrame.stFrameInfo.enPixelType;
            CvtParam.enDstPixelType=PixelType_Gvsp_RGB8_Packed;
            CvtParam.nHeight=stOutFrame.stFrameInfo.nHeight;
            CvtParam.nWidth=stOutFrame.stFrameInfo.nWidth;
            CvtParam.nDstBufferSize=stOutFrame.stFrameInfo.nWidth * stOutFrame.stFrameInfo.nHeight *  4 + 2048;
            CvtParam.pSrcData=stOutFrame.pBufAddr;
            CvtParam.pDstBuffer=pDataForRGB;
            CvtParam.nSrcDataLen=stOutFrame.stFrameInfo.nFrameLen;
            MV_CC_ConvertPixelType(handle,&CvtParam);
            *srcimg=Mat(stOutFrame.stFrameInfo.nHeight,stOutFrame.stFrameInfo.nWidth,CV_8UC3,pDataForRGB);
            cvtColor(*srcimg,*srcimg,COLOR_RGB2BGR);
        }
        else
        {
            printf("open image time out: 0x%x\n", nRet);
            exit(-1);
        }
        if(NULL != stOutFrame.pBufAddr)
        {
            MV_CC_FreeImageBuffer(handle, &stOutFrame);
        }
    }
    void camera::re_iso()
    {
        MV_CC_SetEnumValue(handle, "BalanceWhiteAuto", 2);
        MV_CC_SetEnumValue(handle, "ExposureAuto", 1);
    }
}
