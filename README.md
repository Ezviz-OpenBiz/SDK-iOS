# EZOpenSDK-iOS

## 集成方式一：CocoaPods（2026年12月即将废弃）

> ⚠️ CocoaPods 已宣布停止维护，后续版本将不再通过 CocoaPods 发布。建议尽快迁移至 Swift Package Manager（方式二）。

1.在Podfile文件中添加如下语句
  ```
  pod 'EZOpenSDK'
  ```
2.执行
  ```
  pod install
  ```
3.关闭目标target的bitcode功能
  Build Settings->Enable Bitcode设置为NO

4.安装完成

## 集成方式二：Swift Package Manager

1.在 Xcode 中选择 **File → Add Package Dependencies**

2.输入仓库地址：
  ```
  https://github.com/Ezviz-OpenBiz/SDK-iOS
  ```

3.选择版本规则（建议 Up to Next Major Version），点击 **Add Package**

4.添加资源文件（必须）

  从本仓库 `dist/EZOpenSDK/dynamicSDK/` 目录下载以下资源文件，拖入你的 Xcode 工程中（勾选 Copy items if needed）：
  - `com.hri.hpc.mobile.ios.player.metallib`
  - `CNN_SR_X2_fp16_ios_w1472xh828.bin`
  - `CNN_SR_X2_fp16_ios_w828xh1472.bin`
  - `CNN_SR_X4_fp16_ios_w432xh768.bin`
  - `CNN_SR_X4_fp16_ios_w768xh432.bin`

  确认这些文件出现在 target 的 **Build Phases → Copy Bundle Resources** 中。

  > ⚠️ 如果缺少这些资源文件，使用播放功能时会导致程序崩溃。

5.在代码中导入 SDK
  ```objc
  // Objective-C
  @import EZOpenSDKFramework;
  ```
  ```swift
  // Swift
  import EZOpenSDKFramework
  ```

6.集成完成

### 注意事项
- 仅支持真机运行（arm64），不支持模拟器
- 系统最低版本要求：iOS 12.0+
- Xcode 最低版本要求：15.0+

## 使用说明

请移步萤石开放平台[SDK下载(含demo)](https://open.ys7.com/mobile/download.html?type=app)
