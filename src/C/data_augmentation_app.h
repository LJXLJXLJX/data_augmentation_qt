#pragma once

#include <list>
#include <vector>
#include <QtWidgets/QMainWindow>

#include <opencv2/opencv.hpp>

#include "ui_data_augmentation.h"
#include "command_editor.h"
#include "command.h"

class DataAugmentationApp : public QMainWindow
{
	Q_OBJECT

public:
	DataAugmentationApp(QWidget *parent = Q_NULLPTR);

	~DataAugmentationApp() {};

	Command*& addNewCommand(int flag, CommandEditor* ce, std::initializer_list<double> il);

	Command*& addNewCommand(int flag, CommandEditor* ce, std::initializer_list<int> il);

	Command*& addNewCommand(int flag, CommandEditor* ce, std::initializer_list<bool> il);

	void resetCommand(int flag, CommandEditor* ce, std::initializer_list<double> il);

	void resetCommand(int flag, CommandEditor* ce, std::initializer_list<int> il);

	void resetCommand(int flag, CommandEditor* ce, std::initializer_list<bool> il);

	cv::Mat processImgAccordingToCommandList(cv::Mat& img);
	

private:
	Ui::DataAugmentationClass ui;
	cv::Mat m_demo_img;

	Command* createCommand(int flag, CommandEditor*ce, std::initializer_list<double> il);
	
	Command* createCommand(int flag, CommandEditor*ce, std::initializer_list<bool> il);

	Command* createCommand(int flag, CommandEditor*ce, std::initializer_list<int> il);

	void processImgAccordingToACommand(Command* cmd, cv::Mat& img);

private slots:

	void on_pb_addItemToCommandList_clicked();

	void on_commandList_itemDoubleClicked(QListWidgetItem *item);

	void on_pushButtonProcessDemo_clicked();

};
