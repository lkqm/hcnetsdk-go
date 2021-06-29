#ifndef _HC_NET_SDK_H_
#define _HC_NET_SDK_H_

#ifndef _WINDOWS_
    #if (defined(_WIN32) || defined(_WIN64))
        #include <winsock2.h>
        #include <windows.h>
    #endif
#endif

#ifndef __PLAYRECT_defined
    #define __PLAYRECT_defined
    typedef struct __PLAYRECT
    {
        int x;
        int y;
        int uWidth;
        int uHeight;
    }PLAYRECT;
#endif

#if (defined(_WIN32)) //windows
    typedef  unsigned __int64   UINT64;
    typedef  signed   __int64   INT64;
#elif defined(__linux__) || defined(__APPLE__) //linux
    #define  BOOL  int
      #include <stdint.h>
      typedef uint32_t    DWORD;
      typedef uint16_t    WORD;
      typedef uint16_t    SHORT;
      typedef uint16_t    USHORT;
      typedef int32_t     LONG;
      typedef uint8_t     BYTE;
      typedef uint32_t    UINT;
      typedef void*       LPVOID;
      typedef void*       HANDLE;
      typedef uint32_t *  LPDWORD;
      typedef uint64_t    UINT64;

    #ifndef TRUE
        #define TRUE  1
    #endif
    #ifndef FALSE
        #define FALSE 0
    #endif
    #ifndef NULL
        #define NULL 0
    #endif

    #define __stdcall
    #define CALLBACK

    #define NET_DVR_API extern "C"
    typedef unsigned int   COLORKEY;
    typedef unsigned int   COLORREF;

    #ifndef __HWND_defined
        #define __HWND_defined
        #if defined(__linux__)
            typedef unsigned int HWND;
        #else
            typedef void* HWND;
        #endif
    #endif

    #ifndef __HDC_defined
        #define __HDC_defined
        #if defined(__linux__)
            typedef struct __DC
            {
                void*   surface;        //SDL Surface
                HWND    hWnd;           //HDC window handle
            }DC;
            typedef DC* HDC;
        #else
            typedef void* HDC;
        #endif
    #endif

    typedef struct tagInitInfo
    {
        int uWidth;
        int uHeight;
    }INITINFO;
#endif

#define SERIALNO_LEN            48      //���кų���
#define NET_DVR_DEV_ADDRESS_MAX_LEN 129
#define NET_DVR_LOGIN_USERNAME_MAX_LEN 64
#define NET_DVR_LOGIN_PASSWD_MAX_LEN 64


#define LIGHT_PWRON        2    /* ��ͨ�ƹ��Դ */
#define WIPER_PWRON        3    /* ��ͨ��ˢ���� */
#define FAN_PWRON        4    /* ��ͨ���ȿ��� */
#define HEATER_PWRON    5    /* ��ͨ���������� */
#define AUX_PWRON1        6    /* ��ͨ�����豸���� */
#define AUX_PWRON2        7    /* ��ͨ�����豸���� */
#define SET_PRESET        8    /* ����Ԥ�õ� */
#define CLE_PRESET        9    /* ���Ԥ�õ� */

#define ZOOM_IN            11    /* �������ٶ�SS���(���ʱ��) */
#define ZOOM_OUT        12    /* �������ٶ�SS��С(���ʱ�С) */
#define FOCUS_NEAR      13  /* �������ٶ�SSǰ�� */
#define FOCUS_FAR       14  /* �������ٶ�SS��� */
#define IRIS_OPEN       15  /* ��Ȧ���ٶ�SS���� */
#define IRIS_CLOSE      16  /* ��Ȧ���ٶ�SS��С */

#define TILT_UP            21    /* ��̨��SS���ٶ����� */
#define TILT_DOWN        22    /* ��̨��SS���ٶ��¸� */
#define PAN_LEFT        23    /* ��̨��SS���ٶ���ת */
#define PAN_RIGHT        24    /* ��̨��SS���ٶ���ת */
#define UP_LEFT            25    /* ��̨��SS���ٶ���������ת */
#define UP_RIGHT        26    /* ��̨��SS���ٶ���������ת */
#define DOWN_LEFT        27    /* ��̨��SS���ٶ��¸�����ת */
#define DOWN_RIGHT        28    /* ��̨��SS���ٶ��¸�����ת */
#define PAN_AUTO        29    /* ��̨��SS���ٶ������Զ�ɨ�� */

#define FILL_PRE_SEQ    30    /* ��Ԥ�õ����Ѳ������ */
#define SET_SEQ_DWELL    31    /* ����Ѳ����ͣ��ʱ�� */
#define SET_SEQ_SPEED    32    /* ����Ѳ���ٶ� */
#define CLE_PRE_SEQ        33    /* ��Ԥ�õ��Ѳ��������ɾ�� */
#define STA_MEM_CRUISE    34    /* ��ʼ��¼�켣 */
#define STO_MEM_CRUISE    35    /* ֹͣ��¼�켣 */
#define RUN_CRUISE        36    /* ��ʼ�켣 */
#define RUN_SEQ            37    /* ��ʼѲ�� */
#define STOP_SEQ        38    /* ֹͣѲ�� */
#define GOTO_PRESET        39    /* ����ת��Ԥ�õ� */

#define DEL_SEQ         43  /* ɾ��Ѳ��·�� */
#define STOP_CRUISE        44    /* ֹͣ�켣 */
#define DELETE_CRUISE    45    /* ɾ�������켣 */
#define DELETE_ALL_CRUISE 46/* ɾ�����й켣 */

#define PAN_CIRCLE      50   /* ��̨��SS���ٶ��Զ�Բ��ɨ�� */
#define DRAG_PTZ        51   /* �϶�PTZ */
#define LINEAR_SCAN     52   /* ����ɨ�� */ //2014-03-15
#define CLE_ALL_PRESET  53   /* Ԥ�õ�ȫ����� */
#define CLE_ALL_SEQ     54   /* Ѳ��ȫ����� */
#define CLE_ALL_CRUISE  55   /* �켣ȫ����� */

#define POPUP_MENU      56   /* ��ʾ�����˵� */

