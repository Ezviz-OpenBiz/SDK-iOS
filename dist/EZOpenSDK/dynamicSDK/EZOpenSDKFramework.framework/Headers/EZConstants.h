//
//  EZConstants.h
//  EzvizOpenSDK
//
//  Created by DeJohn Dong on 16/7/20.
//  Copyright © 2016年 Ezviz. All rights reserved.
//

#import <Foundation/Foundation.h>

//萤石开放平台委托方法
@protocol EZOpenSDKDelegate <NSObject>

@optional

/**
 萤石登录是否成功
 
 @param result 是否成功
 */
- (void)ezvizLoginResult:(BOOL)result;

@end

/* EZOpenSDK的错误定义 */
typedef NS_ENUM(NSInteger, EZErrorCode) {
    /**
     *  对讲错误码
     */
    EZ_DEVICE_TTS_REQUEST_TIMEOUT = 360001,           //客户端请求超时
    EZ_DEVICE_TTS_TALKING_TIMEOUT = 360002,           //对讲发起超时
    EZ_DEVICE_TTS_DEVICE_CONNECT_ERROR = 360003,      //TTS的设备端发生错误
    EZ_DEVICE_TTS_INTER_ERROR = 360004,               //TTS内部发生错误
    EZ_DEVICE_TTS_SEND_ERROR = 360005,                //客户端发送的消息错误
    EZ_DEVICE_TTS_RECEIVE_ERROR = 360006,             //客户端接收发生错误
    EZ_DEVICE_TTS_CLOSE_CONNECT = 360007,             //TTS关闭了与客户端的连接
    EZ_DEVICE_TTS_TALKING = 360010,                   //设备正在对讲中
    EZ_DEVICE_TTS_PRIVACY_PROTECT = 360013,           //设备开启了隐私保护
    EZ_DEVICE_TTS_INIT_ERROR = 360102,                //TTS初始化失败
    
    
    /**
     *  取流错误码
     */
    EZ_DEVICE_IS_PRIVACY_PROTECTING = 380011,         //设备隐私保护中
    EZ_DEVICE_CONNECT_COUNT_LIMIT = 380045,           //设备直连取流连接数量过大
    EZ_DEVICE_COMMAND_NOT_SUPPORT = 380047,           //设备不支持该命令
    EZ_DEVICE_CAS_TALKING = 380077,                   //设备正在对讲中
    EZ_DEVICE_CAS_REC_ERROR = 380102,                 //数据接收异常
    EZ_DEVICE_CAS_PARSE_ERROR = 380205,               //设备检测入参异常
    EZ_PLAY_TIMEOUT = 380209,                         //网络连接超时
    EZ_DEVICE_TIMEOUT = 380212,                       //设备端网络连接超时
    EZ_STREAM_CLIENT_TIMEOUT = 390038,                //同时`390037`手机网络引起的取流超时
    EZ_STREAM_CLIENT_NOT_FIND_FILE = 395402,          //回放找不到录像文件，检查传入的回放文件是否正确
    EZ_STREAM_CLIENT_OFFLINE = 395404,                //设备不在线
    EZ_STREAM_CLIENT_TOKEN_INVALID = 395406,          //取流token验证失效
    EZ_STREAM_CLIENT_PRIVACY_PROTECT = 395409,        //预览开启隐私保护,可以在萤石云APP中关闭
    EZ_STREAM_CLIENT_DEVICE_COUNT_LIMIT = 395410,     //设备连接数过大,有过多的终端正在对该设备进行取流操作
    EZ_STREAM_CLIENT_TOKEN_LIMIT  = 395411,           //token无权限
    EZ_STREAM_CLIENT_CAMERANO_ERROR = 395415,         //设备通道错
    EZ_STREAM_CLIENT_TYPE_UNSUPPORT = 395451,         //设备不支持的码流类型
    EZ_STREAM_CLIENT_CONNECT_SERVER_ERROR = 395452,   //设备连接预览流媒体服务器失败
    EZ_STREAM_CLIENT_SESSION_NOT_EXIST = 395454,      //会话不存在
    EZ_STREAM_CLIENT_SAME_REQUEST = 395491,           //相同请求正在处理，拒绝本次处理
    EZ_STREAM_CLIENT_INNER_ERROR = 395500,            //流媒体服务器内部处理错误
    EZ_STREAM_CLIENT_NO_SOURCE = 395544,              //设备返回无视频源
    EZ_STREAM_CLIENT_VIDEO_OUT_SHARE_TIME = 395545,   //视频分享时间已经结束
    EZ_STREAM_CLIENT_LIMIT = 395546,                  //设备取流受到限制，升级企业版可放开限制
    EZ_STREAM_CLIENT_DEVICE_OUT_SHARE_TIME = 395600,  //分享设备不在分享时间内
    
    /**
     *  HTTP 错误码
     */
    EZ_HTTPS_PARAM_ERROR = 110001,                    //请求参数错误
    EZ_HTTPS_ACCESS_TOKEN_INVALID = 110002,           //AccessToken无效
    EZ_HTTPS_ACCESS_TOKEN_EXPIRE = 110003,            //AccessToken过期
    EZ_HTTPS_REGIST_USER_NOT_EXSIT = 110004,          //注册用户不存在
    EZ_HTTPS_APPKEY_ERROR = 110005,                   //AppKey异常
    EZ_HTTPS_IP_LIMIT = 110006,                       //ip受限
    EZ_HTTPS_INVOKE_LIMIT = 110007,                   //调用次数达到上限
    EZ_HTTPS_USER_BINDED = 110012,                    //第三方账户与萤石账号已经绑定
    EZ_HTTPS_APPKEY_IS_NULL = 110017,                 //AppKey不存在
    EZ_HTTPS_APPKEY_NOT_MATCHED = 110018,             //AppKey不匹配，请检查服务端设置的appKey是否和SDK使用的appKey一致
    EZ_HTTPS_CAMERA_NOT_EXISTS = 120001,              //通道不存在，请检查摄像头设备是否重新添加过
    EZ_HTTPS_DEVICE_NOT_EXISTS = 120002,              //设备不存在
    EZ_HTTPS_DEVICE_NETWORK_ANOMALY = 120006,         //网络异常
    EZ_HTTPS_DEVICE_OFFLINE = 120007,                 //设备不在线
    EZ_HTTPS_DEIVCE_RESPONSE_TIMEOUT = 120008,        //设备请求响应超时异常
    EZ_HTTPS_DEVICE_VALICATECODE_ERROR = 120010,      //设备验证码错误
    EZ_HTTPS_ILLEGAL_DEVICE_SERIAL = 120014,          //不合法的序列号
    EZ_HTTPS_DEVICE_STORAGE_FORMATTING = 120016,      //设备正在格式化磁盘
    EZ_HTTPS_DEVICE_ADDED_MYSELF = 120017,            //同`120020`设备已经被自己添加
    EZ_HTTPS_USER_NOT_OWN_THIS_DEVICE = 120018,       //该用户不拥有该设备
    EZ_HTTPS_DEVICE_UNSUPPORT_CLOUD = 120019,         //设备不支持云存储服务
    EZ_HTTPS_DEVICE_ONLINE_ADDED = 120020,            //设备在线，被自己添加
    EZ_HTTPS_DEVICE_ONLINE_NOT_ADDED = 120021,        //设备在线，未被用户添加
    EZ_HTTPS_DEVICE_ONLINE_IS_ADDED = 120022,         //设备在线，已经被别的用户添加
    EZ_HTTPS_DEVICE_OFFLINE_NOT_ADDED = 120023,       //设备不在线，未被用户添加
    EZ_HTTPS_DEVICE_OFFLINE_IS_ADDED = 120024,        //设备不在线，已经被别的用户添加
    EZ_HTTPS_DEVICE_OFFLINE_IS_ADDED_MYSELF = 120029, //设备不在线，但是已经被自己添加
    EZ_HTTPS_DEVICE_BUNDEL_STATUS_ON = 120031,        //同时`106002`错误码也是，设备开启了终端绑定，请到萤石云客户端关闭终端绑定
    EZ_HTTPS_OPERATE_LEAVE_MSG_FAIL = 120202,         //操作留言消息失败
    EZ_HTTPS_SERVER_DATA_ERROR = 149999,              //数据异常
    EZ_HTTPS_SERVER_ERROR = 150000,                   //服务器异常
    EZ_HTTPS_CLOUD_DELETE_ALL_EXCEPT_LAST = 150002,   //云存储视频删除完成，除了最后一个在录制的视频无法删除
    EZ_HTTPS_DEVICE_PTZ_NOT_SUPPORT = 160000,         //设备不支持云台控制
    EZ_HTTPS_DEVICE_PTZ_NO_PERMISSION = 160001,       //用户没有权限操作云台控制
    EZ_HTTPS_DEVICE_PTZ_UPPER_LIMIT = 160002,         //云台达到上限位（顶部）
    EZ_HTTPS_DEVICE_PTZ_FLOOR_LIMIT = 160003,         //云台达到下限位（底部）
    EZ_HTTPS_DEVICE_PTZ_LEFT_LIMIT = 160004,          //云台达到左限位（最左边）
    EZ_HTTPS_DEVICE_PTZ_RIGHT_LIMIT = 160005,         //云台达到右限位（最右边）
    EZ_HTTPS_DEVICE_PTZ_FAILED = 160006,              //云台操作失败
    EZ_HTTPS_DEVICE_PTZ_RESETING = 160009,            //云台正在调用预置点
    EZ_HTTPS_DEVICE_COMMAND_NOT_SUPPORT = 160020,     //设备抓图失败，不支持抓图
    
    /**
     *  接口 错误码(SDK本地校验)
     */
    EZ_SDK_PARAM_ERROR = 400002,                      //接口参数错误
    EZ_SDK_NOT_SUPPORT_TALK = 400025,                 //设备不支持对讲
    EZ_SDK_TIMEOUT = 400034,                          //无播放token，请stop再start播放器
    EZ_SDK_NEED_VALIDATECODE = 400035,                //需要设备验证码
    EZ_SDK_VALIDATECODE_NOT_MATCH = 400036,           //设备验证码不匹配
    EZ_SDK_DECODE_TIMEOUT = 400041,                   //解码超时，可能是验证码错误
    EZ_SDK_STREAM_TIMEOUT = 400015,                   //取流超时,请检查手机网络
    EZ_SDK_PLAYBACK_STREAM_TIMEOUT = 400409,          //回放取流超时,请检查手机网络
    EZ_SDK_STREAM_NO_PERMISSION = 400907,             //取流无权限，设备拥有者、设备托管者、设备分享者 3个权限都没有时，禁止取流
    
    /**
     *  NPC取流错误码
     */
    EZ_NPC_CLIENT_PARAMETER_ERROR = 500001,           //参数错误
    EZ_NPC_CLIENT_ORDER_ERROR = 500002,               //调用顺序出错
    EZ_NPC_CLIENT_MEMORY_ERROR = 500003,              //分配内存失败
    EZ_NPC_CLIENT_BUFFER_OVERFLOW_ERROR = 500004,     //缓冲区溢出
    EZ_NPC_CLIENT_SYSTEM_NO_SUPPORT_ERROR = 500005,   //系统不支持
    EZ_NPC_CLIENT_INVALID_PORT_ERROR = 500006,        //无效端口
    EZ_NPC_CLIENT_STREAM_CLOSE_ERROR = 500101,        //流关闭
    EZ_NPC_CLIENT_TRACK_CLOSE_ERROR = 500102,         //TRACK_CLOSE
    EZ_NPC_CLIENT_NPCCREATE_ERROR = 500103,           //创建失败
    EZ_NPC_CLIENT_TRSCREATE_ERROR = 500104,           //TRSCREATE_ERROR
    EZ_NPC_CLIENT_FAIL_UNKNOWN_ERROR = 509999,        //FAIL_UNKNOWN
};

