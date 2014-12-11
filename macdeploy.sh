#!/bin/bash
echo
echo PanUploader

echo - macdeployqt 

cd ~/Development/aforge/panuploader

rm -R '../../Distribution/PanUploader/PanUploader.app'
cp -R './PanUploader-build-Desktop_Qt_5_3_2_LLDB-Release/PanUploader.app' '../../Distribution/PanUploader/PanUploader.app'
cp './trunk/Resources/Info.plist' '../../Distribution/PanUploader/PanUploader.app/Contents/Info.plist'

/Developer/Qt/5.3/clang_64/bin/macdeployqt '../../Distribution/PanUploader/PanUploader.app'

../patchQtFramework.sh '../../Distribution/PanUpLoader/PanUpLoader.app/Contents/Frameworks/QtCore.framework'
../patchQtFramework.sh '../../Distribution/PanUpLoader/PanUpLoader.app/Contents/Frameworks/QtGui.framework'
../patchQtFramework.sh '../../Distribution/PanUpLoader/PanUpLoader.app/Contents/Frameworks/QtNetwork.framework'
../patchQtFramework.sh '../../Distribution/PanUpLoader/PanUpLoader.app/Contents/Frameworks/QtPrintSupport.framework'
../patchQtFramework.sh '../../Distribution/PanUpLoader/PanUpLoader.app/Contents/Frameworks/QtWidgets.framework'

echo - code signing

codesign --force --verify --sign 'Developer ID Application: Alfred-Wegener-Institut fur Polar- und Meeresforschung (AWI)' '../../Distribution/PanUpLoader/PanUpLoader.app/Contents/Frameworks/QtCore.framework'
codesign --force --verify --sign 'Developer ID Application: Alfred-Wegener-Institut fur Polar- und Meeresforschung (AWI)' '../../Distribution/PanUpLoader/PanUpLoader.app/Contents/Frameworks/QtGui.framework'
codesign --force --verify --sign 'Developer ID Application: Alfred-Wegener-Institut fur Polar- und Meeresforschung (AWI)' '../../Distribution/PanUpLoader/PanUpLoader.app/Contents/Frameworks/QtNetwork.framework'
codesign --force --verify --sign 'Developer ID Application: Alfred-Wegener-Institut fur Polar- und Meeresforschung (AWI)' '../../Distribution/PanUpLoader/PanUpLoader.app/Contents/Frameworks/QtPrintSupport.framework'
codesign --force --verify --sign 'Developer ID Application: Alfred-Wegener-Institut fur Polar- und Meeresforschung (AWI)' '../../Distribution/PanUpLoader/PanUpLoader.app/Contents/Frameworks/QtWidgets.framework'

