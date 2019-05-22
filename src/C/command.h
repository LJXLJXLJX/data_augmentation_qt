#pragma once
#include <vector>
#include <any>

#include "command_editor.h"
#include "qlistwidget.h"
#include "qstring.h"




enum OpFlag {
	OP_TRANSLATE,
	OP_ROTATE,
	OP_SCALING,
	OP_FLIPPING,
	OP_GAUSSIAN_FILTER,
	OP_MEDIAN_FILTER,
	OP_MEAN_FILTER,
	OP_BILATERAL_FILTER,
	OP_GAUSSIAN_NOISE,
	OP_UNIFORM_NOISE,
	OP_GAMMA_NOISE
};


class Command : public QListWidgetItem {
public:
	Command(int flag, CommandEditor* ce, const char* text)
		:m_op_flag(flag), m_p_command_editor(ce), QListWidgetItem(QString::fromLocal8Bit(text)) {};

	virtual ~Command() {}

	virtual void setParams(std::vector<std::any>vec) {};


	CommandEditor*& getCommandEditor() {
		return m_p_command_editor;
	}

	int getFlag() {
		return m_op_flag;
	}

protected:
	int m_op_flag;
	CommandEditor* m_p_command_editor;
};

class CommandTranslate : public Command {
public:
	CommandTranslate(CommandEditor* p_ce, const char* text, std::vector<std::any>vec)
		:Command(OP_TRANSLATE, p_ce, text)
	{
		setParams(vec);
	}

	void setParams(std::vector<std::any>vec) {
		auto it =vec.begin();
		m_x_min = std::any_cast<double>(*it++);
		m_x_max = std::any_cast<double>(*it++);
		m_y_min = std::any_cast<double>(*it++);
		m_y_max = std::any_cast<double>(*it++);
	}
	double m_x_min;
	double m_x_max;
	double m_y_min;
	double m_y_max;
};

class CommandRotate : public Command {
public:
	CommandRotate(CommandEditor* p_ce, const char* text, std::vector<std::any>vec)
		:Command(OP_ROTATE, p_ce, text)
	{
		setParams(vec);
	}

	void setParams(std::vector<std::any>vec) {
		auto it =vec.begin();
		m_theta_min = std::any_cast<double>(*it++);
		m_theta_max = std::any_cast<double>(*it++);
	}
	double m_theta_min;
	double m_theta_max;
};

class CommandScaling : public Command {
public:
	CommandScaling(CommandEditor* p_ce, const char* text, std::vector<std::any>vec)
		:Command(OP_SCALING, p_ce, text)
	{
		setParams(vec);
	}

	void setParams(std::vector<std::any>vec) {
		auto it =vec.begin();
		m_x_min = std::any_cast<double>(*it++);
		m_x_max = std::any_cast<double>(*it++);
		m_y_min = std::any_cast<double>(*it++);
		m_y_max = std::any_cast<double>(*it++);
	}

	double m_x_min;
	double m_x_max;
	double m_y_min;
	double m_y_max;
};

class CommandFlipping : public Command {
public:
	CommandFlipping(CommandEditor* p_ce, const char* text, std::vector<std::any>vec)
		:Command(OP_FLIPPING, p_ce, text)
	{
		setParams(vec);
	}

	void setParams(std::vector<std::any>vec) {
		auto it =vec.begin();
		m_x = std::any_cast<bool>(*it++);
		m_y = std::any_cast<bool>(*it++);
	}
	bool m_x;
	bool m_y;
};

class CommandGaussianFilter : public Command {
public:
	CommandGaussianFilter(CommandEditor* p_ce, const char* text, std::vector<std::any> vec)
		:Command(OP_GAUSSIAN_FILTER, p_ce, text)
	{
		setParams(vec);
	}
	void setParams(std::vector<std::any>vec) {
		auto it =vec.begin();
		m_kx_min = std::any_cast<int>(*it++);
		m_kx_max = std::any_cast<int>(*it++);
		m_ky_min = std::any_cast<int>(*it++);
		m_ky_max = std::any_cast<int>(*it++);
		m_sigma_x_min = std::any_cast<double>(*it++);
		m_sigma_x_max = std::any_cast<double>(*it++);
		m_sigma_y_min = std::any_cast<double>(*it++);
		m_sigma_y_max = std::any_cast<double>(*it++);
	}
	int m_kx_min;
	int m_kx_max;
	int m_ky_min;
	int m_ky_max;
	double m_sigma_x_min;
	double m_sigma_x_max;
	double m_sigma_y_min;
	double m_sigma_y_max;
};

