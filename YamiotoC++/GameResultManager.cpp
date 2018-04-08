#include "GameResultManager.h"


//-------------------------------------------------------
//--コンストラクタ・デストラクタ
GameResultManager::GameResultManager( ) {
	_sceneChangeFlag = false;
}


GameResultManager::~GameResultManager( ) {
}
//-------------------------------------------------------
//-------------------------------------------------------


//--------------------------------------------
//--ゲッター
bool GameResultManager::GetSceneChangeFlag( ) {
	return _sceneChangeFlag;
}
//--------------------------------------------
//--------------------------------------------


//--------------------------------------------
//--セッター
void GameResultManager::SetSceneChangeFlag( bool x ) {
	_sceneChangeFlag = x;
}
//--------------------------------------------
//--------------------------------------------


void GameResultManager::Main( ) {
	if ( GetSceneChangeFlag( ) ) return;	//シーン遷移フラグが立っている時は処理をしない

	_inputChecker.UpdateDevice( );
	if ( _inputChecker.GetKey( KEY_INPUT_2 ) == 1 ) SetSceneChangeFlag( true );

	DrawFormatString( 0,0,0xffffff, "ResultScene" );
}