#include "healtcheck.h"
#include "ui_healtcheck.h"

#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QFontDialog>
#include <QDialog>
#include <QFont>
#include <QColorDialog>
#include <QColor>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

HealtCheck::HealtCheck(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::HealtCheck)
{
     ui->setupUi(this);
     ui -> menuBar ->setVisible(false);


    mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("C:/Users/Łukasz/Desktop/mydb.db");

    if(!mydb.open())
    {
        qDebug()<<"Failed to open the database" << mydb.lastError().text();
    }




     ui -> stackedWidget-> insertWidget(1, &whr);
    ui -> stackedWidget-> insertWidget(2, &bmi);
     ui -> stackedWidget-> insertWidget(3, &diet);
     ui -> stackedWidget-> insertWidget(5, &kcal);
     ui -> stackedWidget-> insertWidget(6, &exercises);


     connect(&whr, SIGNAL(HomeClicked()), this, SLOT(moveHome()));

        connect(&bmi, SIGNAL(HomeClicked()), this, SLOT(moveHome()));

            connect(&diet, SIGNAL(HomeClicked()), this, SLOT(moveHome()));

              connect(&kcal, SIGNAL(HomeClicked()), this, SLOT(moveHome()));

                     connect(&exercises, SIGNAL(HomeClicked()), this, SLOT(moveHome()));



}

 //user code


HealtCheck::~HealtCheck()
{
    mydb.close();
    delete ui;
}


void HealtCheck::on_pushButton_whr_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    whr.index(index);
}

void HealtCheck::on_pushButton_bmi_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    bmi.index(index);

}

void HealtCheck::on_pushButton_diets_clicked()
{
     ui->stackedWidget->setCurrentIndex(3);

}


void HealtCheck::moveHome()
{
      ui->stackedWidget->setCurrentIndex(7);

}


void HealtCheck::on_pushButton_athlets_clicked()
{
     ui->stackedWidget->setCurrentIndex(8);

}


void HealtCheck::on_pushButton_back_to_menu_clicked()
{
     ui->stackedWidget->setCurrentIndex(7);

}




void HealtCheck::on_actionNew_triggered()
{

    ui->stackedWidget->setCurrentIndex(8); //przenoszenie na index z athlets dietary
    QSqlQuery qry;
    qry.prepare("select * from users where id=:id");
    qry.bindValue(":id", index);

    qry.exec();
    qDebug() << qry.lastError();


    while(qry.next())
    {
    float bmi, whr, kcal;
    bmi=round(qry.value(5).toFloat());
    whr=qry.value(4).toFloat();
    kcal=round(qry.value(3).toFloat());
    qDebug() << bmi << whr << kcal;

    QString bmi1, whr1, kcal1;
    bmi1.setNum(bmi);
    whr1.setNum(whr);
    kcal1.setNum(kcal);




    file_path_ = "";
     ui->textEdit->setText("Podaj swoją wagę:  \n"
                           "Podaj swój wzrost: \n"
                           "Podaj swój wiek: \n"
                           "Podaj dietę którą stosujesz: \n"
                           "Twoje bmi: "+bmi1+"\n"
                           "Twoj wskaznik whr: "+whr1+"\n"
                           "Twoje dzienne zapotrzebowanie kcal: "+kcal1+"\n"
                           "Twoje uwagi: \n"
                           );

    }




}


void HealtCheck::on_actionOpen_triggered()
{
   QString file_open = QFileDialog::getOpenFileName(this,"Open the file");
     QFile file(file_open);
     file_path_ = file_open;
     if(!file.open(QFile::ReadOnly | QFile::Text)) {
         QMessageBox::warning(this,"Open","The file has not been opened");
         return;
       }
     QTextStream in(&file);
     QString text = in.readAll();
     ui->textEdit->setText(text);
     file.close();
      ui->stackedWidget->setCurrentIndex(8);
      //przenoszenie na index z athlets dietary
}


void HealtCheck::on_actionSave_triggered()
{
    QFile file(file_path_);
      if(!file.open(QFile::WriteOnly | QFile::Text)) {
          QMessageBox::warning(this,"Save","The file has not been saved, select the save as option");
          return;
        }
      QTextStream out(&file);
      QString text = ui->textEdit->toPlainText();
      out << text;
      file.flush();
      file.close();
}


void HealtCheck::on_actionSave_as_triggered()
{
   QString file_open = QFileDialog::getSaveFileName(this,"Save file as");
     QFile file(file_open + ".txt");
     file_path_ = file_open;
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
         QMessageBox::warning(this,"Save as","The file has not been saved");
         return;

       }
     QTextStream out(&file);
     QString text = ui->textEdit->toPlainText();
     out << text;
     file.flush();
     file.close();

}


void HealtCheck::on_actionCut_triggered()
{
     ui->textEdit->cut();
}


void HealtCheck::on_actionCopy_triggered()
{
     ui->textEdit->copy();
}


void HealtCheck::on_actionPaste_triggered()
{
     ui->textEdit->paste();
}


void HealtCheck::on_actionUndo_triggered()
{
     ui->textEdit->undo();
}


void HealtCheck::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}


void HealtCheck::on_pushButton_kcal_clicked()
{
     ui->stackedWidget->setCurrentIndex(5);
     kcal.index(index);
}


void HealtCheck::on_pushButton_exercises_clicked()
{
    ui ->stackedWidget -> setCurrentIndex(6);
}


void HealtCheck::on_pushButton_login_clicked()
{

    QString username, password;
    username=ui->lineEdit_username->text();
    password=ui->lineEdit_password->text();

    QSqlQuery qry;
    qry.prepare("select * from users where username=:username and password=:password");
    qry.bindValue(":username", username);
    qry.bindValue(":password", password);

    if(qry.exec())
    {
        while(qry.next())
        {
            count++;
            index = qry.value(0).toInt();
        }

        if(count==1)
        {
            ui->label_6 ->setText("Correct username and password");
            ui ->stackedWidget -> setCurrentIndex(7);
            ui -> menuBar ->setVisible(true);

        }
        if(count<1)
            ui-> label_6->setText("Not correct username and password");
    }



}


void HealtCheck::on_pushButton_back_to_login_clicked()
{
     ui ->stackedWidget -> setCurrentIndex(4);
}


void HealtCheck::on_pushButton_registery_clicked()
{


    bool check=true;
    QString username, password;
    username=ui->lineEdit_username_2->text();
    password=ui->lineEdit_password_2->text();

     QSqlQuery qry;

     qry.prepare("select * from users where username=:username");
     qry.bindValue(":username", username);

     qry.exec();


     while(qry.next())
     {
         QString usernamedb=qry.value(1).toString();
         if(username==usernamedb)
         {
              QMessageBox::warning(this,"Warning", "User already exists");
              check=false;
         }


     }

     if(check)
     {
         qry.prepare("insert into users (username, password)" "VALUES (:username, :password)");
                 qry.bindValue(":username", username);
                 qry.bindValue(":password", password);
                 qry.exec();
                 ui->lineEdit_username_2->clear();
                 ui->lineEdit_password_2->clear();
                 ui->stackedWidget->setCurrentIndex(4);
     }


}


void HealtCheck::on_pushButton_go_to_registery_clicked()
{
    ui ->stackedWidget -> setCurrentIndex(0);
}

