//
//  EZPlayWaterMarkConfig.h
//  EZPlay
//
//  Created by JuneCheng on 2025/9/18.
//

#import <Foundation/Foundation.h>

// 字体对齐方式枚举
typedef NS_ENUM(NSUInteger, EZWaterMarkTextAlignment) {
    EZWaterMarkTextAlignmentCenter = 0, // 居中对齐
    EZWaterMarkTextAlignmentLeft        // 左对齐
};

// 窗口自适应方式枚举
typedef NS_ENUM(NSUInteger, EZWaterMarkWindowAdaptMode) {
    EZWaterMarkWindowAdaptModeNone = 0,       // 固定字体大小和固定行列数（不进行自适应计算，按输入参数fontSize和number的值进行显示）
    EZWaterMarkWindowAdaptModeFontRowColumn,  // 字体行列数进行自适应改变（字体大小不变，number的值失效）
    EZWaterMarkWindowAdaptModeFontSize,       // 字体大小进行自适应改变 （行列数不变）
};

NS_ASSUME_NONNULL_BEGIN

@interface EZPlayWaterMarkConfig : NSObject

/// 文本信息数组
@property (nonatomic, strong) NSArray<NSString *> *fontArray;
/// 字体宽度，限制：大于0（小于15的会默认为15），默认值为35
@property (nonatomic, assign) int fontWidth;
/// 字体高度，限制：大于0（小于15的会默认为15），默认值为35
@property (nonatomic, assign) int fontHeight;
/// 字体行间距，限制：无 建议取值范围[1~2]，表示字体高的倍数，1就是紧贴，默认值为1.2
@property (nonatomic, assign) float fontSpace;
/// 字体对齐方式，默认左对齐
@property (nonatomic, assign) EZWaterMarkTextAlignment fontAlignment;

/// 字体顺时针倾斜角度，限制[0, 360]，默认值为0
@property (nonatomic, assign) float fontRotateAngle;

/// 字体颜色是否自适应，默认关闭。开启后，自定义设置的color属性会失效。深色背景字体会显示白色，浅色背景字体会显示成黑色。
@property (nonatomic, assign) BOOL fontColorAdapt;

/// 红，限制：[0, 255]，默认值为0
@property (nonatomic, assign) int red;
/// 绿，限制：[0, 255]，默认值为0
@property (nonatomic, assign) int green;
/// 蓝，限制：[0, 255]，默认值为0
@property (nonatomic, assign) int blue;
/// 透明度，限制：[0, 100]  设置0会默认为100，默认值为0
@property (nonatomic, assign) int alpha;


/// x轴比例开始位置，限制[0, 1]，默认值为0
@property (nonatomic, assign) float startPosX;
/// y轴比例开始位置，限制[0, 1]，默认值为0
@property (nonatomic, assign) float startPosY;


/// 窗口自适应，默认值为EZWaterMarkWindowAdaptModeNone
@property (nonatomic, assign) EZWaterMarkWindowAdaptMode windowAdaptMode;

/**
  设置自适应行列数行间距 限制：大于0 windowAdaptMode == EZWaterMarkWindowAdaptModeFontRowColumn时用到。，默认值为100
  计算方式：rowSpace = 300，当前窗口大小 = 900，行数 = 900/300 = 3。 当窗口大小增大到1200时，行数自适应调整 = 1200/300 = 4。
  （当不足一行或一列时，最小为2行2列）（小于30，效果为30）
 */
@property (nonatomic, assign) int windowAdaptRowSpace;
/**
  设置自适应行列数列间距 限制：大于0 windowAdaptMode == EZWaterMarkWindowAdaptModeFontRowColumn时用到。，默认值为100
  （当不足一行或一列时，最小为2行2列）
 */
@property (nonatomic, assign) int windowAdaptColumnSpace;
/**
  设置字体比例的基准窗口宽 限制：大于0 windowAdaptMode == EZWaterMarkWindowAdaptModeFontSize时用到。
  计算方式：输入fontWidth = 20，baseWindowWidth = 0.5625，字体大小 = 当前窗口宽 * 20 / 900 。
  如当前窗口宽为1200时，字体大小 = 1200 * 20 / 900 = 26
 */
@property (nonatomic, assign) int windowAdaptBaseWindowWidth;
@property (nonatomic, assign) int windowAdaptBaseWindowHeight;

/**
  水印是否全屏，当windowAdaptMode = EZWaterMarkWindowAdaptModeNone或EZWaterMarkWindowAdaptModeFontSize时生效，默认关闭。
  开启后，需要用到rowNumber、columnNumber属性
 */
@property (nonatomic, assign) BOOL fillFullScreen;
/// 行数，默认值为2
@property (nonatomic, assign) int rowNumber;
/// 列数，默认值为2
@property (nonatomic, assign) int columnNumber;

@end

NS_ASSUME_NONNULL_END
