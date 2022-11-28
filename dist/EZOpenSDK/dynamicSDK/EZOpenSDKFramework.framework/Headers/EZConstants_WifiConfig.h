//
//  EZConstants_WifiConfig.h
//  WifiConfig
//
//  Created by JuneCheng on 2022/5/6.
//

#ifndef EZConstants_WifiConfig_h
#define EZConstants_WifiConfig_h

/* 配网方式 */
typedef NS_ENUM(NSInteger, EZWiFiConfigMode) {
    EZWiFiConfigSmart        = 1 << 0,  // smart config
    EZWiFiConfigWave         = 1 << 1,  // 声波配网
};

/* WiFi配置设备状态 */
typedef NS_ENUM(NSInteger, EZWifiConfigStatus) {
    DEVICE_WIFI_CONNECTING = 1,   //设备正在连接WiFi
    DEVICE_WIFI_CONNECTED = 2,    //设备连接WiFi成功  (已废弃 v4.16.0)
    DEVICE_PLATFORM_REGISTED = 3, //设备注册平台成功
    DEVICE_ACCOUNT_BINDED = 4,    //设备已经绑定账户  (已废弃 v4.16.0)
    DEVICE_WIFI_SENT_SUCCESS = 5, //向设备发送WiFi信息成功
    DEVICE_WIFI_SENT_FAILED = 6,  //向设备发送WiFi信息失败
    DEVICE_PLATFORM_REGIST_FAILED = 7, //设备注册平台失败，轮询20次，20次未查询到设备上线视为注册平台失败
};

/* New AP配网设备状态 */
typedef NS_ENUM(NSInteger, EZNewAPConfigStatus) {
    EZNewAPConfigStatusConnectSuccess          = 104,    // 连接成功
    EZNewAPConfigStatusUnknow                  = 105,    // 未知错误
    EZNewAPConfigStatusPasswordError           = 106,    // 密码错误
    EZNewAPConfigStatusNoAPFound               = 201,    // 未找到wifi热点
};

#endif /* EZConstants_WifiConfig_h */
