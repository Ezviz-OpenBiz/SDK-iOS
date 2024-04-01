//
//  EZVideoTalkGlobal.h
//  EZVideoTalk
//
//  Created by yuqian on 2018/9/12.
//  Copyright © 2018年 hikvision. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "EZRTCMediaSessionDefines.h"

#define EZVideoTalkVersion @"v6.4.5.20240308"

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
 打开视频码流抓取（包括自身采集和接收到的）

 @param enble 是否打开
 */
+(void)setDebugVideoStreamSave:(BOOL)enble;


/**
 打开音频码流抓取（包括自身采集和接收到的）

 @param enble 是否打开
 */
+(void)setDebugAudioStreamSave:(BOOL)enble;

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

/// 设置是否优先硬解，默认NO
/// @param enalbe YES:优先硬解 NO:采用软解
+ (void)setHardDecodePriority:(BOOL)enalbe;

+ (void)setPlayerWriteFlag:(NSArray<NSNumber *> *)flags;

/// 网络状态变化信息同步 0-切换 1-断开 2-恢复
/// @param networkChange 网络状态变化信息同步 0-切换 1-断开 2-恢复
+ (void)setNetworkChange:(NSInteger)networkChange;

#pragma mark - AGC
/// 设置是否开启AGC编码
/// @param enable YES：开启；NO：关闭
+ (void)setAgcEncode:(BOOL)enable;
+ (BOOL)agcEncodeEnable;

/// 设置AGC增益等级
/// @param agcLevel 输出增益等级0-30，默认27级，0表示AGC开关，等级1-30表示-32~-3，等级之间等间隔差-1dB
+ (void)setAgcLevel:(NSInteger)agcLevel;
+ (NSInteger)agcLevel;



#pragma mark - ECDH


/// 初始化SDK接口，当前内部仅初始化加密模块，如果不需要调用下面两个接口，则本接口不必须。
+ (void)initSDK;

/// 生成 本终端自己的 public key 和 private key，key 可以缓存到磁盘，定期比如三月更新一次即可
/// 如果需要调用该接口，必须先调用 initSDK接口初始化底层加密模块
/// @param selfPublicKey out 外部分配的用来存储publickey的char数组，比如 unsigned char key[256];
/// @param selfPublicKeyLen out 生成的key的长度，指针
/// @param selfPrivateKey out 外部分配的用来存储privatekey的char数组，比如 unsigned char key[256];
/// @param selfPrivateKeyLen out 生成的key的长度，指针
+ (void)generatePublicKey:(unsigned char *)selfPublicKey length:(unsigned int *)selfPublicKeyLen
               privateKey:(unsigned char *)selfPrivateKey length:(unsigned int *)selfPrivateKeyLen;

/// 设置 本终端 的公私钥
/// 如果需要调用该接口，必须先调用 initSDK接口初始化底层加密模块
/// @param selfPublicKey 公钥
/// @param selfPublicKeyLen 长度
/// @param selfPrivateKey 私钥
/// @param selfPrivateKeyLen 长度
+ (void)setPublicKey:(unsigned char *)selfPublicKey length:(unsigned int)selfPublicKeyLen
          privateKey:(unsigned char *)selfPrivateKey length:(unsigned int)selfPrivateKeyLen;

@end
