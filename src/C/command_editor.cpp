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
	std::vector<std::any> vec;
	int flag = -1;

	switch (ui.comboBox->currentIndex()) {
	case 0:
	{
		std::any x_min = ui.translateXSpinBoxMin->value();
		std::any x_max = ui.translateXSpinBoxMax->value();
		std::any y_min = ui.translateYSpinBoxMin->value();
		std::any y_max = ui.translateYSpinBoxMax->value();
		flag = OP_TRANSLATE;
		vec = { x_min,x_max,y_min,y_max };
		break;
	}
	case 1:
	{
		std::any theta_min = ui.rotateAngleMin->value();
		std::any theta_max = ui.rotateAngleMax->value();
		flag = OP_ROTATE;
		vec = { theta_min,theta_max };
		break;
	}
	case 2:
	{
		std::any x_min = ui.scalingXSpinBoxMin->value();
		std::any x_max = ui.scalingXSpinBoxMax->value();
		std::any y_min = ui.scalingYSpinBoxMin->value();
		std::any y_max = ui.scalingYSpinBoxMax->value();
		flag = OP_SCALING;
		vec = { x_min,y_max,y_min,y_max };
		break;
	}
	case 3:
	{
		std::any x = ui.flippingXcheckBox->isChecked();
		std::any y = ui.flippingYcheckBox->isChecked();
		flag = OP_FLIPPING;
		vec = { x,y };
		break;
	}
	case 4:
	{
		std::any kx_min = ui.gaussianFilterKxSpinBoxMin->value();
		std::any kx_max = ui.gaussianFilterKxSpinBoxMax->value();
		std::any ky_min = ui.gaussianFilterKySpinBoxMin->value();
		std::any ky_max = ui.gaussianFilterKySpinBoxMax->value();
		std::any sigmaX_min = ui.gaussianFilterSigmaXSpinBoxMin->value();
		std::any sigmaX_max = ui.gaussianFilterSigmaXSpinBoxMax->value();
		std::any sigmaY_min = ui.gaussianFilterSigmaYSpinBoxMin->value();
		std::any sigmaY_max = ui.gaussianFilterSigmaYSpinBoxMax->value();
		flag = OP_GAUSSIAN_FILTER;
		vec = { kx_min,kx_max,ky_min,ky_max,sigmaX_min,sigmaX_max,sigmaY_min,sigmaY_max };
		break;
	}
	case 5:
	{
		std::any ksize_min = ui.medianFilterKsizeSpinBoxMin->value();
		std::any ksize_max = ui.medianFilterKsizeSpinBoxMax->value();
		flag = OP_MEDIAN_FILTER;
		vec = { ksize_min,ksize_max };
		break;
	}
	case 6:
	{
		std::any kx_min = ui.meanFilterKxSpinBoxMin->value();
		std::any kx_max = ui.meanFilterKxSpinBoxMax->value();
		std::any ky_min = ui.meanFilterKySpinBoxMin->value();
		std::any ky_max = ui.meanFilterKySpinBoxMax->value();
		flag = OP_MEAN_FILTER;
		vec = { kx_min,kx_max,ky_min,ky_max };
		break;
	}
	case 7:
	{
		std::any d_min = ui.bilateralFilterDSpinBoxMin->value();
		std::any d_max = ui.bilateralFilterDSpinBoxMax->value();
		std::any sigma_color_min = ui.bilateralFilterSigmaColorSpinBoxMin->value();
		std::any sigma_color_max = ui.bilateralFilterSigmaColorSpinBoxMax->value();
		std::any sigma_space_min = ui.bilateralFilterSigmaSpaceSpinBoxMin->value();
		std::any sigma_space_max = ui.bilateralFilterSigmaSpaceSpinBoxMax->value();
		flag = OP_BILATERAL_FILTER;
		vec = { d_min,d_max,sigma_color_min,sigma_color_max,sigma_space_min,sigma_space_max };
		break;
	}
	case 8:
	{
		std::any mu_min = ui.gaussianNoiseMuSpinBoxMin->value();
		std::any mu_max = ui.gaussianNoiseMuSpinBoxMax->value();
		std::any sigma_min = ui.gaussianNoiseSigmaSpinBoxMin->value();
		std::any sigma_max = ui.gaussianNoiseSigmaSpinBoxMax->value();
		flag = OP_GAUSSIAN_NOISE;
		vec = { mu_min ,mu_max ,sigma_min ,sigma_max };
		break;
	}
	case 9:
	{
		std::any a = ui.uniformNoiseASpinBox->value();
		std::any b = ui.uniformNoiseBSpinBox->value();
		flag = OP_UNIFORM_NOISE;
		vec = { a,b };
		break;
	}
	case 10:
	{
		std::any alpha_min = ui.gammaNoiseAlphaSpinBoxMin->value();
		std::any alpha_max = ui.gammaNoiseAlphaSpinBoxMax->value();
		std::any beta_min = ui.gammaNoiseBetaSpinBoxMin->value();
		std::any beta_max = ui.gammaNoiseBetaSpinBoxMax->value();
		flag = OP_GAUSSIAN_FILTER;
		vec = { alpha_min,alpha_max,beta_min,beta_max };
		break;
	}
	}

	if (m_cmd == Q_NULLPTR) {
		Command* cmd = parent->addNewCommand(flag, this, vec);
		setCommand(cmd);
	}
	else {
		parent->resetCommand(flag, this, vec);
	}

	this->accept();
}

void CommandEditor::reject()
{
	qDebug() << "reject";

	QDialog::reject();
}






