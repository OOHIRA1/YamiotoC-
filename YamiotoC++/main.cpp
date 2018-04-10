#include <DXLib.h>
#include "WindowInformation.h"
#include "GameManager.h"

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdshow ) {
	SetWindowText( "闇音" );
	Sounder::Set3DSoundOneMetre( 0.2f );
	ChangeWindowMode( TRUE );
	SetAlwaysRunFlag( TRUE );							//別のウィンドウに切り替えても処理が継続される関数
	SetWindowSize( SCREEN_WIDTH, SCREEN_HEIGHT );
	SetGraphMode( SCREEN_WIDTH, SCREEN_HEIGHT, 32 );	//画像の解像度を設定する関数
	SetEnableXAudioFlag( TRUE );						//サウンドの再生にXAudio2を使用するかどうかを設定する
	if ( DxLib_Init( ) == -1 ) {
		return -1;
	}

	GameManager gameManager;

	while( 1 ) {
		if ( ScreenFlip( ) != 0 || ProcessMessage( ) != 0 || ClearDrawScreen( ) != 0 ) {
			break;
		}

		gameManager.Main( );
		gameManager.GetInputChecker( )->UpdateDevice( );	//キー・パット入力受付
		if ( gameManager.GetInputChecker( )->GetKey( KEY_INPUT_ESCAPE ) > 1 ) {		//escapeキーを押したら強制終了
			break;
		}
	}

	DxLib_End( );
	return 0;
}