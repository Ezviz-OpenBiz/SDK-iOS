//
//  EZSubDeviceInfo.h
//  EZPlay
//
//  Created by JuneCheng on 2023/12/6.
//

#import <Foundation/Foundation.h>
#import "EZCameraInfo.h"

NS_ASSUME_NONNULL_BEGIN

@interface EZSubDeviceInfo : EZCameraInfo

@property (nonatomic, assign) NSInteger resourceType;///< 资源类型
@property (nonatomic, copy) NSString *resourceName;///< 资源名称

/// 是否支持对讲 0-不支持对讲，1-支持全双工对讲，3-支持半双工对讲，4-同时支持全双工和半双工
@property (nonatomic) NSInteger isSupportTalk;
/// 是否支持云台控制
@property (nonatomic) BOOL isSupportPTZ;
/// 是否支持放大
@property (nonatomic) BOOL isSupportZoom;
///是否支持提示音开关
@property (nonatomic) BOOL isSupportAudioOnOff;
/// 是否支持中心镜像翻转
@property (nonatomic) BOOL isSupportMirrorCenter;
/// 是否支持声波配网
@property (nonatomic) BOOL isSupportSoundWave;
/// 是否支持倍数回放
@property (nonatomic) BOOL isSupportPlaybackRate;
/// 内网直连下是否支持倍数回放
@property (nonatomic) BOOL isSupportDirectInnerRelaySpeed;
/// 是否支持SD卡录像下载
@property (nonatomic) BOOL isSupportSDRecordDownload;
/// 是否支持SD卡录像封面
@property (nonatomic) BOOL isSupportSdCover;

/**
 * 根据位数获取设备能力集
 * @param index 位数，必须大于0
 *
 * @return 能力值
 */
- (int)getSupportInt:(int)index;

/** 是否是视频类设备 */
- (BOOL)isCamera;

@end

NS_ASSUME_NONNULL_END
