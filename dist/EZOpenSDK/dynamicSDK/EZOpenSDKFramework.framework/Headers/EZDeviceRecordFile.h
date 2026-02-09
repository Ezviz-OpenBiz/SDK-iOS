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
/// 文件类型 -2:UNKNOW-未知 -1:ALLEVENT-所有事件 0:ALARM-报警录像 1:TIMING-定时录像 2:IO-IO外设触发录像 3:CMR-时序录像 4:event-事件录像 5:all-所有类型录像
@property (nonatomic, assign) int type;
@property (nonatomic, copy) NSString *channelType;

/// 当该设备绑定在NVR下时，该值为true，表示该录像是IPC SD卡下直接查询到的；该值为false，表示该录像是NVR通道下查询到的；
/// 当该设备未绑定NVR时，该值无意义
@property (nonatomic, assign) BOOL isIPCRecordDirectQuery;

@property (nonatomic, assign) int seq;
@property (nonatomic, strong) NSData *imageData;///< 

@end
