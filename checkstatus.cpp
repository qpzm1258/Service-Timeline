#include "checkstatus.h"
#include <QJsonDocument>
#include <QVariant>
CheckStatus::CheckStatus(string &url,QObject *parent)
	: QObject(parent)
{
	this->url = &url;
}

CheckStatus::~CheckStatus()
{
}

void CheckStatus::OnTimeOut()
{
	curl_global_init(CURL_GLOBAL_ALL);

	// test get requery  
	string getUrlStr = *url+"/api/ServerStatus";
	string getResponseStr;
	auto res = curl_get_req(getUrlStr, getResponseStr);
	if (res == CURLE_OK)
	{
		QJsonParseError e;
		QString jsonStr = QString::fromUtf8(getResponseStr.data());

		QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonStr.toUtf8(), &e);
		if (e.error == QJsonParseError::NoError && !jsonDoc.isNull())
		{
			QVariantMap result = jsonDoc.toVariant().toMap();
			auto a = result["result"].toBool();
            ServerOk(a);
			return;
		}
		ServerOk(false);
	}
	else
	{
		ServerOk(false);
	}
}

size_t CheckStatus::req_reply(void *ptr, size_t size, size_t nmemb, void *stream)
{
	//cout << "----->reply" << endl;
	string *str = (string*)stream;
	//cout << *str << endl;
	(*str).append((char*)ptr, size*nmemb);
	return size * nmemb;
}

CURLcode CheckStatus::curl_get_req(const std::string &url, std::string &response)
{
	// init curl  
	CURL *curl = curl_easy_init();
	// res code  
    CURLcode res=CURLcode();
	if (curl)
	{
		// set params  
		curl_easy_setopt(curl, CURLOPT_URL, url.c_str()); // url  
		curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, false); // if want to use https  
		curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, false); // set peer and host verify false  
		curl_easy_setopt(curl, CURLOPT_VERBOSE, 0);
		curl_easy_setopt(curl, CURLOPT_READFUNCTION, NULL);
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &req_reply);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&response);
		curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 1);
		curl_easy_setopt(curl, CURLOPT_HEADER, 0);
		curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT, 3); // set transport and time out time  
		curl_easy_setopt(curl, CURLOPT_TIMEOUT, 3);
		// start req  
		res = curl_easy_perform(curl);
	}
	// release curl  
	curl_easy_cleanup(curl);
	return res;
}
