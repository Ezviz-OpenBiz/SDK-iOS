//
//  EZDeviceCloudServiceInfo.h
//  EzvizOpenSDK
//
//  Created by JuneCheng on 2022/1/4.
//  Copyright © 2022 Hikvision. All rights reserved.
//

#import <Foundation/Foundation.h>
@class EZCloudServicePackageInfo;

NS_ASSUME_NONNULL_BEGIN

/// 云存储设备通道套餐信息
@interface EZDeviceCloudServiceInfo : NSObject

/// 设备所属用户用户名
@property (nonatomic, copy) NSString *ownerId;
/// 设备序列号
@property (nonatomic, copy) NSString *serial;
/// 通道号
@property (nonatomic, assign) NSInteger channelNo;
/// 设备图片url
@property (nonatomic, copy) NSString *devicePicUrl;
/// 存储时长
@property (nonatomic, assign) NSInteger storageTime;
/// 存储时长单位：1-天，2-周，3-月，4-年
@property (nonatomic, assign) NSInteger storageTimeUnit;
/// 云存储服务过期时间
@property (nonatomic, copy) NSString *expireTime;
/// 到期时间： yyyy年MM月dd日 格式
@property (nonatomic, copy) NSString *expireDate;
/// 设备型号
@property (nonatomic, copy) NSString *devModel;
/// 设备名称
@property (nonatomic, copy) NSString *devName;
/// 设备在线状态
@property (nonatomic, assign) NSInteger onlineStatus;
/// 云存储状态 -2不支持 -1未开启 0暂停 1开启 2过期 4指定生效云存储待生效状态
@property (nonatomic, assign) NSInteger status;
/// 当前距离过期的有效天数
@property (nonatomic, assign) NSInteger expireDay;
/// 服务可使用的天数
@property (nonatomic, assign) NSInteger validDay;
/// 创建时间
@property (nonatomic, copy) NSString *createTime;
/// 是否是指定设备
@property (nonatomic, assign) BOOL designateDevice;
/// 是否由当前订阅开通
@property (nonatomic, assign) BOOL subscribe;
/// 是否支持订阅云存储
@property (nonatomic, assign) BOOL supportSubscribe;
/// 是否支持点卡
@property (nonatomic, assign) BOOL supportCard;
/// 是否屏蔽云存储试用 1为屏蔽，其他为未屏蔽
@property (nonatomic, assign) NSInteger openTryCloudShield;
@property (nonatomic, strong) NSArray<EZCloudServicePackageInfo *> *serviceList;///<

@end


@interface EZCloudServicePackageInfo : NSObject

@property (nonatomic, assign) long serviceId;
/// 产品付费类型：1付费 2 试用 3免费
@property (nonatomic, assign) NSInteger productPayType;
/// 存储时长单位：1-天 2-周 3-月 4-年 5-小时
@property (nonatomic, assign) NSInteger storageTimeUnit;
/// 过期时间
@property (nonatomic, copy) NSString *expireTime;
/// 强制绑定状态 1-强制绑定 2-可转移
@property (nonatomic, assign) NSInteger forceBinding;
/// 服务是否立即生效 1-立即生效 2-延迟生效 3-指定日期生效
@property (nonatomic, assign) NSInteger effectImmediately;
/// 可加入套餐设备数
@property (nonatomic, assign) NSInteger canFamilyDeviceNum;
/// 家庭套餐服务ID
@property (nonatomic, assign) long familyServiceId;
/// 云存储使用时长
@property (nonatomic, assign) NSInteger serviceTime;
/// 已加入套餐设备数
@property (nonatomic, assign) NSInteger addFamilyDeviceNum;
/// 产品编号
@property (nonatomic, assign) NSInteger productCode;
/// 购买数量
@property (nonatomic, assign) NSInteger buyNum;
/// 订单号：当前开通服务与订单关联
@property (nonatomic, copy) NSString *businessOrderNo;
/// 云存储使用时长单位：1-天 2-周 3-月 4-年
@property (nonatomic, assign) NSInteger serviceTimeUnit;
/// 存储时长
@property (nonatomic, assign) NSInteger storageTime;
/// 套餐类型，2、家庭套餐， 1 or null为普通套餐
@property (nonatomic, assign) NSInteger serviceType;
/// 生效时间
@property (nonatomic, copy) NSString *effectTime;
/// 状态：1 待使用 2使用中 3已使用
@property (nonatomic, assign) NSInteger status;

@end

NS_ASSUME_NONNULL_END
