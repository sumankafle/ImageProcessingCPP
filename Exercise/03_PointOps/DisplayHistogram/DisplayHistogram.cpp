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
#define INPUT_IMAGE_RELATIVE_PATH "/Images/Cologne.jpg"	// Image file including relative path

/* Prototypes */
cv::Mat createHistogram(const cv::Mat& image);

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

	// Create histogram image
	cv::Mat histoImage = createHistogram(image);

	// Display images in named windows
	cv::imshow("Image", image);
	cv::imshow("Histogram", histoImage);

	// Write images to file
	//cv::imwrite("D:/Gray.jpg", image);
	//cv::imwrite("D:/Histogram.png", histoImage);

	// Wait for keypress and terminate
	cv::waitKey(0);
	return 0;
}

/*! Create an image depicting the histogram of a 8-bit grayscale image.
*
* \param image Image to create histogram for
* \return histogram of size 256 x 256 pixel
*/
cv::Mat createHistogram(const cv::Mat& image) {
	cv::Mat histImage;
	const int NUMBER_BINS = 256;

	// Check for correct image type (8-bit grayscale)
	if (image.type() != CV_8U) {
		cout << "[ERROR] Incorrect image type. Expected 8-bit grayscale." << endl;
		return histImage;
	}

	// Init array and count pixels
	unsigned histogram[NUMBER_BINS] = { 0 };
	for (int y = 0; y < image.rows; y++) {
		const uchar* data = image.ptr<uchar>(y);
		for (int x = 0; x < image.cols; x++) {
			histogram[data[x]]++;
		}
	}

	// Find maximum histogram value
	unsigned maxCount = histogram[0];
	for (int i = 1; i < NUMBER_BINS; i++) {
		if (histogram[i] > maxCount)
			maxCount = histogram[i];
	}

	// Create image
	int height = NUMBER_BINS, maxY = NUMBER_BINS - 1;
	int colorBars = 125, colorBackgnd = 240, colorText = 0;
	double scale = 0.95 * height / (double)maxCount;

	histImage.create(NUMBER_BINS, NUMBER_BINS, CV_8U);
	histImage = colorBackgnd;
	for (int x = 0; x < NUMBER_BINS; x++) {
		cv::line(histImage, cv::Point(x, maxY), cv::Point(x, maxY - (int)(scale * histogram[x])), colorBars);
	}

	cv::putText(histImage, "h_max: " + to_string(maxCount), cv::Point(10, 20),	// String and position
		cv::FONT_HERSHEY_PLAIN, 1.0, colorText, 1);								// Font

	return histImage;
}
