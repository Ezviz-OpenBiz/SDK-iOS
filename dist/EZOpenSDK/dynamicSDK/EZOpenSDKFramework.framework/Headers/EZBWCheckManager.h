//
//  EZBWCheckManager.h
//  EZPlay
//
//  Created by JuneCheng on 2025/11/21.
//

#import <Foundation/Foundation.h>
#import "EZConstants.h"
#import "EZBWCheckResult.h"

NS_ASSUME_NONNULL_BEGIN

@interface EZBWCheckManager : NSObject

+ (instancetype)sharedInstance;

/**
 * 开始带宽检测
 *
 * @param bwCheckType 带宽检测类型，EZBWCheckType中列举的类型进行任意组合。
 *      EZBWCheckClientUpward：只进行客户端上行检测
 *      EZBWCheckClientDownward：只进行客户端下行检测
 *      EZBWCheckClientUpward | EZBWCheckClientDownward：串行进行客户端上行和客户端下行检测，耗时为expireTime*2
 * @param deviceSerial  设备序列号，可选。设置后检测客户端到设备机房的带宽
 * @param cameraNo      通道号，默认1，可选。设置后检测客户端到设备机房的带宽
 * @param checkTime     最大带宽测试时长、取值区间【15s~30s】
 * @param bwCheckToken  带宽检测token，必填
 * @param completion      带宽检测结果回调
 */
- (void)startBWCheck:(EZBWCheckType)bwCheckType
        deviceSerial:(NSString *)deviceSerial
            cameraNo:(NSInteger)cameraNo
           checkTime:(NSInteger)checkTime
        bwCheckToken:(NSString *)bwCheckToken
          completion:(void (^)(EZBWCheckResult *result, NSError * __nullable error))completion;

/**
 * 停止带宽检测
 */
- (void)stopBWCheck;

@end

NS_ASSUME_NONNULL_END
