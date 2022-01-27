#ifndef HEALTCHECK_H
#define HEALTCHECK_H
#include <QMainWindow>
#include <whr.h>
#include <bmi.h>
#include <diet.h>
#include <liczeniebmi.h>
#include <kcal.h>
#include <exercises.h>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

QT_BEGIN_NAMESPACE
namespace Ui { class HealtCheck; }
QT_END_NAMESPACE

class HealtCheck : public QMainWindow
{
    Q_OBJECT

public:
    HealtCheck(QWidget *parent = nullptr);
    ~HealtCheck();

    int index;
    int id;
    int count=0;

private slots:
    void on_pushButton_whr_clicked();
    void moveHome();
    void on_pushButton_bmi_clicked();
    void on_pushButton_diets_clicked();

    void on_pushButton_athlets_clicked();

    void on_pushButton_back_to_menu_clicked();

    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionSave_as_triggered();

    void on_actionCut_triggered();

    void on_actionCopy_triggered();

    void on_actionPaste_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

    void on_pushButton_kcal_clicked();

    void on_pushButton_exercises_clicked();

    void on_pushButton_login_clicked();



    void on_pushButton_back_to_login_clicked();

    void on_pushButton_registery_clicked();

    void on_pushButton_go_to_registery_clicked();

public slots:



private:
    Ui::HealtCheck *ui;
   Whr whr;
    Bmi bmi;
    Diet diet;
    Kcal kcal;
    Exercises exercises;
    QString file_path_;
    QSqlDatabase mydb;

};
#endif // HEALTCHECK_H
