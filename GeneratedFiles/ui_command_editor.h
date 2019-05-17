/********************************************************************************
** Form generated from reading UI file 'command_editor.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMMAND_EDITOR_H
#define UI_COMMAND_EDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_commandEditorClass
{
public:
    QStackedWidget *stackedWidget;
    QWidget *pageTranslate;
    QDoubleSpinBox *translateXSpinBoxMin;
    QDoubleSpinBox *translateYSpinBoxMin;
    QLabel *tranlateXLabel;
    QLabel *translateYLabel;
    QDoubleSpinBox *translateXSpinBoxMax;
    QDoubleSpinBox *translateYSpinBoxMax;
    QWidget *pageRotate;
    QDoubleSpinBox *rotateAngleMin;
    QLabel *rotateLabel;
    QDoubleSpinBox *rotateAngleMax;
    QWidget *pageScaling;
    QLabel *scalingXlabel;
    QDoubleSpinBox *scalingXSpinBoxMin;
    QLabel *scalingYLabel;
    QDoubleSpinBox *scalingYSpinBoxMin;
    QDoubleSpinBox *scalingXSpinBoxMax;
    QDoubleSpinBox *scalingYSpinBoxMax;
    QWidget *pageFlipping;
    QCheckBox *flippingXcheckBox;
    QCheckBox *flippingYcheckBox;
    QWidget *pageGaussianFilter;
    QLabel *gaussianFilterKxLable;
    QSpinBox *gaussianFilterKxSpinBoxMin;
    QSpinBox *gaussianFilterKxLableSpinBoxMin;
    QLabel *gaussianFilterKyLable;
    QLabel *gaussianFilterSigmaXLable;
    QDoubleSpinBox *gaussianFilterSigmaXSpinBoxMin;
    QLabel *gaussianFilterSigmaYLable;
    QDoubleSpinBox *gaussianFilterSigmaYSpinBoxMin;
    QSpinBox *gaussianFilterKxLableSpinBoxMax;
    QDoubleSpinBox *gaussianFilterSigmaYSpinBoxMax;
    QSpinBox *gaussianFilterKxSpinBoxMax;
    QDoubleSpinBox *gaussianFilterSigmaXSpinBoxMax;
    QWidget *pageMedianFilter;
    QLabel *medianFilterKsizeLabel;
    QSpinBox *medianFilterKsizeSpinBoxMin;
    QSpinBox *medianFilterKsizeSpinBoxMax;
    QWidget *pageMeanFilter;
    QSpinBox *meanFilterKySpinBoxMin;
    QSpinBox *meanFilterKxSpinBoxMin;
    QSpinBox *meanFilterKxSpinBoxMax;
    QLabel *meanFilterKyLabel;
    QLabel *meanFilterKxLabel;
    QSpinBox *meanFilterKySpinBoxMax;
    QWidget *pageBilateralFilter;
    QLabel *bilateralFilterSigmaColorLabel;
    QDoubleSpinBox *bilateralFilterSigmaSpaceSpinBoxMin;
    QLabel *bilateralFilterSigmaSpaceLabel;
    QDoubleSpinBox *bilateralFilterSigmaColorSpinBoxMin;
    QDoubleSpinBox *bilateralFilterSigmaColorSpinBoxMax;
    QDoubleSpinBox *bilateralFilterSigmaSpaceSpinBoxMax;
    QSpinBox *bilateralFilterDSpinBoxMin;
    QSpinBox *bilateralFilterDSpinBoxMax;
    QLabel *bilateralFilterDLabel;
    QWidget *pageGaussianNoise;
    QDoubleSpinBox *gaussianNoiseMuSpinBoxMin;
    QLabel *gaussianNoiseMuLabel;
    QDoubleSpinBox *gaussianNoiseMuSpinBoxMax;
    QDoubleSpinBox *gaussianNoiseSigmaSpinBoxMin;
    QLabel *gaussianNoiseSigmaLabel;
    QDoubleSpinBox *gaussianNoiseSigmaSpinBoxMax;
    QWidget *pageUniformNoise;
    QDoubleSpinBox *uniformNoiseASpinBox;
    QDoubleSpinBox *uniformNoiseBSpinBox;
    QLabel *uniformNoiseBLabel;
    QLabel *uniformNoiseALabel;
    QWidget *pageGammaNoise;
    QDoubleSpinBox *gammaNoiseAlphaSpinBoxMin;
    QDoubleSpinBox *gammaNoiseBetaSpinBoxMax;
    QDoubleSpinBox *gammaNoiseBetaSpinBoxMin;
    QDoubleSpinBox *gammaNoiseAlphaSpinBoxMax;
    QLabel *gammaNoiseBetaLabel;
    QLabel *gammaNoiseAlphaLabel;
    QComboBox *comboBox;
    QPushButton *commandEditorOKButton;

    void setupUi(QDialog *commandEditorClass)
    {
        if (commandEditorClass->objectName().isEmpty())
            commandEditorClass->setObjectName(QString::fromUtf8("commandEditorClass"));
        commandEditorClass->resize(400, 440);
        stackedWidget = new QStackedWidget(commandEditorClass);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(70, 110, 261, 261));
        pageTranslate = new QWidget();
        pageTranslate->setObjectName(QString::fromUtf8("pageTranslate"));
        translateXSpinBoxMin = new QDoubleSpinBox(pageTranslate);
        translateXSpinBoxMin->setObjectName(QString::fromUtf8("translateXSpinBoxMin"));
        translateXSpinBoxMin->setGeometry(QRect(65, 76, 71, 22));
        translateXSpinBoxMin->setMaximum(1.000000000000000);
        translateXSpinBoxMin->setSingleStep(0.100000000000000);
        translateYSpinBoxMin = new QDoubleSpinBox(pageTranslate);
        translateYSpinBoxMin->setObjectName(QString::fromUtf8("translateYSpinBoxMin"));
        translateYSpinBoxMin->setGeometry(QRect(63, 145, 71, 22));
        translateYSpinBoxMin->setMaximum(1.000000000000000);
        translateYSpinBoxMin->setSingleStep(0.100000000000000);
        tranlateXLabel = new QLabel(pageTranslate);
        tranlateXLabel->setObjectName(QString::fromUtf8("tranlateXLabel"));
        tranlateXLabel->setGeometry(QRect(40, 80, 20, 16));
        translateYLabel = new QLabel(pageTranslate);
        translateYLabel->setObjectName(QString::fromUtf8("translateYLabel"));
        translateYLabel->setGeometry(QRect(40, 150, 18, 16));
        translateXSpinBoxMax = new QDoubleSpinBox(pageTranslate);
        translateXSpinBoxMax->setObjectName(QString::fromUtf8("translateXSpinBoxMax"));
        translateXSpinBoxMax->setGeometry(QRect(154, 76, 71, 22));
        translateXSpinBoxMax->setMaximum(1.000000000000000);
        translateXSpinBoxMax->setSingleStep(0.100000000000000);
        translateYSpinBoxMax = new QDoubleSpinBox(pageTranslate);
        translateYSpinBoxMax->setObjectName(QString::fromUtf8("translateYSpinBoxMax"));
        translateYSpinBoxMax->setGeometry(QRect(152, 145, 71, 22));
        translateYSpinBoxMax->setMaximum(1.000000000000000);
        translateYSpinBoxMax->setSingleStep(0.100000000000000);
        stackedWidget->addWidget(pageTranslate);
        pageRotate = new QWidget();
        pageRotate->setObjectName(QString::fromUtf8("pageRotate"));
        rotateAngleMin = new QDoubleSpinBox(pageRotate);
        rotateAngleMin->setObjectName(QString::fromUtf8("rotateAngleMin"));
        rotateAngleMin->setGeometry(QRect(94, 119, 62, 22));
        rotateAngleMin->setMinimum(-360.000000000000000);
        rotateAngleMin->setMaximum(360.000000000000000);
        rotateLabel = new QLabel(pageRotate);
        rotateLabel->setObjectName(QString::fromUtf8("rotateLabel"));
        rotateLabel->setGeometry(QRect(14, 124, 54, 12));
        rotateAngleMax = new QDoubleSpinBox(pageRotate);
        rotateAngleMax->setObjectName(QString::fromUtf8("rotateAngleMax"));
        rotateAngleMax->setGeometry(QRect(172, 119, 62, 22));
        rotateAngleMax->setMinimum(-360.000000000000000);
        rotateAngleMax->setMaximum(360.000000000000000);
        stackedWidget->addWidget(pageRotate);
        pageScaling = new QWidget();
        pageScaling->setObjectName(QString::fromUtf8("pageScaling"));
        scalingXlabel = new QLabel(pageScaling);
        scalingXlabel->setObjectName(QString::fromUtf8("scalingXlabel"));
        scalingXlabel->setGeometry(QRect(41, 106, 25, 16));
        scalingXSpinBoxMin = new QDoubleSpinBox(pageScaling);
        scalingXSpinBoxMin->setObjectName(QString::fromUtf8("scalingXSpinBoxMin"));
        scalingXSpinBoxMin->setGeometry(QRect(70, 102, 62, 22));
        scalingYLabel = new QLabel(pageScaling);
        scalingYLabel->setObjectName(QString::fromUtf8("scalingYLabel"));
        scalingYLabel->setGeometry(QRect(41, 151, 25, 16));
        scalingYSpinBoxMin = new QDoubleSpinBox(pageScaling);
        scalingYSpinBoxMin->setObjectName(QString::fromUtf8("scalingYSpinBoxMin"));
        scalingYSpinBoxMin->setGeometry(QRect(70, 147, 62, 22));
        scalingXSpinBoxMax = new QDoubleSpinBox(pageScaling);
        scalingXSpinBoxMax->setObjectName(QString::fromUtf8("scalingXSpinBoxMax"));
        scalingXSpinBoxMax->setGeometry(QRect(151, 102, 62, 22));
        scalingYSpinBoxMax = new QDoubleSpinBox(pageScaling);
        scalingYSpinBoxMax->setObjectName(QString::fromUtf8("scalingYSpinBoxMax"));
        scalingYSpinBoxMax->setGeometry(QRect(151, 147, 62, 22));
        stackedWidget->addWidget(pageScaling);
        pageFlipping = new QWidget();
        pageFlipping->setObjectName(QString::fromUtf8("pageFlipping"));
        flippingXcheckBox = new QCheckBox(pageFlipping);
        flippingXcheckBox->setObjectName(QString::fromUtf8("flippingXcheckBox"));
        flippingXcheckBox->setGeometry(QRect(100, 90, 71, 16));
        flippingYcheckBox = new QCheckBox(pageFlipping);
        flippingYcheckBox->setObjectName(QString::fromUtf8("flippingYcheckBox"));
        flippingYcheckBox->setGeometry(QRect(100, 140, 71, 16));
        stackedWidget->addWidget(pageFlipping);
        pageGaussianFilter = new QWidget();
        pageGaussianFilter->setObjectName(QString::fromUtf8("pageGaussianFilter"));
        gaussianFilterKxLable = new QLabel(pageGaussianFilter);
        gaussianFilterKxLable->setObjectName(QString::fromUtf8("gaussianFilterKxLable"));
        gaussianFilterKxLable->setGeometry(QRect(20, 65, 54, 12));
        gaussianFilterKxSpinBoxMin = new QSpinBox(pageGaussianFilter);
        gaussianFilterKxSpinBoxMin->setObjectName(QString::fromUtf8("gaussianFilterKxSpinBoxMin"));
        gaussianFilterKxSpinBoxMin->setGeometry(QRect(110, 60, 42, 22));
        gaussianFilterKxSpinBoxMin->setMinimum(1);
        gaussianFilterKxLableSpinBoxMin = new QSpinBox(pageGaussianFilter);
        gaussianFilterKxLableSpinBoxMin->setObjectName(QString::fromUtf8("gaussianFilterKxLableSpinBoxMin"));
        gaussianFilterKxLableSpinBoxMin->setGeometry(QRect(110, 100, 42, 22));
        gaussianFilterKxLableSpinBoxMin->setMinimum(1);
        gaussianFilterKyLable = new QLabel(pageGaussianFilter);
        gaussianFilterKyLable->setObjectName(QString::fromUtf8("gaussianFilterKyLable"));
        gaussianFilterKyLable->setGeometry(QRect(20, 105, 54, 12));
        gaussianFilterSigmaXLable = new QLabel(pageGaussianFilter);
        gaussianFilterSigmaXLable->setObjectName(QString::fromUtf8("gaussianFilterSigmaXLable"));
        gaussianFilterSigmaXLable->setGeometry(QRect(20, 145, 54, 12));
        gaussianFilterSigmaXSpinBoxMin = new QDoubleSpinBox(pageGaussianFilter);
        gaussianFilterSigmaXSpinBoxMin->setObjectName(QString::fromUtf8("gaussianFilterSigmaXSpinBoxMin"));
        gaussianFilterSigmaXSpinBoxMin->setGeometry(QRect(100, 140, 62, 22));
        gaussianFilterSigmaYLable = new QLabel(pageGaussianFilter);
        gaussianFilterSigmaYLable->setObjectName(QString::fromUtf8("gaussianFilterSigmaYLable"));
        gaussianFilterSigmaYLable->setGeometry(QRect(20, 180, 54, 12));
        gaussianFilterSigmaYSpinBoxMin = new QDoubleSpinBox(pageGaussianFilter);
        gaussianFilterSigmaYSpinBoxMin->setObjectName(QString::fromUtf8("gaussianFilterSigmaYSpinBoxMin"));
        gaussianFilterSigmaYSpinBoxMin->setGeometry(QRect(100, 175, 62, 22));
        gaussianFilterKxLableSpinBoxMax = new QSpinBox(pageGaussianFilter);
        gaussianFilterKxLableSpinBoxMax->setObjectName(QString::fromUtf8("gaussianFilterKxLableSpinBoxMax"));
        gaussianFilterKxLableSpinBoxMax->setGeometry(QRect(200, 100, 42, 22));
        gaussianFilterKxLableSpinBoxMax->setMinimum(1);
        gaussianFilterSigmaYSpinBoxMax = new QDoubleSpinBox(pageGaussianFilter);
        gaussianFilterSigmaYSpinBoxMax->setObjectName(QString::fromUtf8("gaussianFilterSigmaYSpinBoxMax"));
        gaussianFilterSigmaYSpinBoxMax->setGeometry(QRect(190, 175, 62, 22));
        gaussianFilterKxSpinBoxMax = new QSpinBox(pageGaussianFilter);
        gaussianFilterKxSpinBoxMax->setObjectName(QString::fromUtf8("gaussianFilterKxSpinBoxMax"));
        gaussianFilterKxSpinBoxMax->setGeometry(QRect(200, 60, 42, 22));
        gaussianFilterKxSpinBoxMax->setMinimum(1);
        gaussianFilterSigmaXSpinBoxMax = new QDoubleSpinBox(pageGaussianFilter);
        gaussianFilterSigmaXSpinBoxMax->setObjectName(QString::fromUtf8("gaussianFilterSigmaXSpinBoxMax"));
        gaussianFilterSigmaXSpinBoxMax->setGeometry(QRect(190, 140, 62, 22));
        stackedWidget->addWidget(pageGaussianFilter);
        pageMedianFilter = new QWidget();
        pageMedianFilter->setObjectName(QString::fromUtf8("pageMedianFilter"));
        medianFilterKsizeLabel = new QLabel(pageMedianFilter);
        medianFilterKsizeLabel->setObjectName(QString::fromUtf8("medianFilterKsizeLabel"));
        medianFilterKsizeLabel->setGeometry(QRect(26, 129, 54, 16));
        medianFilterKsizeSpinBoxMin = new QSpinBox(pageMedianFilter);
        medianFilterKsizeSpinBoxMin->setObjectName(QString::fromUtf8("medianFilterKsizeSpinBoxMin"));
        medianFilterKsizeSpinBoxMin->setGeometry(QRect(116, 124, 42, 22));
        medianFilterKsizeSpinBoxMin->setMinimum(1);
        medianFilterKsizeSpinBoxMax = new QSpinBox(pageMedianFilter);
        medianFilterKsizeSpinBoxMax->setObjectName(QString::fromUtf8("medianFilterKsizeSpinBoxMax"));
        medianFilterKsizeSpinBoxMax->setGeometry(QRect(206, 124, 42, 22));
        medianFilterKsizeSpinBoxMax->setMinimum(1);
        stackedWidget->addWidget(pageMedianFilter);
        pageMeanFilter = new QWidget();
        pageMeanFilter->setObjectName(QString::fromUtf8("pageMeanFilter"));
        meanFilterKySpinBoxMin = new QSpinBox(pageMeanFilter);
        meanFilterKySpinBoxMin->setObjectName(QString::fromUtf8("meanFilterKySpinBoxMin"));
        meanFilterKySpinBoxMin->setGeometry(QRect(113, 144, 42, 22));
        meanFilterKySpinBoxMin->setMinimum(1);
        meanFilterKxSpinBoxMin = new QSpinBox(pageMeanFilter);
        meanFilterKxSpinBoxMin->setObjectName(QString::fromUtf8("meanFilterKxSpinBoxMin"));
        meanFilterKxSpinBoxMin->setGeometry(QRect(113, 104, 42, 22));
        meanFilterKxSpinBoxMin->setMinimum(1);
        meanFilterKxSpinBoxMax = new QSpinBox(pageMeanFilter);
        meanFilterKxSpinBoxMax->setObjectName(QString::fromUtf8("meanFilterKxSpinBoxMax"));
        meanFilterKxSpinBoxMax->setGeometry(QRect(203, 104, 42, 22));
        meanFilterKxSpinBoxMax->setMinimum(1);
        meanFilterKyLabel = new QLabel(pageMeanFilter);
        meanFilterKyLabel->setObjectName(QString::fromUtf8("meanFilterKyLabel"));
        meanFilterKyLabel->setGeometry(QRect(23, 149, 54, 12));
        meanFilterKxLabel = new QLabel(pageMeanFilter);
        meanFilterKxLabel->setObjectName(QString::fromUtf8("meanFilterKxLabel"));
        meanFilterKxLabel->setGeometry(QRect(23, 109, 54, 12));
        meanFilterKySpinBoxMax = new QSpinBox(pageMeanFilter);
        meanFilterKySpinBoxMax->setObjectName(QString::fromUtf8("meanFilterKySpinBoxMax"));
        meanFilterKySpinBoxMax->setGeometry(QRect(203, 144, 42, 22));
        meanFilterKySpinBoxMax->setMinimum(1);
        stackedWidget->addWidget(pageMeanFilter);
        pageBilateralFilter = new QWidget();
        pageBilateralFilter->setObjectName(QString::fromUtf8("pageBilateralFilter"));
        bilateralFilterSigmaColorLabel = new QLabel(pageBilateralFilter);
        bilateralFilterSigmaColorLabel->setObjectName(QString::fromUtf8("bilateralFilterSigmaColorLabel"));
        bilateralFilterSigmaColorLabel->setGeometry(QRect(18, 124, 68, 16));
        bilateralFilterSigmaSpaceSpinBoxMin = new QDoubleSpinBox(pageBilateralFilter);
        bilateralFilterSigmaSpaceSpinBoxMin->setObjectName(QString::fromUtf8("bilateralFilterSigmaSpaceSpinBoxMin"));
        bilateralFilterSigmaSpaceSpinBoxMin->setGeometry(QRect(98, 154, 62, 22));
        bilateralFilterSigmaSpaceLabel = new QLabel(pageBilateralFilter);
        bilateralFilterSigmaSpaceLabel->setObjectName(QString::fromUtf8("bilateralFilterSigmaSpaceLabel"));
        bilateralFilterSigmaSpaceLabel->setGeometry(QRect(18, 159, 65, 16));
        bilateralFilterSigmaColorSpinBoxMin = new QDoubleSpinBox(pageBilateralFilter);
        bilateralFilterSigmaColorSpinBoxMin->setObjectName(QString::fromUtf8("bilateralFilterSigmaColorSpinBoxMin"));
        bilateralFilterSigmaColorSpinBoxMin->setGeometry(QRect(98, 119, 62, 22));
        bilateralFilterSigmaColorSpinBoxMax = new QDoubleSpinBox(pageBilateralFilter);
        bilateralFilterSigmaColorSpinBoxMax->setObjectName(QString::fromUtf8("bilateralFilterSigmaColorSpinBoxMax"));
        bilateralFilterSigmaColorSpinBoxMax->setGeometry(QRect(188, 119, 62, 22));
        bilateralFilterSigmaSpaceSpinBoxMax = new QDoubleSpinBox(pageBilateralFilter);
        bilateralFilterSigmaSpaceSpinBoxMax->setObjectName(QString::fromUtf8("bilateralFilterSigmaSpaceSpinBoxMax"));
        bilateralFilterSigmaSpaceSpinBoxMax->setGeometry(QRect(188, 154, 62, 22));
        bilateralFilterDSpinBoxMin = new QSpinBox(pageBilateralFilter);
        bilateralFilterDSpinBoxMin->setObjectName(QString::fromUtf8("bilateralFilterDSpinBoxMin"));
        bilateralFilterDSpinBoxMin->setGeometry(QRect(110, 83, 42, 22));
        bilateralFilterDSpinBoxMin->setMinimum(1);
        bilateralFilterDSpinBoxMax = new QSpinBox(pageBilateralFilter);
        bilateralFilterDSpinBoxMax->setObjectName(QString::fromUtf8("bilateralFilterDSpinBoxMax"));
        bilateralFilterDSpinBoxMax->setGeometry(QRect(200, 83, 42, 22));
        bilateralFilterDSpinBoxMax->setMinimum(1);
        bilateralFilterDLabel = new QLabel(pageBilateralFilter);
        bilateralFilterDLabel->setObjectName(QString::fromUtf8("bilateralFilterDLabel"));
        bilateralFilterDLabel->setGeometry(QRect(20, 88, 54, 12));
        stackedWidget->addWidget(pageBilateralFilter);
        pageGaussianNoise = new QWidget();
        pageGaussianNoise->setObjectName(QString::fromUtf8("pageGaussianNoise"));
        gaussianNoiseMuSpinBoxMin = new QDoubleSpinBox(pageGaussianNoise);
        gaussianNoiseMuSpinBoxMin->setObjectName(QString::fromUtf8("gaussianNoiseMuSpinBoxMin"));
        gaussianNoiseMuSpinBoxMin->setGeometry(QRect(93, 97, 62, 22));
        gaussianNoiseMuSpinBoxMin->setMinimum(-500.000000000000000);
        gaussianNoiseMuSpinBoxMin->setMaximum(500.000000000000000);
        gaussianNoiseMuLabel = new QLabel(pageGaussianNoise);
        gaussianNoiseMuLabel->setObjectName(QString::fromUtf8("gaussianNoiseMuLabel"));
        gaussianNoiseMuLabel->setGeometry(QRect(13, 102, 65, 16));
        gaussianNoiseMuSpinBoxMax = new QDoubleSpinBox(pageGaussianNoise);
        gaussianNoiseMuSpinBoxMax->setObjectName(QString::fromUtf8("gaussianNoiseMuSpinBoxMax"));
        gaussianNoiseMuSpinBoxMax->setGeometry(QRect(183, 97, 62, 22));
        gaussianNoiseMuSpinBoxMax->setMinimum(-500.000000000000000);
        gaussianNoiseMuSpinBoxMax->setMaximum(500.000000000000000);
        gaussianNoiseSigmaSpinBoxMin = new QDoubleSpinBox(pageGaussianNoise);
        gaussianNoiseSigmaSpinBoxMin->setObjectName(QString::fromUtf8("gaussianNoiseSigmaSpinBoxMin"));
        gaussianNoiseSigmaSpinBoxMin->setGeometry(QRect(93, 139, 62, 22));
        gaussianNoiseSigmaSpinBoxMin->setMaximum(1000.000000000000000);
        gaussianNoiseSigmaLabel = new QLabel(pageGaussianNoise);
        gaussianNoiseSigmaLabel->setObjectName(QString::fromUtf8("gaussianNoiseSigmaLabel"));
        gaussianNoiseSigmaLabel->setGeometry(QRect(13, 144, 65, 16));
        gaussianNoiseSigmaSpinBoxMax = new QDoubleSpinBox(pageGaussianNoise);
        gaussianNoiseSigmaSpinBoxMax->setObjectName(QString::fromUtf8("gaussianNoiseSigmaSpinBoxMax"));
        gaussianNoiseSigmaSpinBoxMax->setGeometry(QRect(183, 139, 62, 22));
        gaussianNoiseSigmaSpinBoxMax->setMaximum(1000.000000000000000);
        stackedWidget->addWidget(pageGaussianNoise);
        pageUniformNoise = new QWidget();
        pageUniformNoise->setObjectName(QString::fromUtf8("pageUniformNoise"));
        uniformNoiseASpinBox = new QDoubleSpinBox(pageUniformNoise);
        uniformNoiseASpinBox->setObjectName(QString::fromUtf8("uniformNoiseASpinBox"));
        uniformNoiseASpinBox->setGeometry(QRect(139, 112, 62, 22));
        uniformNoiseASpinBox->setMinimum(-255.000000000000000);
        uniformNoiseASpinBox->setMaximum(255.000000000000000);
        uniformNoiseBSpinBox = new QDoubleSpinBox(pageUniformNoise);
        uniformNoiseBSpinBox->setObjectName(QString::fromUtf8("uniformNoiseBSpinBox"));
        uniformNoiseBSpinBox->setGeometry(QRect(139, 154, 62, 22));
        uniformNoiseBSpinBox->setMinimum(-255.000000000000000);
        uniformNoiseBSpinBox->setMaximum(255.000000000000000);
        uniformNoiseBLabel = new QLabel(pageUniformNoise);
        uniformNoiseBLabel->setObjectName(QString::fromUtf8("uniformNoiseBLabel"));
        uniformNoiseBLabel->setGeometry(QRect(59, 159, 65, 16));
        uniformNoiseALabel = new QLabel(pageUniformNoise);
        uniformNoiseALabel->setObjectName(QString::fromUtf8("uniformNoiseALabel"));
        uniformNoiseALabel->setGeometry(QRect(59, 117, 65, 16));
        stackedWidget->addWidget(pageUniformNoise);
        pageGammaNoise = new QWidget();
        pageGammaNoise->setObjectName(QString::fromUtf8("pageGammaNoise"));
        gammaNoiseAlphaSpinBoxMin = new QDoubleSpinBox(pageGammaNoise);
        gammaNoiseAlphaSpinBoxMin->setObjectName(QString::fromUtf8("gammaNoiseAlphaSpinBoxMin"));
        gammaNoiseAlphaSpinBoxMin->setGeometry(QRect(92, 101, 62, 22));
        gammaNoiseAlphaSpinBoxMin->setMinimum(0.100000000000000);
        gammaNoiseAlphaSpinBoxMin->setMaximum(500.000000000000000);
        gammaNoiseBetaSpinBoxMax = new QDoubleSpinBox(pageGammaNoise);
        gammaNoiseBetaSpinBoxMax->setObjectName(QString::fromUtf8("gammaNoiseBetaSpinBoxMax"));
        gammaNoiseBetaSpinBoxMax->setGeometry(QRect(182, 143, 62, 22));
        gammaNoiseBetaSpinBoxMax->setMinimum(0.100000000000000);
        gammaNoiseBetaSpinBoxMax->setMaximum(1000.000000000000000);
        gammaNoiseBetaSpinBoxMin = new QDoubleSpinBox(pageGammaNoise);
        gammaNoiseBetaSpinBoxMin->setObjectName(QString::fromUtf8("gammaNoiseBetaSpinBoxMin"));
        gammaNoiseBetaSpinBoxMin->setGeometry(QRect(92, 143, 62, 22));
        gammaNoiseBetaSpinBoxMin->setMinimum(0.100000000000000);
        gammaNoiseBetaSpinBoxMin->setMaximum(1000.000000000000000);
        gammaNoiseAlphaSpinBoxMax = new QDoubleSpinBox(pageGammaNoise);
        gammaNoiseAlphaSpinBoxMax->setObjectName(QString::fromUtf8("gammaNoiseAlphaSpinBoxMax"));
        gammaNoiseAlphaSpinBoxMax->setGeometry(QRect(182, 101, 62, 22));
        gammaNoiseAlphaSpinBoxMax->setMinimum(0.100000000000000);
        gammaNoiseAlphaSpinBoxMax->setMaximum(500.000000000000000);
        gammaNoiseBetaLabel = new QLabel(pageGammaNoise);
        gammaNoiseBetaLabel->setObjectName(QString::fromUtf8("gammaNoiseBetaLabel"));
        gammaNoiseBetaLabel->setGeometry(QRect(12, 148, 65, 16));
        gammaNoiseAlphaLabel = new QLabel(pageGammaNoise);
        gammaNoiseAlphaLabel->setObjectName(QString::fromUtf8("gammaNoiseAlphaLabel"));
        gammaNoiseAlphaLabel->setGeometry(QRect(12, 106, 65, 16));
        stackedWidget->addWidget(pageGammaNoise);
        comboBox = new QComboBox(commandEditorClass);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(120, 40, 161, 22));
        commandEditorOKButton = new QPushButton(commandEditorClass);
        commandEditorOKButton->setObjectName(QString::fromUtf8("commandEditorOKButton"));
        commandEditorOKButton->setGeometry(QRect(242, 397, 75, 23));

        retranslateUi(commandEditorClass);

        stackedWidget->setCurrentIndex(8);


        QMetaObject::connectSlotsByName(commandEditorClass);
    } // setupUi

    void retranslateUi(QDialog *commandEditorClass)
    {
        commandEditorClass->setWindowTitle(QApplication::translate("commandEditorClass", "\345\221\275\344\273\244\350\256\276\347\275\256", nullptr));
        tranlateXLabel->setText(QApplication::translate("commandEditorClass", "X", nullptr));
        translateYLabel->setText(QApplication::translate("commandEditorClass", "Y", nullptr));
        rotateLabel->setText(QApplication::translate("commandEditorClass", "\346\227\213\350\275\254\350\247\222\345\272\246", nullptr));
        scalingXlabel->setText(QApplication::translate("commandEditorClass", "X", nullptr));
        scalingYLabel->setText(QApplication::translate("commandEditorClass", "Y", nullptr));
        flippingXcheckBox->setText(QApplication::translate("commandEditorClass", "X", nullptr));
        flippingYcheckBox->setText(QApplication::translate("commandEditorClass", "Y", nullptr));
        gaussianFilterKxLable->setText(QApplication::translate("commandEditorClass", "kx", nullptr));
        gaussianFilterKyLable->setText(QApplication::translate("commandEditorClass", "ky", nullptr));
        gaussianFilterSigmaXLable->setText(QApplication::translate("commandEditorClass", "sigmaX", nullptr));
        gaussianFilterSigmaYLable->setText(QApplication::translate("commandEditorClass", "sigmaY", nullptr));
        medianFilterKsizeLabel->setText(QApplication::translate("commandEditorClass", "ksize", nullptr));
        meanFilterKyLabel->setText(QApplication::translate("commandEditorClass", "ky", nullptr));
        meanFilterKxLabel->setText(QApplication::translate("commandEditorClass", "kx", nullptr));
        bilateralFilterSigmaColorLabel->setText(QApplication::translate("commandEditorClass", "sigma color", nullptr));
        bilateralFilterSigmaSpaceLabel->setText(QApplication::translate("commandEditorClass", "sigma space", nullptr));
        bilateralFilterDLabel->setText(QApplication::translate("commandEditorClass", "d", nullptr));
        gaussianNoiseMuLabel->setText(QApplication::translate("commandEditorClass", "mu", nullptr));
        gaussianNoiseSigmaLabel->setText(QApplication::translate("commandEditorClass", "sigma", nullptr));
        uniformNoiseBLabel->setText(QApplication::translate("commandEditorClass", "b", nullptr));
        uniformNoiseALabel->setText(QApplication::translate("commandEditorClass", "a", nullptr));
        gammaNoiseBetaLabel->setText(QApplication::translate("commandEditorClass", "beta", nullptr));
        gammaNoiseAlphaLabel->setText(QApplication::translate("commandEditorClass", "alpha", nullptr));
        comboBox->setItemText(0, QApplication::translate("commandEditorClass", "\345\271\263\347\247\273", nullptr));
        comboBox->setItemText(1, QApplication::translate("commandEditorClass", "\346\227\213\350\275\254", nullptr));
        comboBox->setItemText(2, QApplication::translate("commandEditorClass", "\347\274\251\346\224\276", nullptr));
        comboBox->setItemText(3, QApplication::translate("commandEditorClass", "\347\277\273\350\275\254", nullptr));
        comboBox->setItemText(4, QApplication::translate("commandEditorClass", "\351\253\230\346\226\257\346\273\244\346\263\242", nullptr));
        comboBox->setItemText(5, QApplication::translate("commandEditorClass", "\344\270\255\345\200\274\346\273\244\346\263\242", nullptr));
        comboBox->setItemText(6, QApplication::translate("commandEditorClass", "\345\235\207\345\200\274\346\273\244\346\263\242", nullptr));
        comboBox->setItemText(7, QApplication::translate("commandEditorClass", "\345\217\214\347\272\277\346\200\247\346\273\244\346\263\242", nullptr));
        comboBox->setItemText(8, QApplication::translate("commandEditorClass", "\351\253\230\346\226\257\345\231\252\345\243\260", nullptr));
        comboBox->setItemText(9, QApplication::translate("commandEditorClass", "\345\235\207\345\214\200\345\231\252\345\243\260", nullptr));
        comboBox->setItemText(10, QApplication::translate("commandEditorClass", "\344\274\275\351\251\254\345\231\252\345\243\260", nullptr));

        commandEditorOKButton->setText(QApplication::translate("commandEditorClass", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class commandEditorClass: public Ui_commandEditorClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMMAND_EDITOR_H
