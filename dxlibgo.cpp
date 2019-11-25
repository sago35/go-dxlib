#include "DxLib_GCC3_21b/8_2_0/DxLib.h"


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
}
