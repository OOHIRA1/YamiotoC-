#include "GameMainManager.h"
#include <math.h>


//---------------------------------------
//--コンストラクタ・デストラクタ
GameMainManager::GameMainManager( ) {
	_player = new Player( &_sounder );
	_enemy = new Enemy;
	_questionnaire   = new Questionnaire( &_inputChecker, &_sounder );
	_debuger = new Debuger( _player, _enemy, _questionnaire );
	_sceneChangeFlag = false;
	_debug = false;
	_flameCount = 0;
	_distance = 0;
	_pPosIndex = 1;		//_player->_prePos[ 0 ]は最初の値を格納済み(_player->_prePos[ 0 ]を上書きしないため)
	_ePosIndex = 0;
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
	VECTOR pPos = _player->GetPosition( );
	VECTOR ePos = _enemy->GetPosition( );
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
		_sounder.Set3DPositionSoundMem( _enemy->GetPosition( ), soundHandle2 );
		_sounder.Set3DRadiusSoundMem( 60, soundHandle2 );
		_sounder.ChangeVolumeSoundMem( soundHandle2, 255 );
		_sounder.PlaySoundMem( soundHandle2, DX_PLAYTYPE_LOOP, TRUE );
	}
	//-----------------------------------------------------------------------------------------

	//デバックモード表示処理-------------------------------------------------------------------
	_debuger->Debug( _distance, _pPosIndex, _ePosIndex );
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

	//画面フェーズ===================================
	//・道選択表示画面
	//・問題難易度のみ表示画面（道選択後の移動処理）
	//・問題表示画面
	//・非表示画面（問題解答後の処理）
	//===============================================

	//道選択表示画面フェーズ----------------------------------------------------------------------------------
	if ( _questionnaire->GetChooseWayFlag( ) ) {
		_questionnaire->ChooseWay( );	//道選択表示
		if ( !_questionnaire->GetChooseWayFlag( ) ) {
			_questionnaire->RandamQuestion( );	//道選択後に問題ランダム処理
		}
	}
	//--------------------------------------------------------------------------------------------------------

	//問題難易度のみ表示画面フェーズ----------------------------------------------------------------------------------------------------------
	if ( !_questionnaire->GetChooseWayFlag( ) && !_questionnaire->GetAnswer( ) && !_questionnaire->GetNotAnswer( ) ) {
		_questionnaire->DisplayLevel( );	//問題難易度表示
		if ( !_questionnaire->GetInput( ) ) {
			//走る処理-------------------------------------------------------
			switch( _questionnaire->GetWay( ) ) {
			case Way::STRAIGHT_WAY:
				_player->MoveForward( ESCAPE_COUNT_MAX, FLAME_PER_PIXEL );
				break;
			case Way::RIGHT_WAY:
				_player->MoveRight( ESCAPE_COUNT_MAX, FLAME_PER_PIXEL );
				break;
			case Way::LEFT_WAY:
				_player->MoveLeft( ESCAPE_COUNT_MAX, FLAME_PER_PIXEL );
				break;
			}
			//--------------------------------------------------------------

			//走り終わっていたら行う処理-------------------------------------------------------------------
			int soundHandle3 = _sounder.GetSoundDataManager( ).GetSoundHandle( SoundData::PLAYER_ASIOTO );
			if ( !_sounder.CheckSoundMem( soundHandle3 ) ) {
				_player->ResetMovedCount( );
				_player->KnockDoor( );
				_questionnaire->SetInput( true );

				UpdatePlayerPrePos( );		//プレイヤーの座標をいれる
			}
			//----------------------------------------------------------------------------------------------
		}
	}
	//----------------------------------------------------------------------------------------------------------------------------------------

	//問題表示画面フェーズ----------------------------------------------------------------------------------------------------
	if ( _questionnaire->GetInput( ) ) {
		_questionnaire->Question( );		//問題表示
		if ( _questionnaire->GetInput( ) ) {	//問題を答えた後はカーソルが表示しないようにif文で括った
			_questionnaire->CursorDisplay( );	//カーソル表示
		}
	}
	//------------------------------------------------------------------------------------------------------------------------

	//非表示画面フェーズ-----------------------------------------------------------------------------------------
	if ( _questionnaire->GetAnswer( ) ) {	//正解処理
		if ( _player->GetMovedCount( ) == 0 ) {
			_player->OpenDoor( );
		}
		_player->MoveForward( ESCAPE_COUNT_MAX, FLAME_PER_PIXEL );
		//走り終わっていたら行う処理-------------------------------------------------------------------
		int soundHandle3 = _sounder.GetSoundDataManager( ).GetSoundHandle( SoundData::PLAYER_ASIOTO );
		if ( !_sounder.CheckSoundMem( soundHandle3 ) ) {
			_player->ResetMovedCount( );
			_player->PlusAnswerCount( );

			UpdatePlayerPrePos( );		//プレイヤーの座標をいれる

			UpdateQFinished( );	//_questionnaire->_qFinishedを更新

			_questionnaire->SetSelectedSentence( 0 );
			_questionnaire->SetInput( false );
			_questionnaire->SetLevelRandomed( false );	//道に難易度を振り分けられるようにする
			_questionnaire->SetAnswer( false );
			_questionnaire->SetChooseWayFlag( true );	//道を選べるようにする
		}
		//----------------------------------------------------------------------------------------------
	}
	if ( _questionnaire->GetNotAnswer( ) ) {	//不正解処理
		_player->Freeze( ESCAPE_COUNT_MAX );
		//ペナルティが終了したら行う処理----------------------------------------
		if ( _player->GetFreezedCount( ) == ESCAPE_COUNT_MAX ) {
			_player->ResetFreezedCount( );

			UpdateQFinished( );	//_questionnaire->_qFinishedを更新

			_questionnaire->RandamQuestion( );	//問題のランダム処理
			_questionnaire->SetSelectedSentence( 0 );
			_questionnaire->SetInput( true );
			_questionnaire->SetNotAnswer( false );
		}
		//----------------------------------------------------------------------
	}
	//-----------------------------------------------------------------------------------------------------------
	
	////デバックモード表示処理-------------------------------------------------------------------※ここでデバックモード表示処理を行うとドアガチャの時にデバックモード表示が消える(　ScreenFrip()もしてないのになぜ消えるかは謎(+_+)　)
	//_debuger->Debug( _distance, _pPosIndex, _ePosIndex );
	////-----------------------------------------------------------------------------------------

	_inputChecker.UpdateDevice( );
}


//--プレイヤーの座標を_player->_prePosに入れる関数
void GameMainManager::UpdatePlayerPrePos( ) {
	_player->SetPrePos( _pPosIndex, _player->GetPosition( ) );
	_pPosIndex = ( _pPosIndex + 1 ) % PRE_POS_MAX_INDEX;	//数値を0〜29で繰り返す
}


//--出題した問題にフラグを立て全ての問題が出たらリセットする関数
void GameMainManager::UpdateQFinished( ) {
	int exerciseBookNum = _questionnaire->GetExerciseBookNum( );
	int questionNum     = _questionnaire->GetQuestionNum( );
	_questionnaire->SetQFinished( exerciseBookNum, questionNum - 1, true );	//出た問題にフラグを立てる

	//全ての問題が出たらリセットする---------------------------------------
	for ( int i = 0; i < QUESTION_MAX; i++ ) {
		bool* qFinished = _questionnaire->GetQFinished( exerciseBookNum );
		if ( !qFinished[ i ] ) break;

		if ( i == QUESTION_MAX - 1 ) {
			for ( int j = 0; j < QUESTION_MAX; j++ ) {
				_questionnaire->SetQFinished( exerciseBookNum, j, false );
			}
		}
	}
	//-----------------------------------------------------------------------
}