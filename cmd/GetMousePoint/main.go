package main

import (
	"fmt"
	"os"

	. "github.com/sago35/go-dxlib"
)

func main() {
	var StrBuf string
	var MouseX, MouseY int
	var StringCr, BoxCr uint32

	// ＤＸライブラリ初期化処理
	if DxLib_Init() == -1 {
		// エラーが発生したら終了
		os.Exit(-1)
	}

	// マウスを表示状態にする
	SetMouseDispFlag(TRUE)

	// 白色の値を取得
	StringCr = GetColor(255, 255, 255)

	// 黒の値を取得
	BoxCr = GetColor(0, 0, 0)

	// キーが押されるまでループ
	for CheckHitKeyAll(DX_CHECKINPUT_ALL) == 0 {
		// マウスの位置を取得
		GetMousePoint(&MouseX, &MouseY)

		// 表示する文字列を作成
		StrBuf = fmt.Sprintf("座標 Ｘ%d　Ｙ %d", MouseX, MouseY)

		// 画面左上の領域に黒い四角を描き前に描いてあった文字列を消す
		DrawBox(0, 0, 200, 32, BoxCr, TRUE)

		// 座標文字列を描く
		DrawString(0, 0, StrBuf, StringCr, 0)

		// メッセージ処理
		if ProcessMessage() == -1 {
			// エラーが起きたらループを抜ける
			break
		}

		// 一定時間待つ
		WaitTimer(100)
	}

	// ＤＸライブラリ使用の終了処理
	DxLib_End()

	// ソフトの終了
	os.Exit(0)
}
