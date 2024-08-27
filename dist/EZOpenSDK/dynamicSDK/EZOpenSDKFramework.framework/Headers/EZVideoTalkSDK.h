//
//  EZVideoTalkSDK.h
//  EZOpenSDK
//
//  Created by yuqian on 2020/3/14.
//  Copyright © 2020 Hikvision. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "EZRTCMediaSessionDefines.h"
#import "EZBAVParam.h"


NS_ASSUME_NONNULL_BEGIN


@class EZVideoTalkSDK, EZMediaSessionVideoParam, EZVideoTalkView, EZBAVParam, EZConferenceParam;

@protocol EZVideoTalkSDKDelegate<NSObject>

- (void)videoTalk:(id)client didReceivedError:(int32_t)errorCode;

/**
 回调消息

 @param client client
 @param messageCode 消息码 参见EZBAVMessage
 @param msg 透传消息，
    如果是EZVideoTalkMessagePeerEnteredRoom和EZVideoTalkMessagePeerLeaveRoom消息，msg是{@"clientID":@(9527),@"clientName":@"张三"}
        如果消息是 EZVideoTalkMessageTransferData msg是 msg是{@"content":@"实际的透传消息"}
 */
- (void)videoTalk:(id)client didReceivedMessage:(int32_t)messageCode msg:(id)msg;

/// 画面显示回调
/// @param client client
/// @param width 画面的宽 像素单位
/// @param height 画面的高 像素单位
/// @param userID 用户id
- (void)videoTalk:(id)client didDisplayWidth:(int32_t)width height:(int32_t)height ofRemoteClient:(NSString *)userID;

@end

@interface EZVideoTalkSDK : NSObject

@property (nonatomic, weak) id<EZVideoTalkSDKDelegate> delegate;

/// 加入的房间号
@property (nonatomic, assign, readonly) int32_t roomID;

/**
 对讲时，强制采用扬声器播放声音，默认为YES
 */
@property (nonatomic, assign) BOOL forceToSpeaker;

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


/// 是否开启屏幕共享
/// @param enable 是否开启
- (NSInteger)enableScreenShare:(BOOL)enable withName:(NSString *)name;


/// 发起双向音视频对讲，耗时接口，成功返回 noErr，失败返回错误码
/// @param param EZBAVParam
- (int32_t)startWithParam:(EZBAVParam *)param;

/// 设置远程窗口，.如果设置非空对象view，必须在主线程调用（如果是设置成nil，可以不在主线程调用）
/// @param window 播放窗口
- (int32_t)setRemoteWindow:(UIView *)window;

///  停止双向音视频对讲，成功返回 noErr，失败返回错误码
- (int32_t)stop;

/// 切换对讲时使用的摄像头，默认采用前置 同步接口
/// @param backCameraSelected YES:选择后置，NO:选择前置
- (int32_t)switchCamera:(BOOL)backCameraSelected;


/// 开关远程声音，默认开
/// @param open 开启
- (int32_t)enableRemoteSound:(BOOL)open;

#pragma mark - 日志调试
/**
 日志设置
 
 @param enable 是否打印日志
 @param logCallback 日志回调，上层自定义处理
 */
+ (void)setDebugLogEnable:(BOOL)enable withLogCallback:(void(^)(NSString *logStr))logCallback;

/**
 打开对端码流抓取

 @param enble 是否打开
 */
+(void)setDebugVideoLog:(BOOL)enble;

/**
 获取sdk版本信息

 @return 版本号
 */
+ (NSString*)getVersion;

@end


@interface EZRTCClient : NSObject

@property (nonatomic, weak) id<EZVideoTalkSDKDelegate> delegate;

/// 加入的房间号
@property (nonatomic, assign, readonly) int32_t roomID;

/**
 对讲时，强制采用扬声器播放声音，默认为YES
 */
@property (nonatomic, assign) BOOL forceToSpeaker;


/// 初始化视频通话SDK对象
- (instancetype)init;


