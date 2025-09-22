import XCTest


@testable import mob_sec_test
import MOBFoundation

final class mob_sec_testTests: XCTestCase {
    func testExample() throws {
        // XCTest Documentation
        // https://developer.apple.com/documentation/xctest

        // Defining Test Cases and Test Methods
        // https://developer.apple.com/documentation/xctest/defining_test_cases_and_test_methods
        
        NetworkingManager.doSomethingAwesome()
        //FlyVerifyC.initKey("123", secret: "321")
//        let value1 = FlyVerifyC.flyVerifyKey()
        MobSDK.registerAppKey("123", appSecret:  "321")
        let value1 = MobSDK.appKey()
        print(value1)
        
        
        
    }
}
