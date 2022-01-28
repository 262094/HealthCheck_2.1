#include "kcal.h"
#include "ui_kcal.h"
#include "liczeniekcal.h"
#include <QMessageBox>

Kcal::Kcal(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Kcal)
{
    ui->setupUi(this);
}

Kcal::~Kcal()
{
    delete ui;
}

void Kcal::on_pushButton_back_to_menu_clicked()
{
     emit HomeClicked();
     ui->lineEdit->clear();
      ui->lineEdit_2->clear();
       ui->lineEdit_3->clear();
}


void Kcal::on_pushButton_calculate_kcal_clicked()
{
     QString gender = ui ->comboBox_gender->currentText();
     QString activity = ui ->comboBox_activity->currentText();
     float height = ui->lineEdit->text().toFloat();
     float weight = ui->lineEdit_2->text().toFloat();
     float age = ui->lineEdit_3->text().toFloat();


     liczeniekcal(gender, activity, height,  weight, age, id);


}

void Kcal::index(int index)
{
    id = index;
    qDebug() << id;
}
