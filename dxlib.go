package dxlib

/*
#cgo CFLAGS: -IDxLib_GCC3_21b/8_2_0 -DDX_GCC_COMPILE -DDX_NON_INLINE_ASM
#cgo LDFLAGS: -LDxLib_GCC3_21b/8_2_0 -lDxLib -lDxUseCLib -lDxDrawFunc -ljpeg -lpng -lzlib -ltiff -ltheora_static -lvorbis_static -lvorbisfile_static -logg_static -lbulletdynamics -lbulletcollision -lbulletmath -lopusfile -lopus -lsilk_common -lcelt
#include <windows.h>
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

// SetDrawScreen ...
func SetDrawScreen(DrawScreen int) int {
	return int(C.goSetDrawScreen(C.int(DrawScreen)))
}

const (
	DX_SCREEN_FRONT     = -4
	DX_SCREEN_BACK      = -2
	DX_SCREEN_WORK      = -3
	DX_SCREEN_TEMPFRONT = -15
	DX_SCREEN_OTHER     = -6

	TRUE  = 0
	FALSE = -1
)

// GetRand 乱数を取得する( RandMax : 返って来る値の最大値 )
func GetRand(RandMax int) int {
	return int(C.goGetRand(C.int(RandMax)))
}

// DrawBox 四角形を描画する
func DrawBox(x1, y1, x2, y2 int, Color uint32, FillFlag int) int {
	return int(C.goDrawBox(C.int(x1), C.int(y1), C.int(x2), C.int(y2), C.uint(Color), C.int(FillFlag)))
}

// RECT ...
type RECT C.RECT

// ClearDrawScreen 画面をクリアする
func ClearDrawScreen(ClearRect ...*RECT) int {
	cr := C.struct_tagRECT{}
	if len(ClearRect) > 0 {
		cr.left = ClearRect[0].left
		cr.top = ClearRect[0].top
		cr.right = ClearRect[0].right
		cr.bottom = ClearRect[0].bottom
	}
	return int(C.goClearDrawScreen(&cr))
}

// ScreenFlip 裏画面と表画面の内容を交換する
func ScreenFlip() int {
	return int(C.goScreenFlip())
}
