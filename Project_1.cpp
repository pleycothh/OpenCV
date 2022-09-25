#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>


using namespace cv;
using namespace std;



vector<vector<int>> myColors {{0,49,106,213,255,255},{57,86,85,227,75,176}}; // orange; green

// orage: 0,49,106,213,255,255
//green?: 57,86,85,227,75,176

vector<Scalar> myColorValues{ {255,0,255},{0,255,0} }; // pupor ; green

void findColor(Mat img)
{

    Mat imgHSV;

    cvtColor(img, imgHSV, COLOR_BGR2HSV);

    for (int i = 0; i < myColors.size(); i++)
    {
        Scalar lower(myColors[i][0], myColors[i][1], myColors[i][2]);
        Scalar upper(myColors[i][3], myColors[i][4], myColors[i][5]);
        
        Mat mask;
        inRange(imgHSV, lower, upper, mask); // mask per color
        
        imshow(to_string(i), mask);
    }

}


// virtural pointer
void main()
{

    VideoCapture cap(0);
    Mat img;

    while (true) {
        cap.read(img);
        
        findColor(img);
        
        imshow("video", img);
        waitKey(20);

    }


}