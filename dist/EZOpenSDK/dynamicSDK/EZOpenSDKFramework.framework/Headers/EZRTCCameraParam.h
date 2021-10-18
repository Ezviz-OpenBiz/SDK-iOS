//
//  EZMediaSessionVideoParam.h
//  EZBAVClient
//
//  Created by kanhaiping on 2018/7/13.
//  Copyright © 2018年 hikvision. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>

@interface EZRTCCameraParam : NSObject


/// 摄像头采集采集画面的默认设置，比如AVCaptureSessionPreset1280x720，请传入AVCaptureSessionPreset640x480 以上的分辨率
//@property (nonatomic, strong) AVCaptureSessionPreset resolutionPreset;

/// 最终输出的画面的宽
//@property (nonatomic, assign) NSInteger pixelWidth;
//
///// 最终输出的画面的高
//@property (nonatomic, assign) NSInteger pixelHeigth;

/// 传入 AVCaptureVideoOrientation，默认竖屏
@property (nonatomic, assign) AVCaptureVideoOrientation videoOrientation;


/// 是否是后置摄像头，默认NO
@property (nonatomic, assign) BOOL isBackCameraSeleced;

///// I帧间隔 默认4秒
//@property (nonatomic, assign) NSInteger encodeKeyFrameInterval;
//
///// 帧率
//@property (nonatomic, assign) NSInteger fps;

+ (AVCaptureSessionPreset)resolutionPresetForWidth:(NSInteger)width andHeigth:(NSInteger)heigth andOri:(AVCaptureVideoOrientation)ori;
@end
