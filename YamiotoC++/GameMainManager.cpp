#include "GameMainManager.h"
#include <math.h>


//---------------------------------------
//--�R���X�g���N�^�E�f�X�g���N�^
GameMainManager::GameMainManager( ) {
	_player = new Player( &_sounder );
	_enemy = new Enemy;
	_questionnaire   = new Questionnaire( &_inputChecker, &_sounder );
	_debuger = new Debuger( _player, _enemy, _questionnaire );
	_sceneChangeFlag = false;
	_debug = false;
	_flameCount = 0;
	_distance = 0;
	_pPosIndex = 1;		//_player->_prePos[ 0 ]�͍ŏ��̒l���i�[�ς�(_player->_prePos[ 0 ]���㏑�����Ȃ�����)
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
//--�Q�b�^�[
bool GameMainManager::GetSceneChangeFlag( ) {
	return _sceneChangeFlag;
}


int GameMainManager::GetDistance( ) {
	return _distance;
}
//---------------------------------------
//---------------------------------------


//---------------------------------------
//--�Z�b�^�[
void GameMainManager::SetSceneChangeFlag( bool x ) {
	_sceneChangeFlag = x;
}
//---------------------------------------
//---------------------------------------


//--���C���֐�
void GameMainManager::Main( ) {
	if ( GetSceneChangeFlag( ) ) return;	//�V�[���J�ڃt���O�������Ă��鎞�͏��������Ȃ�

	_flameCount++;

	//�v���C���[�ƃG�l�~�[�̋����̌v�Z---------------------------------------------------------
	VECTOR pPos = _player->GetPosition( );
	VECTOR ePos = _enemy->GetPosition( );
	_distance = ( int )( ( pPos.z - ePos.z ) + fabs( pPos.x - ePos.x ) );
	//-----------------------------------------------------------------------------------------

	//BGM�𗬂�����----------------------------------------------------------------------------
	int soundHandle = _sounder.GetSoundDataManager( ).GetSoundHandle( GAME_MAIN_BGM );
	if ( !_sounder.CheckSoundMem( soundHandle ) ) {
		_sounder.ChangeVolumeSoundMem( soundHandle, 100 );
		_sounder.PlaySoundMem( soundHandle, DX_PLAYTYPE_LOOP, TRUE );
	}
	//-----------------------------------------------------------------------------------------

	//�G�l�~�[�̉̐��𗬂�����-----------------------------------------------------------------
	int soundHandle2 = _sounder.GetSoundDataManager( ).GetSoundHandle( ENEMY_VOICE );
	if ( !_sounder.CheckSoundMem( soundHandle2 ) ) {
		_sounder.Set3DPositionSoundMem( _enemy->GetPosition( ), soundHandle2 );
		_sounder.Set3DRadiusSoundMem( 60, soundHandle2 );
		_sounder.ChangeVolumeSoundMem( soundHandle2, 255 );
		_sounder.PlaySoundMem( soundHandle2, DX_PLAYTYPE_LOOP, TRUE );
	}
	//-----------------------------------------------------------------------------------------

	//���҂̏���-----------------------------------------------------------------------------
	//_questionnaire->Main( );
	//-----------------------------------------------------------------------------------------

	//�G�l�~�[���v���C���[�ɋ߂Â�����---------------------------------------------------------
	if ( !_questionnaire->GetAnswer( ) || _questionnaire->GetChooseWayFlag( ) ) {	//���𓚂��Ă��Ȃ��Ƃ� �܂��́@����I��ł��Ȃ��Ƃ�
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

	//��ʃt�F�[�Y===================================
	//�E���I��\�����
	//�E����Փx�̂ݕ\����ʁi���I����̈ړ������j
	//�E���\�����
	//�E��\����ʁi���𓚌�̏����j
	//===============================================

	//���I��\����ʃt�F�[�Y----------------------------------------------------------------------------------
	if ( _questionnaire->GetChooseWayFlag( ) ) {
		_questionnaire->ChooseWay( );	//���I��\��
		if ( !_questionnaire->GetChooseWayFlag( ) ) {
			_questionnaire->RandamQuestion( );	//���I����ɖ�胉���_������
		}
	}
	//--------------------------------------------------------------------------------------------------------

	//����Փx�̂ݕ\����ʃt�F�[�Y----------------------------------------------------------------------------------------------------------
	if ( !_questionnaire->GetChooseWayFlag( ) && !_questionnaire->GetAnswer( ) && !_questionnaire->GetNotAnswer( ) ) {
		_questionnaire->DisplayLevel( );	//����Փx�\��
		if ( !_questionnaire->GetInput( ) ) {
			//���鏈��-------------------------------------------------------
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

			//����I����Ă�����s������-------------------------------------------------------------------
			int soundHandle3 = _sounder.GetSoundDataManager( ).GetSoundHandle( SoundData::PLAYER_ASIOTO );
			if ( !_sounder.CheckSoundMem( soundHandle3 ) ) {
				_player->ResetMovedCount( );
				_player->KnockDoor( );
				_questionnaire->SetInput( true );

				UpdatePlayerPrePos( );		//�v���C���[�̍��W�������
			}
			//----------------------------------------------------------------------------------------------
		}
	}
	//----------------------------------------------------------------------------------------------------------------------------------------

	//���\����ʃt�F�[�Y----------------------------------------------------------------------------------------------------
	if ( _questionnaire->GetInput( ) ) {
		_questionnaire->Question( );		//���\��
		if ( _questionnaire->GetInput( ) ) {	//���𓚂�����̓J�[�\�����\�����Ȃ��悤��if���Ŋ�����
			_questionnaire->CursorDisplay( );	//�J�[�\���\��
		}
	}
	//------------------------------------------------------------------------------------------------------------------------

	//��\����ʃt�F�[�Y-----------------------------------------------------------------------------------------
	if ( _questionnaire->GetAnswer( ) ) {	//��������
		if ( _player->GetMovedCount( ) == 0 ) {
			_player->OpenDoor( );
		}
		_player->MoveForward( ESCAPE_COUNT_MAX, FLAME_PER_PIXEL );
		int soundHandle3 = _sounder.GetSoundDataManager( ).GetSoundHandle( SoundData::PLAYER_ASIOTO );
		if ( !_sounder.CheckSoundMem( soundHandle3 ) ) {
			_player->ResetMovedCount( );
			_player->PlusAnswerCount( );

			UpdatePlayerPrePos( );		//�v���C���[�̍��W�������

			_questionnaire->SetSelectedSentence( 0 );
			_questionnaire->SetInput( false );
			_questionnaire->SetLevelRandomed( false );	//���ɓ�Փx��U�蕪������悤�ɂ���
			_questionnaire->SetAnswer( false );
			_questionnaire->SetChooseWayFlag( true );	//����I�ׂ�悤�ɂ���
		}
	}
	//-----------------------------------------------------------------------------------------------------------
	//-----------------------------------------------------------------------------------------
	//-----------------------------------------------------------------------------------------
	//-----------------------------------------------------------------------------------------
	//-----------------------------------------------------------------------------------------
	//�f�o�b�N���[�h�\������-------------------------------------------------------------------
	_debuger->Debug( _distance, _pPosIndex, _ePosIndex );
	//-----------------------------------------------------------------------------------------

	_inputChecker.UpdateDevice( );
	//if ( _inputChecker.GetKey( KEY_INPUT_A ) ) {
	//	_player->MoveForward( 200, 20 );
	//} else {
	//	_player->ResetMovedCount( );
	//}
	//if ( _inputChecker.GetKey( KEY_INPUT_C ) == 1 ) _questionnaire->SetInput( true );
	//if ( _inputChecker.GetKey( KEY_INPUT_RETURN ) == 1 ) SetSceneChangeFlag( true );

	DrawString( 0,100,"MainScene", 0xff0000 );	//�e�X�g�p
}


//--�v���C���[�̍��W��_player->_prePos�ɓ����֐�
void GameMainManager::UpdatePlayerPrePos( ) {
	_player->SetPrePos( _pPosIndex, _player->GetPosition( ) );
	_pPosIndex = ( _pPosIndex + 1 ) % PRE_POS_MAX_INDEX;	//���l��0�`29�ŌJ��Ԃ�
}