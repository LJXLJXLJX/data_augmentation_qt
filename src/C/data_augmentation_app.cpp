#include "data_augmentation_app.h"
#include "../M/data_augmentor.h"
#include "../M/distribution_wrapper.h"
#include "../M/utils.h"

#include <qdebug.h>
#include <qfiledialog.h>
#include <qmessagebox.h>

#include <filesystem>
#include <thread>
#include <queue>


using namespace std;
using namespace cv;
namespace fs = filesystem;

DataAugmentationApp::DataAugmentationApp(QWidget *parent)
	: QMainWindow(parent), m_processed_num(0)
{
	ui.setupUi(this);
	setFixedSize(830, 600);
	m_demo_img = imread("Resources/hj.jpg");

#ifdef _DEBUG
	ui.sbNum->setValue(100);
	ui.sbThreadNum->setValue(1);
	ui.leInputDir->setText("F:/Project/data_augmentation_qt/data_augmentation/test/origin");
	ui.leOutputDir->setText("F:/Project/data_augmentation_qt/data_augmentation/test/aug");
#endif // _DEBUG


}


Command*& DataAugmentationApp::addNewCommand(int flag, CommandEditor* ce, std::vector<std::any> vec)
{
	Command* cmd = createCommand(flag, ce, vec);
	if (cmd != Q_NULLPTR)
		ui.commandList->addItem(cmd);
	return cmd;
}


void DataAugmentationApp::resetCommand(int flag, CommandEditor* ce, std::vector<std::any> vec)
{
	Command* cmd = createCommand(flag, ce, vec);
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
		processImgAccordingToACommand(cmd, ret);
	}
	return ret;
}

