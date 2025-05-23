//
//  ERTCEngine+Service.h
//  ERTC
//
//  Created by Harper Kan on 2021/11/22.
//

#import "ERTC.h"

NS_ASSUME_NONNULL_BEGIN


/// 获取token的Response对象
@interface ERTC_Rsp_Token : NSObject

/// 加入房间的token
@property (nonatomic, strong) NSString *token;

/// token过期时间（单位秒）
@property (nonatomic, assign) long expire;
@end

/// ERTCEngine 的 HTTP Service 相关的 Extension
@interface ERTCEngine (Service)

/// 获取token接口
/// @param userId userId 加入房间时的自己的userId
/// @param roomId 加入发房间ID
/// @param rtctoken 授权Token
/// @param completion 结果
+ (NSURLSessionDataTask *)getTokenWithUserId:(NSString *)userId roomId:(NSString *)roomId rtcToken:(NSString *)rtctoken completion:(void (^)(ERTC_Rsp_Token *tokenInfo, NSError *error))completion;
@end

NS_ASSUME_NONNULL_END
