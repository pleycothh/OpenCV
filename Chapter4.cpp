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


// resize
void mian()
{
    // 8 bit is 0-255 pix
    Mat img(512, 512, CV_8UC3, Scalar(255, 0, 0));

    imshow("Image", img);

    waitKey(0);
}