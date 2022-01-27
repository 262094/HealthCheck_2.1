#ifndef LICZENIEWHR_H
#define LICZENIEWHR_H
#include <QMainWindow>
#include <healtcheck.h>
#include <QWidget>


class liczeniewhr
{
public:
    liczeniewhr(QString gender, float wr, float hr, int index);

private:
 Whr *licz2;
 QSqlDatabase mydb;

};

#endif // LICZENIEWHR_H
