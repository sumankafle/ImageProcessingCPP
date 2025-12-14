/*! Digital image processing using OpenCV.
*
* \category Excercise Code
* \author Suman Kafle
*/

/* Include files */
#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

/* Defines */
#define WAIT_TIME_MS 30

/* Namespaces */
using namespace std;

/* Main function */
int main()
{
	// Open the first conencted camera found
	cv::VideoCapture camera(0);

	if (!camera.isOpened()) {
		cout << "ERROR: Cannot open camera" << endl;
		return 0;
	}

	// Loop through frames
	cv::Mat frame;

	while (true) {
		// Get current frame from camera
		camera >> frame;

		// Display frame in named window
		cv::imshow("Camera [press any key to quit]", frame);

		// Wait (exit loop on key press)
		if (cv::waitKey(WAIT_TIME_MS) >= 0)
			break;
	}

	return 0;
}
