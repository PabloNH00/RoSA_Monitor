/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QLabel *workspace_selected;
    QPushButton *select_workspace_button;
    QVBoxLayout *verticalLayout_5;
    QLabel *imgETSIDI;
    QLabel *imgUPM;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *previousMenuButton;
    QSplitter *splitter;
    QWidget *layoutWidget_3;
    QVBoxLayout *verticalLayout;
    QPushButton *RosaButton;
    QPushButton *EnterSimButton;
    QPushButton *DemoButton;
    QWidget *layoutWidget_4;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1058, 547);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout_3 = new QHBoxLayout(centralwidget);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(30, 30, 30, 30);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(-1, -1, 15, -1);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);

        verticalLayout_3->addWidget(label_3, 0, Qt::AlignHCenter);

        workspace_selected = new QLabel(centralwidget);
        workspace_selected->setObjectName(QString::fromUtf8("workspace_selected"));
        sizePolicy1.setHeightForWidth(workspace_selected->sizePolicy().hasHeightForWidth());
        workspace_selected->setSizePolicy(sizePolicy1);

        verticalLayout_3->addWidget(workspace_selected, 0, Qt::AlignHCenter);

        select_workspace_button = new QPushButton(centralwidget);
        select_workspace_button->setObjectName(QString::fromUtf8("select_workspace_button"));
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(select_workspace_button->sizePolicy().hasHeightForWidth());
        select_workspace_button->setSizePolicy(sizePolicy2);

        verticalLayout_3->addWidget(select_workspace_button, 0, Qt::AlignHCenter);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setSizeConstraint(QLayout::SetMaximumSize);
        imgETSIDI = new QLabel(centralwidget);
        imgETSIDI->setObjectName(QString::fromUtf8("imgETSIDI"));
        QSizePolicy sizePolicy3(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(imgETSIDI->sizePolicy().hasHeightForWidth());
        imgETSIDI->setSizePolicy(sizePolicy3);
        imgETSIDI->setMaximumSize(QSize(350, 350));

        verticalLayout_5->addWidget(imgETSIDI);

        imgUPM = new QLabel(centralwidget);
        imgUPM->setObjectName(QString::fromUtf8("imgUPM"));
        sizePolicy3.setHeightForWidth(imgUPM->sizePolicy().hasHeightForWidth());
        imgUPM->setSizePolicy(sizePolicy3);
        imgUPM->setMaximumSize(QSize(350, 350));

        verticalLayout_5->addWidget(imgUPM);


        verticalLayout_3->addLayout(verticalLayout_5);


        horizontalLayout_3->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(15, -1, -1, -1);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        previousMenuButton = new QPushButton(centralwidget);
        previousMenuButton->setObjectName(QString::fromUtf8("previousMenuButton"));
        QSizePolicy sizePolicy4(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(previousMenuButton->sizePolicy().hasHeightForWidth());
        previousMenuButton->setSizePolicy(sizePolicy4);
        previousMenuButton->setContextMenuPolicy(Qt::NoContextMenu);

        horizontalLayout_2->addWidget(previousMenuButton, 0, Qt::AlignRight);


        verticalLayout_4->addLayout(horizontalLayout_2);

        splitter = new QSplitter(centralwidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Vertical);
        layoutWidget_3 = new QWidget(splitter);
        layoutWidget_3->setObjectName(QString::fromUtf8("layoutWidget_3"));
        verticalLayout = new QVBoxLayout(layoutWidget_3);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        RosaButton = new QPushButton(layoutWidget_3);
        RosaButton->setObjectName(QString::fromUtf8("RosaButton"));
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(RosaButton->sizePolicy().hasHeightForWidth());
        RosaButton->setSizePolicy(sizePolicy5);
        RosaButton->setCheckable(true);

        verticalLayout->addWidget(RosaButton);

        EnterSimButton = new QPushButton(layoutWidget_3);
        EnterSimButton->setObjectName(QString::fromUtf8("EnterSimButton"));
        sizePolicy5.setHeightForWidth(EnterSimButton->sizePolicy().hasHeightForWidth());
        EnterSimButton->setSizePolicy(sizePolicy5);
        EnterSimButton->setAutoFillBackground(false);
        EnterSimButton->setCheckable(true);

        verticalLayout->addWidget(EnterSimButton);

        DemoButton = new QPushButton(layoutWidget_3);
        DemoButton->setObjectName(QString::fromUtf8("DemoButton"));
        sizePolicy5.setHeightForWidth(DemoButton->sizePolicy().hasHeightForWidth());
        DemoButton->setSizePolicy(sizePolicy5);
        DemoButton->setCheckable(true);

        verticalLayout->addWidget(DemoButton);

        splitter->addWidget(layoutWidget_3);
        layoutWidget_4 = new QWidget(splitter);
        layoutWidget_4->setObjectName(QString::fromUtf8("layoutWidget_4"));
        verticalLayout_2 = new QVBoxLayout(layoutWidget_4);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget_4);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QSizePolicy sizePolicy6(QSizePolicy::Preferred, QSizePolicy::Ignored);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy6);

        verticalLayout_2->addWidget(label_2, 0, Qt::AlignRight);

        label = new QLabel(layoutWidget_4);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy6.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy6);

        verticalLayout_2->addWidget(label, 0, Qt::AlignRight);

        splitter->addWidget(layoutWidget_4);

        verticalLayout_4->addWidget(splitter);


        horizontalLayout_3->addLayout(verticalLayout_4);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1058, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:600;\">Selected workspace:</span></p></body></html>", nullptr));
        workspace_selected->setText(QCoreApplication::translate("MainWindow", "No workspace selected", nullptr));
        select_workspace_button->setText(QCoreApplication::translate("MainWindow", "Select workspace", nullptr));
        imgETSIDI->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        imgUPM->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        previousMenuButton->setText(QCoreApplication::translate("MainWindow", "Previous menu", nullptr));
        RosaButton->setText(QCoreApplication::translate("MainWindow", "Enter ROSA Menu", nullptr));
        EnterSimButton->setText(QCoreApplication::translate("MainWindow", "Enter Simulation Menu", nullptr));
        DemoButton->setText(QCoreApplication::translate("MainWindow", "Enter Demo Speak", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "ROSA Monitor", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Version 1.0.0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
