//
//  EZOpenSDK.h
//  EZOpenSDK
//
//  Created by JuneCheng on 2022/7/18.
//

#import <Foundation/Foundation.h>
#import "EZConstants.h"
#import "EZConstants_Auth.h"
#import "EZConstants_WifiConfig.h"

@class EZPlayer;
@class EZDeviceInfo;
@class EZAccessToken;
@class EZCameraInfo;
@class EZDeviceVersion;
@class EZUserInfo;
@class EZProbeDeviceInfo;
@class EZDeviceUpgradeStatus;
@class EZLeaveMessage;
@class EZWiFiItemInfo, EZAPDevInfo, EZConfigTokenInfo;

NS_ASSUME_NONNULL_BEGIN

@interface EZOpenSDK : NSObject

#pragma mark - Auth认证相关Api

/**
 *  实例EZOpenSDK接口
 *
 *  @param appKey 传入申请的appKey
 *
 *  @return YES/NO
 */
+ (BOOL)initLibWithAppKey:(NSString *)appKey;

/**
 *  初始化接口，可设置服务器，海外用户使用该初始化方法
 *
 *  @param appKey 传入申请的appKey
 *  @param apiUrl apiUrl地址
 *  @param authUrl auth地址
 *
 *  @return YES/NO
 */
+ (BOOL)initLibWithAppKey:(NSString *)appKey
                      url:(NSString *)apiUrl
                  authUrl:(NSString *)authUrl;

/**
 *  销毁EZOpenSDK接口
 *
 *  @return YES/NO
 */
+ (BOOL)destoryLib;

/**
 *  设置是否打印debug日志,需在初始化sdk之前调用
 *
 *  @param enable 是否打印日志，默认关闭
 *
 *  @return YES/NO
 */
+ (BOOL)setDebugLogEnable:(BOOL)enable;

/**
 *  设置debug日志回调,需在初始化sdk之前调用
 *
 *  @param logCallback 日志回调
 */
+ (void)setDebugLogCallBack:(void(^)(NSString *logStr))logCallback;

/**
 *  打开授权登录中间页面接口
 *
 *  @param block 回调block
*/
+ (void)openLoginPage:(void (^)(EZAccessToken *accessToken))block;

/**
 *  授权登录以后给EZOpenSDK设置accessToken接口
 *
 *  @param accessToken 授权登录获取的accessToken
 */
+ (void)setAccessToken:(NSString *)accessToken;

/**
 *  账户注销接口
 *
 *  @param completion 回调block，error为空表示登出成功
 */
+ (void)logout:(void (^)(NSError *error))completion;


/**
 外部跳转处理方法，适用于iOS9以上，包括iOS9

 @param url 跳转过来的url
 @param options 参数，默认为空，目前未进行处理，预留
 @param delegate 委托
 @return 结果
 */
+ (BOOL)handleOpenUrl:(NSURL *)url options:(NSDictionary *)options delegate:(id<EZOpenSDKDelegate>)delegate;

/**
 *  获取SDK版本号接口
 *
 *  @return 版本号
 */
+ (NSString *)getVersion;

/**
 *  打开云存储中间页
 *
 *  @param deviceSerial 设备序列号
 *  @param channelNo    设备通道号
 */
+ (void)openCloudPage:(NSString *)deviceSerial channelNo:(NSInteger)channelNo;

/**
 *  打开修改密码中间页
 *
 *  @param completion 回调block resultCode为0时表示修改密码成功
 */
+ (void)openChangePasswordPage:(void (^)(NSInteger resultCode))completion;

/**
 是否已经登录

 @return YES：已经登录；NO：未登录
 */
+ (BOOL)isLogin;

/**
 获取当前accessToken

 @return accessToken
 */
+ (NSString *)getAccesstoken;

#pragma mark - 播放器创建Api

/**
 *  根据cameraId构造EZPlayer对象
 *
 *  @param deviceSerial 设备序列号
 *  @param cameraNo     通道号
 *
 *  @return EZPlayer对象
 */
+ (EZPlayer *)createPlayerWithDeviceSerial:(NSString *)deviceSerial
                                  cameraNo:(NSInteger)cameraNo;

/**
 *  根据cameraId构造EZPlayer对象（for 国标）
 *
 *  @param deviceSerial 设备序列号
 *  @param strCameraNo     通道号
 *
 *  @return EZPlayer对象
 */
+ (EZPlayer *)createPlayerWithDeviceSerial:(NSString *)deviceSerial
                               strCameraNo:(NSString *)strCameraNo DEPRECATED_MSG_ATTRIBUTE("use createPlayerWithDeviceSerial:cameraNo: instead");

/**
 *  一个页面存在多个视频使用最小的码流，没有子码流的话还是使用主码流
 *
 *  @param deviceSerial 设备序列号
 *  @param cameraNo     虚拟通道
 *  @param useSubStream   是否使用子码流
 *
 *  @return EZPlayer对象
 */
+ (EZPlayer *)createPlayerWithDeviceSerial:(NSString *)deviceSerial
                                  cameraNo:(NSInteger)cameraNo
                              useSubStream:(BOOL)useSubStream;

/**
 *  根据url构造EZPlayer对象 （主要用来处理视频广场的播放）
 *
 *  @param url 播放url，目前只支持该协议：ysproto://vtm.ys7.com:8554/live?dev=531993276&chn=1&stream=1&cln=1&isp=0&biz=3
 *
 *  @return EZPlayer对象
 */
