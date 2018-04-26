#ifndef SERVICETIMELINETABLE_H
#define SERVICETIMELINETABLE_H

#include <QWidget>
#include <QDialog>
#include "ui_servicetimelinetable.h"
using namespace std;

class ServiceTimeLineTable : public QDialog
{
    Q_OBJECT

public:
    ServiceTimeLineTable(QWidget *parent = 0);
    ~ServiceTimeLineTable();

public slots:
    void Search();
    void FillinTable(QString json);
    void clear();

private:
    void SetHerader();
    Ui::ServiceTimeLineTable *ui;
};

#endif // SERVICETIMELINETABLE_H
