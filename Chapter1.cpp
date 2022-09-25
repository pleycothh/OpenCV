#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;


/// <summary>
/// Importing Images
/// </summary>
void Image() 
{
    string path = "Resources/test.png";

    /// read image from opencv type
    Mat img = imread(path);
    imshow("Image", img);
    waitKey(0);

}

void video() 
{
   // string path = "Resources/test_video.mp4";
    VideoCapture video (0);
    Mat img;

    while (true) {
        video.read(img);
        imshow("video", img);
        waitKey(20);

    }


}