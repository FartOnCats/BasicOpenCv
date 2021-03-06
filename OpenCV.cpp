// OpenCV.cpp : Defines the entry point for the console application.
#include "opencv2\\opencv.hpp";
using namespace cv;

void images() {

	//declaring images to show
	Mat file1 = imread("image.png", CV_LOAD_IMAGE_UNCHANGED);
	Mat file2 = imread("image.png", CV_LOAD_IMAGE_GRAYSCALE);
	//making namedwindows for images 
	namedWindow("Image Name", CV_WINDOW_FREERATIO);
	namedWindow("Image grey", CV_WINDOW_AUTOSIZE);
	//resize windows
	resizeWindow("Image Name", file1.cols, file1.rows);
	resizeWindow("Image grey", file2.cols / 2, file2.rows / 2);
	//move windows
	//moveWindow("windows name", x, y)

	//showing the named windows
	imshow("Image Name", file1);
	imshow("Image grey", file2);
	waitKey();

}

int video() {

	Mat curFrame;
	//0 represents the webcam, so if you want to use another webcame use 1-2-3 etc, if you want to stream a file input the file name
	VideoCapture vid(0);
	
	//ensures that there is actual data coming outta the 
	if (vid.isOpened()) {
		//push the video to curFrame
		while (true) {

			vid >> curFrame;
			imshow("webCam", curFrame);
			//waitkey uses miliseconds as time. the 20 is the fps we want to stream at
			if (waitKey( 1000/20 ) >= 0) {
				break;

			}

		}

	}
	else {
		//return -1 if failed to get video
		return -1;
	}

}

int main()
{
	//load images and display them using namedWindows and imshow
	images();
	
	//load webcam 0 and streams it to imshow
	video();

}


