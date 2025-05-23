//
//  ERTCEngine.h
//  ERTC
//
//  Created by Harper Kan on 2021/10/26.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "ERTCDef.h"
#import "ERTCStatistics.h"
#import "ERTCSpeedTestResult.h"
#import "ERTCEngineObjects.h"
#import <AVFoundation/AVFoundation.h>

NS_ASSUME_NONNULL_BEGIN


/// ERTCEngine 的委托协议，所有的反馈消息通过该协议给出
@protocol ERTCDelegate <NSObject>

@optional
/// 错误码回调
/// @param errCode 详见 ERTCError.h
- (void)onError:(NSInteger)errCode;


/// 用户加入房间成功，加入房间成功后将收到回调
/// @param result 加入房间耗时
- (void)onEnterRoomSuccess:(NSInteger)result;


/// 用户退出房间，非主动退出房间才会收到该回调
/// @param reason 退出房间原因
- (void)onExitRoom:(ERTCSelfExitReason)reason;


/// 远端用户进入房间成功回调，进入房间时将会收到所有已在房间内用户加入房间的回调
/// @param userId 用户id
- (void)onRemoteUserEnterRoom:(NSString *)userId;


/// 远端用户离开房间
/// @param userId 用户ID
/// @param reason 离开原因，0表示用户主动退出房间，1表示用户超时退出。
- (void)onRemoteUserLeaveRoom:(NSString *)userId reason:(NSInteger)reason;


/// 远端用户打开或关闭视频流的回调
/// @param userId 远端用户id
/// @param available true-视频可用 false-视频不可用
- (void)onUserVideoAvailable:(NSString *)userId available:(BOOL)available;


/// 远端用户推流或关闭音频流的回调
/// @param userId 远端用户id
/// @param available  true-音频可用 false-音频不可用
- (void)onUserAudioAvailable:(NSString *)userId available:(BOOL)available;

/// 远端用户开启或关闭屏幕共享的回调
/// @param userId 远端用户id
/// @param available  true-可用 false-不可用
- (void)onUserScreenShareAvailable:(NSString *)userId available:(BOOL)available;

/// 本地视频预览回调
/// @param width 视频宽度，单位像素
/// @param height 视频高度，单位像素
- (void)onFirstLocalVideoFrameWithWidth:(int)width height:(int)height;


/// 远端视频预览回调，订阅视频后将会收到该回调
/// @param userId 远端用户id
/// @param width 视频宽度，单位像素
/// @param height 视频高度，单位像素
- (void)onFirstRemoteVideoFrame:(NSString *)userId width:(int)width height:(int)height;

///远端共享流回调,订阅屏幕共享后会收到该回调
- (void)onFirstScreenShareStream:(int)width height:(int)height;

/// 音量回调，用户需要调用 enableAudioVolumeEvaluation 开启才会产生回调
/// @param userVolumes 列表，最多返回音量最大的三个用户
/// @param totalVolume 混音后的整个会场音量大小
- (void)onUserVoiceVolume:(NSArray<ERTCVolumeInfo *> *)userVolumes totalVolume:(NSInteger)totalVolume;


/// 网络质量回调
/// @param upQuality 上行网络质量
/// @param downQuality 下行网络质量
/// @param userId 用户id, 当id为自己的userId时，表示本地网络质量，否则表示其它用户的
- (void)onNetworkQualityWithUp:(ERTCNetworkQuality)upQuality down:(ERTCNetworkQuality)downQuality ofUser:(NSString *)userId;


/// 当房间中的某个用户使用 {sendCustomMsg} 发送自定义 消息时，房间中的其它用户可以通过 onUserCustomMsg 事件回调接收到该条消息。
/// @param userId 用户标识
/// @param msg 消息数据
- (void)onUserCustomMsg:(NSString *)userId msg:(NSData *)msg;

///本地视频实时数据
///@param videoStats 视频数据
///
- (void)onLocalVideoStats:(ERTCLocalVideoStatistics *)videoStats;

///远端视频实时数据
///@param videoStats 视频数据
///
- (void)onRemoteVideoStats:(ERTCRemoteVideoStatistics *)videoStats;


///本地音频实时数据
///@param audioStats 音频数据
- (void)onLocalAudioStats:(ERTCLocalAudioStatistics *)audioStats;