#define TILT_DOWN_ZOOM_IN    58    /* ��̨��SS���ٶ��¸�&&�������ٶ�SS���(���ʱ��) */
#define TILT_DOWN_ZOOM_OUT  59  /* ��̨��SS���ٶ��¸�&&�������ٶ�SS��С(���ʱ�С) */
#define PAN_LEFT_ZOOM_IN    60  /* ��̨��SS���ٶ���ת&&�������ٶ�SS���(���ʱ��)*/
#define PAN_LEFT_ZOOM_OUT   61  /* ��̨��SS���ٶ���ת&&�������ٶ�SS��С(���ʱ�С)*/
#define PAN_RIGHT_ZOOM_IN    62  /* ��̨��SS���ٶ���ת&&�������ٶ�SS���(���ʱ��) */
#define PAN_RIGHT_ZOOM_OUT  63  /* ��̨��SS���ٶ���ת&&�������ٶ�SS��С(���ʱ�С) */
#define UP_LEFT_ZOOM_IN     64  /* ��̨��SS���ٶ���������ת&&�������ٶ�SS���(���ʱ��)*/
#define UP_LEFT_ZOOM_OUT    65  /* ��̨��SS���ٶ���������ת&&�������ٶ�SS��С(���ʱ�С)*/
#define UP_RIGHT_ZOOM_IN    66  /* ��̨��SS���ٶ���������ת&&�������ٶ�SS���(���ʱ��)*/
#define UP_RIGHT_ZOOM_OUT   67  /* ��̨��SS���ٶ���������ת&&�������ٶ�SS��С(���ʱ�С)*/
#define DOWN_LEFT_ZOOM_IN   68  /* ��̨��SS���ٶ��¸�����ת&&�������ٶ�SS���(���ʱ��) */
#define DOWN_LEFT_ZOOM_OUT  69  /* ��̨��SS���ٶ��¸�����ת&&�������ٶ�SS��С(���ʱ�С) */
#define DOWN_RIGHT_ZOOM_IN    70  /* ��̨��SS���ٶ��¸�����ת&&�������ٶ�SS���(���ʱ��) */
#define DOWN_RIGHT_ZOOM_OUT    71  /* ��̨��SS���ٶ��¸�����ת&&�������ٶ�SS��С(���ʱ�С) */
#define TILT_UP_ZOOM_IN        72    /* ��̨��SS���ٶ�����&&�������ٶ�SS���(���ʱ��) */
#define TILT_UP_ZOOM_OUT    73

#define MAX_NAMELEN  16
#define NAME_LEN 32
#define PASSWD_LEN 16
#define MACADDR_LEN 6
#define MAX_USERNUM_V30 32  //9000设备最大用户数
#define MAX_RIGHT 32
#define MAX_CHANNUM_V30 64

#define MAX_ID_NUM_LEN                  32  //×î´óÉí·ÝÖ¤ºÅ³¤¶È
#define MAX_ID_NAME_LEN                 128   //×î´óÐÕÃû³¤¶È
#define MAX_ID_ADDR_LEN                 280   //×î´ó×¡Ö·³¤¶È
#define MAX_ID_ISSUING_AUTHORITY_LEN    128 //×î´óÇ©·¢»ú¹Ø³¤¶È



//NET_DVR_Login_V30()�����ṹ
typedef struct tagNET_DVR_DEVICEINFO_V30
{
    BYTE sSerialNumber[SERIALNO_LEN];  //���к�
    BYTE byAlarmInPortNum;                //�����������
    BYTE byAlarmOutPortNum;                //�����������
    BYTE byDiskNum;                    //Ӳ�̸���
    BYTE byDVRType;                    //�豸����, 1:DVR 2:ATM DVR 3:DVS ......
    BYTE byChanNum;                    //ģ��ͨ������
    BYTE byStartChan;                    //��ʼͨ����,����DVS-1,DVR - 1
    BYTE byAudioChanNum;                //����ͨ����
    BYTE byIPChanNum;                    //�������ͨ����������λ
    BYTE byZeroChanNum;            //��ͨ��������� //2010-01-16
    BYTE byMainProto;            //����������Э������ 0-private, 1-rtsp,2-ͬʱ֧��private��rtsp
    BYTE bySubProto;                //����������Э������0-private, 1-rtsp,2-ͬʱ֧��private��rtsp
    BYTE bySupport;
    BYTE bySupport1;
    BYTE bySupport2;
    WORD wDevType;
    BYTE bySupport3;
    BYTE byMultiStreamProto;//�Ƿ�֧�ֶ�����,��λ��ʾ,0-��֧��,1-֧��,bit1-����3,bit2-����4,bit7-��������bit-8������
    BYTE byStartDChan;        //��ʼ����ͨ����,0��ʾ��Ч
    BYTE byStartDTalkChan;    //��ʼ���ֶԽ�ͨ���ţ�������ģ��Խ�ͨ���ţ�0��ʾ��Ч
    BYTE byHighDChanNum;        //����ͨ����������λ
    BYTE bySupport4;
    BYTE byLanguageType;
    BYTE byVoiceInChanNum;   //��Ƶ����ͨ����
    BYTE byStartVoiceInChanNo; //��Ƶ������ʼͨ���� 0��ʾ��Ч
    BYTE  bySupport5;
    BYTE  bySupport6;
    BYTE  byMirrorChanNum;    //����ͨ��������<¼�����������ڱ�ʾ����ͨ��>
    WORD wStartMirrorChanNo;  //��ʼ����ͨ����
    BYTE bySupport7;
    BYTE  byRes2;        //����
}NET_DVR_DEVICEINFO_V30, *LPNET_DVR_DEVICEINFO_V30;

typedef struct tagNET_DVR_DEVICEINFO_V40
{
    NET_DVR_DEVICEINFO_V30 struDeviceV30;
    BYTE  bySupportLock;        //�豸֧���������ܣ����ֶ���SDK�����豸����ֵ����ֵ�ġ�bySupportLockΪ1ʱ��dwSurplusLockTime��byRetryLoginTime��Ч
    BYTE  byRetryLoginTime;        //ʣ��ɳ��Ե�½�Ĵ������û������������ʱ���˲�����Ч
    BYTE  byPasswordLevel;      //admin���밲ȫ�ȼ�0-��Ч��1-Ĭ�����룬2-��Ч����,3-���սϸߵ����롣���û�������Ϊ����Ĭ�����루12345�����߷��սϸߵ�����ʱ���ϲ�ͻ�����Ҫ��ʾ�û��������롣
    BYTE  byProxyType;  //�������ͣ�0-��ʹ�ô���, 1-ʹ��socks5����, 2-ʹ��EHome����
    DWORD dwSurplusLockTime;    //ʣ��ʱ�䣬��λ�룬�û�����ʱ���˲�����Ч
    BYTE  byCharEncodeType;     //�ַ���������
    BYTE  bySupportDev5;//֧��v50�汾���豸������ȡ���豸���ƺ��豸�������Ƴ�����չΪ64�ֽ�
    BYTE  bySupport;  //��������չ��λ������0- ��֧�֣�1- ֧��
    BYTE  byLoginMode; //��¼ģʽ 0-Private��¼ 1-ISAPI��¼
    DWORD dwOEMCode;
    int iResidualValidity;   //���û�����ʣ����Ч��������λ���죬���ظ�ֵ����ʾ�����Ѿ�����ʹ�ã����硰-3��ʾ�����Ѿ�����ʹ��3�족
    BYTE  byResidualValidity; // iResidualValidity�ֶ��Ƿ���Ч��0-��Ч��1-��Ч
    BYTE  byRes2[243];
}NET_DVR_DEVICEINFO_V40, *LPNET_DVR_DEVICEINFO_V40;

