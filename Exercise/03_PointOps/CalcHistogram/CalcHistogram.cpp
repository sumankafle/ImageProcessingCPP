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

	// Check for correct image type (8-bit grayscale)
	if (image.type() != CV_8U) {
		cout << "[ERROR] Incorrect image type. Expected 8-bit grayscale." << endl;
		return 0;
	}

	// Determine histogram
	int histogram[256] = { 0 };

	for (int y = 0; y < image.rows; y++) {
		uchar* data = image.ptr<uchar>(y);

		for (int x = 0; x < image.cols; x++)
			histogram[data[x]]++;
	}

	// Display image in named window
	cv::imshow("Image", image);

	// Wait for keypress and terminate
	cv::waitKey(0);
	return 0;
}
