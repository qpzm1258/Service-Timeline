#include "TakePhotos.h"
#include "idcardreader.h"
#include "qmessagebox.h"
#include "qtimer.h"
#include "qactiongroup.h"
#include "putchinesetext.h"
#include "QSettings"
#include <QThread>
#include <QDir>
#include <QPainter>
#include <qstandardpaths.h>
#ifdef _MSC_VER
    #pragma execution_character_set("utf-8")
#endif


TakePhotos::TakePhotos(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
    setFixedSize(this->width(),this->height());

	//tSetttings->show();
	//x = 0;
	//y = 0;
	//r = 0;
	//g = 0;
	//b = 0;
	InitSettings();
	LoadSettings();
	serverStatusLabel = new QLabel(tr("Server status: Error"));
	cameraStatusLabel = new QLabel(tr("Camera status: Error"));
	checker = new CheckStatus(url,NULL);
	serverCheckerTimer = new QTimer();
	serverCheckerTimer->setInterval(1000 * 10);
	connect(serverCheckerTimer, SIGNAL(timeout()), checker, SLOT(OnTimeOut()));
	connect(checker, SIGNAL(ServerOk(bool)), this, SLOT(ChangeServerStatus(bool)));
	checker->OnTimeOut();
	//threadForServerChecker = new QThread();
	//checker->moveToThread(threadForServerChecker);
	serverCheckerTimer->start();
	
	checker->OnTimeOut();
	ui.statusBar->addPermanentWidget(serverStatusLabel);
	ui.statusBar->addPermanentWidget(cameraStatusLabel);

    agentIdImage=new QPixmap();
    idImage=new QPixmap();

	a = 0;
	//fontSize = 25;
	workType = 0;
	//fontType = "黑体";
	cameraGroup= new QActionGroup(this);
	camera_1=new QAction(tr("Camera 1"),ui.menuSwitch_Camera);
	camera_2=new QAction(tr("Camera 2"),ui.menuSwitch_Camera);
	camera_3=new QAction(tr("Camera 3"),ui.menuSwitch_Camera);
	camera_4=new QAction(tr("Camera 4"),ui.menuSwitch_Camera);
	camera_5=new QAction(tr("Camera 5"),ui.menuSwitch_Camera);
	cameraGroup->addAction(camera_1);
	cameraGroup->addAction(camera_2);
	cameraGroup->addAction(camera_3);
	cameraGroup->addAction(camera_4);
	cameraGroup->addAction(camera_5);
	cameraGroup->setExclusive(true);
	ui.menuSwitch_Camera->addAction(camera_1);
	ui.menuSwitch_Camera->addAction(camera_2);
	ui.menuSwitch_Camera->addAction(camera_3);
	ui.menuSwitch_Camera->addAction(camera_4);
	ui.menuSwitch_Camera->addAction(camera_5);
	camera_1->setCheckable(true);
	camera_2->setCheckable(true);
	camera_3->setCheckable(true);
	camera_4->setCheckable(true);
	camera_5->setCheckable(true);
	camera_1->setChecked(true);
	connect(ui.actionFont_Settings,SIGNAL(triggered()), this, SLOT(ShowFontSettings()));
	connect(ui.actionServer_Setting, SIGNAL(triggered()), this, SLOT(ShowServerSettings()));
	connect(ui.readInfoBtn, SIGNAL(clicked()), this, SLOT(GetInfo()));
	connect(ui.cleanBtn, SIGNAL(clicked()), this, SLOT(CleanInfo()));
	connect(ui.readAgentBtn, SIGNAL(clicked()), this, SLOT(GetAgentInfo()));
	connect(ui.cleanAgentBtn, SIGNAL(clicked()), this, SLOT(CleanAgentInfo()));
	connect(camera_1, SIGNAL(triggered()), this, SLOT(SwitchCamera()));
	connect(camera_2, SIGNAL(triggered()), this, SLOT(SwitchCamera()));
	connect(camera_3, SIGNAL(triggered()), this, SLOT(SwitchCamera()));
	connect(camera_4, SIGNAL(triggered()), this, SLOT(SwitchCamera()));
	connect(camera_5, SIGNAL(triggered()), this, SLOT(SwitchCamera()));
	connect(ui.comboBox_2, SIGNAL(currentIndexChanged(int)), this, SLOT(SwitchType()));
	connect(ui.submitBtn, SIGNAL(clicked()), this, SLOT(Submit()));
	//connect(tSetttings, SIGNAL(SetFont(QString)), this, SLOT(SetFont(QString)));
	//connect(tSetttings, SIGNAL(SetRed(int)), this, SLOT(SetRed(int)));
	//connect(tSetttings, SIGNAL(SetGreen(int)), this, SLOT(SetGreen(int)));
	//connect(tSetttings, SIGNAL(SetBlue(int)), this, SLOT(SetBlue(int)));
	//connect(tSetttings, SIGNAL(SetSize(int)), this, SLOT(SetSize(int)));

	//connect(tSetttings, SIGNAL(DoUp()), this, SLOT(TextUp()));
	//connect(tSetttings, SIGNAL(DoDown()), this, SLOT(TextDown()));
	//connect(tSetttings, SIGNAL(DoLeft()), this, SLOT(TextLeft()));
	//connect(tSetttings, SIGNAL(DoRight()), this, SLOT(TextRight()));

	
	connect(ui.cleanAllBtn, SIGNAL(clicked()), this, SLOT(CleanAll()));

	switch (cameraIdx) 
	{
	case 1:
		camera_2->setChecked(true);
		break;
	case 2:
		camera_3->setChecked(true);
		break;
	case 3:
		camera_4->setChecked(true);
		break;
	case 4:
		camera_5->setChecked(true);
		break;
	default:
		camera_1->setChecked(true);
		break;
	}

	InitCamera();
	submitData = new SubmitData(url,this);

    connect(ui.actionHistory,SIGNAL(triggered()),this,SLOT(OpenHistoryDig()));
}

