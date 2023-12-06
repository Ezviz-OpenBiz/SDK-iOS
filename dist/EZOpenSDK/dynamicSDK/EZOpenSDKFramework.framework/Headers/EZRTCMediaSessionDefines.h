//
//  EZMediaSessionDefines.h
//  H264 Encode and Decode
//
//  Created by kanhaiping on 2018/6/22.
//  Copyright © 2018年 AJB. All rights reserved.
//

#import <Foundation/Foundation.h>

#define EZMediaSessionEncodeResolutionRatioHigh  1  //分辨率 1：480*480 0：320*320
#define EZMediaSessionDstVideoFPS (15)
#define EZMediaSessionDstVideoMaxKeyFrameInterval (300)//单位秒

#define EZMediaSessionSmallStreamWidth (320)
#define EZMediaSessionSmallStreamHeight (320)

#define EZMediaSessionDefaultStreamWidth (480)
#define EZMediaSessionDefaultStreamHeight (640)

#define EZMediaSessionDstVideoAverageBitRate640x480 (5 * 128 * 1024)//单位 bps  //averageBPS
#define EZMediaSessionDstVideoAverageBitRate480x480 (4 * 128 * 1024)//单位 bps  //averageBPS
#define EZMediaSessionDstVideoDataRateLimits480x480 (6 * 128 * 1024)//单位 bps  //maxBPS
#define EZMediaSessionDstVideoAverageBitRate320x320 (4 * 128 * 1024 * 5 / 8)//单位 bps  //averageBPS
#define EZMediaSessionDstVideoDataRateLimits320x320 (6 * 128 * 1024 * 5 / 8)//单位 bps  //maxBPS

#define EZMediaSessionDstVideoAverageBitRate160x120 (64 * 1024)//单位 bps  //averageBPS
#define EZMediaSessionDstSmallVideoFPS (7)

#define EZPixelBlockSize (16)
#define EZPixelStandard(pixelSize) (ceil((double)(pixelSize)/EZPixelBlockSize)*EZPixelBlockSize)
#define EZMediaSessionScreenShareHeight (1920)
#define EZMediaSessionScreenShareWidth  EZPixelStandard((EZMediaSessionScreenShareHeight * UIScreen.mainScreen.bounds.size.width / UIScreen.mainScreen.bounds.size.height))
#define EZMediaSessionScreenShareFPS (10)
#define EZMediaSessionScreenShareAverageBitRate (8 * 128 * 1024)//单位 bps

typedef NS_OPTIONS(NSUInteger, EZMediaCaptureSessionType) {
    EZMediaSessionCaptureNone = 1 << 0,
    EZMediaSessionCaptureVideoType = 1 << 1,
    EZMediaSessionCaptureAudioType = 1 << 2,
    EZMediaSessionCaptureThumbnailType = 1 << 3,
    EZMediaSessionCaptureShareScreenType = 1 << 4,

};

typedef NS_ENUM(NSUInteger, EZMediaSessionErrorBase) {
    EZMediaSessionErrorUnknowError = 9000,
    EZMediaSessionErrorNotReadyToSendData,
    EZMediaSessionErrorCallSeqError,
    EZMediaSessionErrorDuplicated,
    EZMediaSessionErrorParamError,
    EZMediaSessionErrorBaseAudioCapture = 10000,
    EZMediaSessionErrorBaseVideoCapture = 20000,
    EZMediaSessionErrorBaseAudioEncode = 30000,
    EZMediaSessionErrorBaseVideoEncode = 40000,
    EZMediaSessionErrorBaseStreamClient = 50000,
    EZMediaSessionErrorBasePlayer = 60000,
};

typedef NS_ENUM(NSUInteger, EZAudioRecorderError) {
    EZAudioRecorderErrorUnknown = EZMediaSessionErrorBaseAudioCapture,
    EZAudioRecorderErrorInitError = 10100,
    EZAudioRecorderErrorUnableToCreateSample,
    EZAudioRecorderErrorStateError,
    EZAudioRecorderErrorAuthorizeFailed = 10152,
    EZAudioRecorderErrorStopError = 10200,
};

typedef NS_ENUM(NSUInteger, EZMediaCaptureError) {
    EZMediaCaptureErrorUnknown = EZMediaSessionErrorBaseVideoCapture,
    EZMediaCaptureErrorInitError = 20100,
    EZMediaCaptureErrorAuthorizeFailed = 20153,
    EZMediaCaptureErrorSwitchCameraError = 20200,
    EZMediaCaptureErrorCroppedError = 20300,
    EZMediaCaptureErrorRenderError = 20400,
    EZMediaCaptureErrorScreenStartError = 20500,
    EZMediaCaptureErrorScreenStopError,
    EZMediaCaptureErrorScreenRecordError,
    EZMediaCaptureErrorUnsupport,
};

typedef NS_ENUM(NSUInteger, EZAudioEncoderError) {
    EZAudioEncoderErrorUnknown = EZMediaSessionErrorBaseAudioEncode,
    EZAudioEncoderErrorFailToInitConverter = 30100,
    EZAudioEncoderErrorFailToGetDataBuffer,
    EZAudioEncoderErrorFailToEncodeBuffer,
};

typedef NS_ENUM(NSUInteger, EZVideoH264EncoderError) {
    EZVideoH264EncoderErrorUnknown = EZMediaSessionErrorBaseVideoEncode,
    EZVideoH264EncoderErrorInitFailed = 40100,
    EZVideoH264EncoderErrorInvalidSample,
    EZVideoH264EncoderErrorSampleNotReady,
    EZVideoH264EncoderErrorNotRunning,
    EZVideoH264EncoderErrorSetMaxBPSFailed,
    EZVideoH264EncoderErrorSetAverageBPSFailed,
    EZVideoH264EncoderErrorParamError,
    EZVideoH264EncoderErrorEncodeFailed = 40200,
};

typedef NS_ENUM(NSUInteger, EZBAVStreamClientError) {
    EZBAVStreamClientErrorUnknow = EZMediaSessionErrorBaseStreamClient,
    EZBAVStreamClientErrorAudioEnableNotAllowed = EZMediaSessionErrorBaseStreamClient + 9000,
    EZBAVStreamClientErrorShareEnableNotAllowed,

};


typedef NS_ENUM(NSUInteger, EZRTCAudioEncodeType) {
    EZRTCAudioEncodeType_AAC = 0,//该枚举值不能轻易修改
    EZRTCAudioEncodeType_Opus = 1,
};


@interface EZRTCMediaSessionDefines : NSObject
@end

typedef void(^EZScreenShareResultBlock)(NSInteger ret);

///拉伸填充模式
extern int32_t const EZRTCVideoScaleType_Fill;
///保持宽高比 缩放模式 可能有黑边
extern int32_t const EZRTCVideoScaleType_ResizeAspectFit;
///保持宽高比 填充模式 可能画面被裁剪
extern int32_t const EZRTCVideoScaleType_ResizeAspectFill;
