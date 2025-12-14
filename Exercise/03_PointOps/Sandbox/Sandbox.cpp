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
#include <opencv2/imgproc/imgproc.hpp>

/* Defines */
#define IMAGE_DATA_PATH getenv("ImagingData")			// Read environment variable ImagingData
#define INPUT_IMAGE_RELATIVE_PATH "/Images/PCB.jpg"	// Image file including relative path

/* Namespaces */
using namespace std;

/* Prototypes */
cv::Mat createHistogram(cv::Mat& image);

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

	// Contrast
	double gMin, gMax;
	cv::minMaxLoc(image, &gMin, &gMax);
	cout << "Min: " << gMin << endl;
	cout << "Max: " << gMax << endl;
	cout << "Contrast: " << (gMax - gMin) << endl;

	// Create histogram plot
	cv::Mat histoPlot = createHistogram(image);

	// Display image in named window
	cv::imshow("Image", image);
	cv::imshow("h(g)", histoPlot);

	// Wait for keypress and terminate
	cv::waitKey(0);
	return 0;
}

cv::Mat createHistogram(cv::Mat& image)
{
	const int numberBins = 256;
	int height = 256;

	// Calculate histogram values
	unsigned h[numberBins] = { 0 };

	for (int y = 0; y < image.rows; y++) {
		uchar* row = image.ptr<uchar>(y);

		for (int x = 0; x < image.cols; x++) {
			h[row[x]]++;
		}
	}

	// Determine max{h}
	unsigned maxValue = h[0];

	for (int i = 1; i < numberBins; i++) {
		if (maxValue < h[i])
			maxValue = h[i];
	}

	// Create bar plot
	cv::Mat histogram(cv::Size(numberBins, height), CV_8UC3, cv::Scalar(240, 240, 240));

	for (int i = 1; i < numberBins; i++) {
		int barLength = (int)(0.95 * height * (h[i] / (double)maxValue));

		cv::line(histogram, cv::Point(i, height - 1), cv::Point(i, height - barLength), cv::Scalar(220, 175, 175));
	}

	return histogram;
}
