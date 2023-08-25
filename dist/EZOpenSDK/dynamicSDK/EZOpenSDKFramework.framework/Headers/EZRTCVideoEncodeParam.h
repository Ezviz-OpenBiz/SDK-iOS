//
//  EZMediaSessionEncodeParam.h
//  EZMediaSession
//
//  Created by kanhaiping on 2018/8/24.
//  Copyright © 2018年 hikvision. All rights reserved.
//

#import <Foundation/Foundation.h>

@class EZRTCCameraParam;

@interface EZRTCVideoEncodeParam : NSObject

//如果编码的目标宽高为0，则编码输出为输入的原始宽高
@property (nonatomic, assign) NSInteger pixelWidth;
@property (nonatomic, assign) NSInteger pixelHeight;
//可选参数，帧率
@property (nonatomic, assign) NSInteger fps;
//必填参数，码率，单位 bps
@property (nonatomic, assign) NSInteger averageBPS;
//只读参数
@property (nonatomic, assign, readonly) NSInteger maxBPS;
//可选参数，I帧间隔，单位秒
@property (nonatomic, assign) NSInteger encodeKeyFrameInterval;

//+ (EZRTCVideoEncodeParam *)encodeParamFromVideoParam:(EZRTCCameraParam *)videoParam;
+ (EZRTCVideoEncodeParam *)defaultEncodeParam;
+ (EZRTCVideoEncodeParam *)defaultSmallEncParam;
+ (EZRTCVideoEncodeParam *)deviceWatchParam;
+ (EZRTCVideoEncodeParam *)deviceBabyRobotParam;
+ (EZRTCVideoEncodeParam *)encodeParamForScreenShare;
+ (EZRTCVideoEncodeParam *)encodeParamForGlobalScreenShare;

@end
