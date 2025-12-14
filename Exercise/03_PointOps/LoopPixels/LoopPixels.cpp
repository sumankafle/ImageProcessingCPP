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
#define ROWS 150
#define COLUMNS 256

/* Namespaces */
using namespace std;

/* Main function */
int main()
{
	// Create gray image
	cv::Mat image(cv::Size(COLUMNS, ROWS), CV_8U);

	// Loop through pixels and modify image
	for (int y = 0; y < image.rows; y++) {
		for (int x = 0; x < image.cols; x++)
			image.at<uchar>(y, x) = x;
	}

	// Display image
	cv::imshow("Image", image);

	// Wait for keypress and terminate
	cv::waitKey(0);
	return 0;
}
