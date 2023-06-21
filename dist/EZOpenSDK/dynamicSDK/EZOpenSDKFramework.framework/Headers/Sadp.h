#ifndef _SADP_H_
#define _SADP_H_


#if defined _WIN32 || defined _WIN64
#define CSADP_API  extern "C" __declspec(dllimport)
#elif defined __linux__ || defined __APPLE__
#define CSADP_API  extern "C"
#endif

#if defined _WIN32 || defined _WIN64
#define CALLBACK __stdcall
#elif defined __linux__ || defined __APPLE__
#define CALLBACK  
#endif

#define     BOOL int

//��Ϣ����������
#define SADP_ADD          1         //����һ�豸
#define SADP_UPDATE       2         //�����豸
#define SADP_DEC          3         //�豸����
#define SADP_RESTART      4         //�豸��������
#define SADP_UPDATEFAIL   5         //�豸����ʧ��

//�ⲿ������
#define SADP_GET_DEVICE_CODE                1   //��ȡ�豸�룬��Ӧ�ṹ��SADP_SAFE_CODE
#define SADP_GET_ENCRYPT_STRING             2   //��ȡ���ܴ�����Ӧ�ṹ��SADP_ENCRYPT_STRING
#define SADP_GET_DEVICE_TYPE_UNLOCK_CODE    3   //��ȡ�豸���ͽ���룬��Ӧ�Ľṹ��SADP_TYPE_UNLOCK_CODE
#define SADP_SET_DEVICE_CUSTOM_TYPE         4   //�����豸�Զ����ͺţ���Ӧ�Ľṹ��SADP_CUSTOM_DEVICE_TYPE
#define SADP_GET_GUID                       5   //��ȡGUID
#define SADP_GET_SECURITY_QUESTION          6   //��ȡ��ȫ����
#define SADP_SET_SECURITY_QUESTION          7   //���ð�ȫ����
#define SADP_SET_HCPLATFORM_STATUS          8   //����HCPLATFORM״̬
#define SADP_SET_VERIFICATION_CODE          9   //������֤�루��֤������өʯ���롢Ԥ�������Ƶ�Ψһ���룩
#define SADP_GET_BIND_LIST                  12  //��ȡ���豸�б�
#define SADP_SET_BIND_LIST                  13  //���ð��豸�б�
#define SADP_RESTORE_INACTIVE               14  //�ָ�δ����
#define SADP_SET_WIFI_REGION                15  //����wifi����
#define SADP_SET_CHANNEL_DEFAULT_PASSWORD   16  //����ͨ��Ĭ������
#define SADP_GET_SELF_CHECK                 17  //��ȡ�豸�Լ�״̬
#define SADP_DISK_LOCATE                    18  //���̶�λ
#define SADP_EHOME_ENABLE                   19  //EHomeʹ��
#define SADP_SET_USER_MAILBOX               20  //�����û�����
#define SADP_GET_QR_CODES                   21  //��ȡ��ά������
#define SADP_GET_PASSWORD_RESET_TYPE        27  //��ȡ�������뷽ʽ����
#define SADP_SET_EZVIZ_USER_TOKEN           28  //����өʯ�û�token



#define SADP_MAX_VERIFICATION_CODE_LEN  12   //�����֤�볤��
#define MAX_PASS_LEN                    16   //�豸������볤��
#define MAX_QUESTION_LIST_LEN           32   //��������б����
#define SADP_MAX_BIND_NUM               32   //�����豸����
#define MAX_CPU_LEN                     32   //CPU����
#define MAX_MEMORY_LEN                  32   //�ڴ泤��
#define MAX_USERNAME_LEN                32   //�û�����󳤶�
#define SADP_MAX_SERIALNO_LEN           64   //����豸���кų���
#define MAX_DEVICE_CODE                 128  //�豸�����볤�ȣ��ݶ����128
#define MAX_MAILBOX_LEN                 128  //���䳤�ȣ��ݶ����128
#define MAX_GUID_LEN                    128  //GUID����
#define MAX_EXCHANGE_CODE               256  //�����볤��
#define MAX_ENCRYPT_CODE                256  //�豸��������ܺ󳤶�
#define MAX_UNLOCK_CODE_KEY             256  //�����Կ
#define MAX_QR_CODES                    256  //��ά�����ݳ��ȣ��ݶ����256
#define MAX_ANSWER_LEN                  256  //���𰸳���
#define MAX_UNLOCK_CODE_RANDOM_LEN      256  //����������
#define MAX_FILE_PATH_LEN               260  //�ļ����·������
#define MAX_TOKEN_LEN                   16   //өʯ�û�token��󳤶�




// ������
#define SADP_ERROR_BASE                 2000
#define SADP_NOERROR                    0                     // û�д���
#define SADP_ALLOC_RESOURCE_ERROR       (SADP_ERROR_BASE+1)   // ��Դ�������
#define SADP_NOT_START_ERROR            (SADP_ERROR_BASE+2)   // SADPδ����
#define SADP_NO_ADAPTER_ERROR           (SADP_ERROR_BASE+3)   // ������
#define SADP_GET_ADAPTER_FAIL_ERROR     (SADP_ERROR_BASE+4)   // ��ȡ������Ϣʧ��
#define SADP_PARAMETER_ERROR            (SADP_ERROR_BASE+5)   // ��������
#define SADP_OPEN_ADAPTER_FAIL_ERROR    (SADP_ERROR_BASE+6)   // ������ʧ��
#define SADP_SEND_PACKET_FAIL_ERROR     (SADP_ERROR_BASE+7)   // ��������ʧ��
#define SADP_SYSTEM_CALL_ERROR          (SADP_ERROR_BASE+8)   // ϵͳ�ӿڵ���ʧ��
#define SADP_DEVICE_DENY                (SADP_ERROR_BASE+9)   // �豸�ܾ�����
#define SADP_NPF_INSTALL_ERROR          (SADP_ERROR_BASE+10)  // ��װNPF����ʧ��
#define SADP_TIMEOUT                    (SADP_ERROR_BASE+11)  // �豸��ʱ
#define SADP_CREATE_SOCKET_ERROR        (SADP_ERROR_BASE+12)  // ����socketʧ��
#define SADP_BIND_SOCKET_ERROR          (SADP_ERROR_BASE+13)  // ��socketʧ��
#define SADP_JOIN_MULTI_CAST_ERROR      (SADP_ERROR_BASE+14)  // ����ಥ��ʧ��
#define SADP_NETWORK_SEND_ERROR         (SADP_ERROR_BASE+15)  // ���ͳ���
#define SADP_NETWORK_RECV_ERROR         (SADP_ERROR_BASE+16)  // ���ճ���
#define SADP_XML_PARSE_ERROR            (SADP_ERROR_BASE+17)  // �ಥXML��������
#define SADP_LOCKED                     (SADP_ERROR_BASE+18)  // �豸����
#define SADP_NOT_ACTIVATED              (SADP_ERROR_BASE+19)  // �豸δ����
#define SADP_RISK_PASSWORD              (SADP_ERROR_BASE+20)  // ���ոߵ�����
#define SADP_HAS_ACTIVATED              (SADP_ERROR_BASE+21)  // �豸�Ѽ���
#define SADP_EMPTY_ENCRYPT_STRING       (SADP_ERROR_BASE+22)  // ���ܴ�Ϊ��
#define SADP_EXPORT_FILE_OVERDUE        (SADP_ERROR_BASE+23)  // �����ļ�����
#define SADP_PASSWORD_ERROR             (SADP_ERROR_BASE+24)  // �������
#define SADP_LONG_SECURITY_ANSWER       (SADP_ERROR_BASE+25)  // ��ȫ�����̫��
#define SADP_INVALID_GUID               (SADP_ERROR_BASE+26)  // ��Ч��GUID
#define SADP_ANSWER_ERROR               (SADP_ERROR_BASE+27)  // �𰸴���
#define SADP_QUESTION_NUM_ERR           (SADP_ERROR_BASE+28)  // ��ȫ����������ô���
#define SADP_LOAD_WPCAP_FAIL            (SADP_ERROR_BASE+30)  // ����Wpcapʧ��
#define SADP_ILLEGAL_VERIFICATION_CODE  (SADP_ERROR_BASE+33)  // �Ƿ���֤��
#define SADP_BIND_ERROR_DEV             (SADP_ERROR_BASE+34)  // �󶨴�����豸
#define SADP_EXTED_MAX_BIND_NUM         (SADP_ERROR_BASE+35)  // �������󶨸���
#define SADP_MAILBOX_NOT_EXIST          (SADP_ERROR_BASE+36)  // ���䲻����
#define SADP_MAILBOX_NOT_SET            (SADP_ERROR_BASE+38)  // [add] <2019/01/08> by yangzheng ������������δ��������
#define SADP_INVALID_RESET_CODE         (SADP_ERROR_BASE+39)  // ��������  ���ÿ������
#define SADP_NO_PERMISSION              (SADP_ERROR_BASE+40)  // û��Ȩ�ޣ� 1.Win&Linux��û�й���ԱȨ�޲������� 2.Android IOSû�жಥȨ��
#define SADP_GET_EXCHANGE_CODE_ERROR    (SADP_ERROR_BASE+41)  // ��ȡ�����õĽ�����ʧ��
#define SADP_CREATE_RSA_KEY_ERROR       (SADP_ERROR_BASE+42)  // ����RSA��˽Կʧ��
#define SADP_BASE64_ENCODE_ERROR        (SADP_ERROR_BASE+43)  // BASE64�������
#define SADP_BASE64_DECODE_ERROR        (SADP_ERROR_BASE+44)  // BASE64�������
#define SADP_AES_ENCRYPT_ERROR          (SADP_ERROR_BASE+45)  // AES����ʧ��


//SADP�豸���˹�������
//��λ��ʾ��Ϊ1��ʾ���ˣ�0��ʾ������;
//bit 1:�Ƿ����өʯ;bit 2:�Ƿ����OEM;
#define SADP_DISPLAY_ALL           0            //��ʾ�����豸
#define SADP_FILTER_EZVIZ          0x01         //����өʯ�豸
#define SADP_FILTER_OEM            0x02         //����OEM�豸
#define SADP_FILTER_EZVIZ_OEM      0x03         //ͬʱ����өʯ��OEM�豸
#define SADP_ONLY_DISPLAY_OEM      0xfffffffd   //����ʾOEM�豸,��Ӧ�ṹ��SADP_DISPLAY_OEM_CFG
#define SADP_ONLY_DISPLAY_EZVIZ    0xfffffffe   //����ʾөʯ�豸
// �ṹ��

typedef struct tagSADP_DEVICE_INFO
{
    char            szSeries[12];          //�豸ϵ�У�������
    char            szSerialNO[48];        //�豸���к�
    char            szMAC[20];             //�豸�����ַ
    char            szIPv4Address[16];     //�豸IPv4��ַ
    char            szIPv4SubnetMask[16];  //�豸IPv4��������
    unsigned int    dwDeviceType;          //�豸���ͣ�������ֵ������豸�ͺ�
    unsigned int    dwPort;                //�豸����SDK����˿ں�(Ĭ��8000)
    unsigned int    dwNumberOfEncoders;    //�豸���������������豸����ͨ�����������ڽ���������ֵ��Ϊ0
    unsigned int    dwNumberOfHardDisk;    //�豸Ӳ����Ŀ
    char            szDeviceSoftwareVersion[48];  //�豸����汾��
    char            szDSPVersion[48];      //�豸DSP�汾��
    char            szBootTime[48];        //����ʱ��
    int             iResult;               
                    //��Ϣ���ͣ� 1.�豸����  2.�豸����  3.�豸����  4.�豸����  5.�豸����ʧ��
                    //SADP_ADD        1   ���豸���ߣ�֮ǰ��SADP���б���δ���ֵ��豸
                    //SADP_UPDATE     2   ���ߵ��豸�������������ĳЩ״̬�ı�
                    //SADP_DEC        3   �豸���ߣ��豸�Զ�����������Ϣ��120���ڼ�ⲻ���豸
                    //SADP_RESTART    4   ֮ǰSADP���б��г��ֹ�֮�����ߵ��豸�ٴ�����
                    //SADP_UPDATEFAIL 5   �豸����ʧ��
    char            szDevDesc[24];         //�豸�������� ��dwDeviceType��Ӧ
    char            szOEMinfo[24];         //OEM������Ϣ
    char            szIPv4Gateway[16];     //IPv4����
    char            szIPv6Address[46];     //IPv6��ַ
    char            szIPv6Gateway[46];     //IPv6����
    unsigned char   byIPv6MaskLen;         //IPv6����ǰ׺����
    unsigned char   bySupport;           
                    //��λ��ʾ,��ӦΪΪ1��ʾ֧��
                    //0x01:�Ƿ�֧��Ipv6
                    //0x02:�Ƿ�֧���޸�Ipv6����
                    //0x04:�Ƿ�֧��Dhcp	
                    //0x08:�Ƿ�֧��udp�ಥ 
                    //0x10:�Ƿ񺬼��ܽڵ�
                    //0x20:�Ƿ�֧�ָֻ�����
                    //0x40:�Ƿ�֧����������
                    //0x80:�Ƿ�֧��ͬ��IPC����
    unsigned char   byDhcpEnabled;         //Dhcp״̬, 0 ������ 1 ����
    unsigned char   byDeviceAbility;       //�豸����
                                           //0���豸��֧�֡����豸���������� 'OEM����' 'IPv4����' ��IPv6��ַ�� 'IPv6����' ��IPv6����ǰ׺����DHCP����  
                                           //1��֧�����߹���
    unsigned short  wHttpPort;             //Http �˿�
    unsigned short  wDigitalChannelNum;    //����ͨ����
    char            szCmsIPv4[16];         //CMSע�������IPv4��ַ
    unsigned short  wCmsPort;              //CMSע������������˿�
    unsigned char   byOEMCode;             //0-�����豸 1-OEM�豸
    unsigned char   byActivated;           //�豸�Ƿ񼤻�;0-���1-δ����ϵ��豸�����Ѽ���״̬��
    char            szBaseDesc[24];        //���߶��ͺţ����涨�ƶ��޸ĵ��ͺţ�����өʯƽ̨�����ͺŶԱ�
    unsigned char   bySupport1; 
                    //��λ��ʾ,  1��ʾ֧�֣�0��ʾ��֧��
                    //0x01:�Ƿ�֧���������뷽ʽ2 
                    //0x02;�Ƿ�֧���豸��������
                    //0x04:�Ƿ�֧�ֵ���GUID��������
                    //0x08:�Ƿ�֧�ְ�ȫ������������
                    //0x10:�Ƿ�֧��OEM����Logo
                    //0x20:�Ƿ�֧�ְ󶨲���
                    //0x40:�Ƿ�֧�ָֻ�δ����
                    //0x80:�Ƿ�֧��wifi�ź���ǿģʽ
    unsigned char   byHCPlatform;          //�Ƿ�֧��HCPlatform 0-����, 1-֧��, 2-��֧��   
    unsigned char   byEnableHCPlatform;    //�Ƿ�����HCPlatform  0-����, 1-���ã� 2-������
    unsigned char   byEZVIZCode;           //0-�����豸, 1-өʯ�豸
    unsigned int    dwDetailOEMCode;       //��ϸOEMCode��Ϣ:oemcode�ɿͻ���ţ��ɱ�λ,��1��ʼ��1~429496)+�˵����2λ��+����ţ�2λ�������ֹ��ɡ�	
                                           //����˵����oemcode���ֵΪ4294967295�������ʮλ����
                                           //0: ���豸
                                           //1: �»����豸
                                           //10101: �о���OEM code��ΪOEM�豸
    unsigned char   byModifyVerificationCode; //�Ƿ��޸���֤�� 0-������ 1-�޸���֤�룬 2-���޸���֤��
    unsigned char   byMaxBindNum;          //֧�ְ󶨵���������Ŀǰֻ��NVR֧�ָ��ֶΣ�
    unsigned short  wOEMCommandPort;       //OEM����˿�
    unsigned char   bySupportWifiRegion;
                    //�豸֧�ֵ�wifi�����б���λ��ʾ��1��ʾ֧�֣�0��ʾ��֧��
                    //0x01:�Ƿ�֧��default��Ĭ�Ϲ��ʺͱ���һ�£�
                    //0x02:�Ƿ�֧��china
                    //0x04:�Ƿ�֧��nothAmerica
                    //0x08:�Ƿ�֧��japan
                    //0x10:�Ƿ�֧��europe
                    //0x20:�Ƿ�֧��world
    unsigned char   byEnableWifiEnhancement;//�Ƿ�����wifi��ǿģʽ,0-�����ã�1-����
    unsigned char   byWifiRegion;           //�豸��ǰ����0-default��1-china��2-nothAmerica��3-japan��4-europe,5-world
    unsigned char   bySupport2; 
                    //��λ��ʾ,  1��ʾ֧�֣�0��ʾ��֧��
                    //0x01:�Ƿ�֧��ͨ��Ĭ���������ã�����������nvr���IPC�� Ĭ��ʹ�õ���nvr admin���룬�ᵥ�������ڱ��أ�
                    //0x02:�Ƿ�֧��������������
                    //0x04:�Ƿ�֧��δ��������SSID��Password
}SADP_DEVICE_INFO, *LPSADP_DEVICE_INFO;

