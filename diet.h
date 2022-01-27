#ifndef DIET_H
#define DIET_H

#include <QWidget>

namespace Ui {
class Diet;
}

class Diet : public QWidget
{
    Q_OBJECT

public:
    explicit Diet(QWidget *parent = nullptr);
    ~Diet();

private:
    Ui::Diet *ui;

signals:
    void HomeClicked();

private slots:
    void on_pushButton_back_to_menu_clicked();

    void on_pushButton_open_the_diet_clicked();
};

#endif // DIET_H
