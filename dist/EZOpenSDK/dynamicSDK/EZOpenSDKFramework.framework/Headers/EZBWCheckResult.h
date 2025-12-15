//
//  EZBWCheckResult.h
//  EZPlay
//
//  Created by JuneCheng on 2025/11/21.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface EZBWCheckResult : NSObject

/// 设备序列号
@property (nonatomic, copy) NSString *deviceSerial;
/// 设备通道号
@property (nonatomic, assign) NSInteger cameraNo;
/// IP运营商
@property (nonatomic, copy) NSString *isp;
/// IP地址，如果有传设备序列号，返回的是设备机房的IP地址，没有传的话返回网关IP地址
@property (nonatomic, copy) NSString *exIp;
/// 带宽检测类型 1：客户端上行 2：客户端下行 3：客户端上行 & 客户端下行
@property (nonatomic, assign) NSInteger checkType;
/// 下载速度，单位：Mbps
@property (nonatomic, assign) float downloadSpeed;
/// 上传速度，单位：Mbps
@property (nonatomic, assign) float uploadSpeed;
/// 时延，单位：ms
@property (nonatomic, assign) NSInteger latency;
/// 丢包率，单位：%
@property (nonatomic, assign) NSInteger loss;
/**
 * 检测结果
 * 0-成功
 * 1-通用错误
 * 2-无效参数
 * 3-无效的URL请求信息
 * 4-内存不足
 * 5-ECDH-MasterKey生成失败
 * 6-ECDH-Sessionkey生成失败
 * 7-ECDH加密失败
 * 8-ECDH解密失败
 * 9-请求服务公钥为空
 * 10-达到并发请求数上限
 * 11-连接VTM服务超时
 * 12-请求VTM服务信令响应超时
 * 13-接收数据长度异常
 * 14-响应数据JSON解析失败
 * 15-自身的ecdh的公私钥对不存在
 * 16-连接BWC服务超时
 * 17-请求BWC服务信令响应超时
 * 1001-服务资源满，需要排队等待
 * 1002-服务无带宽资源
 * 1003-服务内部错误
 * 1004-客户端信令异常
 * 1200-请求内容异常（URL异常）
 * 1201-请求URL过期
 * 1202-服务ECDH解密失败
 * 1203-服务ECDH加密失败
 * 1503-VTM服务中无可用的BWC带宽检测服务
 * 1504-VTM服务中的BWC带宽检测服务负载满
 */
@property (nonatomic, assign) NSInteger result;
/// 检测时间
@property (nonatomic, copy) NSString *checkTime;
/// 网络名称 空值，需开发者自己设置
@property (nonatomic, copy) NSString *networkName;

- (instancetype)initWithDeviceSerial:(NSString *)deviceSerial
                            cameraNo:(NSInteger)cameraNo
                           checkType:(NSInteger)checkType
                                exIp:(NSString *)exIp
                                 isp:(NSString *)isp;

@end

NS_ASSUME_NONNULL_END