typedef struct tagSADP_DEVICE_INFO_V40
{
    SADP_DEVICE_INFO struSadpDeviceInfo;
    unsigned char   byLicensed;          //�豸�Ƿ���Ȩ��0-����,1-�豸δ��Ȩ��2-�豸����Ȩ
    unsigned char   bySystemMode;        //ϵͳģʽ 0-����,1-���أ�2-˫�أ�3-������Ⱥ��4-˫�ؼ�Ⱥ
    unsigned char   byControllerType;    //���������� 0-������1-A�أ�2-B��
    char            szEhmoeVersion[16];  //Ehmoe�汾��
    unsigned char   bySpecificDeviceType;//�豸���ͣ�1-�����豸  2-�����豸
    unsigned int    dwSDKOverTLSPort;    //˽��Э���� SDK Over TLS ����˿�
    unsigned char   bySecurityMode;      //�豸��ȫģʽ��0-standard,1-high-A,2-high-B,3-custom
    unsigned char   bySDKServerStatus;   //�豸SDK����״̬, 0-������1-�ر�
    unsigned char   bySDKOverTLSServerStatus;         //�豸SDKOverTLS����״̬, 0-�رգ�1-����
    char            szUserName[MAX_USERNAME_LEN + 1]; //����Ա�û����û������豸��ȫģʽ�ڷǱ�׼ģʽ���������û����ù���Ա�û����û�������׼ģʽĬ��Ϊadmin��
    char            szWifiMAC[20];       //�豸����wifi��Mac��ַ
    unsigned char   byDataFromMulticast; //0-��· 1-�ಥ
    unsigned char   bySupportEzvizUnbind; //�Ƿ�֧��өʯ��� 0-��֧�� 1-֧��
    unsigned char   bySupportCodeEncrypt; //�Ƿ�֧�����ÿ���AES128_ECB����  0-��֧�� 1-֧��
    unsigned char   bySupportPasswordResetType; //�Ƿ�֧�ֻ�ȡ�������÷�ʽ����  0-��֧�� 1-֧��
    unsigned char   byEZVIZBindStatus; //�豸өʯ�ư�״̬,0-δ֪,1-�Ѱ�,2-δ��
    char            szPhysicalAccessVerification[16]; //�豸֧�ֵ�����Ӵ�ʽ��ӷ�ʽ,1#AP��������,2#�û����ƣ��û�token����,3#�������Ӵ�,4#ɨ��󶨣��豸token��
    unsigned short  wHttpsPort; // Https �˿�
    unsigned char   bySupportEzvizUserToken; //�Ƿ�֧��өʯ�û�token����  0-��֧�� 1-֧��
    char            szDevDescEx[64];         //�Ƕ�SADP_DEVICE_INFO�ṹ���е�szDevDesc�ֶ���չ
    char            szSerialNOEx[128];        //�Ƕ�SADP_DEVICE_INFO�ṹ���е�szSerialNO�ֶ���չ
    char            szManufacturer[32];     //�豸������Ϣ
    unsigned char   byRes[184];
}SADP_DEVICE_INFO_V40, *LPSADP_DEVICE_INFO_V40;

//���޸ĵ��豸�������
typedef struct tagSADP_DEV_NET_PARAM
{
    char            szIPv4Address[16];      // IPv4��ַ
    char            szIPv4SubNetMask[16];   // IPv4��������
    char            szIPv4Gateway[16];      // IPv4����
    char            szIPv6Address[128];     // IPv6��ַ
    char            szIPv6Gateway[128];     // IPv6����
    unsigned short  wPort;                  // �豸����SDK����˿ں�(Ĭ��8000)
    unsigned char   byIPv6MaskLen;          // IPv6���볤��
    unsigned char   byDhcpEnable;           // DHCPʹ��
    unsigned short  wHttpPort;              // HTTP�˿�
    unsigned int    dwSDKOverTLSPort;       // ˽��Э���� SDK Over TLS ����˿�
    unsigned char   byRes[122];
}SADP_DEV_NET_PARAM, *LPSADP_DEV_NET_PARAM;


