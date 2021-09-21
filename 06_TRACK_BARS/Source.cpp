#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
using namespace cv;
using namespace std;
Mat image;
void brightnessCallBack(int value, void* userData)
{
	Mat outputImage;
	int contrastValue = *(static_cast<int*>(userData));

	//Calculating brightness and contrast value
	int iBrightness = value - 50;
	double dContrast = contrastValue / 50.0;

	//adjust the brightness and contrast
	image.convertTo(outputImage, -1, dContrast, iBrightness);

	//show the brightness and contrast adjusted image
	imshow("My Window", outputImage);
}
void contrastCallBack(int value, void* userData)
{
	Mat outputImage;
	int brightnessValue = *(static_cast<int*>(userData));

	//Calculating brightness and contrast value
	int iBrightness = brightnessValue - 50;
	double dContrast = value / 50.0;
	//adjust the brightness and contrast
	image.convertTo(outputImage, -1, dContrast, iBrightness);

	//show the brightness and contrast adjusted image
	imshow("My Window",outputImage);
}
int main()
{
	image = imread("images/avatar.jpg");
	if (image.empty()) {
		return -1;
	}
	// Create a named window
	namedWindow("Brightness and Contrast", 1);

	int value1 = 50, value2 = 50;
	// Create trackbars
	createTrackbar("Brightness", "Brightness and Contrast", &value1, 100, brightnessCallBack, &value2);
	createTrackbar("Contrast", "Brightness and Contrast", &value2, 100, contrastCallBack, &value1);
	
	imshow("Brightness and Contrast", image); 
	int key = waitKey(0);
	if (key == 27) {
	cvDestroyAllWindows();
	}
	
	
	return 0;
}