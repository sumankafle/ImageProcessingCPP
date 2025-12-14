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

/* Defines */
#define IMAGE_DATA_PATH getenv("ImagingData")			// Read environment variable ImagingData
#define INPUT_IMAGE_RELATIVE_PATH "/Images/PCB.jpg"	// Image file including relative path

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

	// Apply automatic contrast maximization
	cv::Mat processed;
	ip::maximizeContrast(image, processed, 0.5);

	// Create histograms
	cv::Mat imageHist, procHist;
	ip::histogramChart(image, imageHist);
	ip::histogramChart(processed, procHist);

	// Display images and histograms in named windows
	cv::imshow("Image", image);
	cv::imshow("Image histogram", imageHist);
	cv::imshow("Maximum contrast", processed);
	cv::imshow("Max histogram", procHist);

	// Write images to file
	//cv::imwrite("D:/Gray.jpg", image);
	//cv::imwrite("D:/GrayHist.png", imageHist);
	//cv::imwrite("D:/MaxContrast.jpg", processed);
	//cv::imwrite("D:/MaxContrastHist.png", procHist);

	// Wait for keypress and terminate
	cv::waitKey(0);
	return 0;
}
