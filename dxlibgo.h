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

extern	int			goSetMouseDispFlag(		int DispFlag ) ;												// マウスポインタの表示状態を設定する( DispFlag:マウスポインタを表示するかどうか( TRUE:表示する  FALSE:表示しない )
extern	int			goCheckHitKeyAll(							int CheckType ) ;									// どれか一つでもキーが押されているかどうかを取得( 押されていたら戻り値が 0 以外になる )
extern	int			goWaitTimer( int WaitTime ) ;												// 指定の時間だけ処理をとめる
extern	int			goGetMousePoint(			int *XBuf, int *YBuf ) ;										// マウスポインタの位置を取得する
extern	int			goDrawString(                             int x, int y,                                              const TCHAR *String,                      unsigned int Color, unsigned int EdgeColor ) ;							// デフォルトフォントハンドルを使用して文字列を描画する
extern	int			goProcessMessage( void ) ;												// ウインドウズのメッセージループに代わる処理を行う
extern	int			goSetUseZBuffer3D(					int Flag ) ;													// Ｚバッファを使用するかどうかを設定する( ３Ｄ描画のみに影響 )( TRUE:Ｚバッファを使用する  FALSE:Ｚバッファを使用しない( デフォルト ) )
extern	int			goSetWriteZBuffer3D(					int Flag ) ;													// Ｚバッファに書き込みを行うかどうかを設定する( ３Ｄ描画のみに影響 )( TRUE:書き込みを行う  FALSE:書き込みを行わない( デフォルト ) )

// ベクトルデータ型
typedef struct tagVECTOR
{
	float					x, y, z ;
} VECTOR, *LPVECTOR, FLOAT3, *LPFLOAT3 ;

extern VECTOR goVGet( float x, float y, float z ); // ベクトル値の生成
extern	int			goDrawCone3D(      VECTOR   TopPos, VECTOR   BottomPos, float  r, int DivNum, unsigned int DifColor, unsigned int SpcColor, int FillFlag ) ;		// ３Ｄの円錐を描画する
extern	int			goMV1LoadModel(						const TCHAR *FileName ) ;											// モデルの読み込み( -1:エラー  0以上:モデルハンドル )
extern	int			goChangeLightTypeDir(			VECTOR Direction ) ;															// デフォルトライトのタイプをディレクショナルライトにする
extern	int			goMV1SetPosition(						int MHandle, VECTOR   Position ) ;									// モデルの座標をセット
extern	int			goMV1DrawModel(						int MHandle ) ;														// モデルを描画する
extern	int			goMV1DeleteModel(						int MHandle ) ;														// モデルを削除する

extern	int			goChangeWindowMode(						int Flag ) ;																		// ウインドウモードを変更する


// float 型のカラー値
typedef struct tagCOLOR_F
{
    float					r, g, b, a ;
} COLOR_F, *LPCOLOR_F ;
extern	COLOR_F			goGetColorF(               float Red, float Green, float Blue, float Alpha ) ;													// 浮動小数点型のカラー値を作成する
extern	int			goMV1SetMaterialAmbColor( 			int MHandle, int MaterialIndex, COLOR_F Color ) ;						// 指定のマテリアルのアンビエントカラーを設定する

extern int goSample();
