#pragma once
#include <opencv2/opencv.hpp>

#ifdef _DEBUG
#pragma comment(lib,"opencv_core410d.lib")
#pragma comment(lib,"opencv_highgui410d.lib")
#pragma comment(lib,"opencv_imgcodecs410d.lib")
#pragma comment(lib,"opencv_imgproc410d.lib")
#else
#pragma comment(lib,"opencv_core410.lib")
#pragma comment(lib,"opencv_highgui410.lib")
#pragma comment(lib,"opencv_imgcodecs410.lib")
#pragma comment(lib,"opencv_imgproc410.lib")
#endif // _DEBUG





class DataAugmentor
{
public:
	static DataAugmentor* getInstance();

	void translation(cv::Mat& input, cv::Mat& output, int dx, int dy, int border_type, int arg = 0);

	void rotate(cv::Mat& input, cv::Mat& output, int center_x, int center_y, float theta, int border_type, int arg = 0);

	void scaling(cv::Mat& input, cv::Mat& output, float relative_x, float relative_y, int interpolation_mode = cv::INTER_LINEAR);

	void flipping(cv::Mat& input, cv::Mat& output, int flip_code);

	void gaussianFilter(cv::Mat& input, cv::Mat& output, int kx, int ky, double sigmaX, double sigmaY = 0, int border_type = cv::BORDER_DEFAULT);

	void meanFilter(cv::Mat& input, cv::Mat& output, int kx, int ky, int border_type);

	void medianFilter(cv::Mat& input, cv::Mat& output, int ksize);

	void bilateralFilter(cv::Mat& input, cv::Mat& output, int d, double sigma_color, double sigma_space, int border_type = cv::BORDER_DEFAULT);

	void addPDFNoise(cv::Mat& input, cv::Mat& output, int pdf, std::initializer_list<double> il);




protected:
	struct Object_Creator
	{
		Object_Creator()
		{
			DataAugmentor::getInstance();
		}
	};
	static Object_Creator _object_creator;

	DataAugmentor() {}
	~DataAugmentor() {}

};