void TakePhotos::GetInfo()
{
	idreader::IDCardReader idr;
	if (idr.errCode == 0)
	{
		QImage* img = new QImage;

		if (!(img->load("./photo.bmp"))) //加载图像
		{
			QMessageBox::critical(this,
				tr("Error"),
				tr("Can not open photo!"));
			delete img;
			return;
		}
		ui.nameInput->setText(QString::fromLocal8Bit(idr.name.c_str()).replace(" ",""));
		ui.IDCardNumInput->setText(QString::fromLocal8Bit(idr.code.c_str()));
		ui.cardPhotoLabel->setPixmap(QPixmap::fromImage(*img));
        transactor.GetMessageFormIdCardReader(idr);
        QFile photo(QCoreApplication::applicationDirPath()  + "/photo.bmp");
        if(photo.exists())
        {
            photo.remove();
        }

        QFile transactorSFZfront(QCoreApplication::applicationDirPath()  + "/1.jpg");
        QFile transactorSFZback(QCoreApplication::applicationDirPath()  + "/2.jpg");
        if(transactorSFZfront.exists() && transactorSFZback.exists())
        {
            QPixmap front;

            QPixmap back;

            if(back.load(QCoreApplication::applicationDirPath()  + "/2.jpg")&&front.load(QCoreApplication::applicationDirPath()  + "/1.jpg"))
            {
                idImage=new QPixmap(front.width(),front.height()*2);
                QPainter  painter(idImage);
                painter.drawPixmap(0,0,front.width(),front.height(),front);
                painter.drawPixmap(0,back.height()+1,back.width(),back.height(),back);
                //idImage->save("idimage.jpg");
                transactorSFZfront.remove();
                transactorSFZback.remove();
            }
        }
	}
	else
	{
		QString errMsg;
		switch (idr.errCode)
		{
		case -1:
			errMsg = tr("Can not open Sdtapi.dll!");
			break;
		case -2:
			errMsg = tr("Can not load function!");
			break;
		case -3:
			errMsg = tr("Can not link to CardReader!");
			break;
		case -4:
			errMsg = tr("Can not Find IDCard!");
			break;
		case -5:
			errMsg = tr("Can not Read IDCard Information!");
			break;
		default:
			break;
		}
		QMessageBox::critical(this,
			tr("Error"),
			errMsg);
	}
}