/// 加入会议（新接口）
/// @param roomId 房间号
/// @param password 密码
/// @param userID 用户自定义ID
- (void)enterRoom:(int32_t)roomId
     withPassword:(NSString *)password
       withUserID:(NSString *)userID
       withAppId:(NSString *)appId;


/// 退出会议
- (NSInteger)exitRoom;


/// 解散会议，解散后，其他与会者会收到会议被解散消息
- (void)dissolveRoom;

/// 本地摄像头开启/关闭接口.
/// @param enable 是否开启摄像头
- (NSInteger)enableLocalVideo:(BOOL)enable;

/// 设置本地的预览窗口
/// @param localWin 窗口window
- (void)setLocalView:(EZVideoTalkView *)localWin;

/// 是否开启辅流，辅流分辨率更低、码率更小
/// @param enable 是否开启
- (NSInteger)enableLocalSmallVideo:(BOOL)enable;

/// 本地麦克风开启/关闭接口
/// @param enable 是否开启麦克风
/// @param block 主线程回调结果
- (void)enableLocalAudio:(BOOL)enable withResultBlock:(EZAudioOpenResultBlock)block;

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
/// @param streamType 1视频 2音频 4小流
- (int32_t)setRemoteView:(nullable UIView *)window ofUser:(NSString *)userID withStream:(NSInteger)streamType;

/// 设置观看屏幕共享的窗口,必须在主线程调用
/// @param view 窗口
- (int32_t)setScreenShareView:(UIView *_Nullable)view;

/// 切换对讲时使用的摄像头，默认采用前置 同步接口
/// @param backCameraSelected YES:选择后置，NO:选择前置
- (int32_t)switchCamera:(BOOL)backCameraSelected;

#pragma mark - 录制相关接口
/// 开始房间视频会议录制
/// @param roomId 房间号
/// @param customId 开发者自定义用户ID
/// @param recUsers 需要录制的房间参与者id
/// @param projectId 云存储项目ID
/// @param fileId 云存储文件名
/// @param completion operation
+ (void)requestStartRecordRoomId:(NSString *)roomId
                        customId:(NSInteger)customId
                        recUsers:(NSArray *)recUsers
                       projectId:(NSString *)projectId
                          fileId:(NSString *)fileId
                      completion:(void (^)(bool success, NSError *error))completion;

/// 停止房间视频会议录制
/// @param roomId 房间号
/// @param customId 开发者自定义用户ID
/// @param completion operation
+ (void)requestStopRecordRoomId:(NSString *)roomId
                       customId:(NSInteger)customId
                     completion:(void (^)(bool success, NSError *error))completion;

/// 获取文件下载地址
/// @param projectId 项目ID
/// @param fileId 文件ID
/// @param completion operation
+ (void)requestGetRecordFileProjectId:(NSString *)projectId
                               fileId:(NSString *)fileId
                           completion:(void (^)(id responseObject, NSError *error))completion;


/// 新建项目接口
/// @param projectId 项目ID
/// @param projectName 项目名称
/// @param expireDays 项目存储对象过期天数 默认永不过期
/// @param completion operation
+ (void)requestCreateProjectId:(NSString *)projectId
                   projectName:(NSString *)projectName
                    expireDays:(NSInteger )expireDays
                    completion:(void (^)(bool success, NSError *error))completion;



#pragma mark - 4.16.3 新的会控接口
/// 预订会议接口
/// @param customId 主持人用户id（开发者自定义的用户id）
/// @param password 房间密码（若不传或为空则认为房间公开、无密码）
/// @param limit 房间人数限制（<100，不传则默认100）
/// @param beginTime 毫秒时间戳，会议预计开始时间（>=当前时间）
/// @param endTime 毫秒时间戳，会议预计结束时间（>beginTime且<七天后的时间戳）
/// @param completion completion
+ (NSURLSessionDataTask *)orderMeetingWithCustomId:(NSString *)customId
                                          password:(NSString *)password
                                             limit:(NSInteger)limit
                                         beginTime:(long)beginTime
                                           endTime:(long)endTime
                                        completion:(void (^)(int32_t roomId, NSInteger limit, NSError *error))completion;



@end



NS_ASSUME_NONNULL_END
