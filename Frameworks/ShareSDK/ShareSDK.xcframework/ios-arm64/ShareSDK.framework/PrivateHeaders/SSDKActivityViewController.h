//
//  SSDKActivityViewController.h
//  ShareSDK
//
//  Created by maxl on 2020/5/15.
//  Copyright © 2020 掌淘科技. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

//如果数据源比如图片或者视频是在bundle中，需要把资源拷贝到沙盒中，在传入activityViewController中，否则在部分机型会出问题
@interface SSDKActivityViewController : UIActivityViewController

@property (nonatomic, copy) NSArray *whiteList;

- (void)ssdk_dismiss;

@property (nonatomic, assign) BOOL isClickElement;

@end

NS_ASSUME_NONNULL_END
