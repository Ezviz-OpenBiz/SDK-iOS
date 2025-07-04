//
//  EZPlayer.h
//  EzvizOpenSDK
//
//  Created by DeJohn Dong on 15/9/16.
//  Copyright (c) 2015年 Ezviz. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "EZConstants.h"

@class EZDeviceRecordFile;
@class EZCloudRecordFile;
@class EZPlayer;
@class EZPlayerExParamInfo;
@class EZDevicePtzAngleInfo;
@class EZPMPlayPrivateTokenInfo;
@class EZDeviceDetailPublicInfo;

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
    PLAYER_CLOUD_IFRAME_CHANGED = 23, //云存储快放时，由全帧快放切换到抽帧快放的提示回调
    PLAYER_PLAYSPEED_LOWER = 24,      //云存储快放时的降速通知(存在两次降速：当前倍速大于4倍速时，降到4倍速；当前为4倍速时，降为1倍速)
    PLAYER_VIDEO_LEVEL_AUTO_IMPROVE = 25,//预览自动清晰度提升消息
    PLAYER_VIDEO_LEVEL_AUTO_REDUCE = 26, //预览自动清晰度降低消息
};


/**
 *  回放速率
 */
typedef NS_ENUM(NSInteger, EZPlaybackRate) {
    EZOPENSDK_PLAY_RATE_1_16 = 9,  //以1/16倍速度播放
    EZOPENSDK_PLAY_RATE_1_8 = 7,   //以1/8倍速度播放
    EZOPENSDK_PLAY_RATE_1_4 = 5,   //以1/4倍速度播放
    EZOPENSDK_PLAY_RATE_1_2 = 3,   //以1/2倍速播放
    EZOPENSDK_PLAY_RATE_1 = 1,     //以正常速度播放
    EZOPENSDK_PLAY_RATE_2 = 2,     //以2倍速播放
    EZOPENSDK_PLAY_RATE_4 = 4,     //以4倍速度播放
    EZOPENSDK_PLAY_RATE_8 = 6,     //以8倍速度播放
    EZOPENSDK_PLAY_RATE_16 = 8,    //以16倍速度播放
    EZOPENSDK_PLAY_RATE_32 = 10,   //以32倍速度播放
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
 *  该方法废弃于v4.8.8版本，底层库不再支持。请使用getStreamFlow方法
 *  收到的数据长度（每秒调用一次）
 *
 *  @param player     播放器对象
 *  @param dataLength 播放器流媒体数据的长度（每秒字节数）
 */
- (void)player:(EZPlayer *)player didReceivedDataLength:(NSInteger)dataLength DEPRECATED_MSG_ATTRIBUTE("use getStreamFlow instead");

/**
 *  收到的画面长宽值
 *
 *  @param player 播放器对象
 *  @param height 高度
 *  @param width  宽度
 */
- (void)player:(EZPlayer *)player didReceivedDisplayHeight:(NSInteger)height displayWidth:(NSInteger)width;

/**
 * 设备云台角度数据回调
 *
 * @param player 播放器对象
 * @param info 私有数据
 */
- (void)player:(EZPlayer *)player didReceivedDevicePtzAngleInfo:(EZDevicePtzAngleInfo *)info;

/**
 * 播放过程中 回调解码数据
 * 重要：该回调会比较频繁(一秒若干次)，同时直接由播放库线程回调上来，请勿在方法中做耗时操作
 * 重要：回调的数据的内存是由播放库内部分配并管理的，在使用时，请同步处理回调的data；如需异步处理，请拷贝该数据
 *
 * @param player 播放器对象
 * @param data 播放库解码出的数据
 * @param width 视频宽度
 * @param height 视频高度
 */
- (void)player:(EZPlayer *)player didDecodedData:(NSData *)data width:(NSInteger)width height:(NSInteger)height;

/**
 * 取流数据中获取开门token回调
 *
 * @param player 播放器对象
 * @param tokenInfo token对象
 */
- (void)player:(EZPlayer *)player playPrivateTokenInfo:(EZPMPlayPrivateTokenInfo *)tokenInfo;

/**
 * 对讲时采集时的音频大小，必须调用`EZPlayer.setVoiceTalkLoudnessInterval`设置回调时间间隔后才会有回调
 * 注意：回调的音量单位为分贝，均为负数。在数字音频处理中，音量通常以dBFS（分贝满刻度）为单位来表示。
 * 0dBFS表示信号的最大可能幅度，即满量程刻度。由于有效的信号数值通常小于这个最大值，取对数后得到的值通常是负数。
 * 建议：(-90, -40)音量显示1格，[-40, -35)音量显示2格，[-35, -30)音量显示3格，[-30, -20)音量显示4格，[-20, 0)音量显示5格
 * 如需其他层级的音量显示效果，需开发者自行调试
 *
 * @param player 播放器对象
 * @param loudness 音频大小 [-90 ，0]
 */
- (void)player:(EZPlayer *)player didReceivedVoiceTalkLoudness:(float)loudness;

@end

/// 此类为萤石播放器类
@interface EZPlayer : NSObject

/// EZPlayer关联的delegate
@property (nonatomic, weak) id<EZPlayerDelegate> delegate;

/**
 * 是否让播放器处理进入后台,YES:自动处理（进入后台停止播放，进入前台恢复播放）;NO:不处理,默认为YES
 * 预览：进入后台停止播放，进入前台开始播放
 * 回放：进入后台暂停播放，进入前台恢复播放
 * 对讲：进入后台停止对讲，进入前台不处理
 */
@property (nonatomic, assign) BOOL backgroundModeByPlayer;

#pragma mark - 播放器创建

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
 *  一个页面存在多个视频使用最小的码流，没有子码流的话还是使用主码流
 *
 *  @param deviceSerial 设备序列号
 *  @param cameraNo     虚拟通道
 *  @param useSubStream   是否使用子码流
 *
 *  @return EZPlayer对象
 */
+ (instancetype)createPlayerWithDeviceSerial:(NSString *)deviceSerial cameraNo:(NSInteger)cameraNo useSubStream:(BOOL)useSubStream;

/**
 * 根据设备序列号和通道号创建EZPlayer对象（for 国标设备）
 *
 * @param deviceSerial 国标设备序列号
 * @param strCameraNo   国标设备通道号
 * 
 * @return EZPlayer对象
 */
+ (instancetype)createPlayerWithDeviceSerial:(NSString *)deviceSerial strCameraNo:(NSString *)strCameraNo;

/**
 *  根据url构造EZPlayer对象 （主要用来处理视频广场的播放）
 *
 *  @param url 播放url
 *
 *  @return EZPlayer对象
 */
+ (instancetype)createPlayerWithUrl:(NSString *)url;

/**
 *  门口机专用构建EZPlayer接口（for 4500）
 *
 *  @param deviceSerial 设备序列号
 *  @param cameraNo     虚拟通道号
 *  @param streamType   码流类型：1-主码流，2-子码流
 *
 *  @return EZPlayer对象
 */
+ (instancetype)createPlayerWithDeviceSerial:(NSString *)deviceSerial cameraNo:(NSInteger)cameraNo streamType:(NSInteger)streamType;

/**
 * 局域网设备创建播放器接口
 *
 * @param userId 用户id，登录局域网设备后获取
 * @param cameraNo 通道号
 * @param streamType 码流类型 1:主码流 2:子码流
 *
 * @return EZPlayer对象
 */
+ (instancetype)createPlayerWithUserId:(NSInteger)userId cameraNo:(NSInteger)cameraNo streamType:(NSInteger)streamType;

/**
 * EZPlayer存在的时候，切换至其他设备进行取流，不需要重新创建
 * @param deviceSerial 设备序列号
 * @param cameraNo     虚拟通道号
 */
- (void)resetDeviceSerial:(NSString *)deviceSerial cameraNo:(NSInteger)cameraNo;

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
 *  设置播放器的view
 *
 *  @param playerView 播放器view
 *  @param streamId 双目设备轨道
 */
- (void)setPlayerView:(UIView *)playerView streamId:(int)streamId;

#pragma mark - 预览

/**
 *  是否静音播放，startRealPlay之前调用
 *
 *  @param isSilencePlay 是否静音播放
 */
- (void)setSilencePlay:(BOOL)isSilencePlay;

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
 * 预览时开始本地录像预录制功能，异步方法
 *
 * @param path 文件存储路径
 *
 * @return YES/NO
 */
- (BOOL)startLocalRecordWithPathExt:(NSString *)path;

/** 测试排查问题用，开发者勿使用，以后版本会删除 */
- (BOOL)startLocalRecordWithPathExt:(NSString *)path psPath:(NSString *)psPath;

/**
 * 结束本地录像预录制，并生成mp4录制文件，异步方法
 *
 * @param complete 操作是否成功 YES/NO
 */
- (void)stopLocalRecordExt:(void (^)(BOOL ret))complete;

#pragma mark - 对讲

/**
 *  开始TTS对讲，异步接口，返回值只是表示操作成功，不代表对讲成功
 *
 *  @return YES/NO
 */
- (BOOL)startVoiceTalk;

/**
 *  开始TTS对讲，异步接口，返回值只是表示操作成功，不代表对讲成功
 *  针对于NVR对讲使用
 *  @return YES/NO
 */
- (BOOL)startVoiceTalkNeedVoiceChannel:(BOOL)needVoiceChannel;

/**
 *  开始Qos对讲，异步接口，返回值只是表示操作成功，不代表对讲成功
 *
 *  @return YES/NO
 */
- (BOOL)startVoiceTalkByQos;

/**
 *  停止对讲，异步接口，返回值只是表示操作成功
 *
 *  @return YES/NO
 */
- (BOOL)stopVoiceTalk;

/**
 * 设置对讲本地采集音量大小回调时间间隔；默认为0，响度不回调
 * 在调用startVoiceTalk前生效
 * 设置后会通过`-player:didReceivedVoiceTalkLoudness:`代理方法进行回调
 *
 * @param interval 回调时间间隔
 */
- (void)setVoiceTalkLoudnessInterval:(float)interval;

/**
 *  对讲变声，对讲成功后开启，需要设备开通变声服务后才生效（只支持国内，海外不支持）
 *
 *  @param voiceChangeType 变声类型
 *  @param complete 操作是否成功
 */
- (void)startVoiceChange:(EZVoiceChangeType)voiceChangeType complete:(void (^)(BOOL ret, NSError *error))complete;

/**
 *  半双工对讲专用接口，是否切换到听说状态，startVoiceTalk对讲开启成功后才能调用
 *
 *  @param isPressed 是否只说状态
 *
 *  @return YES/NO
 */
- (BOOL)audioTalkPressed:(BOOL)isPressed;

/**
 * 设置全双工对讲时的模式,对讲成功后调用
 *
 * @param routeToSpeaker YES:使用扬声器 NO:使用听筒
 */
- (void)changeTalkingRouteMode:(BOOL)routeToSpeaker;

/**
 * 设置采集和播放的AGC放大的参数，在对讲发起前设置
 * 仅针对部分型号设备对讲时，设备端播放的声音比较小，用于放大手机端采集的声音；正常情况下不要调用，会影响对讲效果
 * @param maxGain 最大db数，范围[5,90]，萤石当前默认值15
 * @param gain 目标幅值，取值[0,30]，萤石当前默认值21
 */
- (void)setAGCParam:(NSInteger)maxGain gainLevel:(NSInteger)gain;

#pragma mark - 回放

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
 *  开始远程SD卡AI回放，异步接口，返回值只是表示操作成功，不代表播放成功（专供华住私有云，其他不支持）
 *
 *  @param deviceFile SD卡文件信息
 *
 *  @return YES/NO
 */
- (BOOL)startAIPlaybackFromDevice:(EZDeviceRecordFile *)deviceFile;

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
sd卡及云存储倍速回放接口
1.支持抽帧快放的设备最高支持16倍速快放（所有取流方式，包括P2P）
2.不支持抽帧快放的设备，仅支持内外网直连快放，最高支持8倍
3.HCNetSDK取流没有快放概念，全速推流，只改变播放库速率
4.注意区别：
   老SD卡回放以及HCNetSDK回放，设置完通过返回值返回成功还是失败，没有其他消息
   新协议的云存储回放以及支持seek、continue的设备的新SD卡回放，设置完通过返回值返回成功还是失败，如果成功，
   则后续还有一条EZVideoPlayerMessageStart异步消息表示成功再次取流
   返回其他错误码表示失败 (新协议云存储和新SD卡回放返回EZ_ERROR_NEED_RETRY 表示需要重试）

@param rate    回放速度，具体参考 EZ_PLAY_BACK_RATE
@param mode 回放时的抽帧控制，当前仅云存储支持。0： 4倍速全帧，8倍速以上抽帧   1：抽帧   2：全帧  （如设备回放当前不支持，传入0即可）
@return YES/NO
 */
- (BOOL)setPlaybackRate:(EZPlaybackRate) rate mode:(NSUInteger)mode;

#pragma mark - 其他方法

/**
 *  设置使用硬件解码器优先，需在startRealPlay之前调用；默认软解
 *
 *  @param HDPriority 是否硬解优先
 */
- (void)setHDPriority:(BOOL)HDPriority;

/**
 * 获取当前的软硬解情况，在码流正常播放后调用
 *
 * @return 1：软解 2：硬解 0：出错
 */
- (int)getHDPriorityStatus;

/**
 *  设置设备归属业务来源，需要在预览回放前调用  国标设备使用
 *
 *  @param bizType 类型       国标为 bizType='GB28181'
 */
- (void)setBizType:(NSString *)bizType;

/**
 *  平台id 国标设备使用
 *
 *  @param platformId 类型
*/
- (void)setPlatformId:(NSString *)platformId;

/**
 * 获取播放组件内部的播放库的port
 *
 * @return 播放库的port,可能为-1（无效值）
 */
- (int)getInnerPlayerPort;

/**
 * 获取内部播放器句柄。建议每次使用播放器句柄时均调用此方法获取，并进行有效性判断。
 *
 * @return 小于0为无效值，大于等于0为有效值
 */
- (int)getPlayPort;

/**
 *  直播画面抓图
 *
 *  @param quality 抓图质量（0～100）,数值越大图片质量越好，图片大小越大
 *
 *  @return image
 */
- (UIImage *)capturePicture:(NSInteger)quality;

/**
 *  直播画面抓图
 *
 *  @param quality 抓图质量（0～100）,数值越大图片质量越好，图片大小越大
 *  @param streamId 双目设备轨道
 *
 *  @return image
 */
- (UIImage *)capturePicture:(NSInteger)quality streamId:(int)streamId;

/**
 * 获取当前取流方式（耗时操作，需要在子线程中执行）
 *
 * @return 当前取流类型
 */
- (int)getStreamFetchType;

/**
 * 获取当前已播放的总流量，单位字节
 eg.计算每秒的流量：
 NSInteger a = [self getStreamFlow];
 //1s后调用
 NSInteger b = [self getStreamFlow];
 NSInteger perSecondFlow = b - a;
 *
 * @return 流量值
 */
- (NSInteger)getStreamFlow;

/**
 * 获取设备部分详情信息（出画面后才有回调）
 *
 * @param complete  设备对象回调
 */
- (void)getDeviceDetailInfo:(void (^)(EZDeviceDetailPublicInfo *info))complete;

/**
 * 扩展参数 UIKit专用
 *
 * @param exParamInfo EZPlayerExParamInfo
 */
- (void)setExParamInfo:(EZPlayerExParamInfo *)exParamInfo;

/**
 * 设置打开播放库的智能分析，当前温感相机的框框使用了该智能分析数据，预览成功后调用，在播放过程中随时开关
 *
 * @param enable YES：开  NO：关
 *
 * @return 返回状态
 */
- (BOOL)setIntelAnalysis:(BOOL)enable;

/**
 * 全局p2p开启的情况下，该播放器禁用p2p取流。startRealPlay之前调用
 */
- (void)setPlayerDisableP2P;

/**
 * 是否开启自动清晰度网络检测开关；此api未调用时，不会回调以下消息 
 * EZPlayer - EZMessageCode - PLAYER_VIDEO_LEVEL_AUTO_IMPROVE  网络好，会回调此消息，建议切换高一级清晰度
 * EZPlayer - EZMessageCode - PLAYER_VIDEO_LEVEL_AUTO_REDUCE    网络差，会回调此消息，建议切换低一级清晰度
 */
- (void)enableDeviceAutoVideoLevel;

/**
 * 设置性能优先或画质优先，startRealPlay之前调用，播放前会先设置清晰度再发起取流，会增加首帧画面耗时
 * 因为涉及到清晰度切换，取流成功后必须设置下清晰度UI
 *
 * @param videoQuality  视频质量，指定性能优先或画质优先
 */
- (void)setVideoQuality:(EZVideoQualityType)videoQuality;

/**
 * `EZOpenSDK.enableSDKWithTKToken`开启后，需要设置取流小权限token，startRealPlay之前调用
 * 注意：IPC设备对讲使用的是0通道，对讲streamToken生成请使用0通道
 *
 * @param streamToken  取流小权限token
 */
- (void)setStreamToken:(NSString *)streamToken;

/**
 * 设置播放画面的旋转角度
 *
 * @param rotationAngle  旋转角度
 */
- (BOOL)setPlayerViewRotation:(EZPlayerViewRotationAngle)rotationAngle;

/**
 * 设置电子放大区域
 * 
 * @param rect 电子放大区域
 * @param streamId 双目设备轨道
 */
- (void)setDisplayRegionEx:(CGRect *)rect streamId:(int)streamId;

#pragma mark - 鱼眼矫正模式

/**
 * 设置鱼眼播放视图
 */
- (void)setFecPlayViews:(NSArray<UIView *> *)fecPlayViews;

/**
 * 打开鱼眼矫正
 *
 * @param fecCorrectType 矫正模式
 * @param fecPlaceType     安装模式
 */
- (void)openFecCorrect:(EZFecCorrectType)fecCorrectType fecPlaceType:(EZFecPlaceType)fecPlaceType;

/**
 * 鱼眼设备 - 移动手势操作
 *
 * @param state 手势状态
 * @param point 坐标
 * @param gestureRecognizer 手势
 */
- (void)panGestureWith:(UIGestureRecognizerState)state point:(CGPoint)point gestureRecognizer:(UIPanGestureRecognizer *)gestureRecognizer;

/**
 * 鱼眼设备 - 缩放手势操作
 * 
 * @param state 手势状态
 * @param zoomAccuracy 缩放精度
 * @param gestureRecognizer 手势
 */
- (void)pinGestureWith:(UIGestureRecognizerState)state zoom:(float)zoomAccuracy gestureRecognizer:(UIPinchGestureRecognizer *)gestureRecognizer;

/**
 * 鱼眼设备 - 点击手势操作
 *
 * @param gestureRecognizer 手势
 */
- (BOOL)tapGestureWith:(UITapGestureRecognizer *)gestureRecognizer;

@end

