//
//  EZBAVParam.h
//  EZBAVClient
//
//  Created by kanhaiping on 2018/6/27.
//  Copyright © 2018年 hikvision. All rights reserved.
//

#import <Foundation/Foundation.h>


/*
 typedef struct SBavDevInfo
 {
     YS_INT8            m_szDevSerial[STREAM_DEV_SERIAL_LEN + 1];                //必填    设备序列号
     YS_UINT32        m_sChannel;                                                //必填    通道号
     YS_INT16        m_sDevStreamType;                                        //必填    设备主子码类型
     YS_INT8            m_szAuthToken[STREAM_TOKEN_LEN + 1];                    //必填    认证token
 }SBavDevInfo;
 */

@interface EZBAVDevInfo : NSObject
@property (nonatomic, strong) NSString *serial; /**< 必填    设备序列号 */
@property (nonatomic, assign) int32_t m_iChannel;//必填    通道号
@property (nonatomic, assign) int32_t m_iDevStreamType;//必填    设备主子码类型
@property (nonatomic, strong) NSString *m_szAuthToken; /**< 必填    认证token */
@end
/*
 typedef struct
 {
     YS_UINT32        m_iRoomId;                                                //必填    需要加入房间号
     YS_UINT32        m_uClientId;                                            //必填    加入方clientId
     YS_INT8            m_szCustomId[CUSTOMID_LEN + 1];                            //选择    加入方自定义Id
     YS_INT8            m_szPassword[STREAM_TOKEN_LEN + 1];                        //必填    房间密码
     YS_UINT8        m_iCltType;                                                //必填    客户端类型
     YS_UINT16        m_iStsPort;                                                //必填    转发服务端口
     YS_INT8            m_szStsAddr[CLIENT_STREAM_SVR_ADDR_LEN + 1];            //必填    转发服务地址
     YS_UINT16        m_iVcPort;                                                //必填    会控服务端口
     YS_INT8            m_szVcAddr[CLIENT_STREAM_SVR_ADDR_LEN + 1];                //必填    会控服务地址
     YS_INT8            m_szFilePath[FLIEPATH + 1];                                //选择  写文件的路径
     YS_INT8            m_szExtensionParas[CLIENT_STREAM_EXTENSION_LEN + 1];    //选择    扩展字段信息
 }EZConferenceParam;
 */
@interface EZRTCJoinParam : NSObject
@property (nonatomic, strong) NSString *m_szAppId;//必填，APPID
@property (nonatomic, strong) NSString *m_szCustomRoomId; //自定义的房间号
@property (nonatomic, assign) int32_t m_iRoomId; /**<必填    需要加入房间号 */
@property (nonatomic, assign) int32_t m_uClientId; /**< 必填    加入方clientId */
@property (nonatomic, strong) NSString *m_szCustomId;  /**< 选择    加入方自定义Id */
@property (nonatomic, assign) int32_t m_iAuthType; /**< 必填    认证方式 */
@property (nonatomic, strong) NSString *m_szPassword;  /**< 选择     房间密码 */
@property (nonatomic, assign) int32_t m_iCltType; /**< 必填    客户端类型 */
@property (nonatomic, strong) NSString *m_szVcAddr;//必填    视频会议必填 会控服务地址
@property (nonatomic, assign) int32_t m_iVcPort;//必填    视频会议必填 会控服务端k口
@property (nonatomic, strong) NSString *m_szStsAddr; /**< 必填    转发服务地址 */
@property (nonatomic, assign) int32_t m_iStsPort; /**< 必填    转发服务端口 */
@property (nonatomic, assign) int32_t m_iPublicKeyVersion;/**< 选择  信令版本与信令公钥一起填写 */
@property (nonatomic, strong) NSData *m_szPublicKey; /**<选择  信令公钥base64 */
@property (nonatomic, strong) NSString *m_szExtensionParas; /**< 选择    扩展字段信息 */

@end