typedef void (*fLoginResultCallBack) (LONG lUserID, DWORD dwResult, LPNET_DVR_DEVICEINFO_V30 lpDeviceInfo , void* pUser);
typedef void (*REALDATACALLBACK) (LONG lPlayHandle, DWORD dwDataType, BYTE *pBuffer, DWORD dwBufSize, void* pUser);

typedef struct tagNET_DVR_USER_LOGIN_INFO
{
    char sDeviceAddress[NET_DVR_DEV_ADDRESS_MAX_LEN];
    BYTE byUseTransport;    //�Ƿ�����������͸����0--������͸����Ĭ�ϣ�1--����͸��
    WORD wPort;
    char sUserName[NET_DVR_LOGIN_USERNAME_MAX_LEN];
    char sPassword[NET_DVR_LOGIN_PASSWD_MAX_LEN];
    fLoginResultCallBack cbLoginResult;
    void *pUser;
    BOOL bUseAsynLogin;
    BYTE byProxyType; //0:��ʹ�ô���1��ʹ�ñ�׼����2��ʹ��EHome����
    BYTE byUseUTCTime;    //0-������ת����Ĭ��,1-�ӿ����������ȫ��ʹ��UTCʱ��,SDK���UTCʱ�����豸ʱ����ת��,2-�ӿ����������ȫ��ʹ��ƽ̨����ʱ�䣬SDK���ƽ̨����ʱ�����豸ʱ����ת��
    BYTE byLoginMode; //0-Private 1-ISAPI 2-����Ӧ
    BYTE byHttps;    //0-������tls��1-ʹ��tls 2-����Ӧ
    LONG iProxyID;    //�����������ţ���Ӵ����������Ϣʱ�����Ӧ�ķ����������±�ֵ
    BYTE byVerifyMode;  //��֤��ʽ��0-����֤��1-˫����֤��2-������֤����֤����ʹ��TLS��ʱ����Ч;
    BYTE byRes3[119];
}NET_DVR_USER_LOGIN_INFO,*LPNET_DVR_USER_LOGIN_INFO;

//ͼƬ����
typedef struct tagNET_DVR_JPEGPARA
{
    WORD    wPicSize;
    WORD    wPicQuality;            /* ͼƬ����ϵ�� 0-��� 1-�Ϻ� 2-һ�� */
}NET_DVR_JPEGPARA, *LPNET_DVR_JPEGPARA;

//�����Ԥ������
typedef struct tagNET_DVR_CLIENTINFO
{
    LONG lChannel;
    LONG lLinkMode;
    HWND hPlayWnd;
    char* sMultiCastIP;
    BYTE byProtoType;
    BYTE byRes[3];
}NET_DVR_CLIENTINFO, *LPNET_DVR_CLIENTINFO;

#define STREAM_ID_LEN   32

//Ԥ��V40�ӿ�
typedef struct tagNET_DVR_PREVIEWINFO
{
    LONG lChannel;
    DWORD dwStreamType;
    DWORD dwLinkMode;
    HWND hPlayWnd;
    DWORD bBlocked;
    DWORD bPassbackRecord;
    BYTE byPreviewMode;
    BYTE byStreamID[STREAM_ID_LEN];
    BYTE byProtoType;
    BYTE byRes1;
    BYTE byVideoCodingType;
    DWORD dwDisplayBufNum;
    BYTE byNPQMode;
    BYTE byRes[215];
}NET_DVR_PREVIEWINFO, *LPNET_DVR_PREVIEWINFO;



BOOL NET_DVR_Init();
BOOL NET_DVR_Cleanup();

LONG NET_DVR_Login_V30(char *sDVRIP, WORD wDVRPort, char *sUserName, char *sPassword, LPNET_DVR_DEVICEINFO_V30 lpDeviceInfo);
LONG NET_DVR_Login_V40(LPNET_DVR_USER_LOGIN_INFO pLoginInfo,LPNET_DVR_DEVICEINFO_V40 lpDeviceInfo);
BOOL NET_DVR_Logout(LONG lUserID);
BOOL NET_DVR_Logout_V30(LONG lUserID);

BOOL NET_DVR_SetConnectTime(DWORD dwWaitTime, DWORD dwTryTimes);
BOOL NET_DVR_SetReconnect(DWORD dwInterval, BOOL bEnableRecon);

BOOL NET_DVR_CaptureJPEGPicture(LONG lUserID, LONG lChannel, LPNET_DVR_JPEGPARA lpJpegPara, char *sPicFileName);
LONG NET_DVR_RealPlay_V30(LONG lUserID, LPNET_DVR_CLIENTINFO lpClientInfo, void(*fRealDataCallBack_V30) (LONG lRealHandle, DWORD dwDataType, BYTE *pBuffer, DWORD dwBufSize, void* pUser), void* pUser, BOOL bBlocked);
BOOL NET_DVR_ClosePreview(LONG lUserID, DWORD nSessionID);
BOOL NET_DVR_ClosePlayBack(LONG lUserID, DWORD nSessionID);
LONG NET_DVR_RealPlay_V40(LONG lUserID, LPNET_DVR_PREVIEWINFO lpPreviewInfo, REALDATACALLBACK fRealDataCallBack_V30, void* pUser);

BOOL NET_DVR_SaveRealData(LONG lRealHandle,char *sFileName);
BOOL NET_DVR_StopSaveRealData(LONG lRealHandle);

BOOL NET_DVR_PTZControlWithSpeed(LONG lRealHandle, DWORD dwPTZCommand, DWORD dwStop, DWORD dwSpeed);
BOOL NET_DVR_StopRealPlay(LONG lRealHandle);

DWORD NET_DVR_GetLastError();
char* NET_DVR_GetErrorMsg(LONG *pErrorNo);

BOOL NET_DVR_RebootDVR(LONG lUserID);
BOOL NET_DVR_RemoteControl(LONG lUserID, DWORD dwCommand, LPVOID lpInBuffer, DWORD dwInBufferSize);

