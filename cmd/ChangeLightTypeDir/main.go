package main

import (
	"os"

	. "github.com/sago35/go-dxlib"
)

func main() {
	var ModelHandle int

	ChangeWindowMode(TRUE)

	// ＤＸライブラリの初期化
	if DxLib_Init() < 0 {
		// エラーが発生したら直ちに終了
		os.Exit(-1)
	}

	// モデルの読み込み
	//ModelHandle = MV1LoadModel( "SimpleModel.mqo" ) ;
	ModelHandle = MV1LoadModel("go_gopher_high.x")

	// マウスを表示状態にする
	SetMouseDispFlag(TRUE)

	for CheckHitKeyAll(DX_CHECKINPUT_ALL) == 0 {
		// マウスの位置を取得
		var MouseX, MouseY int
		GetMousePoint(&MouseX, &MouseY)

		var x, y, z float32
		x = float32(MouseX-320) / 6400
		y = float32(MouseY-240) / 4800
		z = -0.01

		// Ｘ軸のマイナス方向のディレクショナルライトに変更
		ChangeLightTypeDir(VGet(x, y, z))

		// モデルをカメラの映る位置に移動
		MV1SetPosition(ModelHandle, VGet(320.0, 240.0, 0.0))

		MV1SetMaterialAmbColor(ModelHandle, 0, GetColorF(0.1, 0.1, 0.5, 1.0))
		// モデルを描画
		MV1DrawModel(ModelHandle)

		WaitTimer(100)
	}

	// モデルハンドルの削除
	MV1DeleteModel(ModelHandle)

	// キー入力待ち
	WaitKey()

	// ＤＸライブラリの後始末
	DxLib_End()

	// ソフトの終了
	os.Exit(0)
}
