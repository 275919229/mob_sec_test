//
//  SSDKShareWindow.h
//  ShareSDK
//
//  Created by maxl on 2019/9/9.
//  Copyright © 2019 掌淘科技. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SSDKPrivacyManager.h"

NS_ASSUME_NONNULL_BEGIN
//YES测试环境，不写或NO为正式环境
//#define IsAppServiceTest YES

@interface SSDKApplicationHandleOpenUrlInfoModel : NSObject

@property (nonatomic, copy) NSString * sourceApplication;

@property (nonatomic, strong) id annotation;

@property (nonatomic, assign) BOOL openInPlace;

@property (nonatomic, copy) NSString *sourceSel;

//根据不同的方法传回不同的数据
@property (nonatomic, strong) id orignOption;

@end

typedef void(^SSDKApplicationHandleOpenUrlContextBlock)(id source, id url, SSDKApplicationHandleOpenUrlInfoModel * options,BOOL *success);

typedef void(^SSDKApplicationContinueUserActivityBlock)(id source, NSUserActivity *userActivity, SEL sel, BOOL *success);


@interface SSDKApplication : NSObject

+ (SSDKApplication *)sharedApplication;

@property (nonatomic, assign, readonly) BOOL isSceneApp;


#pragma mark - window And Controller -
/**
 iOS13基于UIScene：
 1.若当前只有一个激活的window，则获取当前激活的window
 2.否则，获取最近点击的window
 
 否则：
 获取application的代理的window
 */

//当前活跃window
@property (nonatomic, strong, readonly) UIWindow *window;

//当前或缺的scene的delegateWindow
@property (nonatomic, strong, readonly) UIWindow *higherWindow;

//当前活跃windowscene
@property (nonatomic, copy, readonly) UIWindow *keyWindow;

//屏幕
@property (nonatomic, assign) CGRect  mainBounds;

//当前活跃的scene
@property (nonatomic, strong, readonly) id currentScene;

//当前活跃的windows
@property (nonatomic, strong, readonly) NSArray <UIWindow *>* windows;

/// 在iOS13.0调用后将当前window加载到windowScene上
- (void)showWindow:(UIWindow *)window;

//此方法可保证一定在application的window第一次初始化加载完成后调用
- (void)addBeforeWindowEvent:(void (^) (SSDKApplication *application))event;

#pragma mark - app style -
@property (nonatomic, assign) UIStatusBarStyle statusBarStyle;

@property (nonatomic, assign) BOOL statusBarHidden;

@property (nonatomic, assign, readonly) CGRect statusBarFrame;

@property (nonatomic, assign) UIInterfaceOrientation statusBarOrientation;

@property (nonatomic, assign) BOOL networkActivityIndicatorVisible;


#pragma mark - Scene代理 -

//scene:openURLContexts: 第三方scheme方式打开本app
- (void)addSceneHandleOpenUrlContext:(SSDKApplicationHandleOpenUrlContextBlock)source;


//scene:continueUserActivity:第三方ul方式打开本app
- (void)addSceneContinueUserActivity:(SSDKApplicationContinueUserActivityBlock)source;

//scene:willConnectToSession:options: 添加connect链接
- (void)addSceneWillConnected:(void (^)(id source, id session, NSDictionary * options))source;

//openURL:options:completionHandler: 添加打开第三方应用
- (void)addSceneOpenUrl:(void (^) (id source, id options ,id completionHandler))source;

//application:didFinishLaunchingWithOptions: 应用程序开始加载
- (void)addAppDidFinishLaunchingWithOptions:(void (^) (id source, id launchOptions, BOOL * success))source;

//applicationDidResignActive: 取消活跃状态
- (void)addAppWillResignActice:(void (^)(id source))source;

//addAppWillBecomeActice: 进入活跃状态
- (void)addAppWillBecomeActice:(void (^)(id source))source;

#pragma mark - 设置类的模态推出样式 -
//给一个类统一
- (void)setPreferredStyle:(UIModalPresentationStyle)style forClassName:(NSString *)className;
- (void)removePreferredStyleWithClassName:(NSString *)className;
//给一个对象添加模态突出模式统一
- (void)setPreferredStyle:(UIModalPresentationStyle)style forObject:(__kindof UIViewController *)vc;


//移除js方法
+ (void)removeJsContextMethod:(NSString *)method;


- (IMP)methodImpSet:(dispatch_block_t)newImpBlock class:(Class)clas selector:(SEL)selector encodeTypes:(NSString *)encodeTypes;

- (IMP)methodImpSetClass:(dispatch_block_t)newImpBlock class:(Class)clas selector:(SEL)selector encodeTypes:(NSString *)encodeTypes;

- (IMP)methodImpSet:(dispatch_block_t)newImpBlock class:(Class)clas selector:(SEL)selector;

- (IMP)methodImpSetClass:(dispatch_block_t)newImpBlock class:(Class)clas selector:(SEL)selector;

#pragma mark - 隐私协议 -

@property (nonatomic, strong) SSDKPrivacyManager *privacyManager;

@end


typedef void(^ssdkApplication_vcdismisstask)(id object, UIViewController *presentingViewController);
@interface UIViewController (SSDKApplication)

//直接模态推出alert
@property (nonatomic, copy, readonly) UIViewController * (^ _ssdkAlertShow)(BOOL animated, void (^_Nullable completion)(void));

@property (nonatomic, copy, readonly) UIViewController * (^ _ssdkAlertShowWithStyle)(UIStatusBarStyle style ,BOOL animated, void (^_Nullable completion)(void));

@property (nonatomic, copy, readonly) UIViewController * _Nonnull (^SSDKApplication_vcDismiss)(ssdkApplication_vcdismisstask _Nonnull);

- (void)ssdk_removeFromWindow;

@end


typedef void(^ssdkApplication_deallocTask)(id object);

@interface NSObject (SSDKApplication)
/**
 添加销毁任务,此方法不支持异步
 */
@property (nonatomic, copy, readonly) NSObject * (^ SSDKApplication_addDellocTask)(ssdkApplication_deallocTask task);

@end

@interface UIView (SSDKApplication)

- (UIViewController *)ssdk_viewController;

@end

@interface SSDKApplicationRootViewController : UIViewController
@property (nonatomic, copy) void (^ ssdk_didLoad) (UIViewController * vc);
@end

@interface NSDictionary (SSDKApplication)

- (NSMutableDictionary *)_conventToShareSDKParameters:(NSInteger)platformType;

@end

typedef NS_ENUM(NSUInteger, SSDKUserInterfaceStyle) {
    SSDKUserInterfaceStyleUnspecified,
    SSDKUserInterfaceStyleLight,
    SSDKUserInterfaceStyleDark,
};
@interface SSDKApplication (ApplicationExtention)

+ (NSDictionary *)infoPlist;

+ (NSArray *)urlQueriesSchemes;

+ (NSArray *)urlTypes;

+ (UIColor *)colorWithLightColor:(UIColor *)lightColor darkColor:(UIColor *)darkColor;

@end

@interface SSDKApplication (Convenient)

+ (CGRect)mainBounds;

@end



NS_ASSUME_NONNULL_END
 
