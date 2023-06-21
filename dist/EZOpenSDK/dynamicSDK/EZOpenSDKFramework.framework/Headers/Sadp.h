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

//消息操作的类型
#define SADP_ADD          1         //增加一设备
#define SADP_UPDATE       2         //更新设备
#define SADP_DEC          3         //设备下线
#define SADP_RESTART      4         //设备重新启动
#define SADP_UPDATEFAIL   5         //设备更新失败

//外部命令码
#define SADP_GET_DEVICE_CODE                1   //获取设备码，对应结构体SADP_SAFE_CODE
#define SADP_GET_ENCRYPT_STRING             2   //获取加密串，对应结构体SADP_ENCRYPT_STRING
#define SADP_GET_DEVICE_TYPE_UNLOCK_CODE    3   //获取设备类型解禁码，对应的结构体SADP_TYPE_UNLOCK_CODE
#define SADP_SET_DEVICE_CUSTOM_TYPE         4   //设置设备自定义型号，对应的结构体SADP_CUSTOM_DEVICE_TYPE
#define SADP_GET_GUID                       5   //获取GUID
#define SADP_GET_SECURITY_QUESTION          6   //获取安全问题
#define SADP_SET_SECURITY_QUESTION          7   //设置安全问题
#define SADP_SET_HCPLATFORM_STATUS          8   //设置HCPLATFORM状态
#define SADP_SET_VERIFICATION_CODE          9   //设置验证码（验证码用于萤石接入、预览、控制的唯一密码）
#define SADP_GET_BIND_LIST                  12  //获取绑定设备列表
#define SADP_SET_BIND_LIST                  13  //设置绑定设备列表
#define SADP_RESTORE_INACTIVE               14  //恢复未激活
#define SADP_SET_WIFI_REGION                15  //设置wifi区域
#define SADP_SET_CHANNEL_DEFAULT_PASSWORD   16  //设置通道默认密码
#define SADP_GET_SELF_CHECK                 17  //获取设备自检状态
#define SADP_DISK_LOCATE                    18  //坏盘定位
#define SADP_EHOME_ENABLE                   19  //EHome使能
#define SADP_SET_USER_MAILBOX               20  //设置用户邮箱
#define SADP_GET_QR_CODES                   21  //获取二维码数据
#define SADP_GET_PASSWORD_RESET_TYPE        27  //获取重置密码方式参数
#define SADP_SET_EZVIZ_USER_TOKEN           28  //配置萤石用户token



#define SADP_MAX_VERIFICATION_CODE_LEN  12   //最大验证码长度
#define MAX_PASS_LEN                    16   //设备最大密码长度
#define MAX_QUESTION_LIST_LEN           32   //最多问题列表个数
#define SADP_MAX_BIND_NUM               32   //最大绑定设备个数
#define MAX_CPU_LEN                     32   //CPU长度
#define MAX_MEMORY_LEN                  32   //内存长度
#define MAX_USERNAME_LEN                32   //用户名最大长度
#define SADP_MAX_SERIALNO_LEN           64   //最大设备序列号长度
#define MAX_DEVICE_CODE                 128  //设备返回码长度，暂定最大128
#define MAX_MAILBOX_LEN                 128  //邮箱长度，暂定最大128
#define MAX_GUID_LEN                    128  //GUID长度
#define MAX_EXCHANGE_CODE               256  //交换码长度
#define MAX_ENCRYPT_CODE                256  //设备返回码加密后长度
#define MAX_UNLOCK_CODE_KEY             256  //解禁密钥
#define MAX_QR_CODES                    256  //二维码数据长度，暂定最大256
#define MAX_ANSWER_LEN                  256  //最大答案长度
#define MAX_UNLOCK_CODE_RANDOM_LEN      256  //解禁码随机串
#define MAX_FILE_PATH_LEN               260  //文件最大路径长度
#define MAX_TOKEN_LEN                   16   //萤石用户token最大长度




