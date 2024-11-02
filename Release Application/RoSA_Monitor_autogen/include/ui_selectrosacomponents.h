/********************************************************************************
** Form generated from reading UI file 'selectrosacomponents.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTROSACOMPONENTS_H
#define UI_SELECTROSACOMPONENTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SelectRosaComponents
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_8;
    QCheckBox *launchAllCheckbox;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QCheckBox *firmwareCheckbox;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_2;
    QCheckBox *urdfCheckbox;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_3;
    QCheckBox *lidarCheckbox;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_4;
    QCheckBox *cameraCheckbox;
    QPushButton *okButton;

    void setupUi(QDialog *SelectRosaComponents)
    {
        if (SelectRosaComponents->objectName().isEmpty())
            SelectRosaComponents->setObjectName(QString::fromUtf8("SelectRosaComponents"));
        SelectRosaComponents->resize(746, 632);
        gridLayout = new QGridLayout(SelectRosaComponents);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        launchAllCheckbox = new QCheckBox(SelectRosaComponents);
        launchAllCheckbox->setObjectName(QString::fromUtf8("launchAllCheckbox"));

        verticalLayout_8->addWidget(launchAllCheckbox);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        firmwareCheckbox = new QCheckBox(SelectRosaComponents);
        firmwareCheckbox->setObjectName(QString::fromUtf8("firmwareCheckbox"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(firmwareCheckbox->sizePolicy().hasHeightForWidth());
        firmwareCheckbox->setSizePolicy(sizePolicy);
        firmwareCheckbox->setIconSize(QSize(16, 16));
        firmwareCheckbox->setChecked(true);
        firmwareCheckbox->setTristate(false);

        horizontalLayout_2->addWidget(firmwareCheckbox);


        verticalLayout_8->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        urdfCheckbox = new QCheckBox(SelectRosaComponents);
        urdfCheckbox->setObjectName(QString::fromUtf8("urdfCheckbox"));
        sizePolicy.setHeightForWidth(urdfCheckbox->sizePolicy().hasHeightForWidth());
        urdfCheckbox->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(urdfCheckbox);


        verticalLayout_8->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);

        lidarCheckbox = new QCheckBox(SelectRosaComponents);
        lidarCheckbox->setObjectName(QString::fromUtf8("lidarCheckbox"));
        sizePolicy.setHeightForWidth(lidarCheckbox->sizePolicy().hasHeightForWidth());
        lidarCheckbox->setSizePolicy(sizePolicy);

        horizontalLayout_5->addWidget(lidarCheckbox);


        verticalLayout_8->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_4);

        cameraCheckbox = new QCheckBox(SelectRosaComponents);
        cameraCheckbox->setObjectName(QString::fromUtf8("cameraCheckbox"));
        sizePolicy.setHeightForWidth(cameraCheckbox->sizePolicy().hasHeightForWidth());
        cameraCheckbox->setSizePolicy(sizePolicy);

        horizontalLayout_6->addWidget(cameraCheckbox);


        verticalLayout_8->addLayout(horizontalLayout_6);


        verticalLayout_6->addLayout(verticalLayout_8);

        okButton = new QPushButton(SelectRosaComponents);
        okButton->setObjectName(QString::fromUtf8("okButton"));

        verticalLayout_6->addWidget(okButton);


        gridLayout->addLayout(verticalLayout_6, 0, 0, 1, 1);


        retranslateUi(SelectRosaComponents);

        QMetaObject::connectSlotsByName(SelectRosaComponents);
    } // setupUi

    void retranslateUi(QDialog *SelectRosaComponents)
    {
        SelectRosaComponents->setWindowTitle(QCoreApplication::translate("SelectRosaComponents", "Select Components", nullptr));
        launchAllCheckbox->setText(QCoreApplication::translate("SelectRosaComponents", "Launch all", nullptr));
        firmwareCheckbox->setText(QCoreApplication::translate("SelectRosaComponents", "Launch Odom from Firmware ", nullptr));
        urdfCheckbox->setText(QCoreApplication::translate("SelectRosaComponents", "Launch URDF", nullptr));
        lidarCheckbox->setText(QCoreApplication::translate("SelectRosaComponents", "Launch LiDAR", nullptr));
        cameraCheckbox->setText(QCoreApplication::translate("SelectRosaComponents", "Launch Camera", nullptr));
        okButton->setText(QCoreApplication::translate("SelectRosaComponents", "Launch selected", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SelectRosaComponents: public Ui_SelectRosaComponents {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTROSACOMPONENTS_H
