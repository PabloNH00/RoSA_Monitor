/********************************************************************************
** Form generated from reading UI file 'demowindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEMOWINDOW_H
#define UI_DEMOWINDOW_H

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

class Ui_DemoWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QTabWidget *tabdemoWidget;
    QWidget *tab_IndeximMenu;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout_3;
    QPushButton *mainMenuButton;
    QFrame *line_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QPushButton *graphButton;
    QPushButton *nodeListButton;
    QFrame *line;
    QVBoxLayout *verticalLayout_7;
    QPushButton *DemoButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *DemoWindow)
    {
        if (DemoWindow->objectName().isEmpty())
            DemoWindow->setObjectName(QString::fromUtf8("DemoWindow"));
        DemoWindow->resize(800, 600);
        centralwidget = new QWidget(DemoWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tabdemoWidget = new QTabWidget(centralwidget);
        tabdemoWidget->setObjectName(QString::fromUtf8("tabdemoWidget"));
        tabdemoWidget->setEnabled(true);
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

        graphButton = new QPushButton(tab_IndeximMenu);
        graphButton->setObjectName(QString::fromUtf8("graphButton"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
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


        horizontalLayout_3->addLayout(verticalLayout_2);

        line = new QFrame(tab_IndeximMenu);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout_3->addWidget(line);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        DemoButton = new QPushButton(tab_IndeximMenu);
        DemoButton->setObjectName(QString::fromUtf8("DemoButton"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(DemoButton->sizePolicy().hasHeightForWidth());
        DemoButton->setSizePolicy(sizePolicy3);
        DemoButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        DemoButton->setCheckable(true);

        verticalLayout_7->addWidget(DemoButton);


        horizontalLayout_3->addLayout(verticalLayout_7);


        gridLayout_2->addLayout(horizontalLayout_3, 0, 0, 1, 1);

        tabdemoWidget->addTab(tab_IndeximMenu, QString());

        gridLayout->addWidget(tabdemoWidget, 0, 0, 1, 1);

        DemoWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(DemoWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        DemoWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(DemoWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        DemoWindow->setStatusBar(statusbar);

        retranslateUi(DemoWindow);

        tabdemoWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(DemoWindow);
    } // setupUi

    void retranslateUi(QMainWindow *DemoWindow)
    {
        DemoWindow->setWindowTitle(QCoreApplication::translate("DemoWindow", "Demo Speak", nullptr));
        mainMenuButton->setText(QCoreApplication::translate("DemoWindow", "Main menu", nullptr));
        label->setText(QCoreApplication::translate("DemoWindow", "Debug Tools:", nullptr));
        graphButton->setText(QCoreApplication::translate("DemoWindow", "Run rqt_graph", nullptr));
        nodeListButton->setText(QCoreApplication::translate("DemoWindow", "ROS2 node list", nullptr));
        DemoButton->setText(QCoreApplication::translate("DemoWindow", "Run Demo", nullptr));
        tabdemoWidget->setTabText(tabdemoWidget->indexOf(tab_IndeximMenu), QCoreApplication::translate("DemoWindow", "Simulation menu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DemoWindow: public Ui_DemoWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEMOWINDOW_H
