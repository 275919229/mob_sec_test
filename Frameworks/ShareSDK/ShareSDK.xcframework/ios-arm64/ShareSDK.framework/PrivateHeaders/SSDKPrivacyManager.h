//
//  MLSDKPrivacyManager.h
//  MobLinkPro
//
//  Created by PP on 2020/2/12.
//  Copyright © 2020 Mob. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface SSDKPrivacyManager : NSObject

- (void)shareSDK_isShare:(BOOL)isShare privacyCompleteBlock:(void (^)(BOOL success))block;

//level 为1或者2时,必须手动设置过授权
+ (BOOL)hasUploadPrivacy;
@end

NS_ASSUME_NONNULL_END