// 错误码
#define SADP_ERROR_BASE                 2000
#define SADP_NOERROR                    0                     // 没有错误
#define SADP_ALLOC_RESOURCE_ERROR       (SADP_ERROR_BASE+1)   // 资源分配错误
#define SADP_NOT_START_ERROR            (SADP_ERROR_BASE+2)   // SADP未启动
#define SADP_NO_ADAPTER_ERROR           (SADP_ERROR_BASE+3)   // 无网卡
#define SADP_GET_ADAPTER_FAIL_ERROR     (SADP_ERROR_BASE+4)   // 获取网卡信息失败
#define SADP_PARAMETER_ERROR            (SADP_ERROR_BASE+5)   // 参数错误
#define SADP_OPEN_ADAPTER_FAIL_ERROR    (SADP_ERROR_BASE+6)   // 打开网卡失败
#define SADP_SEND_PACKET_FAIL_ERROR     (SADP_ERROR_BASE+7)   // 发送数据失败
#define SADP_SYSTEM_CALL_ERROR          (SADP_ERROR_BASE+8)   // 系统接口调用失败
#define SADP_DEVICE_DENY                (SADP_ERROR_BASE+9)   // 设备拒绝处理
#define SADP_NPF_INSTALL_ERROR          (SADP_ERROR_BASE+10)  // 安装NPF服务失败
#define SADP_TIMEOUT                    (SADP_ERROR_BASE+11)  // 设备超时
#define SADP_CREATE_SOCKET_ERROR        (SADP_ERROR_BASE+12)  // 创建socket失败
#define SADP_BIND_SOCKET_ERROR          (SADP_ERROR_BASE+13)  // 绑定socket失败
#define SADP_JOIN_MULTI_CAST_ERROR      (SADP_ERROR_BASE+14)  // 加入多播组失败
#define SADP_NETWORK_SEND_ERROR         (SADP_ERROR_BASE+15)  // 发送出错
#define SADP_NETWORK_RECV_ERROR         (SADP_ERROR_BASE+16)  // 接收出错
#define SADP_XML_PARSE_ERROR            (SADP_ERROR_BASE+17)  // 多播XML解析出错
#define SADP_LOCKED                     (SADP_ERROR_BASE+18)  // 设备锁定
#define SADP_NOT_ACTIVATED              (SADP_ERROR_BASE+19)  // 设备未激活
#define SADP_RISK_PASSWORD              (SADP_ERROR_BASE+20)  // 风险高的密码
#define SADP_HAS_ACTIVATED              (SADP_ERROR_BASE+21)  // 设备已激活
#define SADP_EMPTY_ENCRYPT_STRING       (SADP_ERROR_BASE+22)  // 加密串为空
#define SADP_EXPORT_FILE_OVERDUE        (SADP_ERROR_BASE+23)  // 导出文件超期
#define SADP_PASSWORD_ERROR             (SADP_ERROR_BASE+24)  // 密码错误
#define SADP_LONG_SECURITY_ANSWER       (SADP_ERROR_BASE+25)  // 安全问题答案太长
#define SADP_INVALID_GUID               (SADP_ERROR_BASE+26)  // 无效的GUID
#define SADP_ANSWER_ERROR               (SADP_ERROR_BASE+27)  // 答案错误
#define SADP_QUESTION_NUM_ERR           (SADP_ERROR_BASE+28)  // 安全问题个数配置错误
#define SADP_LOAD_WPCAP_FAIL            (SADP_ERROR_BASE+30)  // 加载Wpcap失败
#define SADP_ILLEGAL_VERIFICATION_CODE  (SADP_ERROR_BASE+33)  // 非法验证码
#define SADP_BIND_ERROR_DEV             (SADP_ERROR_BASE+34)  // 绑定错误的设备
#define SADP_EXTED_MAX_BIND_NUM         (SADP_ERROR_BASE+35)  // 超过最大绑定个数
#define SADP_MAILBOX_NOT_EXIST          (SADP_ERROR_BASE+36)  // 邮箱不存在
#define SADP_MAILBOX_NOT_SET            (SADP_ERROR_BASE+38)  // [add] <2019/01/08> by yangzheng 邮箱重置密码未设置邮箱
#define SADP_INVALID_RESET_CODE         (SADP_ERROR_BASE+39)  // 重置密码  重置口令错误
#define SADP_NO_PERMISSION              (SADP_ERROR_BASE+40)  // 没有权限： 1.Win&Linux下没有管理员权限操作网卡 2.Android IOS没有多播权限
#define SADP_GET_EXCHANGE_CODE_ERROR    (SADP_ERROR_BASE+41)  // 获取加密用的交换码失败
#define SADP_CREATE_RSA_KEY_ERROR       (SADP_ERROR_BASE+42)  // 生成RSA公私钥失败
#define SADP_BASE64_ENCODE_ERROR        (SADP_ERROR_BASE+43)  // BASE64编码错误
#define SADP_BASE64_DECODE_ERROR        (SADP_ERROR_BASE+44)  // BASE64解码错误
#define SADP_AES_ENCRYPT_ERROR          (SADP_ERROR_BASE+45)  // AES加密失败


//SADP设备过滤规则类型
//按位表示，为1表示过滤，0表示不过滤;
//bit 1:是否过滤萤石;bit 2:是否过滤OEM;
#define SADP_DISPLAY_ALL           0            //显示所有设备
#define SADP_FILTER_EZVIZ          0x01         //过滤萤石设备
#define SADP_FILTER_OEM            0x02         //过滤OEM设备
#define SADP_FILTER_EZVIZ_OEM      0x03         //同时过滤萤石和OEM设备
#define SADP_ONLY_DISPLAY_OEM      0xfffffffd   //仅显示OEM设备,对应结构体SADP_DISPLAY_OEM_CFG
#define SADP_ONLY_DISPLAY_EZVIZ    0xfffffffe   //仅显示萤石设备
// 结构体

