#include "servicetimelinetable.h"
#include "ui_servicetimelinetable.h"
#include <QMessageBox>
#include <QSettings>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonValue>
#include <QJsonObject>
#include <string>
#include "submitdata.h"

ServiceTimeLineTable::ServiceTimeLineTable(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ServiceTimeLineTable)
{
    ui->setupUi(this);
//    QStringList header;
//    header.append(tr("Id"));
//    header.append(tr("Name"));
//    header.append(tr("Code"));
//    header.append(tr("Agent Name"));
//    header.append(tr("Agent Code"));
//    header.append(tr("Update Time"));


    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(6);
    //ui->tableWidget->setHorizontalHeaderLabels(header);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->verticalHeader()->setHidden(true);
    ui->tableWidget->setColumnWidth(2,150);
    ui->tableWidget->setColumnWidth(4,150);
    //tableWidget->setHorizontalHeaderLabels(header);
    SetHerader();
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(Search()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(clear()));
}

ServiceTimeLineTable::~ServiceTimeLineTable()
{
    delete ui;
}

void ServiceTimeLineTable::Search()
{
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(0);
    SetHerader();
    //ui->tableWidget->clear();
   //QMessageBox::information(this,tr("info"),QString::number(ui->dateTimeEdit->dateTime().toTime_t()));
   QSettings *settings=new QSettings(QCoreApplication::applicationDirPath() + "/Settings.ini", QSettings::IniFormat);
   if (!settings->contains("ServerAddress"))
   {
       QMessageBox::critical(this,tr("Error"),tr("Please set server address"));
       return;
   }
   string url = settings->value("ServerAddress").toString().toLocal8Bit().data();
   SubmitData *submit=new SubmitData(url,this);
   if(!ui->lineEdit->text().isEmpty())
   {
       submit->AppendText("name",ui->lineEdit->text());
   }

   if(!ui->lineEdit_2->text().isEmpty())
   {
       submit->AppendText("code",ui->lineEdit_2->text());
   }

   if(!ui->dateTimeEdit->dateTime().isValid())
   {
       QMessageBox::critical(this,tr("Error"),tr("Start time set invalid"));
       return;
   }

   if(!ui->dateTimeEdit_2->dateTime().isValid())
   {
       QMessageBox::critical(this,tr("Error"),tr("End time set invalid"));
       return;
   }

   if(ui->dateTimeEdit->dateTime()>=ui->dateTimeEdit_2->dateTime())
   {
       QMessageBox::critical(this,tr("Error"),tr("End time must later then start"));
       return;
   }

   submit->AppendText("start",QString::number(ui->dateTimeEdit->dateTime().toTime_t()));
   submit->AppendText("end",QString::number(ui->dateTimeEdit_2->dateTime().toTime_t()));

   submit->CustomSubmit("/api/History");
   if(!submit->Result())
   {
       QMessageBox::critical(this,tr("Error"),QString::fromStdString(submit->Response()));
       return;
   }
   FillinTable(QString::fromUtf8(submit->Response().data()));
}

void ServiceTimeLineTable::FillinTable(QString json)
{
    QJsonParseError e;
    //QString jsonStr = QString::fromUtf8(response.data());

    QJsonDocument jsonDoc = QJsonDocument::fromJson(json.toUtf8(), &e);
    if (e.error == QJsonParseError::NoError && !jsonDoc.isNull())
    {
        if (jsonDoc.isArray())
        {
            QJsonArray array = jsonDoc.array();
            int nSize = array.size();  // 获取数组大小
            if(nSize==0)
            {
                QMessageBox::critical(this,tr("Error"),tr("No data!"));
                return;
            }
            for (int i = 0; i < nSize; ++i)
            {
                QJsonValue value = array.at(i);
                if(!value.isObject())
                {
                    QMessageBox::critical(this,tr("Error"),tr("Return json format error!"));
                    return;
                }
                QJsonObject history=value.toObject();
                if(!history.contains("id"))
                {
                    QMessageBox::critical(this,tr("Error"),tr("Return json format error!"));
                    return;
                }
                QJsonValue id = history.value("id");
                if(!id.isDouble())
                {
                    QMessageBox::critical(this,tr("Error"),tr("Return json format error!"));
                    return;
                }
                ui->tableWidget->insertRow(ui->tableWidget->rowCount());
                ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,0,new QTableWidgetItem(QString::number(id.toInt())));

                if(history.contains("updateTime"))
                {
                    QJsonValue updateTime = history.value("updateTime");
                    if(updateTime.isString())
                    {
                        QString timeStr=updateTime.toString().replace("T"," ").section(".",0,0).trimmed();
                        QDateTime time = QDateTime::fromString(timeStr,"yyyy-MM-dd HH:mm:ss");
                        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,5,new QTableWidgetItem(time.toString()));
                    }
                }
                if(history.contains("agentInfo"))
                {
                    QJsonValue agentInfo = history.value("agentInfo");
                    if(agentInfo.isObject())
                    {
                        QJsonObject agent = agentInfo.toObject();
                        if(agent.contains("name"))
                        {
                            QJsonValue agentName = agent.value("name");
                            if(agentName.isString())
                            {
                                ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,3,new QTableWidgetItem(agentName.toString()));
                            }
                        }

                        if(agent.contains("code"))
                        {
                            QJsonValue agentCode = agent.value("code");
                            if(agentCode.isString())
                            {
                                ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,4,new QTableWidgetItem(agentCode.toString()));
                            }
                        }
                    }
                    if(history.contains("transactorInfo"))
                    {
                        QJsonValue transactorInfo = history.value("transactorInfo");
                        if(transactorInfo.isObject())
                        {
                            QJsonObject transactor = transactorInfo.toObject();
                            if(transactor.contains("name"))
                            {
                                QJsonValue transactorName = transactor.value("name");
                                if(transactorName.isString())
                                {
                                    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,1,new QTableWidgetItem(transactorName.toString()));
                                }
                            }

                            if(transactor.contains("code"))
                            {
                                QJsonValue transactorCode = transactor.value("code");
                                if(transactorCode.isString())
                                {
                                    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,2,new QTableWidgetItem(transactorCode.toString()));
                                }
                            }
                        }
                    }
                }

                //ui->tableWidget->item(ui->tableWidget->rowCount(),1)->setText(QString::number(id.toInt()));
                //ui->tableWidget->cellWidget(ui->tableWidget->rowCount()-1,1)=new QTableWidgetItem(id.toInt());
            }
        }
        else
        {
            QMessageBox::critical(this,tr("Error"),tr("Return json format error!"));
            return;
        }
        //auto a = result["err"].toBool();
        //ServerOk(true);

        return;
    }
    else
    {
        QMessageBox::critical(this,tr("Error"),tr("Return json format error!"));
        return;
    }
}

void ServiceTimeLineTable::SetHerader()
{
    QStringList header;
    header.append(tr("Id"));
    header.append(tr("Name"));
    header.append(tr("Code"));
    header.append(tr("Agent Name"));
    header.append(tr("Agent Code"));
    header.append(tr("Update Time"));

    ui->tableWidget->setHorizontalHeaderLabels(header);
}

void ServiceTimeLineTable::clear()
{
    ui->dateTimeEdit->setDateTime(QDateTime::fromString("2000-01-01 00:00:00","yyyy-MM-dd HH:mm:ss"));
    ui->dateTimeEdit_2->setDateTime(QDateTime::currentDateTime());
    ui->lineEdit->setText("");
    ui->lineEdit_2->setText("");
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(0);
    SetHerader();
}