+ (EZPlayer *)createPlayerWithUrl:(NSString *)url;


/**
 *  释放EZPlayer对象
 *
 *  @param player EZPlayer对象
 *
 *  @return YES/NO
 */
+ (BOOL)releasePlayer:(EZPlayer *)player;

#pragma mark - 取流相关Api

/**
 *  设置是否支持P2P取流，默认是不支持的
 *  P2P取流可以降低转发取流的比例，但是在多人同时观看时对设备端的带宽要求也更高，设备端带宽不够的情况下，影响播放体验
 *  对于可能多人同时观看的场景，建议不支持
 *  对于家用监控类的场景，建议支持P2P
 *
 *  @param enable p2p是否开启
 */
+ (void)enableP2P:(BOOL)enable;

/**
 *  清除取流时的缓存数据
 */
+ (void)clearStreamInfoCache;

/**
 *  是否支持国标
 *  @param enable YES or NO
 */
+ (void)enableNationalStandard:(BOOL)enable;

/**
 *  取流是否使用用户自己Saas服务的token，在`initLibWithAppKey`前调用（此开关打开后，预览、对讲、SD卡录像回放、SD卡录像下载需设置自己的token）
 *  `EZPlayer.setStreamSaasToken`
 *  `EZDeviceRecordDownloadTask.initTaskWithID`
 *
 *  @param enable   是否使用自己Saas服务的token
 */
+ (void)enableStreamWithSaasToken:(BOOL)enable;

/**
 *  获取所有的p2p预连接设备序列号（包括正在进行预操作的以及预操作完成的）
 *  需要在子线程中调用
 *
 *  @return 设备序列号数组
 */
+ (NSArray<NSString *> *)getAllProcessedPreconnectSerials;

/**
 *  获取所有正在排队的p2p预连接设备序列号（指还没有进行预操作的）
 *  需要在子线程中调用
 *
 *  @return 设备序列号数组
 */
+ (NSArray<NSString *> *)getAllToDoPreconnectSerials;

/**
 *  某一设备p2p预连接是否成功
 *
 *  @param deviceSerial 设备序列号
 */
+ (BOOL)isPreConnectionSucceed:(NSString *)deviceSerial;

/**
 *  对某一设备进行p2p预连接操作
 *
 *  @param deviceSerial 设备序列号
 */
+ (void)startP2PPreconnect:(NSString *)deviceSerial;

/**
 *  对某一设备进行p2p预连接清除操作
 *
 *  @param deviceSerial 设备序列号
 */
+ (void)clearP2PPreconnect:(NSString *)deviceSerial;

#pragma mark - 录像查询Api

/**
 *  查询云存储录像信息列表接口
 *
 *  @param deviceSerial 设备序列号
 *  @param cameraNo     通道号
 *  @param beginTime    查询时间范围开始时间
 *  @param endTime      查询时间范围结束时间
 *  @param completion   回调block，正常时返回EZCloudRecordFile的对象数组，错误时返回错误码
 *
 *  @return operation
 */
+ (NSURLSessionDataTask *)searchRecordFileFromCloud:(NSString *)deviceSerial
                                           cameraNo:(NSInteger)cameraNo
                                          beginTime:(NSDate *)beginTime
                                            endTime:(NSDate *)endTime
                                         completion:(void (^)(NSArray *couldRecords, NSError * __nullable error))completion;

/**
 *  查询远程SD卡存储录像信息列表接口
 *
 *  @param deviceSerial 设备序列号
 *  @param cameraNo     通道号
 *  @param beginTime    查询时间范围开始时间
 *  @param endTime      查询时间范围结束时间
 *  @param completion   回调block，正常时返回EZDeviceRecordFile的对象数组，错误时返回错误码
 *
 *  @return operation
 */
+ (NSURLSessionDataTask *)searchRecordFileFromDevice:(NSString *)deviceSerial
                                            cameraNo:(NSInteger)cameraNo
                                           beginTime:(NSDate *)beginTime
                                             endTime:(NSDate *)endTime
                                          completion:(void (^)(NSArray *deviceRecords, NSError * __nullable error))completion;

/**
 *  查询远程SD卡存储录像信息列表接口，同一个录像可以同时是定时录像和事件录像
 *
 *  @param deviceSerial 设备序列号
 *  @param cameraNo     通道号
 *  @param beginTime    查询时间范围开始时间
 *  @param endTime      查询时间范围结束时间
 *  @param videoRecordType      录像类型
 *  @param completion   回调block，正常时返回EZDeviceRecordFile的对象数组，错误时返回错误码
 *
 *  @return operation
 */
+ (NSURLSessionDataTask *)searchRecordFileFromDevice:(NSString *)deviceSerial
                                            cameraNo:(NSInteger)cameraNo
                                           beginTime:(NSDate *)beginTime
                                             endTime:(NSDate *)endTime
                                     videoRecordType:(EZVideoRecordType)videoRecordType
                                          completion:(void (^)(NSArray *deviceRecords, NSError * __nullable error))completion;

/**
 *  查询远程SD卡存储录像信息列表接口（接口支持获取浓缩录像）
 *
 *  @param deviceSerial 设备序列号
 *  @param cameraNo     通道号
 *  @param beginTime    查询时间范围开始时间
 *  @param endTime      查询时间范围结束时间
 *  @param videoRecordTypeEx      录像类型扩展
 *  @param completion   回调block，正常时返回EZDeviceRecordFile的对象数组，错误时返回错误码
 *
 *  @return operation
 */
