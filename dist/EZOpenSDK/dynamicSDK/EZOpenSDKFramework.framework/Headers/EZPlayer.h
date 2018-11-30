//
//  EZPlayer.h
//  EzvizOpenSDK
//
//  Created by DeJohn Dong on 15/9/16.
//  Copyright (c) 2015年 Hikvision. All rights reserved.
//

#import <UIKit/UIKit.h>

@class EZDeviceRecordFile;
@class EZCloudRecordFile;
@class EZPlayer;
/**
 *  预览清晰度
 */
typedef NS_ENUM(NSInteger, EZVideoQuality) {
    EZVideoQualityLow    = 0,  //流畅
    EZVideoQualityMiddle = 1,  //均衡
    EZVideoQualityHigh   = 2   //高清
};

/* 播放器EZPlayer的状态消息定义 */
typedef NS_ENUM(NSInteger, EZMessageCode) {
    PLAYER_REALPLAY_START = 1,        //直播开始
    PLAYER_VIDEOLEVEL_CHANGE = 2,     //直播流清晰度切换中
    PLAYER_STREAM_RECONNECT = 3,      //直播流取流正在重连
    PLAYER_VOICE_TALK_START = 4,      //对讲开始
    PLAYER_VOICE_TALK_END = 5,        //对讲结束
    PLAYER_STREAM_START = 10,         //录像取流开始
    PLAYER_PLAYBACK_START = 11,       //录像回放开始播放
    PLAYER_PLAYBACK_STOP = 12,        //录像回放结束播放
    PLAYER_PLAYBACK_FINISHED = 13,    //录像回放被用户强制中断
    PLAYER_PLAYBACK_PAUSE = 14,       //录像回放暂停
    PLAYER_NET_CHANGED = 21,          //播放器检测到wifi变换过
    PLAYER_NO_NETWORK = 22,           //播放器检测到无网络
};


/**
 *  SD卡回放速率
 */
typedef NS_ENUM(NSInteger, EZPlaybackRate) {
    EZ_PLAYBACK_RATE_1 = 1,         // 1倍速
    EZ_PLAYBACK_RATE_2,             // 2倍速
    EZ_PLAYBACK_RATE_2_1,           // 1/2倍速
    EZ_PLAYBACK_RATE_4,             // 4倍速
    EZ_PLAYBACK_RATE_4_1,           // 1/4倍速
    EZ_PLAYBACK_RATE_8,             // 8倍速
    EZ_PLAYBACK_RATE_8_1,           // 1/8倍速
};

/**
 *  云存储回放速率
 */
typedef NS_ENUM(NSInteger, EZCloudPlaybackRate) {
    EZ_CLOUD_PLAYBACK_RATE_1 = 1,               // 1倍速
    EZ_CLOUD_PLAYBACK_RATE_4 = 4,               // 4倍速
    EZ_CLOUD_PLAYBACK_RATE_8 = 6,               // 8倍速
    EZ_CLOUD_PLAYBACK_RATE_16 = 8,              // 16倍速
    EZ_CLOUD_PLAYBACK_RATE_32 = 10,             // 32倍速
};

/// 萤石播放器delegate方法
@protocol EZPlayerDelegate <NSObject>

@optional
/**
 *  播放器播放失败错误回调
 *
 *  @param player 播放器对象
 *  @param error  播放器错误
 */
- (void)player:(EZPlayer *)player didPlayFailed:(NSError *)error;

/**
 *  播放器消息回调
 *
 *  @param player      播放器对象
 *  @param messageCode 播放器消息码，请对照EZOpenSDK头文件中的EZMessageCode使用
 */
- (void)player:(EZPlayer *)player didReceivedMessage:(NSInteger)messageCode;

/**
 *  收到的数据长度（每秒调用一次）
 *
 *  @param player     播放器对象
 *  @param dataLength 播放器流媒体数据的长度（每秒字节数）
 */
- (void)player:(EZPlayer *)player didReceivedDataLength:(NSInteger)dataLength;

/**
 *  收到的画面长宽值
 *
 *  @param player 播放器对象
 *  @param height 高度
 *  @param width  宽度
 */
- (void)player:(EZPlayer *)player didReceivedDisplayHeight:(NSInteger)height displayWidth:(NSInteger)width;

@end

/// 此类为萤石播放器类
@interface EZPlayer : NSObject

/// EZPlayer关联的delegate
@property (nonatomic, weak) id<EZPlayerDelegate> delegate;

/// 是否让播放器处理进入后台,YES:自动处理;NO:不处理,默认为YES
@property (nonatomic) BOOL backgroundModeByPlayer;

/**
 *  根据设备序列号和通道号创建EZPlayer对象
 *
 *  @param deviceSerial 设备序列号
 *  @param cameraNo     通道号
 *
 *  @return EZPlayer对象
 */
+ (instancetype)createPlayerWithDeviceSerial:(NSString *)deviceSerial cameraNo:(NSInteger)cameraNo;

