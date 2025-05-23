//
//  ERTC_Replay_Kit.h
//  ERTC
//
//  Created by Harper Kan on 2022/3/3.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef enum : NSUInteger {
    ERTCReplayKitStateUnconnected,
    ERTCReplayKitStateConnecting,
    ERTCReplayKitStateConnected,
    ERTCReplayKitStateStopped,
} ERTCReplayKitState;


@interface ERTCReplayKit : NSObject
+ (ERTCReplayKit *)sharedManager;
@property (nonatomic, assign, readonly) ERTCReplayKitState state;
@property (nonatomic, assign) int lineID;//线路ID 1:外网 2:内网
- (void)setup;
- (void)finish;
- (void)sendVideoBuffer:(CMSampleBufferRef)sampleBuffer;
@end

NS_ASSUME_NONNULL_END
