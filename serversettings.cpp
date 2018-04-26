#include "serversettings.h"
#include <QMessageBox>

ServerSettings::ServerSettings(QSettings *settings, QWidget *parent)
	: QDialog(parent)
{
	this->settings = settings;
	this->parent = parent;
	setWindowFlags(windowFlags()&~Qt::WindowCloseButtonHint&~Qt::WindowContextHelpButtonHint);
	ui.setupUi(this);
	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(SaveChange()));
	connect(ui.pushButton_2, SIGNAL(clicked()), this, SLOT(Cancel()));
	if (settings->contains("ServerAddress"))
	{
		ui.lineEdit->setText(settings->value("ServerAddress").toString());
	}
}

ServerSettings::~ServerSettings()
{
}

void ServerSettings::SaveChange()
{
	if (ui.lineEdit->text().isEmpty())
	{
		QMessageBox::critical(this,
			tr("Error"),
			tr("The server address is not allowed to be empty!"));
	}
	else
	{
		ApplyChange(ui.lineEdit->text());
		this->close();
	}
}

void ServerSettings::Cancel()
{
	DiscardChange();
}
