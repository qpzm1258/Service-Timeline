#include"idcardreader.h"
#include <thread>

#define filewlt   "photo.wlt"
#define filebmp   "photo.bmp"
#define filejpg   "photo.jpg"

namespace idreader
{

const char * gfolk[] = {
"汉",
"蒙古",
"回",
"藏",
"维吾尔",
"苗",
"彝",
"壮",
"布依",
"朝鲜",
"满",
"侗",
"瑶",
"白",
"土家",
"哈尼",
"哈萨克",
"傣",
"黎",
"傈僳",
"佤",
"畲",
"高山",
"拉祜",
"水",
"东乡",
"纳西",
"景颇",
"柯尔克孜",
"土",
"达斡尔",
"仫佬",
"羌",
"布朗",
"撒拉",
"毛南",
"仡佬",
"锡伯",
"阿昌",
"普米",
"塔吉克",
"怒",
"乌孜别克",
"俄罗斯",
"鄂温克",
"德昂",
"保安",
"裕固",
"京",
"塔塔尔",
"独龙",
"鄂伦春",
"赫哲",
"门巴",
"珞巴",
"基诺",
"其他",
"其他",
"其他",
"其他",
"其他",
"其他",
"其他",
"其他",
"其他",
"其他",
"其他",
"其他",
"其他",
"其他",
"其他",
"其他",
"其他",
"其他",
"其他",
"其他",
"其他",
"其他",
"其他",
"其他",
"其他",
"其他",
"其他",
"其他",
"其他",
"其他",
"其他",
"其他",
"其他",
"其他",
"其他",
"其他",
"其他",
"芒人",
"摩梭人",
"革家人",
"穿青人",
"入籍",
"其他族"
};

	long IDCardReader::LoadDll()
	{
		HDLL= LoadLibrary(TEXT("Sdtapi.dll"));
        HDLL_DEWLT=LoadLibrary(TEXT("Dewlt.dll"));
        if (HDLL == NULL || HDLL_DEWLT==NULL)
		{
			//errMessage = tr("Can not open Sdtapi.dll!").toStdString();
			errCode = -1;
			return errCode;
		}

		return 0;
	}

	long IDCardReader::LoadFunction()
	{
		if (LoadDll() != 0)
		{
			return errCode;
		}
		InitConnection= (InitComm)GetProcAddress(HDLL, "InitComm");
		AuthenticateIdCard =(Authenticate)GetProcAddress(HDLL, "Authenticate");
		ReadIDCard= (ReadBaseInfos)GetProcAddress(HDLL, "ReadBaseInfos");
		CloseConnection= (CloseComm)GetProcAddress(HDLL, "CloseComm");
        ReadBin= (SDT_ReadBaseMsg)GetProcAddress(HDLL, "SDT_ReadBaseMsg");
        Dewlt=(dewlt)GetProcAddress(HDLL_DEWLT, "dewlt");
        if (InitConnection == NULL || AuthenticateIdCard == NULL || ReadIDCard == NULL || CloseConnection == NULL || Dewlt==NULL)
		{
			//errMessage = tr("Can not load function!").toStdString();
			errCode = -2;
			return errCode;
		}

		return 0;
	}

	long IDCardReader::InitCon(int iPort)
	{
		if (LoadFunction() != 0)
		{
			return errCode;
		}

		if (InitConnection(iPort) != 1)
		{
			//errMessage = tr("Can not link to CardReader!").toStdString();
			errCode = -3;
			return errCode;
		}

		return 0;
	}

	long IDCardReader::CloseCon()
	{
		if (errCode == -2)
		{
			return errCode;
		}

		CloseConnection();

		return 0;
	}

	long IDCardReader::CheckIdCard(int iPort)
	{
		if (InitCon(iPort) != 0)
		{
			return errCode;
		}
		if (AuthenticateIdCard() != 1)
		{
			//errMessage = tr("Can not Find IDCard!").toStdString();
			errCode = -4;
			return errCode;
		}
		return 0;
	}

