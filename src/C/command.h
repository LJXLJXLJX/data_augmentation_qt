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
	OP_MEADIAN_FILTER,
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

class CommandTranslate :public Command {
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

class CommandRotate :public Command {
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
