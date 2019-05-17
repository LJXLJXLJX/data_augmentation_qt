#pragma once
#include <initializer_list>

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

	virtual void setParams(std::initializer_list<double> il) {};

	virtual void setParams(std::initializer_list<bool> il) {};

	virtual void setParams(std::initializer_list<int> il) {};

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
	CommandTranslate(CommandEditor* p_ce, const char* text, std::initializer_list<double> il)
		:Command(OP_TRANSLATE, p_ce, text)
	{
		setParams(il);
	}

	void setParams(std::initializer_list<double> il) {
		auto it = il.begin();
		m_x_min = *it++;
		m_x_max = *it++;
		m_y_min = *it++;
		m_y_max = *it++;
	}
	double m_x_min;
	double m_x_max;
	double m_y_min;
	double m_y_max;
};

class CommandRotate : public Command {
public:
	CommandRotate(CommandEditor* p_ce, const char* text, std::initializer_list<double> il)
		:Command(OP_ROTATE, p_ce, text)
	{
		setParams(il);
	}

	void setParams(std::initializer_list<double> il) {
		auto it = il.begin();
		m_theta_min = *it++;
		m_theta_max = *it++;
	}
	double m_theta_min;
	double m_theta_max;
};

class CommandScaling : public Command {
public:
	CommandScaling(CommandEditor* p_ce, const char* text, std::initializer_list<double> il)
		:Command(OP_SCALING, p_ce, text)
	{
		setParams(il);
	}

	void setParams(std::initializer_list<double> il) {
		auto it = il.begin();
		m_x_min = *it++;
		m_x_max = *it++;
		m_y_min = *it++;
		m_y_max = *it++;
	}

	double m_x_min;
	double m_x_max;
	double m_y_min;
	double m_y_max;
};

class CommandFlipping : public Command {
public:
	CommandFlipping(CommandEditor* p_ce, const char* text, std::initializer_list<bool> il)
		:Command(OP_FLIPPING, p_ce, text)
	{
		setParams(il);
	}

	void setParams(std::initializer_list<bool> il) {
		auto it = il.begin();
		m_x = *it++;
		m_y = *it++;
	}
	bool m_x;
	bool m_y;
};

class CommandGaussianFilter : public Command {
public:
	CommandGaussianFilter(CommandEditor* p_ce, const char* text, std::initializer_list<double>il)
		:Command(OP_GAUSSIAN_FILTER, p_ce, text)
	{
		setParams(il);
	}
	void setParams(std::initializer_list<double> il) {
		auto it = il.begin();
		m_kx_min = static_cast<int>(round(*it++));
		m_kx_max = static_cast<int>(round(*it++));
		m_ky_min = static_cast<int>(round(*it++));
		m_ky_max = static_cast<int>(round(*it++));
		m_sigma_x_min = *it++;
		m_sigma_x_max = *it++;
		m_sigma_y_min = *it++;
		m_sigma_y_max = *it++;
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
	CommandMedianFilter(CommandEditor* p_ce, const char* text, std::initializer_list<int>il)
		:Command(OP_MEDIAN_FILTER, p_ce, text)
	{
		setParams(il);
	}
	void setParams(std::initializer_list<int> il) {
		auto it = il.begin();
		m_ksize_min = *it++;
		m_ksize_max = *it++;
	}
	int m_ksize_min;
	int m_ksize_max;
};


class CommandMeanFilter : public Command {
public:
	CommandMeanFilter(CommandEditor* p_ce, const char* text, std::initializer_list<int>il)
		:Command(OP_MEAN_FILTER, p_ce, text)
	{
		setParams(il);
	}
	void setParams(std::initializer_list<int> il) {
		auto it = il.begin();
		m_kx_min = *it++;
		m_kx_max = *it++;
		m_ky_min = *it++;
		m_ky_max = *it++;
	}
	int m_kx_min;
	int m_kx_max;
	int m_ky_min;
	int m_ky_max;
};

class CommandBilateralFilter : public Command {
public:
	CommandBilateralFilter(CommandEditor* p_ce, const char* text, std::initializer_list<double>il)
		:Command(OP_BILATERAL_FILTER, p_ce, text)
	{
		setParams(il);
	}
	void setParams(std::initializer_list<double> il) {
		auto it = il.begin();
		m_d_min = static_cast<int>(round(*it++));
		m_d_max = static_cast<int>(round(*it++));
		m_sigma_color_min = *it++;
		m_sigma_color_max = *it++;
		m_sigma_space_min = *it++;
		m_sigma_space_max = *it++;
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
	CommandGaussianNoise(CommandEditor* p_ce, const char* text, std::initializer_list<double>il)
		:Command(OP_GAUSSIAN_NOISE, p_ce, text)
	{
		setParams(il);
	}
	void setParams(std::initializer_list<double> il) {
		auto it = il.begin();
		m_mu_min = *it++;
		m_mu_max = *it++;
		m_sigma_min = *it++;
		m_sigma_max = *it++;
	}
	double m_mu_min;
	double m_mu_max;
	double m_sigma_min;
	double m_sigma_max;
};

class CommandUniformNoise : public Command {
public:
	CommandUniformNoise(CommandEditor* p_ce, const char* text, std::initializer_list<double>il)
		:Command(OP_UNIFORM_NOISE, p_ce, text)
	{
		setParams(il);
	}
	void setParams(std::initializer_list<double> il) {
		auto it = il.begin();
		m_a = *it++;
		m_b = *it++;
	}
	double m_a;
	double m_b;
};

class CommandGammaNoise : public Command {
public:
	CommandGammaNoise(CommandEditor* p_ce, const char* text, std::initializer_list<double>il)
		:Command(OP_GAMMA_NOISE, p_ce, text)
	{
		setParams(il);
	}
	void setParams(std::initializer_list<double> il) {
		auto it = il.begin();
		m_alpha_min = *it++;
		m_alpha_max = *it++;
		m_beta_min = *it++;
		m_beta_max = *it++;
	}
	double m_alpha_min;
	double m_alpha_max;
	double m_beta_min;
	double m_beta_max;
};
