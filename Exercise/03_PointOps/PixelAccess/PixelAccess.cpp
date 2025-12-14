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
#define IMAGE_SIZE 100

/* Namespaces */
using namespace std;

/* Main function */
int main()
{
	// Create gray image
	cv::Mat image = cv::Mat::zeros(cv::Size(IMAGE_SIZE, IMAGE_SIZE), CV_8U);

	// Print a specific pixel value to console
	uchar value = image.at<uchar>(2, 1);
	cout << "Pixel value g(2, 1) = " << (int)value << endl;

	// Modify some pixels and display the image
	for (int i = 0; i < 25; i++)
		image.at<uchar>(i, i) = 255;

	cv::imshow("Image", image);

	// Wait for keypress and terminate
	cv::waitKey(0);
	return 0;
}
