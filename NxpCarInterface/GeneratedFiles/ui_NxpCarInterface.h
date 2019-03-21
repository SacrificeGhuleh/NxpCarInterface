/********************************************************************************
** Form generated from reading UI file 'NxpCarInterface.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NXPCARINTERFACE_H
#define UI_NXPCARINTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NxpCarInterfaceClass
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_2;
    QFrame *frame_7;
    QHBoxLayout *horizontalLayout;
    QFrame *originalImageMainFrame;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QGraphicsView *originalPlot;
    QFrame *frame_3;
    QVBoxLayout *verticalLayout_3;
    QGraphicsView *originalHistory;
    QFrame *normalizedImageMainFrame;
    QVBoxLayout *verticalLayout_21;
    QLabel *label_8;
    QFrame *frame_17;
    QVBoxLayout *verticalLayout_22;
    QGraphicsView *normalizedPlot;
    QFrame *frame_18;
    QVBoxLayout *verticalLayout_23;
    QGraphicsView *normalizedHistory;
    QFrame *thresholdedImageMainFrame;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_2;
    QFrame *frame_5;
    QVBoxLayout *verticalLayout_5;
    QGraphicsView *thresholdedPlot;
    QFrame *frame_6;
    QVBoxLayout *verticalLayout_6;
    QGraphicsView *thresholdedHistory;
    QFrame *servoMainFrame;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_3;
    QFrame *frame_9;
    QVBoxLayout *verticalLayout_8;
    QLabel *servoValueLabel;
    QFrame *frame_10;
    QVBoxLayout *verticalLayout_9;
    QGraphicsView *linesHistory;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_27;
    QFrame *leftPwmMainFrame;
    QVBoxLayout *verticalLayout_10;
    QLabel *label_4;
    QFrame *frame_11;
    QVBoxLayout *verticalLayout_11;
    QLabel *leftPWMValueLabel;
    QFrame *frame_12;
    QVBoxLayout *verticalLayout_12;
    QFrame *rightPwmMainFrame;
    QVBoxLayout *verticalLayout_13;
    QLabel *label_5;
    QFrame *frame_13;
    QVBoxLayout *verticalLayout_14;
    QLabel *rightPwmValueLabel;
    QFrame *frame_14;
    QVBoxLayout *verticalLayout_15;
    QFrame *motorSpeedFrame;
    QVBoxLayout *verticalLayout_24;
    QLabel *label_9;
    QFrame *frame_19;
    QVBoxLayout *verticalLayout_25;
    QLabel *motorSpeedValueLabel;
    QFrame *frame_20;
    QVBoxLayout *verticalLayout_26;
    QFrame *voltageMainFrame;
    QVBoxLayout *verticalLayout_16;
    QLabel *label_6;
    QFrame *frame_15;
    QVBoxLayout *verticalLayout_17;
    QLabel *voltageValueLabel;
    QFrame *frame_16;
    QVBoxLayout *verticalLayout_18;
    QFrame *voltageMainFrame_3;
    QVBoxLayout *verticalLayout_41;
    QLabel *label_14;
    QFrame *frame_30;
    QVBoxLayout *verticalLayout_42;
    QLabel *blackRegionsCountValueLabel;
    QFrame *frame_31;
    QVBoxLayout *verticalLayout_43;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *verticalSpacer_2;
    QFrame *frame_21;
    QVBoxLayout *verticalLayout_28;
    QFrame *leftPwmMainFrame_2;
    QVBoxLayout *verticalLayout_29;
    QLabel *label_10;
    QFrame *frame_22;
    QVBoxLayout *verticalLayout_30;
    QLabel *regionSizeLabel;
    QFrame *frame_23;
    QVBoxLayout *verticalLayout_31;
    QFrame *rightPwmMainFrame_2;
    QVBoxLayout *verticalLayout_32;
    QLabel *label_11;
    QFrame *frame_24;
    QVBoxLayout *verticalLayout_33;
    QLabel *regionCenterLabel;
    QFrame *frame_25;
    QVBoxLayout *verticalLayout_34;
    QFrame *motorSpeedFrame_2;
    QVBoxLayout *verticalLayout_35;
    QLabel *label_12;
    QFrame *frame_26;
    QVBoxLayout *verticalLayout_36;
    QLabel *leftPotLabel;
    QFrame *frame_27;
    QVBoxLayout *verticalLayout_37;
    QFrame *voltageMainFrame_2;
    QVBoxLayout *verticalLayout_38;
    QLabel *label_13;
    QFrame *frame_28;
    QVBoxLayout *verticalLayout_39;
    QLabel *rightPotLabel;
    QFrame *frame_29;
    QVBoxLayout *verticalLayout_40;
    QFrame *voltageMainFrame_4;
    QVBoxLayout *verticalLayout_44;
    QLabel *label_15;
    QFrame *frame_32;
    QVBoxLayout *verticalLayout_45;
    QLabel *whiteRegionsCountValueLabel;
    QFrame *frame_33;
    QVBoxLayout *verticalLayout_46;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *horizontalSpacer;
    QFrame *connectionMainFrame;
    QVBoxLayout *verticalLayout_19;
    QLabel *label_7;
    QFrame *frame_4;
    QVBoxLayout *verticalLayout_20;
    QComboBox *connectComboBoxAddress;
    QLineEdit *connectLineAddress;
    QLineEdit *connectPort;
    QPushButton *connectBtn;
    QPushButton *disconnectBtn;
    QSpacerItem *verticalSpacer;
    QFrame *frame_8;
    QHBoxLayout *horizontalLayout_3;

    void setupUi(QMainWindow *NxpCarInterfaceClass)
    {
        if (NxpCarInterfaceClass->objectName().isEmpty())
            NxpCarInterfaceClass->setObjectName(QString::fromUtf8("NxpCarInterfaceClass"));
        NxpCarInterfaceClass->resize(1485, 1068);
        centralWidget = new QWidget(NxpCarInterfaceClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout_2 = new QHBoxLayout(centralWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        frame_7 = new QFrame(centralWidget);
        frame_7->setObjectName(QString::fromUtf8("frame_7"));
        frame_7->setFrameShape(QFrame::StyledPanel);
        frame_7->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame_7);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        originalImageMainFrame = new QFrame(frame_7);
        originalImageMainFrame->setObjectName(QString::fromUtf8("originalImageMainFrame"));
        originalImageMainFrame->setMaximumSize(QSize(168, 16777215));
        originalImageMainFrame->setFrameShape(QFrame::StyledPanel);
        originalImageMainFrame->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(originalImageMainFrame);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(originalImageMainFrame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label);

        frame = new QFrame(originalImageMainFrame);
        frame->setObjectName(QString::fromUtf8("frame"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setMaximumSize(QSize(148, 16777215));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        originalPlot = new QGraphicsView(frame);
        originalPlot->setObjectName(QString::fromUtf8("originalPlot"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(originalPlot->sizePolicy().hasHeightForWidth());
        originalPlot->setSizePolicy(sizePolicy1);
        originalPlot->setMaximumSize(QSize(128, 128));
        originalPlot->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        originalPlot->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        verticalLayout->addWidget(originalPlot);


        verticalLayout_2->addWidget(frame);

        frame_3 = new QFrame(originalImageMainFrame);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setMaximumSize(QSize(148, 16777215));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(frame_3);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        originalHistory = new QGraphicsView(frame_3);
        originalHistory->setObjectName(QString::fromUtf8("originalHistory"));
        originalHistory->setMinimumSize(QSize(128, 128));
        originalHistory->setMaximumSize(QSize(128, 16777215));
        originalHistory->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        originalHistory->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        verticalLayout_3->addWidget(originalHistory);


        verticalLayout_2->addWidget(frame_3);


        horizontalLayout->addWidget(originalImageMainFrame);

        normalizedImageMainFrame = new QFrame(frame_7);
        normalizedImageMainFrame->setObjectName(QString::fromUtf8("normalizedImageMainFrame"));
        normalizedImageMainFrame->setMaximumSize(QSize(168, 16777215));
        normalizedImageMainFrame->setFrameShape(QFrame::StyledPanel);
        normalizedImageMainFrame->setFrameShadow(QFrame::Raised);
        verticalLayout_21 = new QVBoxLayout(normalizedImageMainFrame);
        verticalLayout_21->setSpacing(0);
        verticalLayout_21->setContentsMargins(11, 11, 11, 11);
        verticalLayout_21->setObjectName(QString::fromUtf8("verticalLayout_21"));
        verticalLayout_21->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(normalizedImageMainFrame);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setAlignment(Qt::AlignCenter);

        verticalLayout_21->addWidget(label_8);

        frame_17 = new QFrame(normalizedImageMainFrame);
        frame_17->setObjectName(QString::fromUtf8("frame_17"));
        sizePolicy.setHeightForWidth(frame_17->sizePolicy().hasHeightForWidth());
        frame_17->setSizePolicy(sizePolicy);
        frame_17->setMaximumSize(QSize(148, 16777215));
        frame_17->setFrameShape(QFrame::StyledPanel);
        frame_17->setFrameShadow(QFrame::Raised);
        verticalLayout_22 = new QVBoxLayout(frame_17);
        verticalLayout_22->setSpacing(6);
        verticalLayout_22->setContentsMargins(11, 11, 11, 11);
        verticalLayout_22->setObjectName(QString::fromUtf8("verticalLayout_22"));
        normalizedPlot = new QGraphicsView(frame_17);
        normalizedPlot->setObjectName(QString::fromUtf8("normalizedPlot"));
        sizePolicy1.setHeightForWidth(normalizedPlot->sizePolicy().hasHeightForWidth());
        normalizedPlot->setSizePolicy(sizePolicy1);
        normalizedPlot->setMaximumSize(QSize(128, 128));
        normalizedPlot->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        normalizedPlot->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        verticalLayout_22->addWidget(normalizedPlot);


        verticalLayout_21->addWidget(frame_17);

        frame_18 = new QFrame(normalizedImageMainFrame);
        frame_18->setObjectName(QString::fromUtf8("frame_18"));
        frame_18->setMaximumSize(QSize(148, 16777215));
        frame_18->setFrameShape(QFrame::StyledPanel);
        frame_18->setFrameShadow(QFrame::Raised);
        verticalLayout_23 = new QVBoxLayout(frame_18);
        verticalLayout_23->setSpacing(6);
        verticalLayout_23->setContentsMargins(11, 11, 11, 11);
        verticalLayout_23->setObjectName(QString::fromUtf8("verticalLayout_23"));
        normalizedHistory = new QGraphicsView(frame_18);
        normalizedHistory->setObjectName(QString::fromUtf8("normalizedHistory"));
        normalizedHistory->setMinimumSize(QSize(128, 128));
        normalizedHistory->setMaximumSize(QSize(128, 16777215));
        normalizedHistory->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        normalizedHistory->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        verticalLayout_23->addWidget(normalizedHistory);


        verticalLayout_21->addWidget(frame_18);


        horizontalLayout->addWidget(normalizedImageMainFrame);

        thresholdedImageMainFrame = new QFrame(frame_7);
        thresholdedImageMainFrame->setObjectName(QString::fromUtf8("thresholdedImageMainFrame"));
        thresholdedImageMainFrame->setMaximumSize(QSize(168, 16777215));
        thresholdedImageMainFrame->setFrameShape(QFrame::StyledPanel);
        thresholdedImageMainFrame->setFrameShadow(QFrame::Raised);
        verticalLayout_4 = new QVBoxLayout(thresholdedImageMainFrame);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(thresholdedImageMainFrame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_2);

        frame_5 = new QFrame(thresholdedImageMainFrame);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        sizePolicy.setHeightForWidth(frame_5->sizePolicy().hasHeightForWidth());
        frame_5->setSizePolicy(sizePolicy);
        frame_5->setMaximumSize(QSize(148, 16777215));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        verticalLayout_5 = new QVBoxLayout(frame_5);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        thresholdedPlot = new QGraphicsView(frame_5);
        thresholdedPlot->setObjectName(QString::fromUtf8("thresholdedPlot"));
        sizePolicy1.setHeightForWidth(thresholdedPlot->sizePolicy().hasHeightForWidth());
        thresholdedPlot->setSizePolicy(sizePolicy1);
        thresholdedPlot->setMaximumSize(QSize(128, 128));
        thresholdedPlot->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        thresholdedPlot->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        verticalLayout_5->addWidget(thresholdedPlot);


        verticalLayout_4->addWidget(frame_5);

        frame_6 = new QFrame(thresholdedImageMainFrame);
        frame_6->setObjectName(QString::fromUtf8("frame_6"));
        frame_6->setMaximumSize(QSize(148, 16777215));
        frame_6->setFrameShape(QFrame::StyledPanel);
        frame_6->setFrameShadow(QFrame::Raised);
        verticalLayout_6 = new QVBoxLayout(frame_6);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        thresholdedHistory = new QGraphicsView(frame_6);
        thresholdedHistory->setObjectName(QString::fromUtf8("thresholdedHistory"));
        thresholdedHistory->setMinimumSize(QSize(128, 128));
        thresholdedHistory->setMaximumSize(QSize(128, 16777215));
        thresholdedHistory->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        thresholdedHistory->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        verticalLayout_6->addWidget(thresholdedHistory);


        verticalLayout_4->addWidget(frame_6);


        horizontalLayout->addWidget(thresholdedImageMainFrame);

        servoMainFrame = new QFrame(frame_7);
        servoMainFrame->setObjectName(QString::fromUtf8("servoMainFrame"));
        servoMainFrame->setMaximumSize(QSize(168, 16777215));
        servoMainFrame->setFrameShape(QFrame::StyledPanel);
        servoMainFrame->setFrameShadow(QFrame::Raised);
        verticalLayout_7 = new QVBoxLayout(servoMainFrame);
        verticalLayout_7->setSpacing(0);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(servoMainFrame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(label_3);

        frame_9 = new QFrame(servoMainFrame);
        frame_9->setObjectName(QString::fromUtf8("frame_9"));
        sizePolicy.setHeightForWidth(frame_9->sizePolicy().hasHeightForWidth());
        frame_9->setSizePolicy(sizePolicy);
        frame_9->setMaximumSize(QSize(148, 16777215));
        frame_9->setFrameShape(QFrame::StyledPanel);
        frame_9->setFrameShadow(QFrame::Raised);
        verticalLayout_8 = new QVBoxLayout(frame_9);
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        servoValueLabel = new QLabel(frame_9);
        servoValueLabel->setObjectName(QString::fromUtf8("servoValueLabel"));
        servoValueLabel->setMinimumSize(QSize(128, 128));
        servoValueLabel->setMaximumSize(QSize(128, 128));
        servoValueLabel->setStyleSheet(QString::fromUtf8("font: 75 36pt \"Segoe UI\";"));
        servoValueLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_8->addWidget(servoValueLabel);


        verticalLayout_7->addWidget(frame_9);

        frame_10 = new QFrame(servoMainFrame);
        frame_10->setObjectName(QString::fromUtf8("frame_10"));
        frame_10->setMaximumSize(QSize(148, 16777215));
        frame_10->setFrameShape(QFrame::StyledPanel);
        frame_10->setFrameShadow(QFrame::Raised);
        verticalLayout_9 = new QVBoxLayout(frame_10);
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        linesHistory = new QGraphicsView(frame_10);
        linesHistory->setObjectName(QString::fromUtf8("linesHistory"));
        linesHistory->setMinimumSize(QSize(128, 128));
        linesHistory->setMaximumSize(QSize(128, 16777215));
        linesHistory->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        linesHistory->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        verticalLayout_9->addWidget(linesHistory);


        verticalLayout_7->addWidget(frame_10);


        horizontalLayout->addWidget(servoMainFrame);

        frame_2 = new QFrame(frame_7);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        verticalLayout_27 = new QVBoxLayout(frame_2);
        verticalLayout_27->setSpacing(6);
        verticalLayout_27->setContentsMargins(11, 11, 11, 11);
        verticalLayout_27->setObjectName(QString::fromUtf8("verticalLayout_27"));
        leftPwmMainFrame = new QFrame(frame_2);
        leftPwmMainFrame->setObjectName(QString::fromUtf8("leftPwmMainFrame"));
        leftPwmMainFrame->setMaximumSize(QSize(168, 16777215));
        leftPwmMainFrame->setFrameShape(QFrame::StyledPanel);
        leftPwmMainFrame->setFrameShadow(QFrame::Raised);
        verticalLayout_10 = new QVBoxLayout(leftPwmMainFrame);
        verticalLayout_10->setSpacing(0);
        verticalLayout_10->setContentsMargins(11, 11, 11, 11);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        verticalLayout_10->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(leftPwmMainFrame);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignCenter);

        verticalLayout_10->addWidget(label_4);

        frame_11 = new QFrame(leftPwmMainFrame);
        frame_11->setObjectName(QString::fromUtf8("frame_11"));
        sizePolicy.setHeightForWidth(frame_11->sizePolicy().hasHeightForWidth());
        frame_11->setSizePolicy(sizePolicy);
        frame_11->setMaximumSize(QSize(148, 16777215));
        frame_11->setFrameShape(QFrame::StyledPanel);
        frame_11->setFrameShadow(QFrame::Raised);
        verticalLayout_11 = new QVBoxLayout(frame_11);
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setContentsMargins(11, 11, 11, 11);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        leftPWMValueLabel = new QLabel(frame_11);
        leftPWMValueLabel->setObjectName(QString::fromUtf8("leftPWMValueLabel"));
        leftPWMValueLabel->setMinimumSize(QSize(128, 128));
        leftPWMValueLabel->setMaximumSize(QSize(128, 128));
        leftPWMValueLabel->setStyleSheet(QString::fromUtf8("font: 75 36pt \"Segoe UI\";"));
        leftPWMValueLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_11->addWidget(leftPWMValueLabel);


        verticalLayout_10->addWidget(frame_11);

        frame_12 = new QFrame(leftPwmMainFrame);
        frame_12->setObjectName(QString::fromUtf8("frame_12"));
        frame_12->setMaximumSize(QSize(148, 16777215));
        frame_12->setFrameShape(QFrame::StyledPanel);
        frame_12->setFrameShadow(QFrame::Raised);
        verticalLayout_12 = new QVBoxLayout(frame_12);
        verticalLayout_12->setSpacing(6);
        verticalLayout_12->setContentsMargins(11, 11, 11, 11);
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));

        verticalLayout_10->addWidget(frame_12);


        verticalLayout_27->addWidget(leftPwmMainFrame);

        rightPwmMainFrame = new QFrame(frame_2);
        rightPwmMainFrame->setObjectName(QString::fromUtf8("rightPwmMainFrame"));
        rightPwmMainFrame->setMaximumSize(QSize(168, 16777215));
        rightPwmMainFrame->setFrameShape(QFrame::StyledPanel);
        rightPwmMainFrame->setFrameShadow(QFrame::Raised);
        verticalLayout_13 = new QVBoxLayout(rightPwmMainFrame);
        verticalLayout_13->setSpacing(0);
        verticalLayout_13->setContentsMargins(11, 11, 11, 11);
        verticalLayout_13->setObjectName(QString::fromUtf8("verticalLayout_13"));
        verticalLayout_13->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(rightPwmMainFrame);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignCenter);

        verticalLayout_13->addWidget(label_5);

        frame_13 = new QFrame(rightPwmMainFrame);
        frame_13->setObjectName(QString::fromUtf8("frame_13"));
        sizePolicy.setHeightForWidth(frame_13->sizePolicy().hasHeightForWidth());
        frame_13->setSizePolicy(sizePolicy);
        frame_13->setMaximumSize(QSize(148, 16777215));
        frame_13->setFrameShape(QFrame::StyledPanel);
        frame_13->setFrameShadow(QFrame::Raised);
        verticalLayout_14 = new QVBoxLayout(frame_13);
        verticalLayout_14->setSpacing(6);
        verticalLayout_14->setContentsMargins(11, 11, 11, 11);
        verticalLayout_14->setObjectName(QString::fromUtf8("verticalLayout_14"));
        rightPwmValueLabel = new QLabel(frame_13);
        rightPwmValueLabel->setObjectName(QString::fromUtf8("rightPwmValueLabel"));
        rightPwmValueLabel->setMinimumSize(QSize(128, 128));
        rightPwmValueLabel->setMaximumSize(QSize(128, 128));
        rightPwmValueLabel->setStyleSheet(QString::fromUtf8("font: 75 36pt \"Segoe UI\";"));
        rightPwmValueLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_14->addWidget(rightPwmValueLabel);


        verticalLayout_13->addWidget(frame_13);

        frame_14 = new QFrame(rightPwmMainFrame);
        frame_14->setObjectName(QString::fromUtf8("frame_14"));
        frame_14->setMaximumSize(QSize(148, 16777215));
        frame_14->setFrameShape(QFrame::StyledPanel);
        frame_14->setFrameShadow(QFrame::Raised);
        verticalLayout_15 = new QVBoxLayout(frame_14);
        verticalLayout_15->setSpacing(6);
        verticalLayout_15->setContentsMargins(11, 11, 11, 11);
        verticalLayout_15->setObjectName(QString::fromUtf8("verticalLayout_15"));

        verticalLayout_13->addWidget(frame_14);


        verticalLayout_27->addWidget(rightPwmMainFrame);

        motorSpeedFrame = new QFrame(frame_2);
        motorSpeedFrame->setObjectName(QString::fromUtf8("motorSpeedFrame"));
        motorSpeedFrame->setMaximumSize(QSize(168, 16777215));
        motorSpeedFrame->setFrameShape(QFrame::StyledPanel);
        motorSpeedFrame->setFrameShadow(QFrame::Raised);
        verticalLayout_24 = new QVBoxLayout(motorSpeedFrame);
        verticalLayout_24->setSpacing(0);
        verticalLayout_24->setContentsMargins(11, 11, 11, 11);
        verticalLayout_24->setObjectName(QString::fromUtf8("verticalLayout_24"));
        verticalLayout_24->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(motorSpeedFrame);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setAlignment(Qt::AlignCenter);

        verticalLayout_24->addWidget(label_9);

        frame_19 = new QFrame(motorSpeedFrame);
        frame_19->setObjectName(QString::fromUtf8("frame_19"));
        sizePolicy.setHeightForWidth(frame_19->sizePolicy().hasHeightForWidth());
        frame_19->setSizePolicy(sizePolicy);
        frame_19->setMaximumSize(QSize(148, 16777215));
        frame_19->setFrameShape(QFrame::StyledPanel);
        frame_19->setFrameShadow(QFrame::Raised);
        verticalLayout_25 = new QVBoxLayout(frame_19);
        verticalLayout_25->setSpacing(6);
        verticalLayout_25->setContentsMargins(11, 11, 11, 11);
        verticalLayout_25->setObjectName(QString::fromUtf8("verticalLayout_25"));
        motorSpeedValueLabel = new QLabel(frame_19);
        motorSpeedValueLabel->setObjectName(QString::fromUtf8("motorSpeedValueLabel"));
        motorSpeedValueLabel->setMinimumSize(QSize(128, 128));
        motorSpeedValueLabel->setMaximumSize(QSize(128, 128));
        motorSpeedValueLabel->setStyleSheet(QString::fromUtf8("font: 75 36pt \"Segoe UI\";"));
        motorSpeedValueLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_25->addWidget(motorSpeedValueLabel);


        verticalLayout_24->addWidget(frame_19);

        frame_20 = new QFrame(motorSpeedFrame);
        frame_20->setObjectName(QString::fromUtf8("frame_20"));
        frame_20->setMaximumSize(QSize(148, 16777215));
        frame_20->setFrameShape(QFrame::StyledPanel);
        frame_20->setFrameShadow(QFrame::Raised);
        verticalLayout_26 = new QVBoxLayout(frame_20);
        verticalLayout_26->setSpacing(6);
        verticalLayout_26->setContentsMargins(11, 11, 11, 11);
        verticalLayout_26->setObjectName(QString::fromUtf8("verticalLayout_26"));

        verticalLayout_24->addWidget(frame_20);


        verticalLayout_27->addWidget(motorSpeedFrame);

        voltageMainFrame = new QFrame(frame_2);
        voltageMainFrame->setObjectName(QString::fromUtf8("voltageMainFrame"));
        voltageMainFrame->setMaximumSize(QSize(168, 16777215));
        voltageMainFrame->setFrameShape(QFrame::StyledPanel);
        voltageMainFrame->setFrameShadow(QFrame::Raised);
        verticalLayout_16 = new QVBoxLayout(voltageMainFrame);
        verticalLayout_16->setSpacing(0);
        verticalLayout_16->setContentsMargins(11, 11, 11, 11);
        verticalLayout_16->setObjectName(QString::fromUtf8("verticalLayout_16"));
        verticalLayout_16->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(voltageMainFrame);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setAlignment(Qt::AlignCenter);

        verticalLayout_16->addWidget(label_6);

        frame_15 = new QFrame(voltageMainFrame);
        frame_15->setObjectName(QString::fromUtf8("frame_15"));
        sizePolicy.setHeightForWidth(frame_15->sizePolicy().hasHeightForWidth());
        frame_15->setSizePolicy(sizePolicy);
        frame_15->setMaximumSize(QSize(148, 16777215));
        frame_15->setFrameShape(QFrame::StyledPanel);
        frame_15->setFrameShadow(QFrame::Raised);
        verticalLayout_17 = new QVBoxLayout(frame_15);
        verticalLayout_17->setSpacing(6);
        verticalLayout_17->setContentsMargins(11, 11, 11, 11);
        verticalLayout_17->setObjectName(QString::fromUtf8("verticalLayout_17"));
        voltageValueLabel = new QLabel(frame_15);
        voltageValueLabel->setObjectName(QString::fromUtf8("voltageValueLabel"));
        voltageValueLabel->setMinimumSize(QSize(128, 128));
        voltageValueLabel->setMaximumSize(QSize(128, 128));
        voltageValueLabel->setStyleSheet(QString::fromUtf8("font: 75 36pt \"Segoe UI\";"));
        voltageValueLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_17->addWidget(voltageValueLabel);


        verticalLayout_16->addWidget(frame_15);

        frame_16 = new QFrame(voltageMainFrame);
        frame_16->setObjectName(QString::fromUtf8("frame_16"));
        frame_16->setMaximumSize(QSize(148, 16777215));
        frame_16->setFrameShape(QFrame::StyledPanel);
        frame_16->setFrameShadow(QFrame::Raised);
        verticalLayout_18 = new QVBoxLayout(frame_16);
        verticalLayout_18->setSpacing(6);
        verticalLayout_18->setContentsMargins(11, 11, 11, 11);
        verticalLayout_18->setObjectName(QString::fromUtf8("verticalLayout_18"));
        voltageMainFrame_3 = new QFrame(frame_16);
        voltageMainFrame_3->setObjectName(QString::fromUtf8("voltageMainFrame_3"));
        voltageMainFrame_3->setMaximumSize(QSize(168, 16777215));
        voltageMainFrame_3->setFrameShape(QFrame::StyledPanel);
        voltageMainFrame_3->setFrameShadow(QFrame::Raised);
        verticalLayout_41 = new QVBoxLayout(voltageMainFrame_3);
        verticalLayout_41->setSpacing(0);
        verticalLayout_41->setContentsMargins(11, 11, 11, 11);
        verticalLayout_41->setObjectName(QString::fromUtf8("verticalLayout_41"));
        verticalLayout_41->setContentsMargins(0, 0, 0, 0);
        label_14 = new QLabel(voltageMainFrame_3);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setAlignment(Qt::AlignCenter);

        verticalLayout_41->addWidget(label_14);

        frame_30 = new QFrame(voltageMainFrame_3);
        frame_30->setObjectName(QString::fromUtf8("frame_30"));
        sizePolicy.setHeightForWidth(frame_30->sizePolicy().hasHeightForWidth());
        frame_30->setSizePolicy(sizePolicy);
        frame_30->setMaximumSize(QSize(148, 16777215));
        frame_30->setFrameShape(QFrame::StyledPanel);
        frame_30->setFrameShadow(QFrame::Raised);
        verticalLayout_42 = new QVBoxLayout(frame_30);
        verticalLayout_42->setSpacing(6);
        verticalLayout_42->setContentsMargins(11, 11, 11, 11);
        verticalLayout_42->setObjectName(QString::fromUtf8("verticalLayout_42"));
        blackRegionsCountValueLabel = new QLabel(frame_30);
        blackRegionsCountValueLabel->setObjectName(QString::fromUtf8("blackRegionsCountValueLabel"));
        blackRegionsCountValueLabel->setMinimumSize(QSize(128, 128));
        blackRegionsCountValueLabel->setMaximumSize(QSize(128, 128));
        blackRegionsCountValueLabel->setStyleSheet(QString::fromUtf8("font: 75 36pt \"Segoe UI\";"));
        blackRegionsCountValueLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_42->addWidget(blackRegionsCountValueLabel);


        verticalLayout_41->addWidget(frame_30);

        frame_31 = new QFrame(voltageMainFrame_3);
        frame_31->setObjectName(QString::fromUtf8("frame_31"));
        frame_31->setMaximumSize(QSize(148, 16777215));
        frame_31->setFrameShape(QFrame::StyledPanel);
        frame_31->setFrameShadow(QFrame::Raised);
        verticalLayout_43 = new QVBoxLayout(frame_31);
        verticalLayout_43->setSpacing(6);
        verticalLayout_43->setContentsMargins(11, 11, 11, 11);
        verticalLayout_43->setObjectName(QString::fromUtf8("verticalLayout_43"));
        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_43->addItem(verticalSpacer_4);


        verticalLayout_41->addWidget(frame_31);


        verticalLayout_18->addWidget(voltageMainFrame_3);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_18->addItem(verticalSpacer_2);


        verticalLayout_16->addWidget(frame_16);


        verticalLayout_27->addWidget(voltageMainFrame);


        horizontalLayout->addWidget(frame_2);

        frame_21 = new QFrame(frame_7);
        frame_21->setObjectName(QString::fromUtf8("frame_21"));
        frame_21->setFrameShape(QFrame::StyledPanel);
        frame_21->setFrameShadow(QFrame::Raised);
        verticalLayout_28 = new QVBoxLayout(frame_21);
        verticalLayout_28->setSpacing(6);
        verticalLayout_28->setContentsMargins(11, 11, 11, 11);
        verticalLayout_28->setObjectName(QString::fromUtf8("verticalLayout_28"));
        leftPwmMainFrame_2 = new QFrame(frame_21);
        leftPwmMainFrame_2->setObjectName(QString::fromUtf8("leftPwmMainFrame_2"));
        leftPwmMainFrame_2->setMaximumSize(QSize(168, 16777215));
        leftPwmMainFrame_2->setFrameShape(QFrame::StyledPanel);
        leftPwmMainFrame_2->setFrameShadow(QFrame::Raised);
        verticalLayout_29 = new QVBoxLayout(leftPwmMainFrame_2);
        verticalLayout_29->setSpacing(0);
        verticalLayout_29->setContentsMargins(11, 11, 11, 11);
        verticalLayout_29->setObjectName(QString::fromUtf8("verticalLayout_29"));
        verticalLayout_29->setContentsMargins(0, 0, 0, 0);
        label_10 = new QLabel(leftPwmMainFrame_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setAlignment(Qt::AlignCenter);

        verticalLayout_29->addWidget(label_10);

        frame_22 = new QFrame(leftPwmMainFrame_2);
        frame_22->setObjectName(QString::fromUtf8("frame_22"));
        sizePolicy.setHeightForWidth(frame_22->sizePolicy().hasHeightForWidth());
        frame_22->setSizePolicy(sizePolicy);
        frame_22->setMaximumSize(QSize(148, 16777215));
        frame_22->setFrameShape(QFrame::StyledPanel);
        frame_22->setFrameShadow(QFrame::Raised);
        verticalLayout_30 = new QVBoxLayout(frame_22);
        verticalLayout_30->setSpacing(6);
        verticalLayout_30->setContentsMargins(11, 11, 11, 11);
        verticalLayout_30->setObjectName(QString::fromUtf8("verticalLayout_30"));
        regionSizeLabel = new QLabel(frame_22);
        regionSizeLabel->setObjectName(QString::fromUtf8("regionSizeLabel"));
        regionSizeLabel->setMinimumSize(QSize(128, 128));
        regionSizeLabel->setMaximumSize(QSize(128, 128));
        regionSizeLabel->setStyleSheet(QString::fromUtf8("font: 75 36pt \"Segoe UI\";"));
        regionSizeLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_30->addWidget(regionSizeLabel);


        verticalLayout_29->addWidget(frame_22);

        frame_23 = new QFrame(leftPwmMainFrame_2);
        frame_23->setObjectName(QString::fromUtf8("frame_23"));
        frame_23->setMaximumSize(QSize(148, 16777215));
        frame_23->setFrameShape(QFrame::StyledPanel);
        frame_23->setFrameShadow(QFrame::Raised);
        verticalLayout_31 = new QVBoxLayout(frame_23);
        verticalLayout_31->setSpacing(6);
        verticalLayout_31->setContentsMargins(11, 11, 11, 11);
        verticalLayout_31->setObjectName(QString::fromUtf8("verticalLayout_31"));

        verticalLayout_29->addWidget(frame_23);


        verticalLayout_28->addWidget(leftPwmMainFrame_2);

        rightPwmMainFrame_2 = new QFrame(frame_21);
        rightPwmMainFrame_2->setObjectName(QString::fromUtf8("rightPwmMainFrame_2"));
        rightPwmMainFrame_2->setMaximumSize(QSize(168, 16777215));
        rightPwmMainFrame_2->setFrameShape(QFrame::StyledPanel);
        rightPwmMainFrame_2->setFrameShadow(QFrame::Raised);
        verticalLayout_32 = new QVBoxLayout(rightPwmMainFrame_2);
        verticalLayout_32->setSpacing(0);
        verticalLayout_32->setContentsMargins(11, 11, 11, 11);
        verticalLayout_32->setObjectName(QString::fromUtf8("verticalLayout_32"));
        verticalLayout_32->setContentsMargins(0, 0, 0, 0);
        label_11 = new QLabel(rightPwmMainFrame_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setAlignment(Qt::AlignCenter);

        verticalLayout_32->addWidget(label_11);

        frame_24 = new QFrame(rightPwmMainFrame_2);
        frame_24->setObjectName(QString::fromUtf8("frame_24"));
        sizePolicy.setHeightForWidth(frame_24->sizePolicy().hasHeightForWidth());
        frame_24->setSizePolicy(sizePolicy);
        frame_24->setMaximumSize(QSize(148, 16777215));
        frame_24->setFrameShape(QFrame::StyledPanel);
        frame_24->setFrameShadow(QFrame::Raised);
        verticalLayout_33 = new QVBoxLayout(frame_24);
        verticalLayout_33->setSpacing(6);
        verticalLayout_33->setContentsMargins(11, 11, 11, 11);
        verticalLayout_33->setObjectName(QString::fromUtf8("verticalLayout_33"));
        regionCenterLabel = new QLabel(frame_24);
        regionCenterLabel->setObjectName(QString::fromUtf8("regionCenterLabel"));
        regionCenterLabel->setMinimumSize(QSize(128, 128));
        regionCenterLabel->setMaximumSize(QSize(128, 128));
        regionCenterLabel->setStyleSheet(QString::fromUtf8("font: 75 36pt \"Segoe UI\";"));
        regionCenterLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_33->addWidget(regionCenterLabel);


        verticalLayout_32->addWidget(frame_24);

        frame_25 = new QFrame(rightPwmMainFrame_2);
        frame_25->setObjectName(QString::fromUtf8("frame_25"));
        frame_25->setMaximumSize(QSize(148, 16777215));
        frame_25->setFrameShape(QFrame::StyledPanel);
        frame_25->setFrameShadow(QFrame::Raised);
        verticalLayout_34 = new QVBoxLayout(frame_25);
        verticalLayout_34->setSpacing(6);
        verticalLayout_34->setContentsMargins(11, 11, 11, 11);
        verticalLayout_34->setObjectName(QString::fromUtf8("verticalLayout_34"));

        verticalLayout_32->addWidget(frame_25);


        verticalLayout_28->addWidget(rightPwmMainFrame_2);

        motorSpeedFrame_2 = new QFrame(frame_21);
        motorSpeedFrame_2->setObjectName(QString::fromUtf8("motorSpeedFrame_2"));
        motorSpeedFrame_2->setMaximumSize(QSize(168, 16777215));
        motorSpeedFrame_2->setFrameShape(QFrame::StyledPanel);
        motorSpeedFrame_2->setFrameShadow(QFrame::Raised);
        verticalLayout_35 = new QVBoxLayout(motorSpeedFrame_2);
        verticalLayout_35->setSpacing(0);
        verticalLayout_35->setContentsMargins(11, 11, 11, 11);
        verticalLayout_35->setObjectName(QString::fromUtf8("verticalLayout_35"));
        verticalLayout_35->setContentsMargins(0, 0, 0, 0);
        label_12 = new QLabel(motorSpeedFrame_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setAlignment(Qt::AlignCenter);

        verticalLayout_35->addWidget(label_12);

        frame_26 = new QFrame(motorSpeedFrame_2);
        frame_26->setObjectName(QString::fromUtf8("frame_26"));
        sizePolicy.setHeightForWidth(frame_26->sizePolicy().hasHeightForWidth());
        frame_26->setSizePolicy(sizePolicy);
        frame_26->setMaximumSize(QSize(148, 16777215));
        frame_26->setFrameShape(QFrame::StyledPanel);
        frame_26->setFrameShadow(QFrame::Raised);
        verticalLayout_36 = new QVBoxLayout(frame_26);
        verticalLayout_36->setSpacing(6);
        verticalLayout_36->setContentsMargins(11, 11, 11, 11);
        verticalLayout_36->setObjectName(QString::fromUtf8("verticalLayout_36"));
        leftPotLabel = new QLabel(frame_26);
        leftPotLabel->setObjectName(QString::fromUtf8("leftPotLabel"));
        leftPotLabel->setMinimumSize(QSize(128, 128));
        leftPotLabel->setMaximumSize(QSize(128, 128));
        leftPotLabel->setStyleSheet(QString::fromUtf8("font: 75 36pt \"Segoe UI\";"));
        leftPotLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_36->addWidget(leftPotLabel);


        verticalLayout_35->addWidget(frame_26);

        frame_27 = new QFrame(motorSpeedFrame_2);
        frame_27->setObjectName(QString::fromUtf8("frame_27"));
        frame_27->setMaximumSize(QSize(148, 16777215));
        frame_27->setFrameShape(QFrame::StyledPanel);
        frame_27->setFrameShadow(QFrame::Raised);
        verticalLayout_37 = new QVBoxLayout(frame_27);
        verticalLayout_37->setSpacing(6);
        verticalLayout_37->setContentsMargins(11, 11, 11, 11);
        verticalLayout_37->setObjectName(QString::fromUtf8("verticalLayout_37"));

        verticalLayout_35->addWidget(frame_27);


        verticalLayout_28->addWidget(motorSpeedFrame_2);

        voltageMainFrame_2 = new QFrame(frame_21);
        voltageMainFrame_2->setObjectName(QString::fromUtf8("voltageMainFrame_2"));
        voltageMainFrame_2->setMaximumSize(QSize(168, 16777215));
        voltageMainFrame_2->setFrameShape(QFrame::StyledPanel);
        voltageMainFrame_2->setFrameShadow(QFrame::Raised);
        verticalLayout_38 = new QVBoxLayout(voltageMainFrame_2);
        verticalLayout_38->setSpacing(0);
        verticalLayout_38->setContentsMargins(11, 11, 11, 11);
        verticalLayout_38->setObjectName(QString::fromUtf8("verticalLayout_38"));
        verticalLayout_38->setContentsMargins(0, 0, 0, 0);
        label_13 = new QLabel(voltageMainFrame_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setAlignment(Qt::AlignCenter);

        verticalLayout_38->addWidget(label_13);

        frame_28 = new QFrame(voltageMainFrame_2);
        frame_28->setObjectName(QString::fromUtf8("frame_28"));
        sizePolicy.setHeightForWidth(frame_28->sizePolicy().hasHeightForWidth());
        frame_28->setSizePolicy(sizePolicy);
        frame_28->setMaximumSize(QSize(148, 16777215));
        frame_28->setFrameShape(QFrame::StyledPanel);
        frame_28->setFrameShadow(QFrame::Raised);
        verticalLayout_39 = new QVBoxLayout(frame_28);
        verticalLayout_39->setSpacing(6);
        verticalLayout_39->setContentsMargins(11, 11, 11, 11);
        verticalLayout_39->setObjectName(QString::fromUtf8("verticalLayout_39"));
        rightPotLabel = new QLabel(frame_28);
        rightPotLabel->setObjectName(QString::fromUtf8("rightPotLabel"));
        rightPotLabel->setMinimumSize(QSize(128, 128));
        rightPotLabel->setMaximumSize(QSize(128, 128));
        rightPotLabel->setStyleSheet(QString::fromUtf8("font: 75 36pt \"Segoe UI\";"));
        rightPotLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_39->addWidget(rightPotLabel);


        verticalLayout_38->addWidget(frame_28);

        frame_29 = new QFrame(voltageMainFrame_2);
        frame_29->setObjectName(QString::fromUtf8("frame_29"));
        frame_29->setMaximumSize(QSize(148, 16777215));
        frame_29->setFrameShape(QFrame::StyledPanel);
        frame_29->setFrameShadow(QFrame::Raised);
        verticalLayout_40 = new QVBoxLayout(frame_29);
        verticalLayout_40->setSpacing(6);
        verticalLayout_40->setContentsMargins(11, 11, 11, 11);
        verticalLayout_40->setObjectName(QString::fromUtf8("verticalLayout_40"));
        voltageMainFrame_4 = new QFrame(frame_29);
        voltageMainFrame_4->setObjectName(QString::fromUtf8("voltageMainFrame_4"));
        voltageMainFrame_4->setMaximumSize(QSize(168, 16777215));
        voltageMainFrame_4->setFrameShape(QFrame::StyledPanel);
        voltageMainFrame_4->setFrameShadow(QFrame::Raised);
        verticalLayout_44 = new QVBoxLayout(voltageMainFrame_4);
        verticalLayout_44->setSpacing(0);
        verticalLayout_44->setContentsMargins(11, 11, 11, 11);
        verticalLayout_44->setObjectName(QString::fromUtf8("verticalLayout_44"));
        verticalLayout_44->setContentsMargins(0, 0, 0, 0);
        label_15 = new QLabel(voltageMainFrame_4);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setAlignment(Qt::AlignCenter);

        verticalLayout_44->addWidget(label_15);

        frame_32 = new QFrame(voltageMainFrame_4);
        frame_32->setObjectName(QString::fromUtf8("frame_32"));
        sizePolicy.setHeightForWidth(frame_32->sizePolicy().hasHeightForWidth());
        frame_32->setSizePolicy(sizePolicy);
        frame_32->setMaximumSize(QSize(148, 16777215));
        frame_32->setFrameShape(QFrame::StyledPanel);
        frame_32->setFrameShadow(QFrame::Raised);
        verticalLayout_45 = new QVBoxLayout(frame_32);
        verticalLayout_45->setSpacing(6);
        verticalLayout_45->setContentsMargins(11, 11, 11, 11);
        verticalLayout_45->setObjectName(QString::fromUtf8("verticalLayout_45"));
        whiteRegionsCountValueLabel = new QLabel(frame_32);
        whiteRegionsCountValueLabel->setObjectName(QString::fromUtf8("whiteRegionsCountValueLabel"));
        whiteRegionsCountValueLabel->setMinimumSize(QSize(128, 128));
        whiteRegionsCountValueLabel->setMaximumSize(QSize(128, 128));
        whiteRegionsCountValueLabel->setStyleSheet(QString::fromUtf8("font: 75 36pt \"Segoe UI\";"));
        whiteRegionsCountValueLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_45->addWidget(whiteRegionsCountValueLabel);


        verticalLayout_44->addWidget(frame_32);

        frame_33 = new QFrame(voltageMainFrame_4);
        frame_33->setObjectName(QString::fromUtf8("frame_33"));
        frame_33->setMaximumSize(QSize(148, 16777215));
        frame_33->setFrameShape(QFrame::StyledPanel);
        frame_33->setFrameShadow(QFrame::Raised);
        verticalLayout_46 = new QVBoxLayout(frame_33);
        verticalLayout_46->setSpacing(6);
        verticalLayout_46->setContentsMargins(11, 11, 11, 11);
        verticalLayout_46->setObjectName(QString::fromUtf8("verticalLayout_46"));
        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_46->addItem(verticalSpacer_5);


        verticalLayout_44->addWidget(frame_33);


        verticalLayout_40->addWidget(voltageMainFrame_4);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_40->addItem(verticalSpacer_3);


        verticalLayout_38->addWidget(frame_29);


        verticalLayout_28->addWidget(voltageMainFrame_2);


        horizontalLayout->addWidget(frame_21);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        connectionMainFrame = new QFrame(frame_7);
        connectionMainFrame->setObjectName(QString::fromUtf8("connectionMainFrame"));
        connectionMainFrame->setFrameShape(QFrame::StyledPanel);
        connectionMainFrame->setFrameShadow(QFrame::Raised);
        verticalLayout_19 = new QVBoxLayout(connectionMainFrame);
        verticalLayout_19->setSpacing(0);
        verticalLayout_19->setContentsMargins(11, 11, 11, 11);
        verticalLayout_19->setObjectName(QString::fromUtf8("verticalLayout_19"));
        verticalLayout_19->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(connectionMainFrame);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setAlignment(Qt::AlignCenter);

        verticalLayout_19->addWidget(label_7);

        frame_4 = new QFrame(connectionMainFrame);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        verticalLayout_20 = new QVBoxLayout(frame_4);
        verticalLayout_20->setSpacing(6);
        verticalLayout_20->setContentsMargins(11, 11, 11, 11);
        verticalLayout_20->setObjectName(QString::fromUtf8("verticalLayout_20"));
        connectComboBoxAddress = new QComboBox(frame_4);
        connectComboBoxAddress->addItem(QString());
        connectComboBoxAddress->addItem(QString());
        connectComboBoxAddress->addItem(QString());
        connectComboBoxAddress->addItem(QString());
        connectComboBoxAddress->setObjectName(QString::fromUtf8("connectComboBoxAddress"));

        verticalLayout_20->addWidget(connectComboBoxAddress);

        connectLineAddress = new QLineEdit(frame_4);
        connectLineAddress->setObjectName(QString::fromUtf8("connectLineAddress"));

        verticalLayout_20->addWidget(connectLineAddress);

        connectPort = new QLineEdit(frame_4);
        connectPort->setObjectName(QString::fromUtf8("connectPort"));

        verticalLayout_20->addWidget(connectPort);

        connectBtn = new QPushButton(frame_4);
        connectBtn->setObjectName(QString::fromUtf8("connectBtn"));

        verticalLayout_20->addWidget(connectBtn);

        disconnectBtn = new QPushButton(frame_4);
        disconnectBtn->setObjectName(QString::fromUtf8("disconnectBtn"));

        verticalLayout_20->addWidget(disconnectBtn);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_20->addItem(verticalSpacer);


        verticalLayout_19->addWidget(frame_4);


        horizontalLayout->addWidget(connectionMainFrame);


        horizontalLayout_2->addWidget(frame_7);

        frame_8 = new QFrame(centralWidget);
        frame_8->setObjectName(QString::fromUtf8("frame_8"));
        frame_8->setFrameShape(QFrame::StyledPanel);
        frame_8->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(frame_8);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));

        horizontalLayout_2->addWidget(frame_8);

        NxpCarInterfaceClass->setCentralWidget(centralWidget);

        retranslateUi(NxpCarInterfaceClass);

        QMetaObject::connectSlotsByName(NxpCarInterfaceClass);
    } // setupUi

    void retranslateUi(QMainWindow *NxpCarInterfaceClass)
    {
        NxpCarInterfaceClass->setWindowTitle(QApplication::translate("NxpCarInterfaceClass", "NxpCarInterface", nullptr));
        label->setText(QApplication::translate("NxpCarInterfaceClass", "Original Image", nullptr));
        label_8->setText(QApplication::translate("NxpCarInterfaceClass", "Normalized Image", nullptr));
        label_2->setText(QApplication::translate("NxpCarInterfaceClass", "Thresholded image", nullptr));
        label_3->setText(QApplication::translate("NxpCarInterfaceClass", "Servo", nullptr));
        servoValueLabel->setText(QApplication::translate("NxpCarInterfaceClass", "255", nullptr));
        label_4->setText(QApplication::translate("NxpCarInterfaceClass", "Left PWM", nullptr));
        leftPWMValueLabel->setText(QApplication::translate("NxpCarInterfaceClass", "255", nullptr));
        label_5->setText(QApplication::translate("NxpCarInterfaceClass", "Right PWM", nullptr));
        rightPwmValueLabel->setText(QApplication::translate("NxpCarInterfaceClass", "255", nullptr));
        label_9->setText(QApplication::translate("NxpCarInterfaceClass", "Motor speed", nullptr));
        motorSpeedValueLabel->setText(QApplication::translate("NxpCarInterfaceClass", "255", nullptr));
        label_6->setText(QApplication::translate("NxpCarInterfaceClass", "Voltage", nullptr));
        voltageValueLabel->setText(QApplication::translate("NxpCarInterfaceClass", "255", nullptr));
        label_14->setText(QApplication::translate("NxpCarInterfaceClass", "Black count", nullptr));
        blackRegionsCountValueLabel->setText(QApplication::translate("NxpCarInterfaceClass", "255", nullptr));
        label_10->setText(QApplication::translate("NxpCarInterfaceClass", "Velikost oblasti", nullptr));
        regionSizeLabel->setText(QApplication::translate("NxpCarInterfaceClass", "255", nullptr));
        label_11->setText(QApplication::translate("NxpCarInterfaceClass", "Stred oblasti", nullptr));
        regionCenterLabel->setText(QApplication::translate("NxpCarInterfaceClass", "255", nullptr));
        label_12->setText(QApplication::translate("NxpCarInterfaceClass", "Levy potenciometr", nullptr));
        leftPotLabel->setText(QApplication::translate("NxpCarInterfaceClass", "255", nullptr));
        label_13->setText(QApplication::translate("NxpCarInterfaceClass", "Pravy potenciometr", nullptr));
        rightPotLabel->setText(QApplication::translate("NxpCarInterfaceClass", "255", nullptr));
        label_15->setText(QApplication::translate("NxpCarInterfaceClass", "White count", nullptr));
        whiteRegionsCountValueLabel->setText(QApplication::translate("NxpCarInterfaceClass", "255", nullptr));
        label_7->setText(QApplication::translate("NxpCarInterfaceClass", "Connection", nullptr));
        connectComboBoxAddress->setItemText(0, QApplication::translate("NxpCarInterfaceClass", "192.168.4.1", nullptr));
        connectComboBoxAddress->setItemText(1, QApplication::translate("NxpCarInterfaceClass", "192.168.2.130", nullptr));
        connectComboBoxAddress->setItemText(2, QApplication::translate("NxpCarInterfaceClass", "169.254.94.243", nullptr));
        connectComboBoxAddress->setItemText(3, QApplication::translate("NxpCarInterfaceClass", "158.196.157.44", nullptr));

        connectLineAddress->setPlaceholderText(QApplication::translate("NxpCarInterfaceClass", "ip addr", nullptr));
        connectPort->setText(QApplication::translate("NxpCarInterfaceClass", "4444", nullptr));
        connectPort->setPlaceholderText(QApplication::translate("NxpCarInterfaceClass", "port", nullptr));
        connectBtn->setText(QApplication::translate("NxpCarInterfaceClass", "Connect", nullptr));
        disconnectBtn->setText(QApplication::translate("NxpCarInterfaceClass", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NxpCarInterfaceClass: public Ui_NxpCarInterfaceClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NXPCARINTERFACE_H