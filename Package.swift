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
            url: "https://github.com/Ezviz-OpenBiz/SDK-iOS/releases/download/5.34/EZOpenSDKFramework.xcframework.zip",
            checksum: "f7d9043c781910cab519b5cb89508917d849a094f1df11507eec02d495e2742d"
        ),
    ]
)