// 消息回调
typedef struct tagNET_DVR_ALARMER{
  BYTE     byUserIDValid;
  BYTE     bySerialValid;
  BYTE     byVersionValid;
  BYTE     byDeviceNameValid;
  BYTE     byMacAddrValid;
  BYTE     byLinkPortValid;
  BYTE     byDeviceIPValid;
  BYTE     bySocketIPValid;
  LONG     lUserID;
  BYTE     sSerialNumber[SERIALNO_LEN];
  DWORD    dwDeviceVersion;
  char     sDeviceName[NAME_LEN];
  BYTE     byMacAddr[MACADDR_LEN];
  WORD     wLinkPort;
  char     sDeviceIP[128];
  char     sSocketIP[128];
  BYTE     byIpProtocol;
  BYTE     byRes2[11];
}NET_DVR_ALARMER,*LPNET_DVR_ALARMER;

typedef BOOL (*MSGCallBack)(LONG lCommand, NET_DVR_ALARMER *pAlarmer, char *pAlarmInfo, DWORD dwBufLen, void *pUser);
BOOL NET_DVR_SetDVRMessageCallBack_V30(MSGCallBack fMessageCallBack, void* pUser);
LONG NET_DVR_SetupAlarmChan_V30(LONG lUserID);
BOOL NET_DVR_CloseAlarmChan_V30(LONG lAlarmHandle);

// 异常消息
typedef void (*FExceptionCallBack)(DWORD dwType, LONG lUserID, LONG lHandle, void *pUser);
#ifdef _WIN32
BOOL NET_DVR_SetExceptionCallBack_V30(UINT nMessage, HWND hWnd, FExceptionCallBack  cbExceptionCallBack, void *pUser);
#elif defined(__linux__) || defined(__APPLE__)
BOOL NET_DVR_SetExceptionCallBack_V30(UINT nMessage, void* reserved2, FExceptionCallBack  cbExceptionCallBack, void *pUser);
#endif

//// 视频实时播放
//typedef struct tagNET_DVR_PREVIEWINFO
//{
//    LONG lChannel;//Í¨µÀºÅ
//    DWORD dwStreamType;    // ÂëÁ÷ÀàÐÍ£¬0-Ö÷ÂëÁ÷£¬1-×ÓÂëÁ÷£¬2-ÂëÁ÷3£¬3-ÂëÁ÷4, 4-ÂëÁ÷5,5-ÂëÁ÷6,7-ÂëÁ÷7,8-ÂëÁ÷8,9-ÂëÁ÷9,10-ÂëÁ÷10
//    DWORD dwLinkMode;// 0£ºTCP·½Ê½,1£ºUDP·½Ê½,2£º¶à²¥·½Ê½,3 - RTP·½Ê½£¬4-RTP/RTSP,5-RSTP/HTTP ,6- HRUDP£¨¿É¿¿´«Êä£© ,7-RTSP/HTTPS
//    HWND hPlayWnd;//²¥·Å´°¿ÚµÄ¾ä±ú,ÎªNULL±íÊ¾²»²¥·ÅÍ¼Ïó
//    DWORD bBlocked;  //0-·Ç×èÈûÈ¡Á÷, 1-×èÈûÈ¡Á÷, Èç¹û×èÈûSDKÄÚ²¿connectÊ§°Ü½«»áÓÐ5sµÄ³¬Ê±²ÅÄÜ¹»·µ»Ø,²»ÊÊºÏÓÚÂÖÑ¯È¡Á÷²Ù×÷.
//    DWORD bPassbackRecord; //0-²»ÆôÓÃÂ¼Ïñ»Ø´«,1ÆôÓÃÂ¼Ïñ»Ø´«
//    BYTE byPreviewMode;//Ô¤ÀÀÄ£Ê½£¬0-Õý³£Ô¤ÀÀ£¬1-ÑÓ³ÙÔ¤ÀÀ
//    BYTE byStreamID[STREAM_ID_LEN/*32*/];//Á÷ID£¬lChannelÎª0xffffffffÊ±ÆôÓÃ´Ë²ÎÊý
//    BYTE byProtoType; //Ó¦ÓÃ²ãÈ¡Á÷Ð­Òé£¬0-Ë½ÓÐÐ­Òé£¬1-RTSPÐ­Òé,2-SRTPÂëÁ÷¼ÓÃÜ£¨¶ÔÓ¦´Ë½á¹¹ÌåÖÐdwLinkMode ×Ö¶Î£¬Ö§³ÖÈçÏÂ·½Ê½, Îª1£¬±íÊ¾udp´«Êä·½Ê½£¬ÐÅÁî×ßTLS¼ÓÃÜ£¬ÂëÁ÷×ßSRTP¼ÓÃÜ£¬Îª2£¬±íÊ¾¶à²¥´«Êä·½Ê½£¬ÐÅÁî×ßTLS¼ÓÃÜ£¬ÂëÁ÷×ßSRTP¼ÓÃÜ£©
//    BYTE byRes1;
//    BYTE byVideoCodingType; //ÂëÁ÷Êý¾Ý±à½âÂëÀàÐÍ 0-Í¨ÓÃ±àÂëÊý¾Ý 1-ÈÈ³ÉÏñÌ½²âÆ÷²úÉúµÄÔ­Ê¼Êý¾Ý£¨ÎÂ¶ÈÊý¾ÝµÄ¼ÓÃÜÐÅÏ¢£¬Í¨¹ýÈ¥¼ÓÃÜÔËËã£¬½«Ô­Ê¼Êý¾ÝËã³öÕæÊµµÄÎÂ¶ÈÖµ£©
//    DWORD dwDisplayBufNum; //²¥·Å¿â²¥·Å»º³åÇø×î´ó»º³åÖ¡Êý£¬·¶Î§1-50£¬ÖÃ0Ê±Ä¬ÈÏÎª1
//    BYTE byNPQMode;	//NPQÊÇÖ±Á¬Ä£Ê½£¬»¹ÊÇ¹ýÁ÷Ã½Ìå 0-Ö±Á¬ 1-¹ýÁ÷Ã½Ìå
//    BYTE byRecvMetaData;  //ÊÇ·ñ½ÓÊÕmetadataÊý¾Ý£¬Éè±¸ÊÇ·ñÖ§³Ö¸Ã¹¦ÄÜÍ¨¹ýGET /ISAPI/System/capabilities ÖÐDeviceCap.SysCap.isSupportMetadataÊÇ·ñ´æÔÚÇÒÎªtrue
//    BYTE byRes[214];
//}NET_DVR_PREVIEWINFO, *LPNET_DVR_PREVIEWINFO;
//typedef void (*REALDATACALLBACK)(LONG lPlayHandle, DWORD dwDataType, BYTE *pBuffer, DWORD dwBufSize, void* pUser);
//LONG NET_DVR_RealPlay_V40(LONG lUserID, LPNET_DVR_PREVIEWINFO lpPreviewInfo, REALDATACALLBACK fRealDataCallBack_V30, void *pUser);