typedef struct tagSADP_DEVICE_INFO
{
    char            szSeries[12];          //设备系列（保留）
    char            szSerialNO[48];        //设备序列号
    char            szMAC[20];             //设备物理地址
    char            szIPv4Address[16];     //设备IPv4地址
    char            szIPv4SubnetMask[16];  //设备IPv4子网掩码
    unsigned int    dwDeviceType;          //设备类型，具体数值代表的设备型号
    unsigned int    dwPort;                //设备网络SDK服务端口号(默认8000)
    unsigned int    dwNumberOfEncoders;    //设备编码器个数，即设备编码通道个数。对于解码器，其值设为0
    unsigned int    dwNumberOfHardDisk;    //设备硬盘数目
    char            szDeviceSoftwareVersion[48];  //设备软件版本号
    char            szDSPVersion[48];      //设备DSP版本号
    char            szBootTime[48];        //开机时间
    int             iResult;               
                    //信息类型： 1.设备上线  2.设备更新  3.设备下线  4.设备重启  5.设备更新失败
                    //SADP_ADD        1   新设备上线，之前在SADP库列表中未出现的设备
                    //SADP_UPDATE     2   在线的设备的网络参数或者某些状态改变
                    //SADP_DEC        3   设备下线，设备自动发送下线消息或120秒内检测不到设备
                    //SADP_RESTART    4   之前SADP库列表中出现过之后下线的设备再次上线
                    //SADP_UPDATEFAIL 5   设备更新失败
    char            szDevDesc[24];         //设备类型描述 与dwDeviceType对应
    char            szOEMinfo[24];         //OEM产商信息
    char            szIPv4Gateway[16];     //IPv4网关
    char            szIPv6Address[46];     //IPv6地址
    char            szIPv6Gateway[46];     //IPv6网关
    unsigned char   byIPv6MaskLen;         //IPv6子网前缀长度
    unsigned char   bySupport;           
                    //按位表示,对应为为1表示支持
                    //0x01:是否支持Ipv6
                    //0x02:是否支持修改Ipv6参数
                    //0x04:是否支持Dhcp	
                    //0x08:是否支持udp多播 
                    //0x10:是否含加密节点
                    //0x20:是否支持恢复密码
                    //0x40:是否支持重置密码
                    //0x80:是否支持同步IPC密码
    unsigned char   byDhcpEnabled;         //Dhcp状态, 0 不启用 1 启用
    unsigned char   byDeviceAbility;       //设备能力
                                           //0：设备不支持“‘设备类型描述’ 'OEM厂商' 'IPv4网关' ‘IPv6地址’ 'IPv6网关' ‘IPv6子网前缀’‘DHCP’”  
                                           //1：支持上诉功能
    unsigned short  wHttpPort;             //Http 端口
    unsigned short  wDigitalChannelNum;    //数字通道数
    char            szCmsIPv4[16];         //CMS注册服务器IPv4地址
    unsigned short  wCmsPort;              //CMS注册服务器监听端口
    unsigned char   byOEMCode;             //0-基线设备 1-OEM设备
    unsigned char   byActivated;           //设备是否激活;0-激活，1-未激活（老的设备都是已激活状态）
    char            szBaseDesc[24];        //基线短型号，不随定制而修改的型号，用于萤石平台进行型号对比
    unsigned char   bySupport1; 
                    //按位表示,  1表示支持，0表示不支持
                    //0x01:是否支持重置密码方式2 
                    //0x02;是否支持设备锁定功能
                    //0x04:是否支持导入GUID重置密码
                    //0x08:是否支持安全问题重置密码
                    //0x10:是否支持OEM更换Logo
                    //0x20:是否支持绑定操作
                    //0x40:是否支持恢复未激活
                    //0x80:是否支持wifi信号增强模式
    unsigned char   byHCPlatform;          //是否支持HCPlatform 0-保留, 1-支持, 2-不支持   
    unsigned char   byEnableHCPlatform;    //是否启用HCPlatform  0-保留, 1-启用， 2-不启用
    unsigned char   byEZVIZCode;           //0-基线设备, 1-萤石设备
    unsigned int    dwDetailOEMCode;       //详细OEMCode信息:oemcode由客户序号（可变位,从1开始，1~429496)+菜单风格（2位）+区域号（2位）三部分构成。	
                                           //规则说明：oemcode最大值为4294967295，最多是十位数。
                                           //0: 老设备
                                           //1: 新基线设备
                                           //10101: 有具体OEM code的为OEM设备
    unsigned char   byModifyVerificationCode; //是否修改验证码 0-保留， 1-修改验证码， 2-不修改验证码
    unsigned char   byMaxBindNum;          //支持绑定的最大个数（目前只有NVR支持该字段）
    unsigned short  wOEMCommandPort;       //OEM命令端口
    unsigned char   bySupportWifiRegion;
                    //设备支持的wifi区域列表，按位表示，1表示支持，0表示不支持
                    //0x01:是否支持default（默认功率和北美一致）
                    //0x02:是否支持china
                    //0x04:是否支持nothAmerica
                    //0x08:是否支持japan
                    //0x10:是否支持europe
                    //0x20:是否支持world
    unsigned char   byEnableWifiEnhancement;//是否启用wifi增强模式,0-不启用，1-启用
    unsigned char   byWifiRegion;           //设备当前区域，0-default，1-china，2-nothAmerica，3-japan，4-europe,5-world
    unsigned char   bySupport2; 
                    //按位表示,  1表示支持，0表示不支持
                    //0x01:是否支持通道默认密码配置（该密码用于nvr添加IPC， 默认使用的是nvr admin密码，会单独保存在本地）
                    //0x02:是否支持邮箱重置密码
                    //0x04:是否支持未激活配置SSID和Password
}SADP_DEVICE_INFO, *LPSADP_DEVICE_INFO;

