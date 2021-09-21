# Morphological Operations

- Erode Images or Videos
- Dilate Images or Videos

### 1. Erode Images

Erosion is a fundamental morphological operation in image processing. As the name implies, this operation erodes foreground pixels in an image at their boundaries. After this erosion operation is performed, objects in an image becomes smaller where as the holes within the object (if any) becomes larger.

In this technique, each pixel value of the resultant image is calculated as the minimum value of the neighborhood of the pixel defined by the kernel. For color images, each color plane is processed independently.

> Example:
> In this example we will erode the images and display them with two different kernel sizes, `5x5` and `3x3`.

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
	Mat imageErosion3x3, imageErosion5x5;

	erode(image, imageErosion3x3, getStructuringElement(MORPH_RECT, Size(3, 3)));
	erode(image, imageErosion5x5, getStructuringElement(MORPH_RECT, Size(5, 5)));
	imshow("Original Image", image);
	imshow("imageErosion3x3", imageErosion3x3);
	imshow("imageErosion5x5", imageErosion5x5);
	waitKey(0);
	cvDestroyAllWindows();
	return 0;
}
```

> `erode()` function erodes the image using the specified kernel which determines the neighborhood of a pixel over which the minimum is taken. `getStructuringElement(MORPH_RECT, Size(3, 3))` function is used to get the rectangular kernel with the size of 3 x 3 for this morphological operation.

### 2. Dilate Images

Dilating is something like opposite of the eroding an image.

> Example.
> In this example we will dilate the images and display them with two different kernel sizes, `5x5` and `3x3`.
> That's all on the next section we will look at the Morphological Operations on images and videos.

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
```

That's all in the next section we will look at Trackbar in openCV

## Documentation Reference

- [Documentation](https://www.opencv-srf.com/2017/12/play-video-from-file-or-camera.html)

## Credits

- [Stackoverflow](https://stackoverflow.com/)

```

```
