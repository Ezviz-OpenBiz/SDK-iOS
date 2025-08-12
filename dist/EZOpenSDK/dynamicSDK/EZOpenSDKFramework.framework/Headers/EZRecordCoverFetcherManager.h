//
//  EZRecordCoverFetcherManager.h
//  EZPlay
//
//  Created by JuneCheng on 2022/12/19.
//

#import <Foundation/Foundation.h>
@class EZDeviceRecordFile;

// Fetcher初始化代理
@protocol RecordCoverFetcherDelegate<NSObject>

@optional
/**
 * SD卡录像封面提取器初始化成功回调
 */
- (void)onFetcherInitSuccess;

/**
 * SD卡录像封面提取器初始化失败回调
 */
- (void)onFetcherInitFailed;

/**
 * SD卡录像封面提取封面成功回调
 */
- (void)onGetCoverSuccess:(int)seq data:(NSData *_Nonnull)data;

/**
 * SD卡录像封面提取封面失败回调
 */
- (void)onGetCoverFailed:(int)errorCode;

@end

NS_ASSUME_NONNULL_BEGIN

@interface EZRecordCoverFetcherManager : NSObject


@property (nonatomic, weak) id <RecordCoverFetcherDelegate> fetcherDelegate;

+ (instancetype)sharedInstance;

/**
 * 与设备建立链接（国内支持，海外不支持）
 *
 * @param   deviceSerial 设备序列号
 * @param   cameraNo 设备通道号
 */
- (void)initFetcherWithDeviceSerial:(NSString *)deviceSerial cameraNo:(NSInteger)cameraNo;


/**
 * 断开与设备的链接（国内支持，海外不支持）
 */
- (void)stopFetcher;


/**
 * 跟设备请求SD卡录像封面（国内支持，海外不支持）
 * 只支持主账号，不支持子账号和托管账号
 */
- (void)requestRecordCover:(NSArray<EZDeviceRecordFile *> *)recordFiles;


@end

NS_ASSUME_NONNULL_END
