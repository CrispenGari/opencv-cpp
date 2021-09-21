
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
	Mat imageContrastHigh2;
	image.convertTo(imageContrastHigh2, -1, 2, 0); //increase the contrast by 2

	Mat imageContrastHigh4;
	image.convertTo(imageContrastHigh4, -1, 4, 0); //increase the contrast by 4

	Mat imageContrastLow0_5;
	image.convertTo(imageContrastLow0_5, -1, 0.5, 0); //decrease the contrast by 0.5

	Mat imageContrastLow0_25;
	image.convertTo(imageContrastLow0_25, -1, 0.25, 0); //decrease the contrast by 0.25
	imshow("Original image", image);
	imshow("image Contrast +2", imageContrastHigh2);
	imshow("image Contrast +4", imageContrastHigh4);
	imshow("image Contrast decrease by .5", imageContrastLow0_5);
	imshow("image Contrast decrease by .25", imageContrastLow0_25);

	waitKey(0);
	destroyAllWindows();
	return 0;
}