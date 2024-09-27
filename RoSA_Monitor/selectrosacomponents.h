#ifndef SELECTROSACOMPONENTS_H
#define SELECTROSACOMPONENTS_H

#include <QDialog>
#include <QCheckBox>

/*************************************************
 *     DIALOG TO SELECT COMPONENTS TO LAUNCH     *
 * **********************************************/

namespace Ui {
class SelectRosaComponents;
}

class SelectRosaComponents : public QDialog
{
    Q_OBJECT

public:
    explicit SelectRosaComponents(QWidget *parent = nullptr);
    ~SelectRosaComponents();

    QList<QCheckBox*> getSelectedComponents();

private slots:
    void on_okButton_clicked();

    //Called when select all checkbox is clicked
    void on_launchAllCheckbox_stateChanged(int arg1);

private:
    Ui::SelectRosaComponents *ui;

    QList<QCheckBox*> checkBoxes;
};

#endif // SELECTROSACOMPONENTS_H
