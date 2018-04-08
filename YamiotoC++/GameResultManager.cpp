#include "GameResultManager.h"


//-------------------------------------------------------
//--�R���X�g���N�^�E�f�X�g���N�^
GameResultManager::GameResultManager( ) {
	_sceneChangeFlag = false;
}


GameResultManager::~GameResultManager( ) {
}
//-------------------------------------------------------
//-------------------------------------------------------


//--------------------------------------------
//--�Q�b�^�[
bool GameResultManager::GetSceneChangeFlag( ) {
	return _sceneChangeFlag;
}
//--------------------------------------------
//--------------------------------------------


//--------------------------------------------
//--�Z�b�^�[
void GameResultManager::SetSceneChangeFlag( bool x ) {
	_sceneChangeFlag = x;
}
//--------------------------------------------
//--------------------------------------------


void GameResultManager::Main( ) {
	if ( GetSceneChangeFlag( ) ) return;	//�V�[���J�ڃt���O�������Ă��鎞�͏��������Ȃ�

	_inputChecker.UpdateDevice( );
	if ( _inputChecker.GetKey( KEY_INPUT_2 ) == 1 ) SetSceneChangeFlag( true );

	DrawFormatString( 0,0,0xffffff, "ResultScene" );
}