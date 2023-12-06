//
//  EZBAVClient.h
//  EZBAVClient
//
//  Created by kanhaiping on 2018/6/26.
//  Copyright © 2018年 hikvision. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "EZRTCMediaSessionDefines.h"
#import "EZBAVParam.h"
#import "EZVideoTalkView.h"
#import "EZRTCFilterParam.h"


@class EZConferenceClient;
@class EZRTCCameraParam;
@class EZRTCVideoEncodeParam;

@protocol EZConferenceClientDelegate<NSObject>


/// 错误回调
/// @param client client
/// @param errorCode 出错的错误码
- (void)bavClient:(EZConferenceClient *)client didReceivedError:(int32_t)errorCode;

/**
 回调消息

 @param client client
 @param messageCode 消息码 参见EZBAVMessage
 @param msg 附加信息，
    如果是EZBAVMessagePeerEnteredRoom，msg是EZRTCParticipantsInfo对象，但是只有m_uClientId、m_szUserName字段有效
    如果是EZBAVMessagePeerLeaveRoom消息，msg是EZRTCParticipantsInfo对象，但是只有m_uClientId字段有效
    如果是EZBAVMessageVolumeInfo消息，msg是EZRTCParticipantVolumeInfo对象，包含了所有与会客户端（打开了声音的客户端）的音量
    如果消息是 EZBAVMessageTransferData msg是 msg是字符串 @"实际的透传消息"
    如果消息是EZBAVMessageClientAudioAvailable，msg是EZRTCParticipantsInfo对象，但是只有m_uClientId和audioState字段有效
    如果消息是EZBAVMessageClientVideoAvailable ，msg是EZRTCParticipantsInfo对象，但是只有m_uClientId和videoState字段有效
    如果消息是EZBAVMessageNetworkQuality ，msg是EZRTCParticipantsInfo对象，但是只有m_uClientId和netState字段有效
    如果消息是EZBAVMessageJoinRoomOK ，msg是nil
    如果消息是EZBAVMessageForcedQuit ，msg是NSNumber，比如@(EZBAVForcedQuitReasonMovedOut)
    如果消息是EZBAVMessageStatistic，msg是EZRTCStatistic
    如果消息是EZBAVMessageTransparent，msg是NSString 格式的json
 
 */
- (void)bavClient:(EZConferenceClient *)client didReceivedMessage:(int32_t)messageCode msg:(id)msg;


@optional

///**
// 回调消息 bavclient log回调
//
// @param client client
// @param msg 透传消息
// */
//- (void)bavClient:(EZVideoTalk *)client didReceivedBavClientLogMsg:(NSString*)msg;

/**
 显示回调，首次画面出来以及后续画面尺寸发生变化时回调

 @param client client
 @param width 画面宽度
 @param height 画面高度
 */
- (void)bavClient:(EZConferenceClient *)client didDisplayWidth:(int32_t)width height:(int32_t)height ofRemoteClient:(int)clientID;

/**
 播放卡顿
 
 @param client client
 @param delayTime 卡顿时间
 */
- (void)bavClient:(EZConferenceClient *)client playDelayTime:(int32_t)delayTime ofRemoteClient:(int)clientID;

/**
 播放卡顿统计
 
 @param client client
 @param delayTimeStat 卡顿时间
 */
- (void)bavClient:(EZConferenceClient *)client playDelayTimeStatistics:(double)delayTimeStat ofRemoteClient:(int)clientID;



/// 接收到与会者的自定义消息
/// @param client client
/// @param msg 消息
- (void)bavClient:(EZConferenceClient *)client didReceivedCustomMsg:(EZRTCParticipantCustomMsg *)msg;



/// 某个已订阅并显示的与会者，当前显示了一帧，该回调以每秒十几次的频率回调，请勿在该回调内做耗时操作
/// @param client client
/// @param clientID 已订阅并显示画面的与会者
/// @param length 当前显示的画面的数据的长度
- (void)bavClient:(EZConferenceClient *)client didDisplayOfClient:(int32_t)clientID withDataLength:(NSInteger)length;

/**
 本地视频数据回调
 
 @param localVideoStatistics 视频相关参数
 @param width    宽度
 @param height  高度
 */
- (void)onLocalVideoStats:(EZRTCLocalStatistics *)localVideoStatistics width:(int)width height:(int)height;

