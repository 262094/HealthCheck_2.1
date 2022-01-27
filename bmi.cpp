#include "bmi.h"
#include "ui_bmi.h"
#include "liczeniebmi.h"
#include <QMessageBox>


Bmi::Bmi(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Bmi)
{
    ui->setupUi(this);
}

Bmi::~Bmi()
{
    delete ui;
}

void Bmi::on_pushButton_back_to_menu_clicked()
{
    emit HomeClicked();
}

void Bmi::on_pushButton_calculate_bmi_clicked()
{
    QString gender = ui ->comboBox->currentText();
    float height = ui->lineEdit->text().toFloat();
    float weight = ui->lineEdit_2->text().toFloat();


   liczeniebmi(gender, height, weight, id);
}

void Bmi::index(int index)
{
    id = index;
    qDebug() << id;
}
