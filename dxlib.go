package dxlib

/*
#cgo CPPFLAGS: -DDX_GCC_COMPILE -DDX_NON_INLINE_ASM
#cgo LDFLAGS: -lDxLib -lDxUseCLib -lDxDrawFunc -ljpeg -lpng -lzlib -ltiff -ltheora_static -lvorbis_static -lvorbisfile_static -logg_static -lbulletdynamics -lbulletcollision -lbulletmath -lopusfile -lopus -lsilk_common -lcelt
#include <windows.h>
#include "dxlibgo.h"
*/
import "C"
import (
	"golang.org/x/text/encoding/japanese"
	"golang.org/x/text/transform"
)

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

	TRUE  = C.TRUE
	FALSE = C.FALSE
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

// マウスポインタの表示状態を設定する( DispFlag:マウスポインタを表示するかどうか( TRUE:表示する  FALSE:表示しない )
func SetMouseDispFlag(DispFlag int) int {
	return int(C.goSetMouseDispFlag(C.int(DispFlag)))
}

// どれか一つでもキーが押されているかどうかを取得( 押されていたら戻り値が 0 以外になる )
func CheckHitKeyAll(CheckType int) int {
	return int(C.goCheckHitKeyAll(C.int(CheckType)))
}

const (
	DX_CHECKINPUT_KEY   = (0x0001)                                                      // キー入力を調べる
	DX_CHECKINPUT_PAD   = (0x0002)                                                      // パッド入力を調べる
	DX_CHECKINPUT_MOUSE = (0x0004)                                                      // マウスボタン入力を調べる
	DX_CHECKINPUT_ALL   = (DX_CHECKINPUT_KEY | DX_CHECKINPUT_PAD | DX_CHECKINPUT_MOUSE) // すべての入力を調べる
	//DX_CHECKINPUT_ALL = (0x0007) // すべての入力を調べる
)

// 指定の時間だけ処理をとめる
func WaitTimer(WaitTime int) int {
	return int(C.goWaitTimer(C.int(WaitTime)))
}

// マウスポインタの位置を取得する
func GetMousePoint(XBuf, YBuf *int) int {
	x := C.int(0)
	y := C.int(0)
	ret := C.goGetMousePoint(&x, &y)

	*XBuf = int(x)
	*YBuf = int(y)
	return int(ret)
}

// デフォルトフォントハンドルを使用して文字列を描画する
func DrawString(x, y int, String string, Color, EdgeColor uint32) int {
	str, _, err := transform.String(japanese.ShiftJIS.NewEncoder(), String)
	if err != nil {
		return -1
	}
	return int(C.goDrawString(C.int(x), C.int(y), C.CString(str), C.uint(Color), C.uint(EdgeColor)))
}

// ウインドウズのメッセージループに代わる処理を行う
func ProcessMessage() int {
	return int(C.goProcessMessage())
}

// Ｚバッファを使用するかどうかを設定する( ３Ｄ描画のみに影響 )( TRUE:Ｚバッファを使用する  FALSE:Ｚバッファを使用しない( デフォルト ) )
func SetUseZBuffer3D(Flag int) int {
	return int(C.goSetUseZBuffer3D(C.int(Flag)))
}

// Ｚバッファに書き込みを行うかどうかを設定する( ３Ｄ描画のみに影響 )( TRUE:書き込みを行う  FALSE:書き込みを行わない( デフォルト ) )
func SetWriteZBuffer3D(Flag int) int {
	return int(C.goSetWriteZBuffer3D(C.int(Flag)))
}

// VECTOR ...
type VECTOR struct {
	x float32
	y float32
	z float32
}

// ベクトル値の生成
func VGet(x, y, z float32) VECTOR {
	v := C.goVGet(C.float(x), C.float(y), C.float(z))
	return VECTOR{
		x: float32(v.x),
		y: float32(v.y),
		z: float32(v.z),
	}
}

// ３Ｄの円錐を描画する
func DrawCone3D(TopPos, BottomPos VECTOR, r float32, DivNum int, DifColor, SpcColor uint32, FillFlag int) int {
	tp := C.struct_tagVECTOR{
		x: C.float(TopPos.x),
		y: C.float(TopPos.y),
		z: C.float(TopPos.z),
	}
	bp := C.struct_tagVECTOR{
		x: C.float(BottomPos.x),
		y: C.float(BottomPos.y),
		z: C.float(BottomPos.z),
	}
	return int(C.goDrawCone3D(tp, bp, C.float(r), C.int(DivNum), C.uint(DifColor), C.uint(SpcColor), C.int(FillFlag)))
}

func Sample() int {
	return int(C.goSample())
}
