#include "GameMainManager.h"


//---------------------------------------
//--コンストラクタ・デストラクタ
GameMainManager::GameMainManager( ) {
	_sceneChangeFlag = false;
}


GameMainManager::~GameMainManager( ) {
}
//----------------------------------------
//----------------------------------------


//---------------------------------------
//--ゲッター
bool GameMainManager::GetSceneChangeFlag( ) {
	return _sceneChangeFlag;
}
//---------------------------------------
//---------------------------------------


//---------------------------------------
//--セッター
void GameMainManager::SetSceneChangeFlag( bool x ) {
	_sceneChangeFlag = x;
}
//---------------------------------------
//---------------------------------------


//--メイン関数
void GameMainManager::Main( ) {
	if ( GetSceneChangeFlag( ) ) return;

	_inputChecker.UpdateDevice( );
	if ( _inputChecker.GetKey( KEY_INPUT_RETURN ) == 1 ) SetSceneChangeFlag( true );

	DrawString( 0,100,"MainScene", 0xff0000 );
}