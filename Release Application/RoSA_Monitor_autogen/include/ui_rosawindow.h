/********************************************************************************
** Form generated from reading UI file 'rosawindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROSAWINDOW_H
#define UI_ROSAWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RosaWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QTabWidget *tabRoSAWidget;
    QWidget *tabRosaMenu;
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout_5;
    QPushButton *mainMenuButton;
    QVBoxLayout *verticalLayout_4;
    QPushButton *rosaButton;
    QHBoxLayout *horizontalLayout;
    QPushButton *firmwareButton;
    QPushButton *URDFButton;
    QPushButton *lidarButton;
    QPushButton *cameraButton;
    QWidget *tabDebugTools;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout_3;
    QPushButton *mainMenuButton_2;
    QFrame *line_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QPushButton *RvizzButton;
    QPushButton *graphButton;
    QPushButton *rqtButton;
    QPushButton *viewFramesButton;
    QPushButton *TeleopButton;
    QPushButton *esp32Button;
    QPushButton *nodeListButton;
    QFrame *line_3;
    QLabel *label_2;
    QLabel *mapLabel;
    QPushButton *selectMapButton;
    QFrame *line;
    QVBoxLayout *verticalLayout_7;
    QPushButton *SlamButton;
    QPushButton *navigationButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *RosaWindow)
    {
        if (RosaWindow->objectName().isEmpty())
            RosaWindow->setObjectName(QString::fromUtf8("RosaWindow"));
        RosaWindow->resize(789, 622);
        centralwidget = new QWidget(RosaWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tabRoSAWidget = new QTabWidget(centralwidget);
        tabRoSAWidget->setObjectName(QString::fromUtf8("tabRoSAWidget"));
        tabRosaMenu = new QWidget();
        tabRosaMenu->setObjectName(QString::fromUtf8("tabRosaMenu"));
        gridLayout_3 = new QGridLayout(tabRosaMenu);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        mainMenuButton = new QPushButton(tabRosaMenu);
        mainMenuButton->setObjectName(QString::fromUtf8("mainMenuButton"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(mainMenuButton->sizePolicy().hasHeightForWidth());
        mainMenuButton->setSizePolicy(sizePolicy);
        mainMenuButton->setContextMenuPolicy(Qt::NoContextMenu);

        verticalLayout_5->addWidget(mainMenuButton);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        rosaButton = new QPushButton(tabRosaMenu);
        rosaButton->setObjectName(QString::fromUtf8("rosaButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(rosaButton->sizePolicy().hasHeightForWidth());
        rosaButton->setSizePolicy(sizePolicy1);
        rosaButton->setCheckable(false);

        verticalLayout_4->addWidget(rosaButton);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        firmwareButton = new QPushButton(tabRosaMenu);
        firmwareButton->setObjectName(QString::fromUtf8("firmwareButton"));
        sizePolicy1.setHeightForWidth(firmwareButton->sizePolicy().hasHeightForWidth());
        firmwareButton->setSizePolicy(sizePolicy1);
        firmwareButton->setCheckable(true);

        horizontalLayout->addWidget(firmwareButton);

        URDFButton = new QPushButton(tabRosaMenu);
        URDFButton->setObjectName(QString::fromUtf8("URDFButton"));
        sizePolicy1.setHeightForWidth(URDFButton->sizePolicy().hasHeightForWidth());
        URDFButton->setSizePolicy(sizePolicy1);
        URDFButton->setCheckable(true);

        horizontalLayout->addWidget(URDFButton);

        lidarButton = new QPushButton(tabRosaMenu);
        lidarButton->setObjectName(QString::fromUtf8("lidarButton"));
        sizePolicy1.setHeightForWidth(lidarButton->sizePolicy().hasHeightForWidth());
        lidarButton->setSizePolicy(sizePolicy1);
        lidarButton->setCheckable(true);

        horizontalLayout->addWidget(lidarButton);

        cameraButton = new QPushButton(tabRosaMenu);
        cameraButton->setObjectName(QString::fromUtf8("cameraButton"));
        sizePolicy1.setHeightForWidth(cameraButton->sizePolicy().hasHeightForWidth());
        cameraButton->setSizePolicy(sizePolicy1);
        cameraButton->setContextMenuPolicy(Qt::NoContextMenu);
        cameraButton->setCheckable(true);

        horizontalLayout->addWidget(cameraButton);


        verticalLayout_4->addLayout(horizontalLayout);


        verticalLayout_5->addLayout(verticalLayout_4);


        gridLayout_3->addLayout(verticalLayout_5, 0, 0, 1, 1);

        tabRoSAWidget->addTab(tabRosaMenu, QString());
        tabDebugTools = new QWidget();
        tabDebugTools->setObjectName(QString::fromUtf8("tabDebugTools"));
        gridLayout_2 = new QGridLayout(tabDebugTools);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        mainMenuButton_2 = new QPushButton(tabDebugTools);
        mainMenuButton_2->setObjectName(QString::fromUtf8("mainMenuButton_2"));
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(mainMenuButton_2->sizePolicy().hasHeightForWidth());
        mainMenuButton_2->setSizePolicy(sizePolicy2);

        verticalLayout_3->addWidget(mainMenuButton_2);

        line_2 = new QFrame(tabDebugTools);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(tabDebugTools);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy3);

        verticalLayout->addWidget(label);

        RvizzButton = new QPushButton(tabDebugTools);
        RvizzButton->setObjectName(QString::fromUtf8("RvizzButton"));
        sizePolicy1.setHeightForWidth(RvizzButton->sizePolicy().hasHeightForWidth());
        RvizzButton->setSizePolicy(sizePolicy1);
        RvizzButton->setCheckable(true);

        verticalLayout->addWidget(RvizzButton);

        graphButton = new QPushButton(tabDebugTools);
        graphButton->setObjectName(QString::fromUtf8("graphButton"));
        sizePolicy1.setHeightForWidth(graphButton->sizePolicy().hasHeightForWidth());
        graphButton->setSizePolicy(sizePolicy1);
        graphButton->setCheckable(true);

        verticalLayout->addWidget(graphButton);

        rqtButton = new QPushButton(tabDebugTools);
        rqtButton->setObjectName(QString::fromUtf8("rqtButton"));
        sizePolicy1.setHeightForWidth(rqtButton->sizePolicy().hasHeightForWidth());
        rqtButton->setSizePolicy(sizePolicy1);
        rqtButton->setCheckable(true);

        verticalLayout->addWidget(rqtButton);

        viewFramesButton = new QPushButton(tabDebugTools);
        viewFramesButton->setObjectName(QString::fromUtf8("viewFramesButton"));
        sizePolicy1.setHeightForWidth(viewFramesButton->sizePolicy().hasHeightForWidth());
        viewFramesButton->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(viewFramesButton);

        TeleopButton = new QPushButton(tabDebugTools);
        TeleopButton->setObjectName(QString::fromUtf8("TeleopButton"));
        sizePolicy1.setHeightForWidth(TeleopButton->sizePolicy().hasHeightForWidth());
        TeleopButton->setSizePolicy(sizePolicy1);
        TeleopButton->setCheckable(true);

        verticalLayout->addWidget(TeleopButton);

        esp32Button = new QPushButton(tabDebugTools);
        esp32Button->setObjectName(QString::fromUtf8("esp32Button"));
        sizePolicy1.setHeightForWidth(esp32Button->sizePolicy().hasHeightForWidth());
        esp32Button->setSizePolicy(sizePolicy1);
        esp32Button->setCheckable(true);

        verticalLayout->addWidget(esp32Button);

        nodeListButton = new QPushButton(tabDebugTools);
        nodeListButton->setObjectName(QString::fromUtf8("nodeListButton"));
        sizePolicy1.setHeightForWidth(nodeListButton->sizePolicy().hasHeightForWidth());
        nodeListButton->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(nodeListButton);


        verticalLayout_3->addLayout(verticalLayout);


        verticalLayout_2->addLayout(verticalLayout_3);

        line_3 = new QFrame(tabDebugTools);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_3);

        label_2 = new QLabel(tabDebugTools);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy4);

        verticalLayout_2->addWidget(label_2);

        mapLabel = new QLabel(tabDebugTools);
        mapLabel->setObjectName(QString::fromUtf8("mapLabel"));
        sizePolicy4.setHeightForWidth(mapLabel->sizePolicy().hasHeightForWidth());
        mapLabel->setSizePolicy(sizePolicy4);

        verticalLayout_2->addWidget(mapLabel);

        selectMapButton = new QPushButton(tabDebugTools);
        selectMapButton->setObjectName(QString::fromUtf8("selectMapButton"));
        selectMapButton->setMaximumSize(QSize(550, 16777215));

        verticalLayout_2->addWidget(selectMapButton);


        horizontalLayout_3->addLayout(verticalLayout_2);

        line = new QFrame(tabDebugTools);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout_3->addWidget(line);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        SlamButton = new QPushButton(tabDebugTools);
        SlamButton->setObjectName(QString::fromUtf8("SlamButton"));
        QSizePolicy sizePolicy5(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(SlamButton->sizePolicy().hasHeightForWidth());
        SlamButton->setSizePolicy(sizePolicy5);
        SlamButton->setCheckable(true);

        verticalLayout_7->addWidget(SlamButton);

        navigationButton = new QPushButton(tabDebugTools);
        navigationButton->setObjectName(QString::fromUtf8("navigationButton"));
        sizePolicy5.setHeightForWidth(navigationButton->sizePolicy().hasHeightForWidth());
        navigationButton->setSizePolicy(sizePolicy5);
        navigationButton->setCheckable(true);

        verticalLayout_7->addWidget(navigationButton);


        horizontalLayout_3->addLayout(verticalLayout_7);


        gridLayout_2->addLayout(horizontalLayout_3, 0, 0, 1, 1);

        tabRoSAWidget->addTab(tabDebugTools, QString());

        gridLayout->addWidget(tabRoSAWidget, 0, 0, 1, 1);

        RosaWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(RosaWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 789, 22));
        RosaWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(RosaWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        RosaWindow->setStatusBar(statusbar);

        retranslateUi(RosaWindow);

        tabRoSAWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(RosaWindow);
    } // setupUi

    void retranslateUi(QMainWindow *RosaWindow)
    {
        RosaWindow->setWindowTitle(QCoreApplication::translate("RosaWindow", "MainWindow", nullptr));
        mainMenuButton->setText(QCoreApplication::translate("RosaWindow", "Main Menu", nullptr));
        rosaButton->setText(QCoreApplication::translate("RosaWindow", "Launch ROSA", nullptr));
        firmwareButton->setText(QCoreApplication::translate("RosaWindow", "Run Firmware", nullptr));
        URDFButton->setText(QCoreApplication::translate("RosaWindow", "Run URDF", nullptr));
        lidarButton->setText(QCoreApplication::translate("RosaWindow", "Run Hokuyo LiDAR", nullptr));
        cameraButton->setText(QCoreApplication::translate("RosaWindow", "Run camera", nullptr));
        tabRoSAWidget->setTabText(tabRoSAWidget->indexOf(tabRosaMenu), QCoreApplication::translate("RosaWindow", "RoSA Components", nullptr));
        mainMenuButton_2->setText(QCoreApplication::translate("RosaWindow", "Main menu", nullptr));
        label->setText(QCoreApplication::translate("RosaWindow", "Debug Tools:", nullptr));
        RvizzButton->setText(QCoreApplication::translate("RosaWindow", "Run Rviz2", nullptr));
        graphButton->setText(QCoreApplication::translate("RosaWindow", "Run rqt_graph", nullptr));
        rqtButton->setText(QCoreApplication::translate("RosaWindow", "Run rqt", nullptr));
        viewFramesButton->setText(QCoreApplication::translate("RosaWindow", "Print transform tree", nullptr));
        TeleopButton->setText(QCoreApplication::translate("RosaWindow", "Run Teleop_Twist", nullptr));
        esp32Button->setText(QCoreApplication::translate("RosaWindow", "Run ESP32 monitor", nullptr));
        nodeListButton->setText(QCoreApplication::translate("RosaWindow", "ROS2 node list", nullptr));
        label_2->setText(QCoreApplication::translate("RosaWindow", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600;\">Selected map for navigation:</span></p></body></html>", nullptr));
        mapLabel->setText(QCoreApplication::translate("RosaWindow", "<html><head/><body><p><span style=\" font-size:10pt;\">No map selected</span></p></body></html>", nullptr));
        selectMapButton->setText(QCoreApplication::translate("RosaWindow", "Select map", nullptr));
        SlamButton->setText(QCoreApplication::translate("RosaWindow", "Run SLAM", nullptr));
        navigationButton->setText(QCoreApplication::translate("RosaWindow", "Run Navigation", nullptr));
        tabRoSAWidget->setTabText(tabRoSAWidget->indexOf(tabDebugTools), QCoreApplication::translate("RosaWindow", "RoSA Menu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RosaWindow: public Ui_RosaWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROSAWINDOW_H