+ (NSURLSessionDataTask *)searchRecordFileFromDeviceEx:(NSString *)deviceSerial
                                              cameraNo:(NSInteger)cameraNo
                                             beginTime:(NSDate *)beginTime
                                               endTime:(NSDate *)endTime
                                     videoRecordTypeEx:(EZVideoRecordTypeEx)videoRecordTypeEx
                                            completion:(void (^)(NSArray *deviceRecords, NSError * __nullable error))completion;

/**
 *  查询设备SDK云录制录像信息列表接口
 *
 *  @param deviceSerial 设备序列号
 *  @param cameraNo     通道号，传入<=0的值则为默认值
 *  @param beginTime    开始时间，传入nil则为当天00:00:00
 *  @param endTime      结束时间，传入nil则为当天23:59:59
 *  @param spaceId      录像空间
 *  @param completion   回调block records:EzvizRecordFileInfo的数组
 *
 *  @return operation
 */
+ (NSURLSessionDataTask *)searchRecordFileFromSDKCloudRecord:(NSString *)deviceSerial
                                                    cameraNo:(NSInteger)cameraNo
                                                   beginTime:(NSDate *)beginTime
                                                     endTime:(NSDate *)endTime
                                                     spaceId:(NSString *)spaceId
                                                  completion:(void (^)(id records, NSError * __nullable error))completion;

/**
 *  获取指定时间内的所有录像文件
 *
 *  @param deviceSerial 设备序列号
 *  @param cameraNo     通道号，传入<=0的值则为默认值
 *  @param beginTime    开始时间，传入nil则为当天00:00:00
 *  @param endTime      结束时间，传入nil则为当天23:59:59
 *  @param rectype      回放源，0-系统自动选择，1-云存储，2-本地录像，5-sdk。非必选，默认为0，传入负值则为默认值
 *  @param bizType       设备归属业务来源
 *  @param platFormId  平台ID
 *  @param completion   回调block records:EzvizRecordFileInfo的数组
 *
 *  @return operation
 */
+ (NSURLSessionDataTask *)searchRecordFile:(NSString *)deviceSerial
                                  cameraNo:(NSString *)cameraNo
                                 beginTime:(NSDate *)beginTime
                                   endTime:(NSDate *)endTime
                                   recType:(NSInteger)rectype
                                   bizType:(NSString *)bizType
                                platFormId:(NSString *)platFormId
                                completion:(void (^)(id records, NSError * __nullable error))completion;

#pragma mark - 设备相关Api

/**
 *  根据设备序列号和设备验证码添加设备接口
 *
 *  @param deviceSerial 设备序列号
 *  @param verifyCode   设备验证码
 *  @param completion   回调block，error为空时表示添加成功
 *
 *  @return operation
 */
+ (NSURLSessionDataTask *)addDevice:(NSString *)deviceSerial
                         verifyCode:(NSString *)verifyCode
                         completion:(void (^)(NSError * __nullable error))completion;

/**
 *  获取用户所有的设备列表
 *
 *  @param pageIndex  分页当前页码（从0开始）
 *  @param pageSize   分页每页数量（建议20以内）
 *  @param completion 回调block，正常时返回EZDeviceInfo的对象数组和设备总数，错误时返回错误码
 *
 *  @return operation
 */
+ (NSURLSessionDataTask *)getDeviceList:(NSInteger)pageIndex
                               pageSize:(NSInteger)pageSize
                             completion:(void (^)(NSArray *deviceList, NSInteger totalCount, NSError * __nullable error))completion;

/**
 *  获取用户所有的设备列表（包含子设备）
 *
 *  @param pageIndex  分页当前页码（从0开始）
 *  @param pageSize   分页每页数量（建议20以内）
 *  @param completion 回调block，正常时返回EZDeviceInfo的对象数组和设备总数，错误时返回错误码
 *
 *  @return operation
 */
+ (NSURLSessionDataTask *)getDeviceListEx:(NSInteger)pageIndex
                                 pageSize:(NSInteger)pageSize
                               completion:(void (^)(NSArray *deviceList, NSInteger totalCount, NSError * __nullable error))completion;

/**
 *  获取分享给用户的设备列表接口
 *
 *  @param pageIndex  分页当前页码（从0开始）
 *  @param pageSize   分页每页数量（建议20以内）
 *  @param completion 回调block，正常时返回EZDeviceInfo的对象数组和设备总数，错误时返回错误码
 *
 *  @return operation
 */
+ (NSURLSessionDataTask *)getSharedDeviceList:(NSInteger)pageIndex
                                     pageSize:(NSInteger)pageSize
                                   completion:(void (^)(NSArray *deviceList, NSInteger totalCount, NSError * __nullable error))completion;

/**
 *  根据序列号获取设备信息
 *
 *  @param deviceSerial 设备序列号
 *  @param completion 回调block，正常时返回EZDeviceInfo的对象，错误时返回错误码
 *
 *  @return operation
 */
+ (NSURLSessionDataTask *)getDeviceInfo:(NSString *)deviceSerial
                             completion:(void (^)(EZDeviceInfo *deviceInfo, NSError * __nullable error))completion;

