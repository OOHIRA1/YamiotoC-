#include "GameManager.h"

//---------------------------------------------
//--コンストラクタ・デストラクタ
GameManager::GameManager( ) {
	_gameStartManager  = new GameStartManager( &_drawer, &_inputChecker, &_sounder );
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
//--ゲッター
InputChecker* GameManager::GetInputChecker( ) {
	return &_inputChecker;
}
//-----------------------------------
//-----------------------------------


//-----------------------------------
//--セッター
//-----------------------------------
//-----------------------------------


//--メイン関数
void GameManager::Main( ) {
	//各シーンへの命令処理-----------------------------------------------------------
	switch( _gameStatus ) {
	case GAME_START:
		_gameStartManager->Main( );
		break;
	case GAME_MAIN:
		_gameMainManager->Main( );
		break;
	case GAME_RESULT:
		_gameResultManager->Main( );
		break;
	default :
		break;
	}
	//-------------------------------------------------------------------------------

	//_gameStatus変更処理(_gameStatus変更時にデータ引き継ぎ・メモリの解放を行う)---------------------
	switch( _gameStatus ) {
	case GAME_START:
		if ( _gameStartManager->GetSceneChangeFlag( ) ) {
			_gameStatus = GAME_MAIN;
			_gameMainManager = new GameMainManager( &_drawer, &_inputChecker, &_sounder );
			delete( _gameStartManager );
			_gameStartManager = NULL;
		}
		break;
	case GAME_MAIN:
		if ( _gameMainManager->GetSceneChangeFlag( ) ) {
			_gameStatus = GAME_RESULT;
			_gameResultManager = new GameResultManager( &_drawer, &_inputChecker, &_sounder, _gameMainManager->GetPlayer( ) );
			delete( _gameMainManager );
			_gameMainManager = NULL;
		}
		break;
	case GAME_RESULT:
		if ( _gameResultManager->GetSceneChangeFlag( ) ) {
			_gameStatus = GAME_START;
			_gameStartManager = new GameStartManager( &_drawer, &_inputChecker, &_sounder );
			delete( _gameResultManager );
			_gameResultManager = NULL;
		}
		break;
	}
	//-----------------------------------------------------------------------------------------------
	//_inputChecker.UpdateDevice( );
}