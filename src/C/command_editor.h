#pragma once
#include <QtWidgets/qwidget.h>
#include <QtWidgets/qmainwindow.h>
#include <ui_command_editor.h>



class CommandEditor : public QDialog
{
	Q_OBJECT

public:
	CommandEditor(QWidget *parent = Q_NULLPTR);


private:
	Ui::commandEditorClass ui;

private slots:
	void on_comboBox_currentIndexChanged();
};