typedef struct tagSADP_DEVICE_INFO_V40
{
    SADP_DEVICE_INFO struSadpDeviceInfo;
    unsigned char   byLicensed;          //设备是否授权：0-保留,1-设备未授权，2-设备已授权
    unsigned char   bySystemMode;        //系统模式 0-保留,1-单控，2-双控，3-单机集群，4-双控集群
    unsigned char   byControllerType;    //控制器类型 0-保留，1-A控，2-B控
    char            szEhmoeVersion[16];  //Ehmoe版本号
    unsigned char   bySpecificDeviceType;//设备类型，1-中性设备  2-海康设备
    unsigned int    dwSDKOverTLSPort;    //私有协议中 SDK Over TLS 命令端口
    unsigned char   bySecurityMode;      //设备安全模式：0-standard,1-high-A,2-high-B,3-custom
    unsigned char   bySDKServerStatus;   //设备SDK服务状态, 0-开启，1-关闭
    unsigned char   bySDKOverTLSServerStatus;         //设备SDKOverTLS服务状态, 0-关闭，1-开启
    char            szUserName[MAX_USERNAME_LEN + 1]; //管理员用户的用户名（设备安全模式在非标准模式下是允许用户设置管理员用户的用户名，标准模式默认为admin）
    char            szWifiMAC[20];       //设备所连wifi的Mac地址
    unsigned char   byDataFromMulticast; //0-链路 1-多播
    unsigned char   bySupportEzvizUnbind; //是否支持萤石解绑 0-不支持 1-支持
    unsigned char   bySupportCodeEncrypt; //是否支持重置口令AES128_ECB解密  0-不支持 1-支持
    unsigned char   bySupportPasswordResetType; //是否支持获取密码重置方式参数  0-不支持 1-支持
    unsigned char   byEZVIZBindStatus; //设备萤石云绑定状态,0-未知,1-已绑定,2-未绑定
    char            szPhysicalAccessVerification[16]; //设备支持的物理接触式添加方式,1#AP配网传递,2#用户令牌（用户token）绑定,3#物理按键接触,4#扫码绑定（设备token）
    unsigned short  wHttpsPort; // Https 端口
    unsigned char   bySupportEzvizUserToken; //是否支持萤石用户token配置  0-不支持 1-支持
    char            szDevDescEx[64];         //是对SADP_DEVICE_INFO结构体中的szDevDesc字段扩展
    char            szSerialNOEx[128];        //是对SADP_DEVICE_INFO结构体中的szSerialNO字段扩展
    char            szManufacturer[32];     //设备厂商信息
    unsigned char   byRes[184];
}SADP_DEVICE_INFO_V40, *LPSADP_DEVICE_INFO_V40;

//待修改的设备网络参数
typedef struct tagSADP_DEV_NET_PARAM
{
    char            szIPv4Address[16];      // IPv4地址
    char            szIPv4SubNetMask[16];   // IPv4子网掩码
    char            szIPv4Gateway[16];      // IPv4网关
    char            szIPv6Address[128];     // IPv6地址
    char            szIPv6Gateway[128];     // IPv6网关
    unsigned short  wPort;                  // 设备网络SDK服务端口号(默认8000)
    unsigned char   byIPv6MaskLen;          // IPv6掩码长度
    unsigned char   byDhcpEnable;           // DHCP使能
    unsigned short  wHttpPort;              // HTTP端口
    unsigned int    dwSDKOverTLSPort;       // 私有协议中 SDK Over TLS 命令端口
    unsigned char   byRes[122];
}SADP_DEV_NET_PARAM, *LPSADP_DEV_NET_PARAM;


//设备返回网络参数信息
typedef struct tagSADP_DEV_RET_NET_PARAM
{
    unsigned char   byRetryModifyTime;  //剩余可尝试修改网络参数次数
    unsigned char   bySurplusLockTime;  //剩余时间，单位：分钟，用户锁定时此参数有效
    unsigned char   byRes[126];
}SADP_DEV_RET_NET_PARAM, *LPSADP_DEV_RET_NET_PARAM;