typedef  struct  tagNET_DVR_DATE
{
    WORD         wYear;
    BYTE        byMonth;
    BYTE         byDay;
}NET_DVR_DATE,*LPNET_DVR_DATE;


typedef struct tagNET_DVR_TIME
{
  DWORD    dwYear;
  DWORD    dwMonth;
  DWORD    dwDay;
  DWORD    dwHour;
  DWORD    dwMinute;
  DWORD    dwSecond;
}NET_DVR_TIME, *LPNET_DVR_TIME;
typedef struct tagNET_DVR_TIME_V30
{
    WORD wYear;
    BYTE byMonth;
    BYTE byDay;
    BYTE byHour;
    BYTE byMinute;
    BYTE bySecond;
    BYTE    byISO8601;
    WORD	wMilliSec;
    char    cTimeDifferenceH;
    char    cTimeDifferenceM;
}NET_DVR_TIME_V30, *LPNET_DVR_TIME_V30;
BOOL NET_DVR_SetDVRConfig(LONG lUserID, DWORD dwCommand, LONG lChannel, LPVOID lpInBuffer, DWORD dwInBufferSize);
BOOL NET_DVR_GetDVRConfig(LONG lUserID, DWORD dwCommand, LONG lChannel, LPVOID lpOutBuffer, DWORD dwOutBufferSize, LPDWORD lpBytesReturned);

typedef struct tagNET_DVR_XML_CONFIG_INPUT
{
    DWORD   dwSize;                     //½á¹¹Ìå´óÐ¡
    void*   lpRequestUrl;               //ÇëÇóÐÅÁî£¬×Ö·û´®¸ñÊ½
    DWORD   dwRequestUrlLen;            //ÇëÇóÐÅÁî³¤¶È£¬×Ö·û´®³¤¶È
    void*   lpInBuffer;                 //ÊäÈë²ÎÊý»º³åÇø£¬XML¸ñÊ½
    DWORD   dwInBufferSize;             //ÊäÈë²ÎÊý»º³åÇø´óÐ¡
    DWORD   dwRecvTimeOut;              //½ÓÊÕ³¬Ê±Ê±¼ä£¬µ¥Î»£ºms£¬Ìî0ÔòÊ¹ÓÃÄ¬ÈÏ³¬Ê±5s
    BYTE    byForceEncrpt;              //ÊÇ·ñÇ¿ÖÆ¼ÓÃÜ£¬0-·ñ£¬1-ÊÇ
    BYTE    byNumOfMultiPart;           //0-ÎÞÐ§£¬ÆäËûÖµ±íÊ¾±¨ÎÄ·Ö¶Î¸öÊý£¬·ÇÁãÊ±lpInBuffer´«ÈëµÄÊÇNET_DVR_MIME_UNIT½á¹¹ÌåÊý×éµÄÖ¸Õë£¬¸ÃÖµ¼´´ú±í½á¹¹Ìå¸öÊý
    BYTE    byRes[30];
}NET_DVR_XML_CONFIG_INPUT, *LPNET_DVR_XML_CONFIG_INPUT;

typedef struct tagNET_DVR_XML_CONFIG_OUTPUT
{
    DWORD   dwSize;                        //½á¹¹Ìå´óÐ¡
    void*    lpOutBuffer;                //Êä³ö²ÎÊý»º³åÇø£¬XML¸ñÊ½
    DWORD    dwOutBufferSize;            //Êä³ö²ÎÊý»º³åÇø´óÐ¡(ÄÚ´æ´óÐ¡)
    DWORD   dwReturnedXMLSize;            //Êµ¼ÊÊä³öµÄXMLÄÚÈÝ´óÐ¡
    void*    lpStatusBuffer;                //·µ»ØµÄ×´Ì¬²ÎÊý(XML¸ñÊ½),»ñÈ¡ÃüÁî³É¹¦Ê±²»»á¸³Öµ,Èç¹û²»ÐèÒª,¿ÉÒÔÖÃNULL
    DWORD    dwStatusSize;                //×´Ì¬»º³åÇø´óÐ¡(ÄÚ´æ´óÐ¡)
    BYTE    byRes[32];
}NET_DVR_XML_CONFIG_OUTPUT, *LPNET_DVR_XML_CONFIG_OUTPUT;
BOOL NET_DVR_STDXMLConfig(LONG lUserID, NET_DVR_XML_CONFIG_INPUT* lpInputParam, NET_DVR_XML_CONFIG_OUTPUT* lpOutputParam);

// 用户信息
typedef struct tagNET_DVR_IPADDR
{
    char    sIpV4[16];
    BYTE    sIpV6[128];
}NET_DVR_IPADDR, *LPNET_DVR_IPADDR;

typedef struct tagNET_DVR_USER_INFO_V30{
  BYTE                sUserName[NAME_LEN];
  BYTE                sPassword[PASSWD_LEN];
  BYTE                byLocalRight[MAX_RIGHT];
  BYTE                byRemoteRight[MAX_RIGHT];
  BYTE                byNetPreviewRight[MAX_CHANNUM_V30];
  BYTE                byLocalPlaybackRight[MAX_CHANNUM_V30];
  BYTE                byNetPlaybackRight[MAX_CHANNUM_V30];
  BYTE                byLocalRecordRight[MAX_CHANNUM_V30];
  BYTE                byNetRecordRight[MAX_CHANNUM_V30];
  BYTE                byLocalPTZRight[MAX_CHANNUM_V30];
  BYTE                byNetPTZRight[MAX_CHANNUM_V30];
  BYTE                byLocalBackupRight[MAX_CHANNUM_V30];
  NET_DVR_IPADDR      struUserIP;
  BYTE                byMACAddr[MACADDR_LEN];
  BYTE                byPriority;
  BYTE                byAlarmOnRight;
  BYTE                byAlarmOffRight;
  BYTE                byBypassRight;
  BYTE                byRes[14];
}NET_DVR_USER_INFO_V30,*LPNET_DVR_USER_INFO_V30;

typedef struct tagNET_DVR_USER_V30
{
    DWORD   dwSize;
    NET_DVR_USER_INFO_V30   struUser[MAX_USERNUM_V30];
}NET_DVR_USER_V30,*LPNET_DVR_USER_V30;

DWORD NET_DVR_GetSDKBuildVersion();
BOOL NET_DVR_SetLogToFile(DWORD nLogLevel, char *strLogDir, BOOL bAutoDel);

