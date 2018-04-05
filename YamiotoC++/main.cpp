#include <DXLib.h>
#include "InputChecker.h"
#include "Sounder.h"
#include "GameStartManager.h"

const int SCREEN_WIDTH			= 1280;					//ウィンドウの横幅
const int SCREEN_HEIGHT		    = 720;					//ウィンドウの縦幅
const int SCREEN_WIDTH_CENTER	= 1280 / 2;				//ウィンドウ中心x座標
const int SCREEN_HEIGHT_CENTER  = 720 / 2;				//ウィンドウ中心y座標

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdshow ) {
	SetWindowText( "闇音" );
	Sounder sounder;
	sounder.Set3DSoundOneMetre( 0.2f );
	ChangeWindowMode( TRUE );
	SetAlwaysRunFlag( TRUE );							//別のウィンドウに切り替えても処理が継続される関数
	SetWindowSize( SCREEN_WIDTH, SCREEN_HEIGHT );
	SetGraphMode( SCREEN_WIDTH, SCREEN_HEIGHT, 32 );	//画像の解像度を設定する関数
	SetEnableXAudioFlag( TRUE );						//サウンドの再生にXAudio2を使用するかどうかを設定する
	if ( DxLib_Init( ) == -1 ) {
		return -1;
	}


	InputChecker inputChecker;
	GameStartManager start;


	while( 1 ) {
		if ( ScreenFlip( ) != 0 || ProcessMessage( ) != 0 || ClearDrawScreen( ) != 0 ) {
			break;
		}
		start.Main();
		inputChecker.UpdateDevice( );	//キー・パット入力受付
		if ( inputChecker.GetKey( KEY_INPUT_ESCAPE ) > 1 ) {	//escapeキーを押したら強制終了
			break;
		}
	}

	DxLib_End( );
	return 0;
}