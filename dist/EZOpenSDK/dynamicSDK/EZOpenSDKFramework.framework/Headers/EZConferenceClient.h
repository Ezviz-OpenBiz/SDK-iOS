//
//  EZBAVClient.h
//  EZBAVClient
//
//  Created by kanhaiping on 2018/6/26.
//  Copyright © 2018年 hikvision. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "EZBAVParam.h"
#import "EZRTCMediaSessionDefines.h"
#import "EZVideoTalkView.h"



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
    如果是EZBAVMessageClientVolume消息，msg是EZBAVParticipantVolume对象
    如果消息是 EZBAVMessageTransferData msg是 msg是字符串 @"实际的透传消息"
    如果消息是EZBAVMessageClientAudioAvailable，msg是EZRTCParticipantsInfo对象，但是只有m_uClientId和audioState字段有效
    如果消息是EZBAVMessageClientVideoAvailable ，msg是EZRTCParticipantsInfo对象，但是只有m_uClientId和videoState字段有效
    如果消息是EZBAVMessageNetworkQuality ，msg是EZRTCParticipantsInfo对象，但是只有m_uClientId和netState字段有效
    如果消息是EZBAVMessageJoinRoomOK ，msg是nil
    如果消息是EZBAVMessageForcedQuit ，msg是NSNumber，比如@(EZBAVForcedQuitReasonMovedOut)
    如果消息是EZBAVMessageStatistic，msg是EZRTCStatistic
 
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


@end

@interface EZConferenceClient : NSObject

@property (nonatomic, weak) id<EZConferenceClientDelegate> delegate;
@property (nonatomic, assign, readonly) int32_t roomID;
@property (nonatomic, assign, readonly) int32_t clientID;


/**
 对讲时，强制采用扬声器播放声音，默认为YES
 */
@property (nonatomic, assign) BOOL forceToSpeaker;


/// 初始化视频通话SDK对象
- (instancetype)init;

/// 加入会议（新接口）
/// @param param 参数
- (NSInteger)enterRoom:(EZRTCJoinParam *)param;


/// 退出会议
- (NSInteger)exitRoom;


/// 解散会议，解散后，其他与会者会收到会议被解散消息
- (void)dissolveRoom;

/// 本地摄像头开启/关闭接口
/// @param enable 是否开启摄像头
- (NSInteger)enableLocalVideo:(BOOL)enable;

/// 设置本地的预览窗口
/// @param localWin 窗口window
- (void)setLocalView:(nullable EZVideoTalkView *)localWin;

/// 本地麦克风开启/关闭接口
/// @param enable 是否开启麦克风
/// @param block 主线程回调结果
- (void)enableLocalAudio:(BOOL)enable withResultBlock:(EZAudioOpenResultBlock)block;

/// 是否开启辅流，辅流分辨率更低、码率更小
/// @param enable 是否开启
/// @param encodeParam 编码参数，可以传入nil
- (NSInteger)enableLocalSmallVideo:(BOOL)enable;


/// 开启屏幕共享
/// @param name 共享名称
/// @param resultBlock 屏幕共享结果回调
/// @param didFinishBlock 屏幕共享结束回调，在正常的屏幕共享结束结束后回调
- (void)startScreenShareWithName:(NSString *)name
                 withResultBlock:(EZScreenShareResultBlock)resultBlock
                   andEndedBlock:(dispatch_block_t)didFinishBlock;


/// 结束屏幕共享
- (void)stopScreenShare;


/// 设置远程窗口，1.必须在拿到远端客户端加入的消息后设置，2.必须在主线程调用
/// @param window 播放窗口
/// @param clientID 加入的客户端的ID
/// @param streamType 1视频 4小流
- (int32_t)setRemoteView:(nullable UIView *)window ofClient:(int32_t)clientID withStream:(NSInteger)streamType;

/// 设置观看屏幕共享的窗口,必须在主线程调用
/// @param view 窗口
- (int32_t)setScreenShareView:(UIView *_Nullable)view;


/// 邀请设备加入会议
/// @param dev 设备信息
- (int32_t)inviteDev:(EZBAVDevInfo *_Nonnull)dev;


/// 切换对讲时使用的摄像头，默认采用前置 同步接口
/// @param backCameraSelected YES:选择后置，NO:选择前置
- (int32_t)switchCamera:(BOOL)backCameraSelected;


- (EZRTCStatistic *_Nullable)getStatistic;

#pragma 附加接口

/// 开关会议中某个与会者的声音，默认开
/// @param open YES:开，NO:关
- (int32_t)soundCtrl:(BOOL)open forClient:(int32_t)clientID;



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
- (int)sendTransferMsg:(NSString *)msg;

@end
