# ZHInfiniteScrollView
实现无限自动滚动的轮播图 ScrollView, 可以通过继承 ZHInfiniteScrollViewCell 来实现自定义 Cell 的展示.

例子: UIViewController 中添加一个 ZHInfiniteScrollView

1. 声明一个 ZHInfiniteScrollView成员变量(我推荐您这么做, 因为您需要在 ViewWillDisAppear 方法中调用 ZHInfiniteScrollView 实例的 startAutoScroll 方法来停止滚动, 否则由于定时器的存在, 将会无法释放.) 和 NSMutableArray数据源数组.

@property (nonatomic, strong) ZHInfiniteScrollView *scrollView;

@property (nonatomic, strong) NSMutableArray *dataSource;


2. 初始化您的数据源数组, 在这里我们给数据源数组添加 UIColor 实例.

self.dataSource = [[NSMutableArray alloc] initWithObjects:@{@"color":[UIColorredColor],      @"title":@"红色"},
    @{@"color":[UIColor orangeColor],   @"title":@"橙色"},
    @{@"color":[UIColor yellowColor],   @"title":@"黄色"},
    @{@"color":[UIColor greenColor],    @"title":@"绿色"},
    @{@"color":[UIColor cyanColor],     @"title":@"青色"},
    @{@"color":[UIColor blueColor],     @"title":@"蓝色"},
    @{@"color":[UIColor purpleColor],   @"title":@"紫色"},
    @{@"color":[UIColor brownColor],    @"title":@"棕色"},
    nil];

3. 初始化 ZHInfiniteScrollView, 您只需要调用这一个工厂方法, 便可以轻松实例化一个 ZHInfiniteScrollView 实例.

self.scrollView = [ZHInfiniteScrollView infiniteScrollViewWithFrame: CGRectMake(0, 64, [UIScreen mainScreen].bounds.size.width, 200) delegate:self dataSource:self timeInterval:4.0 inView: self.view];

4. 实现 ZHInfiniteScrollView 的数据源方法

(NSInteger) numberOfItemsInInfiniteScrollView:(ZHInfiniteScrollView *)scrollView 

{

return self.dataSource.count;

}

(ZHInfiniteScrollViewCell *) infiniteScrollView:(ZHInfiniteScrollView *)scrollView viewAtIndex:(NSInteger)index

{

ZHInfiniteScrollViewCell *cell = [scrollView dequeueReusableCellWithIdentifier: @"CellIdentifier"];

if (!cell) {
cell = [ZHInfiniteScrollViewCell infiniteScrollViewCellWithStyle: ZHInfiniteScrollViewStyleSubTitle     reusableIdentifier: @"CellIdentifier" bounds: scrollView.bounds];
}

cell.contentView.backgroundColor = [self.dataSource[index] objectForKey:@"color"];

if (index%2) {
cell.textLabel.text = [self.dataSource[index] objectForKey: @"title"];
} else {
cell.imageView.image = [UIImage imageNamed:@"data18.bin_1"];
}

return cell;
}

5. 请在 ViewController 的 ViewWillAppear 中加入以下代码

(void) viewWillAppear:(BOOL)animated 

{

[super viewWillAppear: animated];

[self.scrollView startAutoScroll];

}

6. 请在 ViewController 的 ViewWillDisappear 中加入以下代码

(void) viewWillDisappear:(BOOL)animated 

{

[super viewWillDisappear: animated];

[self.scrollView stopAutoScroll];

}

5. 简单的几步, 就已经实现了一个轮播图的效果. 当然您还可以继承 ZHInfiniteScrollViewCell 类来实现自定义的 Cell, 更多详情请参照 ZHInfiniteScrollViewDemo.

6. 如果您有什么疑问或建议, 您可以随时联系我, 尽管放马过来吧大神们.  邮箱: melodyzh0806@163.com  QQ: 593394100