@interface EZBAVParam : NSObject

@property (nonatomic, assign) int32_t m_iCltRole; /**< 必填    0 发起 1 接受 发起端填写0 接受端填写1 拒绝为2 */
@property (nonatomic, assign) int32_t m_iStreamType;/**< 必选    0 音视频 1 对讲 2 会议*/
//@property (nonatomic, assign) int32_t m_szIsNpq;/**< 选择  0 不走NPQ，走TCP 1 是NPQ，走UDP */
@property (nonatomic, assign) int32_t m_iCltType; /**< 必填    客户端类型 */

@property (nonatomic, strong) NSString *m_szVcAddr;//必填    视频会议必填 会控服务地址
@property (nonatomic, assign) int32_t m_iVcPort;//必填    视频会议必填 会控服务端k口
@property (nonatomic, strong) NSString *m_szStsAddr; /**< 必填    转发服务地址 */
@property (nonatomic, assign) int32_t m_iStsPort; /**< 必填    转发服务端口 */

@property (nonatomic, assign) int32_t m_iRoomId; /**< 选择    需要加入房间号，只有接受端需要填写 */
@property (nonatomic, assign) int32_t m_iClientId; //选填  发起or加入者的id
@property (nonatomic, strong) NSString *m_szSelfId;  /**< 必填  标识Id */
@property (nonatomic, assign) int32_t m_iReason; /**< 选择  原因 拒接接听101 无人接听102 */

//@property (nonatomic, assign) int32_t m_iMaxBitrate;/**< 必填    码率变化范围的最大值 */
//
//@property (nonatomic, assign) int32_t m_iMinBitrate;/**< 必填    码率变化范围的最小值 */

//@property (nonatomic, assign) int32_t m_iType;/**< 选择  参考BAV_QOS_TYPE */
//
//@property (nonatomic, assign) int32_t m_iVideo;/**< 选择  是否开启视频Qos 1 开启 0 不开启 */
//
//@property (nonatomic, assign) int32_t m_iAudio;/**< 选择  是否开启音频Qos 1 开启 0 不开启 */

@property (nonatomic, assign) int32_t m_iAuthType; /**< 必填    认证方式 */
@property (nonatomic, strong) NSString *m_szAuthToken; /**< 必填    认证token */



@property (nonatomic, assign) int32_t m_iOtherCltType; /**< 选择    只有对端是手表端需填写 */
@property (nonatomic, strong) NSString *m_szOterId; /**< 选择    只有对端是手表端需填写 */
@property (nonatomic, assign) int32_t m_iChannel;//选填  三方音视频时，IPC设备需要填写
@property (nonatomic, assign) int32_t m_iDevStreamType;//选填  设备主子码流

@property (nonatomic, strong) NSString *m_szExtensionParas; /**< 选择    扩展字段信息 */


@end



/// 与会者信息
@interface EZRTCParticipantsInfo : NSObject
@property (nonatomic, assign) uint32_t m_uRoomId;
@property (nonatomic, assign) uint32_t m_uClientId;
@property (nonatomic, strong) NSString *m_sCustomId;
@property (nonatomic, strong) NSString *m_szUserName;
@property (nonatomic, assign) uint8_t m_iCltType; //用以区分是否是设备 111:设备 
@property (nonatomic, assign) int8_t audioState;// 声音启用状态 0-关闭 1-启用
@property (nonatomic, assign) int8_t videoState;// 视频启用状态 0-关闭 1-主流 5-主子流
@property (nonatomic, assign) int8_t shareState;// 屏幕共享启用状态 0-关闭 1-启用
@property (nonatomic, assign) int8_t upNetState;//网络状态 0:网络状态未知  1:网络非常好 2:网络好 3:网络一般 4:网络差 5:网络非常差 6:网络不可用
@property (nonatomic, assign) int8_t downNetState;//网络状态 0:网络状态未知  1:网络非常好 2:网络好 3:网络一般 4:网络差 5:网络非常差 6:网络不可用

