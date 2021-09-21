#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
using namespace cv;
using namespace std;

void mouseCallBack(int event, int x, int y, int flags, void* userdata) {
	if (flags == EVENT_FLAG_ALTKEY) {
		cout << "YOU HAVE PRESSED ALT KEY" << endl;
	}
	else if (flags == EVENT_FLAG_CTRLKEY) {
		cout << "YOU HAVE PRESSED CTRL KEY" << endl;
	}
	else if (flags == EVENT_FLAG_SHIFTKEY) {
		cout << "YOU HAVE PRESSED SHIFT KEY" << endl;
	}
	else if (flags == EVENT_FLAG_CTRLKEY + int('c')) {
		cout << "YOU HAVE PRESSED CTRLKEY + C KEYS" << endl;
	}
	else if (flags == EVENT_FLAG_SHIFTKEY + EVENT_FLAG_CTRLKEY) {
		cout << "YOU HAVE PRESSED SHIFT KEY + CTRLKEY " << endl;
	}
	else {

	}
}
int main()
{
	Mat image = imread("images/avatar.jpg");
	if (image.empty()) {
		cout << "Image Can Not Be Empty" << endl;
		exit(0);
	}
	imshow("Image", image);
	setMouseCallback("Image", mouseCallBack, NULL);
	
	waitKey(0);
	cvDestroyAllWindows();
	return 0;
}