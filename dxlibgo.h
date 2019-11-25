extern	int			goDxLib_Init( void ) ;													// ライブラリ初期化を行う
extern	int			goDxLib_End( void ) ;														// ライブラリ使用の後始末を行う

extern	int			goDxLib_GlobalStructInitialize( void ) ;									// ライブラリの内部で使用している構造体をゼロ初期化して、DxLib_Init の前に行った設定を無効化する( DxLib_Init の前でのみ有効 )
extern	int			goDxLib_IsInit( void ) ;													// ライブラリが初期化されているかどうかを取得する( 戻り値: TRUE=初期化されている  FALSE=されていない )

extern 	int			goDrawPixel(        int   x,  int   y,                                                              unsigned int Color ) ;													// 点を描画する
extern	unsigned int	goGetColor(                int Red, int Green, int Blue ) ;																		// DrawPixel 等の描画関数で使用するカラー値を取得する
extern	int			goWaitKey( void ) ;														// キーの入力待ちを行う

extern	int				goSetDrawScreen(								int DrawScreen ) ;																// 描画先画面を設定する( MakeScreen で作成したグラフィックハンドルも渡すことができます )

// 描画先画面指定用定義
#define DX_SCREEN_FRONT								(0xfffffffc)
#define DX_SCREEN_BACK								(0xfffffffe)
#define DX_SCREEN_WORK 								(0xfffffffd)
#define DX_SCREEN_TEMPFRONT							(0xfffffff0)
#define DX_SCREEN_OTHER								(0xfffffffa)

extern	int			goGetRand( int RandMax ) ;												// 乱数を取得する( RandMax : 返って来る値の最大値 )
extern	int			goDrawBox(          int   x1, int   y1, int   x2, int   y2,                                         unsigned int Color, int FillFlag ) ;										// 四角形を描画する
extern	int				goClearDrawScreen(					        const RECT *ClearRect ) ;												// 画面をクリアする
extern	int				goScreenFlip(									void ) ;																		// 裏画面と表画面の内容を交換する
