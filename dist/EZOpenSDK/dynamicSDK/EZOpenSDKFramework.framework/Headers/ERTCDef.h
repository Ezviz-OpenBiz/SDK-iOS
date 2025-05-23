//
//  ERTCDef.h
//  ERTC
//
//  Created by Harper Kan on 2021/11/1.
//

#ifndef ERTCDef_h
#define ERTCDef_h
#import <Foundation/Foundation.h>



#define NetworkQualityDescs (@[@"未知", @"非常好", @"比较好", @"一般", @"较差", @"很差", @"不可用", @"无法检测", @"检测中"])

typedef NS_ENUM(NSInteger, ERTCVideoStreamType) {

    ///高清大画面，一般用来传输摄像头的视频数据。
    ERTCVideoStreamTypeBig = 0,

    ///低清小画面：小画面和大画面的内容相互，但是分辨率和码率都比大画面低，因此清晰度也更低。
    ERTCVideoStreamTypeSmall = 1,

    ///辅流画面：一般用于屏幕分享，同一时间在同一个房间中只允许一个用户发布辅流视频，其他用户必须要等该用户关闭之后才能发布自己的辅流。
    ERTCVideoStreamTypeSub = 2,

};

typedef NS_ENUM(NSUInteger, ERTCAppScene) {
    
    ///视频通话
    ERTCAppScene_VideoCall = 0,
};

typedef NS_ENUM(NSUInteger, ERTCAudioEncodeType) {
    ERTCAudioEncodeType_AAC = 0,//AAC编码
    ERTCAudioEncodeType_Opus = 1,//Opus编码
};

typedef NS_ENUM(NSInteger, ERTCStreamType) {

    ///视频大码流
    ERTCStreamTypeBigVideo = 0,

    ///视频小码流
    ERTCStreamTypeSmallVideo = 1,

    ///屏幕共享流
    ERTCStreamTypeScreen = 2,
    
    ///音频流
    ERTCStreamTypeAudio = 3,
    
    ///无效类型
    ERTCStreamTypeInValid = -1

};


typedef NS_ENUM(NSUInteger, ERTCVideoResolution) {
    
    ///宽高比 1:1；分辨率 120x120；建议码率（VideoCall）80kbps; 建议码率（LIVE）120kbps。
    ERTCVideoResolution_120_120 = 1,

    ///宽高比 1:1 分辨率 160x160；建议码率（VideoCall）100kbps; 建议码率（LIVE）150kbps。
    ERTCVideoResolution_160_160 = 3,

    ///宽高比 1:1；分辨率 270x270；建议码率（VideoCall）200kbps; 建议码率（LIVE）300kbps。
    ERTCVideoResolution_270_270 = 5,

    ///宽高比 1:1；分辨率 480x480；建议码率（VideoCall）350kbps; 建议码率（LIVE）500kbps。
    ERTCVideoResolution_480_480 = 7,

    ///宽高比4:3；分辨率 160x120；建议码率（VideoCall）100kbps; 建议码率（LIVE）150kbps。
    ERTCVideoResolution_160_120 = 50,

    ///宽高比 4:3；分辨率 240x180；建议码率（VideoCall）150kbps; 建议码率（LIVE）250kbps。
    ERTCVideoResolution_240_180 = 52,

    ///宽高比 4:3；分辨率 280x210；建议码率（VideoCall）200kbps; 建议码率（LIVE）300kbps。
    ERTCVideoResolution_280_210 = 54,

    ///宽高比 4:3；分辨率 320x240；建议码率（VideoCall）250kbps; 建议码率（LIVE）375kbps。
    ERTCVideoResolution_320_240 = 56,

    ///宽高比 4:3；分辨率 400x300；建议码率（VideoCall）300kbps; 建议码率（LIVE）450kbps。
    ERTCVideoResolution_400_300 = 58,

    ///宽高比 4:3；分辨率 480x360；建议码率（VideoCall）400kbps; 建议码率（LIVE）600kbps。
    ERTCVideoResolution_480_360 = 60,

    ///宽高比 4:3；分辨率 640x480；建议码率（VideoCall）600kbps; 建议码率（LIVE）900kbps。
    ERTCVideoResolution_640_480 = 62,

    ///宽高比 4:3；分辨率 960x720；建议码率（VideoCall）1000kbps; 建议码率（LIVE）1500kbps。
    ERTCVideoResolution_960_720 = 64,

    ///宽高比 16:9；分辨率 160x90；建议码率（VideoCall）150kbps; 建议码率（LIVE）250kbps。
    ERTCVideoResolution_160_90 = 100,

    ///宽高比 16:9；分辨率 256x144；建议码率（VideoCall）200kbps; 建议码率（LIVE）300kbps。
    ERTCVideoResolution_256_144 = 102,

    ///宽高比 16:9；分辨率 320x180；建议码率（VideoCall）250kbps; 建议码率（LIVE）400kbps。
    ERTCVideoResolution_320_180 = 104,

    ///宽高比 16:9；分辨率 480x270；建议码率（VideoCall）350kbps; 建议码率（LIVE）550kbps。
    ERTCVideoResolution_480_270 = 106,

    ///宽高比 16:9；分辨率 640x360；建议码率（VideoCall）500kbps; 建议码率（LIVE）900kbps。
    ERTCVideoResolution_640_360 = 108,

    ///宽高比 16:9；分辨率 960x540；建议码率（VideoCall）850kbps; 建议码率（LIVE）1300kbps。
    ERTCVideoResolution_960_540 = 110,

    ///宽高比 16:9；分辨率 1280x720；建议码率（VideoCall）1200kbps; 建议码率（LIVE）1800kbps。
    ERTCVideoResolution_1280_720 = 112,

    ///宽高比 16:9；分辨率 1920x1080；建议码率（VideoCall）2000kbps; 建议码率（LIVE）3000kbps。
    ERTCVideoResolution_1920_1080 = 114,
};

