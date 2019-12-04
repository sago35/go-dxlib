package main

import (
	"os"

	. "github.com/sago35/go-dxlib"
)

func main() {
	// ＤＸライブラリの初期化
	if DxLib_Init() < 0 {
		// エラーが発生したら直ちに終了
		os.Exit(-1)
	}

	// Ｚバッファを有効にする
	SetUseZBuffer3D(TRUE)

	// Ｚバッファへの書き込みを有効にする
	SetWriteZBuffer3D(TRUE)

	// ３Ｄ空間上に円錐を描画する
	DrawCone3D(VGet(320.0, 400.0, 0.0), VGet(320.0, 100.0, 0.0), 80.0, 16, GetColor(0, 0, 255), GetColor(255, 255, 255), TRUE)

	// キー入力待ちをする
	WaitKey()

	// ＤＸライブラリの後始末
	DxLib_End()

	// ソフトの終了
	os.Exit(0)
}
