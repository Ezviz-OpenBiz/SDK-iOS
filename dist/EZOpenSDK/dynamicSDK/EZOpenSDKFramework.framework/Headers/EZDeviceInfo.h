//
//  EZDeviceInfo.h
//  EzvizOpenSDK
//
//  Created by DeJohn Dong on 15/9/16.
//  Copyright (c) 2015年 Ezviz. All rights reserved.
//

#import <Foundation/Foundation.h>

/// 此类为设备信息对象
@interface EZDeviceInfo : NSObject

/// 设备关联的通道信息
@property (nonatomic, strong) NSArray *cameraInfo;
/// 设备关联的通道数量
@property (nonatomic) NSInteger cameraNum;
/// 具有防护能力的设备布撤防状态：0-睡眠，8-在家，16-外出，普通IPC布撤防状态：0-撤防，1-布防
@property (nonatomic) NSInteger defence;
/// 设备关联的探测器数量
@property (nonatomic) NSInteger detectorNum;
/// 设备关联的探测器信息
@property (nonatomic, strong) NSArray *detectorInfo;
/// 设备关联的子设备信息
@property (nonatomic, strong) NSArray *subDeviceInfo;
/// 设备图片
@property (nonatomic, copy) NSString *deviceCover;
/// 设备名称
@property (nonatomic, copy) NSString *deviceName;
/// 设备序列号
@property (nonatomic, copy) NSString *deviceSerial;
/// 设备类型
@property (nonatomic, copy) NSString *deviceType;
/// 设备版本号
@property (nonatomic, copy) NSString *deviceVersion;
/// 设备协议版本号类型  0:非国标 6:国标
@property (nonatomic) NSInteger devProtoEnum;
/// 设备是否开启加密
@property (nonatomic) BOOL isEncrypt;
/// 设备状态，1-在线，2-不在线
@property (nonatomic) NSInteger status;
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
/// 设备大类
@property (nonatomic, copy) NSString *category;
/// 添加时间
@property (nonatomic, strong) NSDate *addTime;

/**
 * 根据位数获取设备能力集
 * @param index 位数，必须大于0
 *
 * @return 能力值
 */
- (int)getSupportInt:(int)index;

@end
