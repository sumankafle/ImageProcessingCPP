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
	// Create gray images and display in named windows
	cv::Mat gray1(480, 640, CV_8UC1, cv::Scalar(128));
	cv::Mat gray2(cv::Size(640, 480), CV_8U, 128);
	cv::imshow("Gray image 1", gray1);
	cv::imshow("Gray image 2", gray2);

	// Wait for key press and close windows
	cv::waitKey(0);
	cv::destroyAllWindows();

	// Create color images and display in named windows
	cv::Mat red(cv::Size(320, 240), CV_8UC3, cv::Scalar(0, 0, 255));
	cv::Mat green(cv::Size(320, 240), CV_8UC3, cv::Scalar(0, 255, 0));
	cv::imshow("Red image", red);
	cv::imshow("Green image", green);

	// Wait for key press and close windows
	cv::waitKey(0);
	cv::destroyAllWindows();

	// Create images using zeros() and ones()
	cv::Mat grayZeros = cv::Mat::zeros(cv::Size(320, 240), CV_8U);
	cv::Mat floatOnes = cv::Mat::ones(cv::Size(320, 240), CV_32F);
	cv::imshow("Zeros", grayZeros);
	cv::imshow("Ones", floatOnes);

	// Wait for keypress and terminate
	cv::waitKey(0);
	return 0;
}
