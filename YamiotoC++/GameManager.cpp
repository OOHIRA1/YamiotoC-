#include "GameManager.h"

//---------------------------------------------
//--コンストラクタ・デストラクタ
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
	_sceneManager->Main( );
	//-------------------------------------------------------------------------------

	//_gameStatus変更処理(_gameStatus変更時にデータ引き継ぎ・メモリの解放を行う)---------------------
	if ( _sceneManager->GetSceneChangeFlag( ) ) {
		SceneManager* nextSceneManager = NULL;
		switch( _gameStatus ) {
		case GAME_START:
				_gameStatus = GAME_MAIN;
				nextSceneManager = new GameMainManager( &_drawer, &_inputChecker, &_sounder );
			break;
		case GAME_MAIN:
				_gameStatus = GAME_RESULT;
				//Player* player = dynamic_cast<GameMainManager*>( _sceneManager )->GetPlayer( );	//deleteする前にplayerのデータを受け継ぐ
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

	//_inputChecker.UpdateDevice( );	//main.cppで行っているのでやらなくてよい
}