#include "GameResultManager.h"


//-------------------------------------------------------
//--コンストラクタ・デストラクタ
GameResultManager::GameResultManager( /*Sounder* sounder,*/ Player* player ) {
	//_sounder = sounder;
	_player = player;
	_sceneChangeFlag = false;
	_BGMsounded = false;
	_pushed = false;
	_gameOverWaitCount = 0;
	_enemyImage = { SCREEN_WIDTH_CENTER, SCREEN_HEIGHT_CENTER, SCREEN_WIDTH_CENTER - 1, SCREEN_HEIGHT_CENTER - 1 };
}


GameResultManager::~GameResultManager( ) {
	delete( _player );
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

	//メインBGMと足音と敵の歌声を止める-------------------------------------------------------------
	/*int soundHandle  = _sounder->GetSoundDataManager( ).GetSoundHandle( GAME_MAIN_BGM );
	int soundHandle2 = _sounder->GetSoundDataManager( ).GetSoundHandle( ENEMY_VOICE );
	int soundHandle3 = _sounder->GetSoundDataManager( ).GetSoundHandle( SoundData::PLAYER_ASIOTO );
	if ( _sounder->CheckSoundMem( soundHandle ) ) {
		_sounder->StopSoundMem( soundHandle );
	}
	if ( _sounder->CheckSoundMem( soundHandle2 ) ) {
		_sounder->StopSoundMem( soundHandle2 );
	}
	if ( _sounder->CheckSoundMem( soundHandle3 ) ) {
		_sounder->StopSoundMem( soundHandle3 );
	}*/
	//----------------------------------------------------------------------------------------------

	if ( _player->GetAnswerCount( ) == CLEAR ) {	//クリア時
		//文字画像描画-----------------------------------------------------------------------------------------------------
		int grHandle = _drawer.GetImageManager( ).GetResourceHandle( ResourceData::GAME_CLEAR_TEXT );
		_drawer.DrawGraph( SCREEN_WIDTH_CENTER - 170, SCREEN_HEIGHT_CENTER - 45, grHandle, TRUE );	//中央に来るように座標を調整
		//-----------------------------------------------------------------------------------------------------------------
		
		//音を鳴らす処理-----------------------------------------------------------------------------------
		int soundHandle4 = _sounder.GetSoundDataManager( ).GetSoundHandle( SoundData::GAME_CLEAR );
		if ( !_BGMsounded ) {
			_sounder.ChangeVolumeSoundMem( 100, soundHandle4 );
			_sounder.PlaySoundMem( soundHandle4, DX_PLAYTYPE_BACK, TRUE );
			_BGMsounded = true;
		}
		//------------------------------------------------------------------------------------------------

		if ( !_sounder.CheckSoundMem( soundHandle4 ) ) {	//音が止まってから行う処理
			DrawPushButton( );
		}
	} else {	//ゲームオーバー時
		if ( _gameOverWaitCount < GAME_OVER_WAIT_FLAME ) _gameOverWaitCount++;	//ゲームオーバーの間

		if ( _gameOverWaitCount >= GAME_OVER_WAIT_FLAME ) {
			//エネミーが近づく処理------------------------------------------------------------------------------------------------------------------
			int grHandle = _drawer.GetImageManager( ).GetResourceHandle( ResourceData::GAME_OVER_IMAGE );
			_drawer.DrawExtendGraph( _enemyImage.leftUp_x, _enemyImage.leftUp_y,_enemyImage.rightDown_x,_enemyImage.rightDown_y, grHandle, TRUE );

			if ( _enemyImage.leftUp_x > 100  ) { 
				_enemyImage.leftUp_x -= 40;
				_enemyImage.leftUp_y -= 40;
				_enemyImage.rightDown_x += 40;
				_enemyImage.rightDown_y += 40;
			}
			//---------------------------------------------------------------------------------------------------------------------------------------
			
			//音を鳴らす処理------------------------------------------------------------------------------------
			int soundHandle4 =_sounder.GetSoundDataManager( ).GetSoundHandle( SoundData::GAME_OVER );
			if ( !_BGMsounded ) {
				_sounder.ChangeVolumeSoundMem( 100, soundHandle4 );
				_sounder.PlaySoundMem( soundHandle4, DX_PLAYTYPE_BACK, TRUE );
				_BGMsounded = true;
			}
			//--------------------------------------------------------------------------------------------------

			if ( !_sounder.CheckSoundMem( soundHandle4 ) ) {	//音が止まってから行う処理
				int grHandle2 = _drawer.GetImageManager( ).GetResourceHandle( ResourceData::GAME_OVER_TEXT );
				_drawer.DrawGraph( SCREEN_WIDTH_CENTER - 300, SCREEN_HEIGHT_CENTER - 40, grHandle2, TRUE );
				DrawPushButton( );
			}
		}
	}
	_inputChecker.UpdateDevice( );
}


//--PushButtonを表示する関数
void GameResultManager::DrawPushButton( ) {
	//文字画像描画----------------------------------------------------------------------------------------------------
			if ( !_pushed ) {
				int grHandle = _drawer.GetImageManager( ).GetResourceHandle( ResourceData::PUSH_BUTTON_TEXT );
				_drawer.FlashGraph( SCREEN_WIDTH_CENTER - 80, SCREEN_HEIGHT_CENTER + 100, grHandle );	//座標は中央下に来るように調整
			}
			//----------------------------------------------------------------------------------------------------------------

			//キー受付------------------------------------------------------------------------------------------------------------------------------------
			if ( _inputChecker.GetKey( KEY_INPUT_RETURN ) == 1 ||
				 _inputChecker.GetJoypad( INPUT_1 )		  == 1 ||
				 _inputChecker.GetJoypad( INPUT_2 )		  == 1 ||
				 _inputChecker.GetJoypad( INPUT_3 )		  == 1 ||
				 _inputChecker.GetJoypad( INPUT_4 )		  == 1
				) {
				int soundHandle5 = _sounder.GetSoundDataManager( ).GetSoundHandle( GAME_START_SE );
				_sounder.ChangeVolumeSoundMem( 80, soundHandle5 );
				_sounder.PlaySoundMem( soundHandle5, DX_PLAYTYPE_BACK, TRUE );
				_pushed = true;
			}
			//---------------------------------------------------------------------------------------------------------------------------------------------

			//キー入力後処理------------------------
			if ( _pushed ) {
				_drawer.FadeOut( );
				if ( _drawer.GetAlpha( ) <= 0 ) {
					SetSceneChangeFlag( true );
				}
			}
			//--------------------------------------
}