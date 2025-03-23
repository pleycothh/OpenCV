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

void Basic()
{
    string path = "Resources/test.png";
    Mat img = imread(path);
    Mat imgGray;
    Mat imgBlur;
    Mat imgCanny, imgDia, imgErode;


    cvtColor(img, imgGray, COLOR_BGR2GRAY);
    GaussianBlur(img, imgBlur, Size(3,3), 3,0);
    // edge detector
    Canny(imgBlur, imgCanny, 50, 150);

    // dilate make canny line thicker
    Mat kernel = getStructuringElement(MORPH_RECT, Size(5, 5));
    dilate(imgCanny, imgDia, kernel);

    // erotion
    erode(imgDia, imgErode, kernel);


    imshow("Image", img);
    imshow("Image Gray", imgErode);
    waitKey(0);
}