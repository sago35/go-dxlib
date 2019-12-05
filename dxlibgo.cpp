#include "DxLib.h"


extern "C" {
    int goDxLib_Init( void ) {
        return DxLib_Init();
    }

    int goDxLib_End( void ) {
        return DxLib_End();
    }

    int goDrawPixel( int x, int y, unsigned int Color ) {
        return DrawPixel(x, y, Color);
    }

    unsigned int goGetColor( int Red, int Green, int Blue ) {
        return GetColor(Red, Green, Blue);
    }

    int goWaitKey( void ) {
        return WaitKey();
    }

    int goSetDrawScreen( int DrawScreen ) {
        return SetDrawScreen(DrawScreen);
    }

    int goGetRand( int RandMax ) {
        return GetRand(RandMax);
    }

    int goDrawBox( int x1, int y1, int x2, int y2, unsigned int Color, int FillFlag ) {
        return DrawBox(x1, y1, x2, y2, Color, FillFlag);
    }

    int goClearDrawScreen( const RECT *ClearRect ) {
        return ClearDrawScreen(ClearRect);
    }

    int goScreenFlip( void ) {
        return ScreenFlip();
    }


    int goSetMouseDispFlag( int DispFlag ) {
        return SetMouseDispFlag(DispFlag);
    }

    int goCheckHitKeyAll( int CheckType ) {
        return CheckHitKeyAll(CheckType);
    }

    int goWaitTimer( int WaitTime ) {
        return WaitTimer(WaitTime);
    }

    int goGetMousePoint( int *XBuf, int *YBuf ) {
        return GetMousePoint(XBuf, YBuf);
    }

    int goDrawString( int x, int y, const TCHAR *String, unsigned int Color, unsigned int EdgeColor ) {
        return DrawString(x, y, String, Color, EdgeColor);
    }

    int goProcessMessage( void ) {
        return ProcessMessage();
    }

    int goSetUseZBuffer3D( int Flag ) {
        return SetUseZBuffer3D(Flag);
    }

    int goSetWriteZBuffer3D( int Flag ) {
        return SetWriteZBuffer3D(Flag);
    }

    VECTOR goVGet( float x, float y, float z )
    {
        VECTOR Result;
        Result.x = x ;
        Result.y = y ;
        Result.z = z ;
        return Result ;
    }

    int goDrawCone3D( VECTOR TopPos, VECTOR BottomPos, float r, int DivNum, unsigned int DifColor, unsigned int SpcColor, int FillFlag ) {
        return DrawCone3D(TopPos, BottomPos, r, DivNum, DifColor, SpcColor, FillFlag);
    }

    int goMV1LoadModel( const TCHAR *FileName ) {
        return MV1LoadModel(FileName);
    }

    int goChangeLightTypeDir( VECTOR Direction ) {
        return ChangeLightTypeDir(Direction);
    }

    int goMV1SetPosition( int MHandle, VECTOR Position ) {
        return MV1SetPosition(MHandle, Position);
    }

    int goMV1DrawModel( int MHandle ) {
        return MV1DrawModel(MHandle);
    }
    int goMV1DeleteModel( int MHandle ) {
        return MV1DeleteModel(MHandle);
    }

    int goChangeWindowMode( int Flag ) {
        return ChangeWindowMode(Flag);
    }

    COLOR_F goGetColorF( float Red, float Green, float Blue, float Alpha ) {
        return GetColorF(Red, Green, Blue, Alpha);
    }

    int goMV1SetMaterialAmbColor( int MHandle, int MaterialIndex, COLOR_F Color ) {
        return MV1SetMaterialAmbColor(MHandle, MaterialIndex, Color);
    }

    int goSample( void ) {

        int ModelHandle ;

        // ＤＸライブラリの初期化
        if( DxLib_Init() < 0 )
        {
            // エラーが発生したら直ちに終了
            return -1 ;
        }

        // ３Ｄモデルの読み込み
        //ModelHandle = MV1LoadModel( "DxChara.x" ) ;
        ModelHandle = MV1LoadModel( "go_gopher_high.x" ) ;

        // 画面に映る位置に３Ｄモデルを移動
        MV1SetPosition( ModelHandle, VGet( 320.0f, -300.0f, 600.0f ) ) ;

        // ３Ｄモデルに含まれる０番目のマテリアルのアンビエントカラーを紫色にします
        MV1SetMaterialAmbColor( ModelHandle, 0, GetColorF( 0.4f, 0.4f, 1.0f, 1.0f ) ) ;

        // ３Ｄモデルの描画
        MV1DrawModel( ModelHandle ) ;

        // モデルハンドルの削除
        MV1DeleteModel( ModelHandle ) ;

        // キーの入力待ち
        WaitKey() ;

        // ＤＸライブラリの後始末
        DxLib_End() ;

        // ソフトの終了
        return 0 ;
    }
}
