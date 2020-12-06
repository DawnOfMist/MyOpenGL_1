//
//  GLTriangleViewController.m
//  MyOpenGL_1
//
//  Created by licaiyun on 2020/12/6.
//

#import "GLTriangleViewController.h"
#include "GLTriangleRender.hpp"

@interface GLTriangleViewController ()

@property (nonatomic) GLRender::GLTriangleRender *render;

@property (nonatomic) CADisplayLink *timer;

@end

@implementation GLTriangleViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor whiteColor];
    [self setupCanvs];
}

- (void)viewDidAppear:(BOOL)animated {
    [super viewDidAppear:animated];
    self.timer = [CADisplayLink displayLinkWithTarget:self selector:@selector(screenUpdate)];
    [self.timer addToRunLoop:[NSRunLoop mainRunLoop] forMode:NSRunLoopCommonModes];
}

- (void)viewDidDisappear:(BOOL)animated {
    [super viewDidDisappear:animated];
    [self.timer invalidate];
    self.timer = nil;
}

- (void)setupCanvs {
    EAGLContext *glContext = [[EAGLContext alloc] initWithAPI:kEAGLRenderingAPIOpenGLES3];
    CGSize s = [UIScreen mainScreen].bounds.size;
    self.canvas = [[GLKView alloc] initWithFrame:CGRectMake(0, 100, s.width, 400)
                                         context:glContext];
    self.canvas.enableSetNeedsDisplay = YES;
    self.canvas.backgroundColor = [UIColor systemGrayColor];
    [self.view addSubview:self.canvas];
    [EAGLContext setCurrentContext:glContext];
    
    self.render = new GLRender::GLTriangleRender();
}

- (void)screenUpdate {
    [self.canvas setNeedsDisplay];
    if (self.render) {
        self.render->render();
    }
}

- (void)dealloc {
    [self.timer invalidate];
    self.timer = nil;
    if (self.render) {
        delete self.render;
    }
}

@end
