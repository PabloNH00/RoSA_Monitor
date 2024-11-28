/********************************************************************************
** Form generated from reading UI file 'simulationwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIMULATIONWINDOW_H
#define UI_SIMULATIONWINDOW_H

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

class Ui_SimulationWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QTabWidget *tabsimulationWidget;
    QWidget *tab_IndeximMenu;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout_3;
    QPushButton *mainMenuButton;
    QFrame *line_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QPushButton *RvizzButton;
    QPushButton *graphButton;
    QPushButton *rqtButton;
    QPushButton *viewFramesButton;
    QPushButton *TeleopButton;
    QPushButton *nodeListButton;
    QFrame *line_3;
    QLabel *label_2;
    QLabel *mapLabel;
    QPushButton *selectMapButton;
    QFrame *line;
    QVBoxLayout *verticalLayout_7;
    QPushButton *GazeboButton;
    QPushButton *SlamButton;
    QPushButton *navigationButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SimulationWindow)
    {
        if (SimulationWindow->objectName().isEmpty())
            SimulationWindow->setObjectName(QString::fromUtf8("SimulationWindow"));
        SimulationWindow->resize(982, 608);
        centralwidget = new QWidget(SimulationWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tabsimulationWidget = new QTabWidget(centralwidget);
        tabsimulationWidget->setObjectName(QString::fromUtf8("tabsimulationWidget"));
        tabsimulationWidget->setEnabled(true);
        tab_IndeximMenu = new QWidget();
        tab_IndeximMenu->setObjectName(QString::fromUtf8("tab_IndeximMenu"));
        gridLayout_2 = new QGridLayout(tab_IndeximMenu);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        mainMenuButton = new QPushButton(tab_IndeximMenu);
        mainMenuButton->setObjectName(QString::fromUtf8("mainMenuButton"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(mainMenuButton->sizePolicy().hasHeightForWidth());
        mainMenuButton->setSizePolicy(sizePolicy);
        mainMenuButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font-family: \"Times New Roman\";\n"
"    font-size: 18px;  /* Fuente m\303\241s grande (18px) */\n"
"    font-weight: bold;\n"
"    border: 2px solid #ccc;  /* Borde gris claro */\n"
"    border-radius: 5px;  /* Bordes ligeramente redondeados */\n"
"    padding: 10px 20px;  /* Relleno alrededor del texto */\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 white, stop:1 #f0f0f0);  /* Degradado de blanco a gris claro */\n"
"    color: black;  /* Texto negro */\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"    border-color: green;  /* Borde verde cuando est\303\251 marcado */\n"
"    background-color: lightgreen;  /* Fondo verde claro cuando est\303\251 marcado */\n"
"}\n"
""));

        verticalLayout_3->addWidget(mainMenuButton);

        line_2 = new QFrame(tab_IndeximMenu);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(tab_IndeximMenu);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(label);

        RvizzButton = new QPushButton(tab_IndeximMenu);
        RvizzButton->setObjectName(QString::fromUtf8("RvizzButton"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(RvizzButton->sizePolicy().hasHeightForWidth());
        RvizzButton->setSizePolicy(sizePolicy2);
        RvizzButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font-family: \"Times New Roman\";\n"
"    font-size: 18px;  /* Fuente m\303\241s grande (18px) */\n"
"    font-weight: bold;\n"
"    border: 2px solid #ccc;  /* Borde gris claro */\n"
"    border-radius: 5px;  /* Bordes ligeramente redondeados */\n"
"    padding: 10px 20px;  /* Relleno alrededor del texto */\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 white, stop:1 #f0f0f0);  /* Degradado de blanco a gris claro */\n"
"    color: black;  /* Texto negro */\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"    border-color: green;  /* Borde verde cuando est\303\251 marcado */\n"
"    background-color: lightgreen;  /* Fondo verde claro cuando est\303\251 marcado */\n"
"}\n"
""));
        RvizzButton->setCheckable(true);

        verticalLayout->addWidget(RvizzButton);

        graphButton = new QPushButton(tab_IndeximMenu);
        graphButton->setObjectName(QString::fromUtf8("graphButton"));
        sizePolicy2.setHeightForWidth(graphButton->sizePolicy().hasHeightForWidth());
        graphButton->setSizePolicy(sizePolicy2);
        graphButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font-family: \"Times New Roman\";\n"
