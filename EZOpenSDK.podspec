Pod::Spec.new do |s|
  s.name     = 'EZOpenSDK'
  s.version  = '4.16.8'
  s.license  = 'MIT'
  s.summary  = 'A EZVIZ SDK'
  s.homepage = 'https://github.com/Ezviz-OpenBiz/SDK-iOS'
  s.authors  = {'ezviz-LinYong' => 'linyong3@hikvision.com'}
  s.source   = {:git => 'https://github.com/Ezviz-OpenBiz/SDK-iOS.git',:tag => s.version,:submodules => true}
  s.requires_arc = true
  s.platform = :ios,'8.0'
  s.vendored_frameworks = 'dist/EZOpenSDK/dynamicSDK/*'
  s.frameworks = 'AudioToolbox', 'CoreMedia', 'ExternalAccessory', 'GLKit', 'MobileCoreServices', 'Network', 'NetworkExtension', 'OpenAL', 'SystemConfiguration', 'VideoToolbox'
  s.libraries = 'bz2', 'c++', 'iconv.2.4.0', 'sqlite3.0', 'z'
  s.xcconfig = { "OTHER_LDFLAGS" => "-ObjC", "ENABLE_BITCODE" => "NO"}


end