@end



@interface EZRTCParticipantVolume : NSObject
@property (nonatomic, assign) uint32_t m_uClientId;
@property (nonatomic, strong) NSString *m_sCustomId;
@property (nonatomic, assign) uint8_t m_sVolume;    //音量强度0-10 10为最强 0为最弱
@end

@interface EZRTCParticipantVolumeInfo : NSObject
@property (nonatomic, strong) NSArray<EZRTCParticipantVolume *> *clientVolumeList;
@property (nonatomic, assign) uint8_t totalVolume;    //音量强度0-10 10为最强 0为最弱
@end

@interface EZRTCParticipantCustomMsg : NSObject
@property (nonatomic, strong) NSData *data;
@property (nonatomic, assign) uint32_t m_uClientId;
@end


@interface EZRTCStatistic : NSObject
@property (nonatomic, assign) int32_t type;//0：子表 1：主表
@property (nonatomic, strong) NSDictionary *statisticInfo;
@end

///本地的音视频统计
@interface EZRTCLocalStatistics : NSObject
///视频指标参数
@property (nonatomic, assign) int32_t videoSentBitrate; //视频传输码率(上行)
@property (nonatomic, assign) int32_t videoSentFrameRate; //帧率大小
@property (nonatomic, assign) int32_t videoPacketLossRate; //视频丢包率
@property (nonatomic, assign) int32_t videoStreamType; //流类型
@property (nonatomic, assign) int32_t videoPacketCount;//发视频总包数
@property (nonatomic, assign) int32_t videoCompensateLossRate;//补偿后丢包率,单位%
///音频指标参数
@property (nonatomic, assign) int32_t audioSentBitrate;//音频传输码率
@property (nonatomic, assign) int32_t audioPacketLossRate;//音频丢包率
@property (nonatomic, assign) int32_t audioPacketCount;//发音频总包数
@end

///远端的音视频统计
@interface  EZRTCRemoteStatistics : NSObject
///视频指标参数
@property (nonatomic, assign) int32_t videoClientId; //远端视频clientId
@property (nonatomic, assign) int32_t videoReceivedBitrate;//远端视频传输码率（下行）
@property (nonatomic, assign) int32_t videoReceivedFrameRate;//远端帧率大小
@property (nonatomic, assign) int32_t videoPacketLossRate;//远端视频丢包率(下行)
@property (nonatomic, assign) int32_t videoTotalFrozenTime;//远端视频总的卡顿时长
@property (nonatomic, assign) int32_t videoFrozenRate; //远端视频卡顿比
@property (nonatomic, assign) int32_t streamType; //远端流类型
@property (nonatomic, assign) int32_t videoPacketCount;//接收视频总包数
@property (nonatomic, assign) int32_t videoUncompensateLoss;//视频补偿前丢包率（％）
///音频指标参数
@property (nonatomic, assign) int32_t audioClientId; //远端音频clientId
@property (nonatomic, assign) int32_t audioReceivedBitrate;//远端音频传输码率（下行）
@property (nonatomic, assign) int32_t audioPacketLossRate;//远端音频丢包率(下行)
@property (nonatomic, assign) int32_t audioTotalFrozenTime;//远端音频总的卡顿时长
@property (nonatomic, assign) int32_t audioFrozenRate; //远端音频卡顿比
@property (nonatomic, assign) int32_t audioPacketCount;//接收音频总包数
@property (nonatomic, assign) int32_t audioPlcPacketCount;//音频帧补偿数量
@property (nonatomic, assign) int32_t audioUncompensateLoss;//音频补偿前丢包率（％）
@property (nonatomic, assign) int32_t audioTotalTime;//播放音频总时间
@end

///视频大小
@interface EZRTCVideoSize : NSObject

@property (nonatomic, assign) int width;//宽
@property (nonatomic, assign) int height;//高

@end

