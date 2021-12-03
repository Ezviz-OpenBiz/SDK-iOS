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
#define EZMediaSessionDefaultStreamHeight (480)

#define EZMediaSessionDstVideoAverageBitRate480x480 (4 * 128 * 1024)//单位 bps  //averageBPS
#define EZMediaSessionDstVideoDataRateLimits480x480 (6 * 128 * 1024)//单位 bps  //maxBPS
#define EZMediaSessionDstVideoAverageBitRate320x320 (4 * 128 * 1024 * 5 / 8)//单位 bps  //averageBPS
#define EZMediaSessionDstVideoDataRateLimits320x320 (6 * 128 * 1024 * 5 / 8)//单位 bps  //maxBPS


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
    EZRTCAudioEncodeType_AAC,
    EZRTCAudioEncodeType_Opus,
};


@interface EZRTCMediaSessionDefines : NSObject
@end

typedef void(^EZScreenShareResultBlock)(NSInteger ret);
