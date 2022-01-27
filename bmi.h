#ifndef BMI_H
#define BMI_H

#include <QWidget>

namespace Ui {
class Bmi;
}

class Bmi : public QWidget
{
    Q_OBJECT

public:
    explicit Bmi(QWidget *parent = nullptr);
    ~Bmi();

    void index(int);

private:
    Ui::Bmi *ui;
    int id;


signals:
    void HomeClicked();

private slots:
    void on_pushButton_back_to_menu_clicked();
    void on_pushButton_calculate_bmi_clicked();


};

#endif // BMI_H