/**
 *  根据序列号获取设备信息（包含子设备）
 *
 *  @param deviceSerial 设备序列号
 *  @param completion 回调block，正常时返回EZDeviceInfo的对象，错误时返回错误码
 *
 *  @return operation
 */
+ (NSURLSessionDataTask *)getDeviceInfoEx:(NSString *)deviceSerial
                               completion:(void (^)(EZDeviceInfo *deviceInfo, NSError * __nullable error))completion;

/**
 *  获取设备的版本信息接口
 *
 *  @param deviceSerial 设备序列号
 *  @param completion   回调block，正常时返回EZDeviceVersion的对象信息，错误时返回错误码
 *
 *  @return operation
 */
+ (NSURLSessionDataTask *)getDeviceVersion:(NSString *)deviceSerial
                                completion:(void (^)(EZDeviceVersion *version, NSError * __nullable error))completion;

/**
 *  通过设备验证码开关视频图片加密接口
 *
 *  @param isEncrypt    是否加密，只有NO(关闭)的时候需要设备验证码的相关参数(vaildateCode)
 *  @param deviceSerial 设备序列号
 *  @param verifyCode 设备验证码
 *  @param completion   回调block，error为空时表示操作成功
 *
 *  @return operation
 */
+ (NSURLSessionDataTask *)setDeviceEncryptStatus:(NSString *)deviceSerial
                                      verifyCode:(NSString *)verifyCode
                                         encrypt:(BOOL)isEncrypt
                                      completion:(void (^)(NSError * __nullable error))completion;

/**
 *  根据设备序列号修改设备名称接口
 *
 *  @param deviceSerial 设备序列号
 *  @param deviceName   设备名称
 *  @param completion   回调block，error为空时表示修改成功
 *
 *  @return operation
 */
+ (NSURLSessionDataTask *)setDeviceName:(NSString *)deviceName
                           deviceSerial:(NSString *)deviceSerial
                             completion:(void (^)(NSError * __nullable error))completion;

/**
 *  根据设备序列号删除当前账号的设备接口
 *
 *  @param deviceSerial 设备序列号
 *  @param completion   回调block，error为空时表示删除成功
 *  @see 该接口与终端绑定功能相关，会遇到删除时报106002的错误，请关闭终端绑定以后再试
 *
 *  @return operation
 */
+ (NSURLSessionDataTask *)deleteDevice:(NSString *)deviceSerial
                            completion:(void (^)(NSError * __nullable error))completion;

/**
 *  根据设备序列号获取存储介质状态(如是否初始化，格式化进度等)
 *
 *  @param deviceSerial 设备序列号
 *  @param completion   回调block，正常时返回EZStorageInfo的对象数组，错误时返回错误码
 *
 *  @return operation
 */
+ (NSURLSessionDataTask *)getStorageStatus:(NSString *)deviceSerial
                                completion:(void (^)(NSArray *storageStatus, NSError * __nullable error))completion;

/**
 *  根据设备序列号和分区编号格式化分区（SD卡）
 *
 *  @param deviceSerial 设备序列号
 *  @param storageIndex 查询返回的分区号，0表示全部格式化，可能会有几块硬盘的情况
 *  @param completion   回调block，error为空表示设置成功
 *
 *  @return operation
 */
+ (NSURLSessionDataTask *)formatStorage:(NSString *)deviceSerial
                           storageIndex:(NSInteger)storageIndex
                             completion:(void (^)(NSError * __nullable error))completion;

/**
 *  根据设备序列号获取设备升级时的进度状态
 *
 *  @param deviceSerial 设备序列号
 *  @param completion   回调block，正常时返回EZDeviceUpgradeStatus对象，错误时返回错误码
 *
 *  @return operation
 */
+ (NSURLSessionDataTask *)getDeviceUpgradeStatus:(NSString *)deviceSerial
                                      completion:(void (^)(EZDeviceUpgradeStatus *status, NSError * __nullable error))completion;

/**
 *  通过设备序列号对设备进行升级操作，前提是该设备有更新软件的提示
 *
 *  @param deviceSerial 设备序列号
 *  @param completion   回调block，error为空表示操作成功
 *
 *  @return operation
 */
+ (NSURLSessionDataTask *)upgradeDevice:(NSString *)deviceSerial
                             completion:(void (^)(NSError * __nullable error))completion;

/**
 *  获取抓取摄像头图片的url接口
 *
 *  @param deviceSerial 设备序列号
 *  @param cameraNo     通道号
 *  @param completion   回调block，正常时返回url地址信息，错误时返回错误码
 *  @see 该接口比较耗时，不建议进行批量设备抓图，SDK内部只支持6个http请求并发，该接口会持续占用http请求资源，如果遇到http请求延时巨大问题，优先考虑抓图接口并发造成的问题,
 *  抓图将在服务器端保留2个小时
 *
 *  @return operation
 */
+ (NSURLSessionDataTask *)captureCamera:(NSString *)deviceSerial
                               cameraNo:(NSInteger)cameraNo
                             completion:(void (^)(NSString *url, NSError * __nullable error))completion;

/**
 *  设置设备通道的清晰度
 *
 *  @param deviceSerial 设备序列号
 *  @param cameraNo     通道号
 *  @param videoLevel   通道清晰度，0-流畅，1-均衡，2-高清，3-超清
 *  @param completion   回调block，无error表示设置成功
 *  @see 如果是正在播放时调用该接口，设置清晰度成功以后必须让EZPlayer调用stopRealPlay再调用startRealPlay重新取流才成完成画面清晰度的切换。
 *
 *  @return operation
 */
