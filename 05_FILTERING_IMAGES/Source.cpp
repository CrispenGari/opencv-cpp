#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
using namespace cv;
using namespace std;
int main() {

    //display the original image
    IplImage* image = cvLoadImage("images/avatar.jpg");
    cvNamedWindow("MyWindow");
    cvShowImage("MyWindow", image);

    //invert and display the inverted image
    cvNot(image, image);
    cvNamedWindow("Inverted");
    cvShowImage("Inverted",image);

    cvWaitKey(0);

    //cleaning up
    cvDestroyWindow("MyWindow");
    cvDestroyWindow("Inverted");
    cvReleaseImage(&image);
	return 0;
}