/* 设备ptz命令，定义的值与Android定义的不一样，SDK会在内部会做一层转换 */
typedef NS_OPTIONS(NSUInteger, EZPTZCommand) {
    EZPTZCommandLeft            = 1 << 0, //向左旋转
    EZPTZCommandRight           = 1 << 1, //向右旋转
    EZPTZCommandUp              = 1 << 2, //向上旋转
    EZPTZCommandDown            = 1 << 3, //向下旋转
    EZPTZCommandZoomIn          = 1 << 4, //镜头拉进
    EZPTZCommandZoomOut         = 1 << 5, //镜头拉远
};

/*
 * 设备显示命令
 */
typedef NS_OPTIONS(NSUInteger, EZDisplayCommand) {
    EZDisplayCommandCenter          = 1 << 0, //显示中间
};

/**
 *  设备ptz动作命令
 */
typedef NS_ENUM(NSInteger, EZPTZAction) {
    EZPTZActionStart = 1, //ptz开始
    EZPTZActionStop = 2   //ptz停止
};

/* 消息状态 */
typedef NS_ENUM(NSInteger, EZMessageStatus) {
    EZMessageStatusRead = 1,    //已读
};

/* 消息类型 */
typedef NS_ENUM(NSInteger, EZMessageType)
{
    EZMessageTypeAlarm = 1,   //告警类型
    EZMessageTypeLeave,       //留言类型
};

