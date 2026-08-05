// swift-tools-version: 5.9
import PackageDescription

let package = Package(
    name: "EZOpenSDK",
    platforms: [.iOS(.v12)],
    products: [
        .library(name: "EZOpenSDK", targets: ["EZOpenSDKWrapper"]),
    ],
    targets: [
        .target(
            name: "EZOpenSDKWrapper",
            dependencies: ["EZOpenSDKFramework"],
            path: "Sources/EZOpenSDKWrapper",
            resources: [
                .copy("Resources/CNN_SR_X2_fp16_ios_w1472xh828.bin"),
                .copy("Resources/CNN_SR_X2_fp16_ios_w828xh1472.bin"),
                .copy("Resources/CNN_SR_X4_fp16_ios_w432xh768.bin"),
                .copy("Resources/CNN_SR_X4_fp16_ios_w768xh432.bin"),
                .copy("Resources/com.hri.hpc.mobile.ios.player.metallib"),
            ],
            linkerSettings: [
                .linkedFramework("AudioToolbox"),
                .linkedFramework("CoreMedia"),
                .linkedFramework("ExternalAccessory"),
                .linkedFramework("GLKit"),
                .linkedFramework("MobileCoreServices"),
                .linkedFramework("NetworkExtension"),
                .linkedFramework("SystemConfiguration"),
                .linkedFramework("VideoToolbox"),
                .linkedFramework("AVFoundation"),
                .linkedLibrary("bz2"),
                .linkedLibrary("c++"),
                .linkedLibrary("iconv"),
                .linkedLibrary("sqlite3"),
                .linkedLibrary("z"),
            ]
        ),
        .binaryTarget(
            name: "EZOpenSDKFramework",
            url: "https://github.com/Ezviz-OpenBiz/SDK-iOS/releases/download/5.30.2/EZOpenSDKFramework.xcframework.zip",
            checksum: "b7c8b5868dc69ec2ec8d6b2ce6c79f36e9740f50993f4ff49286d990df3a0b3d"
        ),
    ]
)
