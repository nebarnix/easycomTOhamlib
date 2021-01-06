/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_7;
    QVBoxLayout *verticalLayout_3;
    QGridLayout *gridLayout_3;
    QGroupBox *horizontalGroupBox_3;
    QHBoxLayout *horizontalLayout_4;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_9;
    QVBoxLayout *verticalLayout_8;
    QGridLayout *gridLayout_2;
    QPushButton *AzContH_down;
    QPushButton *AzContT_up;
    QPushButton *AzContT_down;
    QPushButton *AzContO_up;
    QPushButton *AzContO_down;
    QPushButton *AzContD_up;
    QPushButton *AzContD_down;
    QPushButton *AzContH_up;
    QLabel *label_18;
    QLabel *AzContH;
    QLabel *AzContO;
    QLabel *AzContT;
    QLabel *AzContD;
    QLabel *AzContS;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushbutton_AZ2CMD;
    QLabel *label_6;
    QLabel *AzReadLabel;
    QGroupBox *verticalGroupBox;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_11;
    QVBoxLayout *verticalLayout_10;
    QGridLayout *gridLayout_8;
    QPushButton *ElContO_up;
    QPushButton *ElContD_down;
    QPushButton *ElContD_up;
    QLabel *ElContD;
    QPushButton *ElContH_up;
    QPushButton *ElContO_down;
    QPushButton *ElContH_down;
    QPushButton *ElContT_up;
    QPushButton *ElContT_down;
    QLabel *label_19;
    QLabel *ElContH;
    QLabel *ElContO;
    QLabel *ElContT;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *pushbutton_EL2CMD;
    QLabel *label_10;
    QLabel *ElReadLabel;
    QHBoxLayout *horizontalLayout_3;
    QGridLayout *gridLayout_5;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_Serial;
    QPushButton *pushButton_Network;
    QPushButton *pushButton_STOP;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *pushButton_GO;
    QPushButton *pushButton_SendOnce;
    QGridLayout *gridLayout_6;
    QLineEdit *lineEdit_IPAdd;
    QLineEdit *lineEdit_serPort;
    QLineEdit *lineEdit_IPPort;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QGroupBox *groupBox1;
    QVBoxLayout *verticalLayout_2;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(899, 347);
        MainWindow->setWindowTitle(QStringLiteral("easycomTOhamlib - KE7PHI aka Nebarnix"));
        QIcon icon;
        icon.addFile(QStringLiteral("../../stupidicon.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_7 = new QHBoxLayout(centralWidget);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setSizeConstraint(QLayout::SetFixedSize);
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        horizontalGroupBox_3 = new QGroupBox(centralWidget);
        horizontalGroupBox_3->setObjectName(QStringLiteral("horizontalGroupBox_3"));
        horizontalLayout_4 = new QHBoxLayout(horizontalGroupBox_3);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        groupBox = new QGroupBox(horizontalGroupBox_3);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMinimumSize(QSize(0, 50));
        verticalLayout_9 = new QVBoxLayout(groupBox);
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(-1, 10, -1, 1);
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        AzContH_down = new QPushButton(groupBox);
        AzContH_down->setObjectName(QStringLiteral("AzContH_down"));
        AzContH_down->setMaximumSize(QSize(20, 16777215));

        gridLayout_2->addWidget(AzContH_down, 2, 1, 1, 1);

        AzContT_up = new QPushButton(groupBox);
        AzContT_up->setObjectName(QStringLiteral("AzContT_up"));
        AzContT_up->setMaximumSize(QSize(20, 16777215));

        gridLayout_2->addWidget(AzContT_up, 0, 2, 1, 1);

        AzContT_down = new QPushButton(groupBox);
        AzContT_down->setObjectName(QStringLiteral("AzContT_down"));
        AzContT_down->setMaximumSize(QSize(20, 16777215));

        gridLayout_2->addWidget(AzContT_down, 2, 2, 1, 1);

        AzContO_up = new QPushButton(groupBox);
        AzContO_up->setObjectName(QStringLiteral("AzContO_up"));
        AzContO_up->setMaximumSize(QSize(20, 16777215));

        gridLayout_2->addWidget(AzContO_up, 0, 3, 1, 1);

        AzContO_down = new QPushButton(groupBox);
        AzContO_down->setObjectName(QStringLiteral("AzContO_down"));
        AzContO_down->setMaximumSize(QSize(20, 16777215));

        gridLayout_2->addWidget(AzContO_down, 2, 3, 1, 1);

        AzContD_up = new QPushButton(groupBox);
        AzContD_up->setObjectName(QStringLiteral("AzContD_up"));
        AzContD_up->setMaximumSize(QSize(20, 16777215));

        gridLayout_2->addWidget(AzContD_up, 0, 5, 1, 1);

        AzContD_down = new QPushButton(groupBox);
        AzContD_down->setObjectName(QStringLiteral("AzContD_down"));
        AzContD_down->setMaximumSize(QSize(20, 16777215));

        gridLayout_2->addWidget(AzContD_down, 2, 5, 1, 1);

        AzContH_up = new QPushButton(groupBox);
        AzContH_up->setObjectName(QStringLiteral("AzContH_up"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AzContH_up->sizePolicy().hasHeightForWidth());
        AzContH_up->setSizePolicy(sizePolicy);
        AzContH_up->setMaximumSize(QSize(20, 200));
        AzContH_up->setBaseSize(QSize(0, 0));
        AzContH_up->setText(QString::fromUtf8("\313\204"));
        AzContH_up->setIconSize(QSize(20, 15));
        AzContH_up->setFlat(false);

        gridLayout_2->addWidget(AzContH_up, 0, 1, 1, 1);

        label_18 = new QLabel(groupBox);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setMaximumSize(QSize(10, 16777215));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        label_18->setFont(font);
        label_18->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_18, 1, 4, 1, 1);

        AzContH = new QLabel(groupBox);
        AzContH->setObjectName(QStringLiteral("AzContH"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(AzContH->sizePolicy().hasHeightForWidth());
        AzContH->setSizePolicy(sizePolicy1);
        AzContH->setFont(font);
        AzContH->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(AzContH, 1, 1, 1, 1);

        AzContO = new QLabel(groupBox);
        AzContO->setObjectName(QStringLiteral("AzContO"));
        sizePolicy1.setHeightForWidth(AzContO->sizePolicy().hasHeightForWidth());
        AzContO->setSizePolicy(sizePolicy1);
        AzContO->setFont(font);
        AzContO->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(AzContO, 1, 3, 1, 1);

        AzContT = new QLabel(groupBox);
        AzContT->setObjectName(QStringLiteral("AzContT"));
        sizePolicy1.setHeightForWidth(AzContT->sizePolicy().hasHeightForWidth());
        AzContT->setSizePolicy(sizePolicy1);
        AzContT->setFont(font);
        AzContT->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(AzContT, 1, 2, 1, 1);

        AzContD = new QLabel(groupBox);
        AzContD->setObjectName(QStringLiteral("AzContD"));
        sizePolicy1.setHeightForWidth(AzContD->sizePolicy().hasHeightForWidth());
        AzContD->setSizePolicy(sizePolicy1);
        AzContD->setFont(font);
        AzContD->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(AzContD, 1, 5, 1, 1);

        AzContS = new QLabel(groupBox);
        AzContS->setObjectName(QStringLiteral("AzContS"));
        sizePolicy1.setHeightForWidth(AzContS->sizePolicy().hasHeightForWidth());
        AzContS->setSizePolicy(sizePolicy1);
        AzContS->setMaximumSize(QSize(20, 16777215));
        AzContS->setFont(font);
        AzContS->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(AzContS, 1, 0, 1, 1);


        verticalLayout_8->addLayout(gridLayout_2);


        verticalLayout_9->addLayout(verticalLayout_8);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        pushbutton_AZ2CMD = new QPushButton(groupBox);
        pushbutton_AZ2CMD->setObjectName(QStringLiteral("pushbutton_AZ2CMD"));
        sizePolicy.setHeightForWidth(pushbutton_AZ2CMD->sizePolicy().hasHeightForWidth());
        pushbutton_AZ2CMD->setSizePolicy(sizePolicy);
        pushbutton_AZ2CMD->setMaximumSize(QSize(20, 20));
        pushbutton_AZ2CMD->setBaseSize(QSize(0, 0));
        pushbutton_AZ2CMD->setText(QString::fromUtf8("\313\204"));
        pushbutton_AZ2CMD->setIconSize(QSize(20, 15));
        pushbutton_AZ2CMD->setFlat(false);

        horizontalLayout_5->addWidget(pushbutton_AZ2CMD);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_5->addWidget(label_6);

        AzReadLabel = new QLabel(groupBox);
        AzReadLabel->setObjectName(QStringLiteral("AzReadLabel"));

        horizontalLayout_5->addWidget(AzReadLabel);


        verticalLayout_9->addLayout(horizontalLayout_5);


        horizontalLayout_4->addWidget(groupBox);


        gridLayout_3->addWidget(horizontalGroupBox_3, 0, 0, 1, 1);

        verticalGroupBox = new QGroupBox(centralWidget);
        verticalGroupBox->setObjectName(QStringLiteral("verticalGroupBox"));
        verticalLayout = new QVBoxLayout(verticalGroupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox_2 = new QGroupBox(verticalGroupBox);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setMinimumSize(QSize(0, 20));
        verticalLayout_11 = new QVBoxLayout(groupBox_2);
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setContentsMargins(11, 11, 11, 11);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        verticalLayout_11->setContentsMargins(-1, 10, 11, 1);
        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        gridLayout_8 = new QGridLayout();
        gridLayout_8->setSpacing(6);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        ElContO_up = new QPushButton(groupBox_2);
        ElContO_up->setObjectName(QStringLiteral("ElContO_up"));
        ElContO_up->setMaximumSize(QSize(20, 16777215));

        gridLayout_8->addWidget(ElContO_up, 0, 2, 1, 1);

        ElContD_down = new QPushButton(groupBox_2);
        ElContD_down->setObjectName(QStringLiteral("ElContD_down"));
        ElContD_down->setMaximumSize(QSize(20, 16777215));

        gridLayout_8->addWidget(ElContD_down, 2, 4, 1, 1);

        ElContD_up = new QPushButton(groupBox_2);
        ElContD_up->setObjectName(QStringLiteral("ElContD_up"));
        ElContD_up->setMaximumSize(QSize(20, 16777215));

        gridLayout_8->addWidget(ElContD_up, 0, 4, 1, 1);

        ElContD = new QLabel(groupBox_2);
        ElContD->setObjectName(QStringLiteral("ElContD"));
        sizePolicy1.setHeightForWidth(ElContD->sizePolicy().hasHeightForWidth());
        ElContD->setSizePolicy(sizePolicy1);
        ElContD->setFont(font);
        ElContD->setAlignment(Qt::AlignCenter);

        gridLayout_8->addWidget(ElContD, 1, 4, 1, 1);

        ElContH_up = new QPushButton(groupBox_2);
        ElContH_up->setObjectName(QStringLiteral("ElContH_up"));
        ElContH_up->setMaximumSize(QSize(20, 16777215));

        gridLayout_8->addWidget(ElContH_up, 0, 0, 1, 1);

        ElContO_down = new QPushButton(groupBox_2);
        ElContO_down->setObjectName(QStringLiteral("ElContO_down"));
        ElContO_down->setMaximumSize(QSize(20, 16777215));

        gridLayout_8->addWidget(ElContO_down, 2, 2, 1, 1);

        ElContH_down = new QPushButton(groupBox_2);
        ElContH_down->setObjectName(QStringLiteral("ElContH_down"));
        ElContH_down->setMaximumSize(QSize(20, 16777215));

        gridLayout_8->addWidget(ElContH_down, 2, 0, 1, 1);

        ElContT_up = new QPushButton(groupBox_2);
        ElContT_up->setObjectName(QStringLiteral("ElContT_up"));
        ElContT_up->setMaximumSize(QSize(20, 16777215));

        gridLayout_8->addWidget(ElContT_up, 0, 1, 1, 1);

        ElContT_down = new QPushButton(groupBox_2);
        ElContT_down->setObjectName(QStringLiteral("ElContT_down"));
        ElContT_down->setMaximumSize(QSize(20, 16777215));

        gridLayout_8->addWidget(ElContT_down, 2, 1, 1, 1);

        label_19 = new QLabel(groupBox_2);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setMaximumSize(QSize(10, 16777215));
        label_19->setFont(font);
        label_19->setAlignment(Qt::AlignCenter);

        gridLayout_8->addWidget(label_19, 1, 3, 1, 1);

        ElContH = new QLabel(groupBox_2);
        ElContH->setObjectName(QStringLiteral("ElContH"));
        sizePolicy1.setHeightForWidth(ElContH->sizePolicy().hasHeightForWidth());
        ElContH->setSizePolicy(sizePolicy1);
        ElContH->setFont(font);
        ElContH->setAlignment(Qt::AlignCenter);

        gridLayout_8->addWidget(ElContH, 1, 0, 1, 1);

        ElContO = new QLabel(groupBox_2);
        ElContO->setObjectName(QStringLiteral("ElContO"));
        ElContO->setFont(font);
        ElContO->setAlignment(Qt::AlignCenter);

        gridLayout_8->addWidget(ElContO, 1, 2, 1, 1);

        ElContT = new QLabel(groupBox_2);
        ElContT->setObjectName(QStringLiteral("ElContT"));
        sizePolicy1.setHeightForWidth(ElContT->sizePolicy().hasHeightForWidth());
        ElContT->setSizePolicy(sizePolicy1);
        ElContT->setFont(font);
        ElContT->setAlignment(Qt::AlignCenter);

        gridLayout_8->addWidget(ElContT, 1, 1, 1, 1);


        verticalLayout_10->addLayout(gridLayout_8);


        verticalLayout_11->addLayout(verticalLayout_10);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        pushbutton_EL2CMD = new QPushButton(groupBox_2);
        pushbutton_EL2CMD->setObjectName(QStringLiteral("pushbutton_EL2CMD"));
        sizePolicy.setHeightForWidth(pushbutton_EL2CMD->sizePolicy().hasHeightForWidth());
        pushbutton_EL2CMD->setSizePolicy(sizePolicy);
        pushbutton_EL2CMD->setMaximumSize(QSize(20, 20));
        pushbutton_EL2CMD->setBaseSize(QSize(0, 0));
        pushbutton_EL2CMD->setText(QString::fromUtf8("\313\204"));
        pushbutton_EL2CMD->setIconSize(QSize(20, 15));
        pushbutton_EL2CMD->setFlat(false);

        horizontalLayout_6->addWidget(pushbutton_EL2CMD);

        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout_6->addWidget(label_10);

        ElReadLabel = new QLabel(groupBox_2);
        ElReadLabel->setObjectName(QStringLiteral("ElReadLabel"));

        horizontalLayout_6->addWidget(ElReadLabel);


        verticalLayout_11->addLayout(horizontalLayout_6);


        verticalLayout->addWidget(groupBox_2);


        gridLayout_3->addWidget(verticalGroupBox, 0, 1, 1, 1);


        verticalLayout_3->addLayout(gridLayout_3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        gridLayout_5 = new QGridLayout();
        gridLayout_5->setSpacing(6);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton_Serial = new QPushButton(centralWidget);
        pushButton_Serial->setObjectName(QStringLiteral("pushButton_Serial"));

        horizontalLayout->addWidget(pushButton_Serial);

        pushButton_Network = new QPushButton(centralWidget);
        pushButton_Network->setObjectName(QStringLiteral("pushButton_Network"));

        horizontalLayout->addWidget(pushButton_Network);


        gridLayout_5->addLayout(horizontalLayout, 0, 0, 1, 1);

        pushButton_STOP = new QPushButton(centralWidget);
        pushButton_STOP->setObjectName(QStringLiteral("pushButton_STOP"));
        pushButton_STOP->setStyleSheet(QStringLiteral("background:RED"));

        gridLayout_5->addWidget(pushButton_STOP, 2, 0, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        pushButton_GO = new QPushButton(centralWidget);
        pushButton_GO->setObjectName(QStringLiteral("pushButton_GO"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(5);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButton_GO->sizePolicy().hasHeightForWidth());
        pushButton_GO->setSizePolicy(sizePolicy2);

        horizontalLayout_8->addWidget(pushButton_GO);

        pushButton_SendOnce = new QPushButton(centralWidget);
        pushButton_SendOnce->setObjectName(QStringLiteral("pushButton_SendOnce"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(pushButton_SendOnce->sizePolicy().hasHeightForWidth());
        pushButton_SendOnce->setSizePolicy(sizePolicy3);
        pushButton_SendOnce->setMinimumSize(QSize(50, 0));
        pushButton_SendOnce->setMaximumSize(QSize(60, 16777215));

        horizontalLayout_8->addWidget(pushButton_SendOnce);


        gridLayout_5->addLayout(horizontalLayout_8, 1, 0, 1, 1);


        horizontalLayout_3->addLayout(gridLayout_5);

        gridLayout_6 = new QGridLayout();
        gridLayout_6->setSpacing(6);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        gridLayout_6->setHorizontalSpacing(7);
        lineEdit_IPAdd = new QLineEdit(centralWidget);
        lineEdit_IPAdd->setObjectName(QStringLiteral("lineEdit_IPAdd"));

        gridLayout_6->addWidget(lineEdit_IPAdd, 1, 1, 1, 1);

        lineEdit_serPort = new QLineEdit(centralWidget);
        lineEdit_serPort->setObjectName(QStringLiteral("lineEdit_serPort"));

        gridLayout_6->addWidget(lineEdit_serPort, 0, 1, 1, 1);

        lineEdit_IPPort = new QLineEdit(centralWidget);
        lineEdit_IPPort->setObjectName(QStringLiteral("lineEdit_IPPort"));

        gridLayout_6->addWidget(lineEdit_IPPort, 2, 1, 1, 1);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_6->addWidget(label_2, 1, 0, 1, 1);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_6->addWidget(label_3, 2, 0, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_6->addWidget(label, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer, 1, 2, 1, 1);

        gridLayout_6->setColumnStretch(1, 7);
        gridLayout_6->setColumnStretch(2, 1);

        horizontalLayout_3->addLayout(gridLayout_6);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 1);

        verticalLayout_3->addLayout(horizontalLayout_3);


        horizontalLayout_7->addLayout(verticalLayout_3);

        groupBox1 = new QGroupBox(centralWidget);
        groupBox1->setObjectName(QStringLiteral("groupBox1"));
        sizePolicy.setHeightForWidth(groupBox1->sizePolicy().hasHeightForWidth());
        groupBox1->setSizePolicy(sizePolicy);
        groupBox1->setMinimumSize(QSize(300, 300));
        verticalLayout_2 = new QVBoxLayout(groupBox1);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));

        horizontalLayout_7->addWidget(groupBox1);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        AzContH_up->setDefault(false);
        pushbutton_AZ2CMD->setDefault(false);
        pushbutton_EL2CMD->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        groupBox->setTitle(QApplication::translate("MainWindow", "Azimuth", 0));
        AzContH_down->setText(QApplication::translate("MainWindow", "\313\205", 0));
        AzContT_up->setText(QApplication::translate("MainWindow", "\313\204", 0));
        AzContT_down->setText(QApplication::translate("MainWindow", "\313\205", 0));
        AzContO_up->setText(QApplication::translate("MainWindow", "\313\204", 0));
        AzContO_down->setText(QApplication::translate("MainWindow", "\313\205", 0));
        AzContD_up->setText(QApplication::translate("MainWindow", "\313\204", 0));
        AzContD_down->setText(QApplication::translate("MainWindow", "\313\205", 0));
        label_18->setText(QApplication::translate("MainWindow", ".", 0));
        AzContH->setText(QApplication::translate("MainWindow", "0", 0));
        AzContO->setText(QApplication::translate("MainWindow", "5", 0));
        AzContT->setText(QApplication::translate("MainWindow", "4", 0));
        AzContD->setText(QApplication::translate("MainWindow", "6", 0));
        AzContS->setText(QApplication::translate("MainWindow", "+", 0));
        label_6->setText(QApplication::translate("MainWindow", "Read:", 0));
        AzReadLabel->setText(QApplication::translate("MainWindow", "000.0", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Elevation", 0));
        ElContO_up->setText(QApplication::translate("MainWindow", "\313\204", 0));
        ElContD_down->setText(QApplication::translate("MainWindow", "\313\205", 0));
        ElContD_up->setText(QApplication::translate("MainWindow", "\313\204", 0));
        ElContD->setText(QApplication::translate("MainWindow", "5", 0));
        ElContH_up->setText(QApplication::translate("MainWindow", "\313\204", 0));
        ElContO_down->setText(QApplication::translate("MainWindow", "\313\205", 0));
        ElContH_down->setText(QApplication::translate("MainWindow", "\313\205", 0));
        ElContT_up->setText(QApplication::translate("MainWindow", "\313\204", 0));
        ElContT_down->setText(QApplication::translate("MainWindow", "\313\205", 0));
        label_19->setText(QApplication::translate("MainWindow", ".", 0));
        ElContH->setText(QApplication::translate("MainWindow", "0", 0));
        ElContO->setText(QApplication::translate("MainWindow", "5", 0));
        ElContT->setText(QApplication::translate("MainWindow", "4", 0));
        label_10->setText(QApplication::translate("MainWindow", "Read:", 0));
        ElReadLabel->setText(QApplication::translate("MainWindow", "000.0", 0));
        pushButton_Serial->setText(QApplication::translate("MainWindow", "Connect Serial", 0));
        pushButton_Network->setText(QApplication::translate("MainWindow", "Connect Network", 0));
        pushButton_STOP->setText(QApplication::translate("MainWindow", "EMERGENCY STOP", 0));
        pushButton_GO->setText(QApplication::translate("MainWindow", "GO", 0));
        pushButton_SendOnce->setText(QApplication::translate("MainWindow", "Once", 0));
        lineEdit_IPAdd->setText(QApplication::translate("MainWindow", "192.168.1.138", 0));
        lineEdit_IPPort->setText(QApplication::translate("MainWindow", "4533", 0));
        label_2->setText(QApplication::translate("MainWindow", "Rotor IP", 0));
        label_3->setText(QApplication::translate("MainWindow", "Rotor Port      ", 0));
        label->setText(QApplication::translate("MainWindow", "Serial Port", 0));
        Q_UNUSED(MainWindow);
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