+ (NSURLSessionDataTask *)setVideoLevel:(NSString *)deviceSerial
                               cameraNo:(NSInteger)cameraNo
                             videoLevel:(EZVideoLevelType)videoLevel
                             completion:(void (^)(NSError * __nullable error))completion;

/**
 *  设备设置布防状态，兼容A1和IPC设备的布防
 *
 *  @param defence      布防状态, IPC布防状态只有0和1，A1有0:睡眠 8:在家 16:外出
 *  @param deviceSerial 设备序列号
 *  @param completion   回调block，error为空表示设置成功
 *
 *  @return operation
 */
+ (NSURLSessionDataTask *)setDefence:(EZDefenceStatus)defence
                        deviceSerial:(NSString *)deviceSerial
                          completion:(void (^)(NSError * __nullable error))completion;

/**
 *  刷新设备详细缓存信息（修改验证码后调用）
 *
 *  @param deviceSerial 设备序列号
 *  @param cameraNo     通道号
 *  @param completion   回调block
 */
+ (void)refreshDeviceDetailInfo:(NSString *)deviceSerial
                       cameraNo:(NSInteger)cameraNo
                     completion:(void (^)(NSError * __nullable error))completion;

#pragma mark - 云台控制Api

/**
 *  PTZ 控制接口
 *
 *  @param deviceSerial 设备序列号
 *  @param cameraNo     通道号
 *  @param command      ptz控制命令
 *  @param action       控制启动/停止
 *  @param speed        云台速度：0-慢，1-适中，2-快
 *  @param resultBlock  回调block，当error为空时表示操作成功
 *
 *  @return operation
 */
+ (NSURLSessionDataTask *)controlPTZ:(NSString *)deviceSerial
                            cameraNo:(NSInteger)cameraNo
                             command:(EZPTZCommand)command
                              action:(EZPTZAction)action
                               speed:(NSInteger)speed
                              result:(void (^)(NSError * __nullable error))resultBlock;

/**
 *  PTZ 控制接口，支持8档速率，更细化
 *
 *  @param deviceSerial 设备序列号
 *  @param cameraNo     通道号
 *  @param command       ptz控制命令
 *  @param action         控制启动/停止
 *  @param newSpeed     云台速度：分为0-7共8档，数值越大，转速越快
 *  @param resultBlock  回调block，当error为空时表示操作成功
 *
 *  @return operation
 */
+ (NSURLSessionDataTask *)controlPTZEx:(NSString *)deviceSerial
                              cameraNo:(NSInteger)cameraNo
                               command:(EZPTZCommand)command
                                action:(EZPTZAction)action
                              newSpeed:(NSInteger)newSpeed
                                result:(void (^)(NSError * __nullable error))resultBlock;

/**
 *  PTZ 控制接口，http+p2p双通道，设备响应先到达的指令，响应更快（推荐）
 *
 *  @param deviceSerial 设备序列号
 *  @param cameraNo     通道号
 *  @param command       ptz控制命令
 *  @param action         控制启动/停止
 *  @param newSpeed     云台速度：分为0-7共8档，数值越大，转速越快
 *  @param resultBlock  回调block，当error为空时表示操作成功
 */
+ (NSURLSessionDataTask *)controlPTZMix:(NSString *)deviceSerial
                               cameraNo:(NSInteger)cameraNo
                                command:(EZPTZCommand)command
                                 action:(EZPTZAction)action
                               newSpeed:(NSInteger)newSpeed
                                 result:(void (^)(NSError *error))resultBlock;

/**
 *  PTZ 控制接口，通过p2p服务控制云台（需要设备支持）
 *
 *  @param deviceSerial 设备序列号
 *  @param cameraNo     通道号
 *  @param command       ptz控制命令
 *  @param action         控制启动/停止
 *  @param newSpeed     云台速度：分为0-7共8档，数值越大，转速越快
 *  @param resultBlock  回调block，当error为空时表示操作成功
 *
 */
+ (void)controlPTZViaP2P:(NSString *)deviceSerial
                cameraNo:(NSInteger)cameraNo
                 command:(EZPTZCommand)command
                  action:(EZPTZAction)action
                newSpeed:(NSInteger)newSpeed
                  result:(void (^)(NSError * __nullable error))resultBlock;

/**
 *  摄像头显示控制接口
 *
 *  @param deviceSerial 设备序列号
 *  @param cameraNo     通道号
 *  @param command      显示控制命令
 *  @param resultBlock  回调block，当error为空时表示操作成功
 */
+ (void)controlVideoFlip:(NSString *)deviceSerial
                cameraNo:(NSInteger)cameraNo
                 command:(EZDisplayCommand)command
                  result:(void (^)(NSError * __nullable error))resultBlock;

#pragma mark - 告警相关Api

/**
 *  根据设备序列号获取告警信息列表，设备序列号为nil时查询整个账户下的告警信息列表
 *
 *  @param deviceSerial 设备序列号
 *  @param pageIndex    分页当前页码（从0开始）
 *  @param pageSize     分页每页数量（建议20以内）
 *  @param beginTime    搜索时间范围开始时间
 *  @param endTime      搜索时间范围结束时间
 *  @param completion   回调block，正常时返回EZAlarmInfo的对象数据和查询时间范围内的告警个数的总数，错误时返回错误码
 *
 *  @return operation
 */
