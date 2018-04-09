#include "GameMainManager.h"
#include <math.h>


//---------------------------------------
//--コンストラクタ・デストラクタ
GameMainManager::GameMainManager( ) {
	_player = new Player( &_sounder );
	_enemy = new Enemy;
	_questionnaire   = new Questionnaire( &_inputChecker, &_sounder );
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

	//プレイヤーとエネミーの距離の計算---------------------------------------------------------
	VECTOR pPos = _player->GetPlayerPosition( );
	VECTOR ePos = _enemy->GetEnemyPosition( );
	_distance = ( int )( ( pPos.z - ePos.z ) + fabs( pPos.x - ePos.x ) );
	//-----------------------------------------------------------------------------------------

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
	//-----------------------------------------------------------------------------------------

	//問題者の処理-----------------------------------------------------------------------------
	_questionnaire->Main( );
	//-----------------------------------------------------------------------------------------

	//エネミーがプレイヤーに近づく処理---------------------------------------------------------
	if ( !_questionnaire->GetAnswer( ) || _questionnaire->GetChooseWayFlag( ) ) {	//問題を答えていないとき または　道を選んでいないとき
		/*float x_diff = player.pre_pos[ e_pos_index ].x - enemy.position.x;
		

		if ( ( player.pre_pos[ e_pos_index ] - enemy.position ) == 0 ){
			e_pos_index = ( e_pos_index + 1 ) % PRE_POS_MAX_INDEX;
		}

		switch( player.not_answer_count ) {
		case 0:
			if ( x_diff < 0 ) {
				enemy.position.x -= flame_count % 61 / 60;
			} else if ( x_diff > 0 ){
				enemy.position.x += flame_count % 61 / 60;
			} else {
				enemy.position.z += flame_count % 61 / 60;
			}
			break;

		case 1:
			if ( x_diff < 0 ) {
				enemy.position.x -= flame_count % 46 / 45;
			} else if ( x_diff > 0 ){
				enemy.position.x += flame_count % 46 / 45;
			} else {							  
				enemy.position.z += flame_count % 46 / 45;
			}
			break;

		default:
			if ( x_diff < 0 ) {
				enemy.position.x -= flame_count % 31 / 30;
			} else if ( x_diff > 0 ){
				enemy.position.x += flame_count % 31 / 30;
			} else {							  
				enemy.position.z += flame_count % 31 / 30;
			}
			break;
		}

		SetEnemySoundPos( enemy.position, sound[ ENEMY_VOICE ] );*/
	}
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
	if ( _inputChecker.GetKey( KEY_INPUT_C ) == 1 ) _questionnaire->SetInput( true );
	//if ( _inputChecker.GetKey( KEY_INPUT_RETURN ) == 1 ) SetSceneChangeFlag( true );

	DrawString( 0,100,"MainScene", 0xff0000 );	//テスト用
}