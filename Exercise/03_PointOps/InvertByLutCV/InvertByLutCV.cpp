/*! Digital image processing using OpenCV.
*
* \category Excercise Code
* \author Suman Kafle
*/


/* Compiler settings */
#define _CRT_SECURE_NO_WARNINGS		// Enable getenv()

/* Include files */
#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

/* Defines */
#define IMAGE_DATA_PATH getenv("ImagingData")			// Read environment variable ImagingData
#define INPUT_IMAGE_RELATIVE_PATH "/Images/Cologne.jpg"	// Image file including relative path

/* Namespaces */
using namespace std;

/* Main function */
int main()
{
	// Load image from file
	string inputImagePath = string(IMAGE_DATA_PATH).append(INPUT_IMAGE_RELATIVE_PATH);
	cv::Mat image = cv::imread(inputImagePath, cv::IMREAD_GRAYSCALE);

	if (image.empty()) {
		cout << "[ERROR] Cannot open image: " << inputImagePath << endl;
		return 0;
	}

	// Prepare LUT
	cv::Mat lut(1, 256, CV_8U);

	for (int g = 0; g < 256; g++)
		lut.at<uchar>(g) = 255 - g;

	// Invert image using LUT
	cv::Mat inverted;
	cv::LUT(image, lut, inverted);

	// Display images in named window
	cv::imshow("Image", image);
	cv::imshow("Inverted image", inverted);

	// Wait for keypress and terminate
	cv::waitKey(0);
	return 0;
}
