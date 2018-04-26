#pragma once

#include <QDialog>
#include <QSettings>
#include <QString>
#include "ui_serversettings.h"

class ServerSettings : public QDialog
{
	Q_OBJECT

public:
	ServerSettings(QSettings *settings,QWidget *parent = Q_NULLPTR);
	~ServerSettings();

	

private:
	Ui::ServerSettings ui;
	QSettings *settings;
	QWidget *parent;

public slots:
    void SaveChange();
	void Cancel();

signals:
	void ApplyChange(QString url);
	void DiscardChange();
};
