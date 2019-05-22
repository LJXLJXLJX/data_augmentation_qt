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
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DataAugmentationClass
{
public:
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QVBoxLayout *commandListLayout;
    QLabel *commandListLabel;
    QListWidget *commandList;
    QPushButton *pb_addItemToCommandList;
    QPushButton *pb_deleteItemFromCommandList;
    QPushButton *pushButtonProcessDemo;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *DataAugmentationClass)
    {
        if (DataAugmentationClass->objectName().isEmpty())
            DataAugmentationClass->setObjectName(QString::fromUtf8("DataAugmentationClass"));
        DataAugmentationClass->setEnabled(true);
        DataAugmentationClass->resize(534, 600);
        centralWidget = new QWidget(DataAugmentationClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(50, 30, 258, 453));
        commandListLayout = new QVBoxLayout(layoutWidget);
        commandListLayout->setSpacing(6);
        commandListLayout->setContentsMargins(11, 11, 11, 11);
        commandListLayout->setObjectName(QString::fromUtf8("commandListLayout"));
        commandListLayout->setContentsMargins(0, 0, 0, 0);
        commandListLabel = new QLabel(layoutWidget);
        commandListLabel->setObjectName(QString::fromUtf8("commandListLabel"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(commandListLabel->sizePolicy().hasHeightForWidth());
        commandListLabel->setSizePolicy(sizePolicy);
        commandListLabel->setLayoutDirection(Qt::LeftToRight);
        commandListLabel->setAlignment(Qt::AlignCenter);

        commandListLayout->addWidget(commandListLabel);

        commandList = new QListWidget(layoutWidget);
        commandList->setObjectName(QString::fromUtf8("commandList"));

        commandListLayout->addWidget(commandList);

        pb_addItemToCommandList = new QPushButton(layoutWidget);
        pb_addItemToCommandList->setObjectName(QString::fromUtf8("pb_addItemToCommandList"));

        commandListLayout->addWidget(pb_addItemToCommandList);

        pb_deleteItemFromCommandList = new QPushButton(layoutWidget);
        pb_deleteItemFromCommandList->setObjectName(QString::fromUtf8("pb_deleteItemFromCommandList"));

        commandListLayout->addWidget(pb_deleteItemFromCommandList);

        pushButtonProcessDemo = new QPushButton(centralWidget);
        pushButtonProcessDemo->setObjectName(QString::fromUtf8("pushButtonProcessDemo"));
        pushButtonProcessDemo->setGeometry(QRect(365, 216, 119, 23));
        DataAugmentationClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(DataAugmentationClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 534, 23));
        DataAugmentationClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(DataAugmentationClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        DataAugmentationClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(DataAugmentationClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        DataAugmentationClass->setStatusBar(statusBar);

        retranslateUi(DataAugmentationClass);

        QMetaObject::connectSlotsByName(DataAugmentationClass);
    } // setupUi

    void retranslateUi(QMainWindow *DataAugmentationClass)
    {
        DataAugmentationClass->setWindowTitle(QApplication::translate("DataAugmentationClass", "DataAugmentation", nullptr));
        commandListLabel->setText(QApplication::translate("DataAugmentationClass", "\345\242\236\345\274\272\345\221\275\344\273\244\345\210\227\350\241\250", nullptr));
        pb_addItemToCommandList->setText(QApplication::translate("DataAugmentationClass", "\346\267\273\345\212\240\345\221\275\344\273\244", nullptr));
        pb_deleteItemFromCommandList->setText(QApplication::translate("DataAugmentationClass", "\345\210\240\351\231\244\345\221\275\344\273\244", nullptr));
        pushButtonProcessDemo->setText(QApplication::translate("DataAugmentationClass", "\345\244\204\347\220\206\351\242\204\350\247\210\345\233\276\347\211\207", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DataAugmentationClass: public Ui_DataAugmentationClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATA_AUGMENTATION_H
