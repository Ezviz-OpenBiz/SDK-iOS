//
//  EZAICloudStorageView.h
//  EZPlay
//
//  Created by JuneCheng on 2025/7/17.
//

#import <UIKit/UIKit.h>

@class EZCloudRecordFile;
@class EZAICloudStorageView;

/// AI云存储回调协议
@protocol EZAICloudStorageViewDelegate <NSObject>

@optional

/// 录像片段被点击
/// @param recordFile 被点击的云录像文件对象
- (void)onAICloudRecordFileClick:(EZCloudRecordFile *)recordFile;

/// 封面图加密，需要设备验证码来解密封面
/// 实现方应弹出验证码输入框，获取后调用 reloadEncryptedCovers:
- (void)onAICloudStorageViewNeedVerifyCode;

@end

/// AI云存储视图管理器
/// 将AI云存储UI嵌入到调用方提供的容器View中
@interface EZAICloudStorageView : NSObject

/// 回调代理
@property (nonatomic, weak) id<EZAICloudStorageViewDelegate> delegate;

/// 是否正在展示
@property (nonatomic, assign, readonly) BOOL isShowing;

/**
 *  初始化AI云存储视图
 *
 *  @param containerView 容器视图（由调用方提供）
 *  @param deviceSerial  设备序列号
 *  @param cameraNo      通道号
 *  @param verifyCode    设备验证码（可为 nil，传入后可直接加载加密封面）
 *
 *  @return 实例
 */
- (instancetype)initWithContainerView:(UIView *)containerView
                         deviceSerial:(NSString *)deviceSerial
                             cameraNo:(NSInteger)cameraNo
                           verifyCode:(nullable NSString *)verifyCode;

/// 展示AI云存储UI（先判断设备是否支持，支持则展示对话页面，不支持则展示升级提示页）
- (void)show;

/// 隐藏AI云存储UI（不销毁，可通过resume恢复）
- (void)hide;

/// 恢复已隐藏的AI云存储页面（不重新请求接口，不重建View）
- (void)resume;

/// 释放AI云存储UI资源
- (void)releaseView;

/// 更新AI云存储录像的播放状态
/// @param isPlaying YES=播放中，NO=停止
- (void)updatePlaybackState:(BOOL)isPlaying;

/// 设置验证码并刷新加密封面（外部获取验证码后调用）
/// @param verifyCode 设备验证码
- (void)reloadEncryptedCovers:(NSString *)verifyCode;

/// 是否有加密封面尚未加载
- (BOOL)hasEncryptedCoversNotLoaded;

@end
