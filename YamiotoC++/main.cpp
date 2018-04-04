#include "DXLib.h"

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdshow ) {
	ChangeWindowMode( TRUE );

	if ( DxLib_Init( ) == -1 ) {
		return -1;
	}

	while( 1 ) {
		if ( ScreenFlip( ) != 0 || ProcessMessage( ) != 0 || ClearDrawScreen( ) != 0 ) {
			break;
		}
	}

	DxLib_End( );
	return 0;
}