class CommandMedianFilter : public Command {
public:
	CommandMedianFilter(CommandEditor* p_ce, const char* text, std::vector<std::any> vec)
		:Command(OP_MEDIAN_FILTER, p_ce, text)
	{
		setParams(vec);
	}
	void setParams(std::vector<std::any>vec) {
		auto it =vec.begin();
		m_ksize_min = std::any_cast<int>(*it++);
		m_ksize_max = std::any_cast<int>(*it++);
	}
	int m_ksize_min;
	int m_ksize_max;
};


class CommandMeanFilter : public Command {
public:
	CommandMeanFilter(CommandEditor* p_ce, const char* text, std::vector<std::any> vec)
		:Command(OP_MEAN_FILTER, p_ce, text)
	{
		setParams(vec);
	}
	void setParams(std::vector<std::any>vec) {
		auto it =vec.begin();
		m_kx_min = std::any_cast<int>(*it++);
		m_kx_max = std::any_cast<int>(*it++);
		m_ky_min = std::any_cast<int>(*it++);
		m_ky_max = std::any_cast<int>(*it++);
	}
	int m_kx_min;
	int m_kx_max;
	int m_ky_min;
	int m_ky_max;
};

class CommandBilateralFilter : public Command {
public:
	CommandBilateralFilter(CommandEditor* p_ce, const char* text, std::vector<std::any> vec)
		:Command(OP_BILATERAL_FILTER, p_ce, text)
	{
		setParams(vec);
	}
	void setParams(std::vector<std::any>vec) {
		auto it =vec.begin();
		m_d_min = std::any_cast<int>(*it++);
		m_d_max = std::any_cast<int>(*it++);
		m_sigma_color_min = std::any_cast<double>(*it++);
		m_sigma_color_max = std::any_cast<double>(*it++);
		m_sigma_space_min = std::any_cast<double>(*it++);
		m_sigma_space_max = std::any_cast<double>(*it++);
	}
	int m_d_min;
	int m_d_max;
	double m_sigma_color_min;
	double m_sigma_color_max;
	double m_sigma_space_min;
	double m_sigma_space_max;
};

class CommandGaussianNoise : public Command {
public:
	CommandGaussianNoise(CommandEditor* p_ce, const char* text, std::vector<std::any> vec)
		:Command(OP_GAUSSIAN_NOISE, p_ce, text)
	{
		setParams(vec);
	}
	void setParams(std::vector<std::any>vec) {
		auto it =vec.begin();
		m_mu_min = std::any_cast<double>(*it++);
		m_mu_max = std::any_cast<double>(*it++);
		m_sigma_min = std::any_cast<double>(*it++);
		m_sigma_max = std::any_cast<double>(*it++);
	}
	double m_mu_min;
	double m_mu_max;
	double m_sigma_min;
	double m_sigma_max;
};

class CommandUniformNoise : public Command {
public:
	CommandUniformNoise(CommandEditor* p_ce, const char* text, std::vector<std::any> vec)
		:Command(OP_UNIFORM_NOISE, p_ce, text)
	{
		setParams(vec);
	}
	void setParams(std::vector<std::any>vec) {
		auto it =vec.begin();
		m_a = std::any_cast<double>(*it++);
		m_b = std::any_cast<double>(*it++);
	}
	double m_a;
	double m_b;
};

class CommandGammaNoise : public Command {
public:
	CommandGammaNoise(CommandEditor* p_ce, const char* text, std::vector<std::any> vec)
		:Command(OP_GAMMA_NOISE, p_ce, text)
	{
		setParams(vec);
	}
	void setParams(std::vector<std::any>vec) {
		auto it =vec.begin();
		m_alpha_min = std::any_cast<double>(*it++);
		m_alpha_max = std::any_cast<double>(*it++);
		m_beta_min = std::any_cast<double>(*it++);
		m_beta_max = std::any_cast<double>(*it++);
	}
	double m_alpha_min;
	double m_alpha_max;
	double m_beta_min;
	double m_beta_max;
};
