//
//  EZProbeDeviceInfo.h
//  EZWiFiConfigSDK
//
//  Created by DeJohn Dong on 15/12/11.
//  Copyright © 2015年 Ezviz. All rights reserved.
//

#import <Foundation/Foundation.h>

/// 此类为查询设备信息对象（设备添加前使用）
@interface EZProbeDeviceInfo : NSObject

/// 展示名称
@property (nonatomic, copy) NSString *displayName;
/// 设备大类名
@property (nonatomic, copy) NSString *category;
/// 设备型号名
@property (nonatomic, copy) NSString *model;
/// 设备短序列号
@property (nonatomic, copy) NSString *subSerial;
/// 设备长序列号
@property (nonatomic, copy) NSString *fullSerial;
/// 设备在线状态，1-在线，其他-不在线
@property (nonatomic) NSInteger status;
/// 设备图片
@property (nonatomic, copy) NSString *defaultPicPath;
/// 是否支持wifi，0-不支持，1-支持，2-支持带userId的新的wifi配置方式，3-支持smartwifi
@property (nonatomic) NSInteger supportWifi;
/// 是否支持AP配网，2-支持AP，其他值为不支持AP配网
@property (nonatomic) NSInteger supportAP;
/// AP配网协议类型，1-HTTP 2-NETSDK
@property (nonatomic) NSInteger supportAPType;
/// 是否支持声波配置，0-不支持，1-支持
@property (nonatomic) NSInteger supportSoundWave;
/// 设备热点前缀标识，0-EZVIZ，1-SoftAP，2-CAMGO
@property (nonatomic) NSInteger deviceHotSpot;
/// 是否支持云存储，0-不支持，1-支持
@property (nonatomic) NSInteger supportCloud;
/// 设备协议版本
@property (nonatomic, copy) NSString *releaseVersion;
/// 设备版本
@property (nonatomic, copy) NSString *version;
/// 可用于添加的通道数
@property (nonatomic) NSInteger availiableChannelCount;
/// N1，R1，A1等设备关联的设备数
@property (nonatomic) NSInteger relatedDeviceCount;
/// 能力集
@property (nonatomic, copy) NSString *supportExt;

@property (nonatomic, readonly) NSDictionary *abilitiesExt; //设备能力集扩展

@end
