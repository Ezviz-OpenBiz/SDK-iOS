//
//  EZConstants_Auth.h
//  Auth
//
//  Created by JuneCheng on 2022/5/18.
//

#import <Foundation/Foundation.h>

// 萤石开放平台委托方法
@protocol EZAuthSDKDelegate <NSObject>

@optional

/**
 萤石登录是否成功
 
 @param result 是否成功
 */
- (void)ezvizLoginResult:(BOOL)result;

@end

/* 萤石研发的APP */
typedef NS_ENUM(NSInteger, EZAppType) {
    EZEzviz                 = 0,  // 萤石云视频国内版
    EZEzvizInternational    = 1,  // 萤石云视频海外版
    EZHIKConnect            = 2,  // HIK-Connect
};

/* 萤石负责研发的APP */
typedef NS_ENUM(NSInteger, EZAppPageType) {
    EZPageDeviceList        = 0,  // 设备列表页面
    EZPageAlarmList         = 1,  // 告警消息列表页面
};

///需要进行重新登录的通知，该通知触发频率为5年一次，需在SDK初始化监听
extern const NSNotificationName EZNeedReloginNotification;

///错误解决方案KEY
extern NSErrorUserInfoKey const EZErrorSolutionKey;

///错误模块错误码KEY
extern NSErrorUserInfoKey const EZErrorModuleCodeKey;

NS_ASSUME_NONNULL_BEGIN

@interface EZConstants_Auth : NSObject

@end

NS_ASSUME_NONNULL_END
