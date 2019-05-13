#pragma once

#include <list>
#include <QtWidgets/QMainWindow>
#include "ui_data_augmentation.h"
#include "command_editor.h"

class DataAugmentationApp : public QMainWindow
{
	Q_OBJECT

public:
	DataAugmentationApp(QWidget *parent = Q_NULLPTR);
	~DataAugmentationApp();

private:
	Ui::DataAugmentationClass ui;
	
	std::list<CommandEditor*> m_p_commadn_editor_app_list;


private slots:
	void on_pb_addItemToCommandList_clicked();

};