+ (NSURLSessionDataTask *)getAlarmList:(NSString *)deviceSerial
                             pageIndex:(NSInteger)pageIndex
                              pageSize:(NSInteger)pageSize
                             beginTime:(NSDate *)beginTime
                               endTime:(NSDate *)endTime
                            completion:(void (^)(NSArray *alarmList, NSInteger totalCount, NSError * __nullable error))completion;

/**
 *  告警图片解密方法，设备加密
 *
 *  @param data       需要解密的数据
 *  @param verifyCode 设备验证码
 *
 *  @return 解密的NSData对象，如果返回的数据是空的，请检查密码是否正确或者传入的数据是否正确。
 */
+ (NSData *)decryptData:(NSData *)data verifyCode:(NSString *)verifyCode;

/**
 *  告警图片解密方法，设备加密
 *
 *  @param data       需要解密的数据
 *  @param verifyCode 设备验证码
 *  @param type 1:设备加密；2：平台加密
 *
 *  @return 解密的NSData对象，如果返回的数据是空的，请检查密码是否正确或者传入的数据是否正确。
 */
+ (NSData *)decryptData:(NSData *)data verifyCode:(NSString *)verifyCode encryptType:(NSInteger)type;

/**
 *  设置告警信息为已读接口
 *
 *  @param alarmIds   告警信息Id数组(可以只有一个Id)，最多为10个id,否则会报错
 *  @param status     告警消息状态
 *  @param completion 回调block，error为空时表示设置成功
 *
 *  @return operation
 */
+ (NSURLSessionDataTask *)setAlarmStatus:(NSArray *)alarmIds
                             alarmStatus:(EZMessageStatus)status
                              completion:(void (^)(NSError * __nullable error))completion;

/**
 *  根据alarmId删除告警信息接口
 *
 *  @param alarmIds   告警信息Id数组(可以只有一个Id)，最多为10个Id，否则会报错
 *  @param completion 回调block，error为空时表示删除成功
 *
 *  @return operation
 */
+ (NSURLSessionDataTask *)deleteAlarm:(NSArray *)alarmIds
                           completion:(void (^)(NSError * __nullable error))completion;

/**
 *  根据设备序列号获取未读消息数，设备序列号为空时获取所有设备的未读消息数
 *
 *  @param deviceSerial 需要获取的设备序列号，为空时返回账户下所有设备的未读消息数
 *  @param type         消息类型：EZMessageTypeAlarm 告警消息（1），EZMessageTypeLeave 留言消息（2）
 *  @param completion   回调block，正常时返回未读数量，错误时返回错误码
 *
 *  @return operation
 */
+ (NSURLSessionDataTask *)getUnreadMessageCount:(NSString *)deviceSerial
                                    messageType:(EZMessageType)type
                                     completion:(void (^)(NSInteger count, NSError * __nullable error))completion;

#pragma mark - 语音留言消息数据Api

/**
 *  根据设备序列号获取设备的留言消息列表
 *
 *  @param deviceSerial 需要获取的设备序列号
 *  @param beginTime    开始时间
 *  @param endTime      结束时间
 *  @param pageIndex    分页页码
 *  @param pageSize     分页单页数量
 *  @param completion   回调block，正常时返回EZLeaveMessage的对象数组，错误时返回错误码
 *
 *  @return operation
 */
+ (NSURLSessionDataTask *)getLeaveMessageList:(NSString *)deviceSerial
                                    pageIndex:(NSInteger)pageIndex
                                     pageSize:(NSInteger)pageSize
                                    beginTime:(NSDate *)beginTime
                                      endTime:(NSDate *)endTime
                                   completion:(void (^)(NSArray *leaveMessageList, NSInteger totalCount, NSError * __nullable error))completion;

/**
 *  根据leaveId设置留言消息状态
 *
 *  @param leaveIds   留言消息Id数组(最大数量为10，允许只有1个)
 *  @param status     需要设置的留言状态，目前只支持 EZMessageStatusRead(已读)
 *  @param completion 回调block，error为空表示设置成功
 *
 *  @return operation
 */
+ (NSURLSessionDataTask *)setLeaveMessageStatus:(NSArray *)leaveIds
                                  messageStatus:(EZMessageStatus)status
                                     completion:(void (^)(NSError * __nullable error))completion;

/**
 *  根据leaveId删除留言消息
 *
 *  @param leaveIds   留言消息Id数组(最大数量为10，允许只有1个)
 *  @param completion 回调block，error为空表示删除成功
 *
 *  @return operation
 */
+ (NSURLSessionDataTask *)deleteLeaveMessage:(NSArray *)leaveIds
                                  completion:(void (^)(NSError * __nullable error))completion;

/**
 *  根据EZLeaveMessage对象信息获取语音留言消息数据接口
 *  @param message    留言消息对象
 *  @param completion 回调block （resultCode = 1 表示语音下载成功，-1表示下载失败）
 *
 *  @return operation
 */
+ (NSOperation *)getLeaveMessageData:(EZLeaveMessage *)message
                          completion:(void (^)(NSData *data, NSInteger resultCode))completion;

#pragma mark - VideoTalk视频通话相关Api

/**
 * 获取手表服务相关信息
 * @param deviceId 设备序列号
 * @param completion operation
 */
+ (void)requestGetWatchServerInfo:(NSString *)deviceId
                       completion:(void (^)(id watchServerInfo, NSError * __nullable error))completion;

