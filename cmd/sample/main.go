package main

import (
	"os"

	. "github.com/sago35/go-dxlib"
)

func main() {
	// ＤＸライブラリ初期化処理
	if DxLib_Init() == -1 {
		// エラーが起きたら直ちに終了
		os.Exit(-1)
	}

	// 点を打つ
	DrawPixel(320, 240, GetColor(255, 255, 255))

	// キー入力待ち
	WaitKey()

	// ＤＸライブラリ使用の終了処理
	DxLib_End()

	// ソフトの終了
	os.Exit(0)
}
