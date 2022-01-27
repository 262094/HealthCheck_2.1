#ifndef LICZENIEKCAL_H
#define LICZENIEKCAL_H
#include <QMainWindow>
#include <healtcheck.h>
#include <QWidget>
#include <QObject>

class liczeniekcal
{
public:
     liczeniekcal(QString gender, QString activity, float height, float weight, float age, int index);

private:
Kcal *licz3;
QSqlDatabase mydb;


};

#endif // LICZENIEKCAL_H
