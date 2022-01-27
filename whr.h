#ifndef WHR_H
#define WHR_H

#include <QWidget>

namespace Ui {
class Whr;
}

class Whr : public QWidget
{
    Q_OBJECT

public:
    explicit Whr(QWidget *parent = nullptr);
    ~Whr();
void index(int);

private:
    Ui::Whr *ui;
    int id;

signals:
    void HomeClicked();



private slots:
    void on_pushButton_back_to_menu_clicked();
    void on_pushButton_calculate_clicked();
};

#endif // WHR_H
