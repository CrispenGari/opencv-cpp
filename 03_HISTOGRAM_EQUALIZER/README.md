# Histogram Equalization OpenCV C++

Histogram of an image is the graphical representation of the distribution of intensities of pixels. It provides an estimate of where pixel values are concentrated and whether there are unusual deviations.

- **_Histogram equalization_** is a commonly used technique in image processing to enhance the contrast of an image by equalizing the intensity distribution. It will make a dark image (underexposed) less dark and a bright image (overexposed) less bright.

## 2. Histogram Equalization of an Image

> Example:
> Equalizing the histogram of a `grayscale` image using the OpenCV in-built functions. So from this example will also learn how to convert an image to grayscale using the `cvtColor()` function.

```c++
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

	Mat imgGray;
	Mat histImageGray;

	// Convert the image to grayscale
	cvtColor(image, imgGray, COLOR_BGR2GRAY);
	// apply Histogram equalization on the grayscale
	equalizeHist(imgGray, histImageGray);
	imshow("Original image", image);
	imshow("Gray image", imgGray);
	imshow("Hist Gray image", histImageGray);
	waitKey(0);
	destroyAllWindows();
	return 0;
}
```

> Example:

- In this example, will show you how to equalize the histogram of a color image using simple OpenCV program.

* **Algorithm**
  - Read the image from source
  - Convert the image from BGR to YCrCb color space
  - Split the image into 3 channels; Y, Cr and Cb channels respectively and store it in a `std::vector`
  - Equalize the histogram of only the Y channel
  - Merge 3 channels in the vector to form the color image in YCrCB color space.
  - Convert the histogram equalized image from YCrCb to BGR color space again
  - Display the images

```c++
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
using namespace cv;
using namespace std;
int main()
{
    Mat image = imread("images/avatar.jpg");
    if (image.empty()){
        return -1;
    }

    //Convert the image from BGR to YCrCb color space
    Mat imgYCrCb;
    cvtColor(image, imgYCrCb, COLOR_BGR2YCrCb);

    //Split the image into 3 channels; Y, Cr and Cb channels respectively and store it in a std::vector
    vector<Mat> vec_channels;
    split(imgYCrCb, vec_channels);

    //Equalize the histogram of only the Y channel
    equalizeHist(vec_channels[0], vec_channels[0]);

    //Merge 3 channels in the vector to form the color image in YCrCB color space.
    merge(vec_channels, imgYCrCb);

    //Convert the histogram equalized image from YCrCb to BGR color space again
    cvtColor(imgYCrCb, imgYCrCb, COLOR_YCrCb2BGR);
    imshow("Original Image", image);
    imshow("Hist Image", imgYCrCb);
    waitKey(0);
    destroyAllWindows();

	return 0;
}
```

## 2. Histogram Equalization of a Video with OpenCV

Now we are going to show you how to equalize the histogram of a video using an OpenCV C++ example. This is similar to the previous example.

#### a. On the coloured video

```c++
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
using namespace cv;
using namespace std;
int main()
{
    VideoCapture cap("videos/8.mp4");
    if (cap.isOpened() == false){
        return -1;
    }
    while (cap.isOpened()){
        Mat frame;
        if (cap.read(frame)){
            Mat imageYCrCb;
            cvtColor(frame, imageYCrCb, COLOR_BGR2YCrCb);
            vector<Mat> vec_channels;
            split(imageYCrCb, vec_channels);
            equalizeHist(vec_channels[0], vec_channels[0]);
            merge(vec_channels, imageYCrCb);
            cvtColor(imageYCrCb, imageYCrCb, COLOR_YCrCb2BGR);
            imshow("Original Video", frame);
            imshow("Hist Video", imageYCrCb);
            if (waitKey(10) == 27){ // 1000/fps
                break;
            }
        } else {
            break;
        }
    }
    destroyAllWindows();
    return 0;
}
```

#### b. On the grayscale video

```c++
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
using namespace cv;
using namespace std;
int main()
{
    VideoCapture cap("videos/8.mp4");
    if (cap.isOpened() == false){
        return -1;
    }
    while (cap.isOpened()){
        Mat frame;
        if (cap.read(frame)){
            Mat frameGray, histFrameGray;
            cvtColor(frame, frameGray, COLOR_BGR2GRAY);
            // apply Histogram equalization on the grayscale
            equalizeHist(frameGray, histFrameGray);
            imshow("Original Video", frame);
            imshow("Gray Video", frameGray);
            imshow("HistGray Video", histFrameGray);
            if (waitKey(10) == 27){ // 1000/fps
                break;
            }
        } else {
            break;
        }
    }
    destroyAllWindows();
    return 0;
}
```

That's all on the next section we will look at Filtering Images and Videos

## Documentation Reference

- [Documentation](https://www.opencv-srf.com/2017/12/play-video-from-file-or-camera.html)

## Credits

- [Stackoverflow](https://stackoverflow.com/)
