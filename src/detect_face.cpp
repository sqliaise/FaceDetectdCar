#include <include/detect_face.hpp>
#include <include/ctrl_car.hpp>
#include <iostream>

using namespace cv;
using namespace std;
int detectAndDraw(Mat &img, CascadeClassifier &cascade)
{
    int i = 0;
    double t = 0;
    double scale = 1;
    //建立用于存放人脸的向量容器
    vector<Rect> faces;
    faces.clear();

    vector<Rect> nestedObjects;
    Point center;
    Scalar color = CV_RGB(255,0,0);
    int radius;
    //程序开始和结束插入此函数获取时间，经过计算求得算法执行时间
    //t = (double)cvGetTickCount();
    //检测人脸
    //detectMultiScale函数中smallImg表示的是要检测的输入图像为smallImg，faces表示检测到的人脸目标序列，1.1表示
    //每次图像尺寸减小的比例为1.1，2表示每一个目标至少要被检测到3次才算是真的目标(因为周围的像素和不同的窗口大
    //小都可以检测到人脸),CV_HAAR_SCALE_IMAGE表示不是缩放分类器来检测，而是缩放图像，Size(30, 30)为目标的
    //最小最大尺寸
    cascade.detectMultiScale( img, faces,
        3, 2, 0
        //|CV_HAAR_FIND_BIGGEST_OBJECT
        //|CV_HAAR_DO_ROUGH_SEARCH
        |CV_HAAR_SCALE_IMAGE
        ,Size(1, 1),Size(180,180));

    t = (double)cvGetTickCount() - t;
    //printf( "detection time = %g ms\n", t/((double)cvGetTickFrequency()*1000.) );

    //在视频中圈出人脸的位置
    for( vector<Rect>::const_iterator r = faces.begin(); r != faces.end(); r++, i++ )
    {

        double aspect_ratio = (double)r->width/r->height;
        if( 0.75 < aspect_ratio && aspect_ratio < 1.3 )
        {
            //标示人脸时在缩小之前的图像上标示，所以这里根据缩放比例换算回去
            center.x = cvRound((r->x + r->width*0.5)*scale);
            //center.y = cvRound((r->y + r->height*0.5)*scale);
            //radius = cvRound((r->width + r->height)*0.25*scale);
            //circle( img, center, radius, color, 3, 8, 0 );
        }
        else
            rectangle( img, cvPoint(cvRound(r->x*scale), cvRound(r->y*scale)),
            cvPoint(cvRound((r->x + r->width-1)*scale), cvRound((r->y + r->height-1)*scale)),
            color, 3, 8, 0);
    }

    //imshow( "detection result", img);
    //waitKey(10);
    
    if(!faces.empty())
    {
        // cout<<"start control gpio"<<endl;
        //cout<<center.x<<endl;
        //cout<<img.cols<<endl;
        //cout<<img.rows<<endl;
        if(center.x>(img.cols*0.5+10))
        {
            cout<<"IN_RIGHT"<<endl;
            return IN_RIGHT;
        }

        else if(center.x<(img.cols*0.5-10))
        {
            cout<<"IN_LEFT"<<endl;
            return IN_LEFT;
        }

        else
        {
            cout<<"IN_CENTER"<<endl;
            return IN_CENTER;
        }

        faces.clear();
    }

    else
    {
        cout<<"NOT_FIND"<<endl;
        return NOT_FIND;
    }
}