/**
 *  根据url构造EZPlayer对象 （主要用来处理视频广场的播放）
 *
 *  @param url 播放url
 *
 *  @return EZPlayer对象
 */
+ (instancetype)createPlayerWithUrl:(NSString *)url;


/**
 局域网设备创建播放器接口

 @param userId 用户id，登录局域网设备后获取
 @param cameraNo 通道号
 @param streamType 码流类型 1:主码流 2:子码流
 @return EZPlayer对象
 */
+ (instancetype)createPlayerWithUserId:(NSInteger) userId cameraNo:(NSInteger) cameraNo streamType:(NSInteger) streamType;

/**
 *  销毁EZPlayer
 *
 *  @return YES/NO;
 */
- (BOOL)destoryPlayer;

/**
 *  设置播放器的view
 *
 *  @param playerView 播放器view
 */
- (void)setPlayerView:(UIView *)playerView;

/**
 *  开始播放，异步接口，返回值只是表示操作成功，不代表播放成功
 *
 *  @return YES/NO
 */
- (BOOL)startRealPlay;

/**
 *  停止播放，异步接口，返回值只是表示操作成功
 *
 *  @return YES/NO
 */
- (BOOL)stopRealPlay;

/**
 *  设置播放器解码密码
 *
 *  @param verifyCode 设备验证码
 */
- (void)setPlayVerifyCode:(NSString *)verifyCode;

/**
 *  开启声音
 *
 *  @return YES/NO
 */
- (BOOL)openSound;

/**
 *  关闭声音
 *
 *  @return YES/NO
 */
- (BOOL)closeSound;

/**
 *  开始对讲，异步接口，返回值只是表示操作成功，不代表播放成功
 *
 *  @return YES/NO
 */
- (BOOL)startVoiceTalk;

/**
 *  停止对讲，异步接口，返回值只是表示操作成功
 *
 *  @return YES/NO
 */
- (BOOL)stopVoiceTalk;

/**
 *  半双工对讲专用接口，是否切换到听说状态
 *
 *  @param isPressed 是否只说状态
 *
 *  @return YES/NO
 */
- (BOOL)audioTalkPressed:(BOOL)isPressed;

/**
 *  开始云存储远程回放，异步接口，返回值只是表示操作成功，不代表播放成功
 *  @param cloudFile 云存储文件信息
 *
 *  @return YES/NO
 */
- (BOOL)startPlaybackFromCloud:(EZCloudRecordFile *)cloudFile;

/**
 *  开始远程SD卡回放，异步接口，返回值只是表示操作成功，不代表播放成功
 *
 *  @param deviceFile SD卡文件信息
 *
 *  @return YES/NO
 */
- (BOOL)startPlaybackFromDevice:(EZDeviceRecordFile *)deviceFile;

/**
 *  暂停远程回放播放
 */
- (BOOL)pausePlayback;

/**
 *  继续远程回放播放
 */
- (BOOL)resumePlayback;

/**
 *  根据偏移时间播放
 *
 *  @param offsetTime 录像偏移时间
 */
- (void)seekPlayback:(NSDate *)offsetTime;

/**
 *  获取当前播放时间进度
 *
 *  @return 播放进度的NSDate数据
 */
- (NSDate *)getOSDTime;

/**
 *  停止远程回放
 */
- (BOOL)stopPlayback;

/**
 *  开始本地直播流录像功能（用户自行处理存储过程）
 *
 *  @param recordDataBlock 录像回调数据（可以对数据进行分析，比较人脸识别等）
 *
 *  @return YES/NO
 */
- (BOOL)startLocalRecord:(void (^)(NSData *data))recordDataBlock;

/**
 *  开始本地录像功能（SDK处理存储过程）
 *
 *  @param path 文件存储路径
 *
 *  @return YES/NO
 */
- (BOOL)startLocalRecordWithPath:(NSString *)path;

/**
 *  结束本地直播流录像
 *
 *  @return YES/NO
 */
- (BOOL)stopLocalRecord;

/**
 *  直播画面抓图
 *
 *  @param quality 抓图质量（0～100）,数值越大图片质量越好，图片大小越大
 *
 *  @return image
 */
- (UIImage *)capturePicture:(NSInteger)quality;

/**
 获取内部播放器句柄。建议每次使用播放器句柄时均调用此方法获取，并进行有效性判断。

 @return 小于0为无效值，大于等于0为有效值
 */
- (int) getPlayPort;

/**
 SD卡回放专用接口，倍数回放

 @param rate 回放倍率，见EZPlaybackRate,目前设备存储回放支持1、2、4、8、1/2、1/4、1/8倍数
 @return YES/NO
 */
- (BOOL) setPlaybackRate:(EZPlaybackRate) rate;

/**
 云存储回放专用接口，倍数回放
 
 @param rate 回放倍率，见EZCloudPlaybackRate,目前云存储支持1、4、8、16、32倍数
 @return YES/NO
 */
- (BOOL) setCloudPlaybackRate:(EZCloudPlaybackRate) rate;

@end

