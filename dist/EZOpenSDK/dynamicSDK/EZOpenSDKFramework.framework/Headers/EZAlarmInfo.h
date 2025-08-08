//
//  EZAlarmInfo.h
//  EzvizOpenSDK
//
//  Created by DeJohn Dong on 15/9/16.
//  Copyright (c) 2015年 Ezviz. All rights reserved.
//

#import <Foundation/Foundation.h>

/// 此类为告警信息对象
@interface EZAlarmInfo : NSObject

/// 告警ID
@property (nonatomic, copy) NSString *alarmId;
/// 设备序列号
@property (nonatomic, copy) NSString *deviceSerial;
/// 通道号
@property (nonatomic) NSInteger cameraNo;
/// 告警名称
@property (nonatomic, copy) NSString *alarmName;
/// 告警图片
@property (nonatomic, copy) NSString *alarmPicUrl;
/// 告警开始时间
@property (nonatomic, strong) NSDate *alarmStartTime;
/// 告警类型
@property (nonatomic) NSInteger alarmType;
/// 是否加密
//@property (nonatomic) BOOL isEncrypt;


/// 告警图片加密信息 crypt 0-不确定 1-设备加密 2-平台加密
/// 如果是2，表明是平台加密的图片，请使用下面的checksum作为解密秘钥解密图片
/// 如果是1，表明是设备加密的图片，请使用设备的验证码作为解密秘钥解密图片
/// 如果是0，表明未知的加密信息，请通过上面报警图片URL（alarmPicUrl）中的 isEncrypted 字段，判断图片是 0：未加密 1：设备加密
/// 报警图片的URL示例：
/// https://whpic.ys7.com:8009/HIK_1447836214_458BEBDAE4AB6a6f_525400286893421023815?isEncrypted=1&isCloudStored=0
/// https://www.ys7.com:9090/api/cloud?method=download&fid=5ed92258-8e0f-11e5-8000-c19249a52dcf&deviceSerialNo=504242549&isEncrypted=0&isCloudStored=1
@property (nonatomic) NSInteger crypt;
/// 告警图片平台加密时的密钥
@property (nonatomic, copy) NSString *checksum;
/// 是否已读
@property (nonatomic) BOOL isRead;
/// 存储类型，0-无存储，1-萤石，2-百度，4-sd卡存储，5-萤石和sd卡，6-百度和sd卡
@property (nonatomic) NSInteger recState;
/// 告警录像结束时间时间延后偏移量，通过alarmStartTime加上延后偏移量获得告警录像的具体结束时间
@property (nonatomic) NSInteger delayTime;
/// 告警录像开始时间提前偏移量，通过alarmStartTime减去提前偏移量获得告警录像的具体开始时间
@property (nonatomic) NSInteger preTime;
/// 设备名称
@property (nonatomic, copy) NSString *deviceName;
/// 设备大类
@property (nonatomic, copy) NSString *category;

/// 4530 扩展字段
@property (nonatomic, copy) NSString *customerType;
/// 4530 扩展字段
@property (nonatomic, copy) NSString *customerInfo;

@end