///网速测试请求参数
@interface EZRTCSpeedTestParams : NSObject

@property (nonatomic, assign) int16_t m_iStsPort;//转发服务端口
@property (nonatomic, strong) NSString *m_szStsAddr;//转发服务地址
@property (nonatomic, assign) int32_t m_iPublicKeyVersion;/**< 选择  信令版本与信令公钥一起填写 */
@property (nonatomic, strong) NSData *m_szPublicKey; /**<选择  信令公钥base64 */
@property (nonatomic, assign) int32_t m_expectedUpBandwidth;//上行带宽
@property (nonatomic, assign) int32_t m_expectedDownBandwidth;//下行带宽
@property (nonatomic,strong) NSString *m_szPassword;//房间密码
@property (nonatomic, assign) int32_t testInterval;//必填  统计间隔（毫秒）,取值范围1000ms~60000ms
@property (nonatomic,strong) NSString *m_szExtensionParas;//扩展字段
@end

///网速测试回调结果
@interface EZRTCSpeedTestResult : NSObject
///测试是否成功
@property (nonatomic, assign) BOOL success;
///网络质量
@property (nonatomic, assign) int8_t quality;
///上行丢包率，取值范围是 [0 - 100]，例如 30% 表示每向服务器发送 10 个数据包可能会在中途丢失 3 个
@property (nonatomic, assign) int32_t upLostRate;
///下行丢包率，取值范围是 [0 - 100]，例如 20% 表示每从服务器收取 10 个数据包可能会在中途丢失 2 个
@property (nonatomic, assign) int32_t downLostRate;
///延迟（毫秒），指当前设备到 服务器的一次网络往返时间，该值越小越好，正常数值范围是10ms - 100ms
@property (nonatomic, assign) int32_t rtt;
///上行带宽（kbps，-1：无效值）。
@property (nonatomic, assign) int availableUpBandwidth;
///下行带宽（kbps，-1：无效值)
@property (nonatomic, assign) int availableDownBandwidth;

@property (nonatomic, assign) int stsConnect;
@end

extern int32_t const EZBAVMessageRoomCreated;
extern int32_t const EZBAVMessagePeerEnteredRoom;
extern int32_t const EZBAVMessagePeerLeaveRoom;
extern int32_t const EZBAVMessageStartInputData;
//extern int32_t const EZBAVMessageOtherDisconnect;
extern int32_t const EZBAVMessageTransferData;
//extern int32_t const EZBAVMessageClientInfo;//其他与会客户端信息
//extern int32_t const EZBAVMessageClientVolume;//其他与会客户端音量
extern int32_t const EZBAVMessageClientAudioAvailable;
extern int32_t const EZBAVMessageClientVideoAvailable;
extern int32_t const EZBAVMessageNetworkQuality;
extern int32_t const EZBAVMessageClientShareAvailable;
extern int32_t const EZBAVMessageJoinRoomOK;
extern int32_t const EZBAVMessageForcedQuit;
//extern int32_t const EZBAVMessageStatistic;
extern int32_t const EZBAVMessageVolumeInfo;//会场的音量，里面包含所有开麦的与会者的音量信息


extern int32_t const EZBAVForcedQuitReasonRepeatJoin;//已在其他地方加入房间
extern int32_t const EZBAVForcedQuitReasonMovedOut;//被管理员移出房间
extern int32_t const EZBAVForcedQuitReasonRoomDissolved;//房间解散
extern int32_t const EZBAVMessageSpeedTestResult;//网络测试
extern int32_t const EZBAVMessageTransparent;//底层上抛的json消息

extern int32_t const EZBAVMessageForcedQuitScreenShare;//（屏幕共享中）被强制关闭屏幕共享

typedef void(^EZAudioOpenResultBlock)(NSInteger ret);

typedef enum : NSUInteger {
    EZSubStreamType_Main = 1,
    EZSubStreamType_Min = 4,
} EZSubStreamType;
