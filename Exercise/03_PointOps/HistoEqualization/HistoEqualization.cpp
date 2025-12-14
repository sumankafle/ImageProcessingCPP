/*! Digital image processing using OpenCV.
*
* \category Excercise Code
* \author Suman Kafle
*/


/* Compiler settings */
#define _CRT_SECURE_NO_WARNINGS		// Enable getenv()

/* Include files */
#include "iputils.h"
#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

/* Defines */
#define IMAGE_DATA_PATH getenv("ImagingData")			// Read environment variable ImagingData
#define INPUT_IMAGE_RELATIVE_PATH "/Images/Ton12.jpg"	// Image file including relative path
#define USE_OPENCV_METHOD 0								// Use OpenCV method or own implementation
#define WRITE_IMAGE_FILES 0

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

	// Apply histogram equalization
	cv::Mat processed;
#if USE_OPENCV_METHOD == 1
	cv::equalizeHist(image, processed);
#else
	ip::histogramEqualization(image, processed);
#endif

	// Create histograms
	cv::Mat imageHistogram;
	cv::Mat procHistogram;
	ip::histogramChart(image, imageHistogram);
	ip::histogramChart(processed, procHistogram);

	// Display images and histograms in named windows
	cv::imshow("Image", image);
	cv::imshow("Processed", processed);
	cv::imshow("Image h(g)", imageHistogram);
	cv::imshow("Processed h(g)", procHistogram);

	// Write images to file
#if WRITE_IMAGE_FILES == 1
	cv::imwrite("D:/_.jpg", image);
	cv::imwrite("D:/_Hist.png", imageHistogram);
	cv::imwrite("D:/_Eq.jpg", processed);
	cv::imwrite("D:/_EqHist.png", procHistogram);
#endif

	// Wait for keypress and terminate
	cv::waitKey(0);
	return 0;
}
