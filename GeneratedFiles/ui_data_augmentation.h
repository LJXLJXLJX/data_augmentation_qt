/********************************************************************************
** Form generated from reading UI file 'data_augmentation.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATA_AUGMENTATION_H
#define UI_DATA_AUGMENTATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DataAugmentationClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *DataAugmentationClass)
    {
        if (DataAugmentationClass->objectName().isEmpty())
            DataAugmentationClass->setObjectName(QString::fromUtf8("DataAugmentationClass"));
        DataAugmentationClass->resize(600, 400);
        menuBar = new QMenuBar(DataAugmentationClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        DataAugmentationClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(DataAugmentationClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        DataAugmentationClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(DataAugmentationClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        DataAugmentationClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(DataAugmentationClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        DataAugmentationClass->setStatusBar(statusBar);

        retranslateUi(DataAugmentationClass);

        QMetaObject::connectSlotsByName(DataAugmentationClass);
    } // setupUi

    void retranslateUi(QMainWindow *DataAugmentationClass)
    {
        DataAugmentationClass->setWindowTitle(QApplication::translate("DataAugmentationClass", "DataAugmentation", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DataAugmentationClass: public Ui_DataAugmentationClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATA_AUGMENTATION_H
