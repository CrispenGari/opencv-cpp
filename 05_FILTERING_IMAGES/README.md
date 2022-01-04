# Filter Images or Videos in OpenCV C++

The image filtering is a neighborhood operation in which the value of any given pixel in the output image is determined by applying a certain algorithm to the pixel values ​​in the vicinity of the corresponding input pixel. This technique is commonly used to:

- smooth
- sharpen
- detect edges of images and videos.

Let's defines some terms used when discussing image filtering techniques

#### 1. kernel

- Kernel is a matrix with an odd height and an odd width.
- It is also known as convolution matrix, mask or filter. Kernels are named based on their value distribution.
- Kernel is used to define a neighborhood of a pixel in a image filtering operation.
- Some of the popular kernels are:
  - Normalized box filter
  - Gaussian kernel
  - Laplacian kernel
  - edge detecting kernels
  - etc.
- Kernels can be defined with different sizes. But large kernels result in a large processing time.

#### 2. convolution

Convolution is a mathematical operation performed on images by sliding a kernel across the whole image and calculating new values for each pixels based on the value of the kernel and the value of overlapping pixels of original image.

## Smooth / Blur Images

When an image is acquired by a camera or other method, the image may be corrupted by random dots and noises. Smoothing/blurring is one of image processing techniques to eliminate such imperfections and improve the image. Image smoothing techniques can be applied even for each frames of a video to eliminate imperfections and improve the video.

### 1. Homogeneous Blur

Homogeneous Blur is the most simplest method of smoothing an image. It is also called as Homogeneous Smoothing, Homogeneous Filtering and Box Blurring. In this technique, each pixel value is calculated as the average value of the neighborhood of the pixel defined by the kernel.

> Example

We want to blur/smooth an image with OpenCV with.We are going to illustrate this using 2 kernel sizes `3 x 3` and `5 x 5` kernel for this example program.

```c++
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
using namespace cv;
using namespace std;
int main() {
	Mat image = imread("images/avatar.jpg");
	if (image.empty()) {
		return -1;
	}
	Mat image3x3KernelBlur, image5x5KernelBlur;

	blur(image, image3x3KernelBlur, Size(3, 3));
	blur(image, image5x5KernelBlur, Size(5, 5));
	imshow("Original image", image);
	imshow("image3x3KernelBlur", image3x3KernelBlur);
	imshow("image5x5KernelBlur", image5x5KernelBlur);
	waitKey(0);
	destroyAllWindows();
	return 0;
}
```

### 2. Gaussian Blur

Gaussian blur/smoothing is the most commonly used smoothing technique to eliminate noises in images and videos. In this technique, an image should be convolved with a Gaussian kernel to produce the smoothed image.

You may define the size of the kernel according to your requirement. But the standard deviation of the Gaussian distribution in X and Y direction should be chosen carefully considering the size of the kernel such that the edges of the kernel is close to zero.
OpenCV has an in-built function to perform Gaussian blur/smoothing on images easily. All you have to specify is the size of the Gaussian kernel with which your image should be convolved.

> Example:

```c++
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
using namespace cv;
using namespace std;
int main() {
	Mat image = imread("images/avatar.jpg");
	if (image.empty()) {
		return -1;
	}
	Mat image3x3KernelGaussianBlurBlur, image5x5KernelGaussianBlurBlur;

	GaussianBlur(image, image3x3KernelGaussianBlurBlur, Size(3, 3), 0);
	GaussianBlur(image, image5x5KernelGaussianBlurBlur, Size(5, 5), 0);
	imshow("Original image", image);
	imshow("image3x3KernelGaussianBlurBlu", image3x3KernelGaussianBlurBlur);
	imshow("image5x5KernelGaussianBlurBlur", image5x5KernelGaussianBlurBlur);
	waitKey(0);
	destroyAllWindows();
	return 0;
}
```

### Invert Images

Inverting an image is like taking the negative of an image.

```c++
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
```

That's all on the next section we will look at the Morphological Operations on images and videos.

## Documentation Reference

- [Documentation](https://www.opencv-srf.com/2017/12/play-video-from-file-or-camera.html)

## Credits

- [Stackoverflow](https://stackoverflow.com/)