//�豸�������������Ϣ
typedef struct tagSADP_DEV_RET_NET_PARAM
{
    unsigned char   byRetryModifyTime;  //ʣ��ɳ����޸������������
    unsigned char   bySurplusLockTime;  //ʣ��ʱ�䣬��λ�����ӣ��û�����ʱ�˲�����Ч
    unsigned char   byRes[126];
}SADP_DEV_RET_NET_PARAM, *LPSADP_DEV_RET_NET_PARAM;

//�豸��ȫ�룬��Ӧ��������SADP_GET_DEVICE_CODE���ӿ�SADP_GetDeviceConfig
typedef struct tagSADP_SAFE_CODE
{
    unsigned int    dwCodeSize;
    char            szDeviceCode[MAX_DEVICE_CODE];
    unsigned char   byRes[128];
}SADP_SAFE_CODE, *LPSADP_SAFE_CODE;

//�豸��ά��
typedef struct tagSADP_QR_CODES
{
    unsigned int    dwCodeSize;
    unsigned int    dwMailBoxSize;
    unsigned int    dwServiceMailBoxSize;
    char            szQrCodes[MAX_QR_CODES];
    char            szMailBoxAddr[MAX_MAILBOX_LEN];         //Ҫ���õ������ַ
    char            szServiceMailBoxAddr[MAX_MAILBOX_LEN];  //����������ַ
    unsigned char   byRes[128];
}SADP_QR_CODES, *LPSADP_QR_CODES;

//���ܴ��ṹ�壬��Ӧ��������SADP_GET_ENCRYPT_STRING���ӿ�SADP_GetDeviceConfig
typedef struct tagSADP_ENCRYPT_STRING
{
    unsigned int    dwEncryptStringSize;               //���ܴ�����
    char            szEncryptString[MAX_ENCRYPT_CODE]; //���ܴ�����
    unsigned char   byRes[128];
}SADP_ENCRYPT_STRING, *LPSADP_ENCRYPT_STRING;
//�ָ�/��������ṹ��
typedef struct tagSADP_RESET_PARAM
{
    char            szCode[MAX_ENCRYPT_CODE];     //����ת�����������ַ�������ܹ��߼��ܺ���ַ��� - Ϊ�����Ͻӿ�
    char            szAuthFile[MAX_FILE_PATH_LEN];//������Ȩ�ļ�
    char            szPassword[MAX_PASS_LEN];     //�û�����
    unsigned char   byEnableSyncIPCPW;            //�Ƿ�����ͬ��IPC���롣0 - �����ã� 1- ����
    unsigned char   byRes[511];
}SADP_RESET_PARAM, *LSADP_RESET_PARAM;

//��ʾOEM���ýṹ��
typedef struct tagSADP_DISPLAY_OEM_CFG
{
    unsigned int    dwDisplayOEM;   //0-��ʾ����OEM������ֵΪҪ��ʾ��ĳһ�����͵�OEMCode���������dwDetailOEMCode	
    unsigned char   byRes[32];      //����
}SADP_DISPLAY_OEM_CFG, *LPSADP_DISPLAY_OEM_CFG;

typedef struct tagSADP_TYPE_UNLOCK_CODE
{
    unsigned int   dwCodeSize;
    char           szDeviceTypeUnlockCode[MAX_UNLOCK_CODE_RANDOM_LEN/*256*/];//�豸�ͺŽ����
    unsigned char  byRes[128];
}SADP_TYPE_UNLOCK_CODE, *LPSADP_TYPE_UNLOCK_CODE;

typedef struct tagSADP_CUSTOM_DEVICE_TYPE
{
    unsigned int   dwCodeSize;
    char           szDeviceTypeSecretKey[MAX_UNLOCK_CODE_KEY/*256*/];//���ͽ����Կ
    unsigned char  byRes[128];
}SADP_CUSTOM_DEVICE_TYPE, *LPSADP_CUSTOM_DEVICE_TYPE;

//��ȡGUID�����ṹ��
typedef struct tagSADP_GUID_FILE_COND
{
    char           szPassword[MAX_PASS_LEN];  //�û�����
    unsigned char  byRes[128];
}SADP_GUID_FILE_COND, *LPSADP_GUID_FILE_COND;

//GUID�ṹ��
typedef struct tagSADP_GUID_FILE
{
    unsigned int    dwGUIDSize;
    char            szGUID[MAX_GUID_LEN];
    unsigned char   byRetryGUIDTime;    //ʣ��ɵ���/����GUID����
    unsigned char   bySurplusLockTime;  //ʣ��ʱ�䣬��λ�����ӣ��û�����ʱ�˲�����Ч
    unsigned char   byRes[254];
}SADP_GUID_FILE, *LPSADP_GUID_FILE;

