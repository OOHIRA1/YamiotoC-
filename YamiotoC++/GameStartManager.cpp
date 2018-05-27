#include "GameStartManager.h"
#include "WindowInformation.h"


//--------------------------------------------
//コンストラクタ・デストラクタ
GameStartManager::GameStartManager( Drawer* drawer, InputChecker* inputChecker, Sounder* sounder ) :SceneManager( drawer, inputChecker, sounder ){
	_BGMsounded = false;
	_pushed = false;
}


GameStartManager::~GameStartManager( ) {
	_drawer->SetAlpha( 255 );	//フェードアウト後のアルファ値を元に戻す
	_drawer->SetDrawBlendMode( DX_BLENDMODE_ALPHA, _drawer->GetAlpha( ) );
}
//---------------------------------------------
//--------------------------------------------


//--------------------------------------------
//--ゲッター
//--------------------------------------------
//--------------------------------------------


//--------------------------------------------
//--セッター
//--------------------------------------------
//--------------------------------------------

//--メイン関数
void GameStartManager::Main( ) {
	if ( GetSceneChangeFlag( ) ) return;	//シーン遷移フラグが立っている時は処理をしない

	//スタート画面のBGMを流す処理---------------------------------------------------
	int soundHandle = _sounder->GetSoundDataManager( ).GetSoundHandle( GAME_START_BGM );
	if ( !_BGMsounded ) {
		_sounder->ChangeVolumeSoundMem( soundHandle, 100 );
		_sounder->PlaySoundMem( soundHandle, DX_PLAYTYPE_LOOP, TRUE );
		_BGMsounded = true;
	}
	//------------------------------------------------------------------------------

	//タイトル表示------------------------------------------------------------------
	int grHandle  = _drawer->GetImageManager( ).GetResourceHandle( YAMIOTO_TEXT );
	int grHandle2 = _drawer->GetImageManager( ).GetResourceHandle( PUSH_BUTTON_TEXT );
	_drawer->DrawGraph( SCREEN_WIDTH_CENTER - 148, SCREEN_HEIGHT_CENTER - 100, grHandle, TRUE );
	if ( !_pushed ) {
		_drawer->FlashGraph( SCREEN_WIDTH_CENTER - 80, SCREEN_HEIGHT_CENTER + 100, grHandle2 );
	}
	//------------------------------------------------------------------------------

	//キー受付----------------------------------------------------------------------
	//_inputChecker->UpdateDevice( );	//main.cppで行っているのでやらなくてよい

	int soundHandle2 = _sounder->GetSoundDataManager( ).GetSoundHandle( GAME_START_SE );
	if ( _inputChecker->GetKey( KEY_INPUT_RETURN ) == 1 ||
		_inputChecker->GetJoypad( INPUT_1 ) == 1        ||
		_inputChecker->GetJoypad( INPUT_2 ) == 1        ||
		_inputChecker->GetJoypad( INPUT_3 ) == 1        ||
		_inputChecker->GetJoypad( INPUT_4 ) == 1
		) {
		_sounder->StopSoundMem( soundHandle );
		_sounder->ChangeVolumeSoundMem( 80, soundHandle2 );
		_sounder->PlaySoundMem( soundHandle2 , DX_PLAYTYPE_BACK, TRUE );
		_pushed = true;
	}
	//------------------------------------------------------------------------------

	//キー入力後の処理--------------------------------------------------------------
	if ( _pushed ) {
		_drawer->FadeOut( );

		if ( _drawer->GetAlpha( ) <= 0 ) {
			_sounder->StopSoundMem( soundHandle2 );
			SetSceneChangeFlag( true );
		}
	}
	//------------------------------------------------------------------------------
}