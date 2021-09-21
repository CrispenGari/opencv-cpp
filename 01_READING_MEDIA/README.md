# Reading and Writing Images and Videos

This section will cover the basic of reading and writing images and videos using opencv in C++.

## Project Stucture

- All the images will be located in the `images` folder
- All the videos will be located in the `videos` folder
- Images that will be recorded will be located in the `output/images` folder.
- All of these folders are in this repository.

## Reading an Image from a local Files

The following function will be observed in the code that follows:

- empty()
  - Check if the image is not available and loaded correctly
- imread(window_name, src)
  - For reading an image
- waitKey(delay)
  - keeps the window mounted and display the image

> The following code will read the `avatar.png` file that is in the `images` folder and display it on the screen.

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
		cout << "Image Can Not Be Empty" << endl;
		exit(0);
	}
	imshow("Image", image);
	waitKey(0);
	cvDestroyAllWindows();
	return 0;
}
```

## Reading a Video from a Local File

The following functions will be observed in the code that follows

- cap(path)
  - This function reads or capture the video from the specified path.
- isOpened
  - returns true or false, it checks weather the cap is open or not.
- read(frame)
  - This function reads the video that is captured by the cap object into the frame.
- get(CAP_PROP_FPS)
  - This is used to get frame per second and it returns a number.
- waitKey(delay)
  - keeps the window mounted and display the image

```
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
using namespace cv;
using namespace std;
int main(){
	VideoCapture cap("videos/8.mp4");
    if (cap.isOpened()) {
		try {
			//get the frames rate of the video
			double fps = cap.get(CAP_PROP_FPS);
			while (true) {
				Mat frame;
				if (cap.read(frame)) {
					imshow("Video", frame);
				}
				else {
					break;
				}
				if (waitKey(int(1000/fps)) == 27 ) {
					// wait for the escape key
					break;
				}
				else {
					continue;
				}
			}
		}
		catch (...) {
			cout << "An Error Occured while trying to play the Video" << endl;
			exit(-1);
		}
	}
	else {
		cout << "Failed to open the video. Make sure that the file path is correct!" << endl;
	}
	return 0;
```

> In order to play the video with it's normal rate then we should divide the 1000ms by the Frame per Second and pass it as an argument to the waitKey() function as an integer. The code that does that is as follows:

```
if (waitKey(int(1000/fps)) == 27 ) {
    // wait for the escape key
    break;
}
```

> Note that the video will play with no sound.

## Reading a Video from a webcam

The only difference between reading the video from the webcam and from a local file is the input of the `cap()`. In order to read the video from a webcam we should pass `0` to the cap function. The other difference is the `waitKey(delay)` we should pass a wait key delay of `1ms` in order to capture the video in real time.

```
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
using namespace cv;
using namespace std;
int main(){
	VideoCapture cap(0);
	if (cap.isOpened()) {
		try {
			while (true) {
				Mat frame;
				if (cap.read(frame)) {
					imshow("Video", frame);
				}else {
					break;
				}if (waitKey(1) == 27 ) {
					// wait for the escape key
					break;
				}else {

					continue;
				}
			}
		}catch (...) {
			cout << "An Error Occured while trying to play the Video" << endl;
			exit(-1);
		}
	}
	else {
		cout << "Failed to open the video. Make sure that the file path is correct!" << endl;
	}
	return 0;
}
```

> The code above will read a video and display it in real time from a webcam.

## Saving Image From a Local File to a Local File

> In this example we will read an image and convert it to grayscale. And then we will write save it in the folder called `output/images` with a filename called `gray.png`

```
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
using namespace cv;
using namespace std;
int main(){
	// Read the image in gray scale
	Mat image = imread("images/avatar.jpg", 0);
	try {
		if (image.empty()) {
			throw "Can not find the image. Make sure the path is correctly set!";
		}else {
			imshow("Image Gray", image);
			try {
				imwrite("output/images/gray.png", image);cout << "The image was saved" << endl;
			}catch (...) {
				cout << "Unable to save the image" << endl;
			}
			int key = waitKey(0);
			if (key == 27) {
				destroyAllWindows();
			}
		}
	}catch (string e) {
		cout << e << endl;
	}
	return 0;
}
```

## Writing an Image From Webcam to the Local File

> We want to make this more funny by listening to keyboard event's. We want to say if the user clicks the space on the keyboard then we save the image in the folder `output/images` with the file name `capture.png`. So we are going to use the video capture and modify our code a little bit. For the keys number that correspond to the key you want can be found [Here](https://progtpoint.blogspot.com/2017/06/key-board-ascii-key-code.html)

```
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
using namespace cv;
using namespace std;
int main(){
	VideoCapture cap(0);
	try {
		if (cap.isOpened()) {
			try {
				while (1) {
					Mat frame;
					if (cap.read(frame)) {
						imshow("Take A Photo", frame);
						int key = waitKey(1);
						if (key == 32) {
							// Take a photo
							imwrite("output/images/capture.png", frame);
							cout << "A Photo Has been Captured" << endl;
						}else if(key == 113){
							// when q is clicked close all windows
							cap.release();
							destroyAllWindows();
							break;
						}else {
							continue;
						}
					}else {
						throw "An Error has occured while trying to read the frame";
					}
				}
			}catch (string e) {

				cout << e << endl;
			}
		}else {
			throw "Enable to open the Camera!";
		}
	}catch (string e) {
		cout << e << endl;
	}
	return 0;
}

```

## Recording a Video from a WebCam

We will be introduced to the following new functions

- frame_size(frame_width, frame_height)
  - a variable that will set the frame size of the output video to the frame size of the webcam
- outVidObject(..args..)
  - Opens the stream for writting videos
- outVidObject.write(frame);
  create a single video from multiple frames

> We want to record a video and save it in the folder `output/videos` with the file name `recording.avi` when the user clicks the space button. If the the video is recording on the space button click then it will stop recording otherwise it will start recording.

```
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
using namespace cv;
using namespace std;
int main(){
	VideoCapture cap(0);
	// Get the Frame Dimensions
	int frame_width = static_cast<int>(cap.get(CAP_PROP_FRAME_WIDTH));
	int frame_height = static_cast<int>(cap.get(CAP_PROP_FRAME_HEIGHT));

	// Create the frame_size variable
	Size frame_size(frame_width, frame_height);
	int frames_per_second = 1;
	VideoWriter outVidObject("output/videos/recording.avi", VideoWriter::fourcc('M', 'J', 'P', 'G'), frames_per_second, frame_size, true);

	// Create a boolean record that track the click of the spacekey for recording and stop recording
	bool record = false;
	try {
		if (outVidObject.isOpened()) {
			try {
				if (cap.isOpened()) {
					try {
						while (1) {
							Mat frame;
							if (cap.read(frame)) {
								imshow("Record A Video", frame);
								int key = waitKey(1);
								if (key == 32) {
									record = !record;
									record &&  cout << "Recording started..." || cout<<"Record Stoped Video Saved";
								}else if (key == 113) {
									// when q is clicked close all windows
									cap.release();
									destroyAllWindows();
									break;
								}else {
									continue;
								}
								// Start recording the video
								outVidObject.write(frame);
							}else {
								throw "An Error has occured while trying to read the frame";
							}
						}
					}catch (string e) {

						cout << e << endl;
					}
				}else {
					throw "Enable to open the Camera!";
				}
			}catch (const char* e) {
				cout << e << endl;
			}
		}else {
			cout<< "Failed to create a video output object";
		}
	}catch (const char* e) {
		cout << e << endl;
   }

	return 0;
}
```

That's all next we need want to learn how to change the brightness and contrast of images and videos.

## Documentation Reference

- [Documentation](https://www.opencv-srf.com/2017/12/play-video-from-file-or-camera.html)

## Credits

- [Stackoverflow](https://stackoverflow.com/)
