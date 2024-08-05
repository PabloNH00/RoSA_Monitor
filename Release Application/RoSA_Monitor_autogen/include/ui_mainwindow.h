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
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QLabel *workspace_selected;
    QPushButton *select_workspace_button;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *previousMenuButton;
    QSplitter *splitter;
    QWidget *layoutWidget_3;
    QVBoxLayout *verticalLayout;
    QPushButton *RosaButton;
    QPushButton *EnterSimButton;
    QWidget *layoutWidget_4;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QLabel *label;
    QLabel *imgUPM;
    QLabel *imgETSIDI;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(807, 636);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(40, 50, 161, 73));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_3->addWidget(label_3);

        workspace_selected = new QLabel(layoutWidget);
        workspace_selected->setObjectName(QString::fromUtf8("workspace_selected"));

        verticalLayout_3->addWidget(workspace_selected);

        select_workspace_button = new QPushButton(layoutWidget);
        select_workspace_button->setObjectName(QString::fromUtf8("select_workspace_button"));

        verticalLayout_3->addWidget(select_workspace_button);

        layoutWidget_2 = new QWidget(centralwidget);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(320, 10, 461, 581));
        verticalLayout_4 = new QVBoxLayout(layoutWidget_2);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        previousMenuButton = new QPushButton(layoutWidget_2);
        previousMenuButton->setObjectName(QString::fromUtf8("previousMenuButton"));
        previousMenuButton->setContextMenuPolicy(Qt::NoContextMenu);

        horizontalLayout_2->addWidget(previousMenuButton);


        verticalLayout_4->addLayout(horizontalLayout_2);

        splitter = new QSplitter(layoutWidget_2);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Vertical);
        layoutWidget_3 = new QWidget(splitter);
        layoutWidget_3->setObjectName(QString::fromUtf8("layoutWidget_3"));
        verticalLayout = new QVBoxLayout(layoutWidget_3);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        RosaButton = new QPushButton(layoutWidget_3);
        RosaButton->setObjectName(QString::fromUtf8("RosaButton"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(RosaButton->sizePolicy().hasHeightForWidth());
        RosaButton->setSizePolicy(sizePolicy);
        RosaButton->setCheckable(true);

        verticalLayout->addWidget(RosaButton);

        EnterSimButton = new QPushButton(layoutWidget_3);
        EnterSimButton->setObjectName(QString::fromUtf8("EnterSimButton"));
        sizePolicy.setHeightForWidth(EnterSimButton->sizePolicy().hasHeightForWidth());
        EnterSimButton->setSizePolicy(sizePolicy);
        EnterSimButton->setCheckable(true);

        verticalLayout->addWidget(EnterSimButton);

        splitter->addWidget(layoutWidget_3);
        layoutWidget_4 = new QWidget(splitter);
        layoutWidget_4->setObjectName(QString::fromUtf8("layoutWidget_4"));
        verticalLayout_2 = new QVBoxLayout(layoutWidget_4);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget_4);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Ignored);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);

        verticalLayout_2->addWidget(label_2);

        label = new QLabel(layoutWidget_4);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);

        verticalLayout_2->addWidget(label);

        splitter->addWidget(layoutWidget_4);

        verticalLayout_4->addWidget(splitter);

        imgUPM = new QLabel(centralwidget);
        imgUPM->setObjectName(QString::fromUtf8("imgUPM"));
        imgUPM->setGeometry(QRect(20, 210, 291, 161));
        imgETSIDI = new QLabel(centralwidget);
        imgETSIDI->setObjectName(QString::fromUtf8("imgETSIDI"));
        imgETSIDI->setGeometry(QRect(10, 410, 311, 121));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 807, 22));
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
        select_workspace_button->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        previousMenuButton->setText(QCoreApplication::translate("MainWindow", "Previous menu", nullptr));
        RosaButton->setText(QCoreApplication::translate("MainWindow", "Start RoSA Menu", nullptr));
        EnterSimButton->setText(QCoreApplication::translate("MainWindow", "Enter Simulation Mode", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "                                                                                                     RoSa Monitor", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "                                                                                                       Version 0.1.7", nullptr));
        imgUPM->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        imgETSIDI->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
