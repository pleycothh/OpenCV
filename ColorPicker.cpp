#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;


/*project: out of focuse, AI shalow depth of fouces
*
* 1. use ai to find the human
* 2. defin the edge
* 3. define the depth
* 4. apply the blur
*/

/*
AI remove object from picture:
auto drow the missing part
*/


Mat imgHSV, mask;
int hmin = 0, smin = 0, vmin = 0;
int  hmax = 255, smax = 255, vmax = 255;

VideoCapture cap(0);
Mat img;

//Color detextion
void main2()
{
    //string path = "Resources/lambo.png";
    


    namedWindow("Trackbars", (640, 200));
    // create trackbar called hum min, insted the window trackbars, with hmin as reference value, as start point.
    createTrackbar("Hue Min", "Trackbars", &hmin, 179);
    createTrackbar("Hue Max", "Trackbars", &hmax, 179);
    createTrackbar("Sat Min", "Trackbars", &smin, 255);
    createTrackbar("Sat Max", "Trackbars", &smax, 255);
    createTrackbar("Val Min", "Trackbars", &vmin, 255);
    createTrackbar("Val Max", "Trackbars", &vmax, 255);



    while (true)
    {
        cap.read(img);
        
        cvtColor(img, imgHSV, COLOR_BGR2HSV);

        Scalar lower(hmin, smin, vmin);
        Scalar upper(hmax, smax, vmax);

        inRange(imgHSV, lower, upper, mask);

        //imshow("Image", img);
        ///imshow("Image HSV", imgHSV);
        imshow("Image Mask", mask);
        waitKey(1);

    }

}