/**
 本地音频数据回调
 
 @param localAudioStatistics 音频相关参数
 */
- (void)onLocalAudioStats:(EZRTCLocalStatistics *)localAudioStatistics;

/**
 远端视频数据回调
 
 @param remoteVideoStatistics 视频相关参数
 @param width    宽度
 @param height  高度
 */
- (void)onRemoteVideoStats:(EZRTCRemoteStatistics *)remoteVideoStatistics width:(int)width height:(int)height;

/**
 远端音频数据回调
 
 @param remoteAudioStatistics 音频相关参数
 */
- (void)onRemoteAudioStats:(EZRTCRemoteStatistics *)remoteAudioStatistics;

/**
 网速测试回调
 
 @param result 回调结果
 */
//- (void)onSpeedTestResult:(EZRTCSpeedTestResult *)result;
@end


//typedef NS_ENUM(NSInteger, EZRTCVideoFillMode) {
//
//    ///填充模式：即将画面内容居中等比缩放以充满整个显示区域，超出显示区域的部分将会被裁剪掉，此模式下画面可能不完整。
//    EZRTCVideoFillMode_Fill = 0,
//
//    ///适应模式：即按画面长边进行缩放以适应显示区域，短边部分会被填充为黑色，此模式下图像完整但可能留有黑边。
//    EZRTCVideoFillMode_Fit = 1,
//
//};
//
//
///// 预览视图，用于预览本地用户或者远端用户的视频
//@interface EZRTCView : UIView
///// 显示模式
//@property (nonatomic, assign) EZRTCVideoFillMode fillMode;
//@end

@interface EZConferenceClient : NSObject

@property (nonatomic, weak) id<EZConferenceClientDelegate> delegate;
@property (nonatomic, assign, readonly) int32_t roomID;
@property (nonatomic, assign, readonly) int32_t clientID;

@property (nonatomic, assign) BOOL enableRoomAudio;//开关会场的声音，可以在加入房间前或者 加入房间后调用


/// 是否允许发送本地的视频，在enableLocalVideo 打开的情况下，是否允许发送，默认值为YES； 可以在加入房间前或后调用；也可以在 enableLocalVideo 前提前调用
@property (nonatomic, assign) BOOL enableLocalVideoStreamPublishing;


/// 是否允许视频双流模式，在enableLocalVideo  打开的情况下，会另外编码一路小码流以供按需发送，默认为NO；可以在加入房间前或者后调用，也可以在 enableLocalVideo 前或后调用
@property (nonatomic, assign) BOOL enableDualVideoStreamMode;

/**
 对讲时，强制采用扬声器播放声音，默认为YES
 */
@property (nonatomic, assign) BOOL forceToSpeaker;




/// 美颜开关 在enableLocalVideo前和后均可设置，如果enableLocalVideo 为 YES ，则实时生效
@property (nonatomic, assign) BOOL enableBeauty;

/// 设置美颜参数，美白、磨皮、红润等的效果值。在enableLocalVideo前和后均可设置，如果enableLocalVideo 为 YES ，则实时生效
@property (nonatomic, strong) EZRTCBeautyParam *beautyParam;


/// 滤镜效果类型选择 在enableLocalVideo前和后均可设置，如果enableLocalVideo 为 YES ，则实时生效
@property (nonatomic, assign) EZRTC_Basic_Filter_Type basicFilterType;


/// 滤镜效果的幅度 0~1.0 默认 0.5
@property (atomic, assign) float basicFilterIntensity;


/// 初始化视频通话SDK对象
- (instancetype)init;

/// 加入会议（新接口）
/// @param param 参数
- (NSInteger)enterRoom:(EZRTCJoinParam *)param;


/// 退出会议
- (NSInteger)exitRoom;


/// 解散会议，解散后，其他与会者会收到会议被解散消息
- (void)dissolveRoom;

/// 设置采集的摄像头参数，比如采用前置还是后置，在发起任何视频操作前调用生效
/// @param cameraParam 摄像头参数
- (void)setCameraParam:(EZRTCCameraParam *)cameraParam;


/// 设置采集的视频的编码参数，比如采集最终输出的分辨率、码率等
/// @param encodeParam 编码参数
- (void)setVideoEncodeParam:(EZRTCVideoEncodeParam *)encodeParam;


/// 本地摄像头开启/关闭接口
/// @param enable 是否开启摄像头
- (NSInteger)enableLocalVideo:(BOOL)enable;

