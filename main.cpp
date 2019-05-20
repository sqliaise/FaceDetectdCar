#include <include/main.hpp>

using namespace cv;
using namespace std;
int main()
{
    int ctrl_car_cmd;
    void *faces;
    Mat frame;
    CascadeClassifier cascade;
    cascade.load("init/haarcascade_frontalface_alt.xml");//训练好的文件
    VideoCapture video(0);    //打开默认摄像头
    if(!video.isOpened())
    {
        printf("Open Camera Error!\n");
        return -1;
    }
    pwm_config(6000000, 300000);
    pwm_enable(1);
    while(1)
    {
        video >> frame;
        frame = frame_handle(frame);
        ctrl_car_cmd = detectAndDraw(frame, cascade);
        ctrl_car(ctrl_car_cmd);
        //waitKey(1);
    }
}
