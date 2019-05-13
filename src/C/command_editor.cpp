#include "command_editor.h"
#include <qdebug.h>


CommandEditor::CommandEditor(QWidget *parent)

{
	ui.setupUi(this);
	this->setFixedSize(400, 440);
	ui.stackedWidget->setCurrentIndex(ui.comboBox->currentIndex());
}

void CommandEditor::on_comboBox_currentIndexChanged()
{
	ui.stackedWidget->setCurrentIndex(ui.comboBox->currentIndex());
	qDebug() << "wtf";
}
