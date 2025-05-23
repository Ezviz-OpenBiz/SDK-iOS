//
//  ERTCWBManager.h
//  ERTC
//
//  Created by wangjinlong23 on 2023/8/9.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ERTCWBManagerDelegate<NSObject>
@optional
- (void)onWBError:(NSString *)msg code:(NSInteger)code;
- (void)onWBJoinRoomSuccess;
- (void)onWBRemoteUserJoinRoom:(NSString *)userId;
- (void)onWBRemoteUserLeaveRoom:(NSString *)userId;
@end

@interface ERTCWBManager : NSObject
@property (nonatomic, weak) id<ERTCWBManagerDelegate> delegate;
//@property (nonatomic, assign) int lineId;//线路 id 1:外网 2：内网
/**
 获取单利
 */
+ (instancetype)sharedInstance;

/**
 释放白板资源
 */
+ (void)destroyWB;
/**
 加入白板房间
 @param userId 用户 id
 @param roomId 房间ID
 */
+ (void)joinWhiteBoardRoom:(NSString *)userId roomId:(NSString *)roomId;

/**
 离开白板房间
 */
+(void)leaveWhiteBoardRoom;

/**
 网络切换
 */
+ (void)setNetworkChange:(int)state;

@end

NS_ASSUME_NONNULL_END
