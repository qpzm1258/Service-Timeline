#include "textsettings.h"
#include"qfontdatabase.h"

TextSettings::TextSettings(QSettings *settings,QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	QFontDatabase database;
	foreach(const QString &family, database.families(QFontDatabase::SimplifiedChinese))
	{
		ui.comboBox->addItem(family);
	}
	ui.horizontalSlider->setMaximum(255);
	ui.horizontalSlider_2->setMaximum(255);
	ui.horizontalSlider_3->setMaximum(255);
	ui.horizontalSlider_4->setMaximum(100);

	ui.horizontalSlider->setMinimum(0);
	ui.horizontalSlider_2->setMinimum(0);
	ui.horizontalSlider_3->setMinimum(0);
	ui.horizontalSlider_4->setMinimum(0);

	ui.horizontalSlider->setSingleStep(25);
	ui.horizontalSlider_2->setSingleStep(25);
	ui.horizontalSlider_3->setSingleStep(25);
	ui.horizontalSlider_4->setSingleStep(5);
	upPressedTimer = new QTimer(this);
	upPressedTimer->setInterval(500);
	upContinuityTimer = new QTimer(this);
	upContinuityTimer->setInterval(100);

	downPressedTimer = new QTimer(this);
	downPressedTimer->setInterval(500);
	downContinuityTimer = new QTimer(this);
	downContinuityTimer->setInterval(100);

	leftPressedTimer = new QTimer(this);
	leftPressedTimer->setInterval(500);
	leftContinuityTimer = new QTimer(this);
	leftContinuityTimer->setInterval(100);

	rightPressedTimer = new QTimer(this);
	rightPressedTimer->setInterval(500);
	rightContinuityTimer = new QTimer(this);
	rightContinuityTimer->setInterval(100);



	connect(ui.comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(FontChange()));
	connect(ui.horizontalSlider,SIGNAL(valueChanged(int)), this, SLOT(RedChange(int)));
	connect(ui.horizontalSlider_2, SIGNAL(valueChanged(int)), this, SLOT(GreenChange(int)));
	connect(ui.horizontalSlider_3, SIGNAL(valueChanged(int)), this, SLOT(BlueChange(int)));
	connect(ui.horizontalSlider_4, SIGNAL(valueChanged(int)), this, SLOT(SizeChange(int)));

	connect(ui.pushButton_4, SIGNAL(pressed()), this, SLOT(UpPressed()));
	connect(upPressedTimer, SIGNAL(timeout()), upContinuityTimer, SLOT(start()));
	connect(upContinuityTimer, SIGNAL(timeout()), this, SLOT(UpContinuity()));
	connect(ui.pushButton_4, SIGNAL(released()), this, SLOT(UpRelease()));

	connect(ui.pushButton_5, SIGNAL(pressed()), this, SLOT(DownPressed()));
	connect(downPressedTimer, SIGNAL(timeout()), downContinuityTimer, SLOT(start()));
	connect(downContinuityTimer, SIGNAL(timeout()), this, SLOT(DownContinuity()));
	connect(ui.pushButton_5, SIGNAL(released()), this, SLOT(DownRelease()));

	connect(ui.pushButton, SIGNAL(pressed()), this, SLOT(LeftPressed()));
	connect(leftPressedTimer, SIGNAL(timeout()), leftContinuityTimer, SLOT(start()));
	connect(leftContinuityTimer, SIGNAL(timeout()), this, SLOT(LeftContinuity()));
	connect(ui.pushButton, SIGNAL(released()), this, SLOT(LeftRelease()));

	connect(ui.pushButton_3, SIGNAL(pressed()), this, SLOT(RightPressed()));
	connect(rightPressedTimer, SIGNAL(timeout()), rightContinuityTimer, SLOT(start()));
	connect(rightContinuityTimer, SIGNAL(timeout()), this, SLOT(RightContinuity()));
	connect(ui.pushButton_3, SIGNAL(released()), this, SLOT(RightRelease()));

	connect(ui.pushButton_2, SIGNAL(clicked()), this, SLOT(RestBtnClicked()));

	ui.comboBox->setCurrentText(settings->value("Font").toString());
	ui.horizontalSlider->setValue(settings->value("TextColorR").toInt());
	ui.horizontalSlider_2->setValue(settings->value("TextColorG").toInt());
	ui.horizontalSlider_3->setValue(settings->value("TextColorB").toInt());
	ui.horizontalSlider_4->setValue(settings->value("FontSize").toInt());

	connect(ui.pushButton_6, SIGNAL(clicked()), this, SLOT(OkBtnClicked()));
	connect(ui.pushButton_7, SIGNAL(clicked()), this, SLOT(CancelBtnClicked()));
}

TextSettings::~TextSettings()
{
}

void TextSettings::FontChange()
{
	SetFont(ui.comboBox->currentText());
}

void TextSettings::RedChange(int red)
{
	SetRed(red);
}

void TextSettings::GreenChange(int green)
{
	SetGreen(green);
}

void TextSettings::BlueChange(int blue)
{
	SetBlue(blue);
}

void TextSettings::SizeChange(int size)
{
	SetSize(size);
}

void TextSettings::UpPressed()
{
	upPressedTimer->start();
}

void TextSettings::UpRelease()
{
	if (upContinuityTimer->isActive())
	{
		upContinuityTimer->stop();
	}
	else
	{
		DoUp();
	}
	upPressedTimer->stop();
}

void TextSettings::UpContinuity()
{
	DoUp();
}

void TextSettings::DownPressed()
{
	downPressedTimer->start();
}

void TextSettings::DownRelease()
{
	if (downContinuityTimer->isActive())
	{
		downContinuityTimer->stop();
	}
	else
	{
		DoDown();
	}
	downPressedTimer->stop();
}

void TextSettings::DownContinuity()
{
	DoDown();
}

void TextSettings::LeftPressed()
{
	leftPressedTimer->start();
}

void TextSettings::LeftRelease()
{
	if (leftContinuityTimer->isActive())
	{
		leftContinuityTimer->stop();
	}
	else
	{
		DoLeft();
	}
	leftPressedTimer->stop();
}

void TextSettings::LeftContinuity()
{
	DoLeft();
}

void TextSettings::RightPressed()
{
	rightPressedTimer->start();
}

void TextSettings::RightRelease()
{
	if (rightContinuityTimer->isActive())
	{
		rightContinuityTimer->stop();
	}
	else
	{
		DoRight();
	}
	rightPressedTimer->stop();
}

void TextSettings::RightContinuity()
{
	DoRight();
}

void TextSettings::RestBtnClicked()
{
	DoRest();
}

void TextSettings::OkBtnClicked()
{
	ApplySettings();
	this->close();
}

void TextSettings::CancelBtnClicked()
{
	CancelSettings();
	this->close();
}

