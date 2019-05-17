#include "data_augmentation_app.h"
#include "../M/data_augmentor.h"
#include "../M/distribution_wrapper.h"
#include <qdebug.h>

using namespace std;
using namespace cv;

DataAugmentationApp::DataAugmentationApp(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	setFixedSize(800, 600);
	m_demo_img = imread("Resources/hj.jpg");
}


Command*& DataAugmentationApp::addNewCommand(int flag, CommandEditor* ce, std::initializer_list<double> il)
{
	Command* cmd = createCommand(flag, ce, il);
	if (cmd != Q_NULLPTR)
		ui.commandList->addItem(cmd);
	return cmd;
}

Command*& DataAugmentationApp::addNewCommand(int flag, CommandEditor* ce, std::initializer_list<int> il) {
	Command* cmd = createCommand(flag, ce, il);
	if (cmd != Q_NULLPTR)
		ui.commandList->addItem(cmd);
	return cmd;
}

Command*& DataAugmentationApp::addNewCommand(int flag, CommandEditor* ce, std::initializer_list<bool> il) {
	Command* cmd = createCommand(flag, ce, il);
	if (cmd != Q_NULLPTR)
		ui.commandList->addItem(cmd);
	return cmd;
}
void DataAugmentationApp::resetCommand(int flag, CommandEditor* ce, std::initializer_list<double> il)
{
	Command* cmd = createCommand(flag, ce, il);
	int row = ui.commandList->currentRow();
	delete ui.commandList->currentItem();
	ui.commandList->insertItem(row, cmd);
}

cv::Mat DataAugmentationApp::processImgAccordingToCommandList(cv::Mat & img)
{
	Mat ret = img.clone();

	for (int i = 0; i < ui.commandList->count(); ++i) {
		Command* cmd = dynamic_cast<Command*>(ui.commandList->item(i));
		if (cmd == nullptr) {
			qDebug() << "cast failed";
			continue;
		}
		processImgAccordingToACommand(cmd, img);
	}
	return ret;
}

Command * DataAugmentationApp::createCommand(int flag, CommandEditor*ce, std::initializer_list<double> il)
{
	Command* cmd = Q_NULLPTR;
	switch (flag) {
	case OP_TRANSLATE:			cmd = new CommandTranslate(ce, "平移", il); break;
	case OP_ROTATE:				cmd = new CommandRotate(ce, "旋转", il); break;
	case OP_SCALING:			cmd = new  CommandScaling(ce, "缩放", il); break;
	case OP_GAUSSIAN_FILTER:	cmd = new CommandGaussianFilter(ce, "高斯滤波", il); break;
	case OP_BILATERAL_FILTER:	cmd = new CommandBilateralFilter(ce, "双线性滤波", il); break;
	case OP_GAUSSIAN_NOISE:		cmd = new CommandGaussianNoise(ce, "高斯噪声", il); break;
	case OP_UNIFORM_NOISE:		cmd = new CommandUniformNoise(ce, "均值噪声", il); break;
	case OP_GAMMA_NOISE:		cmd = new CommandGammaNoise(ce, "伽马噪声", il); break;
	default:break;
	}
	return cmd;
}

Command* DataAugmentationApp::createCommand(int flag, CommandEditor*ce, std::initializer_list<bool> il)
{
	Command* cmd = Q_NULLPTR;
	switch (flag) {
	case OP_FLIPPING:			cmd = new CommandFlipping(ce, "翻转", il);
	default:break;
	}
	return cmd;
}

Command* DataAugmentationApp::createCommand(int flag, CommandEditor*ce, std::initializer_list<int> il)
{
	Command* cmd = Q_NULLPTR;
	switch (flag) {
	case OP_MEDIAN_FILTER:		cmd = new CommandMedianFilter(ce, "中值滤波", il); break;
	case OP_MEAN_FILTER:		cmd = new CommandMeanFilter(ce, "均值滤波", il); break;
	default:break;
	}
	return cmd;
}