/* 留言消息类型 */
typedef NS_ENUM(NSInteger, EZLeaveMessageType)
{
    EZLeaveMessageTypeAll,    //全部
    EZLeaveMessageTypeVoice,  //语音类
    EZLeaveMessageTypeVideo,  //视频类
};

/* 设备布防状态枚举类型 */
typedef NS_ENUM(NSInteger, EZDefenceStatus) {
    EZDefenceStatusOffOrSleep     = 0,  //A1设备睡眠模式或者非A1设备的撤防状态
    EZDefenceStatusOn             = 1,  //非A1设备的布防状态
    EZDefenceStatusAtHome         = 8,  //A1在家模式
    EZDefenceStatusOuter          = 16, //A1外出模式
};

/* 视频质量 */
typedef NS_ENUM(NSInteger, EZVideoQualityType) {
    EZVideoQualityTypeNone                = 0,  //默认值
    EZVideoQualityTypePerformancePriority = 1,  //性能优先
    EZVideoQualityTypeQualityPriority     = 2   //质量优先
};

/* 通道清晰度，请注意不是所有设备都有这些清晰度的，请根据实际场景使用 */
typedef NS_ENUM(NSInteger, EZVideoLevelType) {
    EZVideoLevelLow       = 0,  //流畅
    EZVideoLevelMiddle    = 1,  //均衡
    EZVideoLevelHigh      = 2,  //高清
    EZVideoLevelSuperHigh = 3,  //超清
    EZVideoLevelExtremeHigh = 4,//极清
    EZVideoLevel3K = 5,         //3K
    EZVideoLevel4K = 6          //4K
};

