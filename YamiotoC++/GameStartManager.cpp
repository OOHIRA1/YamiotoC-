#include "GameStartManager.h"


//--------------------------------------------
//コンストラクタ・デストラクタ
GameStartManager::GameStartManager( ) {
	_sounded = false;
	_changeSceneFlag = false;
}


GameStartManager::~GameStartManager( ) {
}
//---------------------------------------------
//--------------------------------------------


//--------------------------------------------
//ゲッター
bool GameStartManager::GetSceneChangeFlag( ) {
	return _changeSceneFlag;
}
//--------------------------------------------
//--------------------------------------------


//--------------------------------------------
//セッター
void GameStartManager::SetSceneChangeFlag( bool x ) {
	_changeSceneFlag = x;
}
//--------------------------------------------
//--------------------------------------------


//--メイン関数
void GameStartManager::Main( ) {
	int handle = _sounder.GetSoundDataManager( ).GetSoundHandle( GAME_START_BGM );
	if ( !_sounder.CheckSoundMem( handle ) && !_sounded ) {
		_sounder.ChangeVolumeSoundMem( handle, 100 );
		_sounder.PlaySoundMem( handle, DX_PLAYTYPE_LOOP, TRUE );
		_sounded = true;
	}
}