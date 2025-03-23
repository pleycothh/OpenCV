#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;

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


// Draw
void Draw()
{
    // 8 bit is 0-255 pix
    Mat img(512, 512, CV_8UC3, Scalar(255, 255, 255));

    // thickness 5, OR FILLED
    circle(img, Point(256, 256), 155, Scalar(0, 69, 255), FILLED);

    rectangle(img, Point(130, 226), Point(382, 286), Scalar(255, 255, 255), FILLED);

    line(img, Point(130, 296), Point(382, 296), Scalar(255, 255, 255), 2);

    putText(img, "Ben's Project", Point(137, 262), FONT_HERSHEY_DUPLEX, 0.75, Scalar(0, 69, 255), 1);



    imshow("Image", img);

    waitKey(0);
}