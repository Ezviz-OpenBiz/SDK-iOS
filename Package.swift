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
            url: "https://github.com/Ezviz-OpenBiz/SDK-iOS/releases/download/5.32/EZOpenSDKFramework.xcframework.zip",
            checksum: "6ab452ecc8a17af87292df70e4b3858f9bc2c39cd43cbf3bc257964ecbd2b922"
        ),
    ]
)