void TakePhotos::PutTextToImg(cv::Mat & img)
{
	if (workType == 0)
	{
        string text=QString("本照片用于办理医保IC卡密码初始化业务").toLocal8Bit().data();
        putTextZH(img,text.c_str(), cv::Point(x, y), cv::Scalar(b, g, r), fontSize, fontType.c_str());
	}
	if (workType == 1)
	{
        string text=QString("本照片用于办理医保IC卡解除挂失业务").toLocal8Bit().data();
        putTextZH(img, text.c_str(), cv::Point(x, y), cv::Scalar(b, g, r), fontSize, fontType.c_str());
    }
    if (workType == 2)
    {
        string text=QString("本照片用于办理无卡结算备案").toLocal8Bit().data();
        putTextZH(img, text.c_str(), cv::Point(x, y), cv::Scalar(b, g, r), fontSize, fontType.c_str());
    }
}

void TakePhotos::InitSettings()
{
	settings=new QSettings(QCoreApplication::applicationDirPath() + "/Settings.ini", QSettings::IniFormat);
	if (!settings->contains("TextOffsetX"))
	{
		settings->setValue("TextOffsetX", 0);
	}
	if (!settings->contains("TextOffsetY"))
	{
		settings->setValue("TextOffsetY", 0);
	}
	if (!settings->contains("TextColorR"))
	{
		settings->setValue("TextColorR", 0);
	}
	if (!settings->contains("TextColorG"))
	{
		settings->setValue("TextColorG", 0);
	}
	if (!settings->contains("TextColorB"))
	{
		settings->setValue("TextColorB", 0);
	}
	if (!settings->contains("FontSize"))
	{
		settings->setValue("FontSize", 25);
	}
	if (!settings->contains("Font"))
	{
		settings->setValue("Font", QString::fromLocal8Bit("黑体"));
	}

	if (!settings->contains("CameraIdx"))
	{
		settings->setValue("CameraIdx", 0);
	}

	if (!settings->contains("ServerAddress"))
	{
		ShowServerSettings();
	}
}

void TakePhotos::LoadSettings()
{
	x = settings->value("TextOffsetX").toDouble();
	y = settings->value("TextOffsetY").toDouble();
	r = settings->value("TextColorR").toDouble();
	g = settings->value("TextColorG").toDouble();
	b = settings->value("TextColorB").toDouble();
	fontSize = settings->value("FontSize").toDouble();
    fontType = settings->value("Font").toString().toStdString().data();
	cameraIdx = settings->value("CameraIdx").toInt();
	if (cameraIdx > 4)
	{
		settings->setValue("CameraIdx", 0);
		cameraIdx = 0;
	}
    url = settings->value("ServerAddress").toString().toLocal8Bit().data();
}

void TakePhotos::CleanInfo()
{
	ui.nameInput->clear();
	ui.IDCardNumInput->clear();
	ui.cardPhotoLabel->clear();
    transactor.clear();
}

void TakePhotos::GetAgentInfo()
{
	idreader::IDCardReader idr;
	if (idr.errCode == 0)
	{
		QImage* img = new QImage;

		if (!(img->load("./photo.bmp"))) //加载图像
		{
			QMessageBox::critical(this,
				tr("Error"),
				tr("Can not open photo!"));
			delete img;
			return;
		}

		ui.agentNameInput->setText(QString::fromLocal8Bit(idr.name.c_str()).replace(" ", ""));
		ui.agentNumInput->setText(QString::fromLocal8Bit(idr.code.c_str()));
		ui.agentPhotoLabel->setPixmap(QPixmap::fromImage(*img));
        agent.GetMessageFormIdCardReader(idr);
        QFile photo(QCoreApplication::applicationDirPath()  + "/photo.bmp");
        if(photo.exists())
        {
            photo.remove();
        }
        QFile transactorSFZfront(QCoreApplication::applicationDirPath()  + "/1.jpg");
        QFile transactorSFZback(QCoreApplication::applicationDirPath()  + "/2.jpg");

        if(transactorSFZfront.exists() && transactorSFZback.exists())
        {
            QPixmap front;

            QPixmap back;

            if(back.load(QCoreApplication::applicationDirPath()  + "/2.jpg")&&front.load(QCoreApplication::applicationDirPath()  + "/1.jpg"))
            {
                agentIdImage=new QPixmap(front.width(),front.height()*2);
                QPainter  painter(agentIdImage);
                painter.drawPixmap(0,0,front.width(),front.height(),front);
                painter.drawPixmap(0,back.height()+1,back.width(),back.height(),back);
                //idImage->save("idimage.jpg");
                transactorSFZfront.remove();
                transactorSFZback.remove();
            }
        }
	}
	else
	{
		QString errMsg;
		switch (idr.errCode)
		{
		case -1:
			errMsg = tr("Can not open Sdtapi.dll!");
			break;
		case -2:
			errMsg = tr("Can not load function!");
			break;
		case -3:
			errMsg = tr("Can not link to CardReader!");
			break;
		case -4:
			errMsg = tr("Can not Find IDCard!");
			break;
		case -5:
			errMsg = tr("Can not Read IDCard Information!");
			break;
		default:
			break;
		}
		QMessageBox::critical(this,
			tr("Error"),
			errMsg);
	}
}

