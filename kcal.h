#ifndef KCAL_H
#define KCAL_H

#include <QWidget>

namespace Ui {
class Kcal;
}

class Kcal : public QWidget
{
    Q_OBJECT

public:
    explicit Kcal(QWidget *parent = nullptr);
    ~Kcal();

     void index(int);

private slots:
    void on_pushButton_back_to_menu_clicked();

    void on_pushButton_calculate_kcal_clicked();

signals:
 void HomeClicked();

private:
    Ui::Kcal *ui;
    int id;
};

#endif // KCAL_H
