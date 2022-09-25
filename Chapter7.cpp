



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


void getContours(Mat imgDil, Mat img) 
{
    vector<vector<Point>> contours;

    vector<Vec4i> hierarchy;

    // open cv function
    findContours(imgDil, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

    // -1 is all of them

    /// remove noize

    vector<vector<Point>> conPoly(contours.size());
    vector<Rect> boundRect (contours.size());
    string objType;

    for (int i = 0; i < contours.size(); i++)
    {

        int area = contourArea(contours[i]);

        // contours with only coner poins

        cout << area << endl;

        if (area > 1000)
        {

            float peri = arcLength(contours[i], true);

            approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true); // what is peri??


            cout << conPoly[i].size() << endl;

            boundRect[i] = boundingRect(conPoly[i]);


            int objCor = (int)conPoly[i].size();

            if (objCor == 4)
            {
                float aspRato = (float)boundRect[i].width / (float)boundRect[i].height;

                cout << "Asp Ratio: " << aspRato << endl;
                if (aspRato > 0.9 && aspRato < 1.1) { objType = "Square"; }
                else{ objType = "Rect"; }
                
            }
            if (objCor > 4) { objType = "Circle"; }
            if (objCor < 4) { objType = "Tri"; }

            
            drawContours(img, conPoly, i, Scalar(255, 0, 255), 2);
            rectangle(img, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 255, 0));
            putText(img, objType, { boundRect[i].x, boundRect[i].y - 5 }, FONT_HERSHEY_DUPLEX, 0.5, Scalar(0, 0, 0));

        }
    }
}


// Detct Shapes/ contour detion
void Shap()
{
    string path = "Resources/shapes.png";
    Mat img = imread(path);
    Mat imgGray, imgBlur ,imgCanny, imgDil, imgErode;


    // Preprocessing:
    cvtColor(img, imgGray, COLOR_BGR2GRAY);
    GaussianBlur(imgGray, imgBlur, Size(3, 3), 3, 0);

    Canny(imgBlur, imgCanny, 25, 75);

    Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
    
    dilate(imgCanny, imgDil, kernel);

    getContours(imgDil, img);


    imshow("Image", img);
  //  imshow("ImageGray", imgGray);
  //  imshow("ImageBlur", imgBlur);
  //  imshow("ImageCany", imgCanny);
  //  imshow("ImageDil", imgDil);

    waitKey(0);
 

}
