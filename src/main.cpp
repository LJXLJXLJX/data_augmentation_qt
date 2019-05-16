#include <QtWidgets/QApplication>

#include <iostream>

#include "C/data_augmentation_app.h"
#include "M/data_augmentor.h"
#include "M/distribution_wrapper.h"


using namespace std;
using namespace cv;



//还没完成 先凑活用
void wtf() {

}



int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	DataAugmentationApp w;
	w.show();
	return a.exec();

	//以下是测试
	//DataAugmentor* da = DataAugmentor::getInstance();
	//Mat img = imread("Resources/hj.jpg", 0);

	//da->translation(img,img, -10, 10, BORDER_REFLECT, 0);
	//da->rotate(img, img.cols / 2, img.rows / 2, 90, BORDER_REFLECT101);
	//da->scaling(img, 1.5f, 1.0f);
	//da->flipping(img, -1);
	//da->gaussianFilter(img,img,15, 15, 8, 8);
	//da->meanFilter(img, img, 15, 15, BORDER_DEFAULT);
	//da->bilateralFilter(img, img, 25, 12.5, 50);
	//da->addGammaNoise(img, img, 1.0, 2.0);
	//da->addGaussianNoise(img, img, 0, 50);
	//da->addUniformNoise(img, img, -50, 50);

	//imshow("test", img);
	//waitKey();
	//destroyAllWindows();

}