/**
 * 创建会议信息
 * @param password 自定义密码
 * @param customId 开发者自定义用户ID
 * @param limit 限制最大人数 最大100
 * @param completion operation
 */
+ (void)requestCallingMeetingInfo:(NSString *)password
                         customId:(NSInteger)customId
                            limit:(NSInteger)limit
                       completion:(void (^)(int32_t roomId, NSString *vtmAddress, NSString *clientid, NSInteger customId, NSString *controlServerAddress, NSError * __nullable error))completion;

/**
 * 加入方获取会议信息
 * @param roomId  房间号
 * @param customId 开发者自定义用户ID
 * @param completion operation
 */
+ (void)requestCalledMeetingInfo:(NSString *)roomId
                        customId:(NSInteger)customId
                      completion:(void (^)(int32_t roomId, NSString *vtmAddress,NSString *clientid, NSInteger customId, NSString *controlServerAddress, NSError * __nullable error))completion;

/**
 *  邀请设备进入房间
 *  @param roomId                                房间号
 *  @param deviceSerial                   设备序列号
 *  @param channelNo                         通道号
 *  @param streamType                       主子码流 1-主码流，2-子码流，mode为2时可不传
 *  @param mode                                    加入模式 1-双向音视频模式（默认），2-对讲模式
 *  @param maxActiveSeconds         入会最长时间（秒）
 *  @param completion                       回调block
 *
 *  @return operation
 */
+ (NSURLSessionDataTask *)inviteDeviceEnterMeeting:(NSString *)roomId
                                      deviceSerial:(NSString *)deviceSerial
                                         channelNo:(NSInteger)channelNo
                                        streamType:(NSInteger)streamType
                                              mode:(NSInteger)mode
                                  maxActiveSeconds:(NSInteger)maxActiveSeconds
                                        completion:(void (^)(NSError * __nullable error))completion;

/**
 *  强制设备退出房间
 *  @param roomId                                房间号
 *  @param deviceSerial                   设备序列号
 *  @param channelNo                         通道号
 *  @param completion                       回调block
 *
 *  @return operation
 */
+ (NSURLSessionDataTask *)kickoutDeviceMoveOutRoom:(NSString *)roomId
                                      deviceSerial:(NSString *)deviceSerial
                                         channelNo:(NSInteger)channelNo
                                        completion:(void (^)(NSError * __nullable error))completion;

#pragma mark - WiFi配网相关Api

/**
 *  尝试查询设备信息，设备Wifi配置前查询一次设备的信息
 *
 *  @param deviceSerial 设备序列号
 *  @param deviceType 设备型号，无法获取到设备型号则可传nil
 *  @param completion   回调block，正常时返回EZProbeDeviceInfo对象，错误码返回错误码
 *  @see 全新的设备是没有注册到平台的，所以会出现设备不存在的情况，设备wifi配置成功以后会上报数据到萤石云平台，以后每次查询就不会出现设备不存在的情况了。
 *
 *  @return operation
 */
+ (NSURLSessionDataTask *)probeDeviceInfo:(NSString *)deviceSerial
                               deviceType:(NSString *)deviceType
                               completion:(void (^)(EZProbeDeviceInfo *deviceInfo, NSError * __nullable error))completion;

/**
 *  WiFi配置开始接口
 *
 *  @param ssid         连接WiFi SSID
 *  @param password     连接WiFi 密码
 *  @param deviceSerial 连接WiFi的设备的设备序列号
 *  @param statusBlock  返回连接设备的WiFi配置状态
 *
 *  @return YES/NO
 */
+ (BOOL)startConfigWifi:(NSString *)ssid
               password:(NSString *)password
           deviceSerial:(NSString *)deviceSerial
           deviceStatus:(void (^)(EZWifiConfigStatus status))statusBlock;

/**
 *  WiFi配置开始接口
 *
 *  @param ssid         连接WiFi SSID
 *  @param password     连接WiFi 密码
 *  @param deviceSerial 连接WiFi的设备的设备序列号,批量配置时填nil
 *  @param mode         配网的方式，EZWiFiConfigMode中列举的模式进行任意组合,例如:EZWiFiConfigSmart|EZWiFiConfigWave
 *  @param statusBlock  返回设备序列号以及当前连接状态
 *
 *  @return YES/NO
 */
+ (BOOL)startConfigWifi:(NSString *)ssid
               password:(NSString *)password
           deviceSerial:(NSString *)deviceSerial
                   mode:(NSInteger)mode
           deviceStatus:(void (^)(EZWifiConfigStatus status, NSString *deviceSerial))statusBlock;

/**
 *  WiFi配置开始接口
 *
 *  @param ssid         连接WiFi SSID
 *  @param password     连接WiFi 密码
 *  @param deviceSerial 连接WiFi的设备的设备序列号,批量配置时填nil
 *  @param mode         配网的方式，EZWiFiConfigMode中列举的模式进行任意组合,例如:EZWiFiConfigSmart|EZWiFiConfigWave
 *  @param apiUrl    指定去哪个平台查询
 *  @param statusBlock  返回设备序列号以及当前连接状态
 *
 *  @return YES/NO
 */
+ (BOOL)startConfigWifi:(NSString *)ssid
               password:(NSString *)password
           deviceSerial:(NSString *)deviceSerial
                   mode:(NSInteger)mode
                 apiUrl:(NSString *)apiUrl
           deviceStatus:(void (^)(EZWifiConfigStatus status,NSString *deviceSerial))statusBlock;

