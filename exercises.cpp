#include "exercises.h"
#include "healtcheck.h"
#include "ui_exercises.h"
#include<QUrl>
#include<QDesktopServices>
#include <QWebEngineView>
#include <QApplication>



void Exercises::downloadFile(QNetworkReply *reply)
{

    QPixmap pix;
    pix.loadFromData(reply->readAll());
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
    const QUrl url = QUrl(myUrl);
    QNetworkRequest request(url);
    legs ->get(request);


}


void Exercises::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    QNetworkAccessManager *abs = new QNetworkAccessManager(this);
    connect(abs, &QNetworkAccessManager::finished, this,  &Exercises::downloadFile);
    const QUrl url = QUrl(myUrl2);
    QNetworkRequest request(url);
    abs ->get(request);


}


void Exercises::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    QNetworkAccessManager *pull = new QNetworkAccessManager(this);
    connect(pull, &QNetworkAccessManager::finished, this,  &Exercises::downloadFile);
    const QUrl url = QUrl(myUrl3);
    QNetworkRequest request(url);
    pull ->get(request);

}


void Exercises::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    QNetworkAccessManager *full_body = new QNetworkAccessManager(this);
    connect(full_body, &QNetworkAccessManager::finished, this,  &Exercises::downloadFile);
    const QUrl url = QUrl(myUrl4);
    QNetworkRequest request(url);
    full_body ->get(request);

}


void Exercises::on_pushButton_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    QNetworkAccessManager *fat_burning = new QNetworkAccessManager(this);
    connect(fat_burning, &QNetworkAccessManager::finished, this,  &Exercises::downloadFile);
    const QUrl url = QUrl(myUrl6);
    QNetworkRequest request(url);
    fat_burning ->get(request);
}


void Exercises::on_pushButton_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    QNetworkAccessManager *stronger_arm = new QNetworkAccessManager(this);
    connect(stronger_arm, &QNetworkAccessManager::finished, this,  &Exercises::downloadFile);
    const QUrl url = QUrl(myUrl6);
    QNetworkRequest request(url);
    stronger_arm ->get(request);

}


void Exercises::on_pushButton_back_to_menu_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui -> label_2 -> clear();

}

