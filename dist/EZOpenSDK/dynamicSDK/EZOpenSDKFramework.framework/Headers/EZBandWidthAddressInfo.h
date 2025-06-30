//
//  EZBandWidthAddressInfo.h
//  EZPlay
//
//  Created by JuneCheng on 2025/6/4.
//

#import <Foundation/Foundation.h>

/// 此类为客户端/设备端带宽检测地址对象
@interface EZBandWidthAddressInfo : NSObject

/// 地址id
@property (nonatomic, copy) NSString *addressId;
/// 网络检测地址
@property (nonatomic, copy) NSString *url;
/// ecdh加密公钥
@property (nonatomic, copy) NSString *publicKey;
/// ecdh加密版本
@property (nonatomic, assign) NSInteger version;
/// 地址过期时间
@property (nonatomic, copy) NSString *expireTime;

@end
