//
//  GLTriangleViewController.h
//  MyOpenGL_1
//
//  Created by licaiyun on 2020/12/6.
//

#import <UIKit/UIKit.h>
#import <GLKit/GLKit.h> /// h文件不引用build error

NS_ASSUME_NONNULL_BEGIN

@interface GLTriangleViewController : UIViewController

@property (nonatomic) GLKView *canvas;

@end

NS_ASSUME_NONNULL_END