codesign --force --verify --sign 'Developer ID Application: Alfred-Wegener-Institut fur Polar- und Meeresforschung (AWI)' '../../Distribution/PanUpLoader/PanUpLoader.app/Contents/PlugIns/accessible/libqtaccessiblewidgets.dylib'
codesign --force --verify --sign 'Developer ID Application: Alfred-Wegener-Institut fur Polar- und Meeresforschung (AWI)' '../../Distribution/PanUpLoader/PanUpLoader.app/Contents/PlugIns/bearer/libqcorewlanbearer.dylib'
codesign --force --verify --sign 'Developer ID Application: Alfred-Wegener-Institut fur Polar- und Meeresforschung (AWI)' '../../Distribution/PanUpLoader/PanUpLoader.app/Contents/PlugIns/bearer/libqgenericbearer.dylib'
codesign --force --verify --sign 'Developer ID Application: Alfred-Wegener-Institut fur Polar- und Meeresforschung (AWI)' '../../Distribution/PanUpLoader/PanUpLoader.app/Contents/PlugIns/imageformats/libqdds.dylib'
codesign --force --verify --sign 'Developer ID Application: Alfred-Wegener-Institut fur Polar- und Meeresforschung (AWI)' '../../Distribution/PanUpLoader/PanUpLoader.app/Contents/PlugIns/imageformats/libqgif.dylib'
codesign --force --verify --sign 'Developer ID Application: Alfred-Wegener-Institut fur Polar- und Meeresforschung (AWI)' '../../Distribution/PanUpLoader/PanUpLoader.app/Contents/PlugIns/imageformats/libqicns.dylib'
codesign --force --verify --sign 'Developer ID Application: Alfred-Wegener-Institut fur Polar- und Meeresforschung (AWI)' '../../Distribution/PanUpLoader/PanUpLoader.app/Contents/PlugIns/imageformats/libqico.dylib'
codesign --force --verify --sign 'Developer ID Application: Alfred-Wegener-Institut fur Polar- und Meeresforschung (AWI)' '../../Distribution/PanUpLoader/PanUpLoader.app/Contents/PlugIns/imageformats/libqjp2.dylib'
codesign --force --verify --sign 'Developer ID Application: Alfred-Wegener-Institut fur Polar- und Meeresforschung (AWI)' '../../Distribution/PanUpLoader/PanUpLoader.app/Contents/PlugIns/imageformats/libqjpeg.dylib'
codesign --force --verify --sign 'Developer ID Application: Alfred-Wegener-Institut fur Polar- und Meeresforschung (AWI)' '../../Distribution/PanUpLoader/PanUpLoader.app/Contents/PlugIns/imageformats/libqmng.dylib'
codesign --force --verify --sign 'Developer ID Application: Alfred-Wegener-Institut fur Polar- und Meeresforschung (AWI)' '../../Distribution/PanUpLoader/PanUpLoader.app/Contents/PlugIns/imageformats/libqtga.dylib'
codesign --force --verify --sign 'Developer ID Application: Alfred-Wegener-Institut fur Polar- und Meeresforschung (AWI)' '../../Distribution/PanUpLoader/PanUpLoader.app/Contents/PlugIns/imageformats/libqtiff.dylib'
codesign --force --verify --sign 'Developer ID Application: Alfred-Wegener-Institut fur Polar- und Meeresforschung (AWI)' '../../Distribution/PanUpLoader/PanUpLoader.app/Contents/PlugIns/imageformats/libqwbmp.dylib'
codesign --force --verify --sign 'Developer ID Application: Alfred-Wegener-Institut fur Polar- und Meeresforschung (AWI)' '../../Distribution/PanUpLoader/PanUpLoader.app/Contents/PlugIns/imageformats/libqwebp.dylib'
codesign --force --verify --sign 'Developer ID Application: Alfred-Wegener-Institut fur Polar- und Meeresforschung (AWI)' '../../Distribution/PanUpLoader/PanUpLoader.app/Contents/PlugIns/platforms/libqcocoa.dylib'
codesign --force --verify --sign 'Developer ID Application: Alfred-Wegener-Institut fur Polar- und Meeresforschung (AWI)' '../../Distribution/PanUpLoader/PanUpLoader.app/Contents/PlugIns/printsupport/libcocoaprintersupport.dylib'

codesign --force --verify --sign 'Developer ID Application: Alfred-Wegener-Institut fur Polar- und Meeresforschung (AWI)' '../../Distribution/PanUploader/PanUploader.app' # --entitlements './trunk/Resources/PanUploader.entitlements'

echo - mount package

cd ~/Development/Distribution/PanUploader
hdiutil attach ~/Development/Distribution/PanUploader_OSX.dmg

rm -R '/Volumes/PanUploader/PanUploader.app'
cp -R PanUploader.app '/Volumes/PanUploader'

cd '/Volumes/PanUploader'
rm -rf .fseventsd
mkdir .fseventsd
touch .fseventsd/no_log
cd ~/Development/Distribution

echo - verify package

codesign -dvv '/Volumes/PanUploader/PanUploader.app'

echo
hdiutil detach '/Volumes/PanUploader'