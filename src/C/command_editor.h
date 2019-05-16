#pragma once
#include <QtWidgets/qwidget.h>
#include <QtWidgets/qmainwindow.h>
#include <ui_command_editor.h>



class Command;

class CommandEditor : public QDialog
{
	Q_OBJECT

public:
	CommandEditor(QWidget *parent, Command* cmd = Q_NULLPTR);

	Command* getCommand();

private:

	Ui::commandEditorClass ui;

	void setCommand(Command* cmd);

	Command* m_cmd;


private slots:
	void on_comboBox_currentIndexChanged();

	void on_commandEditorOKButton_clicked();

	void reject();
};
