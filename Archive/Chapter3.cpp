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
void Resize()
{
    string path = "Resources/test.png";
    Mat img = imread(path);
    Mat imgResize, imgCrop;

    //cout << img.size()<<endl;
    //resize(img, imgResize, Size(640,480));
    resize(img, imgResize, Size(), 0.5,0.5);
    

    // rec, start point is 100, 100, then go 300 right, 250 downward
    Rect roi(100, 100, 300, 250);
    imgCrop = img(roi);

    
    imshow("Image", imgCrop);

    waitKey(0);
}