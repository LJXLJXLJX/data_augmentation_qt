#include "data_augmentor.h"
#include "../utils/distribution_wrapper.h"

#include <random>



using namespace std;
using namespace cv;

DataAugmentor * DataAugmentor::getInstance()
{
	static DataAugmentor instance;
	return &instance;
}

void DataAugmentor::translation(cv::Mat & input, cv::Mat& output, int dx, int dy, int border_type, int arg)
{
	Mat M = (Mat_<float>(2, 3) << 1, 0, dx, 0, 1, dy);
	warpAffine(input, output, M, Size(input.cols, input.rows), INTER_LINEAR, border_type, 0);
}

void DataAugmentor::rotate(cv::Mat & input, cv::Mat& output, int center_x, int center_y, float theta, int border_type, int arg)
{
	Mat M = getRotationMatrix2D(Point(center_x, center_y), theta, 1.0);
	warpAffine(input, output, M, Size(input.cols, input.rows), INTER_LINEAR, border_type, 0);
}

void DataAugmentor::scaling(cv::Mat & input, cv::Mat& output, float relative_x, float relative_y, int interpolation_mode)
{
	Mat M = (Mat_<float>(2, 3) << relative_x, 0, 0, 0, relative_y, 0);
	warpAffine(input, output, M, Size(int(relative_x*input.cols), int(relative_y*input.rows)), interpolation_mode);
}

void DataAugmentor::flipping(cv::Mat & input, cv::Mat& output, int flip_code)
{
	flip(input, output, flip_code);
}

void DataAugmentor::gaussianFilter(cv::Mat & input, cv::Mat& output, int kx, int ky, double sigmaX, double sigmaY, int border_type)
{
	Size ksize(kx * 2 + 1, ky * 2 + 1);
	GaussianBlur(input, output, ksize, sigmaX, sigmaY, border_type);
}

void DataAugmentor::meanFilter(cv::Mat & input, cv::Mat& output, int kx, int ky, int border_type)
{
	Size ksize(kx * 2 + 1, ky * 2 + 1);
	blur(input, output, ksize, Point(-1, -1), border_type);
}

void DataAugmentor::medianFilter(cv::Mat & input, cv::Mat & output, int ksize)
{
	medianBlur(input, output, 2 * ksize + 1);
}

void DataAugmentor::bilateralFilter(cv::Mat & input, cv::Mat & output, int d, double sigma_color, double sigma_space, int border_type)
{
	if (input.data == output.data) {
		cout << "This filter does not work inplace." << endl;
		return;
	}
	cv::bilateralFilter(input, output, d, sigma_color, sigma_space, border_type);
}


void DataAugmentor::addPDFNoise(cv::Mat& input, cv::Mat& output, int pdf, std::initializer_list<double> il)
{
	output = input.clone();
	mt19937 gen(random_device{}());

	DistributionWrapper dist_wrapper;


	if (pdf == DIST_NORMAL) {
		auto it = il.begin();
		double mu = *it++;
		double sigma = *it;
		dist_wrapper.setNormalDistribution(mu, sigma);
	}
	else if (pdf == DIST_UNIFORM) {
		auto it = il.begin();
		double a = *it++;
		double b = *it;
		dist_wrapper.setUniformDistribution(a, b);
	}


	if (input.channels() == 1) {
		for (auto it = input.begin<uchar>(); it != input.end<uchar>(); ++it) {
			int val = static_cast<int>(*it);
			val += dist_wrapper.getValue();
			val = std::clamp(val, 0, 255);
			*it = static_cast<uchar>(val);
		}
	}
	else if (input.channels() == 3) {
		for (auto it = input.begin<Vec3b>(); it != input.end<Vec3b>(); ++it) {
			for (int i = 0; i < 3; ++i) {
				int val = static_cast<int>((*it)[i]);
				val += dist_wrapper.getValue();
				val = std::clamp(val, 0, 255);
				(*it)[i] = static_cast<uchar>(val);
			}
		}
	}
}



DataAugmentor::Object_Creator DataAugmentor::_object_creator;