#include "GameStartManager.h"


//--------------------------------------------
//�R���X�g���N�^�E�f�X�g���N�^
GameStartManager::GameStartManager( ) {
	_sounded = false;
	_changeSceneFlag = false;
}


GameStartManager::~GameStartManager( ) {
}
//---------------------------------------------
//--------------------------------------------


//--------------------------------------------
//�Q�b�^�[
bool GameStartManager::GetSceneChangeFlag( ) {
	return _changeSceneFlag;
}
//--------------------------------------------
//--------------------------------------------


//--------------------------------------------
//�Z�b�^�[
void GameStartManager::SetSceneChangeFlag( bool x ) {
	_changeSceneFlag = x;
}
//--------------------------------------------
//--------------------------------------------


//--���C���֐�
void GameStartManager::Main( ) {
	int handle = _sounder.GetSoundDataManager( ).GetSoundHandle( GAME_START_BGM );
	if ( !_sounder.CheckSoundMem( handle ) && !_sounded ) {
		_sounder.ChangeVolumeSoundMem( handle, 100 );
		_sounder.PlaySoundMem( handle, DX_PLAYTYPE_LOOP, TRUE );
		_sounded = true;
	}
}