typedef NS_ENUM(NSUInteger, ERTCVideoFPS) {
    /** 1: 1 fps */
    ERTCVideoFPS_1 = 1,
    /** 2: 2 fps */
    ERTCVideoFPS_2 = 2,
    /** 3: 3 fps */
    ERTCVideoFPS_3 = 3,
    /** 4: 4 fps */
    ERTCVideoFPS_4 = 4,
    /** 5: 5 fps */
    ERTCVideoFPS_5 = 5,
    /** 6: 6 fps */
    ERTCVideoFPS_6 = 6,
    /** 7: 7 fps */
    ERTCVideoFPS_7 = 7,
    /** 8: 8 fps */
    ERTCVideoFPS_8 = 8,
    /** 9: 9 fps */
    ERTCVideoFPS_9 = 9,
    /** 10: 10 fps */
    ERTCVideoFPS_10 = 10,
    /** 11: 11 fps */
    ERTCVideoFPS_11 = 11,
    /** 12: 12 fps */
    ERTCVideoFPS_12 = 12,
    /** 13: 13 fps */
    ERTCVideoFPS_13 = 13,
    /** 14: 14 fps */
    ERTCVideoFPS_14 = 14,
    /** 15: 15 fps */
    ERTCVideoFPS_15 = 15,
    /** 16: 16 fps */
    ERTCVideoFPS_16 = 16,
    /** 17: 17 fps */
    ERTCVideoFPS_17 = 17,
    /** 18: 18 fps */
    ERTCVideoFPS_18 = 18,
    /** 19: 19 fps */
    ERTCVideoFPS_19 = 19,
    /** 20: 20 fps */
    ERTCVideoFPS_20 = 20,
    /** 21: 21 fps */
    ERTCVideoFPS_21 = 21,
    /** 22: 22 fps */
    ERTCVideoFPS_22 = 22,
    /** 23: 23 fps */
    ERTCVideoFPS_23 = 23,
    /** 24: 24 fps */
    ERTCVideoFPS_24 = 24,
    /** 25: 25 fps */
    ERTCVideoFPS_25 = 25,
    /** 30: 30 fps */
    ERTCVideoFPS_30 = 30,
    /** 60: 60 fps (Windows and macOS only) */
    ERTCVideoFPS_60 = 60,
};



typedef NS_ENUM(NSInteger, ERTCVideoFillMode) {

    ///填充模式：即将画面内容居中等比缩放以充满整个显示区域，超出显示区域的部分将会被裁剪掉，此模式下画面可能不完整。
    ERTCVideoFillMode_Fill = 0,

    ///适应模式：即按画面长边进行缩放以适应显示区域，短边部分会被填充为黑色，此模式下图像完整但可能留有黑边。
    ERTCVideoFillMode_Fit = 1,
    
    ///保持宽高比填充模式, 可能画面被裁剪
    ERTCVideoFillMode_AspectFill = 2

};

/**
 * 1.2 视频宽高比模式
 *
 * TRTCVideoResolution 中仅定义了横屏分辨率（如 640 × 360），如需使用竖屏分辨率（如360 × 640），需要同时指定 TRTCVideoResolutionMode 为 Portrait。
 */
typedef NS_ENUM(NSInteger, ERTCVideoResolutionMode) {

    ///横屏分辨率，例如：TRTCVideoResolution_640_360 + TRTCVideoResolutionModeLandscape = 640 × 360。
    ERTCVideoResolutionModeLandscape = 0,

    ///竖屏分辨率，例如：TRTCVideoResolution_640_360 + TRTCVideoResolutionModePortrait  = 360 × 640。
    ERTCVideoResolutionModePortrait = 1,

};

#pragma mark - 美肤操作类型
/**
 美肤操作类型
 
 - RTCBeautySkinBlurNone: 无
 - ERTCBeautySkinSmoothness: 磨皮
 - ERTCBeautySkinWhiteness: 美白
 - ERTCBeautySkinRuddyness: 红润
 - RTCBeautySkinToothWhiten: 美牙
 - RTCBeautySkinMax: 美肤类型个数
*/
typedef NS_ENUM(NSUInteger, ERTCBeautySkin) {
    ERTCBeautySkinBlurNone = 0,
    ERTCBeautySkinSmoothness,
    ERTCBeautySkinWhiteness,
    ERTCBeautySkinRuddyness,
    ERTCBeautySkinToothWhiten,
    ERTCBeautySkinMax
};

