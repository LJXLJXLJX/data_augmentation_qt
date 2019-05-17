#include "command_editor.h"
#include "data_augmentation_app.h"
#include "command.h"
#include <qdebug.h>


CommandEditor::CommandEditor(QWidget *parent, Command* cmd)
	:QDialog(parent), m_cmd(cmd)
{
	ui.setupUi(this);
	this->setFixedSize(400, 440);
	ui.stackedWidget->setCurrentIndex(ui.comboBox->currentIndex());
}

void CommandEditor::on_comboBox_currentIndexChanged()
{
	ui.stackedWidget->setCurrentIndex(ui.comboBox->currentIndex());
}

Command * CommandEditor::getCommand()
{
	return m_cmd;
}

void CommandEditor::setCommand(Command * cmd)
{
	m_cmd = cmd;
}

void CommandEditor::on_commandEditorOKButton_clicked()
{
	DataAugmentationApp* parent = static_cast<DataAugmentationApp*>(this->parentWidget());
	std::initializer_list<double> il;
	int flag = -1;

	switch (ui.comboBox->currentIndex()) {
	case 0:
	{
		double x_min = ui.translateXSpinBoxMin->value();
		double x_max = ui.translateXSpinBoxMax->value();
		double y_min = ui.translateYSpinBoxMin->value();
		double y_max = ui.translateYSpinBoxMax->value();
		flag = OP_TRANSLATE;
		il = { x_min,y_max,y_min,y_max };
		break;
	}
	case 1:
	{
		double theta_min = ui.rotateAngleMin->value();
		double theta_max = ui.rotateAngleMax->value();
		flag = OP_ROTATE;
		il = { theta_min,theta_max };
		break;
	}
	case 2:
	{
		double x_min = ui.scalingXSpinBoxMin->value();
		double x_max = ui.scalingXSpinBoxMax->value();
		double y_min = ui.scalingYSpinBoxMin->value();
		double y_max = ui.scalingYSpinBoxMax->value();
		flag = OP_SCALING;
		il = { x_min,y_max,y_min,y_max };
		break;
	}
	case 3:
	{
		bool x = ui.flippingXcheckBox->isChecked();
		bool y = ui.flippingYcheckBox->isChecked();
		break;
	}



	}

	if (m_cmd == Q_NULLPTR) {
		Command* cmd = parent->addNewCommand(flag, this, il);
		setCommand(cmd);
	}
	else {
		parent->resetCommand(flag, this, il);
	}

	this->accept();
}

void CommandEditor::reject()
{
	qDebug() << "reject";

	QDialog::reject();
}






