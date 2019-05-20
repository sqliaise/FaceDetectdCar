#include <include/frame_handle.hpp>

using namespace cv;
Mat frame_handle(Mat &img)
{
    double scale = 2;


    //建立缩小的图片，加快检测速度
    //nt cvRound (double value) 对一个double型的数进行四舍五入，并返回一个整型数！
    Mat gray, smallImg( cvRound (img.rows/scale), cvRound(img.cols/scale), CV_8UC1 );
    //转成灰度图像，Harr特征基于灰度图
    cvtColor( img, gray, CV_BGR2GRAY );
    //imshow("灰度",gray);
    //改变图像大小，使用双线性差值
    resize( gray, smallImg, smallImg.size(), 0, 0, INTER_LINEAR );
    //imshow("缩小尺寸",smallImg);
    //变换后的图像进行直方图均值化处理
    equalizeHist( smallImg, smallImg );
    //imshow("直方图均值处理",smallImg);
    //程序开始和结束插入此函数获取时间，经过计算求得算法执行时间
    return smallImg;
}