//设备安全码，对应配置命令SADP_GET_DEVICE_CODE，接口SADP_GetDeviceConfig
typedef struct tagSADP_SAFE_CODE
{
    unsigned int    dwCodeSize;
    char            szDeviceCode[MAX_DEVICE_CODE];
    unsigned char   byRes[128];
}SADP_SAFE_CODE, *LPSADP_SAFE_CODE;

//设备二维码
typedef struct tagSADP_QR_CODES
{
    unsigned int    dwCodeSize;
    unsigned int    dwMailBoxSize;
    unsigned int    dwServiceMailBoxSize;
    char            szQrCodes[MAX_QR_CODES];
    char            szMailBoxAddr[MAX_MAILBOX_LEN];         //要设置的邮箱地址
    char            szServiceMailBoxAddr[MAX_MAILBOX_LEN];  //服务的邮箱地址
    unsigned char   byRes[128];
}SADP_QR_CODES, *LPSADP_QR_CODES;

//加密串结构体，对应配置命令SADP_GET_ENCRYPT_STRING，接口SADP_GetDeviceConfig
typedef struct tagSADP_ENCRYPT_STRING
{
    unsigned int    dwEncryptStringSize;               //加密串长度
    char            szEncryptString[MAX_ENCRYPT_CODE]; //加密串内容
    unsigned char   byRes[128];
}SADP_ENCRYPT_STRING, *LPSADP_ENCRYPT_STRING;
//恢复/重置密码结构体
typedef struct tagSADP_RESET_PARAM
{
    char            szCode[MAX_ENCRYPT_CODE];     //日期转换过的特殊字符串或加密工具加密后的字符串 - 为兼容老接口
    char            szAuthFile[MAX_FILE_PATH_LEN];//重置授权文件
    char            szPassword[MAX_PASS_LEN];     //用户密码
    unsigned char   byEnableSyncIPCPW;            //是否启用同步IPC密码。0 - 不启用， 1- 启用
    unsigned char   byRes[511];
}SADP_RESET_PARAM, *LSADP_RESET_PARAM;

//显示OEM配置结构体
typedef struct tagSADP_DISPLAY_OEM_CFG
{
    unsigned int    dwDisplayOEM;   //0-显示所有OEM，其它值为要显示的某一种类型的OEMCode，具体详见dwDetailOEMCode	
    unsigned char   byRes[32];      //保留
}SADP_DISPLAY_OEM_CFG, *LPSADP_DISPLAY_OEM_CFG;

typedef struct tagSADP_TYPE_UNLOCK_CODE
{
    unsigned int   dwCodeSize;
    char           szDeviceTypeUnlockCode[MAX_UNLOCK_CODE_RANDOM_LEN/*256*/];//设备型号解禁码
    unsigned char  byRes[128];
}SADP_TYPE_UNLOCK_CODE, *LPSADP_TYPE_UNLOCK_CODE;

typedef struct tagSADP_CUSTOM_DEVICE_TYPE
{
    unsigned int   dwCodeSize;
    char           szDeviceTypeSecretKey[MAX_UNLOCK_CODE_KEY/*256*/];//类型解禁秘钥
    unsigned char  byRes[128];
}SADP_CUSTOM_DEVICE_TYPE, *LPSADP_CUSTOM_DEVICE_TYPE;

//获取GUID参数结构体
typedef struct tagSADP_GUID_FILE_COND
{
    char           szPassword[MAX_PASS_LEN];  //用户密码
    unsigned char  byRes[128];
}SADP_GUID_FILE_COND, *LPSADP_GUID_FILE_COND;

//GUID结构体
typedef struct tagSADP_GUID_FILE
{
    unsigned int    dwGUIDSize;
    char            szGUID[MAX_GUID_LEN];
    unsigned char   byRetryGUIDTime;    //剩余可导入/导出GUID次数
    unsigned char   bySurplusLockTime;  //剩余时间，单位：分钟，用户锁定时此参数有效
    unsigned char   byRes[254];
}SADP_GUID_FILE, *LPSADP_GUID_FILE;

typedef struct tagSADP_SINGLE_SECURITY_QUESTION_CFG
{
    unsigned int    dwSize;
    unsigned int    dwId;//序号
    char            szAnswer[MAX_ANSWER_LEN/*256*/];//答案，只在设置时有效，获取时无效
    unsigned char   byMark;//标记该序号的问题是否被设置  0-未设置 1-已设置
    unsigned char   byRes[127];
}SADP_SINGLE_SECURITY_QUESTION_CFG, *LPSADP_SINGLE_SECURITY_QUESTION_CFG;