void TakePhotos::CleanAgentInfo()
{
	ui.agentNameInput->clear();
	ui.agentNumInput->clear();
	ui.agentPhotoLabel->clear();
    agent.clear();
}

void TakePhotos::InitCamera()
{
	cameraCapture.open(cameraIdx);
	cameraCapture.set(cv::CAP_PROP_FPS, 30);
	cameraCapture.set(cv::CAP_PROP_FRAME_WIDTH, 640);
	cameraCapture.set(cv::CAP_PROP_FRAME_HEIGHT, 480);
	if (!cameraCapture.isOpened())
	{
		//std::cout << "无法使用摄像头" << std::endl;
		//return -1;
		QMessageBox::critical(this, tr("Error"), tr("Can not open camera!"));
	}
	double rate = cameraCapture.get(cv::CAP_PROP_FPS);
	cv::Mat frame;
	cameraCapture >> frame;

	if (!frame.empty())
	{
		cameraCapture >> frame;
		PutTextToImg(frame);
		QImage image = Mat2QImage(frame);
		ui.cameraLabel->setPixmap(QPixmap::fromImage(image));
	}
	timer = new QTimer(this);
	if (rate < 30)
	{
		rate = 30.0;
	}
	timer->setInterval(1000 / rate);   //set timer match with FPS
	connect(this->timer, SIGNAL(timeout()), this, SLOT(NextFrame()));
	timer->start();
	connect(ui.takePhotoBtn, SIGNAL(clicked()), this, SLOT(TakeOrCleanPhoto()));
}

QImage TakePhotos::Mat2QImage(cv::Mat cvImg)
{
	QImage qImg;
	if (cvImg.channels() == 3)                             //3 channels color image
	{

		cv::cvtColor(cvImg, cvImg, CV_BGR2RGB);
		qImg = QImage((const unsigned char*)(cvImg.data),
			cvImg.cols, cvImg.rows,
			cvImg.cols*cvImg.channels(),
			QImage::Format_RGB888);
	}
	else if (cvImg.channels() == 1)                    //grayscale image
	{
		qImg = QImage((const unsigned char*)(cvImg.data),
			cvImg.cols, cvImg.rows,
			cvImg.cols*cvImg.channels(),
			QImage::Format_Indexed8);
	}
	else
	{
		qImg = QImage((const unsigned char*)(cvImg.data),
			cvImg.cols, cvImg.rows,
			cvImg.cols*cvImg.channels(),
			QImage::Format_RGB888);
	}

	return qImg;

}

void TakePhotos::NextFrame()
{
	if (!cameraCapture.isOpened())
	{
		cameraStatusLabel->setText(tr("Camera status: Error"));
		return;
	}
	cameraStatusLabel->setText(tr("Camera status: Ok"));
	cv::Mat frame;
	cameraCapture >> frame;
	PutTextToImg(frame);
	if (!frame.empty())
	{
		QImage image = Mat2QImage(frame);
		ui.cameraLabel->setPixmap(QPixmap::fromImage(image));
		//this->update();
	}
	else
	{
		cameraStatusLabel->setText(tr("Camera status: Error"));
	}
}

void TakePhotos::SwitchCamera()
{
	if (timer->isActive())
	{
		timer->stop();
	}

	if (camera_1->isChecked())
	{
		cameraIdx = 0;
	}
	if (camera_2->isChecked())
	{
		cameraIdx = 1;
	}
	if (camera_3->isChecked())
	{
		cameraIdx = 2;
	}
	if (camera_4->isChecked())
	{
		cameraIdx = 3;
	}
	if (camera_5->isChecked())
	{
		cameraIdx = 4;
	}
	cameraCapture.open(cameraIdx);
	if (!cameraCapture.isOpened())
	{
		//std::cout << "无法使用摄像头" << std::endl;
		//return -1;
		QMessageBox::critical(this, tr("Error"), tr("Can not open camera!"));
		ui.cameraLabel->clear();
		return;
	}
//	connect(this->timer, SIGNAL(timeout()), this, SLOT(NextFrame()));
	timer->start();
	settings->setValue("CameraIdx", cameraIdx);
}