// 升级设备
typedef struct tagNET_DVR_UPGRADE_PARAM{
  DWORD    dwUpgradeType;
  char     *sFilename;
  void     *pInbuffer;
  DWORD    dwBufferLen;
  char     *pUnitIdList[64];
  BYTE     byRes[112];
}NET_DVR_UPGRADE_PARAM,*LPNET_DVR_UPGRADE_PARAM;
LONG NET_DVR_Upgrade_V50(LONG lUserID, NET_DVR_UPGRADE_PARAM lpUpgradeParam);
int NET_DVR_GetUpgradeState(LONG lUpgradeHandle);
BOOL NET_DVR_CloseUpgradeHandle(LONG lUpgradeHandle);

// 刷证
typedef struct tagNET_DVR_ID_CARD_INFO
{
    DWORD  dwSize;        //½á¹¹³¤¶È
    BYTE  byName[MAX_ID_NAME_LEN];   //ÐÕÃû
    NET_DVR_DATE struBirth; //³öÉúÈÕÆÚ
    BYTE byAddr[MAX_ID_ADDR_LEN];  //×¡Ö·
    BYTE byIDNum[MAX_ID_NUM_LEN];   //Éí·ÝÖ¤ºÅÂë
    BYTE byIssuingAuthority[MAX_ID_ISSUING_AUTHORITY_LEN];  //Ç©·¢»ú¹Ø
    NET_DVR_DATE struStartDate;  //ÓÐÐ§¿ªÊ¼ÈÕÆÚ
    NET_DVR_DATE struEndDate;  //ÓÐÐ§½ØÖ¹ÈÕÆÚ
    BYTE byTermOfValidity;  //ÊÇ·ñ³¤ÆÚÓÐÐ§£¬ 0-·ñ£¬1-ÊÇ£¨ÓÐÐ§½ØÖ¹ÈÕÆÚÎÞÐ§£©
    BYTE   bySex;  //ÐÔ±ð£¬1-ÄÐ£¬2-Å®
    BYTE  byNation;
    BYTE byRes[101];
}NET_DVR_ID_CARD_INFO, *LPNET_DVR_ID_CARD_INFO;

typedef struct tagNET_DVR_ID_CARD_INFO_ALARM
{
    DWORD  dwSize;        //½á¹¹³¤¶È
    NET_DVR_ID_CARD_INFO    struIDCardCfg ;//Éí·ÝÖ¤ÐÅÏ¢
    DWORD dwMajor; //±¨¾¯Ö÷ÀàÐÍ£¬²Î¿¼ºê¶¨Òå
    DWORD dwMinor; //±¨¾¯´ÎÀàÐÍ£¬²Î¿¼ºê¶¨Òå
    NET_DVR_TIME_V30  struSwipeTime; //Ê±¼ä
    BYTE    byNetUser[MAX_NAMELEN] ;//ÍøÂç²Ù×÷µÄÓÃ»§Ãû
    NET_DVR_IPADDR    struRemoteHostAddr ;//Ô¶³ÌÖ÷»úµØÖ·
    DWORD dwCardReaderNo; //¶Á¿¨Æ÷±àºÅ£¬Îª0ÎÞÐ§
    DWORD dwDoorNo; //ÃÅ±àºÅ£¬Îª0ÎÞÐ§
    DWORD dwPicDataLen;   //Í¼Æ¬Êý¾Ý´óÐ¡£¬²»Îª0ÊÇ±íÊ¾ºóÃæ´øÊý¾Ý
    char    *pPicData;
    BYTE byCardType; //¿¨ÀàÐÍ£¬1-ÆÕÍ¨¿¨£¬2-ÌØÊâÈºÌå¿¨£¬3-½ûÖ¹Ãûµ¥¿¨£¬4-Ñ²¸ü¿¨£¬5-Ð²ÆÈ¿¨£¬6-³¬¼¶¿¨£¬7-À´±ö¿¨£¬8-½â³ý¿¨£¬Îª0ÎÞÐ§
    BYTE byDeviceNo;                             // Éè±¸±àºÅ£¬Îª0Ê±ÎÞÐ§£¨ÓÐÐ§·¶Î§1-255£©
    BYTE byMask; //ÊÇ·ñ´ø¿ÚÕÖ£º0-±£Áô£¬1-Î´Öª£¬2-²»´÷¿ÚÕÖ£¬3-´÷¿ÚÕÖ
    BYTE byCurrentEvent; //ÊÇ·ñÎªÊµÊ±ÊÂ¼þ£º0-ÎÞÐ§£¬1-ÊÇ£¨ÊµÊ±ÊÂ¼þ£©£¬2-·ñ£¨ÀëÏßÊÂ¼þ£©
    DWORD dwFingerPrintDataLen;                  // Ö¸ÎÆÊý¾Ý´óÐ¡£¬²»Îª0ÊÇ±íÊ¾ºóÃæ´øÊý¾Ý
    char *pFingerPrintData;
    DWORD dwCapturePicDataLen;                   // ×¥ÅÄÍ¼Æ¬Êý¾Ý´óÐ¡£¬²»Îª0ÊÇ±íÊ¾ºóÃæ´øÊý¾Ý
    char *pCapturePicData;
    DWORD dwCertificatePicDataLen;   //Ö¤¼þ×¥ÅÄÍ¼Æ¬Êý¾Ý´óÐ¡£¬²»Îª0ÊÇ±íÊ¾ºóÃæ´øÊý¾Ý
    char    *pCertificatePicData;
    BYTE byCardReaderKind; //¶Á¿¨Æ÷ÊôÓÚÄÄÒ»Àà£¬0-ÎÞÐ§£¬1-IC¶Á¿¨Æ÷£¬2-Éí·ÝÖ¤¶Á¿¨Æ÷£¬3-¶þÎ¬Âë¶Á¿¨Æ÷,4-Ö¸ÎÆÍ·
    BYTE byHelmet;//¿ÉÑ¡£¬ÊÇ·ñ´÷°²È«Ã±£º0-±£Áô£¬1-Î´Öª£¬2-²»´÷°²È«, 3-´÷°²È«Ã±
    BYTE byRes3;
    BYTE    byIDCardInfoExtend;    //pIDCardInfoExtendÊÇ·ñÓÐÐ§£º0-ÎÞÐ§£¬1-ÓÐÐ§
    char    *pIDCardInfoExtend;    //byIDCardInfoExtendÎª1Ê±£¬±íÊ¾Ö¸ÏòÒ»¸öNET_DVR_ID_CARD_INFO_EXTEND½á¹¹Ìå
    DWORD dwSerialNo; //ÊÂ¼þÁ÷Ë®ºÅ£¬Îª0ÎÞÐ§
    BYTE byRes[168];
}NET_DVR_ID_CARD_INFO_ALARM, *LPNET_DVR_ID_CARD_INFO_ALARM;

