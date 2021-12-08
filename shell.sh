pod trunk push EZOpenSDK.podspec --use-libraries --allow-warnings
# 发布成功或失败
if [ $? -eq 0 ];then
    echo "${__LINE_BREAK_LEFT} SDK发布到CocoaPods成功 🎉 🎉 🎉 ${__LINE_BREAK_RIGHT}"
    
    # 输出打包总用时
    echo "${__LINE_BREAK_LEFT} 使用Shell发布总耗时: ${SECONDS}s ${__LINE_BREAK_RIGHT}"

    # 本地更新
    rm ~/Library/Caches/CocoaPods/search_index.json
    pod setup
    pod repo update
    pod search EZOpenSDK
else
    echo "${__LINE_BREAK_LEFT} ${__DynamicSDK_PATH} SDK发布到CocoaPods失败 😢 😢 😢 ${__LINE_BREAK_RIGHT}"
    echo "${__LINE_BREAK_LEFT} ${__DynamicSDK_PATH} 请重新执行如下命令 ${__LINE_BREAK_RIGHT}"
    echo "${__LINE_BREAK_LEFT} ${__DynamicSDK_PATH} pod trunk push EZOpenSDK.podspec --use-libraries --allow-warnings ${__LINE_BREAK_RIGHT}"
fi