/// 设置本地的预览窗口，已不再使用，建议使用下面的setLocalView
/// @param localWin 窗口window
- (void)setLocalView:(nullable EZVideoTalkView *)localWin;


/// 设置本地的预览窗口，支持设置多个，必须在主线程调用，如果窗口的大小发生变化，需要重新设置一遍
/// @param window 预览View
/// @param regionID 窗口ID，可以填0 、1、
- (NSInteger)setLocalView:(nullable UIView *)window withRegionID:(NSInteger)regionID;


/// 设置本地预览视图的scaleType
/// @param scaleType 画面的填充模式，比如EZRTCVideoScaleType_Fill EZRTCVideoScaleType_ResizeAspectFit
/// @param regionID 窗口ID，可以填0 、1、
- (NSInteger)setScaleType:(NSInteger)scaleType forLocalView:(NSInteger)regionID;

/// 设置音频编码参数，默认AAC
/// @param type 类型
- (void)setAudioEncodeType:(EZRTCAudioEncodeType)type;

/// 本地麦克风开启/关闭接口
/// @param enable 是否开启麦克风
- (NSInteger)enableLocalAudio:(BOOL)enable;


/// 打开音频大小回调
/// @param interval 设置音量回调的触发间隔，单位为ms，最小间隔为100ms
- (void)enableAudioVolumeEvaluation:(NSUInteger)interval;



/// 开启屏幕共享
/// @param name 共享名称
/// @param resultBlock 屏幕共享结果回调
/// @param didFinishBlock 屏幕共享结束回调，在正常的屏幕共享结束结束后回调
- (void)startScreenShareWithName:(NSString *)name
                 withResultBlock:(EZScreenShareResultBlock)resultBlock
                   andEndedBlock:(dispatch_block_t)didFinishBlock;


/// 结束屏幕共享
- (void)stopScreenShare;


/// 强制结束其他用户当前的屏幕共享
- (void)forceCloseOtherScreenShare;


/// 订阅远端用户的码流，并设置远程窗口，1.必须在拿到远端客户端加入的消息后设置，2.必须在主线程调用
/// 该接口同样可以用于订阅屏幕共享的码流，clientID传入0，streamType传入1
/// 该接口与 【subscribe:to:withStream:(NSInteger)streamType  + setRemoteView:forSubscribedClient:withRegionID: 】的配套接口 冲突，要么使用此接口；要么使用配套接口
/// @param window 播放窗口，如果设置为nil，则表示取消订阅
/// @param clientID 加入的客户端的ID
/// @param streamType 1视频大流 4小流
- (int32_t)setRemoteView:(nullable UIView *)window ofClient:(int32_t)clientID withStream:(NSInteger)streamType;


/// 单纯订阅，取消订阅某个用户的视频流，不涉及视图操作，不可以与setRemoteView:ofClient:withStream: 混用
/// 如果窗口与是否订阅该用户的码流是绑定的，则建议使用setRemoteView:ofClient:withStream:
/// @param subscribe YES-开启订阅 NO-取消订阅
/// @param clientID 用户的ID
/// @param streamType EZSubStreamType_Main大视频流  EZSubStreamType_Min 小视频流
- (int32_t)subscribe:(BOOL)subscribe to:(int32_t)clientID withStream:(NSInteger)streamType;


/// 在订阅某个clientID后，设置播放该用户的播放画面，支持针对用一个用户，设置多个画面播放，
/// 不可以与setRemoteView:ofClient:withStream: 混用
/// 必须在 主线程调用该接口
/// @param window 播放窗口
/// @param clientID 已订阅的用户的ID
/// @param regionID 窗口ID，支持 0、1、2、3
- (int32_t)setRemoteView:(nullable UIView *)window forSubscribedClient:(int32_t)clientID withRegionID:(NSInteger)regionID;



/// 设置电子放大接口
/// @param clientID 已订阅，并设置了播放视图的用户ID，如果是屏幕共享，传入clientID为0
/// @param regionID 已订阅，并设置了的RegionID
/// @param rect 上下左右的偏移，以像素为单位
- (int32_t)setDisplayRegionOfClient:(int32_t)clientID
                       withRegionID:(NSInteger)regionID
                             atRect:(CGRect)rect;



