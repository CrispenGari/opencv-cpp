
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
using namespace cv;
using namespace std;
int main()
{
	Mat image = imread("python2.png");
	if (image.empty()) {
		cout << "Image Can Not Be Empty" << endl;
		exit(0);
	}
	imshow("Image", image);
	waitKey(0);
	cvDestroyAllWindows();
	return 0;
}

