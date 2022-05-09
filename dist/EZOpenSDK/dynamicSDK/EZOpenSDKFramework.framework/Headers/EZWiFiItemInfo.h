//
//  EZWiFiItemInfo.h
//  EZWiFiConfigSDK
//
//  Created by yuqian on 2020/7/28.
//  Copyright © 2020 com.ezviz. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface EZWiFiItemInfo : NSObject

@property (nonatomic, copy) NSString *ssid;             /*必填,SSID,string*/
@property (nonatomic, assign) NSInteger signalStrength;   /*必填,信号强度,"-100-0",int，数值越大信号越强*/
@property (nonatomic, copy) NSString *securityMode;     /*可选,安全模式: "open,WEP,WPA-personal,WPA2-personal,WPA-WPA2-personal,WPA2-enterprise",string*/

@end

NS_ASSUME_NONNULL_END