typedef struct tagSADP_SINGLE_SECURITY_QUESTION_CFG
{
    unsigned int    dwSize;
    unsigned int    dwId;//���
    char            szAnswer[MAX_ANSWER_LEN/*256*/];//�𰸣�ֻ������ʱ��Ч����ȡʱ��Ч
    unsigned char   byMark;//��Ǹ���ŵ������Ƿ�����  0-δ���� 1-������
    unsigned char   byRes[127];
}SADP_SINGLE_SECURITY_QUESTION_CFG, *LPSADP_SINGLE_SECURITY_QUESTION_CFG;

typedef struct tagSADP_SECURITY_QUESTION_CFG
{
    unsigned int   dwSize;
    SADP_SINGLE_SECURITY_QUESTION_CFG  struSecurityQuestion[MAX_QUESTION_LIST_LEN/*32*/];//��ȫ�����б�
    char           szPassword[MAX_PASS_LEN];  //�û�����
    unsigned char  byRes[512];
}SADP_SECURITY_QUESTION_CFG, *LPSADP_SECURITY_QUESTION_CFG;

typedef struct tagSADP_SECURITY_QUESTION
{
    unsigned char   byRetryAnswerTime;  //ʣ������ð�ȫ�������
    unsigned char   bySurplusLockTime;  //ʣ��ʱ�䣬��λ�����ӣ��û�����ʱ�˲�����Ч
    unsigned char   byRes[254];
}SADP_SECURITY_QUESTION, *LPSADP_SECURITY_QUESTION;

typedef struct tagSADP_RESET_PARAM_V40
{
    unsigned int    dwSize;
    unsigned char   byResetType;              //������������ 0-����,1- ͨ���豸���кŻָ�Ĭ�����룬2-����/�����ļ��������룬3-��ά�����ã� 4-GUID���ã�5-��ȫ�������� 6-������������
    unsigned char   byEnableSyncIPCPW;        //�Ƿ�ͬʱ����������ΪNVRͬ��IPC���롣0 - �����ã� 1- ����
    unsigned char   byRes2[2];                //����
    char            szPassword[MAX_PASS_LEN]; //�û�����
    char            szCode[MAX_ENCRYPT_CODE]; //����ת�����������ַ�������ܹ��߼��ܺ���ַ��� - byResetType Ϊ1��3ʱ��Ч
    char            szAuthFile[MAX_FILE_PATH_LEN];//������Ȩ�ļ��� byResetType Ϊ2ʱ��Ч
    char            szGUID[MAX_GUID_LEN];     //GUID, byResetType Ϊ4ʱ��Ч
    SADP_SECURITY_QUESTION_CFG struSecurityQuestionCfg;//��ȫ����ṹ�壬 byResetType Ϊ5ʱ��Ч
    unsigned char   byRes[512];
}SADP_RESET_PARAM_V40, *LPSADP_RESET_PARAM_V40;

typedef struct tagSADP_RET_RESET_PARAM_V40
{
    unsigned char   byRetryGUIDTime;    //ʣ������ô���
    unsigned char   bySurplusLockTime;  //ʣ��ʱ�䣬��λ�����ӣ��û�����ʱ�˲�����Ч
    unsigned char   bRetryTimeValid; //byRetryGUIDTime�ֶ��Ƿ���Ч  0-��Ч,1-��Ч
    unsigned char   bLockTimeValid; //bySurplusLockTime�ֶ��Ƿ���Ч  0-��Ч,1-��Ч
    unsigned char   byRes[252];
}SADP_RET_RESET_PARAM_V40, *LPSADP_RET_RESET_PARAM_V40;

//HCPlatform״̬
typedef struct tagSADP_HCPLATFORM_STATUS_INFO
{
    unsigned int    dwSize;
    unsigned char   byEnableHCPlatform;        //�Ƿ�����HCPlatform��0 - ������ 1- ���ã� 2-������
    unsigned char   byRes[3];                  //����
    char            szPassword[MAX_PASS_LEN];  //�û�����
    unsigned char   byRes2[128];
}SADP_HCPLATFORM_STATUS_INFO, *LPSADP_HCPLATFORM_STATUS_INFO;

typedef struct tagSADP_USER_MAILBOX
{
    unsigned int    dwSize;
    char            szPassword[MAX_PASS_LEN];        //�豸admin�û�����
    char            szMailBoxAddr[MAX_MAILBOX_LEN];  //Ԥ�������ַ�����ڽ���������������صİ�ȫ��
    unsigned char   byRes[128];
}SADP_USER_MAILBOX, *LPSADP_USER_MAILBOX;
//�豸��֤��
typedef struct tagSADP_VERIFICATION_CODE_INFO
{
    unsigned int    dwSize;
    char            szVerificationCode[SADP_MAX_VERIFICATION_CODE_LEN];  //��֤�루��֤������өʯ���롢Ԥ�������Ƶ�Ψһ���룩
    char            szPassword[MAX_PASS_LEN];  //�û�����
    unsigned char   byRes[128];
}SADP_VERIFICATION_CODE_INFO, *LPSADP_VERIFICATION_CODE_INFO;

//�豸������Ϣ
typedef struct tagSADP_DEV_LOCK_INFO
{
    unsigned char   byRetryTime;       //ʣ��ɳ��Դ���
    unsigned char   bySurplusLockTime; //ʣ��ʱ�䣬��λ�����ӣ��û�����ʱ�˲�����Ч
    unsigned char   byRes[126];
}SADP_DEV_LOCK_INFO, *LPSADP_DEV_LOCK_INFO;

