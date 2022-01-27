#include "whr.h"
#include "ui_whr.h"
#include "liczeniewhr.h"
#include <QMessageBox>

Whr::Whr(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Whr)
{
    ui->setupUi(this);
}

Whr::~Whr()
{
    delete ui;
}

void Whr::on_pushButton_back_to_menu_clicked()
{
    emit HomeClicked();
}


void Whr::on_pushButton_calculate_clicked()
{
    QString gender = ui ->comboBox->currentText();
      float wr = ui->lineEdit->text().toFloat();
      float hr = ui->lineEdit_2->text().toFloat();

      liczeniewhr (gender, wr, hr, id);

}

void Whr::index(int index)
{
    id = index;
    qDebug() << id;
}