"    font-size: 18px;  /* Fuente m\303\241s grande (18px) */\n"
"    font-weight: bold;\n"
"    border: 2px solid #ccc;  /* Borde gris claro */\n"
"    border-radius: 5px;  /* Bordes ligeramente redondeados */\n"
"    padding: 10px 20px;  /* Relleno alrededor del texto */\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 white, stop:1 #f0f0f0);  /* Degradado de blanco a gris claro */\n"
"    color: black;  /* Texto negro */\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"    border-color: green;  /* Borde verde cuando est\303\251 marcado */\n"
"    background-color: lightgreen;  /* Fondo verde claro cuando est\303\251 marcado */\n"
"}\n"
""));
        graphButton->setCheckable(true);

        verticalLayout->addWidget(graphButton);

        rqtButton = new QPushButton(tab_IndeximMenu);
        rqtButton->setObjectName(QString::fromUtf8("rqtButton"));
        sizePolicy2.setHeightForWidth(rqtButton->sizePolicy().hasHeightForWidth());
        rqtButton->setSizePolicy(sizePolicy2);
        rqtButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font-family: \"Times New Roman\";\n"
"    font-size: 18px;  /* Fuente m\303\241s grande (18px) */\n"
"    font-weight: bold;\n"
"    border: 2px solid #ccc;  /* Borde gris claro */\n"
"    border-radius: 5px;  /* Bordes ligeramente redondeados */\n"
"    padding: 10px 20px;  /* Relleno alrededor del texto */\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 white, stop:1 #f0f0f0);  /* Degradado de blanco a gris claro */\n"
"    color: black;  /* Texto negro */\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"    border-color: green;  /* Borde verde cuando est\303\251 marcado */\n"
"    background-color: lightgreen;  /* Fondo verde claro cuando est\303\251 marcado */\n"
"}\n"
""));
        rqtButton->setCheckable(true);

        verticalLayout->addWidget(rqtButton);

        viewFramesButton = new QPushButton(tab_IndeximMenu);
        viewFramesButton->setObjectName(QString::fromUtf8("viewFramesButton"));
        sizePolicy2.setHeightForWidth(viewFramesButton->sizePolicy().hasHeightForWidth());
        viewFramesButton->setSizePolicy(sizePolicy2);
        viewFramesButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font-family: \"Times New Roman\";\n"
"    font-size: 18px;  /* Fuente m\303\241s grande (18px) */\n"
"    font-weight: bold;\n"
"    border: 2px solid #ccc;  /* Borde gris claro */\n"
"    border-radius: 5px;  /* Bordes ligeramente redondeados */\n"
"    padding: 10px 20px;  /* Relleno alrededor del texto */\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 white, stop:1 #f0f0f0);  /* Degradado de blanco a gris claro */\n"
"    color: black;  /* Texto negro */\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"    border-color: green;  /* Borde verde cuando est\303\251 marcado */\n"
"    background-color: lightgreen;  /* Fondo verde claro cuando est\303\251 marcado */\n"
"}\n"
""));

        verticalLayout->addWidget(viewFramesButton);

        TeleopButton = new QPushButton(tab_IndeximMenu);
        TeleopButton->setObjectName(QString::fromUtf8("TeleopButton"));
        sizePolicy2.setHeightForWidth(TeleopButton->sizePolicy().hasHeightForWidth());
        TeleopButton->setSizePolicy(sizePolicy2);
        TeleopButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font-family: \"Times New Roman\";\n"
"    font-size: 18px;  /* Fuente m\303\241s grande (18px) */\n"
"    font-weight: bold;\n"
"    border: 2px solid #ccc;  /* Borde gris claro */\n"
"    border-radius: 5px;  /* Bordes ligeramente redondeados */\n"
"    padding: 10px 20px;  /* Relleno alrededor del texto */\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 white, stop:1 #f0f0f0);  /* Degradado de blanco a gris claro */\n"
"    color: black;  /* Texto negro */\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"    border-color: green;  /* Borde verde cuando est\303\251 marcado */\n"
"    background-color: lightgreen;  /* Fondo verde claro cuando est\303\251 marcado */\n"
"}\n"
""));
        TeleopButton->setCheckable(true);

        verticalLayout->addWidget(TeleopButton);

        nodeListButton = new QPushButton(tab_IndeximMenu);
        nodeListButton->setObjectName(QString::fromUtf8("nodeListButton"));
        sizePolicy2.setHeightForWidth(nodeListButton->sizePolicy().hasHeightForWidth());
        nodeListButton->setSizePolicy(sizePolicy2);
        nodeListButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font-family: \"Times New Roman\";\n"
