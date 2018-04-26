#pragma once
#include <string>
#include <Windows.h>
//#include <QtWidgets/QMainWindow>
#ifdef _MSC_VER
    #pragma execution_character_set("utf-8")
#endif

using namespace std;
namespace idreader {

	class IDCardReader
	{
		//Q_OBJECT
		typedef long (WINAPI *ReadBaseInfos)(char* Name, char* Gender, char* Folk, char* BirthDay, char* Code, char* Address, char* Agency, char* ExpireStart, char* ExpireEnd);
		typedef long (WINAPI *InitComm)(int iPort);
		typedef long (WINAPI *Authenticate)();
		typedef long (WINAPI *CloseComm)();
        typedef long (WINAPI *SDT_ReadBaseMsg)(int iPortID,unsigned char * pucCHMsg,unsigned int *	puiCHMsgLen,unsigned char * pucPHMsg,unsigned int  *puiPHMsgLen,int iIfOpen);
        typedef int (WINAPI *dewlt)(char *dewltPath);

	public:
		string name;
		string gender;
		string folk;
		string birthDay;
		string code;
		string address;
		string agency;
		string expireStart;
		string expireEnd;
		bool done;
		string errMessage;
		long errCode;
	private:
		HINSTANCE HDLL;
        HINSTANCE HDLL_DEWLT;
		InitComm InitConnection;
		Authenticate AuthenticateIdCard;
		CloseComm CloseConnection;
		ReadBaseInfos ReadIDCard;
        SDT_ReadBaseMsg ReadBin;
        dewlt Dewlt;

	public:
		IDCardReader();
        ~IDCardReader();
		bool CheckCarderStatus();
		long InitCon(int iPort=1001);
		long CheckIdCard(int iPort = 1001);
		long ReadInfo(int iPort = 1001);
        int ReadIDCardBaseInfo(unsigned char *uchRespond,unsigned char * uchPHMsg,int len1,int len2,
                                     char * Name, string *Gender, char * Folk,
                                     char *BirthDay, char * Code, char * Address,
                                     char *Agency, char * ExpireStart,char* ExpireEnd);
		long CloseCon();
	private:
		long LoadDll();
		long LoadFunction();
	};
}
