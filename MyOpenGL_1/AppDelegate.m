//
//  AppDelegate.m
//  MyOpenGL_1
//
//  Created by licaiyun on 2020/12/6.
//

#import "AppDelegate.h"
#import "ViewController.h"

@interface AppDelegate ()

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    self.window = [[UIWindow alloc] init];
    ViewController *vc = [[ViewController alloc] init];
    UINavigationController *rootVC = [[UINavigationController alloc] initWithRootViewController:vc];
    self.window.rootViewController = rootVC;
    [self.window makeKeyWindow];
    return YES;
}


@end
