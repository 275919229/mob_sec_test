// swift-tools-version: 6.0
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "mob_sec_test",
    products: [
        // Products define the executables and libraries a package produces, making them visible to other packages.
        .library(
            name: "mob_sec_test",
            targets: ["mob_sec_test"]),
    ],
    targets: [
        // Targets are the basic building blocks of a package, defining a module or a test suite.
        // Targets can depend on other targets in this package and products from dependencies.
        .target(
            name: "mob_sec_test"),
        .testTarget(
            name: "mob_sec_testTests",
            dependencies: ["mob_sec_test"]
        ),
    ]
)
