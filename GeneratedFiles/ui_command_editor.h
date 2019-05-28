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
    QDoubleSpinBox *sbTranslateXMin;
    QDoubleSpinBox *sbTranslateYMin;
    QLabel *labelTranlateX;
    QLabel *labelTranslateY;
    QDoubleSpinBox *sbTranslateXMax;
    QDoubleSpinBox *sbTranslateYMax;
    QWidget *pageRotate;
    QDoubleSpinBox *sbAngleMin;
    QLabel *labelRotate;
    QDoubleSpinBox *sbAngleMax;
    QWidget *pageScaling;
    QLabel *labelScalingX;
    QDoubleSpinBox *sbScalingXMin;
    QLabel *labelScalingY;
    QDoubleSpinBox *sbScalingYMin;
    QDoubleSpinBox *sbScalingXMax;
    QDoubleSpinBox *sbScalingYMax;
    QWidget *pageFlipping;
    QCheckBox *cbFlippingX;
    QCheckBox *cbFlippingY;
    QWidget *pageGaussianFilter;
    QLabel *labelGaussianFilterKx;
    QSpinBox *sbGaussianFilterKxMin;
    QSpinBox *sbGaussianFilterKyMin;
    QLabel *labelGaussianFilterKy;
    QLabel *labelGaussianFilterSigmaX;
    QDoubleSpinBox *sbGaussianFilterSigmaXMin;
    QLabel *labelGaussianFilterSigmaY;
    QDoubleSpinBox *sbGaussianFilterSigmaYMin;
    QSpinBox *sbGaussianFilterKyMax;
    QDoubleSpinBox *sbGaussianFilterSigmaYMax;
    QSpinBox *sbGaussianFilterKxMax;
    QDoubleSpinBox *sbGaussianFilterSigmaXMax;
    QWidget *pageMedianFilter;
    QLabel *labelMedianFilterKsize;
    QSpinBox *sbMedianFilterKsizeMin;
    QSpinBox *sbMedianFilterKsizeMax;
    QWidget *pageMeanFilter;
    QSpinBox *sbMeanFilterKyMin;
    QSpinBox *sbMeanFilterKxMin;
    QSpinBox *sbMeanFilterKxMax;
    QLabel *labelMeanFilterKy;
    QLabel *labelMeanFilterKx;
    QSpinBox *sbMeanFilterKyMax;
    QWidget *pageBilateralFilter;
    QLabel *labelBilateralFilterSigmaColor;
    QDoubleSpinBox *sbBilateralFilterSigmaSpaceMin;
    QLabel *labelBilateralFilterSigmaSpace;
    QDoubleSpinBox *sbBilateralFilterSigmaColorMin;
    QDoubleSpinBox *sbBilateralFilterSigmaColorMax;
    QDoubleSpinBox *sbBilateralFilterSigmaSpaceMax;
    QSpinBox *sbBilateralFilterDMin;
    QSpinBox *sbBilateralFilterDMax;
    QLabel *labelBilateralFilterD;
    QWidget *pageGaussianNoise;
    QDoubleSpinBox *sbGaussianNoiseMuMin;
    QLabel *labelGaussianNoiseMu;
    QDoubleSpinBox *sbGaussianNoiseMuMax;
    QDoubleSpinBox *sbGaussianNoiseSigmaMin;
    QLabel *labelGaussianNoiseSigma;
    QDoubleSpinBox *sbGaussianNoiseSigmaMax;
    QWidget *pageUniformNoise;
    QDoubleSpinBox *sbUniformNoiseA;
    QDoubleSpinBox *sbUniformNoiseB;
    QLabel *labelUniformNoiseB;
    QLabel *labelUniformNoiseA;
    QWidget *pageGammaNoise;
    QDoubleSpinBox *sbGammaNoiseAlphaMin;
    QDoubleSpinBox *sbGammaNoiseBetaMax;
    QDoubleSpinBox *sbGammaNoiseBetaMin;
    QDoubleSpinBox *sbGammaNoiseAlphaMax;
    QLabel *labelGammaNoiseBeta;
    QLabel *labelGammaNoiseAlpha;
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
        sbTranslateXMin = new QDoubleSpinBox(pageTranslate);
        sbTranslateXMin->setObjectName(QString::fromUtf8("sbTranslateXMin"));
        sbTranslateXMin->setGeometry(QRect(65, 76, 71, 22));
        sbTranslateXMin->setMaximum(1.000000000000000);
        sbTranslateXMin->setSingleStep(0.100000000000000);
        sbTranslateYMin = new QDoubleSpinBox(pageTranslate);
        sbTranslateYMin->setObjectName(QString::fromUtf8("sbTranslateYMin"));
        sbTranslateYMin->setGeometry(QRect(63, 145, 71, 22));
        sbTranslateYMin->setMaximum(1.000000000000000);
        sbTranslateYMin->setSingleStep(0.100000000000000);
        labelTranlateX = new QLabel(pageTranslate);
        labelTranlateX->setObjectName(QString::fromUtf8("labelTranlateX"));
        labelTranlateX->setGeometry(QRect(40, 80, 20, 16));
        labelTranslateY = new QLabel(pageTranslate);
        labelTranslateY->setObjectName(QString::fromUtf8("labelTranslateY"));
        labelTranslateY->setGeometry(QRect(40, 150, 18, 16));
        sbTranslateXMax = new QDoubleSpinBox(pageTranslate);
        sbTranslateXMax->setObjectName(QString::fromUtf8("sbTranslateXMax"));
        sbTranslateXMax->setGeometry(QRect(154, 76, 71, 22));
        sbTranslateXMax->setMaximum(1.000000000000000);
        sbTranslateXMax->setSingleStep(0.100000000000000);
        sbTranslateYMax = new QDoubleSpinBox(pageTranslate);
        sbTranslateYMax->setObjectName(QString::fromUtf8("sbTranslateYMax"));
        sbTranslateYMax->setGeometry(QRect(152, 145, 71, 22));
        sbTranslateYMax->setMaximum(1.000000000000000);
        sbTranslateYMax->setSingleStep(0.100000000000000);
        stackedWidget->addWidget(pageTranslate);
        pageRotate = new QWidget();
        pageRotate->setObjectName(QString::fromUtf8("pageRotate"));
        sbAngleMin = new QDoubleSpinBox(pageRotate);
        sbAngleMin->setObjectName(QString::fromUtf8("sbAngleMin"));
        sbAngleMin->setGeometry(QRect(94, 119, 62, 22));
        sbAngleMin->setMinimum(-360.000000000000000);
        sbAngleMin->setMaximum(360.000000000000000);
        labelRotate = new QLabel(pageRotate);
        labelRotate->setObjectName(QString::fromUtf8("labelRotate"));
        labelRotate->setGeometry(QRect(14, 124, 54, 12));
        sbAngleMax = new QDoubleSpinBox(pageRotate);
        sbAngleMax->setObjectName(QString::fromUtf8("sbAngleMax"));
        sbAngleMax->setGeometry(QRect(172, 119, 62, 22));
        sbAngleMax->setMinimum(-360.000000000000000);
        sbAngleMax->setMaximum(360.000000000000000);
        stackedWidget->addWidget(pageRotate);
        pageScaling = new QWidget();
        pageScaling->setObjectName(QString::fromUtf8("pageScaling"));
        labelScalingX = new QLabel(pageScaling);
        labelScalingX->setObjectName(QString::fromUtf8("labelScalingX"));
        labelScalingX->setGeometry(QRect(41, 106, 25, 16));
        sbScalingXMin = new QDoubleSpinBox(pageScaling);
        sbScalingXMin->setObjectName(QString::fromUtf8("sbScalingXMin"));
        sbScalingXMin->setGeometry(QRect(70, 102, 62, 22));
        labelScalingY = new QLabel(pageScaling);
        labelScalingY->setObjectName(QString::fromUtf8("labelScalingY"));
        labelScalingY->setGeometry(QRect(41, 151, 25, 16));
        sbScalingYMin = new QDoubleSpinBox(pageScaling);
        sbScalingYMin->setObjectName(QString::fromUtf8("sbScalingYMin"));
        sbScalingYMin->setGeometry(QRect(70, 147, 62, 22));
        sbScalingXMax = new QDoubleSpinBox(pageScaling);
        sbScalingXMax->setObjectName(QString::fromUtf8("sbScalingXMax"));
        sbScalingXMax->setGeometry(QRect(151, 102, 62, 22));
        sbScalingYMax = new QDoubleSpinBox(pageScaling);
        sbScalingYMax->setObjectName(QString::fromUtf8("sbScalingYMax"));
        sbScalingYMax->setGeometry(QRect(151, 147, 62, 22));
        stackedWidget->addWidget(pageScaling);
        pageFlipping = new QWidget();
        pageFlipping->setObjectName(QString::fromUtf8("pageFlipping"));
        cbFlippingX = new QCheckBox(pageFlipping);
        cbFlippingX->setObjectName(QString::fromUtf8("cbFlippingX"));
        cbFlippingX->setGeometry(QRect(100, 90, 71, 16));
        cbFlippingY = new QCheckBox(pageFlipping);
        cbFlippingY->setObjectName(QString::fromUtf8("cbFlippingY"));
        cbFlippingY->setGeometry(QRect(100, 140, 71, 16));
        stackedWidget->addWidget(pageFlipping);
        pageGaussianFilter = new QWidget();
        pageGaussianFilter->setObjectName(QString::fromUtf8("pageGaussianFilter"));
        labelGaussianFilterKx = new QLabel(pageGaussianFilter);
        labelGaussianFilterKx->setObjectName(QString::fromUtf8("labelGaussianFilterKx"));
        labelGaussianFilterKx->setGeometry(QRect(20, 65, 54, 12));
        sbGaussianFilterKxMin = new QSpinBox(pageGaussianFilter);
        sbGaussianFilterKxMin->setObjectName(QString::fromUtf8("sbGaussianFilterKxMin"));
        sbGaussianFilterKxMin->setGeometry(QRect(110, 60, 42, 22));
        sbGaussianFilterKxMin->setMinimum(1);
        sbGaussianFilterKyMin = new QSpinBox(pageGaussianFilter);
        sbGaussianFilterKyMin->setObjectName(QString::fromUtf8("sbGaussianFilterKyMin"));
        sbGaussianFilterKyMin->setGeometry(QRect(110, 100, 42, 22));
        sbGaussianFilterKyMin->setMinimum(1);
        labelGaussianFilterKy = new QLabel(pageGaussianFilter);
        labelGaussianFilterKy->setObjectName(QString::fromUtf8("labelGaussianFilterKy"));
        labelGaussianFilterKy->setGeometry(QRect(20, 105, 54, 12));
        labelGaussianFilterSigmaX = new QLabel(pageGaussianFilter);
        labelGaussianFilterSigmaX->setObjectName(QString::fromUtf8("labelGaussianFilterSigmaX"));
        labelGaussianFilterSigmaX->setGeometry(QRect(20, 145, 54, 12));
        sbGaussianFilterSigmaXMin = new QDoubleSpinBox(pageGaussianFilter);
        sbGaussianFilterSigmaXMin->setObjectName(QString::fromUtf8("sbGaussianFilterSigmaXMin"));
        sbGaussianFilterSigmaXMin->setGeometry(QRect(100, 140, 62, 22));
        labelGaussianFilterSigmaY = new QLabel(pageGaussianFilter);
        labelGaussianFilterSigmaY->setObjectName(QString::fromUtf8("labelGaussianFilterSigmaY"));
        labelGaussianFilterSigmaY->setGeometry(QRect(20, 180, 54, 12));
        sbGaussianFilterSigmaYMin = new QDoubleSpinBox(pageGaussianFilter);
        sbGaussianFilterSigmaYMin->setObjectName(QString::fromUtf8("sbGaussianFilterSigmaYMin"));
        sbGaussianFilterSigmaYMin->setGeometry(QRect(100, 175, 62, 22));
        sbGaussianFilterKyMax = new QSpinBox(pageGaussianFilter);
        sbGaussianFilterKyMax->setObjectName(QString::fromUtf8("sbGaussianFilterKyMax"));
        sbGaussianFilterKyMax->setGeometry(QRect(200, 100, 42, 22));
        sbGaussianFilterKyMax->setMinimum(1);
        sbGaussianFilterSigmaYMax = new QDoubleSpinBox(pageGaussianFilter);
        sbGaussianFilterSigmaYMax->setObjectName(QString::fromUtf8("sbGaussianFilterSigmaYMax"));
        sbGaussianFilterSigmaYMax->setGeometry(QRect(190, 175, 62, 22));
        sbGaussianFilterKxMax = new QSpinBox(pageGaussianFilter);
        sbGaussianFilterKxMax->setObjectName(QString::fromUtf8("sbGaussianFilterKxMax"));
        sbGaussianFilterKxMax->setGeometry(QRect(200, 60, 42, 22));
        sbGaussianFilterKxMax->setMinimum(1);
        sbGaussianFilterSigmaXMax = new QDoubleSpinBox(pageGaussianFilter);
        sbGaussianFilterSigmaXMax->setObjectName(QString::fromUtf8("sbGaussianFilterSigmaXMax"));
        sbGaussianFilterSigmaXMax->setGeometry(QRect(190, 140, 62, 22));
        stackedWidget->addWidget(pageGaussianFilter);
        pageMedianFilter = new QWidget();
        pageMedianFilter->setObjectName(QString::fromUtf8("pageMedianFilter"));
        labelMedianFilterKsize = new QLabel(pageMedianFilter);
        labelMedianFilterKsize->setObjectName(QString::fromUtf8("labelMedianFilterKsize"));
        labelMedianFilterKsize->setGeometry(QRect(26, 129, 54, 16));
        sbMedianFilterKsizeMin = new QSpinBox(pageMedianFilter);
        sbMedianFilterKsizeMin->setObjectName(QString::fromUtf8("sbMedianFilterKsizeMin"));
        sbMedianFilterKsizeMin->setGeometry(QRect(116, 124, 42, 22));
        sbMedianFilterKsizeMin->setMinimum(1);
        sbMedianFilterKsizeMax = new QSpinBox(pageMedianFilter);
        sbMedianFilterKsizeMax->setObjectName(QString::fromUtf8("sbMedianFilterKsizeMax"));
        sbMedianFilterKsizeMax->setGeometry(QRect(206, 124, 42, 22));
        sbMedianFilterKsizeMax->setMinimum(1);
        stackedWidget->addWidget(pageMedianFilter);
        pageMeanFilter = new QWidget();
        pageMeanFilter->setObjectName(QString::fromUtf8("pageMeanFilter"));
        sbMeanFilterKyMin = new QSpinBox(pageMeanFilter);
        sbMeanFilterKyMin->setObjectName(QString::fromUtf8("sbMeanFilterKyMin"));
        sbMeanFilterKyMin->setGeometry(QRect(113, 144, 42, 22));
        sbMeanFilterKyMin->setMinimum(1);
        sbMeanFilterKxMin = new QSpinBox(pageMeanFilter);
        sbMeanFilterKxMin->setObjectName(QString::fromUtf8("sbMeanFilterKxMin"));
        sbMeanFilterKxMin->setGeometry(QRect(113, 104, 42, 22));
        sbMeanFilterKxMin->setMinimum(1);
        sbMeanFilterKxMax = new QSpinBox(pageMeanFilter);
        sbMeanFilterKxMax->setObjectName(QString::fromUtf8("sbMeanFilterKxMax"));
        sbMeanFilterKxMax->setGeometry(QRect(203, 104, 42, 22));
        sbMeanFilterKxMax->setMinimum(1);
        labelMeanFilterKy = new QLabel(pageMeanFilter);
        labelMeanFilterKy->setObjectName(QString::fromUtf8("labelMeanFilterKy"));
        labelMeanFilterKy->setGeometry(QRect(23, 149, 54, 12));
        labelMeanFilterKx = new QLabel(pageMeanFilter);
        labelMeanFilterKx->setObjectName(QString::fromUtf8("labelMeanFilterKx"));
        labelMeanFilterKx->setGeometry(QRect(23, 109, 54, 12));
        sbMeanFilterKyMax = new QSpinBox(pageMeanFilter);
        sbMeanFilterKyMax->setObjectName(QString::fromUtf8("sbMeanFilterKyMax"));
        sbMeanFilterKyMax->setGeometry(QRect(203, 144, 42, 22));
        sbMeanFilterKyMax->setMinimum(1);
        stackedWidget->addWidget(pageMeanFilter);
        pageBilateralFilter = new QWidget();
        pageBilateralFilter->setObjectName(QString::fromUtf8("pageBilateralFilter"));
        labelBilateralFilterSigmaColor = new QLabel(pageBilateralFilter);
        labelBilateralFilterSigmaColor->setObjectName(QString::fromUtf8("labelBilateralFilterSigmaColor"));
        labelBilateralFilterSigmaColor->setGeometry(QRect(18, 124, 68, 16));
        sbBilateralFilterSigmaSpaceMin = new QDoubleSpinBox(pageBilateralFilter);
        sbBilateralFilterSigmaSpaceMin->setObjectName(QString::fromUtf8("sbBilateralFilterSigmaSpaceMin"));
        sbBilateralFilterSigmaSpaceMin->setGeometry(QRect(98, 154, 62, 22));
        labelBilateralFilterSigmaSpace = new QLabel(pageBilateralFilter);
        labelBilateralFilterSigmaSpace->setObjectName(QString::fromUtf8("labelBilateralFilterSigmaSpace"));
        labelBilateralFilterSigmaSpace->setGeometry(QRect(18, 159, 65, 16));
        sbBilateralFilterSigmaColorMin = new QDoubleSpinBox(pageBilateralFilter);
        sbBilateralFilterSigmaColorMin->setObjectName(QString::fromUtf8("sbBilateralFilterSigmaColorMin"));
        sbBilateralFilterSigmaColorMin->setGeometry(QRect(98, 119, 62, 22));
        sbBilateralFilterSigmaColorMax = new QDoubleSpinBox(pageBilateralFilter);
        sbBilateralFilterSigmaColorMax->setObjectName(QString::fromUtf8("sbBilateralFilterSigmaColorMax"));
        sbBilateralFilterSigmaColorMax->setGeometry(QRect(188, 119, 62, 22));
        sbBilateralFilterSigmaSpaceMax = new QDoubleSpinBox(pageBilateralFilter);
        sbBilateralFilterSigmaSpaceMax->setObjectName(QString::fromUtf8("sbBilateralFilterSigmaSpaceMax"));
        sbBilateralFilterSigmaSpaceMax->setGeometry(QRect(188, 154, 62, 22));
        sbBilateralFilterDMin = new QSpinBox(pageBilateralFilter);
        sbBilateralFilterDMin->setObjectName(QString::fromUtf8("sbBilateralFilterDMin"));
        sbBilateralFilterDMin->setGeometry(QRect(110, 83, 42, 22));
        sbBilateralFilterDMin->setMinimum(1);
        sbBilateralFilterDMax = new QSpinBox(pageBilateralFilter);
        sbBilateralFilterDMax->setObjectName(QString::fromUtf8("sbBilateralFilterDMax"));
        sbBilateralFilterDMax->setGeometry(QRect(200, 83, 42, 22));
        sbBilateralFilterDMax->setMinimum(1);
        labelBilateralFilterD = new QLabel(pageBilateralFilter);
        labelBilateralFilterD->setObjectName(QString::fromUtf8("labelBilateralFilterD"));
        labelBilateralFilterD->setGeometry(QRect(20, 88, 54, 12));
        stackedWidget->addWidget(pageBilateralFilter);
        pageGaussianNoise = new QWidget();
        pageGaussianNoise->setObjectName(QString::fromUtf8("pageGaussianNoise"));
        sbGaussianNoiseMuMin = new QDoubleSpinBox(pageGaussianNoise);
        sbGaussianNoiseMuMin->setObjectName(QString::fromUtf8("sbGaussianNoiseMuMin"));
        sbGaussianNoiseMuMin->setGeometry(QRect(93, 97, 62, 22));
        sbGaussianNoiseMuMin->setMinimum(-500.000000000000000);
        sbGaussianNoiseMuMin->setMaximum(500.000000000000000);
        labelGaussianNoiseMu = new QLabel(pageGaussianNoise);
        labelGaussianNoiseMu->setObjectName(QString::fromUtf8("labelGaussianNoiseMu"));
        labelGaussianNoiseMu->setGeometry(QRect(13, 102, 65, 16));
        sbGaussianNoiseMuMax = new QDoubleSpinBox(pageGaussianNoise);
        sbGaussianNoiseMuMax->setObjectName(QString::fromUtf8("sbGaussianNoiseMuMax"));
        sbGaussianNoiseMuMax->setGeometry(QRect(183, 97, 62, 22));
        sbGaussianNoiseMuMax->setMinimum(-500.000000000000000);
        sbGaussianNoiseMuMax->setMaximum(500.000000000000000);
        sbGaussianNoiseSigmaMin = new QDoubleSpinBox(pageGaussianNoise);
        sbGaussianNoiseSigmaMin->setObjectName(QString::fromUtf8("sbGaussianNoiseSigmaMin"));
        sbGaussianNoiseSigmaMin->setGeometry(QRect(93, 139, 62, 22));
        sbGaussianNoiseSigmaMin->setMaximum(1000.000000000000000);
        labelGaussianNoiseSigma = new QLabel(pageGaussianNoise);
        labelGaussianNoiseSigma->setObjectName(QString::fromUtf8("labelGaussianNoiseSigma"));
        labelGaussianNoiseSigma->setGeometry(QRect(13, 144, 65, 16));
        sbGaussianNoiseSigmaMax = new QDoubleSpinBox(pageGaussianNoise);
        sbGaussianNoiseSigmaMax->setObjectName(QString::fromUtf8("sbGaussianNoiseSigmaMax"));
        sbGaussianNoiseSigmaMax->setGeometry(QRect(183, 139, 62, 22));
        sbGaussianNoiseSigmaMax->setMaximum(1000.000000000000000);
        stackedWidget->addWidget(pageGaussianNoise);
        pageUniformNoise = new QWidget();
        pageUniformNoise->setObjectName(QString::fromUtf8("pageUniformNoise"));
        sbUniformNoiseA = new QDoubleSpinBox(pageUniformNoise);
        sbUniformNoiseA->setObjectName(QString::fromUtf8("sbUniformNoiseA"));
        sbUniformNoiseA->setGeometry(QRect(139, 112, 62, 22));
        sbUniformNoiseA->setMinimum(-255.000000000000000);
        sbUniformNoiseA->setMaximum(255.000000000000000);
        sbUniformNoiseB = new QDoubleSpinBox(pageUniformNoise);
        sbUniformNoiseB->setObjectName(QString::fromUtf8("sbUniformNoiseB"));
        sbUniformNoiseB->setGeometry(QRect(139, 154, 62, 22));
        sbUniformNoiseB->setMinimum(-255.000000000000000);
        sbUniformNoiseB->setMaximum(255.000000000000000);
        labelUniformNoiseB = new QLabel(pageUniformNoise);
        labelUniformNoiseB->setObjectName(QString::fromUtf8("labelUniformNoiseB"));
        labelUniformNoiseB->setGeometry(QRect(59, 159, 65, 16));
        labelUniformNoiseA = new QLabel(pageUniformNoise);
        labelUniformNoiseA->setObjectName(QString::fromUtf8("labelUniformNoiseA"));
        labelUniformNoiseA->setGeometry(QRect(59, 117, 65, 16));
        stackedWidget->addWidget(pageUniformNoise);
        pageGammaNoise = new QWidget();
        pageGammaNoise->setObjectName(QString::fromUtf8("pageGammaNoise"));
        sbGammaNoiseAlphaMin = new QDoubleSpinBox(pageGammaNoise);
        sbGammaNoiseAlphaMin->setObjectName(QString::fromUtf8("sbGammaNoiseAlphaMin"));
        sbGammaNoiseAlphaMin->setGeometry(QRect(92, 101, 62, 22));
        sbGammaNoiseAlphaMin->setMinimum(0.010000000000000);
        sbGammaNoiseAlphaMin->setMaximum(500.000000000000000);
        sbGammaNoiseAlphaMin->setValue(0.010000000000000);
        sbGammaNoiseBetaMax = new QDoubleSpinBox(pageGammaNoise);
        sbGammaNoiseBetaMax->setObjectName(QString::fromUtf8("sbGammaNoiseBetaMax"));
        sbGammaNoiseBetaMax->setGeometry(QRect(182, 143, 62, 22));
        sbGammaNoiseBetaMax->setMinimum(0.010000000000000);
        sbGammaNoiseBetaMax->setMaximum(1000.000000000000000);
        sbGammaNoiseBetaMax->setValue(0.100000000000000);
        sbGammaNoiseBetaMin = new QDoubleSpinBox(pageGammaNoise);
        sbGammaNoiseBetaMin->setObjectName(QString::fromUtf8("sbGammaNoiseBetaMin"));
        sbGammaNoiseBetaMin->setGeometry(QRect(92, 143, 62, 22));
        sbGammaNoiseBetaMin->setMinimum(0.010000000000000);
        sbGammaNoiseBetaMin->setMaximum(1000.000000000000000);
        sbGammaNoiseBetaMin->setValue(0.010000000000000);
        sbGammaNoiseAlphaMax = new QDoubleSpinBox(pageGammaNoise);
        sbGammaNoiseAlphaMax->setObjectName(QString::fromUtf8("sbGammaNoiseAlphaMax"));
        sbGammaNoiseAlphaMax->setGeometry(QRect(182, 101, 62, 22));
        sbGammaNoiseAlphaMax->setDecimals(2);
        sbGammaNoiseAlphaMax->setMinimum(0.010000000000000);
        sbGammaNoiseAlphaMax->setMaximum(500.000000000000000);
        sbGammaNoiseAlphaMax->setValue(0.010000000000000);
        labelGammaNoiseBeta = new QLabel(pageGammaNoise);
        labelGammaNoiseBeta->setObjectName(QString::fromUtf8("labelGammaNoiseBeta"));
        labelGammaNoiseBeta->setGeometry(QRect(12, 148, 65, 16));
        labelGammaNoiseAlpha = new QLabel(pageGammaNoise);
        labelGammaNoiseAlpha->setObjectName(QString::fromUtf8("labelGammaNoiseAlpha"));
        labelGammaNoiseAlpha->setGeometry(QRect(12, 106, 65, 16));
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

        stackedWidget->setCurrentIndex(10);


        QMetaObject::connectSlotsByName(commandEditorClass);
    } // setupUi

    void retranslateUi(QDialog *commandEditorClass)
    {
        commandEditorClass->setWindowTitle(QApplication::translate("commandEditorClass", "\345\221\275\344\273\244\350\256\276\347\275\256", nullptr));
        labelTranlateX->setText(QApplication::translate("commandEditorClass", "X", nullptr));
        labelTranslateY->setText(QApplication::translate("commandEditorClass", "Y", nullptr));
        labelRotate->setText(QApplication::translate("commandEditorClass", "\346\227\213\350\275\254\350\247\222\345\272\246", nullptr));
        labelScalingX->setText(QApplication::translate("commandEditorClass", "X", nullptr));
        labelScalingY->setText(QApplication::translate("commandEditorClass", "Y", nullptr));
        cbFlippingX->setText(QApplication::translate("commandEditorClass", "X", nullptr));
        cbFlippingY->setText(QApplication::translate("commandEditorClass", "Y", nullptr));
        labelGaussianFilterKx->setText(QApplication::translate("commandEditorClass", "kx", nullptr));
        labelGaussianFilterKy->setText(QApplication::translate("commandEditorClass", "ky", nullptr));
        labelGaussianFilterSigmaX->setText(QApplication::translate("commandEditorClass", "sigmaX", nullptr));
        labelGaussianFilterSigmaY->setText(QApplication::translate("commandEditorClass", "sigmaY", nullptr));
        labelMedianFilterKsize->setText(QApplication::translate("commandEditorClass", "ksize", nullptr));
        labelMeanFilterKy->setText(QApplication::translate("commandEditorClass", "ky", nullptr));
        labelMeanFilterKx->setText(QApplication::translate("commandEditorClass", "kx", nullptr));
        labelBilateralFilterSigmaColor->setText(QApplication::translate("commandEditorClass", "sigma color", nullptr));
        labelBilateralFilterSigmaSpace->setText(QApplication::translate("commandEditorClass", "sigma space", nullptr));
        labelBilateralFilterD->setText(QApplication::translate("commandEditorClass", "d", nullptr));
        labelGaussianNoiseMu->setText(QApplication::translate("commandEditorClass", "mu", nullptr));
        labelGaussianNoiseSigma->setText(QApplication::translate("commandEditorClass", "sigma", nullptr));
        labelUniformNoiseB->setText(QApplication::translate("commandEditorClass", "b", nullptr));
        labelUniformNoiseA->setText(QApplication::translate("commandEditorClass", "a", nullptr));
        labelGammaNoiseBeta->setText(QApplication::translate("commandEditorClass", "beta", nullptr));
        labelGammaNoiseAlpha->setText(QApplication::translate("commandEditorClass", "alpha", nullptr));
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
