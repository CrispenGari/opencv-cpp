#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
using namespace cv;
using namespace std;
int main()
{
	Mat image = imread("images/avatar.jpg");
	if (image.empty()) {
		return -1;
	}
	Mat imageDilate5x5, imageDilate3x3;

	dilate(image, imageDilate3x3, getStructuringElement(MORPH_RECT, Size(3, 3)));
	dilate(image, imageDilate5x5, getStructuringElement(MORPH_RECT, Size(5, 5)));
	imshow("Original Image", image);
	imshow("imageDilate3x3", imageDilate3x3);
	imshow("imageDilate5x5", imageDilate5x5);
	waitKey(0);
	cvDestroyAllWindows();
	return 0;
}