"    font-size: 18px;  /* Fuente m\303\241s grande (18px) */\n"
"    font-weight: bold;\n"
"    border: 2px solid #ccc;  /* Borde gris claro */\n"
"    border-radius: 5px;  /* Bordes ligeramente redondeados */\n"
"    padding: 10px 20px;  /* Relleno alrededor del texto */\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 white, stop:1 #f0f0f0);  /* Degradado de blanco a gris claro */\n"
"    color: black;  /* Texto negro */\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"    border-color: green;  /* Borde verde cuando est\303\251 marcado */\n"
"    background-color: lightgreen;  /* Fondo verde claro cuando est\303\251 marcado */\n"
"}\n"
""));
        nodeListButton->setCheckable(false);

        verticalLayout->addWidget(nodeListButton);


        verticalLayout_3->addLayout(verticalLayout);


        verticalLayout_2->addLayout(verticalLayout_3);

        line_3 = new QFrame(tab_IndeximMenu);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_3);

        label_2 = new QLabel(tab_IndeximMenu);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy3);

        verticalLayout_2->addWidget(label_2);

        mapLabel = new QLabel(tab_IndeximMenu);
        mapLabel->setObjectName(QString::fromUtf8("mapLabel"));
        sizePolicy3.setHeightForWidth(mapLabel->sizePolicy().hasHeightForWidth());
        mapLabel->setSizePolicy(sizePolicy3);

        verticalLayout_2->addWidget(mapLabel);

        selectMapButton = new QPushButton(tab_IndeximMenu);
        selectMapButton->setObjectName(QString::fromUtf8("selectMapButton"));
        selectMapButton->setMaximumSize(QSize(550, 16777215));
        selectMapButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font-family: \"Times New Roman\";\n"
"    font-size: 18px;  /* Fuente m\303\241s grande (18px) */\n"
"    font-weight: bold;\n"
"    border: 2px solid #ccc;  /* Borde gris claro */\n"
"    border-radius: 5px;  /* Bordes ligeramente redondeados */\n"
"    padding: 10px 20px;  /* Relleno alrededor del texto */\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 white, stop:1 #f0f0f0);  /* Degradado de blanco a gris claro */\n"
"    color: black;  /* Texto negro */\n"
"}"));

        verticalLayout_2->addWidget(selectMapButton);


        horizontalLayout_3->addLayout(verticalLayout_2);

        line = new QFrame(tab_IndeximMenu);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout_3->addWidget(line);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        GazeboButton = new QPushButton(tab_IndeximMenu);
        GazeboButton->setObjectName(QString::fromUtf8("GazeboButton"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(GazeboButton->sizePolicy().hasHeightForWidth());
        GazeboButton->setSizePolicy(sizePolicy4);
        GazeboButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font-family: \"Times New Roman\";\n"
"    font-size: 18px;  /* Fuente m\303\241s grande (18px) */\n"
"    font-weight: bold;\n"
"    border: 2px solid #ccc;  /* Borde gris claro */\n"
"    border-radius: 5px;  /* Bordes ligeramente redondeados */\n"
"    padding: 10px 20px;  /* Relleno alrededor del texto */\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 white, stop:1 #f0f0f0);  /* Degradado de blanco a gris claro */\n"
"    color: black;  /* Texto negro */\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"    border-color: green;  /* Borde verde cuando est\303\251 marcado */\n"
"    background-color: lightgreen;  /* Fondo verde claro cuando est\303\251 marcado */\n"
"}\n"
""));
        GazeboButton->setCheckable(true);

        verticalLayout_7->addWidget(GazeboButton);

        SlamButton = new QPushButton(tab_IndeximMenu);
        SlamButton->setObjectName(QString::fromUtf8("SlamButton"));
        sizePolicy4.setHeightForWidth(SlamButton->sizePolicy().hasHeightForWidth());
        SlamButton->setSizePolicy(sizePolicy4);
        SlamButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font-family: \"Times New Roman\";\n"
