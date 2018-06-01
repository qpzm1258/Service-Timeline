#include "historyviewer.h"
#include "ui_historyviewer.h"
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <QMessageBox>

HistoryViewer::HistoryViewer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HistoryViewer)
{
    setWindowFlags(this->windowFlags() &~ Qt::WindowMaximizeButtonHint);
    ui->setupUi(this);
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(close()));
}

HistoryViewer::~HistoryViewer()
{
    delete ui;
}

void HistoryViewer::SetHandlePhoto(QPixmap pixmap)
{
    ui->label->setPixmap(pixmap);
}

void HistoryViewer::SetTransactorCardImage(QPixmap pixmap)
{
    ui->label_2->setPixmap(pixmap);
}

void HistoryViewer::SetAgentCardImage(QPixmap pixmap)
{
    ui->label_3->setPixmap(pixmap);
}

void HistoryViewer::SetHandlePhotoURL(QString url)
{
    QNetworkAccessManager *manager;
    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)),
                    this, SLOT(replyFinishedHandle(QNetworkReply*)));
    manager->get(QNetworkRequest(QUrl(url)));

}

void HistoryViewer::SetTransactorCardImageURL(QString url)
{
    QNetworkAccessManager *manager;
    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)),
                    this, SLOT(replyFinishedTransactor(QNetworkReply*)));
    manager->get(QNetworkRequest(QUrl(url)));
}

void HistoryViewer::SetAgentCardImageURL(QString url)
{
    QNetworkAccessManager *manager;
    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)),
                    this, SLOT(replyFinishedAgent(QNetworkReply*)));
    manager->get(QNetworkRequest(QUrl(url)));
}

void HistoryViewer::replyFinishedHandle(QNetworkReply *reply)
{
    if (reply->error() == QNetworkReply::NoError)
    {
        QByteArray bytes = reply->readAll();
        QPixmap pixmap;
        pixmap.loadFromData(bytes);
        SetHandlePhoto(pixmap);
    }
    else
    {
        QMessageBox::critical(this,tr("Error"),tr("Can not load the image!"));
    }
}

void HistoryViewer::replyFinishedTransactor(QNetworkReply *reply)
{
    if (reply->error() == QNetworkReply::NoError)
    {
        QByteArray bytes = reply->readAll();
        QPixmap pixmap;
        pixmap.loadFromData(bytes);
        SetTransactorCardImage(pixmap);
    }
    else
    {
        QMessageBox::critical(this,tr("Error"),tr("Can not load the image!"));
    }
}
void HistoryViewer::replyFinishedAgent(QNetworkReply *reply)
{
    if (reply->error() == QNetworkReply::NoError)
    {
        QByteArray bytes = reply->readAll();
        QPixmap pixmap;
        pixmap.loadFromData(bytes);
        SetAgentCardImage(pixmap);
    }
    else
    {
        QMessageBox::critical(this,tr("Error"),tr("Can not load the image!"));
    }
}

void HistoryViewer::Clear()
{
    ui->label->clear();
    ui->label_2->clear();
    ui->label_3->clear();
    ui->tabWidget->setCurrentIndex(0);
}
