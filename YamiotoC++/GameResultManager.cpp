#include "GameResultManager.h"


//-------------------------------------------------------
//--�R���X�g���N�^�E�f�X�g���N�^
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
//--�Q�b�^�[
bool GameResultManager::GetSceneChangeFlag( ) {
	return _sceneChangeFlag;
}
//--------------------------------------------
//--------------------------------------------


//--------------------------------------------
//--�Z�b�^�[
void GameResultManager::SetSceneChangeFlag( bool x ) {
	_sceneChangeFlag = x;
}
//--------------------------------------------
//--------------------------------------------


void GameResultManager::Main( ) {
	if ( GetSceneChangeFlag( ) ) return;	//�V�[���J�ڃt���O�������Ă��鎞�͏��������Ȃ�

	//���C��BGM�Ƒ����ƓG�̉̐����~�߂�-------------------------------------------------------------
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

	if ( _player->GetAnswerCount( ) == CLEAR ) {	//�N���A��
		//�����摜�`��-----------------------------------------------------------------------------------------------------
		int grHandle = _drawer.GetImageManager( ).GetResourceHandle( ResourceData::GAME_CLEAR_TEXT );
		_drawer.DrawGraph( SCREEN_WIDTH_CENTER - 170, SCREEN_HEIGHT_CENTER - 45, grHandle, TRUE );	//�����ɗ���悤�ɍ��W�𒲐�
		//-----------------------------------------------------------------------------------------------------------------
		
		//����炷����-----------------------------------------------------------------------------------
		int soundHandle4 = _sounder.GetSoundDataManager( ).GetSoundHandle( SoundData::GAME_CLEAR );
		if ( !_BGMsounded ) {
			_sounder.ChangeVolumeSoundMem( 100, soundHandle4 );
			_sounder.PlaySoundMem( soundHandle4, DX_PLAYTYPE_BACK, TRUE );
			_BGMsounded = true;
		}
		//------------------------------------------------------------------------------------------------

		if ( !_sounder.CheckSoundMem( soundHandle4 ) ) {	//�����~�܂��Ă���s������
			DrawPushButton( );
		}
	} else {	//�Q�[���I�[�o�[��
		if ( _gameOverWaitCount < GAME_OVER_WAIT_FLAME ) _gameOverWaitCount++;	//�Q�[���I�[�o�[�̊�

		if ( _gameOverWaitCount >= GAME_OVER_WAIT_FLAME ) {
			//�G�l�~�[���߂Â�����------------------------------------------------------------------------------------------------------------------
			int grHandle = _drawer.GetImageManager( ).GetResourceHandle( ResourceData::GAME_OVER_IMAGE );
			_drawer.DrawExtendGraph( _enemyImage.leftUp_x, _enemyImage.leftUp_y,_enemyImage.rightDown_x,_enemyImage.rightDown_y, grHandle, TRUE );

			if ( _enemyImage.leftUp_x > 100  ) { 
				_enemyImage.leftUp_x -= 40;
				_enemyImage.leftUp_y -= 40;
				_enemyImage.rightDown_x += 40;
				_enemyImage.rightDown_y += 40;
			}
			//---------------------------------------------------------------------------------------------------------------------------------------
			
			//����炷����------------------------------------------------------------------------------------
			int soundHandle4 =_sounder.GetSoundDataManager( ).GetSoundHandle( SoundData::GAME_OVER );
			if ( !_BGMsounded ) {
				_sounder.ChangeVolumeSoundMem( 100, soundHandle4 );
				_sounder.PlaySoundMem( soundHandle4, DX_PLAYTYPE_BACK, TRUE );
				_BGMsounded = true;
			}
			//--------------------------------------------------------------------------------------------------

			if ( !_sounder.CheckSoundMem( soundHandle4 ) ) {	//�����~�܂��Ă���s������
				int grHandle2 = _drawer.GetImageManager( ).GetResourceHandle( ResourceData::GAME_OVER_TEXT );
				_drawer.DrawGraph( SCREEN_WIDTH_CENTER - 300, SCREEN_HEIGHT_CENTER - 40, grHandle2, TRUE );
				DrawPushButton( );
			}
		}
	}
	_inputChecker.UpdateDevice( );
}


//--PushButton��\������֐�
void GameResultManager::DrawPushButton( ) {
	//�����摜�`��----------------------------------------------------------------------------------------------------
			if ( !_pushed ) {
				int grHandle = _drawer.GetImageManager( ).GetResourceHandle( ResourceData::PUSH_BUTTON_TEXT );
				_drawer.FlashGraph( SCREEN_WIDTH_CENTER - 80, SCREEN_HEIGHT_CENTER + 100, grHandle );	//���W�͒������ɗ���悤�ɒ���
			}
			//----------------------------------------------------------------------------------------------------------------

			//�L�[��t------------------------------------------------------------------------------------------------------------------------------------
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

			//�L�[���͌㏈��------------------------
			if ( _pushed ) {
				_drawer.FadeOut( );
				if ( _drawer.GetAlpha( ) <= 0 ) {
					SetSceneChangeFlag( true );
				}
			}
			//--------------------------------------
}