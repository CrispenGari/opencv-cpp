
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