/* 录像类型 */
typedef NS_ENUM(NSUInteger, EZVideoRecordType) {
    EZVideoRecordTypeAll,     // 所有类型
    EZVideoRecordTypeCMR,     // 定时录像
    EZVideoRecordTypeEvent    // 事件类型
};

/* 录像类型扩展 */
typedef NS_ENUM(NSUInteger, EZVideoRecordTypeEx) {
    EZVideoRecordTypeExNone = 0,        // 无效值
    EZVideoRecordTypeExCMR ,            // 定时录像
    EZVideoRecordTypeExEvent,           // 事件录像
    EZVideoRecordTypeExCar,             // 智能-车录像
    EZVideoRecordTypeExPerson,          // 智能-人型录像
    EZVideoRecordTypeExComPressAuTo,    // 自动浓缩录像
    EZVideoRecordTypeExComPressCMR,     // 定时浓缩录像
    EZVideoRecordTypeExComPressManual   // 手动浓缩录像
};

/* 云存储录像类型 */
typedef NS_ENUM(NSInteger, EZCloudVideoType) {
    EZCloudVideoTypeAll = -1,   // 全部录像
    EZCloudVideoTypeSeries = 1, // 连续录像
    EZCloudVideoTypeAct = 2     // 活动录像
};

/* 鱼眼设备矫正模式 */
typedef NS_ENUM(NSInteger, EZFecCorrectType) {
    EZFecCorrectTypeNone            = 0,
    EZFecCorrectType4PTZ            = 1,            // 4分屏                  1
    EZFecCorrectType180             = 1<<1,         // 180°全景               2
    EZFecCorrectType360             = 1<<2,         // 360°全景               4
    EZFecCorrectTypeFish            = 1<<3,         // 支持鱼眼（原始码流）      8
    EZFecCorrectTypeLAT             = 1<<4,         // 水平-维度拉伸           16
    EZFecCorrectTypeARC_Hor         = 1<<5,         // 水平ARC                32
    EZFecCorrectTypeARC_Ver         = 1<<6,         // 垂直ARC                64
//    EZFecCorrectTypePicInPic        = 1<<7        // 画中画                 128
    EZFecCorrectTypeFull5PTZ        = 1<<8,         // 全景5分屏               256
    EZFecCorrectType5PTZ            = 1<<9,         // 5分屏                  512
    EZFecCorrectTypeCYC             = 1<<10,        // 圆柱显示（桶形）         1024
    EZFecCorrectTypeWideAngle       = 1<<11,        // 广角                   2048
//    EZFecCorrectTypeTiled           = 1<<12,        // 平铺                   4096
//    EZFecCorrectTypeListeningRecognition = 1<<13    // 辅助画中画听声辩位模式
};

