// swift-tools-version: 6.0
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "mob_sec_test",
    platforms: [.iOS(.v12)], // 匹配OC Framework支持的最低版本
    products: [
        // Products define the executables and libraries a package produces, making them visible to other packages.
        .library(
            name: "mob_sec_test",
            targets: ["mob_sec_test"]),
    ],
    dependencies: [
        //.package(path: "../Frameworks/FlyVerifyCSDK.xcframework"),
    ],
    targets: [
        // Targets are the basic building blocks of a package, defining a module or a test suite.
        // Targets can depend on other targets in this package and products from dependencies.
        .binaryTarget(name: "mob_sec_test_oc_fly",
                      path: "Frameworks/FlyVerifyCSDK.xcframework"),
        .binaryTarget(name: "mob_sec_test_oc_mob",
                      path: "Frameworks/MOBFoundation.xcframework"),
        .binaryTarget(name: "ShareSDKSPM",
                      path: "Frameworks/ShareSDK/ShareSDK.xcframework"),
        .target(
            name: "mob_sec_test",
            dependencies: ["mob_sec_test_oc_fly","mob_sec_test_oc_mob","ShareSDKSPM"],
//            dependencies: ["mob_sec_test_oc_fly"],
            resources: [
//                .copy("Frameworks/ShareSDK/Support/Optional/ShareSDKConfigFile.bundle"),
//                .copy("Frameworks/ShareSDK/Support/Optional/ShareSDKUI.bundle"),
                .copy("Resources")
            ],
            linkerSettings: [
                .linkedLibrary("z"),
                .linkedLibrary("c++"),
                .linkedFramework("Security"),
                .linkedFramework("SystemConfiguration"),
                .linkedFramework("Foundation"),
                .linkedFramework("UIKit"),
//                .unsafeFlags(["-ObjC"])
            ]
        ),
        .testTarget(
            name: "mob_sec_testTests",
            dependencies: ["mob_sec_test"]
        ),
    ]
)
