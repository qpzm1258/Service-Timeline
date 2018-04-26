#pragma once

#include <QObject>
#include <string>
#include "curl\curl.h"

using namespace std;
class CheckStatus : public QObject
{
	Q_OBJECT

public:
	CheckStatus(string &url,QObject *parent);
	~CheckStatus();
	static size_t req_reply(void * ptr, size_t size, size_t nmemb, void * stream);
	CURLcode curl_get_req(const std::string & url, std::string & response);
private:
	string * url;
public slots:
	void OnTimeOut();
signals:
	void ServerOk(bool);
};
