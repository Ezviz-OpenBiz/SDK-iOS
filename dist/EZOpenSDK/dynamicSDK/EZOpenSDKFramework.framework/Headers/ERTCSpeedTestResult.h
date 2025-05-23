//
//  ERTCSpeedTestResult.h
//  ERTC
//
//  Created by wangjinlong23 on 2022/4/11.
//

#import <Foundation/Foundation.h>
#import "ERTCDef.h"

NS_ASSUME_NONNULL_BEGIN

@interface ERTCSpeedTestResult : NSObject

///测试是否成功
@property (nonatomic, assign) BOOL success;
///网络质量
@property (nonatomic, assign) ERTCNetworkQuality quality;
///上行丢包率，取值范围是 [0 - 100]，例如 30% 表示每向服务器发送 10 个数据包可能会在中途丢失 3 个
@property (nonatomic, assign) int32_t upLostRate;
///下行丢包率，取值范围是 [0 - 100]，例如 20% 表示每从服务器收取 10 个数据包可能会在中途丢失 2 个
@property (nonatomic, assign) int32_t downLostRate;
///延迟（毫秒），指当前设备到 服务器的一次网络往返时间，该值越小越好，正常数值范围是10ms - 100ms
@property (nonatomic, assign) int32_t rtt;
///上行带宽（kbps，-1：无效值）。
@property (nonatomic, assign) int availableUpBandwidth;
///下行带宽（kbps，-1：无效值)
@property (nonatomic, assign) int availableDownBandwidth;
///流媒体服务器连接情况
@property (nonatomic, assign) int stsConnect;
@end

NS_ASSUME_NONNULL_END