///远端音频实时数据
///@param audioStats 视频数据
- (void)onRemoteAudioStats:(ERTCRemoteAudioStatistics *)audioStats;

///网络测速结果
///@param result 回调结果
- (void)onSpeedTestResult:(ERTCSpeedTestResult *)result;

///远端视频解码回调
///@param userId 用户标识
///@param dataLength 数据长度
///@param data 屏幕共享解码数据
///@param width 屏幕共享流宽度
///@param height 屏幕共享流高度
- (void)onDisplay:(NSString *)userId withData:(const char *)data dataLength:(NSInteger)dataLength width:(NSInteger)width height:(NSInteger)height;

///远端屏幕共享解码回调
///@param dataLength 数据长度
///@param data 屏幕共享解码数据
///@param width 屏幕共享流宽度
///@param height 屏幕共享流高度
- (void)onScreenSharingDispPlay:(NSInteger)dataLength withData:(const char *)data width:(NSInteger)width height:(NSInteger)height;

///强制停止屏幕共享
- (void)onForceStopShareScreen;

///远端用户重新加入房间
///@param userId 用户标识
- (void)remoteUserRejoinRoom:(NSString *)userId;

///本地视频数据
///@param receiveData 本地采集数据
- (void)onReceivedLocalMediaData:(CMSampleBufferRef)receiveData;

///订阅结果
///@param userId 用户标识
///@param reason 订阅结果
///@param streamType 流类型
- (void)onSubscribeResult:(NSString *)userId streamType:(ERTCStreamType)streamType reason:(int)reason;

///用户订阅权限通知
///@param userPermissionsArray 相关用户的订阅权限
- (void)onSubscribePermission:(NSArray<ERTCSubscribePermission *> *)userPermissionsArray;


@end

/// ERTCEngine 配置参数
@interface ERTCEngineConfig : NSObject

/// 平台分配的appID
@property(nonatomic, strong) NSString *appID;

/// 平台地址（可配置）
@property(nonatomic, strong) NSString *apiUrl;

@end


/// 加入房间的参数
@interface ERTCParam : NSObject

/// 用户ID， 外部用户自行约定，需保持唯一性
@property (nonatomic, strong) NSString *userId;

/// 房间id, 限制长度32位
@property (nonatomic, strong) NSString *roomId;

/// 资源Token
@property (nonatomic, strong) NSString *token;

//平台地址（可配置）
@property(nonatomic, strong) NSString *apiUrl;

//平台分配的appID
@property(nonatomic, strong) NSString *appID;

@end


//typedef UIView ERTCView;


/// 预览视图，用于预览本地用户或者远端用户的视频
@interface ERTCView : UIView
/// 显示模式
@property (nonatomic, assign) ERTCVideoFillMode fillMode;
@end


@class ERTCEngine;
typedef void(^InstanceBlock)(ERTCEngine * _Nullable instance,NSError * _Nullable error);


/// RTC引擎，SDK核心类，进行会议的各项业务
@interface ERTCEngine : NSObject

- (instancetype)initWithConfig:(ERTCEngineConfig *)config;


/// 委托
@property (nonatomic, weak) id<ERTCDelegate> delegate;

#pragma mark V1.4.0-新增属性
//开启美颜
@property(nonatomic, assign) BOOL beautyEnabled;
///美白程度
@property(nonatomic, assign) float whitenessLevel;
///磨皮程度
@property(nonatomic, assign) float smoothnessLevel;
///红润程度
@property(nonatomic, assign) float ruddynessLevel;

/// 滤镜效果类型选择 在enableLocalVideo前和后均可设置，如果enableLocalVideo 为 YES ，则实时生效
@property (nonatomic, assign) ERTCFilterType filterType;

/// 滤镜效果的幅度 0~1.0 默认 0.5
@property (atomic, assign) float filterLevel;

///是否允许推流，在enableLocalVideo 打开的情况下，是否允许发送，默认值为YES； 可以在加入房间前或后调用；也可以在 enableLocalVideo 前提前调用
@property(nonatomic, assign) BOOL enableLocalVideoStreamPublishing;


/// 获取SDK版本号
+ (NSString *)version;


/// 创建ERTCEngine对象，接口为异步接口 ，创建的对象内部会强引用，因此外部可以弱引用，创建的对象可以通过destroySharedIntance释放
/// @param config engine的配置参数
/// @param block 结果回调，成功的回调会给出ERTCEngine对象
+ (void)createWithConfig:(ERTCEngineConfig *)config instanceBlock:(InstanceBlock)block;