void DataAugmentationApp::processImgAccordingToACommand(Command * cmd, cv::Mat& img)
{
	DataAugmentor* da = DataAugmentor::getInstance();
	DistributionWrapper dist_wrapper;
	switch (cmd->getFlag())
	{
	case OP_TRANSLATE:
	{
		CommandTranslate* cmd_transate = dynamic_cast<CommandTranslate*>(cmd);
		if (cmd_transate == nullptr) {
			qDebug() << "fail to cast";
			return;
		}
		if (cmd_transate->m_x_min >= cmd_transate->m_x_max || cmd_transate->m_y_min >= cmd_transate->m_y_max) {
			qDebug() << "invalid params";
			return;
		}
		dist_wrapper.setUniformDistribution(cmd_transate->m_x_min, cmd_transate->m_x_max);
		int dx = round(dist_wrapper.getValue()*img.cols);
		dist_wrapper.setUniformDistribution(cmd_transate->m_y_min, cmd_transate->m_y_max);
		int dy = round(dist_wrapper.getValue()*img.rows);
		da->translation(img, img, dx, dy, BORDER_DEFAULT);
		break;
	}
	case OP_ROTATE:
	{
		CommandRotate* cmd_rotate = dynamic_cast<CommandRotate*>(cmd);
		if (cmd_rotate == nullptr) {
			qDebug() << "fail to cast";
			return;
		}
		if (cmd_rotate->m_theta_min >= cmd_rotate->m_theta_max) {
			qDebug() << "invalid params";
			return;
		}
		dist_wrapper.setUniformDistribution(cmd_rotate->m_theta_min, cmd_rotate->m_theta_max);
		double theta = dist_wrapper.getValue();
		da->rotate(img, img, img.cols / 2, img.rows / 2, theta, BORDER_DEFAULT);
		break; }
	case OP_SCALING:
	{CommandScaling* cmd_scaling = dynamic_cast<CommandScaling*>(cmd);
	if (cmd_scaling == nullptr) {
		qDebug() << "fail to cast";
		return;
	}
	if (cmd_scaling->m_x_min >= cmd_scaling->m_x_max ||
		cmd_scaling->m_y_min >= cmd_scaling->m_y_max) {
		qDebug() << "invalid params";
		return;
	}
	dist_wrapper.setUniformDistribution(cmd_scaling->m_x_min, cmd_scaling->m_x_max);
	double x = dist_wrapper.getValue();
	dist_wrapper.setUniformDistribution(cmd_scaling->m_y_max, cmd_scaling->m_y_max);
	double y = dist_wrapper.getValue();
	da->scaling(img, img, x, y, INTER_LINEAR);
	break;
	}
	case OP_FLIPPING:
	{
		CommandFlipping* cmd_flipping = dynamic_cast<CommandFlipping*>(cmd);
		if (cmd_flipping = nullptr) {
			qDebug() << "fail to cast";
			return;
		}
		bool x = cmd_flipping->m_x;
		bool y = cmd_flipping->m_y;
		int flip_flag = 0;
		if (x && !y)
			flip_flag = 0;
		if (!y && y)
			flip_flag = 1;
		if (x && y)
			flip_flag = -1;
		da->flipping(img, img, flip_flag);
		break;
	}
	case OP_GAUSSIAN_FILTER:
	{
		CommandGaussianFilter* cmd_gaussian_filter = dynamic_cast<CommandGaussianFilter*>(cmd);
		if (cmd_gaussian_filter == nullptr) {
			qDebug() << "fail to cast";
			return;
		}
		if (cmd_gaussian_filter->m_kx_min >= cmd_gaussian_filter->m_kx_max ||
			cmd_gaussian_filter->m_ky_min >= cmd_gaussian_filter->m_ky_max ||
			cmd_gaussian_filter->m_sigma_x_min >= cmd_gaussian_filter->m_sigma_x_max ||
			cmd_gaussian_filter->m_sigma_y_min >= cmd_gaussian_filter->m_sigma_y_max) {
			qDebug() << "invalid params";
			return;
		}
		dist_wrapper.setUniformDistribution(cmd_gaussian_filter->m_kx_min, cmd_gaussian_filter->m_kx_max);
		int kx = round(dist_wrapper.getValue());
		dist_wrapper.setUniformDistribution(cmd_gaussian_filter->m_ky_min, cmd_gaussian_filter->m_ky_max);
		int ky = round(dist_wrapper.getValue());
		dist_wrapper.setUniformDistribution(cmd_gaussian_filter->m_sigma_x_min, cmd_gaussian_filter->m_sigma_x_max);
		double sigma_x = dist_wrapper.getValue();
		dist_wrapper.setUniformDistribution(cmd_gaussian_filter->m_sigma_y_min, cmd_gaussian_filter->m_sigma_y_max);
		double sigma_y = dist_wrapper.getValue();
		da->gaussianFilter(img, img, kx, ky, sigma_x, sigma_y);
		break; }
	case OP_MEDIAN_FILTER:
	{	CommandMedianFilter* cmd_median_filter = dynamic_cast<CommandMedianFilter*>(cmd);
	if (cmd_median_filter == nullptr) {
		qDebug() << "fail to cast";
		return;
	}
	if (cmd_median_filter->m_ksize_min >= cmd_median_filter->m_ksize_max) {
		qDebug() << "invalid params";
		return;
	}
	dist_wrapper.setUniformDistribution(cmd_median_filter->m_ksize_min, cmd_median_filter->m_ksize_max);
	int ksize = round(dist_wrapper.getValue());
	da->medianFilter(img, img, ksize);
	break; }
	case OP_MEAN_FILTER:
	{
		CommandMeanFilter* cmd_mean_filter = dynamic_cast<CommandMeanFilter*>(cmd);
		if (cmd_mean_filter == nullptr) {
			qDebug() << "fail to cast";
			return;
		}
		if (cmd_mean_filter->m_kx_min >= cmd_mean_filter->m_kx_max ||
			cmd_mean_filter->m_ky_min >= cmd_mean_filter->m_ky_max) {
			qDebug() << "invalid params";
			return;
		}
		dist_wrapper.setUniformDistribution(cmd_mean_filter->m_kx_min, cmd_mean_filter->m_kx_max);
		int kx = round(dist_wrapper.getValue());
		dist_wrapper.setUniformDistribution(cmd_mean_filter->m_ky_min, cmd_mean_filter->m_ky_max);
		int ky = round(dist_wrapper.getValue());
		da->meanFilter(img, img, kx, ky, BORDER_DEFAULT);
		break; }
	case OP_BILATERAL_FILTER:
	{
		CommandBilateralFilter* cmd_bilatera_filter = dynamic_cast<CommandBilateralFilter*>(cmd);
		if (cmd_bilatera_filter == nullptr) {
			qDebug() << "fail to cast";
			return;
		}
		if (cmd_bilatera_filter->m_d_min >= cmd_bilatera_filter->m_d_max ||
			cmd_bilatera_filter->m_sigma_color_min >= cmd_bilatera_filter->m_sigma_color_max ||
			cmd_bilatera_filter->m_sigma_space_min >= cmd_bilatera_filter->m_sigma_space_max) {
			qDebug() << "invalid params";
			return;
		}
		dist_wrapper.setUniformDistribution(cmd_bilatera_filter->m_d_min, cmd_bilatera_filter->m_d_max);
		int d = round(dist_wrapper.getValue());
		dist_wrapper.setUniformDistribution(cmd_bilatera_filter->m_sigma_color_min, cmd_bilatera_filter->m_sigma_color_max);
		double sigma_color = dist_wrapper.getValue();
		dist_wrapper.setUniformDistribution(cmd_bilatera_filter->m_sigma_space_min, cmd_bilatera_filter->m_sigma_space_max);
		double sigma_space = dist_wrapper.getValue();
		Mat img_copy = img.clone();
		img = Mat();
		da->bilateralFilter(img_copy, img, d, sigma_color, sigma_space);
		break;
	}
	case OP_GAUSSIAN_NOISE:
	{
		CommandGaussianNoise* cmd_gaussian_noise = dynamic_cast<CommandGaussianNoise*>(cmd);
		if (cmd_gaussian_noise == nullptr) {
			qDebug() << "fail to cast";
			return;
		}
		if (cmd_gaussian_noise->m_mu_min >= cmd_gaussian_noise->m_mu_max ||
			cmd_gaussian_noise->m_sigma_min >= cmd_gaussian_noise->m_mu_max) {
			qDebug() << "invalid params";
			return;
		}
		dist_wrapper.setUniformDistribution(cmd_gaussian_noise->m_mu_min, cmd_gaussian_noise->m_mu_max);
		int mu = round(dist_wrapper.getValue());
		dist_wrapper.setUniformDistribution(cmd_gaussian_noise->m_sigma_min, cmd_gaussian_noise->m_sigma_max);
		double sigma = dist_wrapper.getValue();
		da->addGaussianNoise(img, img, mu, sigma);
		break;
	}
	case OP_UNIFORM_NOISE:
	{
		CommandUniformNoise* cmd_uniform_noise = dynamic_cast<CommandUniformNoise*>(cmd);
		if (cmd_uniform_noise == nullptr) {
			qDebug() << "fail to cast";
			return;
		}
		if (cmd_uniform_noise->m_a >= cmd_uniform_noise->m_b) {
			qDebug() << "invalid params";
			return;
		}
		int a = cmd_uniform_noise->m_a;
		int b = cmd_uniform_noise->m_b;
		da->addUniformNoise(img, img, a, b);
		break;
	}
	case OP_GAMMA_NOISE:
	{
		CommandGammaNoise* cmd_gamma_noise = dynamic_cast<CommandGammaNoise*>(cmd);
		if (cmd_gamma_noise == nullptr) {
			qDebug() << "fail to cast";
			return;
		}
		if (cmd_gamma_noise->m_alpha_min >= cmd_gamma_noise->m_alpha_max ||
			cmd_gamma_noise->m_beta_min >= cmd_gamma_noise->m_beta_max) {
			qDebug() << "invalid params";
			return;
		}
		dist_wrapper.setUniformDistribution(cmd_gamma_noise->m_alpha_min, cmd_gamma_noise->m_alpha_max);
		double alpha = dist_wrapper.getValue();
		dist_wrapper.setUniformDistribution(cmd_gamma_noise->m_beta_min, cmd_gamma_noise->m_beta_max);
		double beta = dist_wrapper.getValue();
		da->addGammaNoise(img, img, alpha, beta);
	}
	}
}

void DataAugmentationApp::on_pb_addItemToCommandList_clicked()
{
	qDebug("clicked");
	CommandEditor* ce = new CommandEditor(this);
	ce->exec();
	if (ce->getCommand() == Q_NULLPTR)
		delete ce;
}

void DataAugmentationApp::on_commandList_itemDoubleClicked(QListWidgetItem *item)
{
	qDebug() << "double click: " << item->text();
	Command* cmd = dynamic_cast<Command*>(item);
	if (cmd == nullptr) {
		qDebug() << "cast failed";
		return;
	}
	CommandEditor* ce = cmd->getCommandEditor();
	ce->exec();
}

void DataAugmentationApp::on_pushButtonProcessDemo_clicked()
{
	imshow("处理前", m_demo_img);
	Mat img_clone = m_demo_img.clone();
	processImgAccordingToCommandList(img_clone);
	imshow("处理后", img_clone);
	waitKey();
	destroyAllWindows();
}
