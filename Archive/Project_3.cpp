
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <opencv2/objdetect.hpp>


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

void main()
{
    VideoCapture cap(0);
    Mat img;

    CascadeClassifier plateCascade;
    plateCascade.load("Resources/haarcascade_russian_plate_number.xml");

    if (plateCascade.empty()) { cout << "xml file not loaded" << endl; }

    vector<Rect> plates;

    while (true) 
    {
        cap.read(img);

        plateCascade.detectMultiScale(img, plates, 1.1, 10);

        for (int i = 0; i < plates.size(); i++)
        {
            Mat imgCrop = img(plates[i]);
            imshow(to_string(i), imgCrop);

            rectangle(img, plates[i].tl(), plates[i].br(), Scalar(255, 0, 255), 3);
        }

        imshow("Image", img);
        waitKey(1);

    }


}