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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
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
    QPushButton *pbAddItemToCommandList;
    QPushButton *pbDeleteItemFromCommandList;
    QPushButton *pbProcessDemo;
    QPushButton *pbSelectDemo;
    QPushButton *pbSelectInputDir;
    QPushButton *pbSelectOutputDir;
    QLineEdit *leInputDir;
    QLineEdit *leOutputDir;
    QLabel *labelInputDir;
    QLabel *labelOutputDir;
    QLabel *labelThreadNum;
    QSpinBox *sbThreadNum;
    QLabel *labelNum;
    QSpinBox *sbNum;
    QPushButton *pbStart;
    QProgressBar *progressBar;

    void setupUi(QMainWindow *DataAugmentationClass)
    {
        if (DataAugmentationClass->objectName().isEmpty())
            DataAugmentationClass->setObjectName(QString::fromUtf8("DataAugmentationClass"));
        DataAugmentationClass->setEnabled(true);
        DataAugmentationClass->resize(830, 600);
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

        pbAddItemToCommandList = new QPushButton(layoutWidget);
        pbAddItemToCommandList->setObjectName(QString::fromUtf8("pbAddItemToCommandList"));

        commandListLayout->addWidget(pbAddItemToCommandList);

        pbDeleteItemFromCommandList = new QPushButton(layoutWidget);
        pbDeleteItemFromCommandList->setObjectName(QString::fromUtf8("pbDeleteItemFromCommandList"));

        commandListLayout->addWidget(pbDeleteItemFromCommandList);

        pbProcessDemo = new QPushButton(centralWidget);
        pbProcessDemo->setObjectName(QString::fromUtf8("pbProcessDemo"));
        pbProcessDemo->setGeometry(QRect(503, 150, 119, 23));
        pbSelectDemo = new QPushButton(centralWidget);
        pbSelectDemo->setObjectName(QString::fromUtf8("pbSelectDemo"));
        pbSelectDemo->setGeometry(QRect(503, 108, 118, 23));
        pbSelectInputDir = new QPushButton(centralWidget);
        pbSelectInputDir->setObjectName(QString::fromUtf8("pbSelectInputDir"));
        pbSelectInputDir->setGeometry(QRect(740, 247, 75, 23));
        pbSelectOutputDir = new QPushButton(centralWidget);
        pbSelectOutputDir->setObjectName(QString::fromUtf8("pbSelectOutputDir"));
        pbSelectOutputDir->setGeometry(QRect(740, 304, 75, 23));
        leInputDir = new QLineEdit(centralWidget);
        leInputDir->setObjectName(QString::fromUtf8("leInputDir"));
        leInputDir->setGeometry(QRect(394, 248, 342, 20));
        leInputDir->setReadOnly(true);
        leOutputDir = new QLineEdit(centralWidget);
        leOutputDir->setObjectName(QString::fromUtf8("leOutputDir"));
        leOutputDir->setGeometry(QRect(394, 306, 342, 20));
        leOutputDir->setReadOnly(true);
        labelInputDir = new QLabel(centralWidget);
        labelInputDir->setObjectName(QString::fromUtf8("labelInputDir"));
        labelInputDir->setGeometry(QRect(326, 252, 54, 12));
        labelOutputDir = new QLabel(centralWidget);
        labelOutputDir->setObjectName(QString::fromUtf8("labelOutputDir"));
        labelOutputDir->setGeometry(QRect(327, 310, 54, 12));
        labelThreadNum = new QLabel(centralWidget);
        labelThreadNum->setObjectName(QString::fromUtf8("labelThreadNum"));
        labelThreadNum->setGeometry(QRect(327, 360, 38, 16));
        sbThreadNum = new QSpinBox(centralWidget);
        sbThreadNum->setObjectName(QString::fromUtf8("sbThreadNum"));
        sbThreadNum->setGeometry(QRect(395, 355, 42, 22));
        sbThreadNum->setMinimum(1);
        sbThreadNum->setMaximum(8);
        labelNum = new QLabel(centralWidget);
        labelNum->setObjectName(QString::fromUtf8("labelNum"));
        labelNum->setGeometry(QRect(491, 361, 103, 16));
        sbNum = new QSpinBox(centralWidget);
        sbNum->setObjectName(QString::fromUtf8("sbNum"));
        sbNum->setGeometry(QRect(606, 357, 42, 22));
        sbNum->setMaximum(99999);
        sbNum->setSingleStep(100);
        pbStart = new QPushButton(centralWidget);
        pbStart->setObjectName(QString::fromUtf8("pbStart"));
        pbStart->setGeometry(QRect(528, 436, 75, 23));
        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setEnabled(true);
        progressBar->setGeometry(QRect(351, 502, 462, 23));
        progressBar->setValue(0);
        DataAugmentationClass->setCentralWidget(centralWidget);

        retranslateUi(DataAugmentationClass);

        QMetaObject::connectSlotsByName(DataAugmentationClass);
    } // setupUi

    void retranslateUi(QMainWindow *DataAugmentationClass)
    {
        DataAugmentationClass->setWindowTitle(QApplication::translate("DataAugmentationClass", "DataAugmentation", nullptr));
        commandListLabel->setText(QApplication::translate("DataAugmentationClass", "\345\242\236\345\274\272\345\221\275\344\273\244\345\210\227\350\241\250", nullptr));
        pbAddItemToCommandList->setText(QApplication::translate("DataAugmentationClass", "\346\267\273\345\212\240\345\221\275\344\273\244", nullptr));
        pbDeleteItemFromCommandList->setText(QApplication::translate("DataAugmentationClass", "\345\210\240\351\231\244\345\221\275\344\273\244", nullptr));
        pbProcessDemo->setText(QApplication::translate("DataAugmentationClass", "\345\244\204\347\220\206\351\242\204\350\247\210\345\233\276\347\211\207", nullptr));
        pbSelectDemo->setText(QApplication::translate("DataAugmentationClass", "\351\200\211\346\213\251\351\242\204\350\247\210\345\233\276\347\211\207", nullptr));
        pbSelectInputDir->setText(QApplication::translate("DataAugmentationClass", "\351\200\211\346\213\251\347\233\256\345\275\225", nullptr));
        pbSelectOutputDir->setText(QApplication::translate("DataAugmentationClass", "\351\200\211\346\213\251\347\233\256\345\275\225", nullptr));
        labelInputDir->setText(QApplication::translate("DataAugmentationClass", "\350\276\223\345\205\245\347\233\256\345\275\225", nullptr));
        labelOutputDir->setText(QApplication::translate("DataAugmentationClass", "\350\276\223\345\207\272\347\233\256\345\275\225", nullptr));
        labelThreadNum->setText(QApplication::translate("DataAugmentationClass", "\347\272\277\347\250\213\346\225\260", nullptr));
        labelNum->setText(QApplication::translate("DataAugmentationClass", "\346\257\217\344\270\252\347\233\256\345\275\225\345\242\236\345\274\272\346\225\260\351\207\217", nullptr));
        pbStart->setText(QApplication::translate("DataAugmentationClass", "\345\274\200\345\247\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DataAugmentationClass: public Ui_DataAugmentationClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATA_AUGMENTATION_H
