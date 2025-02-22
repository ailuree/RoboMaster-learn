# matlab相机标定

![1](G:\temp\vgd\1Aa1-联盟赛之后\jpg\matlab相机标定\1.png)

首先确定棋盘格上每个格子的宽度

标定时记得输入此宽度

![2](G:\temp\vgd\1Aa1-联盟赛之后\jpg\matlab相机标定\2.png)

默认选项即可

![3](G:\temp\vgd\1Aa1-联盟赛之后\jpg\matlab相机标定\3.png)

总体小于0.5即认为标定结果可信

另外记得删除一些误差较大的数据

![4](G:\temp\vgd\1Aa1-联盟赛之后\jpg\matlab相机标定\4.png)

![5](G:\temp\vgd\1Aa1-联盟赛之后\jpg\matlab相机标定\5.png)

最后需要

![6](G:\temp\vgd\1Aa1-联盟赛之后\jpg\matlab相机标定\6.png)

径向畸变里的数可能只有两个，此时就是 k3默认为0即可