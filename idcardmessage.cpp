#include "idcardmessage.h"
#include <QMessageBox>
#include <QWidget>

IdCardMessage::IdCardMessage()
{
    name="";
    gender="";
    folk="";
    birthDay="";
    code="";
    address="";
    agency="";
    expireStart="";
    expireEnd="";
}

void IdCardMessage::GetMessageFormIdCardReader(IDCardReader reader)
{
    if(reader.name!="")
    {
        //QWidget *w=new QWidget();
        name=QString::fromLocal8Bit(reader.name.c_str()).replace(" ", "");
        //QMessageBox::critical(w,"test",name);

    }
    if(reader.gender!="")
    {
        gender=QString::fromStdString(reader.gender.data()).replace(" ", "");
        //QMessageBox::critical(w,"test",gender);
    }
    if(reader.folk!="")
    {
        folk=QString::fromUtf8(reader.folk.data()).replace(" ", "");
    //    //QMessageBox::critical(w,"test",folk);
    }
    if(reader.birthDay!="")
    {
        birthDay=QString::fromLocal8Bit(reader.birthDay.c_str()).replace(" ", "");
        //QMessageBox::critical(w,"test",birthDay);
    }
    if(reader.code!="")
    {
        code=QString::fromLocal8Bit(reader.code.c_str()).replace(" ", "");
        //QMessageBox::critical(w,"test",code);
    }
    if(reader.address!="")
    {
        address=QString::fromLocal8Bit(reader.address.c_str()).replace(" ", "");
        //QMessageBox::critical(w,"test",address);
    }
    if(reader.agency!="")
    {
        agency=QString::fromLocal8Bit(reader.agency.c_str()).replace(" ", "");
        //QMessageBox::critical(w,"test",agency);
    }
    if(reader.expireStart!="")
    {
        expireStart=QString::fromLocal8Bit(reader.expireStart.c_str()).replace(" ", "");
        //QMessageBox::critical(w,"test",expireStart);
    }
    if(reader.expireEnd!="")
    {
        expireEnd=QString::fromLocal8Bit(reader.expireEnd.c_str()).replace(" ", "");
        //QMessageBox::critical(w,"test",expireEnd);
    }
}

void IdCardMessage::clear()
{
    name="";
    gender="";
    folk="";
    birthDay="";
    code="";
    address="";
    agency="";
    expireStart="";
    expireEnd="";
}


