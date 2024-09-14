//
//  EZDeviceRecordFile.h
//  EzvizOpenSDK
//
//  Created by DeJohn Dong on 15/9/17.
//  Copyright (c) 2015年 Ezviz. All rights reserved.
//

#import <Foundation/Foundation.h>

/// 此类为设备录像文件信息（包含SD卡、后端关联设备的录像）
@interface EZDeviceRecordFile : NSObject<NSMutableCopying>

/// 设备录像文件的开始时间
@property (nonatomic, strong) NSDate *startTime;
/// 设备录像文件的结束时间
@property (nonatomic, strong) NSDate *stopTime;
/// 文件类型 -2:UNKNOW -1:ALLEVENT 0:ALARM 1:TIMING 2:IO 3:CMR 4:event 5:all
@property (nonatomic, assign) int type;
@property (nonatomic, copy) NSString *channelType;


@property (nonatomic, assign) int seq;
@property (nonatomic, strong) NSData *imageData;///< 

@end
