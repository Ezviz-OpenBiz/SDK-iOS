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
            url: "https://github.com/Ezviz-OpenBiz/SDK-iOS/releases/download/5.31/EZOpenSDKFramework.xcframework.zip",
            checksum: "5f14c8d9dd10157dd68557f097aecb011abe7e200c275ca185dac7c2b1d3765c"
        ),
    ]
)
