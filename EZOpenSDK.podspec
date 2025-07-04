Pod::Spec.new do |s|
  s.name     = 'EZOpenSDK'
  s.version  = '5.22'
  s.license  = 'MIT'
  s.summary  = 'A EZVIZ SDK'
  s.homepage = 'https://github.com/Ezviz-OpenBiz/SDK-iOS'
  s.authors  = {'ezviz-LinYong' => 'linyong3@hikvision.com'}
  s.source   = {:git => 'https://github.com/Ezviz-OpenBiz/SDK-iOS.git',:tag => s.version,:submodules => true}
  s.requires_arc = true
  s.platform = :ios,'11.0'
  s.frameworks = 'AudioToolbox', 'CoreMedia', 'ExternalAccessory', 'GLKit', 'MobileCoreServices', 'NetworkExtension', 'OpenAL', 'SystemConfiguration', 'VideoToolbox', 'AVFoundation'
  s.libraries = 'bz2', 'c++', 'iconv', 'sqlite3.0', 'z'
  s.vendored_frameworks = 'dist/EZOpenSDK/dynamicSDK/*.framework'
  s.resources = 'dist/EZOpenSDK/dynamicSDK/com.hri.hpc.mobile.ios.player.metallib'
  s.xcconfig = { 'OTHER_LDFLAGS' => '-ObjC' }
  s.pod_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64', 'GENERATE_INFOPLIST_FILE' => 'YES' }
  s.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64', 'GENERATE_INFOPLIST_FILE' => 'YES' }

end