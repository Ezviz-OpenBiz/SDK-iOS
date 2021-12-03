//
//  EZVideoTalkGlobal.h
//  EZVideoTalk
//
//  Created by yuqian on 2018/9/12.
//  Copyright © 2018年 hikvision. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "EZRTCMediaSessionDefines.h"

@class EZRTCVideoEncodeParam;
@class EZRTCCameraParam;

@interface EZVideoTalkGlobal : NSObject

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



/// 设置采集的摄像头参数，比如采用前置还是后置，在发起任何视频操作前调用生效
/// @param cameraParam 摄像头参数
+ (void)setCameraParam:(EZRTCCameraParam *)cameraParam;


/// 设置采集的视频的编码参数，比如采集最终输出的分辨率、码率等
/// @param encodeParam 编码参数
+ (void)setVideoEncodeParam:(EZRTCVideoEncodeParam *)encodeParam;


/// 设置采集的辅流的编码参数，比如采集最终输出的分辨率、码率等
/// @param encodeParam 编码参数
+ (void)setSmallVideoEncodeParam:(EZRTCVideoEncodeParam *)encodeParam;


+ (EZRTCAudioEncodeType)audioEncodeType;

/// 设置编码类型，在视频通话发起前设置有效
+ (void)setAudioEncodeType:(EZRTCAudioEncodeType)type;

@end
