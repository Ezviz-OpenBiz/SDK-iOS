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

@class EZVideoTalk;
@class EZRTCCameraParam;
@class EZRTCVideoEncodeParam;

@protocol EZVideoTalkDelegate<NSObject>

@required
/// 错误回调
/// @param client client
/// @param errorCode 出错的错误码
- (void)bavClient:(EZVideoTalk *)client didReceivedError:(int32_t)errorCode;

/**
 回调消息

 @param client client
 @param messageCode 消息码 参见EZBAVMessage
 @param msg 附加信息，
    如果是EZBAVMessagePeerEnteredRoom、EZBAVMessagePeerLeaveRoom消息，msg是EZRTCParticipantsInfo对象
    如果消息是 EZBAVMessageTransferData msg是 msg是字符串 @"实际的透传消息"
 */
- (void)bavClient:(EZVideoTalk *)client didReceivedMessage:(int32_t)messageCode msg:(id)msg;


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
- (void)bavClient:(EZVideoTalk *)client didDisplayWidth:(int32_t)width height:(int32_t)height;

/**
 播放卡顿
 
 @param client client
 @param delayTime 卡顿时间
 */
- (void)bavClient:(EZVideoTalk *)client playDelayTime:(int32_t)delayTime;

///**
// 播放卡顿统计
//
// @param client client
// @param delayTimeStat 卡顿时间
// */
//- (void)bavClient:(EZVideoTalk *)client playDelayTimeStatistics:(double)delayTimeStat;

@end



/// 双向音视频通话类
/// 1.主动呼叫
/// A.发起
/// - init
/// - enableCapture
/// - start:param  role=0 reason=0 roomid=0
/// B.通话结束 调用 stop
/// C.等待对方过程中挂断 调用stop
/// 2.被动收到呼叫
/// - init
/// - enableCapture
/// 展示接听界面
/// A.如果接听 调用 start：param role=1 reason=0 roomid=收到的roomid 接听完通话中挂断调用stop
/// B.如果主动拒接 调用 start：param role=2 reason=101 roomid=收到的roomid 拒接完成后立马调用stop
/// C.如果无人接听 调用 start：param role=2 reason=102 roomid=收到的roomid 完成后立马调用stop
@interface EZVideoTalk : NSObject

@property (nonatomic, weak) id<EZVideoTalkDelegate> delegate;
@property (nonatomic, assign, readonly) int32_t roomID;


/**
 对讲时，强制采用扬声器播放声音，默认为YES
 */
@property (nonatomic, assign) BOOL forceToSpeaker;


/// 初始化视频通话SDK对象
- (instancetype)init;



/// 设置本地的预览窗口
/// @param localWin 窗口window
- (void)setLocalWindow:(EZVideoTalkView *)localWin;


/// 本地摄像头开启/关闭接口
/// @param enable 是否开启摄像头
- (NSInteger)enableVideoCapture:(BOOL)enable;


/// 本地麦克风开启/关闭接口
/// @param enable 是否开启麦克风
- (NSInteger)enableAudioCatpure:(BOOL)enable;


// 是否开启屏幕共享
/// @param enable 是否开启
/// @param block 主线程回调结果
- (void)enableScreenShare:(BOOL)enable andName:(NSString *)name withResultBlock:(EZScreenShareResultBlock)block;


/// 发起双向音视频对讲，耗时接口，成功返回 noErr，失败返回错误码
/// @param param EZBAVParam
- (int32_t)startWithParam:(EZBAVParam *)param;

/// 设置远程窗口，.如果设置非空对象view，必须在主线程调用（如果是设置成nil，可以不在主线程调用）
/// @param window 播放窗口
- (int32_t)setRemoteWindow:(UIView *)window;

///  停止双向音视频对讲，成功返回 noErr，失败返回错误码
- (int32_t)stop;

#pragma 附加接口

/// 切换对讲时使用的摄像头，默认采用前置 同步接口
/// @param backCameraSelected YES:选择后置，NO:选择前置
- (int32_t)switchCamera:(BOOL)backCameraSelected;


/// 开关远程声音，默认开
/// @param open 开启
- (int32_t)enableRemoteSound:(BOOL)open;
/// 异步获取本地抓图
/// @param block 抓图成功回调，失败image为nil
//- (void)localScreenShotWithBlock:(void (^)(UIImage *image))block;

/// 获取远端抓图
/// @param quality 压缩质量 0 ~ 100
//- (UIImage *)remoteScreenShotWithQuality:(int)quality;

/// 本地录制
/// @param path 写入的沙盒路径
//- (BOOL)startLocalVideoRecordWithPath:(NSString *)path;

/// 停止本地录制
//- (BOOL)stopLocalVideoRecord;

/// 开始远端录制 mp4
/// @param path 写入的沙盒路径
//- (BOOL)startRemoteVideoRecordWithPath:(NSString *)path  forClient:(int32_t)clientID;


/// 停止远端录制
//- (BOOL)stopRemoteVideoRecordForClient:(int32_t)clientID;


/// 发送透传消息接口，同步接口，可能耗时
/// @param msg 消息内容，比如json数据
- (int)sendTransferMsg:(NSString *)msg;

@end
