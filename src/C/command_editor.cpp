#include "command_editor.h"
#include "data_augmentation_app.h"
#include "command.h"
#include <qdebug.h>
#include <qmessagebox.h>


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
		double x_min = ui.sbTranslateXMin->value();
		double x_max = ui.sbTranslateXMax->value();
		double y_min = ui.sbTranslateYMin->value();
		double y_max = ui.sbTranslateYMax->value();

		if (x_min > x_max || y_min > y_max) {
			QMessageBox::about(this, QString::fromLocal8Bit("参数错误"), QString::fromLocal8Bit(" 无效参数，请注意参数大小关系"));
			return;
		}

		flag = OP_TRANSLATE;
		vec = { x_min,x_max,y_min,y_max };
		break;
	}
	case 1:
	{
		double theta_min = ui.sbAngleMin->value();
		double theta_max = ui.sbAngleMax->value();

		if (theta_min > theta_max) {
			QMessageBox::about(this, QString::fromLocal8Bit("参数错误"), QString::fromLocal8Bit(" 无效参数，请注意参数大小关系"));
			return;
		}

		flag = OP_ROTATE;
		vec = { theta_min,theta_max };
		break;
	}
	case 2:
	{
		double x_min = ui.sbScalingXMin->value();
		double x_max = ui.sbScalingXMax->value();
		double y_min = ui.sbScalingYMin->value();
		double y_max = ui.sbScalingYMax->value();

		if (x_min > x_max || y_min > y_max) {
			QMessageBox::about(this, QString::fromLocal8Bit("参数错误"), QString::fromLocal8Bit(" 无效参数，请注意参数大小关系"));
			return;
		}

		flag = OP_SCALING;
		vec = { x_min,y_max,y_min,y_max };
		break;
	}
	case 3:
	{
		bool x = ui.cbFlippingX->isChecked();
		bool y = ui.cbFlippingY->isChecked();
		flag = OP_FLIPPING;
		vec = { x,y };
		break;
	}
	case 4:
	{
		int kx_min = ui.sbGaussianFilterKxMin->value();
		int kx_max = ui.sbGaussianFilterKxMax->value();
		int ky_min = ui.sbGaussianFilterKyMin->value();
		int ky_max = ui.sbGaussianFilterKyMax->value();
		double sigmaX_min = ui.sbGaussianFilterSigmaXMin->value();
		double sigmaX_max = ui.sbGaussianFilterSigmaXMax->value();
		double sigmaY_min = ui.sbGaussianFilterSigmaYMin->value();
		double sigmaY_max = ui.sbGaussianFilterSigmaYMax->value();

		if (kx_min > kx_max || ky_min > ky_max || sigmaX_min > sigmaX_max || sigmaY_min > sigmaY_max) {
			QMessageBox::about(this, QString::fromLocal8Bit("参数错误"), QString::fromLocal8Bit(" 无效参数，请注意参数大小关系"));
			return;
		}

		flag = OP_GAUSSIAN_FILTER;
		vec = { kx_min,kx_max,ky_min,ky_max,sigmaX_min,sigmaX_max,sigmaY_min,sigmaY_max };
		break;
	}
	case 5:
	{
		int ksize_min = ui.sbMedianFilterKsizeMin->value();
		int ksize_max = ui.sbMedianFilterKsizeMax->value();

		if (ksize_min > ksize_max) {
			QMessageBox::about(this, QString::fromLocal8Bit("参数错误"), QString::fromLocal8Bit(" 无效参数，请注意参数大小关系"));
			return;
		}

		flag = OP_MEDIAN_FILTER;
		vec = { ksize_min,ksize_max };
		break;
	}
	case 6:
	{
		int kx_min = ui.sbMeanFilterKxMin->value();
		int kx_max = ui.sbMeanFilterKxMax->value();
		int ky_min = ui.sbMeanFilterKyMin->value();
		int ky_max = ui.sbMeanFilterKyMax->value();

		if (kx_min > kx_max || ky_min > ky_max) {
			QMessageBox::about(this, QString::fromLocal8Bit("参数错误"), QString::fromLocal8Bit(" 无效参数，请注意参数大小关系"));
			return;
		}

		flag = OP_MEAN_FILTER;
		vec = { kx_min,kx_max,ky_min,ky_max };
		break;
	}
	case 7:
	{
		int d_min = ui.sbBilateralFilterDMin->value();
		int d_max = ui.sbBilateralFilterDMax->value();
		double sigma_color_min = ui.sbBilateralFilterSigmaColorMin->value();
		double sigma_color_max = ui.sbBilateralFilterSigmaColorMax->value();
		double sigma_space_min = ui.sbBilateralFilterSigmaSpaceMin->value();
		double sigma_space_max = ui.sbBilateralFilterSigmaSpaceMax->value();

		if (d_min > d_max || sigma_color_min > sigma_color_max || sigma_space_min > sigma_space_max) {
			QMessageBox::about(this, QString::fromLocal8Bit("参数错误"), QString::fromLocal8Bit(" 无效参数，请注意参数大小关系"));
			return;
		}

		flag = OP_BILATERAL_FILTER;
		vec = { d_min,d_max,sigma_color_min,sigma_color_max,sigma_space_min,sigma_space_max };
		break;
	}
	case 8:
	{
		double mu_min = ui.sbGaussianNoiseMuMin->value();
		double mu_max = ui.sbGaussianNoiseMuMax->value();
		double sigma_min = ui.sbGaussianNoiseSigmaMin->value();
		double sigma_max = ui.sbGaussianNoiseSigmaMax->value();

		if (mu_min > mu_max || sigma_min > sigma_max) {
			QMessageBox::about(this, QString::fromLocal8Bit("参数错误"), QString::fromLocal8Bit(" 无效参数，请注意参数大小关系"));
			return;
		}

		flag = OP_GAUSSIAN_NOISE;
		vec = { mu_min ,mu_max ,sigma_min ,sigma_max };
		break;
	}
	case 9:
	{
		int a = ui.sbUniformNoiseA->value();
		int b = ui.sbUniformNoiseB->value();

		if (a > b) {
			QMessageBox::about(this, QString::fromLocal8Bit("参数错误"), QString::fromLocal8Bit(" 无效参数，请注意参数大小关系"));
			return;
		}

		flag = OP_UNIFORM_NOISE;
		vec = { a,b };
		break;
	}
	case 10:
	{
		double alpha_min = ui.sbGammaNoiseAlphaMin->value();
		double alpha_max = ui.sbGammaNoiseAlphaMax->value();
		double beta_min = ui.sbGammaNoiseBetaMin->value();
		double beta_max = ui.sbGammaNoiseBetaMax->value();

		if (alpha_min > alpha_max || beta_min > beta_max) {
			QMessageBox::about(this, QString::fromLocal8Bit("参数错误"), QString::fromLocal8Bit(" 无效参数，请注意参数大小关系"));
			return;
		}

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






