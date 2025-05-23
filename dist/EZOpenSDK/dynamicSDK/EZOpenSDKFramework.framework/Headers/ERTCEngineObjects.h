//
//  ERTCEngineObjects.h
//  ERTC
//
//  Created by wangjinlong23 on 2024/5/8.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ERTCEngineObjects : NSObject

@end


#pragma mark 订阅权限
@interface ERTCSubscribePermission : NSObject
///用户id
@property (nonatomic, copy) NSString *userId;
///视频流权限 1：禁止
@property (nonatomic, assign) int32_t videoStream;
///音频流权限 1：禁止
@property (nonatomic, assign) int32_t audioStream;
///音频流权限 1：禁止
@property (nonatomic, assign) int32_t screenStream;

@end

NS_ASSUME_NONNULL_END
