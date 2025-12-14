/*! Digital image processing using OpenCV.
*
* \category Excercise Code
* \author Suman Kafle
*/


/* Include files */
#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

/* Namespaces */
using namespace std;

/* Main function */
int main()
{
	uchar lowValue = 32;
	uchar highValue = 255 - 32;

	// Create bar image
	cv::Mat barImage = lowValue + cv::Mat::zeros(cv::Size(256, 256), CV_8U);
	cv::Rect barRect = cv::Rect(0, 0, barImage.cols/2, barImage.rows);
	cv::Mat barROI(barImage, barRect);
	barROI = highValue;

	// Create rotated bar image
	cv::Mat rotatedImage;
	cv::rotate(barImage, rotatedImage, cv::ROTATE_90_CLOCKWISE);

	// Create 2x2 checkerboard
	cv::Mat checkerImage = lowValue + cv::Mat::zeros(cv::Size(256, 256), CV_8U);

	for (int y = 0; y < checkerImage.rows / 2; y++) {
		uchar* data = checkerImage.ptr<uchar>(y);
		for (int x = 0; x < checkerImage.cols / 2; x++)
			data[x] = highValue;
	}
	for (int y = checkerImage.rows / 2; y < checkerImage.rows ; y++) {
		uchar* data = checkerImage.ptr<uchar>(y);
		for (int x = checkerImage.cols / 2; x < checkerImage.cols; x++)
			data[x] = highValue;
	}

	// Display images in named windows
	cv::imshow("Bars", barImage);
	cv::imshow("Rotated", rotatedImage);
	cv::imshow("Checker", checkerImage);

	// Save images to file
	cv::imwrite("D:/SameHistBars.png", barImage);
	cv::imwrite("D:/SameHistRotated.png", rotatedImage);
	cv::imwrite("D:/SameHistChecker.png", checkerImage);

	// Wait for keypress and terminate
	cv::waitKey(0);
	return 0;
}
