// The Swift Programming Language
// https://docs.swift.org/swift-book
import Foundation
// 如果依赖了Alamofire，记得import
// import Alamofire

public class NetworkingManager {
    public static func doSomethingAwesome() {
        print("Something awesome is happening!")
    }

    // 必须显式声明 public 的初始化方法，外部才能访问
    public init() {}
}
