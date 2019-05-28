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
	/*
	向命令队列中添加一条新命令
	*/

	void resetCommand(int flag, CommandEditor* ce, std::vector<std::any> vec);
	/*
	重新设置一条已经存在的命令
	*/


	cv::Mat processImgAccordingToCommandList(cv::Mat& img);
	/*
	根据命令队列来处理图像
	*/


private:
	Ui::DataAugmentationClass ui;
	cv::Mat m_demo_img;


	Command* createCommand(int flag, CommandEditor*ce, std::vector<std::any> vec);
	/*
	创建一个命令
	*/

	void processImgAccordingToACommand(Command* cmd, cv::Mat& img);
	/*
	根据一条命令来处理图像
	*/

	void processImgsInADirThread(const std::string input_dir, const std::string output_dir, int& count, int target_num);
	/*
	processImgsInADir 的辅助线程函数
	*/

	void processImgsInADir(std::string& input_dir, std::string& output_dir, int thread_num, int target_num);
	/*
	处理一个目录中的所有图像
	*/

	std::list<std::string> getImgsInADir(std::string& dir);
	/*
	获取一个目录下的所有图像文件
	*/

	std::list<std::string>getChildDir(std::string& dir);
	/*
	获取一个目录下的所有子目录
	从效率的角度妥协，若一个目录下一旦有非目录文件，则返回空链表
	*/

	std::list<std::string> getLeafDirs(std::string& dir);
	/*
	获取一个目录下的所有叶目录（无子目录的目录）
	*/



	std::mutex m_mutex;

	int m_processed_num;

private slots:

	void on_pbAddItemToCommandList_clicked();

	void on_pbDeleteItemFromCommandList_clicked();

	void on_commandList_itemDoubleClicked(QListWidgetItem *item);

	void on_pbProcessDemo_clicked();

	void on_pbSelectDemo_clicked();

	void on_pbSelectInputDir_clicked();

	void on_pbSelectOutputDir_clicked();

	void on_pbStart_clicked();
};