void TakePhotos::SwitchType()
{
	workType = ui.comboBox_2->currentIndex();
}

void TakePhotos::ShowFontSettings()
{
	tSetttings = new TextSettings(settings,this);
	connect(tSetttings, SIGNAL(SetFont(QString)), this, SLOT(SetFont(QString)));
	connect(tSetttings, SIGNAL(SetRed(int)), this, SLOT(SetRed(int)));
	connect(tSetttings, SIGNAL(SetGreen(int)), this, SLOT(SetGreen(int)));
	connect(tSetttings, SIGNAL(SetBlue(int)), this, SLOT(SetBlue(int)));
	connect(tSetttings, SIGNAL(SetSize(int)), this, SLOT(SetSize(int)));

	connect(tSetttings, SIGNAL(DoUp()), this, SLOT(TextUp()));
	connect(tSetttings, SIGNAL(DoDown()), this, SLOT(TextDown()));
	connect(tSetttings, SIGNAL(DoLeft()), this, SLOT(TextLeft()));
	connect(tSetttings, SIGNAL(DoRight()), this, SLOT(TextRight()));
	connect(tSetttings, SIGNAL(DoRest()), this, SLOT(TextRest()));

	connect(tSetttings, SIGNAL(ApplySettings()), this, SLOT(SaveSettings()));
	connect(tSetttings, SIGNAL(CancelSettings()), this, SLOT(CancelSettings()));
	tSetttings->show();
}

void TakePhotos::ShowServerSettings()
{
	sSetting = new ServerSettings(settings,this);
	connect(sSetting, SIGNAL(ApplyChange(QString)), this, SLOT(SaveServerSetting(QString)));
	connect(sSetting, SIGNAL(DiscardChange()), this, SLOT(DiscardServerSetting()));
	sSetting->exec();
}

void TakePhotos::SetFont(QString _fontType)
{
    fontType = _fontType.toStdString();
}

void TakePhotos::SetRed(int red)
{
	r = red;
}

void TakePhotos::SetGreen(int green)
{
	g = green;
}

void TakePhotos::SetBlue(int blue)
{
	b = blue;
}

void TakePhotos::SetSize(int size)
{
	fontSize = size;
}

void TakePhotos::TextUp()
{
	y < 5 ? y = 0 : y -= 5;
}

void TakePhotos::TextDown()
{
	y > 480-fontSize-1-5 ? y = 480 - fontSize - 1 : y += 5;
}

void TakePhotos::TextLeft()
{
	x < 5 ? x = 0 : x -= 5;
}

void TakePhotos::TextRight()
{
	x > 640 - fontSize - 1 - 5 ? x = 640 - fontSize - 1 : x += 5;
}

void TakePhotos::TextRest()
{
	x = 0;
	y = 0;
}

void TakePhotos::SaveSettings()
{
	settings->setValue("TextOffsetX", x);
	settings->setValue("TextOffsetY", y);
	settings->setValue("TextColorR", r);
	settings->setValue("TextColorG", g);
	settings->setValue("TextColorB", b);
	settings->setValue("FontSize", fontSize);
    settings->setValue("Font", QString::fromLocal8Bit(fontType.data()).toLocal8Bit());
}

void TakePhotos::CancelSettings()
{
	LoadSettings();
}

void TakePhotos::CleanAll()
{
	if (!timer->isActive())
	{
		timer->start();
		ui.takePhotoBtn->setText(tr("Take Photo"));
	}
	CleanAgentInfo();
	CleanInfo();
}

void TakePhotos::TakeOrCleanPhoto()
{
	if (timer->isActive())
	{
		timer->stop();
		ui.takePhotoBtn->setText(tr("Clean Photo"));
	}
	else
	{
		timer->start();
		ui.takePhotoBtn->setText(tr("Take Photo"));
	}
}

