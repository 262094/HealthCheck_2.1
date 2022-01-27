#include "liczeniewhr.h"
#include <QMessageBox>


liczeniewhr::liczeniewhr(QString gender, float wr, float hr, int index)
{

    mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("C:/Users/Łukasz/Desktop/mydb.db");

    if(!mydb.open())
    {
        qDebug()<<"Failed to open the database" << mydb.lastError().text();
    }

    float whr = round((wr/hr)*100)/100;

    QSqlQuery qry;
    qry.prepare("update users set whr=:whr where id=:id");
    qry.bindValue(":id", index);
    qry.bindValue(":whr", whr);

    qry.exec();


    if(gender== "MEN")
    {
        if(whr > 1)
           //  QMessageBox::about(licz2,"WHR", QString("Your WHR is %1  You have an apple-shaped body type").arg(whr));
            QMessageBox::about(QDialog::find(0),"WHR", QString ("Your WHR is %1  You have an apple-shaped body type").arg(whr));
        if(whr < 1)
           //  QMessageBox::about(licz2,"WHR",QString("Your WHR is %1  You have an pear-shaped body type").arg(whr));
            QMessageBox::about(QDialog::find(0),"WHR", QString ("Your WHR is %1  You have an pear-shaped body type").arg(whr));
        if(whr == 1)
           // QMessageBox::about(licz2,"WHR",QString("Your WHR is %1  You have the perfect body type").arg(whr));
            QMessageBox::about(QDialog::find(0),"WHR", QString ("Your WHR is %1  You have the perfect body type").arg(whr));

    }

    if(gender== "WOMEN")
    {
        if(whr > 0.8f)
         //   QMessageBox::about(licz2,"WHR", QString("Your WHR is %1 You have an apple-shaped body type").arg(whr));
             QMessageBox::about(QDialog::find(0),"WHR", QString ("Your WHR is %1  You have an apple-shaped body type").arg(whr));
        if(whr < 0.8f)
         //  QMessageBox::about(licz2,"WHR",QString("Your WHR is %1 You have an pear-shaped body type").arg(whr));
             QMessageBox::about(QDialog::find(0),"WHR", QString ("Your WHR is %1  You have an pear-shaped body type").arg(whr));
        if(whr == 0.8f)
         //   QMessageBox::about(licz2,"WHR",QString("Your WHR is %1 You have the perfect body type").arg(whr));
             QMessageBox::about(QDialog::find(0),"WHR", QString ("Your WHR is %1  You have the perfect body type").arg(whr));
    }


}
