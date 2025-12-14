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
	// Create RGB image
	cv::Mat image(cv::Size(IMAGE_SIZE, IMAGE_SIZE), CV_8UC3, cv::Scalar(0, 100, 255));

	// Print color components of a specific pixel to console
	cv::Vec3b value = image.at<cv::Vec3b>(0, 0);
	cout << "RGB = ("
		<< (int)value[2] << ", "
		<< (int)value[1] << ", "
		<< (int)value[0] << ")" << endl;

	// Display the image
	cv::imshow("Image", image);

	// Wait for keypress and terminate
	cv::waitKey(0);
	return 0;
}