typedef struct tagSADP_SECURITY_QUESTION_CFG
{
    unsigned int   dwSize;
    SADP_SINGLE_SECURITY_QUESTION_CFG  struSecurityQuestion[MAX_QUESTION_LIST_LEN/*32*/];//安全问题列表
    char           szPassword[MAX_PASS_LEN];  //用户密码
    unsigned char  byRes[512];
}SADP_SECURITY_QUESTION_CFG, *LPSADP_SECURITY_QUESTION_CFG;

typedef struct tagSADP_SECURITY_QUESTION
{
    unsigned char   byRetryAnswerTime;  //剩余可设置安全问题次数
    unsigned char   bySurplusLockTime;  //剩余时间，单位：分钟，用户锁定时此参数有效
    unsigned char   byRes[254];
}SADP_SECURITY_QUESTION, *LPSADP_SECURITY_QUESTION;

typedef struct tagSADP_RESET_PARAM_V40
{
    unsigned int    dwSize;
    unsigned char   byResetType;              //密码重置类型 0-保留,1- 通过设备序列号恢复默认密码，2-导入/导出文件重置密码，3-二维码重置， 4-GUID重置，5-安全问题重置 6-邮箱重置密码
    unsigned char   byEnableSyncIPCPW;        //是否同时将密码启用为NVR同步IPC密码。0 - 不启用， 1- 启用
    unsigned char   byRes2[2];                //保留
    char            szPassword[MAX_PASS_LEN]; //用户密码
    char            szCode[MAX_ENCRYPT_CODE]; //日期转换过的特殊字符串或加密工具加密后的字符串 - byResetType 为1、3时有效
    char            szAuthFile[MAX_FILE_PATH_LEN];//重置授权文件， byResetType 为2时有效
    char            szGUID[MAX_GUID_LEN];     //GUID, byResetType 为4时有效
    SADP_SECURITY_QUESTION_CFG struSecurityQuestionCfg;//安全问题结构体， byResetType 为5时有效
    unsigned char   byRes[512];
}SADP_RESET_PARAM_V40, *LPSADP_RESET_PARAM_V40;

typedef struct tagSADP_RET_RESET_PARAM_V40
{
    unsigned char   byRetryGUIDTime;    //剩余可设置次数
    unsigned char   bySurplusLockTime;  //剩余时间，单位：分钟，用户锁定时此参数有效
    unsigned char   bRetryTimeValid; //byRetryGUIDTime字段是否有效  0-无效,1-有效
    unsigned char   bLockTimeValid; //bySurplusLockTime字段是否有效  0-无效,1-有效
    unsigned char   byRes[252];
}SADP_RET_RESET_PARAM_V40, *LPSADP_RET_RESET_PARAM_V40;

//HCPlatform状态
typedef struct tagSADP_HCPLATFORM_STATUS_INFO
{
    unsigned int    dwSize;
    unsigned char   byEnableHCPlatform;        //是否启用HCPlatform。0 - 保留， 1- 启用， 2-不启用
    unsigned char   byRes[3];                  //保留
    char            szPassword[MAX_PASS_LEN];  //用户密码
    unsigned char   byRes2[128];
}SADP_HCPLATFORM_STATUS_INFO, *LPSADP_HCPLATFORM_STATUS_INFO;

typedef struct tagSADP_USER_MAILBOX
{
    unsigned int    dwSize;
    char            szPassword[MAX_PASS_LEN];        //设备admin用户密码
    char            szMailBoxAddr[MAX_MAILBOX_LEN];  //预留邮箱地址，用于接收密码服务器返回的安全码
    unsigned char   byRes[128];
}SADP_USER_MAILBOX, *LPSADP_USER_MAILBOX;
//设备验证码
typedef struct tagSADP_VERIFICATION_CODE_INFO
{
    unsigned int    dwSize;
    char            szVerificationCode[SADP_MAX_VERIFICATION_CODE_LEN];  //验证码（验证码用于萤石接入、预览、控制的唯一密码）
    char            szPassword[MAX_PASS_LEN];  //用户密码
    unsigned char   byRes[128];
}SADP_VERIFICATION_CODE_INFO, *LPSADP_VERIFICATION_CODE_INFO;

//设备锁定信息
typedef struct tagSADP_DEV_LOCK_INFO
{
    unsigned char   byRetryTime;       //剩余可尝试次数
    unsigned char   bySurplusLockTime; //剩余时间，单位：分钟，用户锁定时此参数有效
    unsigned char   byRes[126];
}SADP_DEV_LOCK_INFO, *LPSADP_DEV_LOCK_INFO;

//被绑定设备信息结构体
typedef struct tagSADP_BIND_INFO
{
    char            szSerialNO[SADP_MAX_SERIALNO_LEN]; //被绑定设备的序列号
    unsigned char   byiBind; //设备是否绑定 0-未绑定；1-已绑定
    unsigned char   byRes[127];
}SADP_BIND_INFO, *LPSADP_BIND_INFO;

