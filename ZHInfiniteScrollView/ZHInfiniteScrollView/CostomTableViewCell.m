//
//  CostomTableViewCell.m
//  ZHInfiniteScrollView
//
//  Created by app on 16/11/7.
//  Copyright © 2016年 ZHMARK. All rights reserved.
//

#import "CostomTableViewCell.h"
#import "ZHInfiniteScrollView.h"
#import "CustomInfiniteScrollViewCell.h"

@interface CostomTableViewCell () <ZHInfiniteScrollViewDelegate, ZHInfiniteScrollViewDataSource>
    
    @property (nonatomic, strong) ZHInfiniteScrollView *scrollView;
    
    @end

@implementation CostomTableViewCell
-(instancetype) initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier {
    
    if (self = [super initWithStyle: style reuseIdentifier: reuseIdentifier]) {
        self.selectionStyle = UITableViewCellSelectionStyleNone;
        [self configureUI];
    }
    
    return self;
}
    
- (void) dealloc {
    [self.scrollView stopAutoScroll];
    NSLog(@"%@ Dealloc", [self class]);
}
    
- (void) configureUI {
    
    self.scrollView = [ZHInfiniteScrollView infiniteScrollViewWithFrame: CGRectMake(0, 0, [UIScreen mainScreen].bounds.size.width, 200) delegate:self dataSource:self timeInterval:4.0];
    self.scrollView.backgroundColor = [UIColor whiteColor];
    [self addSubview: self.scrollView];
}
    
- (void) setDataSource:(NSMutableArray *)dataSource {
    
    _dataSource = dataSource;
    
    [self.scrollView reloadData];
}
    
#pragma mark - ZHInfiniteScrollView Delegate
#pragma mark -
#pragma mark 点击
- (void) infiniteScrollView:(ZHInfiniteScrollView *)scrollView didSelectedItemAtIndex:(NSInteger)index {
    NSLog(@"选择%@", [self.dataSource[index] objectForKey:@"title"]);
}
    
#pragma mark - ZHInfiniteScrollView DataSource
#pragma mark -
#pragma mark 视图个数
- (NSInteger) numberOfItemsInInfiniteScrollView:(ZHInfiniteScrollView *)scrollView {
    return self.dataSource.count;
}
#pragma mark 返回需要显示的视图
- (ZHInfiniteScrollViewCell *) infiniteScrollView:(ZHInfiniteScrollView *)scrollView viewAtIndex:(NSInteger)index {
    
    CustomInfiniteScrollViewCell *cell = [scrollView dequeueReusableCellWithIdentifier: @"CellIdentifier"];
    
    if (!cell) {
        
        cell = [[CustomInfiniteScrollViewCell alloc] initWithStyle:ZHInfiniteScrollViewStyleDefault reusableIdentifier: @"CellIdentifier" bounds:scrollView.bounds];
    }
    
    cell.contentView.backgroundColor = [UIColor clearColor];
    
    cell.dataSource = self.dataSource[index];
    
    return cell;
}
@end