void TakePhotos::SaveServerSetting(QString url)
{
	settings->setValue("ServerAddress", url);
	LoadSettings();
}

void TakePhotos::DiscardServerSetting()
{
	sSetting->close();
}

void TakePhotos::ChangeServerStatus(bool status)
{
	if (status) {
		serverStatusLabel->setText(tr("Server status: Ok"));
	}
	else
	{
		serverStatusLabel ->setText(tr("Server status: Error"));
	}
}

void TakePhotos::Submit()
{
	if (timer->isActive())
	{
		QMessageBox::critical(this, tr("Error"), tr("Please take the photo first !"));
		return;
	}

	if (ui.IDCardNumInput->text().isEmpty() || ui.nameInput->text().isEmpty())
	{
		QMessageBox::critical(this, tr("Error"), tr("Transactor information invalid !"));
		return;
	}
	submitData->SetUrl(url);
	submitData->CleanForm();
	submitData->AppendText("Name", ui.nameInput->text());
	submitData->AppendText("IDNumber", ui.IDCardNumInput->text());
    if(ui.agentNameInput->text()!="")
    {
        submitData->AppendText("AgentName", ui.agentNameInput->text());
    }
    if(ui.agentNumInput->text()!="")
    {
        submitData->AppendText("AgentIDNumber", ui.agentNumInput->text());
    }
	submitData->AppendText("ServiceType", QString::number(ui.comboBox_2->currentIndex()));
    if(transactor.gender!="")
    {
        submitData->AppendText("Gender", transactor.gender);
    }
    if(transactor.folk!="")
    {
        submitData->AppendText("Folk", transactor.folk);
    }
    if(transactor.expireStart!="")
    {
        submitData->AppendText("ExpireStart", transactor.expireStart);
    }
    if(transactor.expireEnd!="")
    {
        submitData->AppendText("ExpireEnd", transactor.expireEnd);
    }
    if(transactor.birthDay!="")
    {
        submitData->AppendText("BirthDay", transactor.birthDay);
    }
    if(transactor.agency!="")
    {
        submitData->AppendText("Agency", transactor.agency);
    }
    if(transactor.address!="")
    {
        submitData->AppendText("Address", transactor.address);
    }

    if(agent.gender!="")
    {
        submitData->AppendText("AgentGender", agent.gender);
    }
    if(agent.folk!="")
    {
        submitData->AppendText("AgentFolk", agent.folk);
    }
    if(agent.expireStart!="")
    {
        submitData->AppendText("AgentExpireStart", agent.expireStart);
    }
    if(agent.expireEnd!="")
    {
        submitData->AppendText("AgentExpireEnd", agent.expireEnd);
    }
    if(agent.birthDay!="")
    {
        submitData->AppendText("AgentBirthDay", agent.birthDay);
    }
    if(agent.agency!="")
    {
        submitData->AppendText("AgentAgency", agent.agency);
    }
    if(agent.address!="")
    {
        submitData->AppendText("AgentAddress", agent.address);
    }

	if(!SaveTmpFile())
	{
		return;
	}
    //QMessageBox::critical(this,"test","1");

    string tempPath;
    //tempPath= QCoreApplication::applicationDirPath().toStdString().data();
    tempPath =QStandardPaths::writableLocation(QStandardPaths::AppConfigLocation).toStdString().data();
    tempPath+= + "/TakePhoto";
    QDir temp(QString::fromStdString(tempPath));

	
	//submitData->AppendFile("IDCardImage",NULL);
	//submitData->AppendFile("AgentIDCardImage",NULL);
	submitData->Submit();
    //QMessageBox::critical(this,"test","2");
	if (submitData->Result())
	{
		QMessageBox::information(this, tr("Success"), tr("Submit Success"));
		CleanAll();
		ui.tabWidget->setCurrentIndex(0);
	}
	else
	{
		QMessageBox::critical(this, tr("Error"), submitData->Response().c_str());
        return;
	}

	QFile handlejpg(QString::fromStdString(tempPath + "/handle.jpg"));
	if (handlejpg.exists())
	{
		handlejpg.remove();
	}

	QFile transactorjpg(QString::fromStdString(tempPath + "/transactor.jpg"));
	if (transactorjpg.exists())
	{
		transactorjpg.remove();
	}

	QFile agentjpg(QString::fromStdString(tempPath + "/agent.jpg"));
	if (agentjpg.exists())
	{
		agentjpg.remove();
	}

    QFile idImagejpg(QString::fromStdString(tempPath + "/idImage.jpg"));
    if (idImagejpg.exists())
    {
        idImagejpg.remove();
    }
    idImage=new QPixmap();
    QFile agentIdImagejpg(QString::fromStdString(tempPath + "/agentIdImage.jpg"));
    if (agentIdImagejpg.exists())
    {
        agentIdImagejpg.remove();
    }
    agentIdImage=new QPixmap();
}

