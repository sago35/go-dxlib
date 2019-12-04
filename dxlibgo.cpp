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

    int goSample( void ) {
        // ＤＸライブラリの初期化
        if( DxLib_Init() < 0 )
        {
            // エラーが発生したら直ちに終了
            return -1 ;
        }

        // Ｚバッファを有効にする
        SetUseZBuffer3D( TRUE ) ;

        // Ｚバッファへの書き込みを有効にする
        SetWriteZBuffer3D( TRUE ) ;

        // ３Ｄ空間上に円錐を描画する
        DrawCone3D( VGet( 320.0f, 400.0f, 0.0f ), VGet( 320.0f, 100.0f, 0.0f ), 80.0f, 16, GetColor( 0,0,255 ), GetColor( 255,255,255 ), TRUE ) ;

        // キー入力待ちをする
        WaitKey() ;

        // ＤＸライブラリの後始末
        DxLib_End() ;

        // ソフトの終了
        return 0 ;
    }
}
