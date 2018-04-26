#pragma once

#include <QDialog>
#include <QSettings>
#include <qtimer.h>
#include "ui_textsettings.h"

class TextSettings : public QDialog
{
	Q_OBJECT

public:
	TextSettings(QSettings *settings, QWidget *parent = Q_NULLPTR);
	~TextSettings();

	

private:
	Ui::TextSettings ui;
	QTimer *upPressedTimer;
	QTimer *upContinuityTimer;
	QTimer *downPressedTimer;
	QTimer *downContinuityTimer;
	QTimer *leftPressedTimer;
	QTimer *leftContinuityTimer;
	QTimer *rightPressedTimer;
	QTimer *rightContinuityTimer;

signals:
	void SetFont(QString fontType);
	void SetRed(int red);
	void SetGreen(int green);
	void SetBlue(int blue);
	void SetSize(int size);
	void DoUp();
	void DoDown();
	void DoLeft();
	void DoRight();
	void DoRest();
	void ApplySettings();
	void CancelSettings();

public slots:
	void FontChange();
	void RedChange(int red);
	void GreenChange(int green);
	void BlueChange(int blue);
	void SizeChange(int size);
	void UpPressed();
	void UpRelease();
	void UpContinuity();
	void DownPressed();
	void DownRelease();
	void DownContinuity();
	void LeftPressed();
	void LeftRelease();
	void LeftContinuity();
	void RightPressed();
	void RightRelease();
	void RightContinuity();
	void RestBtnClicked();
	void OkBtnClicked();
	void CancelBtnClicked();
	
};
