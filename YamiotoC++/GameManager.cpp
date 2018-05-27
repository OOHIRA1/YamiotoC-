#include "GameManager.h"

//---------------------------------------------
//--�R���X�g���N�^�E�f�X�g���N�^
GameManager::GameManager( ) {
	_sceneManager = new GameStartManager( &_drawer, &_inputChecker, &_sounder );
	_gameStatus = GAME_START;
}


GameManager::~GameManager( ) {
	delete( _sceneManager );
}
//---------------------------------------------
//---------------------------------------------


//-----------------------------------
//--�Q�b�^�[
InputChecker* GameManager::GetInputChecker( ) {
	return &_inputChecker;
}
//-----------------------------------
//-----------------------------------


//-----------------------------------
//--�Z�b�^�[
//-----------------------------------
//-----------------------------------


//--���C���֐�
void GameManager::Main( ) {
	//�e�V�[���ւ̖��ߏ���-----------------------------------------------------------
	_sceneManager->Main( );
	//-------------------------------------------------------------------------------

	//_gameStatus�ύX����(_gameStatus�ύX���Ƀf�[�^�����p���E�������̉�����s��)---------------------
	if ( _sceneManager->GetSceneChangeFlag( ) ) {
		SceneManager* nextSceneManager = NULL;
		switch( _gameStatus ) {
		case GAME_START:
				_gameStatus = GAME_MAIN;
				nextSceneManager = new GameMainManager( &_drawer, &_inputChecker, &_sounder );
			break;
		case GAME_MAIN:
				_gameStatus = GAME_RESULT;
				//Player* player = dynamic_cast<GameMainManager*>( _sceneManager )->GetPlayer( );	//delete����O��player�̃f�[�^���󂯌p��
				nextSceneManager = new GameResultManager( &_drawer, &_inputChecker, &_sounder, dynamic_cast<GameMainManager*>( _sceneManager )->GetPlayer( ) );
			break;
		case GAME_RESULT:
				_gameStatus = GAME_START;
				nextSceneManager = new GameStartManager( &_drawer, &_inputChecker, &_sounder );
			break;
		}
		delete( _sceneManager );
		_sceneManager = nextSceneManager;
		

	}
	//-----------------------------------------------------------------------------------------------

	//_inputChecker.UpdateDevice( );	//main.cpp�ōs���Ă���̂ł��Ȃ��Ă悢
}