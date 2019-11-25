package dxlib

/*
#cgo CFLAGS: -IDxLib_GCC3_21b/8_2_0 -DDX_GCC_COMPILE -DDX_NON_INLINE_ASM
#cgo LDFLAGS: -LDxLib_GCC3_21b/8_2_0 -lDxLib -lDxUseCLib -lDxDrawFunc -ljpeg -lpng -lzlib -ltiff -ltheora_static -lvorbis_static -lvorbisfile_static -logg_static -lbulletdynamics -lbulletcollision -lbulletmath -lopusfile -lopus -lsilk_common -lcelt
#include "dxlibgo.h"
*/
import "C"

// DxLib_Init ライブラリ初期化を行う
func DxLib_Init() int {
	return int(C.goDxLib_Init())
}

// DxLib_End ライブラリ使用の後始末を行う
func DxLib_End() int {
	return int(C.goDxLib_End())
}

// DrawPixel 点を描画する
func DrawPixel(x, y int, Color uint32) int {
	return int(C.goDrawPixel(C.int(x), C.int(y), C.uint(Color)))
}

// GetColor DrawPixel 等の描画関数で使用するカラー値を取得する
func GetColor(Red, Green, Blue int) uint32 {
	return uint32(C.goGetColor(C.int(Red), C.int(Green), C.int(Blue)))
}

// WaitKey キーの入力待ちを行う
func WaitKey() int {
	return int(C.goWaitKey())
}
