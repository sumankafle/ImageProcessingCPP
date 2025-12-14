/*! Digital image processing using OpenCV.
*
* \category Excercise Code
* \author Suman Kafle
*/

/* Compiler settings */
#define _CRT_SECURE_NO_WARNINGS		// Enable getenv()

/* Include files */
#include <iostream>
#include <string>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

/* Defines */
#define DATA_ROOT_PATH getenv("ImagingData")
#define VIDEO_PATH "/Videos/MegaZipline.mp4"
#define FRAMES_PER_SECOND 25
#define WAIT_TIME_MS (1000 / FRAMES_PER_SECOND)

/* Namespaces */
using namespace std;

/* Main function */
int main()
{
	// Open video file
	string inputVideoPath = string(DATA_ROOT_PATH).append(VIDEO_PATH);
	cv::VideoCapture video(inputVideoPath);

	if (!video.isOpened()) {
		cout << "ERROR: Cannot open video: " << inputVideoPath << endl;
		return 0;
	}

	// Loop through frames
	cv::Mat frame;

	while (true) {
		// Get next frame from file
		video >> frame;

		// Exit loop when no frame left
		if (frame.empty())
			break;

		// Display frame in named window
		cv::imshow("Video [press any key to quit]", frame);

		// Wait (exit loop on key press)
		if (cv::waitKey(WAIT_TIME_MS) >= 0)
			break;
	}

	return 0;
}
