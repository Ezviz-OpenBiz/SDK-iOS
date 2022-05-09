//
//  EZAPDevInfo.h
//  EZWiFiConfigSDK
//
//  Created by yuqian on 2020/7/28.
//  Copyright © 2020 com.ezviz. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface EZAPDevInfo : NSObject

@property (nonatomic, copy) NSString *apVersion;//版本，当前ap版本1.0
@property (nonatomic, copy) NSString *devSubserial;//设备序列号，最大64
@property (nonatomic, copy) NSString *devType;//设备型号，最大64
@property (nonatomic, copy) NSString *devFirmwareversion;//设备固件版本号，最大64
@property (nonatomic, copy) NSString *macAddr;//设备mac地址

@end

NS_ASSUME_NONNULL_END