/* 鱼眼设备矫正模式 */
typedef NS_ENUM(NSInteger, EZFecPlaceType) {
    EZFecPlaceTypeNone = 0,   // 不矫正
    EZFecPlaceTypeWall = 1,   // 壁装
    EZFecPlaceTypeFloor = 2,  // 底装/桌面
    EZFecPlaceTypeCeiling = 3 // 顶装
};

/* 变声类型 */
typedef NS_ENUM(NSInteger, EZVoiceChangeType) {
    EZVoiceChangeTypeMan = -7,   // 大叔音
    EZVoiceChangeTypeNormal = 0, // 原音
    EZVoiceChangeTypeClown = 7   // 小丑音
};

// 客户端/设备端带宽检测类型
typedef NS_ENUM(NSUInteger, EZBandWidthType) {
    EZBandWidthTypeClientUpward = 1, // 客户端上行
    EZBandWidthTypeClientDownward,   // 客户端下行
    EZBandWidthTypeDeviceUpward,     // 设备端上行
    EZBandWidthTypeDeviceDownward    // 设备端下行
};

// 播放画面旋转角度
typedef NS_ENUM(NSUInteger, EZPlayerViewRotationAngle) {
    EZPlayerViewRotationAngle0 = 0,     // 默认画面，未旋转
    EZPlayerViewRotationAngle90 = 90,   // 旋转90°
    EZPlayerViewRotationAngle180 = 180, // 旋转180°
    EZPlayerViewRotationAngle270 = 270  // 旋转270°
};

/// 开放平台常量类
@interface EZConstants : NSObject

@end
