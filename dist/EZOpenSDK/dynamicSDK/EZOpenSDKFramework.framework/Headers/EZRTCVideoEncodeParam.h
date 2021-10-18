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
@property (nonatomic, assign) NSInteger pixelHeigth;
@property (nonatomic, assign) NSInteger fps;
@property (nonatomic, assign) NSInteger averageBPS;
@property (nonatomic, assign, readonly) NSInteger maxBPS;
@property (nonatomic, assign) NSInteger encodeKeyFrameInterval;//I帧间隔，单位秒

//+ (EZRTCVideoEncodeParam *)encodeParamFromVideoParam:(EZRTCCameraParam *)videoParam;
+ (EZRTCVideoEncodeParam *)defaultEncodeParam;
+ (EZRTCVideoEncodeParam *)deviceWatchParam;
+ (EZRTCVideoEncodeParam *)deviceBabyRobotParam;
+ (EZRTCVideoEncodeParam *)encodeParamForScreenShare;
+ (EZRTCVideoEncodeParam *)encodeParamForGlobalScreenShare;

@end