bool TakePhotos::SaveTmpFile()
{
	auto handleImg = ui.cameraLabel->pixmap();
	auto transactorPhoto = ui.cardPhotoLabel->pixmap();
	auto agentPhtot = ui.agentPhotoLabel->pixmap();

	if (handleImg == NULL || handleImg->isNull())
	{
		QMessageBox::critical(this, tr("Error"), tr("Handle photo is not null !"));
		return false;
	}
    string tempPath;
    //tempPath= QCoreApplication::applicationDirPath().toStdString().data();
    //tempPath+= + "/tmp";
    tempPath =QStandardPaths::writableLocation(QStandardPaths::AppConfigLocation).toStdString().data();
    tempPath+= + "/TakePhoto";
	QDir temp(QString::fromStdString(tempPath));
	if (!temp.exists())
	{
		if (!temp.mkpath(QString::fromStdString(tempPath)))
		{
			QMessageBox::critical(this, tr("Error"), tr("Can not create temporary directory !"));
			return false;
		}
	}
	QFile handlejpg(QString::fromStdString(tempPath + "/handle.jpg"));

	if (handlejpg.exists())
	{
		handlejpg.remove();
	}
    //QMessageBox::critical(this,"test","3");

	QFile transactorjpg(QString::fromStdString(tempPath + "/transactor.jpg"));
	if (transactorjpg.exists())
	{
		transactorjpg.remove();
	}

	QFile agentjpg(QString::fromStdString(tempPath + "/agent.jpg"));
	if (agentjpg.exists())
	{
		agentjpg.remove();
	}
	bool handleIsSave=handleImg->save(QString::fromStdString(tempPath + "/handle.jpg"),"jpg");
	submitData->AppendFile("HandlePhoto", QString::fromStdString(tempPath + "/handle.jpg"));
    bool transactorIsSave = false;
    //QMessageBox::critical(this,"test","4");
	if (transactorPhoto != NULL && !transactorPhoto->isNull())
	{
		transactorIsSave = transactorPhoto->save(QString::fromStdString(tempPath + "/transactor.jpg"), "jpg");
		submitData->AppendFile("Photo", QString::fromStdString(tempPath + "/transactor.jpg"));

	}
    bool agentIsSave = false;
    //QMessageBox::critical(this,"test","5");
	if (agentPhtot != NULL && !agentPhtot->isNull())
	{
		agentIsSave = agentPhtot->save(QString::fromStdString(tempPath + "/agent.jpg"), "jpg");
		submitData->AppendFile("AgentPhoto", QString::fromStdString(tempPath + "/agent.jpg"));
	}
    //QMessageBox::critical(this,"test","6");
    if (idImage != NULL && !idImage->isNull())
    {
        idImage->save(QString::fromStdString(tempPath + "/idImage.jpg"), "jpg");
        submitData->AppendFile("IDCardImage", QString::fromStdString(tempPath + "/idImage.jpg"));
    }
    //QMessageBox::critical(this,"test","7");
    if (agentIdImage != NULL && !agentIdImage->isNull())
    {
        agentIdImage->save(QString::fromStdString(tempPath + "/agentIdImage.jpg"), "jpg");
        submitData->AppendFile("AgentIDCardImage", QString::fromStdString(tempPath + "/agentIdImage.jpg"));
    }
    //QMessageBox::critical(this,"test","8");
	if (!(handleIsSave))
	{
		QMessageBox::critical(this, tr("Error"), tr("Can not save temporary imge!"));
		return false;
	}
    //QMessageBox::critical(this,"test","9");
	return true;
}

void TakePhotos::OpenHistoryDig()
{
    historyTable=new ServiceTimeLineTable();
    historyTable->setWindowFlags(historyTable->windowFlags() &~ Qt::WindowMaximizeButtonHint);
    historyTable->exec();
}
