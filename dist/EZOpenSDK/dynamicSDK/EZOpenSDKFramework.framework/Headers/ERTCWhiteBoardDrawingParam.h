//
//  ERTCWhiteBoardDrawingParam.h
//  ERTC
//
//  Created by wangjinlong23 on 2023/8/4.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
NS_ASSUME_NONNULL_BEGIN

@interface ERTCWhiteBoardDrawingParam : NSObject
///是否可以编辑 默认为YES
@property (nonatomic, assign) BOOL canEdit;
/// 钢笔按钮标题
@property (nonatomic, copy) NSString *penTitle;
/// 荧光笔按钮标题
@property (nonatomic, copy) NSString *highlighterTitle;
/// 橡皮擦按钮标题
@property (nonatomic, copy) NSString *eraserTitle;
/// 颜色按钮标题
@property (nonatomic, copy) NSString *colorTitle;
/// 清除按钮标题
@property (nonatomic, copy) NSString *clearTitle;
/// 图片按钮标题
@property (nonatomic, copy) NSString *pictureTitle;

/// 钢笔按钮图标
@property (nonatomic, copy) NSString *penImage;
/// 荧光笔按钮图标
@property (nonatomic, copy) NSString *highlighterImage;
/// 橡皮擦按钮图标
@property (nonatomic, copy) NSString *eraserImage;
/// 清除按钮图标
@property (nonatomic, copy) NSString *clearImage;

/// 钢笔选中按钮图标
@property (nonatomic, copy) NSString *penSelectImage;
/// 荧光笔选中按钮图标
@property (nonatomic, copy) NSString *highlighterSelectImage;
/// 橡皮擦选中按钮图标
@property (nonatomic, copy) NSString *eraserSelectImage;
/// 清除选中按钮图标
@property (nonatomic, copy) NSString *clearSelectImage;
@end

NS_ASSUME_NONNULL_END
