//
//  ZHInfiniteScrollView.h
//  ZHInfiniteScrollView
//
//  Created by app on 16/11/7.
//  Copyright © 2016年 ZHMARK. All rights reserved.
//
// 无限循环滚动的 ScrollView
// QQ: 593394100

// 请在 ViewController 的 viewWillAppear 方法中调用 ZHInfiniteScrollView 的 startAutoScroll 方法
// 请在 ViewController 的 viewWillDisappear 方法中调用 ZHInfiniteScrollView 的 stopAutoScroll 方法

#import <UIKit/UIKit.h>
#import "ZHInfiniteScrollViewCell.h"

extern NSString * const kStartTimerNotification;
extern NSString * const kStopTimerNotification;

@class ZHInfiniteScrollView;

@protocol ZHInfiniteScrollViewDelegate <NSObject>
    
    @optional
    /**
     *  代理方法: 回调代理, 通知代理点击事件.
     *
     *  @param scrollView    ZHInfiniteScrollView实例对象
     *  @param index            被点击 Item 的下标
     */
- (void) infiniteScrollView:(ZHInfiniteScrollView *)scrollView didSelectedItemAtIndex:(NSInteger)index;
    
    /**
     *  代理方法: 回调代理, 通知代理滚动停止.
     *
     *  @param scrollView    ZHInfiniteScrollView实例对象
     *  @param index            滚动停止时的下标位置
     */
- (void) infiniteScrollView:(ZHInfiniteScrollView *)scrollView stopScrollAnimationAtIndex:(NSInteger)index;
    
    /**
     *  代理方法: 通知代理将要滚动
     *
     *  @param scrollView ZHInfiniteScrollView实例对象
     *  @param index      当前下标位置
     */
- (void) infiniteScrollView:(ZHInfiniteScrollView *)scrollView willBeginScroll:(NSInteger)index;
    
    @end

@protocol ZHInfiniteScrollViewDataSource <NSObject>
    
    /**
     *  数据源方法: 回调数据源, 询问 Item 数量
     *
     *  @param scrollView ZHInfiniteScrollView实例对象
     *
     *  @return Item 数量
     */
- (NSInteger) numberOfItemsInInfiniteScrollView:(ZHInfiniteScrollView *)scrollView;
    
    /**
     *  数据源方法: 回调数据源, 回去 index 位置的 View
     *
     *  @param scrollView ZHInfiniteScrollView实例对象
     *  @param index      将要出现的视图的下标
     *
     *  @return 将要出现的视图
     */
- (ZHInfiniteScrollViewCell *) infiniteScrollView:(ZHInfiniteScrollView *)scrollView viewAtIndex:(NSInteger)index;
    
    @end

@interface ZHInfiniteScrollView : UIView
    /**
     *  工厂方法
     *
     *  @param frame                   ZHInfiniteScrollView实例对象的 Frame
     *  @param delegate               代理对象
     *  @param dataSource           数据源对象
     *  @param timeInterval         时间间隔
     *  @param inView                 父视图
     *
     *  @return ZHInfiniteScrollView实例对象
     */
+ (instancetype) infiniteScrollViewWithFrame:(CGRect)frame delegate:(id<ZHInfiniteScrollViewDelegate>)delegate dataSource:(id<ZHInfiniteScrollViewDataSource>)dataSource timeInterval:(NSTimeInterval)timeInterval inView:(UIView *)destinationView;
    
    /**
     *  工厂方法
     *
     *  @param frame                 ZHInfiniteScrollView实例对象的 Frame
     *  @param delegate             代理对象
     *  @param dataSource        数据源对象
     *  @param timeInterval      时间间隔
     *
     *  @return ZHInfiniteScrollView实例对象
     */
+ (instancetype) infiniteScrollViewWithFrame:(CGRect)frame delegate:(id<ZHInfiniteScrollViewDelegate>)delegate dataSource:(id<ZHInfiniteScrollViewDataSource>)dataSource timeInterval:(NSTimeInterval)timeInterval;
    
    /**
     *  工厂方法
     *
     *  @param frame                ZHInfiniteScrollView实例对象的 Frame
     *  @param delegate            代理对象
     *  @param dataSource       数据源对象
     *
     *  @return ZHInfiniteScrollView实例对象
     */
+ (instancetype) infiniteScrollViewWithFrame:(CGRect)frame delegate:(id<ZHInfiniteScrollViewDelegate>)delegate dataSource:(id<ZHInfiniteScrollViewDataSource>)dataSource;
    
    
    /** 代理 */
    @property (nonatomic, assign) id<ZHInfiniteScrollViewDelegate> delegate;
    /** 数据源 */
    @property (nonatomic, assign) id<ZHInfiniteScrollViewDataSource> dataSource;
    
    /**
     *  刷新数据
     */
- (void) reloadData;
    
    /** 时间间隔 默认为5.0s */
    @property (nonatomic, assign) NSTimeInterval timeInterval;
    
    /**
     *  停止自动滚动
     */
- (void) stopAutoScroll;
    
    /**
     *  开始自动滚动
     */
- (void) startAutoScroll;
    
    /**
     *  获取可复用的 Cell
     *
     *  @param cellIdentifier Cell 的标示符
     *
     *  @return 可复用的 ZHInfiniteScrollViewCell 实例
     */
- (id) dequeueReusableCellWithIdentifier:(NSString *)cellIdentifier;
    
    /** 用来判断是否正在动画过程中 */
    @property (nonatomic, assign, getter=isScrolling, readonly) BOOL scrolling;
@end
