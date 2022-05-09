//
//  EZConfigTokenInfo.h
//  EZWiFiConfigSDK
//
//  Created by yuqian on 2020/7/30.
//  Copyright © 2020 com.ezviz. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface EZConfigTokenInfo : NSObject

@property (nonatomic, copy) NSString *userId;
@property (nonatomic, copy) NSString *token;
@property (nonatomic, copy) NSString *lbsDomain;

@end

NS_ASSUME_NONNULL_END
