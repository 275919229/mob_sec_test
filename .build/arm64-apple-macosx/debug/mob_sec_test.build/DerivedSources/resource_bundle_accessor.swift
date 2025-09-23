import Foundation

extension Foundation.Bundle {
    static let module: Bundle = {
        let mainPath = Bundle.main.bundleURL.appendingPathComponent("mob_sec_test_mob_sec_test.bundle").path
        let buildPath = "/Users/mob_m4/Documents/gitlab_source/spm_test_1/.build/arm64-apple-macosx/debug/mob_sec_test_mob_sec_test.bundle"

        let preferredBundle = Bundle(path: mainPath)

        guard let bundle = preferredBundle ?? Bundle(path: buildPath) else {
            // Users can write a function called fatalError themselves, we should be resilient against that.
            Swift.fatalError("could not load resource bundle: from \(mainPath) or \(buildPath)")
        }

        return bundle
    }()
}