#!/bin/bash
pkg install qt5-qtbase qt5-qttools clang python ffmpeg -y
pip install youtube-dl
qmake .
make
cp dl-music-qt $PREFIX/bin
cp dl-music-qt.desktop $PREFIX/share/applications
