#include "selectrosacomponents.h"
#include "ui_selectrosacomponents.h"

SelectRosaComponents::SelectRosaComponents(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SelectRosaComponents)
{
    ui->setupUi(this);
}

SelectRosaComponents::~SelectRosaComponents()
{
    delete ui;
}

void SelectRosaComponents::on_okButton_clicked()
{
    //Close dialog
    accept();
}

QList<QCheckBox*>  SelectRosaComponents::getSelectedComponents()
{
    checkBoxes.append(ui->launchAllCheckbox);
    checkBoxes.append(ui->firmwareCheckbox);
    checkBoxes.append(ui->urdfCheckbox);
    checkBoxes.append(ui->lidarCheckbox);
    checkBoxes.append(ui->cameraCheckbox);
    return checkBoxes;
}

void SelectRosaComponents::on_launchAllCheckbox_stateChanged(int arg1)
{
    if(arg1)
    {
        ui->firmwareCheckbox->setChecked(true);
        ui->urdfCheckbox->setChecked(true);
        ui->lidarCheckbox->setChecked(true);
        ui->cameraCheckbox->setChecked(true);
    }
    if(!arg1)
    {
        ui->firmwareCheckbox->setChecked(false);
        ui->urdfCheckbox->setChecked(false);
        ui->lidarCheckbox->setChecked(false);
        ui->cameraCheckbox->setChecked(false);
    }
}