"    font-size: 18px;  /* Fuente m\303\241s grande (18px) */\n"
"    font-weight: bold;\n"
"    border: 2px solid #ccc;  /* Borde gris claro */\n"
"    border-radius: 5px;  /* Bordes ligeramente redondeados */\n"
"    padding: 10px 20px;  /* Relleno alrededor del texto */\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 white, stop:1 #f0f0f0);  /* Degradado de blanco a gris claro */\n"
"    color: black;  /* Texto negro */\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"    border-color: green;  /* Borde verde cuando est\303\251 marcado */\n"
"    background-color: lightgreen;  /* Fondo verde claro cuando est\303\251 marcado */\n"
"}\n"
""));
        SlamButton->setCheckable(true);

        verticalLayout_7->addWidget(SlamButton);

        navigationButton = new QPushButton(tab_IndeximMenu);
        navigationButton->setObjectName(QString::fromUtf8("navigationButton"));
        sizePolicy4.setHeightForWidth(navigationButton->sizePolicy().hasHeightForWidth());
        navigationButton->setSizePolicy(sizePolicy4);
        navigationButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font-family: \"Times New Roman\";\n"
"    font-size: 18px;  /* Fuente m\303\241s grande (18px) */\n"
"    font-weight: bold;\n"
"    border: 2px solid #ccc;  /* Borde gris claro */\n"
"    border-radius: 5px;  /* Bordes ligeramente redondeados */\n"
"    padding: 10px 20px;  /* Relleno alrededor del texto */\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 white, stop:1 #f0f0f0);  /* Degradado de blanco a gris claro */\n"
"    color: black;  /* Texto negro */\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"    border-color: green;  /* Borde verde cuando est\303\251 marcado */\n"
"    background-color: lightgreen;  /* Fondo verde claro cuando est\303\251 marcado */\n"
"}\n"
""));
        navigationButton->setCheckable(true);

        verticalLayout_7->addWidget(navigationButton);


        horizontalLayout_3->addLayout(verticalLayout_7);


        gridLayout_2->addLayout(horizontalLayout_3, 0, 0, 1, 1);

        tabsimulationWidget->addTab(tab_IndeximMenu, QString());

        gridLayout->addWidget(tabsimulationWidget, 1, 0, 1, 1);

        SimulationWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SimulationWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 982, 22));
        SimulationWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(SimulationWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        SimulationWindow->setStatusBar(statusbar);

        retranslateUi(SimulationWindow);

        tabsimulationWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(SimulationWindow);
    } // setupUi

    void retranslateUi(QMainWindow *SimulationWindow)
    {
        SimulationWindow->setWindowTitle(QCoreApplication::translate("SimulationWindow", "Simulation Menu", nullptr));
        mainMenuButton->setText(QCoreApplication::translate("SimulationWindow", "Main Menu", nullptr));
        label->setText(QCoreApplication::translate("SimulationWindow", "Debug Tools:", nullptr));
        RvizzButton->setText(QCoreApplication::translate("SimulationWindow", "Run Rviz2", nullptr));
        graphButton->setText(QCoreApplication::translate("SimulationWindow", "Run rqt_graph", nullptr));
        rqtButton->setText(QCoreApplication::translate("SimulationWindow", "Run rqt", nullptr));
        viewFramesButton->setText(QCoreApplication::translate("SimulationWindow", "Print transform tree", nullptr));
        TeleopButton->setText(QCoreApplication::translate("SimulationWindow", "Run Teleop_Twist", nullptr));
        nodeListButton->setText(QCoreApplication::translate("SimulationWindow", "ROS2 node list", nullptr));
        label_2->setText(QCoreApplication::translate("SimulationWindow", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600;\">Selected map for navigation:</span></p></body></html>", nullptr));
        mapLabel->setText(QCoreApplication::translate("SimulationWindow", "<html><head/><body><p><span style=\" font-size:10pt;\">No map selected</span></p></body></html>", nullptr));
        selectMapButton->setText(QCoreApplication::translate("SimulationWindow", "Select map", nullptr));
        GazeboButton->setText(QCoreApplication::translate("SimulationWindow", "Run Gazebo", nullptr));
        SlamButton->setText(QCoreApplication::translate("SimulationWindow", "Run SLAM", nullptr));
        navigationButton->setText(QCoreApplication::translate("SimulationWindow", "Run Navigation", nullptr));
        tabsimulationWidget->setTabText(tabsimulationWidget->indexOf(tab_IndeximMenu), QCoreApplication::translate("SimulationWindow", "Simulation menu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SimulationWindow: public Ui_SimulationWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIMULATIONWINDOW_H
