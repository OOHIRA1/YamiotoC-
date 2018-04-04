#include <DXLib.h>
#include "InputChecker.h"

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdshow ) {
	ChangeWindowMode( TRUE );

	if ( DxLib_Init( ) == -1 ) {
		return -1;
	}

	InputChecker inputChecker;

	while( 1 ) {
		if ( ScreenFlip( ) != 0 || ProcessMessage( ) != 0 || ClearDrawScreen( ) != 0 ) {
			break;
		}

		inputChecker.UpdateDevice( );	//�L�[�E�p�b�g���͎�t
		if ( inputChecker.GetKey( KEY_INPUT_ESCAPE ) > 1 ) {	//escape�L�[���������狭���I��
			break;
		}
	}

	DxLib_End( );
	return 0;
}