#include "GameMainManager.h"
#include <math.h>


//---------------------------------------
//--コンストラクタ・デストラクタ
GameMainManager::GameMainManager( ) {
	_player = new Player( &_sounder );
	_enemy = new Enemy;
	_questionnaire   = new Questionnaire( &_inputChecker );
	_debuger = new Debuger( _player, _enemy );
	_sceneChangeFlag = false;
	_debug = false;
	_flameCount = 0;
	_distance = 0;
}


GameMainManager::~GameMainManager( ) {
	delete( _player );
	delete( _enemy );
	delete( _questionnaire );
	delete( _debuger );
}
//----------------------------------------
//----------------------------------------


//---------------------------------------
//--ゲッター
bool GameMainManager::GetSceneChangeFlag( ) {
	return _sceneChangeFlag;
}


int GameMainManager::GetDistance( ) {
	return _distance;
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
	if ( GetSceneChangeFlag( ) ) return;	//シーン遷移フラグが立っている時は処理をしない

	_flameCount++;

	VECTOR pPos = _player->GetPlayerPosition( );
	VECTOR ePos = _enemy->GetEnemyPosition( );
	_distance = ( int )( ( pPos.z - ePos.z ) + fabs( pPos.x - ePos.x ) );	//プレイヤーとエネミーの距離の計算

	//BGMを流す処理----------------------------------------------------------------------------
	int soundHandle = _sounder.GetSoundDataManager( ).GetSoundHandle( GAME_MAIN_BGM );
	if ( !_sounder.CheckSoundMem( soundHandle ) ) {
		_sounder.ChangeVolumeSoundMem( soundHandle, 100 );
		_sounder.PlaySoundMem( soundHandle, DX_PLAYTYPE_LOOP, TRUE );
	}
	//-----------------------------------------------------------------------------------------

	//エネミーの歌声を流す処理-----------------------------------------------------------------
	int soundHandle2 = _sounder.GetSoundDataManager( ).GetSoundHandle( ENEMY_VOICE );
	if ( !_sounder.CheckSoundMem( soundHandle2 ) ) {
		_sounder.ChangeVolumeSoundMem( soundHandle2, 255 );
		_sounder.PlaySoundMem( soundHandle2, DX_PLAYTYPE_LOOP, TRUE );
	}
	//問題者の処理-----------------------------------------------------------------------------
	_questionnaire->Main( );
	//-----------------------------------------------------------------------------------------
	//-----------------------------------------------------------------------------------------
	//-----------------------------------------------------------------------------------------
	//-----------------------------------------------------------------------------------------
	//-----------------------------------------------------------------------------------------
	//-----------------------------------------------------------------------------------------
	//-----------------------------------------------------------------------------------------
	//-----------------------------------------------------------------------------------------
	//-----------------------------------------------------------------------------------------
	//-----------------------------------------------------------------------------------------
	//-----------------------------------------------------------------------------------------
	//デバックモード表示処理-------------------------------------------------------------------
	_debuger->Debug( _distance );
	//-----------------------------------------------------------------------------------------

	_inputChecker.UpdateDevice( );
	if ( _inputChecker.GetKey( KEY_INPUT_A ) ) {
		_player->MoveForward( 200, 20 );
	} else {
		_player->ResetMovedCount( );
	}
	if ( _inputChecker.GetKey( KEY_INPUT_B ) ) _player->KnockDoor();	//テスト
	//if ( _inputChecker.GetKey( KEY_INPUT_RETURN ) == 1 ) SetSceneChangeFlag( true );

	DrawString( 0,100,"MainScene", 0xff0000 );	//テスト用
}