//�����豸��Ϣ�ṹ��
typedef struct tagSADP_BIND_INFO
{
    char            szSerialNO[SADP_MAX_SERIALNO_LEN]; //�����豸�����к�
    unsigned char   byiBind; //�豸�Ƿ�� 0-δ�󶨣�1-�Ѱ�
    unsigned char   byRes[127];
}SADP_BIND_INFO, *LPSADP_BIND_INFO;

typedef struct tagSADP_BIND_LIST
{
    SADP_BIND_INFO   struBindInfo[SADP_MAX_BIND_NUM]; //���豸��Ϣ�б�
    char             szPassword[MAX_PASS_LEN]; //�û�����
    unsigned char    byUnbindAll; //�Ƿ��������豸 0-����������豸��1-��������豸
    unsigned char    byRes[127];
}SADP_BIND_LIST, *LPSADP_BIND_LIST;

typedef struct tagSADP_INACTIVE_INFO
{
    char             szPassword[MAX_PASS_LEN];  //�û�����
    unsigned char    byRes[128];
}SADP_INACTIVE_INFO, *LPSADP_INACTIVE_INFO;

//wifi Region
typedef struct tagSADP_WIFI_REGION_INFO
{
    unsigned char   byMode;                  //ģʽ��0-������1-wifi��������ģʽ��2-wifi��ǿģʽ
    unsigned char   byWifiRegion;            //wifi���򣬵�byModeΪ1ʱ�����ֶ���Ч��0 -default�� 1- china, 2-nothAmerica,3-japan,4-europe,5-world
    unsigned char   byWifiEnhancementEnabled;//�Ƿ�����wifi��ǿģʽ����byModeΪ2ʱ�����ֶ���Ч 0 -�����ã� 1- ����
    unsigned char   byRes;                   //����
    char            szPassword[MAX_PASS_LEN];//�û�����
    unsigned char   byRes2[128];
}SADP_WIFI_REGION_INFO, *LPSADP_WIFI_REGION_INFO;

//ͨ��Ĭ��������Ϣ
typedef struct tagSADP_CHANNEL_DEFAULT_PASSWORD
{
    char             szPassword[MAX_PASS_LEN]; //�豸admin�û�����
    char             szChannelDefaultPassword[MAX_PASS_LEN]; //ͨ��Ĭ�����루�û�NVR������IPC��
    unsigned char    byRes[128];
}SADP_CHANNEL_DEFAULT_PASSWORD, *LPSADP_CHANNEL_DEFAULT_PASSWORD;


//�豸�Լ�״̬�ṹ��
typedef struct tagSADP_SELF_CHECK_STATE
{
    unsigned int    dwSize;
    int             dwTotalDisk;               //����������Ĭ��ֵΪ-1��
    int             dwGoodDisk;                //��������Ĭ��ֵΪ-1��
    char            szCPU[MAX_CPU_LEN];        //CPU
    char            szMemory[MAX_MEMORY_LEN];  //�ڴ�
    unsigned char   byProgress;                //�Լ���ȣ�0-100
    unsigned char   byTemperatureState;        //�¶�״̬��0-��Ч��1-������2-�쳣
    unsigned char   byFanState;                //����״̬��0-��Ч��1-������2-�쳣
    unsigned char   byPowerState;              //��Դ״̬��0-��Ч��1-������2-�쳣
    unsigned char   bySASConnectState;         //SAS����״̬��0-��Ч��1-���ӣ�2-δ����
    char            byTotalNetworkPort;        //����������Ĭ��ֵΪ-1��
    char            byConnectNetworkPort;      //������������Ĭ��ֵΪ-1��
    unsigned char   byRes[129];
}SADP_SELF_CHECK_STATE, *LPSADP_SELF_CHECK_STATE;

//EHomeʹ�ܲ���
typedef struct tagSADP_EHOME_ENABLE_PARAM
{
    unsigned int    dwSize;
    char            szDevID[MAX_PASS_LEN];     //�豸ID
    char            szEhomeKey[MAX_PASS_LEN];  //Ehome Key
    char            szPassword[MAX_PASS_LEN];  //�豸����
    unsigned char   byRes[64];
}SADP_EHOME_ENABLE_PARAM, *LPSADP_EHOME_ENABLE_PARAM;

//WIFI�������ýṹ��
typedef struct tagSADP_WIFI_CONFIG_PARAM
{
    unsigned int    dwSize;
    char            szSSID[SADP_MAX_SERIALNO_LEN];      //SSID
    char            szPassword[SADP_MAX_SERIALNO_LEN];  //Password
    unsigned char   byWifiMode;  //wifiģʽ��0-Ĭ�ϣ�1-Station�� 2-AP
    unsigned char   byRes[64];
}SADP_WIFI_CONFIG_PARAM, *LPSADP_WIFI_CONFIG_PARAM;

//�����������������Ͳ������ýṹ��
typedef struct tagSADP_PASSWORD_RESET_TYPE_PARAM
{
    unsigned int    dwSize;
    unsigned char   byEnable;  //0-δ����  1-��GUID����ȫ���⣬��ȫ���䣬HC�����ù�һ�ֻ���� 
    unsigned char   byGuidEnabled;  //0-δ������GUID  1-������GUID
    unsigned char   bySecurityQuestionEnabled;  //0-δ���ù���ȫ����  1-���ù���ȫ����
    unsigned char   bySecurityMailBoxEnabled;  //0-δ���ù���ȫ����  1-���ù���ȫ����
    unsigned char   byHikConnectEnabled;  //0-δ��HikConnect�˺�  1-�󶨹�HikConnect�˺�
    unsigned char   byRes1[3];
    unsigned char   byRes[64];
}SADP_PASSWORD_RESET_TYPE_PARAM, *LPSADP_PASSWORD_RESET_TYPE_PARAM;

