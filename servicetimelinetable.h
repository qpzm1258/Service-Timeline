#ifndef SERVICETIMELINETABLE_H
#define SERVICETIMELINETABLE_H

#include <QWidget>
#include <QDialog>
#include <QMenu>
#include <QAction>
#include "ui_servicetimelinetable.h"
#include "historyviewer.h"
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
    void DisplayPhotos();

private:
    void SetHerader();
    QMenu *menu;
    QAction *viewPhoto;
    Ui::ServiceTimeLineTable *ui;
    HistoryViewer *viewer;

protected:
    void contextMenuEvent(QContextMenuEvent *event);
};

#endif // SERVICETIMELINETABLE_H