	long IDCardReader::ReadInfo(int iPort)
	{
		if (CheckIdCard(iPort) != 0)
		{
			return errCode;
		}

		char a[31];
        //char b[4];
        string b;
		char c[10];
		char d[9];
		char e[19];
		char f[71];
		char g[31];
		char h[9];
		char i[9];
//        if (ReadIDCard(a, b, c, d, e, f, g, h, i) != 1)
//        {
            //errMessage = tr("Can not Read IDCard Information!").toStdString();
//            errCode = -5;
//            return errCode;
//        }
//        CloseCon();
        if (CheckIdCard(iPort) != 0)
        {
            return errCode;
        }
//		name = a;
//		gender = b;
//		folk = c;
//		birthDay = d;
//		code = e;
//		address = f;
//		agency = g;
//		expireStart = h;
//		expireEnd = i;
        unsigned char uchRespond[256];
        unsigned char uchPHMsg[1024];
        unsigned int len1, len2;
        long ret = ReadBin(iPort, uchRespond, &len1, uchPHMsg, &len2, 0);
        if(ret==0x90)
        {
            ReadIDCardBaseInfo(uchRespond,uchPHMsg,len1,len2,a, &b, c, d, e, f, g, h, i);
            name = a;
            gender = b;
            folk = c;
            birthDay = d;
            code = e;
            address = f;
            agency = g;
            expireStart = h;
            expireEnd = i;

            long  (WINAPI *pSaveCardJPG)(unsigned char * pucCHMsg, unsigned int puiCHMsgLen, unsigned char * pucPHMsg, unsigned int  puiPHMsgLen, char * front, char *back);
            HINSTANCE hMyDll = LoadLibrary(TEXT("SavePhoto.dll"));
            pSaveCardJPG = (long (WINAPI *)(unsigned char * pucCHMsg, unsigned int 	puiCHMsgLen, unsigned char * pucPHMsg, unsigned int  puiPHMsgLen, char * front, char * back))GetProcAddress(hMyDll, "SaveCard2JPG");
            if (pSaveCardJPG != NULL)
            {
                char front[] = "1.jpg";
                char back[] = "2.jpg";
                char * p1=front;
                char * p2=back;

                pSaveCardJPG(uchRespond, len1, uchPHMsg, len2,p1, p2);
                FreeLibrary(hMyDll);
            }
        }
        else
        {
            errCode = -5;
            return errCode;
        }
        CloseCon();
		errCode = 0;
		//errMessage= tr("Read information finished!").toStdString();
		return 0;
	}

	bool IDCardReader::CheckCarderStatus()
	{
		if (InitCon() == 0)
		{
			return true;
		}
		return false;
	}

	IDCardReader::IDCardReader()
	{
        ReadInfo(1001);
        //std::thread t(&IDCardReader::ReadInfo, this,1001);
        //t.join();
	}
    IDCardReader::~IDCardReader()
    {
        if(HDLL!=NULL)
        {
            CloseCon();
            FreeLibrary(HDLL);
        }
        if(HDLL_DEWLT!=NULL)
        {
            FreeLibrary(HDLL_DEWLT);
        }
    }

    int IDCardReader::ReadIDCardBaseInfo(unsigned char *uchRespond, unsigned char * uchPHMsg, int len1, int len2,
                                 char * Name, string *Gender, char * Folk,
                                 char *BirthDay, char * Code, char * Address,
                                 char *Agency, char * ExpireStart, char* ExpireEnd)
    {
          //int type = 1;
          int i;

          FILE * fp = fopen ( filewlt, "wb+");
                              if ( !fp )return 0;
                              if (len2!=fwrite( (void *)uchPHMsg, 1, len2, fp ) ){
                                   fclose(fp);
                                   return 0;
                              }
          fclose(fp);
          if (Dewlt(filewlt) != 1)
          {
                return 0;
          }
          unsigned char * pChar= uchRespond;
          //int offset = 0;

          memset (Name, 0, 31);
          WideCharToMultiByte ( CP_ACP, 0, (LPCWSTR)pChar,
                              15, Name, 30, NULL, NULL);
          for ( i=29; i>0; i--)
          {
              if (Name[i] == 0x20)
                  Name[i] = 0x0;
              else
                  break;
          }
          pChar += 30;
          //sex
          //memset(Gender, 0, 4 );
          if (*pChar == 0x31)
              *Gender="男";
          else
              *Gender="女";
          pChar += 2;
          //folk
          char _folk[4];
          memset (_folk, 0, 4);
          WideCharToMultiByte (CP_ACP, 0, (LPCWSTR)pChar, 2, _folk, 2, NULL, NULL);
          const char * pfolk = gfolk[atoi( _folk) - 1];
          memset ( Folk, 0, 10 );
          memcpy ( (void*)Folk, (void*)pfolk, strlen(pfolk) );
          pChar += 4;

          //birth
          memset ( BirthDay, 0, 9 );
          WideCharToMultiByte (CP_ACP, 0, (LPCWSTR)pChar, 8, BirthDay, 8, NULL, NULL);
          pChar += 16;

          //addr
          memset (Address, 0, 71);
          WideCharToMultiByte (CP_ACP, 0, (LPCWSTR)pChar, 35, Address, 70, NULL, NULL);
          for (i=0; i<69; i++)
          {
              if (Address[i] == 0x20)
                  Address[i] = 0x0;
          }
          pChar += 70;

          memset (Code, 0, 19 );
          WideCharToMultiByte (CP_ACP, 0, (LPCWSTR)pChar, 18, Code, 18, NULL, NULL);
          pChar += 36;

          memset (Agency, 0, 31);
          WideCharToMultiByte (CP_ACP, 0, (LPCWSTR)pChar, 15, Agency, 30, NULL, NULL);
          pChar += 30;

          //2005-7-18 针对有效期截至日期问题（有长期表示方式）
          memset (ExpireStart, 0, 9);
          WideCharToMultiByte (CP_ACP, 0, (LPCWSTR)pChar, 8, ExpireStart, 8, NULL, NULL);
          pChar += 16;

          //有效期截至日期
          memset (ExpireEnd, 0, 9);
          WideCharToMultiByte (CP_ACP, 0, (LPCWSTR)pChar, 8, ExpireEnd, 8, NULL, NULL);
          return 1;
    }
}