//����өʯ�û�token�ṹ��
typedef struct tagSADP_EZVIZ_USER_TOKEN_PARAM
{
    unsigned int    dwSize;
    char            szToken[MAX_TOKEN_LEN]; //token��8-16�ֽ�
    char            szPassword[MAX_PASS_LEN]; //password��8-16�ֽ�
    unsigned char   byRes[256];
}SADP_EZVIZ_USER_TOKEN_PARAM, *LPSADP_EZVIZ_USER_TOKEN_PARAM;


//-----------------------------------------------------------------�ӿ�-----------------------------------------------------------------

//�ص�����
typedef void (CALLBACK *PDEVICE_FIND_CALLBACK)(const SADP_DEVICE_INFO *lpDeviceInfo, void *pUserData);
typedef void (CALLBACK *PDEVICE_FIND_CALLBACK_V40)(const SADP_DEVICE_INFO_V40 *lpDeviceInfo, void *pUserData);

//����sadp����
CSADP_API BOOL CALLBACK SADP_Start_V30(PDEVICE_FIND_CALLBACK pDeviceFindCallBack, int bInstallNPF = 0, void* pUserData = NULL);
CSADP_API BOOL CALLBACK SADP_Start_V40(PDEVICE_FIND_CALLBACK_V40 pDeviceFindCallBack, int bInstallNPF = 0, void* pUserData = NULL);

//ֹͣsadp����
CSADP_API BOOL CALLBACK SADP_Stop(void);

//�����豸
CSADP_API BOOL CALLBACK SADP_ActivateDevice(const char* sDevSerialNO, const char* sCommand);

//�޸�������� ������ʹ��SADP_ModifyDeviceNetParam_V40��
CSADP_API BOOL CALLBACK SADP_ModifyDeviceNetParam(const char* sMAC, const char* sPassword, const SADP_DEV_NET_PARAM *lpNetParam);
CSADP_API BOOL CALLBACK SADP_ModifyDeviceNetParam_V40(const char* sMAC, const char* sPassword, const SADP_DEV_NET_PARAM *lpNetParam, SADP_DEV_RET_NET_PARAM *lpRetNetParam, unsigned int  dwOutBuffSize);

//�������� ������ʹ��SADP_ResetPasswd_V40��
CSADP_API BOOL CALLBACK SADP_ResetDefaultPasswd(const char* sDevSerialNO, const char* sCommand);
CSADP_API BOOL CALLBACK SADP_ResetPasswd(const char* sDevSerialNO, const SADP_RESET_PARAM *pResetParam);
CSADP_API BOOL CALLBACK SADP_ResetPasswd_V40(const char* sDevSerialNO, const SADP_RESET_PARAM_V40 *pResetParam, SADP_RET_RESET_PARAM_V40 *pRetResetParam);

//��������
CSADP_API BOOL CALLBACK SADP_GetDeviceConfig(const char* sDevSerialNO, unsigned int dwCommand, void* lpInBuffer, unsigned int  dwinBuffSize, void *lpOutBuffer, unsigned int  dwOutBuffSize);
CSADP_API BOOL CALLBACK SADP_SetDeviceConfig(const char* sDevSerialNO, unsigned int dwCommand, void* lpInBuffer, unsigned int  dwInBuffSize, void* lpOutBuffer, unsigned int  dwOutBuffSize);
CSADP_API BOOL CALLBACK SADP_GetDeviceConfigByMAC(const char* sDevMAC, unsigned int dwCommand, void* lpInBuffer, unsigned int  dwinBuffSize, void *lpOutBuffer, unsigned int  dwOutBuffSize);

//����SDK�ڲ��Զ��������
CSADP_API void CALLBACK SADP_SetAutoRequestInterval(unsigned int dwInterval); //�����Զ�����ʱ����(��λ�룬Ϊ0���Զ�����Ĭ��60s)

//����һ�ξ���������
CSADP_API BOOL CALLBACK SADP_SendInquiry(void);

//����SDK�ڲ��豸�����б�
CSADP_API BOOL CALLBACK SADP_Clearup(void);

//�����豸���˹���
//dwFilterRule,��λ��ʾ��Ϊ1��ʾ���ˣ�ȫ0��ʾ������;0x01:����өʯ�豸;0x02:����OEM�豸;0x03:����ө��OEM�豸;0xfffffffe:����ʾөʯ�豸;0xfffffffd:����ʾOEM�豸
CSADP_API BOOL CALLBACK SADP_SetDeviceFilterRule( unsigned int dwFilterRule, const void *lpInBuff, unsigned int dwInBuffLen);

//��ȡSDK�汾
CSADP_API unsigned int CALLBACK SADP_GetSadpVersion(void);

//����SDK��־
CSADP_API BOOL CALLBACK SADP_SetLogToFile(int nLogLevel=0, char const *strLogDir = NULL, int bAutoDel = 1);

//��ȡ������
CSADP_API unsigned int CALLBACK SADP_GetLastError(void);
#endif




