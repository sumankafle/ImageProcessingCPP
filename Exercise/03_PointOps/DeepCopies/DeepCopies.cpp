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
#define DATA_ROOT_PATH getenv("ImagingData")  // Read environment variable
#define INPUT_IMAGE "/Images/Docks.jpg"

/* Namespaces */
using namespace std;

/* Main function */
int main()
{
	// Load image from file
	string inputImagePath = string(DATA_ROOT_PATH).append(INPUT_IMAGE);
	cv::Mat image = cv::imread(inputImagePath, cv::IMREAD_GRAYSCALE);

	if (image.empty()) {
		cout << "[ERROR] Cannot open image: " << inputImagePath << endl;
		return 0;
	}

	// Create deep copies
	cv::Mat clonedImage = image.clone();
	cv::Mat copiedImage(cv::Size(320, 240), CV_8UC3, cv::Scalar(0, 127, 255));
	image.copyTo(copiedImage);

	// Modify original image
	for (int y = 0; y < image.rows; y++) {
		for (int x = 0; x < image.cols; x++)
			image.at<uchar>(y, x) /= 4;
	}
	
	// Display images in named windows
	cv::imshow("Modified image", image);
	cv::imshow("Clone", clonedImage);
	cv::imshow("Copy", copiedImage);

	// Wait for keypress and terminate
	cv::waitKey(0);
	return 0;
}