typedef struct tagSADP_BIND_LIST
{
    SADP_BIND_INFO   struBindInfo[SADP_MAX_BIND_NUM]; //绑定设备信息列表
    char             szPassword[MAX_PASS_LEN]; //用户密码
    unsigned char    byUnbindAll; //是否解绑所有设备 0-不解绑所有设备；1-解绑所有设备
    unsigned char    byRes[127];
}SADP_BIND_LIST, *LPSADP_BIND_LIST;

typedef struct tagSADP_INACTIVE_INFO
{
    char             szPassword[MAX_PASS_LEN];  //用户密码
    unsigned char    byRes[128];
}SADP_INACTIVE_INFO, *LPSADP_INACTIVE_INFO;

//wifi Region
typedef struct tagSADP_WIFI_REGION_INFO
{
    unsigned char   byMode;                  //模式，0-保留，1-wifi区域配置模式，2-wifi增强模式
    unsigned char   byWifiRegion;            //wifi区域，当byMode为1时，该字段有效。0 -default， 1- china, 2-nothAmerica,3-japan,4-europe,5-world
    unsigned char   byWifiEnhancementEnabled;//是否启用wifi增强模式，当byMode为2时，该字段有效 0 -不启用， 1- 启用
    unsigned char   byRes;                   //保留
    char            szPassword[MAX_PASS_LEN];//用户密码
    unsigned char   byRes2[128];
}SADP_WIFI_REGION_INFO, *LPSADP_WIFI_REGION_INFO;

//通道默认密码信息
typedef struct tagSADP_CHANNEL_DEFAULT_PASSWORD
{
    char             szPassword[MAX_PASS_LEN]; //设备admin用户密码
    char             szChannelDefaultPassword[MAX_PASS_LEN]; //通道默认密码（用户NVR激活，添加IPC）
    unsigned char    byRes[128];
}SADP_CHANNEL_DEFAULT_PASSWORD, *LPSADP_CHANNEL_DEFAULT_PASSWORD;


//设备自检状态结构体
typedef struct tagSADP_SELF_CHECK_STATE
{
    unsigned int    dwSize;
    int             dwTotalDisk;               //磁盘总数（默认值为-1）
    int             dwGoodDisk;                //好盘数（默认值为-1）
    char            szCPU[MAX_CPU_LEN];        //CPU
    char            szMemory[MAX_MEMORY_LEN];  //内存
    unsigned char   byProgress;                //自检进度，0-100
    unsigned char   byTemperatureState;        //温度状态，0-无效；1-正常；2-异常
    unsigned char   byFanState;                //风扇状态，0-无效；1-正常；2-异常
    unsigned char   byPowerState;              //电源状态，0-无效；1-正常；2-异常
    unsigned char   bySASConnectState;         //SAS连接状态，0-无效；1-连接；2-未连接
    char            byTotalNetworkPort;        //网口总数（默认值为-1）
    char            byConnectNetworkPort;      //网口连接数（默认值为-1）
    unsigned char   byRes[129];
}SADP_SELF_CHECK_STATE, *LPSADP_SELF_CHECK_STATE;

//EHome使能参数
typedef struct tagSADP_EHOME_ENABLE_PARAM
{
    unsigned int    dwSize;
    char            szDevID[MAX_PASS_LEN];     //设备ID
    char            szEhomeKey[MAX_PASS_LEN];  //Ehome Key
    char            szPassword[MAX_PASS_LEN];  //设备密码
    unsigned char   byRes[64];
}SADP_EHOME_ENABLE_PARAM, *LPSADP_EHOME_ENABLE_PARAM;

//WIFI参数配置结构体
typedef struct tagSADP_WIFI_CONFIG_PARAM
{
    unsigned int    dwSize;
    char            szSSID[SADP_MAX_SERIALNO_LEN];      //SSID
    char            szPassword[SADP_MAX_SERIALNO_LEN];  //Password
    unsigned char   byWifiMode;  //wifi模式，0-默认，1-Station， 2-AP
    unsigned char   byRes[64];
}SADP_WIFI_CONFIG_PARAM, *LPSADP_WIFI_CONFIG_PARAM;

//已配置重置密码类型参数配置结构体
typedef struct tagSADP_PASSWORD_RESET_TYPE_PARAM
{
    unsigned int    dwSize;
    unsigned char   byEnable;  //0-未配置  1-（GUID，安全问题，安全邮箱，HC）配置过一种或多种 
    unsigned char   byGuidEnabled;  //0-未导出过GUID  1-导出过GUID
    unsigned char   bySecurityQuestionEnabled;  //0-未配置过安全问题  1-配置过安全问题
    unsigned char   bySecurityMailBoxEnabled;  //0-未配置过安全邮箱  1-配置过安全邮箱
    unsigned char   byHikConnectEnabled;  //0-未绑定HikConnect账号  1-绑定过HikConnect账号
    unsigned char   byRes1[3];
    unsigned char   byRes[64];
}SADP_PASSWORD_RESET_TYPE_PARAM, *LPSADP_PASSWORD_RESET_TYPE_PARAM;

