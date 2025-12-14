/*! Digital image processing using OpenCV.
*
* \category Excercise Code
* \author Suman Kafle
*/

/* Include files */
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

/* Main function */
int main()
{
	// Load image from file
	cv::Mat image = cv::imread("D:/Docks.jpg", cv::IMREAD_ANYCOLOR);

	// Display image in named window
	cv::imshow("Image", image);

	// Wait for keypress and terminate
	cv::waitKey(0);
	return 0;
}