// 人脸抓拍
//ÇøÓò¿ò½á¹¹
typedef struct tagNET_VCA_RECT
{
    float fX;               //±ß½ç¿ò×óÉÏ½ÇµãµÄXÖá×ø±ê, 0.000~1
    float fY;               //±ß½ç¿ò×óÉÏ½ÇµãµÄYÖá×ø±ê, 0.000~1
    float fWidth;           //±ß½ç¿òµÄ¿í¶È, 0.000~1
    float fHeight;          //±ß½ç¿òµÄ¸ß¶È, 0.000~1
}NET_VCA_RECT, *LPNET_VCA_RECT;

typedef struct tagNET_VCA_TARGET_INFO
{
    DWORD    dwID;                //Ä¿±êID ,ÈËÔ±¾Û¼¯¹ý¸ß±¨¾¯Ê±Îª0
    NET_VCA_RECT struRect;      //Ä¿±ê±ß½ç¿ò
    BYTE      byRes[4];            //±£Áô
}NET_VCA_TARGET_INFO, *LPNET_VCA_TARGET_INFO;

typedef struct tagNET_VCA_DEV_INFO
{
    NET_DVR_IPADDR  struDevIP; //Ç°¶ËÉè±¸µØÖ·£¬
    WORD wPort;             //Ç°¶ËÉè±¸¶Ë¿ÚºÅ£¬
    BYTE byChannel;          //Ç°¶ËÉè±¸Í¨µÀ£¬
    BYTE byIvmsChannel;        // Ivms Í¨µÀ
}NET_VCA_DEV_INFO, *LPNET_VCA_DEV_INFO;

typedef struct tagNET_VCA_HUMAN_FEATURE
{
    BYTE byAgeGroup;    //ÄêÁä¶Î,²Î¼û HUMAN_AGE_GROUP_ENUM
    BYTE bySex;         //ÐÔ±ð, 0-±íÊ¾¡°Î´Öª¡±£¨Ëã·¨²»Ö§³Ö£©,1 ¨C ÄÐ , 2 ¨C Å®, 0xff-Ëã·¨Ö§³Ö£¬µ«ÊÇÃ»ÓÐÊ¶±ð³öÀ´
    BYTE byEyeGlass;    //ÊÇ·ñ´÷ÑÛ¾µ 0-±íÊ¾¡°Î´Öª¡±£¨Ëã·¨²»Ö§³Ö£©,1 ¨C²»´÷, 2 ¨C´÷ÑÛ¾µ, 3 ¨C´÷Ä«¾µ,0xff-Ëã·¨Ö§³Ö£¬µ«ÊÇÃ»ÓÐÊ¶±ð³öÀ´
    //×¥ÅÄÍ¼Æ¬ÈËÁ³ÄêÁäµÄÊ¹ÓÃ·½Ê½£¬ÈçbyAgeÎª15,byAgeDeviationÎª1,±íÊ¾£¬Êµ¼ÊÈËÁ³Í¼Æ¬ÄêÁäµÄÎª14-16Ö®¼ä
    BYTE byAge;//ÄêÁä 0-±íÊ¾¡°Î´Öª¡±£¨Ëã·¨²»Ö§³Ö£©,0xff-Ëã·¨Ö§³Ö£¬µ«ÊÇÃ»ÓÐÊ¶±ð³öÀ´
    BYTE byAgeDeviation;//ÄêÁäÎó²îÖµ
    BYTE byRes0;
    BYTE byMask;       //ÊÇ·ñ´÷¿ÚÕÖ 0-±íÊ¾¡°Î´Öª¡±£¨Ëã·¨²»Ö§³Ö£©,1 ¨C ²»´÷, 2 ¨C ´÷, 0xff-Ëã·¨Ö§³Ö£¬µ«ÊÇÃ»ÓÐÊ¶±ð³öÀ´
    BYTE bySmile;      //ÊÇ·ñÎ¢Ð¦ 0-±íÊ¾¡°Î´Öª¡±£¨Ëã·¨²»Ö§³Ö£©,1 ¨C ²»Î¢Ð¦, 2 ¨C Î¢Ð¦, 0xff-Ëã·¨Ö§³Ö£¬µ«ÊÇÃ»ÓÐÊ¶±ð³öÀ´
    BYTE byFaceExpression;    /* ±íÇé,²Î¼ûFACE_EXPRESSION_GROUP_ENUM*/
    BYTE byRes1;
    BYTE byRes2;
    BYTE byHat; // Ã±×Ó, 0-²»Ö§³Ö,1-²»´÷Ã±×Ó,2-´÷Ã±×Ó, 3-Í·¿ø 0xff-unknow±íÊ¾Î´Öª,Ëã·¨Ö§³ÖÎ´¼ì³ö
    BYTE byRes[4];    //±£Áô
}NET_VCA_HUMAN_FEATURE ,*LPNET_VCA_HUMAN_FEATURE;

