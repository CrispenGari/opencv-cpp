# Change Brightness and Contrast Of Image Frames

## 1. Changing Brightness

Changing brightness of an image is a commonly used point operation. In this operation, the value of each and every pixels in an image should be increased/decreased by a constant. To change the brightness of a video, the same operation should be performed on each frame in the video.

If you want to increase the brightness of an image, you have to add some positive constant value to each and every pixel in the image else you subtract that's it.

> Syntax: `convertTo( OutputArray m, int rtype, double alpha=1, double beta=0)`;

- **m** - Output image. This data structure will be reallocated if required.

- **rtype** - Type of the output image. If rtype is a negative value, the type of the output image will be same as the input image.

- **alpha** - Each pixels in the input image will be multiplied by this number before assigning to the output image.

- **beta** - This value will be added to each pixels in the input image and assigned to the output image.

#### 1. Change the Brightness of an Image

> Example 1: of changing brightness of an Image Frame

- Suppose we want to change the brightness of our image `avatar.jpg` and increase it's brightness by `50` we can do that as follows, Simillarily when we want to reduce the brightness by `100`, of the image frame all we need to do is to subtract a certain value.

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

	Mat imageBrighnessHigh50;
	image.convertTo(imageBrighnessHigh50, -1, 1, 50); //increase the brightness by 50

	Mat imageBrighnessHigh100;
	image.convertTo(imageBrighnessHigh100, -1, 1, 100); //increase the brightness by 100

	Mat imageBrighnessLow50;
	image.convertTo(imageBrighnessLow50, -1, 1, -50); //decrease the brightness by 50

	Mat imageBrighnessLow100;
	image.convertTo(imageBrighnessLow100, -1, 1, -100); //decrease the brightness by 100
	if (image.empty()) {
		return -1;
	}
	imshow("Original Image", image);
	imshow("Image +50", imageBrighnessHigh50);
	imshow("+100 Image", imageBrighnessHigh100);
	imshow("-50 Image", imageBrighnessLow50);
	imshow("-100 Image", imageBrighnessLow100);
	waitKey(0);
	destroyAllWindows();
	return 0;
}
```

> Practical Example

We want to create a program that listen to the user click on the up and down keys if the user presses the up button the brightness of the image should be increased otherwise the brightness of the image should be reduced.

```


#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
using namespace cv;
using namespace std;
int main(){
	Mat image = imread("images/avatar.jpg");
	if (image.empty()) {
		return -1;
	}
	while (true) {
		imshow("Original Image", image);

		int key = waitKey(0);
		if (key == 112) {
			// add brightness 'P' is clicked
			cout << key;
			image.convertTo(image, -1, 1, 50);
		}
		else if (key == 109) {
			// reduce brightness 'M' is clicked
			image.convertTo(image, -1, 1, -50);
			cout << key;
		}
		else if (key == 27) {
			// esc
			goto exit1;
		}
		else {
			continue;
		}
	}
exit1:
	destroyAllWindows();
	return 0;
}

```

#### 2. Change the Brightness of a Video

The method is simmilar to the change of brightness on an image frame.

> Example

```


#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
using namespace cv;
using namespace std;
int main()
{
	VideoCapture cap("videos/8.mp4");
	if (cap.isOpened() != true) {
		return -1;
	}
	double fps = cap.get(CAP_PROP_FPS);
	while (cap.isOpened()) {
		Mat frame;
		if (cap.read(frame)) {
			imshow("Video", frame);

			Mat frameBrighnessHigh50;
			frame.convertTo(frameBrighnessHigh50, -1, 1, 50); //increase the brightness by 50

			Mat frameBrighnessHigh100;
			frame.convertTo(frameBrighnessHigh100, -1, 1, 100); //increase the brightness by 100

			Mat frameBrighnessLow50;
			frame.convertTo(frameBrighnessLow50, -1, 1, -50); //decrease the brightness by 50

			Mat frameBrighnessLow100;
			frame.convertTo(frameBrighnessLow100, -1, 1, -100); //decrease the brightness by 100
			imshow("Original Frame", frame);
			imshow("Frame +50", frameBrighnessHigh50);
			imshow("+100 Frame", frameBrighnessHigh100);
			imshow("-50 Frame", frameBrighnessLow50);
			imshow("-100 Frame", frameBrighnessLow100);
		}
		else {
			return -100;
		}

		if (waitKey(int(1000/fps)) == 27){
			goto stop;
		}
		else {
			continue;
		}
	}
stop:
	cap.release();
		destroyAllWindows();
	return 0;
}

```

## 2. Change Contrast Image and Video Frames

Changing contrast of an image is also a commonly used point operation. In this operation, the value of each and every pixels in an image should be multiplied by a positive constant which is not equal to one. To change the contrast of a video, the same operation should be performed on each frame in the video.

- In order to decrease the contrast of an image, each and every pixel in the image should be multiplied by a positive constant smaller that one.

- In order to increase the contrast of an image, each and every pixel in the image should be multiplied by a positive constant larger that one.

#### 1. Change the Contrast of an Image Frame

> Example

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

```

#### 2. Change the Contrast of a Video

Now we are going to show you how to increase and decrease the contrast of a video using an OpenCV C++ example. This is similar to the previous example.

> Example:

```


#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
using namespace cv;
using namespace std;
int main()
{
	VideoCapture cap("videos/8.mp4");
	if (cap.isOpened() != true) {
		return -1;
	}
	double fps = cap.get(CAP_PROP_FPS);
	while (cap.isOpened()) {
		Mat frame;
		if (cap.read(frame)) {
			imshow("Video", frame);

			Mat frameContrastHigh2;
			frame.convertTo(frameContrastHigh2, -1, 2, 0); //increase the contrast by 2

			Mat frameContrastHigh4;
			frame.convertTo(frameContrastHigh4, -1, 4, 0); //increase the contrast by 4

			Mat frameContrastLow0_5;
			frame.convertTo(frameContrastLow0_5, -1, 0.5, 0); //decrease the contrast by 0.5

			Mat frameContrastLow0_25;
			frame.convertTo(frameContrastLow0_25, -1, 0.25, 0); //decrease the contrast by 0.25
			imshow("Original Frame", frame);
			imshow("Frame Contrast +2", frameContrastHigh2);
			imshow("Frame Contrast +4", frameContrastHigh4);
			imshow("Frame Contrast decrease by .5", frameContrastLow0_5);
			imshow("Frame Contrast decrease by .25", frameContrastLow0_25);
		}
		else {
			return -100;
		}

		if (waitKey(int(1000/fps)) == 27){
			goto stop;
		}
		else {
			continue;
		}
	}
stop:
	cap.release();
		destroyAllWindows();
	return 0;
}

```

That's all on the next section we will look at the Histogram Equalization on images

## Documentation Reference

- [Documentation](https://www.opencv-srf.com/2017/12/play-video-from-file-or-camera.html)

## Credits

- [Stackoverflow](https://stackoverflow.com/)