Command * DataAugmentationApp::createCommand(int flag, CommandEditor*ce, std::vector<std::any> vec)
{
	Command* cmd = Q_NULLPTR;
	switch (flag) {
	case OP_TRANSLATE:			cmd = new CommandTranslate(ce, "平移", vec); break;
	case OP_ROTATE:				cmd = new CommandRotate(ce, "旋转", vec); break;
	case OP_SCALING:			cmd = new  CommandScaling(ce, "缩放", vec); break;
	case OP_FLIPPING:			cmd = new CommandFlipping(ce, "翻转", vec); break;
	case OP_GAUSSIAN_FILTER:	cmd = new CommandGaussianFilter(ce, "高斯滤波", vec); break;
	case OP_MEDIAN_FILTER:		cmd = new CommandMedianFilter(ce, "中值滤波", vec); break;
	case OP_MEAN_FILTER:		cmd = new CommandMeanFilter(ce, "均值滤波", vec); break;
	case OP_BILATERAL_FILTER:	cmd = new CommandBilateralFilter(ce, "双线性滤波", vec); break;
	case OP_GAUSSIAN_NOISE:		cmd = new CommandGaussianNoise(ce, "高斯噪声", vec); break;
	case OP_UNIFORM_NOISE:		cmd = new CommandUniformNoise(ce, "均值噪声", vec); break;
	case OP_GAMMA_NOISE:		cmd = new CommandGammaNoise(ce, "伽马噪声", vec); break;
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
		if (cmd_transate->m_x_min > cmd_transate->m_x_max || cmd_transate->m_y_min > cmd_transate->m_y_max) {
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
		if (cmd_rotate->m_theta_min > cmd_rotate->m_theta_max) {
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
	if (cmd_scaling->m_x_min > cmd_scaling->m_x_max ||
		cmd_scaling->m_y_min > cmd_scaling->m_y_max) {
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
		if (cmd_gaussian_filter->m_kx_min > cmd_gaussian_filter->m_kx_max ||
			cmd_gaussian_filter->m_ky_min > cmd_gaussian_filter->m_ky_max ||
			cmd_gaussian_filter->m_sigma_x_min > cmd_gaussian_filter->m_sigma_x_max ||
			cmd_gaussian_filter->m_sigma_y_min > cmd_gaussian_filter->m_sigma_y_max) {
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
	if (cmd_median_filter->m_ksize_min > cmd_median_filter->m_ksize_max) {
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
		if (cmd_mean_filter->m_kx_min > cmd_mean_filter->m_kx_max ||
			cmd_mean_filter->m_ky_min > cmd_mean_filter->m_ky_max) {
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
		if (cmd_bilatera_filter->m_d_min > cmd_bilatera_filter->m_d_max ||
			cmd_bilatera_filter->m_sigma_color_min > cmd_bilatera_filter->m_sigma_color_max ||
			cmd_bilatera_filter->m_sigma_space_min > cmd_bilatera_filter->m_sigma_space_max) {
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
		if (cmd_gaussian_noise->m_mu_min > cmd_gaussian_noise->m_mu_max ||
			cmd_gaussian_noise->m_sigma_min > cmd_gaussian_noise->m_sigma_max) {
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
		if (cmd_uniform_noise->m_a > cmd_uniform_noise->m_b) {
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
		if (cmd_gamma_noise->m_alpha_min > cmd_gamma_noise->m_alpha_max ||
			cmd_gamma_noise->m_beta_min > cmd_gamma_noise->m_beta_max) {
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

void DataAugmentationApp::processImgsInADirThread(const std::string input_dir, const std::string output_dir, int& count, int target_num)
{
	unique_lock<mutex> ul(m_mutex);
	ul.unlock();	
	while (count < target_num) {
		for (auto& p : fs::directory_iterator(input_dir)) {
			if (p.path().extension() != ".jpg" && p.path().extension() != ".bmp" &&
				p.path().extension() != ".png" && p.path().extension() != ".jpeg") {
				continue;
			}
			Mat img = imread(p.path().string(), -1);
			Mat output_img = processImgAccordingToCommandList(img);

			ul.lock();
			if (count >= target_num)
				return;
			count++;
			m_processed_num++;
			//ui.progressBar->setValue(m_processed_num);
			ul.unlock();
			fs::path out(output_dir);
			string output_path = out.append(randomStr() + ".jpg").string();
			imwrite(output_path, output_img);
		}
	}
}

void DataAugmentationApp::processImgsInADir(std::string& input_dir, std::string& output_dir, int target_num, int thread_num)
{
	int count = 0;
	for (int i = 0; i < thread_num; ++i) {
		std::thread t([&]() {processImgsInADirThread(input_dir, output_dir, count, target_num); });
		t.join();
	}
}

std::list<std::string> DataAugmentationApp::getImgsInADir(std::string& dir)
{
	list<string> img_list;
	for (auto& p : fs::directory_iterator(dir)) {
		string tmp = p.path().string();
		if (p.path().extension() == ".jpg" || p.path().extension() == ".bmp" ||
			p.path().extension() == ".png" || p.path().extension() == ".jpeg") {
			img_list.push_back(tmp);
		}
	}
	return img_list;
}

std::list<std::string> DataAugmentationApp::getChildDir(std::string & dir)
{
	list<string> dir_list;
	for (auto& p : fs::directory_iterator(dir)) {
		if (fs::is_directory(p))
			dir_list.push_back(p.path().string());
		else if (p.path().extension() == ".jpg" || p.path().extension() == ".bmp" ||
			p.path().extension() == ".png" || p.path().extension() == ".jpeg")
			return {};

	}
	return dir_list;
}

std::list<std::string> DataAugmentationApp::getLeafDirs(std::string & dir)
{
	list<string> leaf_dir_list;
	queue<string> dir_queue;
	dir_queue.push(dir);
	while (!dir_queue.empty()) {
		list<string> sub_dirs = getChildDir(dir_queue.front());
		if (sub_dirs.empty()) {
			//还要确保子目录下有图像文件
			for (auto& p : fs::directory_iterator(dir_queue.front()))
				if (p.path().extension() == ".jpg" || p.path().extension() == ".bmp" ||
					p.path().extension() == ".jpeg" || p.path().extension() == ".png") {
					leaf_dir_list.push_back(dir_queue.front());
					break;
				}
		}

		else {
			for (string dir : sub_dirs)
				dir_queue.push(dir);
		}
		dir_queue.pop();
	}
#ifdef _DEBUG
	for (string dir : leaf_dir_list)
		qDebug() << dir.c_str();
#endif // _DEBUG
	return leaf_dir_list;
}


void DataAugmentationApp::on_pbAddItemToCommandList_clicked()
{
	qDebug("add clicked");
	CommandEditor* ce = new CommandEditor(this);
	ce->exec();
	if (ce->getCommand() == Q_NULLPTR)
		delete ce;
}

void DataAugmentationApp::on_pbDeleteItemFromCommandList_clicked()
{
	qDebug("delete clicked");
	if (ui.commandList->count() == 0)
		return;
	delete ui.commandList->currentItem();
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

void DataAugmentationApp::on_pbProcessDemo_clicked()
{
	imshow("处理前", m_demo_img);
	Mat img_clone = m_demo_img.clone();
	processImgAccordingToCommandList(img_clone);
	imshow("处理后", img_clone);
	waitKey();
	destroyAllWindows();
}

void DataAugmentationApp::on_pbSelectDemo_clicked()
{
	QString filename = QFileDialog::getOpenFileName(this, ("选择一个文件"), ".", tr("images(*.jpg *.jpeg *.bmp *.png)"));
	if (filename.isEmpty())
		return;
	m_demo_img = imread(filename.toStdString(), -1);
}

void DataAugmentationApp::on_pbSelectInputDir_clicked()
{
	QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
		"/home",
		QFileDialog::ShowDirsOnly
		| QFileDialog::DontResolveSymlinks);
	if (dir.isEmpty())
		return;
	ui.leInputDir->setText(dir);
}

void DataAugmentationApp::on_pbSelectOutputDir_clicked()
{
	QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
		"/home",
		QFileDialog::ShowDirsOnly
		| QFileDialog::DontResolveSymlinks);
	if (dir.isEmpty())
		return;
	ui.leOutputDir->setText(dir);
}

void DataAugmentationApp::on_pbStart_clicked()
{
	QMessageBox mention(this);
	mention.setWindowTitle(QString::fromLocal8Bit("提示"));
	mention.setText(QString::fromLocal8Bit("请确保目录结构正确，若文件夹中存在图像文件，则不应该存在其他文件夹"));
	mention.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
	if (mention.exec() != QMessageBox::Ok)
		return;

	m_processed_num = 0;
	fs::path input(ui.leInputDir->text().toStdString());
	fs::path output(ui.leOutputDir->text().toStdString());
	if (!fs::exists(input)) {
		QMessageBox::about(this, QString::fromLocal8Bit("目录错误"), QString::fromLocal8Bit(" 输入目录不存在"));
		return;
	}
	list<string> leaf_dirs = getLeafDirs(input.string());
	int process_num_each_dir = ui.sbNum->value();
	if (process_num_each_dir == 0)
		return;
	int to_process_num = process_num_each_dir * leaf_dirs.size();
	int thread_num = ui.sbThreadNum->value();
	string out_root = ui.leOutputDir->text().toStdString();
	ui.progressBar->setMaximum(to_process_num);
	for (string dir : leaf_dirs) {
		string out_dir = fs::path(out_root).append(fs::path(dir).filename().string()).string();
		if (!fs::exists(out_dir))
			fs::create_directory(out_dir);
		processImgsInADir(dir, out_dir, process_num_each_dir, thread_num);
	}
}
