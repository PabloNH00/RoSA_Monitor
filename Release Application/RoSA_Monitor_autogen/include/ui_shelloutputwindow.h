/********************************************************************************
** Form generated from reading UI file 'shelloutputwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHELLOUTPUTWINDOW_H
#define UI_SHELLOUTPUTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ShellOutputWindow
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QPlainTextEdit *shellTextOutput;

    void setupUi(QWidget *ShellOutputWindow)
    {
        if (ShellOutputWindow->objectName().isEmpty())
            ShellOutputWindow->setObjectName(QString::fromUtf8("ShellOutputWindow"));
        ShellOutputWindow->resize(520, 520);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ShellOutputWindow->sizePolicy().hasHeightForWidth());
        ShellOutputWindow->setSizePolicy(sizePolicy);
        ShellOutputWindow->setMinimumSize(QSize(150, 150));
        gridLayout = new QGridLayout(ShellOutputWindow);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        shellTextOutput = new QPlainTextEdit(ShellOutputWindow);
        shellTextOutput->setObjectName(QString::fromUtf8("shellTextOutput"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(shellTextOutput->sizePolicy().hasHeightForWidth());
        shellTextOutput->setSizePolicy(sizePolicy1);
        shellTextOutput->setMinimumSize(QSize(500, 500));
        shellTextOutput->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContentsOnFirstShow);
        shellTextOutput->setReadOnly(true);

        verticalLayout->addWidget(shellTextOutput);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(ShellOutputWindow);

        QMetaObject::connectSlotsByName(ShellOutputWindow);
    } // setupUi

    void retranslateUi(QWidget *ShellOutputWindow)
    {
        ShellOutputWindow->setWindowTitle(QCoreApplication::translate("ShellOutputWindow", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ShellOutputWindow: public Ui_ShellOutputWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHELLOUTPUTWINDOW_H
