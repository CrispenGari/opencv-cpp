
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
using namespace cv;
using namespace std;
int main()
{
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
								}
								else if (key == 113) {
									// when q is clicked close all windows
									cap.release();
									destroyAllWindows();
									break;
								}
								else {
									continue;
								}
								// Start recording the video
								outVidObject.write(frame);
							}
							else {
								throw "An Error has occured while trying to read the frame";
							}
						}
					}
					catch (string e) {

						cout << e << endl;
					}
				}
				else {
					throw "Enable to open the Camera!";
				}
			}
			catch (const char* e) {
				cout << e << endl;
			}
		}
		else {
			cout<< "Failed to create a video output object";
		}
	}
	catch (const char* e) {
		cout << e << endl;
   }
	
	return 0;
}