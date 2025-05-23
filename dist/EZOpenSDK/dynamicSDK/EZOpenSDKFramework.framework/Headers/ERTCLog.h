//
//  ERTCLog.h
//  ERTC
//
//  Created by Harper Kan on 2021/11/24.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN




#define ERTCLogWithType(type, atag, frmt, ...) \
do {[[ERTCLog sharedInstance] logWithType:type tag:atag message:[NSString stringWithFormat:(frmt), ##__VA_ARGS__]];} while(0)

#define ERTCLogError(tag, frmt, ...) \
ERTCLogWithType(ERTCLogTypeError, tag, frmt, ##__VA_ARGS__)
#define ERTCLogWarning(tag, frmt, ...) \
ERTCLogWithType(ERTCLogTypeWarning, tag, frmt, ##__VA_ARGS__)
#define ERTCLogInfo(tag, frmt, ...) \
ERTCLogWithType(ERTCLogTypeInfo, tag, frmt, ##__VA_ARGS__)
#define ERTCLogDefault(tag, frmt, ...) \
ERTCLogWithType(ERTCLogTypeDefault, tag, frmt, ##__VA_ARGS__)
#define ERTCLogDebug(tag, frmt, ...) \
ERTCLogWithType(ERTCLogTypeDebug, tag, frmt, ##__VA_ARGS__)




#ifndef ERTCDefaultTag
#define ERTCDefaultTag (@"Tag")
#endif

#define ERTCLogE(frmt, ...) \
ERTCLogError(ERTCDefaultTag, frmt, ##__VA_ARGS__)
#define ERTCLogW(frmt, ...) \
ERTCLogWarning(ERTCDefaultTag, frmt, ##__VA_ARGS__)
#define ERTCLogI(frmt, ...) \
ERTCLogInfo(ERTCDefaultTag, frmt, ##__VA_ARGS__)
#define ERTCLog(frmt, ...) \
ERTCLogDefault(ERTCDefaultTag, frmt, ##__VA_ARGS__)
#define ERTCLogD(frmt, ...) \
ERTCLogDebug(ERTCDefaultTag, frmt, ##__VA_ARGS__)

#define LOG_ENTER_METHOD ERTCLog(@"Enter %s Line %d", __FUNCTION__, __LINE__);
#define LOG_ENTER_METHOD_WITH_PARAM(param) ERTCLog(@"Enter %s Line %d Param:[%@]", __FUNCTION__, __LINE__,(param));
#define LOG_ENTER_METHOD_WITH_PARAMS(param1,param2) ERTCLogD(@"Enter %s Line %d Param1:[%@] Param2:[%@]", __FUNCTION__, __LINE__,(param1),(param2));

#define LOG_LEAVE_METHOD ERTCLog(@"Leave %s,Line %d", __FUNCTION__, __LINE__);



typedef NS_ENUM(NSUInteger, ERTCLogLevel) {
    ERTCLogLevelOff = 0,
    ERTCLogLevelError,
    ERTCLogLevelWarning,
    ERTCLogLevelInfo,
    ERTCLogLevelDefault,
    ERTCLogLevelDebug,
    ERTCLogLevelAll,
};

typedef NS_ENUM(NSUInteger, ERTCLogType) {
    ERTCLogTypeError = 0,
    ERTCLogTypeWarning,
    ERTCLogTypeInfo,
    ERTCLogTypeDefault,
    ERTCLogTypeDebug,
};


/// ERTC SDK  的日志系统
@interface ERTCLog : NSObject

+ (instancetype)sharedInstance;

/// 设置日志级别
/// @param level level
- (void)setLevel:(ERTCLogLevel)level;


/// 输出log
/// @param type log类型
/// @param tag tag
/// @param message 具体日志
- (void)logWithType:(ERTCLogType)type tag:(NSString * _Nullable)tag message:(NSString *)message;

/**
 启用控制台log。
 */
- (void)enableConsoleLog;

/**
 Disable console log.
 关闭控制台log。
 */
- (void)disableConsoleLog;

/**
 Enable file log. Logs will be written in files.
 打开文件log功能，将log写入文件
 */
- (void)enableFileLog;

/**
 Disable file log.
 关闭文件log功能
 */
- (void)disableFileLog;

/**
 获取日志路径
 */
- (NSArray *)getAllLogFilePath;


 /**
  保存视频文件开关

  @param enble 是否打开
  */
- (void)setERTCDebugVideoLog:(BOOL)enble;

/**
 保存音频文件开关

 @param enble 是否打开
 */
- (void)setERTCDebugAudioLog:(BOOL)enble;
/**
 设置 Bav 日志
 */
- (void)setERTCDebugLog:(BOOL)enble;

@end

NS_ASSUME_NONNULL_END
