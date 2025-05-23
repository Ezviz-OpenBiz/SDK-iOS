//
//  ERTCStatistics.h
//  ERTC
//
//  Created by wangjinlong23 on 2022/4/7.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ERTCStatistics : NSObject

@end

///本地视频实时数据
@interface ERTCLocalVideoStatistics : NSObject

@property (nonatomic, assign) int32_t videoSentBitrate; //视频传输码率(上行)
@property (nonatomic, assign) int32_t videoSentFrameRate; //帧率大小
@property (nonatomic, assign) int32_t videoPacketLossRate; //视频丢包率
@property (nonatomic, assign) int32_t videoStreamType; //流类型
@property (nonatomic, assign) int width;//视频宽
@property (nonatomic,assign) int heigth;//视频高
@property (nonatomic, assign) int32_t videoPacketCount;//发视频总包数
@property (nonatomic, assign) int32_t videoCompensateLossRate;//补偿后丢包率

@end

///本地音频实时数据
@interface ERTCLocalAudioStatistics : NSObject

@property (nonatomic, assign) int32_t audioSentBitrate;//音频传输码率
@property (nonatomic, assign) int32_t audioPacketLossRate;//音频丢包率
@property (nonatomic, assign) int32_t audioPacketCount;//发音频总包数

@end

///远端视频实时数据
@interface ERTCRemoteVideoStatistics : NSObject

@property (nonatomic, copy) NSString *userId; //远端视频clientId
@property (nonatomic, assign) int32_t videoReceivedBitrate;//远端视频传输码率（下行）
@property (nonatomic, assign) int32_t videoReceivedFrameRate;//远端帧率大小
@property (nonatomic, assign) int32_t videoPacketLossRate;//远端视频丢包率(下行)
@property (nonatomic, assign) int32_t videoTotalFrozenTime;//远端视频总的卡顿时长
@property (nonatomic, assign) int32_t videoFrozenRate; //远端视频卡顿比
@property (nonatomic, assign) int32_t streamType; //远端流类型
@property (nonatomic, assign) int width;//视频宽
@property (nonatomic,assign) int heigth;//视频高
@property (nonatomic, assign) int32_t videoPacketCount;//接收视频总包数
@property (nonatomic, assign) int32_t videoUncompensateLoss;//视频补偿前丢包率（％）

@end

///远端音频实时数据
@interface ERTCRemoteAudioStatistics : NSObject

@property (nonatomic, copy) NSString *userId; //远端音频clientId
@property (nonatomic, assign) int32_t audioReceivedBitrate;//远端音频传输码率（下行）
@property (nonatomic, assign) int32_t audioPacketLossRate;//远端音频丢包率(下行)
@property (nonatomic, assign) int32_t audioTotalFrozenTime;//远端音频总的卡顿时长
@property (nonatomic, assign) int32_t audioFrozenRate; //远端音频卡顿比
@property (nonatomic, assign) int32_t audioPacketCount;//接收音频总包数
@property (nonatomic, assign) int32_t audioPlcPacketCount;//音频帧补偿数量
@property (nonatomic, assign) int32_t audioUncompensateLoss;//音频补偿前丢包率（％）
@property (nonatomic, assign) int32_t audioTotalTime;//播放音频总时间
@end

NS_ASSUME_NONNULL_END
