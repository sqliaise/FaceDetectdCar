#ifndef DETECT_HPP_INCLUDED
#define DETECT_HPP_INCLUDED

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/objdetect/objdetect.hpp>

#define IN_RIGHT  0
#define IN_LEFT   1
#define IN_CENTER 2
#define NOT_FIND  3

using namespace cv;
int detectAndDraw(Mat &, CascadeClassifier &);

#endif // DETECT_HPP_INCLUDED
