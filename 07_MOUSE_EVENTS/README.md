# Mouse Events

- OpenCV supports for detecting mouse events. Mouse events include mouse clicks and movements over an attached OpenCV window.
- It simple to do that. All we have do is to define a callback function in the OpenCV C++ code attaching to the OpenCV window.
- That callback function will be called every time, mouse events occur.
- That callback function will also give the coordinates of the mouse events. `(e.g - (x, y) coordinate of a mouse click).`

### Example 1:

- we are going to use the `void setMouseCallback(const string& winname, MouseCallback onMouse, void* userdata = 0)`

* This function sets a callback function to be called every time any mouse events occurs in the specified window:
  - **winname** - Name of the OpenCV window. All mouse events related to this window will be registered
  - **onMouse** - Name of the callback function. Whenever mouse events related to the above window occur, this callback function will be called. This function should have the signature like `void FunctionName(int event, int x, int y, int flags, void* userdata)`
  - **event** - Type of the mouse event. These are the entire list of mouse events
    - EVENT_MOUSEMOVE
    - EVENT_LBUTTONDOWN
    - EVENT_RBUTTONDOWN
    - EVENT_MBUTTONDOWN
    - EVENT_LBUTTONUP
    - EVENT_RBUTTONUP
    - EVENT_MBUTTONUP
    - EVENT_LBUTTONDBLCLK
    - EVENT_RBUTTONDBLCLK
    - EVENT_MBUTTONDBLCLK
  - **x** - x coordinate of the mouse event
  - **y** - y coordinate of the mouse event
  - **flags** - Specific condition whenever a mouse event occurs. See the next OpenCV example code for the usage of this parameter. Here is the entire list of enum values which will be possesed by `flags`
    - EVENT_FLAG_LBUTTON
    - EVENT_FLAG_RBUTTON
    - EVENT_FLAG_MBUTTON
    - EVENT_FLAG_CTRLKEY
    - EVENT_FLAG_SHIFTKEY
    - EVENT_FLAG_ALTKEY
  - **userdata** - Any pointer passes to the "setMouseCallback" function as the 3rd parameter (see below)

```c++
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
using namespace cv;
using namespace std;

void mouseCallBack(int event, int x, int y, int flags, void* userdata) {
	if (event == EVENT_LBUTTONDBLCLK) {
		cout << "You have double clicked at:( " << x << ", " << y<<')' << endl;
	}
	else if (event == EVENT_LBUTTONDOWN) {
		cout << "You have left- clicked at:( " << x << ", " << y << ')' << endl;
	}
	else if (event == EVENT_RBUTTONDOWN) {
		cout << "You have right clicked at:( " << x << ", " << y << ')' << endl;
	}
	else {
		cout << "Your mouse is at position:( " << x << ", " << y << ')' << endl;
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
```

### Output

<div align="center">
<img alt="output-image" src="https://github.com/CrispenGari/opencv-cpp/blob/main/07_MOUSE_EVENTS/bandicam%202021-03-15%2011-07-13-380.jpg">
</div>

## Example 2:

- We are going to detect a mouse event while pressing a key of the keyboard.

  - In this example we will listen to the clicks of keys such as:
    - CTRL
    - ALT
    - SHIFT
    - COMBINATIONAL KEYS

- We will modify our code from the previous example:

```c++
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

```

<div align="center">
<img alt="output-image" src="https://github.com/CrispenGari/opencv-cpp/blob/main/07_MOUSE_EVENTS/bandicam%202021-03-15%2011-24-37-533.jpg">
</div>
That's all on the next section we will look at Rotate Image & Video

## Documentation Reference

- [Documentation](https://www.opencv-srf.com/2017/12/play-video-from-file-or-camera.html)

## Credits

- [Stackoverflow](https://stackoverflow.com/)
