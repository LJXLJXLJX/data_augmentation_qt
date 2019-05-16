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
	if (flag == OP_TRANSLATE) {
		cmd = new CommandTranslate(ce, "平移", il);
	}
	else if (flag == OP_ROTATE) {
		cmd = new CommandRotate(ce, "旋转", il);
	}
	return cmd;
}

void DataAugmentationApp::processImgAccordingToACommand(Command * cmd, cv::Mat& img)
{
	DataAugmentor* da = DataAugmentor::getInstance();
	DistributionWrapper dist_wrapper;

	if (cmd->getFlag() == OP_TRANSLATE) {
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
	}
	else if (cmd->getFlag() == OP_ROTATE) {
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
