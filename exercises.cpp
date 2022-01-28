#include "exercises.h"
#include "healtcheck.h"
#include "ui_exercises.h"
#include<QUrl>
#include<QDesktopServices>
#include <QWebEngineView>
#include <QApplication>



void Exercises::downloadFile(QNetworkReply *zwrot)
{

    QPixmap pix;
    pix.loadFromData(zwrot->readAll());
    ui->label_2->setPixmap(pix.scaled(421,531));

}

Exercises::Exercises(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Exercises)
{
    ui->setupUi(this);

}

Exercises::~Exercises()
{
    delete ui;
}

void Exercises::on_pushButton_back_to_menu_clicked()
{
    emit HomeClicked();
}


void Exercises::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    QNetworkAccessManager *legs = new QNetworkAccessManager(this);
    connect(legs, &QNetworkAccessManager::finished, this,  &Exercises::downloadFile);
    legs ->get(QNetworkRequest(QUrl(myUrl)));

}


void Exercises::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    QNetworkAccessManager *abs = new QNetworkAccessManager(this);
    connect(abs, &QNetworkAccessManager::finished, this,  &Exercises::downloadFile);
     abs ->get(QNetworkRequest(QUrl(myUrl2)));

}


void Exercises::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    QNetworkAccessManager *pull = new QNetworkAccessManager(this);
    connect(pull, &QNetworkAccessManager::finished, this,  &Exercises::downloadFile);
    pull ->get(QNetworkRequest(QUrl(myUrl3)));

}


void Exercises::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    QNetworkAccessManager *full_body = new QNetworkAccessManager(this);
    connect(full_body, &QNetworkAccessManager::finished, this,  &Exercises::downloadFile);
     full_body ->get(QNetworkRequest(QUrl(myUrl4)));

}


void Exercises::on_pushButton_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    QNetworkAccessManager *fat_burning = new QNetworkAccessManager(this);
    connect(fat_burning, &QNetworkAccessManager::finished, this,  &Exercises::downloadFile);
     fat_burning ->get(QNetworkRequest(QUrl(myUrl5)));

}


void Exercises::on_pushButton_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    QNetworkAccessManager *stronger_arm = new QNetworkAccessManager(this);
    connect(stronger_arm, &QNetworkAccessManager::finished, this,  &Exercises::downloadFile);
     stronger_arm ->get(QNetworkRequest(QUrl(myUrl6)));

}


void Exercises::on_pushButton_back_to_menu_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui -> label_2 -> clear();

}

