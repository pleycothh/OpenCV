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

float w = 250, h = 350;
Mat matrix, imgWarp;
// warp
void warp()
{

    string path = "Resources/cards.jpg";
    Mat img = imread(path);

    // top left, top right, butom left, buttom right
    Point2f src[4] = { {529,142}, {771, 190}, {405, 395}, {674, 457} };
    Point2f dst[4] = { {0.0f,0.0f}, {w, 0.0f}, {0.0f, h}, {w, h} };
    
    // transform matrix
    matrix = getPerspectiveTransform(src, dst);

    // apply matrix to img, with size
    warpPerspective(img, imgWarp, matrix, Point(w, h));


    for (int i = 0; i < 4; i++)
    {
        circle(img, Point(src[i]), 5, Scalar(0, 0, 255), FILLED);

    }
    
    imshow("Image", img);
    imshow("ImageW", imgWarp);
    waitKey(0);
}