//
//  ViewController.m
//  MyOpenGL_1
//
//  Created by licaiyun on 2020/12/6.
//

#import "ViewController.h"
#import "GLTriangleViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor whiteColor];
    
    CGFloat top = 100;
    CGFloat pad = 20;
    CGFloat x = [UIScreen mainScreen].bounds.size.width/2;
    UIButton *triangleBtn = [self createButton];
    [triangleBtn setTitle:@"三角形" forState:UIControlStateNormal];
    [triangleBtn addTarget:self
                    action:@selector(didTapTriangleButton)
          forControlEvents:UIControlEventTouchUpInside];
    triangleBtn.center = CGPointMake(x, top + 45/2.0);
    top += pad + 45;
    [self.view addSubview:triangleBtn];
}

- (void)didTapTriangleButton {
    GLTriangleViewController *triangleVC = [[GLTriangleViewController alloc] init];
    [self.navigationController pushViewController:triangleVC animated:YES];
}

- (UIButton *)createButton {
    UIButton *btn = [[UIButton alloc] init];
    btn.frame = CGRectMake(0, 0, 100, 45);
    btn.backgroundColor = UIColor.brownColor;
    btn.layer.cornerRadius = 8;
    return btn;
}


@end