/// 释放之前通过createWithConfig创建的对象
+ (void)destroySharedIntance;


/// 进入房间，进入成功后自己端将收到onEnterRoomSuccess, 房间内其它用户将收到onRemoteUserEnterRoom
/// @param param 进入房间param
/// @param scene  进入房间场景
- (void)enterRoom:(ERTCParam *)param withScene:(ERTCAppScene)scene;


/// 退出房间，退出后其它用户端将收到onRemoteUserLeaveRoom
- (void)exitRoom;


/// 是否开启本地采集并推流。加入房间前调用则加入后自动推流，加入房间后调用则直接推流. 调用后其它用户将收到 onUserVideoAvailable
/// @param enable YES-开启推流 NO-关闭推流
- (void)enableLocalVideo:(BOOL)enable;


/// 开启本地音频模块并推流，调用成功后其它用户将收到 onUserAudioAvailable
/// @param enable YES-开启 NO-关闭
- (void)enableLocalAudio:(BOOL)enable;


/// 设置视频编码参数，不设置则默认为640*480，需要在任何视频操作前设置
/// @param param 视频编码参数,详见ERTCVideoEncParam
- (void)setVideoEncoderParam:(ERTCVideoEncParam *)param;

/// 设置音频编码格式
/// @param type 音频编码参数,详见ERTCVideoEncParam
- (void)setAudioEncoderType:(ERTCAudioEncodeType)type;

/// 是否开启小码流模块
/// @param enable YES-开启 NO-关闭
/// @param smallVideoEncParam 视频编码参数，如果传入nil，则默认160*120
- (void)enableLocalSmallVideo:(BOOL)enable withQuality:(ERTCVideoEncParam *)smallVideoEncParam;

/// 启用音量大小提示 开启此功能后，SDK 会 onUserVoiceVolume 回调中反馈远端音频的音量大小  如需打开此功能，请在 enableLocalAudio 之前调用才可以生效
/// @param interval  设置 onUserVoiceVolume 回调的触发间隔，单位为ms，最小间隔为100ms，如果小于等于 0 则会关闭回调，建议设置为300ms
- (void)enableAudioVolumeEvaluation:(NSUInteger)interval;


/// 切换前后置摄像头
- (void)switchCamera;


/// 打开扬声器，默认扬声器是开的
/// @param enableSpeaker 打开扬声器
- (void)setEnableSpeakerphone:(BOOL)enableSpeaker;



/// 开启屏幕共享
/// @param name 共享名称
/// @param resultBlock 屏幕共享结果回调
/// @param didFinishBlock 屏幕共享结束回调，在正常的屏幕共享结束结束后回调
- (void)startScreenShareWithName:(NSString *)name
                 withResultBlock:(void (^)(NSInteger ret))resultBlock
                   andEndedBlock:(dispatch_block_t)didFinishBlock;


/// 结束屏幕共享
- (void)stopScreenShare;


/// 发送自定义消息给房间内所有用户
/// @param data data 待发送的消息，单个消息的最大长度被限制为 1KB
- (int)sendCustomMsg:(NSData *_Nonnull)data;

/// 开始网络测试
/// @param upBandwidth 上行带宽
/// @param downBandwidth 下行带宽
/// @param testInterval 统计间隔
- (void)startSpeedTestWithUpBandwidth:(int)upBandwidth
                        downBandwidth:(int)downBandwidth
                         testInterval:(int)testInterval;

///停止网络测试
- (void)stopSpeedTest;

///开启Opus编码
- (void)openOpusEncode:(BOOL)open;

/// 设置本地的预览窗口，支持设置多个，必须在主线程调用，如果窗口的大小发生变化，可能需要重新设置一遍
/// @param view 预览View
/// @param regionID 窗口ID，可以填0 、1、
- (void)setLocalPreview:(nullable UIView *)view withRegionID:(NSInteger)regionID;

/// 订阅，取消订阅某个用户的视频流，不可以与setRemoteView:ofClient:withStream: 混用
/// 如果窗口与是否订阅该用户的码流是绑定的，则建议使用setRemoteView:ofClient:withStream:
/// @param subscribe YES-开启订阅 NO-取消订阅
/// @param userId 用户的ID
/// @param type EZSubStreamType_Main大视频流  EZSubStreamType_Min 小视频流
- (void)subscribe:(BOOL)subscribe forUser:(NSString *)userId withStream:(ERTCVideoStreamType)type;

