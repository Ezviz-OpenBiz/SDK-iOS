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
@property (nonatomic, assign) int32_t m_iRoomId; /**<必填    需要加入房间号 */
@property (nonatomic, assign) int32_t m_uClientId; /**< 必填    加入方clientId */
@property (nonatomic, strong) NSString *m_szCustomId;  /**< 选择    加入方自定义Id */
@property (nonatomic, strong) NSString *m_szPassword;  /**< 选择     房间密码 */
@property (nonatomic, assign) int32_t m_iCltType; /**< 必填    客户端类型 */
@property (nonatomic, strong) NSString *m_szVcAddr;//必填    视频会议必填 会控服务地址
@property (nonatomic, assign) int32_t m_iVcPort;//必填    视频会议必填 会控服务端k口
@property (nonatomic, strong) NSString *m_szStsAddr; /**< 必填    转发服务地址 */
@property (nonatomic, assign) int32_t m_iStsPort; /**< 必填    转发服务端口 */
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
@property (nonatomic, assign) int8_t upNetState;//网络状态
@property (nonatomic, assign) int8_t downNetState;//网络状态

@end


@interface EZRTCParticipantVolume : NSObject
@property (nonatomic, assign) uint32_t m_uClientId;
@property (nonatomic, strong) NSString *m_sCustomId;
@property (nonatomic, assign) uint8_t m_sVolume;    //音量强度0-10 10为最强 0为最弱
@end


@interface EZRTCStatistic : NSObject
@property (nonatomic, assign) int32_t type;//0：子表 1：主表
@property (nonatomic, strong) NSDictionary *statisticInfo;
@end

///本地的音视频统计
@interface EZRTCLocalStatistics : NSObject
///视频指标参数
@property (nonatomic, assign) uint32_t videoSentBitrate; //视频传输码率(上行)
@property (nonatomic, assign) uint32_t videoSentFrameRate; //帧率大小
@property (nonatomic, assign) uint16_t videoPacketLossRate; //视频丢包率
@property (nonatomic, assign) uint16_t videoStreamType; //流类型
///音频指标参数
@property (nonatomic, assign) uint32_t audioSentBitrate;//音频传输码率
@property (nonatomic, assign) uint16_t audioPacketLossRate;//音频丢包率
@end

///远端的音视频统计
@interface  EZRTCRemoteStatistics : NSObject
///视频指标参数
@property (nonatomic, assign) uint32_t videoClientId; //远端视频clientId
@property (nonatomic, assign) uint32_t videoReceivedBitrate;//远端视频传输码率（下行）
@property (nonatomic, assign) uint32_t videoReceivedFrameRate;//远端帧率大小
@property (nonatomic, assign) uint16_t videoPacketLossRate;//远端视频丢包率(下行)
@property (nonatomic, assign) uint16_t videoTotalFrozenTime;//远端视频总的卡顿时长
@property (nonatomic, assign) uint16_t videoFrozenRate; //远端视频卡顿比
@property (nonatomic, assign) uint16_t streamType; //远端流类型
///音频指标参数
@property (nonatomic, assign) uint32_t audioClientId; //远端音频clientId
@property (nonatomic, assign) uint32_t audioReceivedBitrate;//远端音频传输码率（下行）
@property (nonatomic, assign) uint16_t audioPacketLossRate;//远端音频丢包率(下行)
@property (nonatomic, assign) uint16_t audioTotalFrozenTime;//远端音频总的卡顿时长
@property (nonatomic, assign) uint16_t audioFrozenRate; //远端音频卡顿比

@end

@interface EZRTCVideoSize : NSObject

@property (nonatomic, assign) int width;//宽
@property (nonatomic, assign) int height;//高

@end

extern int32_t const EZBAVMessageRoomCreated;
extern int32_t const EZBAVMessagePeerEnteredRoom;
extern int32_t const EZBAVMessagePeerLeaveRoom;
extern int32_t const EZBAVMessageStartInputData;
//extern int32_t const EZBAVMessageOtherDisconnect;
extern int32_t const EZBAVMessageTransferData;
//extern int32_t const EZBAVMessageClientInfo;//其他与会客户端信息
extern int32_t const EZBAVMessageClientVolume;//其他与会客户端音量
extern int32_t const EZBAVMessageClientAudioAvailable;
extern int32_t const EZBAVMessageClientVideoAvailable;
extern int32_t const EZBAVMessageNetworkQuality;
extern int32_t const EZBAVMessageClientShareAvailable;
extern int32_t const EZBAVMessageJoinRoomOK;
extern int32_t const EZBAVMessageForcedQuit;
extern int32_t const EZBAVMessageStatistic;

extern int32_t const EZBAVForcedQuitReasonRepeatJoin;//已在其他地方加入房间
extern int32_t const EZBAVForcedQuitReasonMovedOut;//被管理员移出房间
extern int32_t const EZBAVForcedQuitReasonRoomDissolved;//房间解散

extern int32_t const  EZBAVMessageLocalVideoStats;//统计本地视频实时数据
extern int32_t const  EZBAVMessageLocalAudioStats;//统计本地音频实时数据
extern int32_t const  EZBAVMessageRemoteVideoStats;//统计远端视频实时数据
extern int32_t const  EZBAVMessageRemoteAudioStats;//统计远端音频实时数据



typedef void(^EZAudioOpenResultBlock)(NSInteger ret);
