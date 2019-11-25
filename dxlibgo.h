extern	int			goDxLib_Init( void ) ;													// ライブラリ初期化を行う
extern	int			goDxLib_End( void ) ;														// ライブラリ使用の後始末を行う

extern	int			goDxLib_GlobalStructInitialize( void ) ;									// ライブラリの内部で使用している構造体をゼロ初期化して、DxLib_Init の前に行った設定を無効化する( DxLib_Init の前でのみ有効 )
extern	int			goDxLib_IsInit( void ) ;													// ライブラリが初期化されているかどうかを取得する( 戻り値: TRUE=初期化されている  FALSE=されていない )

extern 	int			goDrawPixel(        int   x,  int   y,                                                              unsigned int Color ) ;													// 点を描画する
extern	unsigned int	goGetColor(                int Red, int Green, int Blue ) ;																		// DrawPixel 等の描画関数で使用するカラー値を取得する
extern	int			goWaitKey( void ) ;														// キーの入力待ちを行う
