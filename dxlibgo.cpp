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
}
