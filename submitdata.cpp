#include "submitdata.h"
#include <QJsonDocument>
#include <QVariant>

SubmitData::SubmitData(string &url,QObject *parent)
	: QObject(parent)
{
	//formpost = NULL;
	lastptr = NULL;
	headerlist = NULL;
	//curl_slist_append(headerlist, "charset=utf-8");
	urlptr = &url;
	response="";
	curl_global_init(CURL_GLOBAL_ALL);
	curl = curl_easy_init();
	static const char buf[] = "Expect:";
	curl_slist_append(headerlist, buf);
	curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headerlist);
	curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, false); // if want to use https  
	curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, false); // set peer and host verify false  
	curl_easy_setopt(curl, CURLOPT_VERBOSE, 0);
	curl_easy_setopt(curl, CURLOPT_READFUNCTION, NULL);
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &req_reply);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&response);
	/*curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 1);*/
	curl_easy_setopt(curl, CURLOPT_HEADER, 0);
	curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT, 5); // set transport and time out time  
	curl_easy_setopt(curl, CURLOPT_TIMEOUT, 30);
}

size_t SubmitData::req_reply(void *ptr, size_t size, size_t nmemb, void *stream)
{
	//cout << "----->reply" << endl;
	string *str = (string*)stream;
	//cout << *str << endl;
	(*str).append((char*)ptr, size*nmemb);
	return size * nmemb;
}

void SubmitData::SetUrl(string &url)
{
	urlptr = &url;
}

void SubmitData::AppendText(QString name, QString value)
{
	string key = name.toStdString();
    string v = value.toUtf8().data();
	curl_formadd(&formpost,
		&lastptr,
		CURLFORM_COPYNAME, key.c_str(),
		CURLFORM_COPYCONTENTS, v.c_str() ,
		CURLFORM_END);
}

void SubmitData::AppendFile(QString name, QString path)
{
	string key = name.toStdString();
    string value = path.toLocal8Bit().data();
	curl_formadd(&formpost,
		&lastptr,
		CURLFORM_COPYNAME, key.c_str(),
		CURLFORM_FILE, value.c_str() ,
		CURLFORM_END);
}

void SubmitData::CleanForm()
{
	formpost = NULL;
	lastptr = NULL;
}

void SubmitData::Submit()
{
	string urlpath = "http://" + *urlptr + "/api/InformationServer/";
	curl_easy_setopt(curl, CURLOPT_URL, urlpath.c_str());
	curl_easy_setopt(curl, CURLOPT_HTTPPOST, formpost);

	//struct curl_slist *head = NULL;
	//head = curl_slist_append(head, "application/json; charset=utf-8");
	//curl_easy_setopt(curl, CURLOPT_HTTPHEADER, head);

	res = curl_easy_perform(curl);

	if (res != CURLE_OK)
	{
		response = curl_easy_strerror(res);
		result = false;
		return;
    }
	QJsonParseError e;
	QString jsonStr = QString::fromUtf8(response.data());

	QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonStr.toUtf8(), &e);
	if (e.error == QJsonParseError::NoError && !jsonDoc.isNull())
	{
		QVariantMap result = jsonDoc.toVariant().toMap();
		//auto a = result["err"].toBool();
		//ServerOk(true);
		//return;
	}
	result = true;

}

string SubmitData::Response()
{
	return response;
}

bool SubmitData::Result()
{
	return result;
}

void SubmitData::CustomSubmit(string api)
{
    string urlpath = "http://" + *urlptr + api;
    curl_easy_setopt(curl, CURLOPT_URL, urlpath.c_str());
    curl_easy_setopt(curl, CURLOPT_HTTPPOST, formpost);

    //struct curl_slist *head = NULL;
    //head = curl_slist_append(head, "application/json; charset=utf-8");
    //curl_easy_setopt(curl, CURLOPT_HTTPHEADER, head);

    res = curl_easy_perform(curl);

    if (res != CURLE_OK)
    {
        response = curl_easy_strerror(res);
        result = false;
        return;
    }

    result = true;
}



SubmitData::~SubmitData()
{
	curl_easy_cleanup(curl);
    if(formpost!=NULL)
    {
        formpost=NULL;
    }
}
