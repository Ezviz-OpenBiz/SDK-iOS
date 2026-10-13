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
            url: "https://github.com/Ezviz-OpenBiz/SDK-iOS/releases/download/5.33/EZOpenSDKFramework.xcframework.zip",
            checksum: "8bd42754da0e864030f0a8bfda7e01632d946b1904a645e7836c13369ed94758"
        ),
    ]
)