///自动订阅远端用户音频
///@param subscribe YES-自动开启订阅 NO-取消自动订阅
- (void)autoSubscribeAudio:(BOOL)subscribe;

/// 订阅远端用户音频流
/// @param subscribe YES-开启订阅 NO-取消订阅
/// @param userId 用户的ID
- (void)subscribeAudio:(BOOL)subscribe forUser:(NSString *)userId;

/// 在订阅某个clientID后，设置播放该用户的播放画面，支持针对用一个用户，设置多个画面播放，
/// 不可以与setRemoteView:ofClient:withStream: 混用
/// 必须在 主线程调用该接口
/// @param view 播放窗口
/// @param userId 已订阅的用户的ID
/// @param regionID 窗口ID，支持 0、1、2、3
- (void)setRemoteView:(nullable UIView *)view forUser:(NSString *)userId withRegionID:(NSInteger)regionID;

/// 设置电子放大接口
/// @param userId 已订阅，并设置了播放视图的用户ID，如果是屏幕共享，传入userId为0
/// @param regionID 已订阅，并设置了的RegionID
/// @param rect 上下左右的偏移，以像素为单位
- (void)setDisplayRegionOfUserId:(NSString *)userId
                       withRegionID:(NSInteger)regionID
                             atRect:(CGRect)rect;
/// 获取之前的缩放的倍数
/// @param userId 如果是屏幕共，传入userId为0
/// @param regionID 窗口ID，支持 0、1、2、3
- (CGFloat)viewScaleOfUserId:(NSString *)userId withRegionID:(NSInteger)regionID;

/// 移动/拖动播放视图
/// @param viewSize 播放视图的大小
/// @param userId 如果是屏幕共，传入userId为0
/// @param regionID  窗口ID
/// @param movement 移动的方向，和viewSize同单位
- (void)zoomMoveView:(CGSize)viewSize
            WithUserId:(NSString *)userId
        withRegionID:(NSInteger)regionID
            movement:(CGVector)movement;


/// 缩放播放视图
/// @param viewSize 播放视图的大小
/// @param userId 如果是屏幕共，传入userId为0
/// @param regionID 窗口ID
/// @param scale 缩放的倍数 不小于0，且不大于3
/// @param center 缩放的中心位置坐标
- (void)zoomScaleView:(CGSize)viewSize
           WithUserId:(NSString *)userId
         withRegionID:(NSInteger)regionID
                scale:(CGFloat)scale
               center:(CGPoint)center;


///刷新视图
///设置是否硬件解码优先，订阅码流之前调用有效
///@param enable YES-开启 NO-关闭
- (void)setHardDecodePriority:(BOOL)enable;

///获取当前用户的解码方式
- (BOOL)isHardDecode:(NSString *)userId;

///设置本地预览视图的scaleType
/// @param model 模式
/// @param regionID 窗口ID，支持 0、1
- (void)setLocalPreviewScaleType:(ERTCVideoFillMode)model withRegionID:(NSInteger)regionID;

///设置远端视图的scaleType
/// @param model 模式
/// @param userId 用户id
- (void)setRemoteViewScaleType:(ERTCVideoFillMode)model  withUserId:(NSString *)userId;

///质量监测回调时间设置
/// @param interval 时间间隔
- (void)setQualityInterval:(int)interval;

///不接收所有人视频流
///@param mute 为YES时不接受所有人视频流  False 接收所有人视频流
- (void)muteAllRemoteVideoStreams:(BOOL)mute;

///关闭房间声音
- (void)closeRoomSound:(BOOL)open;

///设置滤镜
- (void)setFilter:(ERTCFilterType )type filterLevel:(float)filterLevel;

///强制关闭其他人的屏幕共享
- (void)forceCloseOtherScreenShare;

///网络状态变化信息同步 0-切换 1-断开 2-恢复
- (void)setNetworkChange:(NSInteger)state;

///刷新窗口
///@param userId 远端用户ID
- (void)refreshRemoteView:(NSString *)userId;

///获取播放视频时对应的图片
/// @param userId 远端用户ID
- (NSData *)getJPEGOfUserId:(NSString *)userId;
@end

NS_ASSUME_NONNULL_END
