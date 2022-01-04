# OPENCV C++

# 1. SETUP

This first chapter will guide you with the step by step installation and set up `Visual Code 2019` with `opencv` for `C++`.

##### I'm going to use `C` as my default drive in your case you may have drive F, D etc. Just know that instead of `C` you replace with whatever drive you are currently using.

## 1. Installation on Windows

- First we need to download and install Visual Studio [here](https://visualstudio.microsoft.com/vs/older-downloads/) and then download and install opencv [here](https://sourceforge.net/projects/opencvlibrary/files/3.4.13/opencv-3.4.13-vc14_vc15.exe/download). When the installation of Visual Studio is complete copy the `opencv` setup into the `C` drive.

Double click the setup and a folder named `opencv` will be created inside the `C` drive as shown in the image bellow.

<img src="https://github.com/CrispenGari/opencv-cpp/blob/main/00_SETUP/bandicam%202021-02-14%2009-35-28-795.jpg" alt="img" width="100%"/>

Copy the path of the build folder that is inside the folder `opencv` and go to `Environment Variables` Settings under path create a new path and add the following path string

```
C:\opencv\build\x64\vc15\bin
```

Follow the following steps when adding the path to `Environment Variables`

<img src="https://github.com/CrispenGari/opencv-cpp/blob/main/00_SETUP/bandicam%202021-02-14%2009-37-55-934.jpg" alt="img" width="100%"/>

Save the changes and restart your computer.

## 2. Setting the environment in VS 2019.

- Open `Visual Studio 2019` and create a new `C++ Console Application` make sure that you set the system to `x64` as shown in the following image:

<img src="https://github.com/CrispenGari/opencv-cpp/blob/main/00_SETUP/bandicam%202021-02-14%2009-33-26-197.jpg" alt="img" width="100%"/>

- Then right click on the project name (you have entered this name in a previous step) on the solution explorer and then click 'Properties' in the opened context menu to open the Property Pages window.
- Go to `Configuration Property` then `VC++ Directories` then click `Include Directories` and the add the following path to it:

```
C:\opencv\build\include
```

- On the same window click `Library Directories` , edit and add the following path to it:

```
C:\opencv\build\x64\vc15\lib
```

Image:

<img src="https://github.com/CrispenGari/opencv-cpp/blob/main/00_SETUP/bandicam%202021-02-14%2009-34-19-069.jpg" alt="img" width="100%"/>

- Under the Linker settings Select `Input` click `Additional Dependencies` and add the following.

```
opencv_world3413d.lib

```

Image:

<img src="https://github.com/CrispenGari/opencv-cpp/blob/main/00_SETUP/bandicam%202021-02-14%2009-34-52-090.jpg" alt="img" width="100%"/>

- Click `apply` and then `ok`

# 2. Testing if it works

Open a new file and paste the following code and try to run the program. Assuming that we have an image called `python2.png` in the project directory then we want to read and show the image on the screen. This can be done as follows:

```
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
```

## Output:

<img src="https://github.com/CrispenGari/opencv-cpp/blob/main/00_SETUP/bandicam%202021-02-14%2009-22-01-648.jpg" alt="img" width="100%"/>

## C++ OpenCV Tutorial Documentation

- [Opencv-C++](https://www.opencv-srf.com/p/introduction.html)