//ÈËÁ³×¥ÅÄ½á¹û
typedef struct tagNET_VCA_FACESNAP_RESULT
{
    DWORD   dwSize;             // ½á¹¹´óÐ¡
    DWORD     dwRelativeTime;     // Ïà¶ÔÊ±±ê
    DWORD    dwAbsTime;            // ¾ø¶ÔÊ±±ê
    DWORD   dwFacePicID;       //ÈËÁ³Í¼ID
    DWORD   dwFaceScore;        //ÈËÁ³ÆÀ·Ö,0-100
    NET_VCA_TARGET_INFO  struTargetInfo;//±¨¾¯Ä¿±êÐÅÏ¢
    NET_VCA_RECT         struRect;      //ÈËÁ³×ÓÍ¼ÇøÓò
    NET_VCA_DEV_INFO       struDevInfo;    //Ç°¶ËÉè±¸ÐÅÏ¢
    DWORD   dwFacePicLen;        //ÈËÁ³×ÓÍ¼µÄ³¤¶È£¬Îª0±íÊ¾Ã»ÓÐÍ¼Æ¬£¬´óÓÚ0±íÊ¾ÓÐÍ¼Æ¬
    DWORD   dwBackgroundPicLen; //±³¾°Í¼µÄ³¤¶È£¬Îª0±íÊ¾Ã»ÓÐÍ¼Æ¬£¬´óÓÚ0±íÊ¾ÓÐÍ¼Æ¬(±£Áô)
    BYTE    bySmart;            //IDSÉè±¸·µ»Ø0(Ä¬ÈÏÖµ)£¬Smart Functiom Return 1
    BYTE    byAlarmEndMark;//±¨¾¯½áÊø±ê¼Ç0-±£Áô£¬1-½áÊø±ê¼Ç£¨¸Ã×Ö¶Î½áºÏÈËÁ³ID×Ö¶ÎÊ¹ÓÃ£¬±íÊ¾¸ÃID¶ÔÓ¦µÄÏÂ±¨¾¯½áÊø£¬Ö÷ÒªÌá¹©¸øNVRÊ¹ÓÃ£¬ÓÃÓÚÅÐ¶Ï±¨¾¯½áÊø£¬ÌáÈ¡Ê¶±ðÍ¼Æ¬Êý¾ÝÖÐ£¬ÇåÎú¶È×î¸ßµÄÍ¼Æ¬£©
    BYTE    byRepeatTimes;   //ÖØ¸´±¨¾¯´ÎÊý£¬0-ÎÞÒâÒå
    BYTE    byUploadEventDataType;//ÈËÁ³Í¼Æ¬Êý¾Ý³¤´«·½Ê½£º0-¶þ½øÖÆÊý¾Ý£¬1-URL
    NET_VCA_HUMAN_FEATURE   struFeature;  //ÈËÌåÊôÐÔ
    float   fStayDuration;  //Í£Áô»­ÃæÖÐÊ±¼ä(µ¥Î»: Ãë)
    char    sStorageIP[16];        //´æ´¢·þÎñIPµØÖ·
    WORD    wStoragePort;            //´æ´¢·þÎñ¶Ë¿ÚºÅ
    WORD    wDevInfoIvmsChannelEx;     //ÓëNET_VCA_DEV_INFOÀïµÄbyIvmsChannelº¬ÒåÏàÍ¬£¬ÄÜ±íÊ¾¸ü´óµÄÖµ¡£ÀÏ¿Í»§¶ËÓÃbyIvmsChannelÄÜ¼ÌÐø¼æÈÝ£¬µ«ÊÇ×î´óµ½255¡£ÐÂ¿Í»§¶Ë°æ±¾ÇëÊ¹ÓÃwDevInfoIvmsChannelEx¡£
    /*ÈËÁ³×ÓÍ¼Í¼Æ¬ÖÊÁ¿ÆÀ¹ÀµÈ¼¶£¬0-µÍµÈÖÊÁ¿,1-ÖÐµÈÖÊÁ¿,2-¸ßµÈÖÊÁ¿,
    ÐÂÔöÈËÁ³×¥ÅÄÖÊÁ¿ÆÀ·Ö»úÖÆÓëÔ­ÓÐµÄÈËÁ³ÆÀ·ÖÇø±ð£º
    Ô­ÓÐµÄÈËÁ³ÆÀ·ÖÊÇÔÚÈËÁ³×¥ÅÄÖÐÊµÏÖ£¬Ä¿µÄÊÇÈ·±£Ò»´ÎÈËÁ³×¥ÅÄÖÐ»ñÈ¡×îºÃµÄÍ¼ÏñÐ§¹û£¬ÊÇÒ»¸öÏà¶ÔÍ¼ÏñÖÊÁ¿µÄÆÀ·Ö£»ÐÂÔöÈËÁ³×¥ÅÄÖÊÁ¿ÆÀ·Ö»úÖÆÊÇÕë¶ÔÒÑ¾­×¥ÅÄÍê³ÉµÄÈËÁ³Í¼Æ¬£¬Ê¹ÓÃÍ¼ÏñËã·¨¶ÔÍ¼ÏñÖÐÈËÁ³£¬ÈËÑÛ£¬¼ç¿íµÈÏà¶ÔÖØÒªµÄÐÅÏ¢½øÐÐ·ÖÎö£¬°´ÕÕÍ³Ò»µÄ±ê×¼¶ÔÈËÁ³Í¼Æ¬Ð§¹ûÖÊÁ¿½øÐÐÆÀ·Ö*/
    BYTE    byFacePicQuality;
    BYTE    byUIDLen;     // ÉÏ´«±¨¾¯µÄ±êÊ¶³¤¶È
    BYTE    byLivenessDetectionStatus;// »îÌå¼ì²â×´Ì¬£º0-±£Áô£¬1-Î´Öª(¼ì²âÊ§°Ü)£¬2-·ÇÕæÈËÈËÁ³£¬3-ÕæÈËÈËÁ³£¬4-Î´¿ªÆô»îÌå¼ì²â
    /*¸½¼ÓÐÅÏ¢±êÊ¶Î»£¨¼´ÊÇ·ñÓÐNET_VCA_FACESNAP_ADDINFO½á¹¹Ìå£©,0-ÎÞ¸½¼ÓÐÅÏ¢, 1-ÓÐ¸½¼ÓÐÅÏ¢¡£*/
    BYTE    byAddInfo;
    BYTE    *pUIDBuffer;  //±êÊ¶Ö¸Õë
    //¸½¼ÓÐÅÏ¢Ö¸Õë,Ö¸ÏòNET_VCA_FACESNAP_ADDINFO½á¹¹Ìå
    BYTE   *pAddInfoBuffer;
    BYTE    byTimeDiffFlag;      /*Ê±²î×Ö¶ÎÊÇ·ñÓÐÐ§  0-Ê±²îÎÞÐ§£¬ 1-Ê±²îÓÐÐ§ */
    char    cTimeDifferenceH;         /*ÓëUTCµÄÊ±²î£¨Ð¡Ê±£©£¬-12 ... +14£¬ +±íÊ¾¶«Çø,£¬byTimeDiffFlagÎª1Ê±ÓÐÐ§*/
    char    cTimeDifferenceM;      	/*ÓëUTCµÄÊ±²î£¨·ÖÖÓ£©£¬-30, 30, 45£¬ +±íÊ¾¶«Çø£¬byTimeDiffFlagÎª1Ê±ÓÐÐ§*/
    BYTE    byBrokenNetHttp;     //¶ÏÍøÐø´«±êÖ¾Î»£¬0-²»ÊÇÖØ´«Êý¾Ý£¬1-ÖØ´«Êý¾Ý
    BYTE*   pBuffer1;  //ÈËÁ³×ÓÍ¼µÄÍ¼Æ¬Êý¾Ý
    BYTE*   pBuffer2;  //±³¾°Í¼µÄÍ¼Æ¬Êý¾Ý£¨±£Áô£¬Í¨¹ý²éÕÒ±³¾°Í¼½Ó¿Ú¿ÉÒÔ»ñÈ¡±³¾°Í¼£©
}NET_VCA_FACESNAP_RESULT, *LPNET_VCA_FACESNAP_RESULT;


#endif