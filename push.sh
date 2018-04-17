#!/bin/sh
adb push lib/libdso.so /usr/lib/
adb push lib/liboptic.so /usr/lib/
adb shell sync
adb shell pkill camera-service
