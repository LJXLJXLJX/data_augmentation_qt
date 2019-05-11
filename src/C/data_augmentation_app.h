#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_data_augmentation.h"

class DataAugmentationApp : public QMainWindow
{
	Q_OBJECT

public:
	DataAugmentationApp(QWidget *parent = Q_NULLPTR);

private:
	Ui::DataAugmentationClass ui;
};
