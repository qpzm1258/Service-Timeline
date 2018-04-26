#ifndef IDCARDMESSAGE_H
#define IDCARDMESSAGE_H

#include <QString>
#include <string>
#include "idcardreader.h"

using namespace std;
using namespace idreader;
class IdCardMessage
{
public:
    QString name;
    QString gender;
    QString folk;
    QString birthDay;
    QString code;
    QString address;
    QString agency;
    QString expireStart;
    QString expireEnd;
    IdCardMessage();
    void GetMessageFormIdCardReader(IDCardReader reader);
    void clear();
};

#endif // IDCARDMESSAGE_H
