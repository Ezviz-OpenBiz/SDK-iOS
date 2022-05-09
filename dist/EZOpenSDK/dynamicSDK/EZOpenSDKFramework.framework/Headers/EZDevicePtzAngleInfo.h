//
//  EZDevicePtzAngleInfo.h
//  EzvizOpenSDK
//
//  Created by JuneCheng on 2022/4/27.
//  Copyright © 2022 Hikvision. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface EZDevicePtzAngleInfo : NSObject

/** 水平方向起点角度 */
@property (readonly) NSInteger horizontalStartAngle;

/** 水平方向终点角度 */
@property (readonly) NSInteger horizontalEndAngle;

/** 水平方向当前角度 */
@property (readonly) NSInteger horizontalCurrentAngle;

/** 垂直方向起点角度 */
@property (readonly) NSInteger verticalStartAngle;

/** 垂直方向终点角度 */
@property (readonly) NSInteger verticalEndAngle;

/** 垂直方向当前角度 */
@property (readonly) NSInteger verticalCurrentAngle;

/** 方向 */
@property (readonly) NSInteger orientation;

/** 版本号 */
@property (readonly) NSInteger ptzCfgVersion;

/** 初始化 */
- (instancetype)initWithType:(NSInteger)type data:(NSData *)data;

- (float)horCurAngPercent;
- (float)verCurAngPercent;

@end

NS_ASSUME_NONNULL_END
