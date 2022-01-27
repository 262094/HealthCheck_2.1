#ifndef LICZENIEBMI_H
#define LICZENIEBMI_H
#include <QMainWindow>
#include <healtcheck.h>
#include <QWidget>
#include <QObject>
#include <QSqlDatabase>
#include <QSqlError>

class liczeniebmi {

public:
 liczeniebmi( QString gender, float height, float weight, int index);

private:

 Bmi *licz;
 QSqlDatabase mydb;


};

#endif // LICZENIEBMI_H

