//
//  FIAgoraSocketManager.h
//  FIAgoraVideo
//
//  Created by flagadmin on 2020/5/7.
//  Copyright © 2020 flagadmin. All rights reserved.
//

#import <ReplayKit/ReplayKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef enum : NSUInteger {
    EZSampleHandleManagerStateUnconnected,
    EZSampleHandleManagerStateConnecting,
    EZSampleHandleManagerStateConnected,
    EZSampleHandleManagerStateStopped,
} EZSampleHandleManagerState;


@interface EZRTCSampleHandleManager : NSObject
+ (EZRTCSampleHandleManager *)sharedManager;
@property (nonatomic, assign, readonly) EZSampleHandleManagerState state;
- (void)setup;
- (void)finish;
- (void)sendVideoBuffer:(CMSampleBufferRef)sampleBuffer;

@end

NS_ASSUME_NONNULL_END
