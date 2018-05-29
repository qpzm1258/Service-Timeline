#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_TakePhotos.h"
#include "opencv2/opencv.hpp"
#include "textsettings.h"
#include "serversettings.h"
#include "checkstatus.h"
#include "QSettings"
#include "submitdata.h"
#include "idcardmessage.h"
#include "serversettings.h"
#include "servicetimelinetable.h"

class TakePhotos : public QMainWindow
{
	Q_OBJECT

public:
	TakePhotos(QWidget *parent = Q_NULLPTR);

private:
	Ui::TakePhotosClass ui;
	void InitCamera();
	QImage Mat2QImage(cv::Mat cvImg);
	QTimer *timer;
	cv::VideoCapture cameraCapture;
	QActionGroup *cameraGroup;
	QAction *camera_1;
	QAction *camera_2;
	QAction *camera_3;
	QAction *camera_4;
	QAction *camera_5;
	int workType;
	void PutTextToImg(cv::Mat &img);
	double fontSize;
	double r, g, b, a;
	double x, y;
	TextSettings *tSetttings;
	ServerSettings *sSetting;

	std::string fontType;
	QSettings *settings;
	void InitSettings();
	void LoadSettings();
	int cameraIdx;
	std::string url;
	QLabel *serverStatusLabel;
	QLabel *cameraStatusLabel;
	CheckStatus *checker;
	QThread* threadForServerChecker;
	QTimer *serverCheckerTimer;
    QPixmap *idImage;
    QPixmap *agentIdImage;

	SubmitData *submitData;
    IdCardMessage transactor;
    IdCardMessage agent;
    ServiceTimeLineTable *historyTable;

	bool SaveTmpFile();
    void isExpired(QString expdate);
public slots:
	void GetInfo();
	void CleanInfo();
	void GetAgentInfo();
	void CleanAgentInfo();
	void NextFrame();
	void SwitchCamera();
	void SwitchType();
	void ShowFontSettings();
	void ShowServerSettings();
	void SetFont(QString _fontType);
	void SetRed(int red);
	void SetGreen(int green);
	void SetBlue(int blue);
	void SetSize(int size);
	void TextUp();
	void TextDown();
	void TextLeft();
	void TextRight();
	void TextRest();
	void SaveSettings();
	void CancelSettings();
	void CleanAll();
	void TakeOrCleanPhoto();
	void SaveServerSetting(QString url);
	void DiscardServerSetting();
	void ChangeServerStatus(bool status);
	void Submit();
    void OpenHistoryDig();
};
