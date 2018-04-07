#include "GameManager.h"

//---------------------------------------------
//--�R���X�g���N�^�E�f�X�g���N�^
GameManager::GameManager( ) {
	_gameStartManager  = new GameStartManager;
	_gameMainManager   = NULL;
	_gameResultManager = NULL;
	_gameStatus = GAME_START;
}


GameManager::~GameManager( ) {
	switch( _gameStatus ) {
	case GAME_START:
		delete( _gameStartManager );
		break;
	case GAME_MAIN:
		delete( _gameMainManager );
		break;
	case GAME_RESULT:
		delete( _gameResultManager );
		break;
	default:
		break;
	}
}
//---------------------------------------------
//---------------------------------------------


//-----------------------------------
//--�Q�b�^�[
//-----------------------------------
//-----------------------------------


//-----------------------------------
//--�Z�b�^�[
//-----------------------------------
//-----------------------------------


//--���C���֐�
void GameManager::Main( ) {
	//�e�V�[���ւ̖��ߏ���-----------------------------------------------------------
	switch( _gameStatus ) {
	case GAME_START:
		if ( !_gameStartManager ) _gameStartManager = new GameStartManager;
		_gameStartManager->Main( );
		break;
	case GAME_MAIN:
		if ( !_gameMainManager ) _gameMainManager = new GameMainManager;
		_gameMainManager->Main( );
		break;
	case GAME_RESULT:
		if ( !_gameResultManager ) _gameResultManager = new GameResultManager;
		_gameResultManager->Main( );
		break;
	default :
		break;
	}
	//-------------------------------------------------------------------------------

	//_gameStatus�ύX����(_gameStatus�ύX���Ƀ������̉�����s��)---------------------
	switch( _gameStatus ) {
	case GAME_START:
		if ( _gameStartManager->GetSceneChangeFlag( ) ) {
			_gameStatus = GAME_MAIN;
			delete( _gameStartManager );
			_gameStartManager = NULL;
		}
		break;
	case GAME_MAIN:
		if ( _gameMainManager->GetSceneChangeFlag( ) ) {
			_gameStatus = GAME_RESULT;
			delete( _gameMainManager );
			_gameMainManager = NULL;
		}
		break;
	case GAME_RESULT:
		if ( _gameResultManager->GetSceneChangeFlag( ) ) {
			_gameStatus = GAME_START;
			delete( _gameResultManager );
			_gameResultManager = NULL;
		}
		break;
	}
	//-------------------------------------------------------------------------------
}