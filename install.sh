#!/bin/bash
pkg install qt5-qtbase qt5-qttools clang python ffmpeg libnotify -y
pip install youtube-dl
qmake .
make
rm $PREFIX/bin/dl-music-qt $PREFIX/share/applications/dl-music-qt.desktop
cp dl-music-qt $PREFIX/bin
cp dl-music-qt.desktop $PREFIX/share/applications
echo "installation succesfull"
