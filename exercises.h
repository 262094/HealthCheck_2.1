#ifndef EXERCISES_H
#define EXERCISES_H

#include <QWidget>
#include <QNetworkAccessManager> //make requsts
#include <QNetworkReply> //handle replies
#include <QPixmap> //work with images




namespace Ui {
class Exercises;
}

class Exercises : public QWidget
{
    Q_OBJECT

public:
    explicit Exercises(QWidget *parent = nullptr);
    ~Exercises();

signals:
    void HomeClicked();

private slots:
    void on_pushButton_back_to_menu_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void downloadFile(QNetworkReply*);

    void on_pushButton_back_to_menu_2_clicked();

private:
    Ui::Exercises *ui;
  //  QUrl commandLineUrlArgument();
    QString myUrl = "https://cdn2.coachmag.co.uk/sites/coachmag/files/styles/insert_main_wide_image/public/2019/03/sundried-legs-workout.jpg?itok=m3gtXnUf";
    QString myUrl2 = "https://darebee.com/images/workouts/express-abs-workout.jpg";
    QString myUrl3 = "https://i.pinimg.com/originals/eb/bd/cc/ebbdcc88e7d8c6ea4a29176c73e3e9e4.jpg";
    QString myUrl4 = "https://i.pinimg.com/originals/1f/dd/cf/1fddcff15e2eaafb2849814651598443.jpg";
    QString myUrl5 = "https://i.pinimg.com/originals/6b/bd/20/6bbd202676eadb9bba908883d619a985.jpg";
    QString myUrl6 = "https://i.pinimg.com/originals/7d/bb/2e/7dbb2e02d9b653dcb57576ad364a210f.png";


};

#endif // EXERCISES_H
