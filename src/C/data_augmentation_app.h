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

	Command*& addNewCommand(int flag, CommandEditor* ce, std::vector<std::any> vec);

	void resetCommand(int flag, CommandEditor* ce, std::vector<std::any> vec);


	cv::Mat processImgAccordingToCommandList(cv::Mat& img);
	

private:
	Ui::DataAugmentationClass ui;
	cv::Mat m_demo_img;

	Command* createCommand(int flag, CommandEditor*ce, std::vector<std::any> vec);

	void processImgAccordingToACommand(Command* cmd, cv::Mat& img);

private slots:

	void on_pb_addItemToCommandList_clicked();

	void on_pb_deleteItemFromCommandList_clicked();

	void on_commandList_itemDoubleClicked(QListWidgetItem *item);

	void on_pushButtonProcessDemo_clicked();

};
