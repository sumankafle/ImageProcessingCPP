/*! Digital image processing using OpenCV.
*
* \category Excercise Code
* \author Suman Kafle
*/


#pragma once
#ifndef IP_UTILS_H
#define IP_UTILS_H

/* Include files */
#include <opencv2/core/core.hpp>

namespace ip
{
	/* Prototypes */
	inline uchar clamp(int value, uchar min, uchar max);
	void clamp(cv::Mat& image, uchar min, uchar max);

	unsigned max(unsigned values[], int size);
	void calcHistogram(const cv::Mat& image, unsigned histogram[256]);
	void histogramChart(const cv::Mat& image, cv::Mat& histogram);

	void maximizeContrast(const cv::Mat& image, cv::Mat& processed, double p = 0.0);
}

#endif /* IP_UTILS_H */
