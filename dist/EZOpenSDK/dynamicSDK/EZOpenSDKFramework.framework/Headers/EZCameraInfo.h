//
//  EZCameraInfo.h
//  EzvizOpenSDK
//
//  Created by DeJohn Dong on 15/9/15.
//  Copyright (c) 2015年 Ezviz. All rights reserved.
//

#import <Foundation/Foundation.h>

/// 此类为通道信息对象
@interface EZCameraInfo : NSObject

/// 摄像头名称
@property (nonatomic, copy) NSString *cameraName;
/// 通道号
@property (nonatomic) NSInteger cameraNo;
/// 设备序列号
@property (nonatomic, copy) NSString *deviceSerial;
/// 分享状态：0、未分享，1、分享所有者，2、分享接受者（表示此摄像头是别人分享给我的）
@property (nonatomic) NSInteger isShared;
/// 通道封面
@property (nonatomic, copy) NSString *cameraCover;
/// 视频质量，0-流畅，1-均衡，2-高清，3-超清，4-极清，5-3K，6-4K
@property (nonatomic) NSInteger videoLevel;
//权限
@property (nonatomic) NSInteger permission;
/// 通道支持的清晰度信息列表，EZVideoQualityInfo对象列表。(/api/device/list 返回的"videoQualityInfos" 有误，以/api/device/detail 接口返回为准)
@property (nonatomic, strong) NSArray *videoQualityInfos;

/// 设备是否开启加密
@property (nonatomic) BOOL isEncrypt;
/// 设备状态，1-在线，2-不在线
@property (nonatomic) NSInteger status;

/** 是否是视频类设备 */
- (BOOL)isCamera;

@end
