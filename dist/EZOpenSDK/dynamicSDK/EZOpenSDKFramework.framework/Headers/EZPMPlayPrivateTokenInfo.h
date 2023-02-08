//
//  EZPMPlayPrivateTokenInfo.h
//  EZPlay
//
//  Created by JuneCheng on 2022/11/24.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface EZPMPlayPrivateTokenInfo : NSObject

@property (nonatomic, assign) BOOL enable;///<
@property (nonatomic, copy) NSString *token;///<


- (instancetype)initWithType:(NSInteger)type data:(NSData *)data;

@end

NS_ASSUME_NONNULL_END
