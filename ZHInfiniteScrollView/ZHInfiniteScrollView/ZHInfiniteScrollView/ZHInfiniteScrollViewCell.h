//
//  ZHInfiniteScrollViewCell.h
//  ZHInfiniteScrollView
//
//  Created by app on 16/11/7.
//  Copyright © 2016年 ZHMARK. All rights reserved.
//

/**
 *  ZHInfiniteScrollViewCell:
 *      请使用
 - (instancetype) initWithStyle:(ZHInfiniteScrollViewStyle)style reusableIdentifier:(NSString *)identifier bounds:(CGRect)bounds;
 或
 + (instancetype) infiniteScrollViewCellWithStyle:(NSInteger)style reusableIdentifier:(NSString *)identifier bounds:(CGRect)bounds;
 实例化 ZHInfiniteScrollViewCell
 */

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, ZHInfiniteScrollViewStyle) {
    ZHInfiniteScrollViewStyleDefault,
    /** 带一张图片 */
    ZHInfiniteScrollViewStyleSingleImage,
    /** 带图片和下方的文字 */
    ZHInfiniteScrollViewStyleSubTitle,
};

typedef void(^InfiniteCellDidClick)(NSInteger index);

@interface ZHInfiniteScrollViewCell : UIView
    
    /**
     *  用于复用的标示符
     */
    @property (nonatomic, copy, readonly) NSString *reusableIdentifier;
    
    /**
     *  类型
     */
    @property (nonatomic, assign, readonly) ZHInfiniteScrollViewStyle style;
    
    /**
     *   Init 方法
     *
     *  @param style      ZHInfiniteScrollViewCell类型
     *  @param identifier ZHInfiniteScrollViewCell标示符
     *  @param bounds     Bounds
     *
     *  @return ZHInfiniteScrollViewCell实例
     */
- (instancetype) initWithStyle:(ZHInfiniteScrollViewStyle)style reusableIdentifier:(NSString *)identifier bounds:(CGRect)bounds;
    
    /**
     *   工厂方法
     *
     *  @param style      ZHInfiniteScrollViewCell类型
     *  @param identifier ZHInfiniteScrollViewCell标示符
     *  @param bounds     Bounds
     *
     *  @return ZHInfiniteScrollViewCell实例
     */
+ (instancetype) infiniteScrollViewCellWithStyle:(NSInteger)style reusableIdentifier:(NSString *)identifier bounds:(CGRect)bounds;
    
    /**
     *  图片
     */
    @property (nonatomic, strong) UIImageView *imageView;
    
    /**
     *  内容视图
     */
    @property (nonatomic, strong) UIView *contentView;
    
    /**
     *  下方文字 Label
     */
    @property (nonatomic, strong) UILabel *textLabel;
    
    /**
     *  当前 Cell 的位置
     */
    @property (nonatomic, assign) NSInteger index;
    
    /**
     *  Cell 点击后的 Block 回调
     */
    @property (nonatomic, copy) InfiniteCellDidClick clickAction;
    
    /**
     *  ContentView 的 Inset
     */
    @property (nonatomic, assign) UIEdgeInsets contentViewInset;
    

@end
