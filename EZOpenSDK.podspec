Pod::Spec.new do |s|
  s.name     = 'EZOpenSDK'
  s.version  = '4.8.6'
  s.license  = 'MIT'
  s.summary  = 'A EZVIZ SDK'
  s.homepage = 'https://github.com/Hikvision-Ezviz/SDK-iOS'
  s.authors  = {'ezviz-LinYong' => 'linyong3@hikvision.com'}
  s.source   = {:git => 'https://github.com/Hikvision-Ezviz/SDK-iOS.git',:tag => s.version,:submodules => true}
  s.requires_arc = true
  s.platform = :ios,'8.0'
  s.vendored_frameworks = 'dist/EZOpenSDK/dynamicSDK/*.framework'
end