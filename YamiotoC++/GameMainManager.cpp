#include "GameMainManager.h"


//---------------------------------------
//--�R���X�g���N�^�E�f�X�g���N�^
GameMainManager::GameMainManager( ) {
	_sceneChangeFlag = false;
}


GameMainManager::~GameMainManager( ) {
}
//----------------------------------------
//----------------------------------------


//---------------------------------------
//--�Q�b�^�[
bool GameMainManager::GetSceneChangeFlag( ) {
	return _sceneChangeFlag;
}
//---------------------------------------
//---------------------------------------


//---------------------------------------
//--�Z�b�^�[
void GameMainManager::SetSceneChangeFlag( bool x ) {
	_sceneChangeFlag = x;
}
//---------------------------------------
//---------------------------------------


//--���C���֐�
void GameMainManager::Main( ) {
	if ( GetSceneChangeFlag( ) ) return;

	_inputChecker.UpdateDevice( );
	if ( _inputChecker.GetKey( KEY_INPUT_RETURN ) == 1 ) SetSceneChangeFlag( true );

	DrawString( 0,100,"MainScene", 0xff0000 );
}