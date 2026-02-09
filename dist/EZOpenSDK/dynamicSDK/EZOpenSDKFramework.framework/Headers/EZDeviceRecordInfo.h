//
//  EZDeviceRecordInfo.h
//  EZPlay
//
//  Created by JuneCheng on 2025/12/26.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// 设备录像信息类
@interface EZDeviceRecordInfo : NSObject

/// 设备SD卡录像列表
@property (nonatomic, strong) NSArray *deviceRecordFileList;

/// 是否还有更多数据
@property (nonatomic, assign) BOOL hasMore;

/// hasMore为true时，该参数值为下一个录像文件的开始时间。如需分页查询，该参数值可作为下一页录像文件查询的开始时间。
@property (nonatomic, strong) NSDate *nextFileTime;

/// 该录像文件是否来自关联的nvr
@property (nonatomic, assign) BOOL fromNvr;

/// fromNvr为true，则返回关联NVR设备序列号，否则返回入参填的设备序列号。
@property (nonatomic, copy) NSString *deviceSerial;

@end

NS_ASSUME_NONNULL_END