/**
 *  @since 3.0.0
 *  Wifi配置停止接口
 *
 *  @return YES/NO
 */
+ (BOOL)stopConfigWifi;

#pragma mark - AP配网相关Api

/**
 * AP配网接口
 *
 * @param ssid WiFi的ssid
 * @param password WiFi的密码
 * @param deviceSerial 设备序列号
 * @param verifyCode 设备验证码
 * @param callback 结果回调，注意：返回YES仅仅代表成功将WiFi信息发送给设备，不代表设备配网成功
 * @return 成功或失败
 */
+ (BOOL)startAPConfigWifiWithSsid:(NSString *)ssid
                         password:(NSString *)password
                     deviceSerial:(NSString *)deviceSerial
                       verifyCode:(NSString *)verifyCode
                           result:(void (^)(BOOL ret))callback;

/**
 * AP配网接口（推荐，v5.0新增，封装了设备状态轮询步骤）
 *
 * @param ssid WiFi的ssid
 * @param password WiFi的密码
 * @param deviceSerial 设备序列号
 * @param verifyCode 设备验证码
 * @param statusBlock 结果回调，返回配网过程中的各种状态
 *
 * @return 成功或失败
 */
+ (BOOL)startAPConfigWifiWithSsid:(NSString *)ssid
                         password:(NSString *)password
                     deviceSerial:(NSString *)deviceSerial
                       verifyCode:(NSString *)verifyCode
                     deviceStatus:(void (^)(EZWifiConfigStatus status, NSString *deviceSerial))statusBlock;

/**
 * 停止AP配网
 */
+ (void)stopAPConfigWifi;

#pragma mark - EZLink配网相关Api

/**
 * EZLink配网接口
 *
 * @param ssid WiFi的ssid
 * @param password WiFi的密码
 * @param deviceSerial 设备序列号
 * @param verifyCode 设备验证码
 * @param statusBlock 结果回调，返回配网过程中的各种状态
 *
 * @return 成功或失败
 */
+ (BOOL)startAPLinkConfigWifiWithSsid:(NSString *)ssid
                             password:(NSString *)password
                         deviceSerial:(NSString *)deviceSerial
                           verifyCode:(NSString *)verifyCode
                         deviceStatus:(void (^)(EZWifiConfigStatus status, NSString *deviceSerial))statusBlock;

/**
 * 停止EZLink配网
 */
+ (void)stopAPLinkConfigWifi;

#pragma mark - 接触式配网 New AP Config

/**
 * 获取接触式AP配网token
 *
 * @param completion 回调
 *
 * @return operation
 */
+ (NSURLSessionDataTask *)getNewApConfigToken:(void(^)(EZConfigTokenInfo *tokenInfo, NSError * __nullable error))completion;

/**
 * 开始NewAP配网（需连接设备热点）
 * @param token 配网token
 * @param ssid WiFi ssid
 * @param password WiFi 密码
 * @param lbsDomain lbs 域名
 * @param handler 回调
 *
 * @return 成功或失败
 */
+ (BOOL)startNewApConfigWithToken:(NSString *)token
                             ssid:(NSString *)ssid
                         password:(NSString *)password
                        lbsDomain:(NSString *)lbsDomain
                completionHandler:(void(^)(EZNewAPConfigStatus status, NSError * __nullable error))handler;

/**
 * 获取设备信息（需连接设备热点）
 *
 * @param handler 回调
 */
+ (void)getAccessDeviceInfo:(void(^)(EZAPDevInfo *devInfo, NSError * __nullable error))handler;

/**
 * 获取设备当前周边WiFi列表，上限20个（需连接设备热点）
 *
 * @param handler 回调
 */
+ (void)getAccessDeviceWifiList:(void(^)(NSArray<EZWiFiItemInfo*> *wifiList, NSError * __nullable error))handler;

/**
 * 查询设备绑定状态
 * @param deviceSerial 设备序列号
 * @param completion 回调block，正常时返回isBindSuccess，错误码返回错误码
 *
 * @return 成功或失败
 */
+ (NSURLSessionDataTask *)queryPlatformBindStatus:(NSString *)deviceSerial
                                       completion:(void(^)(BOOL isBindSuccess, NSError * __nullable error))completion;

/**
 * 设置配网设备网关地址 可选
 * @param devRouteDomain 设备网关地址
 */
+ (void)setDevRouteDomain:(NSString *)devRouteDomain;

#pragma mark - 用户相关Api

/**
 *  获取用户基本信息的接口
 *
 *  @param completion 回调block， 正常时返回EZUserInfo的对象，错误时返回错误码
 *
 *  @return operation
 */
+ (NSURLSessionDataTask *)getUserInfo:(void (^)(EZUserInfo *userInfo, NSError * __nullable error))completion;

#pragma mark - 其他Api

/**
 *  获取终端（手机等）唯一识别码
 *
 *  @return 终端唯一识别码
 */
+ (NSString *)getTerminalId;

/**
 *  上传SDK云录制图片
 *
 *  @param imageData 萤石APP类型
 *  @param completion 回调block
 */
+ (void)uploadSDKCloudRecordImage:(NSData *)imageData completion:(void (^)(NSString *storageId, NSError *error))completion;

@end

NS_ASSUME_NONNULL_END
