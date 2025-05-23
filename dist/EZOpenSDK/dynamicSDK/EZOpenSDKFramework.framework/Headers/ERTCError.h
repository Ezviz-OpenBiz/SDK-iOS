//
//  ERTCError.h
//  ERTC
//
//  Created by Harper Kan on 2021/11/15.
//

#ifndef ERTCError_h
#define ERTCError_h


#define ERTC_ERROR_DOMAIN @"com.ezviz.ertc"
#define ERTC_ERROR_HTTP_SYSTEM_DOMAIN @"com.ezviz.http.system"
#define ERTC_ERROR_HTTP_API_DOMAIN @"https.open.ys7.com"



typedef enum : NSUInteger {
    
    ERTC_ERR_OK = 0,

    //一般性错误
    ERTC_ERR_BASE = 100000,
    //未知错误
    ERTC_ERR_UNKNOWN = ERTC_ERR_BASE + 1,
    //初始化失败
    ERTC_ERR_INIT_FAILED = ERTC_ERR_BASE + 2,
    //调用不支持
    ERTC_ERR_NOT_SUPPORT = ERTC_ERR_BASE + 3,
    //参数非法
    ERTC_ERR_INVALID_ARGUMENT = ERTC_ERR_BASE + 4,
    //调用被拒绝
    ERTC_ERR_REFUSED = ERTC_ERR_BASE + 5,
    //SDK尚未初始化
    ERTC_ERR_NOT_INIT = ERTC_ERR_BASE + 6,
    //调用超时
    ERTC_ERR_TIMEOUT = ERTC_ERR_BASE + 7,
    //房间内用户不存在
    ERTC_ERR_NOT_IN_ROOM = ERTC_ERR_BASE + 8,

    //房间相关错误
    ERTC_ERR_ROOM_BASE = ERTC_ERR_BASE + 1000,
    //进入房间失败
    ERTC_ERR_ROOM_ENTER_FAIL = ERTC_ERR_ROOM_BASE + 1,
    //进入房间参数错误
    ERTC_ERR_ROOM_INVALID_PARAMETER = ERTC_ERR_ROOM_BASE + 2,
    //不是有效的App ID
    ERTC_ERR_ROOM_INVALID_APPID = ERTC_ERR_ROOM_BASE + 3,
    //房间号无效
    ERTC_ERR_ROOM_INVALID_ROOM = ERTC_ERR_ROOM_BASE + 4,
    //无效的用户
    ERTC_ERR_ROOM_INVALID_USERID = ERTC_ERR_ROOM_BASE + 5,
    //无效token
    ERTC_ERR_ROOM_INVALID_TOKEN = ERTC_ERR_ROOM_BASE + 6,
    //进入房间超时
    ERTC_ERR_ROOM_ENTER_TIMEOUT = ERTC_ERR_ROOM_BASE + 7,
    //服务不可用
    ERTC_ERR_ROOM_INVALID_SERVICE = ERTC_ERR_ROOM_BASE + 8,
    //资源已被占用
    ERTC_ERR_ALREADY_IN_USE = ERTC_ERR_ROOM_BASE + 9,
    //进入房间密码错误
    ERTC_ERR_PASSWORD = ERTC_ERR_ROOM_BASE + 10,
    //服务超时
    ERTC_ERR_SEVER_TIMEOUT = ERTC_ERR_ROOM_BASE + 12,
    //房间已满
    ERTC_ERR_ROOMID_FULL = ERTC_ERR_ROOM_BASE + 20,
    //客户端心跳超时
    ERTC_ERR_CLIENT_KEEP_TIMEOUT = ERTC_ERR_ROOM_BASE + 25,
    //退出房间失败
    ERTC_ERR_ROOM_EXIT_FAIL = ERTC_ERR_ROOM_BASE + 501,


    //设备相关错误
    ERTC_ERR_DEVICE_BASE = ERTC_ERR_BASE + 2000,
    //设备未授权
    ERTC_ERR_DEVICE_NO_PERMISSION = ERTC_ERR_DEVICE_BASE + 1,
    //摄像头驱动异常
    ERTC_ERR_CAMERA_START_FAIL = ERTC_ERR_DEVICE_BASE + 2,
    //摄像头正在被占用中
    ERTC_ERR_CAMERA_BUSY = ERTC_ERR_DEVICE_BASE + 3,
    //摄像头参数设置出错（参数不支持或其它）
    ERTC_ERR_CAMERA_SET_PARAM_FAIL = ERTC_ERR_DEVICE_BASE + 4,
    //麦克风未知错误
    ERTC_ERR_MICROPHONE_UNKNOWN = ERTC_ERR_DEVICE_BASE + 401,
    //采集音频错误
    ERTC_ERR_MICROPHONE_CAPTURE_FAIL = ERTC_ERR_DEVICE_BASE + 402,
    //无麦克风或麦克风正在使用中
    ERTC_ERR_MICROPHONE_BUSY = ERTC_ERR_DEVICE_BASE + 403,
    //麦克风驱动异常
    ERTC_ERR_MICROPHONE_START_FAIL = ERTC_ERR_DEVICE_BASE + 404,
    //麦克风参数错误
    ERTC_ERR_MICROPHONE_SET_PARAM_FAIL = ERTC_ERR_DEVICE_BASE + 405,
    //停止麦克风失败
    ERTC_ERR_MICROPHONE_STOP_FAIL = ERTC_ERR_DEVICE_BASE + 406,
    //扬声器驱动异常
    ERTC_ERR_SPEAKER_START_FAIL = ERTC_ERR_DEVICE_BASE + 801,
    //扬声器设置参数失败
    ERTC_ERR_SPEAKER_SET_PARAM_FAIL = ERTC_ERR_DEVICE_BASE + 802,
    //播放音频错误
    ERTC_ERR_SPEAKER_PLAY_FAIL = ERTC_ERR_DEVICE_BASE + 803,
    //停止扬声器失败
    ERTC_ERR_SPEAKER_STOP_FAIL = ERTC_ERR_DEVICE_BASE + 804,

    //编解码错误
    ERTC_ERR_ED_BASE = ERTC_ERR_BASE + 3200,
    //视频编码失败
    ERTC_ERR_VIDEO_ENCODE_FAIL = ERTC_ERR_ED_BASE + 1,
    //不支持的视频分辨率
    ERTC_ERR_VIDEO_UNSUPPORT_RES = ERTC_ERR_ED_BASE + 2,
    //音频编码失败
    ERTC_ERR_AUDIO_ENCODE_FAIL = ERTC_ERR_ED_BASE + 3,
    //不支持的音频采样率
    ERTC_ERR_AUDIO_UNSUPPORT_SMAPLERATE = ERTC_ERR_ED_BASE + 4,
    //媒体模块加载失败
    ERTC_ERR_MEDIA_LOAD_FAILED = ERTC_ERR_ED_BASE + 5,
    
    
    //------------------------------------------
    ERTC_ERR_SERVICE_BASE = 200000,
    
    //以下错误码为iOS系统给出的网络错误，比如NSURLErrorNotConnectedToInternet，参考NSURLError.h头文件中 NSURLErrorDomain
    //没有网络连接 The Internet connection appears to be offline. NSURLErrorNotConnectedToInternet的值为-1009
    ERTC_ERR_SERVICE_NotConnectedToInternet = ERTC_ERR_SERVICE_BASE + 1009,
    
    
    //以下错误码为HTTP服务相关错误码（减去基值ERTC_ERR_SERVICE_BASE后）参考 https://open.ys7.com/doc/zh/book/index/api-code.html
    ///accessToken异常或过期
    ///
    ERTC_ERR_HTTP_BASE = 300000,
    ERTC_ERR_SERVICE_AccesstokenInvalid = ERTC_ERR_HTTP_BASE + 10002,
    
    
} ERTCError;


#endif /* ERTCError_h */