/// 获取之前的缩放的倍数
/// @param clientID clientID
/// @param regionID 窗口ID，支持 0、1、2、3
- (CGFloat)viewScaleOfClient:(int32_t)clientID withRegionID:(NSInteger)regionID;


/// 移动/拖动播放视图
/// @param viewSize 播放视图的大小
/// @param clientID clientID
/// @param regionID  窗口ID
/// @param movement 移动的方向，和viewSize同单位
- (void)zoomMoveView:(CGSize)viewSize
            ofClient:(int32_t)clientID
        withRegionID:(NSInteger)regionID
            movement:(CGVector)movement;


/// 缩放播放视图
/// @param viewSize 播放视图的大小
/// @param clientID clientID
/// @param regionID 窗口ID
/// @param scale 缩放的倍数 不小于0，且不大于3
/// @param center 缩放的中心位置坐标
- (void)zoomScaleView:(CGSize)viewSize
             ofClient:(int32_t)clientID
         withRegionID:(NSInteger)regionID
                scale:(CGFloat)scale
               center:(CGPoint)center;



/// 设置已订阅client的码流类型，如果未订阅，则不生效
/// @param streamType 1视频 4小流
/// @param clientID 客户端的ID
//- (int32_t)setStreamType:(NSInteger)streamType ofClient:(int32_t)clientID;

/// 设置远端用户的显示模式
/// @param scaleType 传入 EZRTCVideoScaleType_Fill 等
/// @param clientID 加入的客户端的ID
- (int32_t)setScaleType:(int32_t)scaleType ofClient:(int32_t)clientID;

/// 设置观看屏幕共享的窗口,必须在主线程调用
/// @param view 窗口
//- (int32_t)setScreenShareView:(UIView *_Nullable)view;


/// 邀请设备加入会议
/// @param dev 设备信息
- (int32_t)inviteDev:(EZBAVDevInfo *_Nonnull)dev;


/// 切换对讲时使用的摄像头，默认采用前置 同步接口
/// @param backCameraSelected YES:选择后置，NO:选择前置
- (int32_t)switchCamera:(BOOL)backCameraSelected;


- (EZRTCStatistic *_Nullable)getStatistic;


/// 设置质量回调间隔（>=1000ms）
/// @param interval interval 质量回调的触发间隔，单位为ms，最小间隔为1000ms，默认2000ms
+ (void)setQualityReportInterval:(NSInteger)interval;

#pragma 附加接口

/// 开关会议中某个与会者的声音，默认开
/// @param open YES:开，NO:关
- (int32_t)soundCtrl:(BOOL)open forClient:(int32_t)clientID;


/// 获取已订阅并播放的与会者的解码类型: -1表示失败 ; 1-表示软解；2 表示硬解
/// @param clientID clientID
- (int32_t)getDecodeEngineOfClient:(int32_t)clientID;


/// 刷新窗口视图
/// @param clientID clientID
- (void)refreshWindowOfClient:(int32_t)clientID;

/// 异步获取本地抓图
/// @param block 抓图成功回调，失败image为nil
//- (void)localScreenShotWithBlock:(void (^)(UIImage *image))block;

/// 获取远端抓图
/// @param quality 压缩质量 0 ~ 100
//- (UIImage *)remoteScreenShotWithQuality:(int)quality;

/// 本地录制
/// @param path 写入的沙盒路径
- (BOOL)startLocalVideoRecordWithPath:(NSString *)path;

/// 停止本地录制
- (BOOL)stopLocalVideoRecord;

/// 开始远端录制 mp4
/// @param path 写入的沙盒路径
- (BOOL)startRemoteVideoRecordWithPath:(NSString *)path  forClient:(int32_t)clientID;


/// 停止远端录制
- (BOOL)stopRemoteVideoRecordForClient:(int32_t)clientID;


/// 发送透传消息接口，同步接口，可能耗时
/// @param msg 消息内容，比如json数据
- (int)sendTransferMsg:(NSString *_Nonnull)msg;


/// 发送自定义消息给房间内所有用户
/// @param data data 待发送的消息，单个消息的最大长度被限制为 1KB
- (int)sendCustomMsg:(NSData *_Nonnull)data;

+ (void)setBAVLogLevel:(NSInteger)level;

///获取播放中的图片
/// @param clientID 客户端的ID
- (nullable NSData *)getJPEGOfClient:(int32_t)clientID;

@end
