//
//  EZDeviceDetailPublicInfo.h
//  EZPlay
//
//  Created by JuneCheng on 2024/6/13.
//

#import <Foundation/Foundation.h>
@class EZDeviceDetailInfo;

NS_ASSUME_NONNULL_BEGIN

@interface EZDeviceDetailPublicInfo : NSObject

/// 通道支持的视频质量信息 EZVideoQualityInfo 对象数组
//@property (nonatomic, strong) NSArray *videoQualityInfos;


/// 是否是设备拥有者 1:设备拥有者 -1:不是设备拥有者，需要鉴权
@property (nonatomic, assign) NSInteger isOwner;
/// 设备局域网信令端口
@property (nonatomic, assign) NSInteger localCmdPort;

@end

NS_ASSUME_NONNULL_END
