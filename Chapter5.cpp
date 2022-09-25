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


// warp
void main()
{

    string path = "Resources/cards.png";

    /// read image from opencv type
    Mat img = imread(path);
    
    
    imshow("Image", img);
    waitKey(0);
}