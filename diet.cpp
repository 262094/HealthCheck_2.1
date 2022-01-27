#include "diet.h"
#include "ui_diet.h"
#include <QMessageBox>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>

Diet::Diet(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Diet)
{
    ui->setupUi(this);
}

Diet::~Diet()
{
    delete ui;
}

void Diet::on_pushButton_back_to_menu_clicked()
{
    emit HomeClicked();
}

void Diet::on_pushButton_open_the_diet_clicked()
{
    QString diet = ui ->comboBox->currentText();

    if(diet == "2000 kcal diet (example)")
    {
          QFile file("dieta_2000.txt");
          if(file.open(QFile::ReadOnly | QFile::Text))
          {
              QTextStream in(&file);
              QString text = in.readAll();
              ui->textEdit->setText(text);
            }
          file.close();
    }


    if(diet == "1500 kcal diet (7 day)")
    {
          QFile file("dieta_1500.txt");
          if(file.open(QFile::ReadOnly | QFile::Text))
          {
              QTextStream in(&file);
              QString text = in.readAll();
              ui->textEdit->setText(text);
            }
          file.close();
    }

     if(diet == "Instant diet (7 day)")
    {
         QFile file("instant_diet.txt");
         if(file.open(QFile::ReadOnly | QFile::Text))
         {
             QTextStream in(&file);
             QString text = in.readAll();
             ui->textEdit->setText(text);
           }
         file.close();
    }

}

