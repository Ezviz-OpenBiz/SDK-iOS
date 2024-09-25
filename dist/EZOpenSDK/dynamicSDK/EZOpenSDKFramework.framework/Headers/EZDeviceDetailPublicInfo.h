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
@property (nonatomic, strong) NSArray *videoQualityInfos;


/// 是否是设备拥有者 1:设备拥有者 -1:不是设备拥有者，需要鉴权
@property (nonatomic, assign) NSInteger isOwner;
/// 设备局域网信令端口
@property (nonatomic, assign) NSInteger localCmdPort;
/// 码流编码格式  0:无编码 1:HIK264 海康私有编码 2:MPEG2 3:MPEG4 4:MJPEG 5:H265 6:SVAC 256:H264
@property (nonatomic, assign) int videoEncodeType;
/// 视频宽度
@property (nonatomic, assign) NSInteger videoWidth;
/// 视频高度
@property (nonatomic, assign) NSInteger videoHeight;

@end

NS_ASSUME_NONNULL_END
