//
//  ERTCWhiteBoardView.h
//  ERTC
//
//  Created by wangjinlong23 on 2023/8/4.
//

#import <UIKit/UIKit.h>
#import "ERTCWhiteBoardDrawingParam.h"
NS_ASSUME_NONNULL_BEGIN
typedef void (^ERTCDrawingClearBlock)(void);
@interface ERTCWhiteBoardView : UIView
/**
 初始化ERTCWhiteBoardView
 @param frame 视图大小
 @param param 白板工具栏参数
 */
- (instancetype)initWithFrame:(CGRect)frame drawingParam:(ERTCWhiteBoardDrawingParam *)param clearBlock:(nullable ERTCDrawingClearBlock)clearBlock;

/**
 设置白板背景图片
 @param image 图片
 */
-(void)setWhiteBoardBackgroundImage:(nullable UIImage *)image;

/**
 清除画板
 */
- (void)drawingClear;



@end

NS_ASSUME_NONNULL_END
