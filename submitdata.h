#pragma once

#include <QObject>
#include "curl\curl.h"
#include <string>
#ifdef _MSC_VER
    #pragma comment ( lib, "ws2_32.lib" )
    #pragma comment ( lib, "wldap32.lib" )
#endif
using namespace std;

class SubmitData : public QObject
{
	Q_OBJECT

public:
	SubmitData(string & url,QObject *parent);
	void SetUrl(string & url);

	~SubmitData();
private:
	CURL * curl;
	CURLcode res;

	bool result;

	struct curl_httppost *formpost;
	struct curl_httppost *lastptr;
	struct curl_slist *headerlist;
	std::string response;
	string * urlptr;

	static size_t req_reply(void * ptr, size_t size, size_t nmemb, void * stream);
public slots:
	void AppendText(QString name, QString value);
	void AppendFile(QString name, QString path);
	void CleanForm();
	void Submit();
    void CustomSubmit(string apiaddr);
	string Response();
	bool Result();
};
