#include "data_augmentation_app.h"


DataAugmentationApp::DataAugmentationApp(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	setFixedSize(800, 600);
	qDebug("UI done");

}

void DataAugmentationApp::on_pb_addItemToCommandList_clicked()
{
	qDebug("clicked");
	CommandEditor* ce = new CommandEditor(this);
	ce->exec();
	m_p_commadn_editor_app_list.push_back(ce);
}

DataAugmentationApp::~DataAugmentationApp()
{
	for (auto ptr : m_p_commadn_editor_app_list)
		delete ptr;
}