/**
 视频处理类型

 - ERTCBeautyDefineSkin: 美肤
 - ERTCBeautyDefineFilter: 滤镜
*/
typedef NS_ENUM(NSUInteger, ERTCBeautyDefine) {
    
    ERTCBeautyDefineSkin,
    ERTCBeautyDefineFilter
};
typedef NS_ENUM(NSUInteger, ERTCFilterType) {
    ERTC_Basic_Filter_Type_None = 0,
    ERTC_Basic_Filter_Type_1,
    ERTC_Basic_Filter_Type_2,
    ERTC_Basic_Filter_Type_3,
    ERTC_Basic_Filter_Type_4,
    ERTC_Basic_Filter_Type_5,
    ERTC_Basic_Filter_Type_6,
    ERTC_Basic_Filter_Type_7,
    ERTC_Basic_Filter_Type_8,
    ERTC_Basic_Filter_Type_9,
    ERTC_Basic_Filter_Type_10,
    ERTC_Basic_Filter_Type_11,
    ERTC_Basic_Filter_Type_12,
};





/// 视频编码参数
@interface ERTCVideoEncParam : NSObject

///【字段含义】 视频分辨率
///【特别说明】如需使用竖屏分辨率，请指定 resMode 为 Portrait，例如： 640 × 360 + Portrait = 360 × 640。
///【推荐取值】
/// - 手机视频通话：建议选择 360 × 640 及以下分辨率，resMode 选择 Portrait，即竖屏分辨率。
/// - 手机在线直播：建议选择 540 × 960，resMode 选择 Portrait，即竖屏分辨率。
/// - 桌面平台（Win + Mac）：建议选择 640 × 360 及以上分辨率，resMode 选择 Landscape，即横屏分辨率。
@property(nonatomic, assign) ERTCVideoResolution videoResolution;

@property(nonatomic, assign) ERTCVideoResolutionMode resMode;

///【字段含义】视频采集帧率
///【推荐取值】15fps或20fps。5fps以下，卡顿感明显。10fps以下，会有轻微卡顿感。20fps以上，会浪费带宽（电影的帧率为24fps）。
///【特别说明】部分 Android 手机的前置摄像头并不支持15fps以上的采集帧率，部分主打美颜功能的 Android 手机的前置摄像头的采集帧率可能低于10fps。
@property(nonatomic, assign) ERTCVideoFPS videoFps;

///【字段含义】目标视频码率，单位Kbps，SDK 会按照目标码率进行编码，只有在弱网络环境下才会主动降低视频码率。
///【推荐取值】请参考本 ERTCVideoResolution 在各档位注释的最佳码率，也可以在此基础上适当调高。
@property(nonatomic, assign) int videoBitrate;


/// 某分辨率推荐的码率
/// @param resolution 视频分辨率
+ (int)recommendedBitrateForRes:(ERTCVideoResolution)resolution;

/// 文字描述，比如 @"640*480”
/// @param res 视频分辨率
+ (NSString *)desForRes:(ERTCVideoResolution)res;

@end



/// 音量信息
@interface ERTCVolumeInfo : NSObject

///说话者的 userId, 如果 userId 为0则代表是当前用户自己。
@property(nonatomic, strong) NSString *userId;

///说话者的音量大小, 取值范围[0 - 100]。
@property(assign, nonatomic) int volume;

@end


/**
* 网络质量
*
* ERTC 会每隔两秒对当前的网络质量进行评估，评估结果为六个等级：Excellent 表示最好，Down 表示最差。
*/
typedef NS_ENUM(NSUInteger, ERTCNetworkQuality) {
    
    ///未定义
    ERTCNetworkQuality_Unknown = 0,

    ///当前网络非常好
    ERTCNetworkQuality_Excellent = 1,

    ///当前网络比较好
    ERTCNetworkQuality_Good = 2,

    ///当前网络一般
    ERTCNetworkQuality_Poor = 3,

    ///当前网络较差
    ERTCNetworkQuality_Bad = 4,

    ///当前网络很差
    ERTCNetworkQuality_Vbad = 5,

    ///当前网络不满足 TRTC 的最低要求
    ERTCNetworkQuality_Down = 6,

    ///暂时无法检测到网络质量
    ERTCNetworkQuality_Unsupported = 7,

    ///网络质量检测已开始还没有完成
    ERTCNetworkQuality_Detecting = 8,
};


typedef NS_ENUM(NSUInteger, ERTCSelfExitReason) {
    ERTCSelfExitReason_Ban = 1,
    ERTCSelfExitReason_Dissolve = 2,
};



#endif /* ERTCDef_h */
