# Add Trackbar

- Trackbars are very useful in lots of occasions. It enables users to change various parameters while the OpenCV application is running.
- Whenever you change the position of a trackbar, the value of an integer variable is changed. Using that value, we can change a property of an image or a video.

## Example 1:

- Creating and getting the trackbar values
  - In this example we are going to create two track and use the `cvGetTrackbarPos(trackbarName, windowName)` method to get the values of each track bar position.
  - This can be done as follows:

```
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
using namespace cv;
using namespace std;
int main()
{
	// Create a named window
	namedWindow("Brightness and Contrast", 1);

	int value1 = 50, value2 = 50;
	// Create trackbars
	createTrackbar("Brightness", "Brightness and Contrast", &value1, 100);
	createTrackbar("Contrast", "Brightness and Contrast", &value2, 100);
	while (true) {
		int brightness = cvGetTrackbarPos("Brightness", "Brightness and Contrast");
		int contrast = cvGetTrackbarPos("Contrast", "Brightness and Contrast");

		cout << "Brightness: " << brightness << endl;
		cout << "Contrast: " << contrast << endl;
		int key = waitKey(1);
		if (key == 27) {
			break;
		}
	}
	cvDestroyAllWindows();
	return 0;
}
```

- The above example helps us to grab the values of track bars in real time.

## Example 2

- In this one we want to change the brightness and contrast of the image `avatar.jpg` which is located in `images` directory.
  - read an image
  - create a named window
  - create track bars
    - The `int createTrackbar(const string& trackbarname, const string& winname, int* value, int count, TrackbarCallback onChange = 0, void* userdata = 0)` method
      - **trackbarname** - The name of the trackbar _**this name is very important especially when we want to track the position of the trackbar**_
      - **winname** - The name of the window to which the trackbar is attached to
      - **value** - This integer, pointed by this pointer, holds the value associated with the position of the trackbar
      - **count** - The maximum value of the trackbar. The minimum value is always zero.
      - **onChange** - This function will be called everytime the position of the trackbar is changed. The prototype of this function should be `"FunctionName(int, void_)"`. The "int" value is the value associate with the position of the trackbar. And "void\*" is any pointer value which you pass as the "userdata".
      - **userdata** - This pointer variable will be passed as the second parameter of the above function

* We will modify our code from the previous example

```
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
	// Create a named window
	namedWindow("Brightness and Contrast", 1);

	int value1 = 50, value2 = 50;
	// Create trackbars
	createTrackbar("Brightness", "Brightness and Contrast", &value1, 100);
	createTrackbar("Contrast", "Brightness and Contrast", &value2, 100);
	while (true) {
		int brightness = cvGetTrackbarPos("Brightness", "Brightness and Contrast");
		int contrast = cvGetTrackbarPos("Contrast", "Brightness and Contrast");

		Mat outputImage;
		image.convertTo(outputImage, -1, contrast, brightness);
		// Display the image on the same window with the trackbars
		imshow("Brightness and Contrast", outputImage);
		int key = waitKey(1);
		if (key == 27) {
			break;
		}
	}
	cvDestroyAllWindows();
	return 0;
}
```

### Output

<div align="center">
<img alt="output-image" src="https://github.com/CrispenGari/Adding-And-Tracking-Track-Bars/blob/main/bandicam%202021-03-15%2010-27-32-900.jpg">
</div>

## Trackbar with Callback Function

- In the above example, we have used only 4 parameters for the `createTrackbar` function. But there are 2 more parameters.
- Here we am going to explain, how to use a callback function using the 5th and 6th parameters of "createTrackbar".
- The advantage of using the callback function is that it is not required to iterate in a while loop periodically as in the above example.

## Example 3:

- In this example, we have added two trackbars to change the brightness and contrast of an image. And a callback function is implemented for each trackbar.
- We are going to modify our code and make it look as follows:

```
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
```

### Output

<div align="center">
<img alt="output-image" src="https://github.com/CrispenGari/Adding-And-Tracking-Track-Bars/blob/main/bandicam%202021-03-15%2010-41-07-366.jpg">
</div>
That's all on the next section we will look at the Mouse Events

## Documentation Reference

- [Documentation](https://www.opencv-srf.com/2017/12/play-video-from-file-or-camera.html)

## Credits

- [Stackoverflow](https://stackoverflow.com/)