//配置萤石用户token结构体
typedef struct tagSADP_EZVIZ_USER_TOKEN_PARAM
{
    unsigned int    dwSize;
    char            szToken[MAX_TOKEN_LEN]; //token，8-16字节
    char            szPassword[MAX_PASS_LEN]; //password，8-16字节
    unsigned char   byRes[256];
}SADP_EZVIZ_USER_TOKEN_PARAM, *LPSADP_EZVIZ_USER_TOKEN_PARAM;


//-----------------------------------------------------------------接口-----------------------------------------------------------------

//回调函数
typedef void (CALLBACK *PDEVICE_FIND_CALLBACK)(const SADP_DEVICE_INFO *lpDeviceInfo, void *pUserData);
typedef void (CALLBACK *PDEVICE_FIND_CALLBACK_V40)(const SADP_DEVICE_INFO_V40 *lpDeviceInfo, void *pUserData);

//启动sadp服务
CSADP_API BOOL CALLBACK SADP_Start_V30(PDEVICE_FIND_CALLBACK pDeviceFindCallBack, int bInstallNPF = 0, void* pUserData = NULL);
CSADP_API BOOL CALLBACK SADP_Start_V40(PDEVICE_FIND_CALLBACK_V40 pDeviceFindCallBack, int bInstallNPF = 0, void* pUserData = NULL);

//停止sadp服务
CSADP_API BOOL CALLBACK SADP_Stop(void);

//激活设备
CSADP_API BOOL CALLBACK SADP_ActivateDevice(const char* sDevSerialNO, const char* sCommand);

//修改网络参数 （优先使用SADP_ModifyDeviceNetParam_V40）
CSADP_API BOOL CALLBACK SADP_ModifyDeviceNetParam(const char* sMAC, const char* sPassword, const SADP_DEV_NET_PARAM *lpNetParam);
CSADP_API BOOL CALLBACK SADP_ModifyDeviceNetParam_V40(const char* sMAC, const char* sPassword, const SADP_DEV_NET_PARAM *lpNetParam, SADP_DEV_RET_NET_PARAM *lpRetNetParam, unsigned int  dwOutBuffSize);

//重置密码 （优先使用SADP_ResetPasswd_V40）
CSADP_API BOOL CALLBACK SADP_ResetDefaultPasswd(const char* sDevSerialNO, const char* sCommand);
CSADP_API BOOL CALLBACK SADP_ResetPasswd(const char* sDevSerialNO, const SADP_RESET_PARAM *pResetParam);
CSADP_API BOOL CALLBACK SADP_ResetPasswd_V40(const char* sDevSerialNO, const SADP_RESET_PARAM_V40 *pResetParam, SADP_RET_RESET_PARAM_V40 *pRetResetParam);

//参数配置
CSADP_API BOOL CALLBACK SADP_GetDeviceConfig(const char* sDevSerialNO, unsigned int dwCommand, void* lpInBuffer, unsigned int  dwinBuffSize, void *lpOutBuffer, unsigned int  dwOutBuffSize);
CSADP_API BOOL CALLBACK SADP_SetDeviceConfig(const char* sDevSerialNO, unsigned int dwCommand, void* lpInBuffer, unsigned int  dwInBuffSize, void* lpOutBuffer, unsigned int  dwOutBuffSize);
CSADP_API BOOL CALLBACK SADP_GetDeviceConfigByMAC(const char* sDevMAC, unsigned int dwCommand, void* lpInBuffer, unsigned int  dwinBuffSize, void *lpOutBuffer, unsigned int  dwOutBuffSize);

//设置SDK内部自动搜索间隔
CSADP_API void CALLBACK SADP_SetAutoRequestInterval(unsigned int dwInterval); //设置自动搜索时间间隔(单位秒，为0则不自动请求，默认60s)

//触发一次局域网搜索
CSADP_API BOOL CALLBACK SADP_SendInquiry(void);

//清理SDK内部设备缓存列表
CSADP_API BOOL CALLBACK SADP_Clearup(void);

//设置设备过滤规则
//dwFilterRule,按位表示，为1表示过滤，全0表示不过滤;0x01:过滤萤石设备;0x02:过滤OEM设备;0x03:过滤萤和OEM设备;0xfffffffe:仅显示萤石设备;0xfffffffd:仅显示OEM设备
CSADP_API BOOL CALLBACK SADP_SetDeviceFilterRule( unsigned int dwFilterRule, const void *lpInBuff, unsigned int dwInBuffLen);

//获取SDK版本
CSADP_API unsigned int CALLBACK SADP_GetSadpVersion(void);

//开启SDK日志
CSADP_API BOOL CALLBACK SADP_SetLogToFile(int nLogLevel=0, char const *strLogDir = NULL, int bAutoDel = 1);

//获取错误码
CSADP_API unsigned int CALLBACK SADP_GetLastError(void);
#endif




