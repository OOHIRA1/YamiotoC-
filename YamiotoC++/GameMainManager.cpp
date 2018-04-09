#include "GameMainManager.h"
#include <math.h>
#include "VectorOperator.h"


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

	//�f�o�b�N���[�h�\������-------------------------------------------------------------------
	_debuger->Debug( _distance, _pPosIndex, _ePosIndex );
	//-----------------------------------------------------------------------------------------

	//���𓚂��Ă��Ȃ��Ƃ��̏���---------------------------------------------------------
	if ( !_questionnaire->GetAnswer( ) ) {
		VECTOR* prePos = _player->GetPrePos( );
		if ( prePos[ _ePosIndex ] == ePos ) {
			_ePosIndex = ( _ePosIndex + 1 ) % PRE_POS_MAX_INDEX;	//_ePosIndex�̍X�V
		}
		//�G�l�~�[���v���C���[�ɋ߂Â�����----------------------------
		int flamePerPixel;
		switch( _player->GetNotAnswerCount( ) ) {
		case 0:
			flamePerPixel = 60;
			break;
		case 1:
			flamePerPixel = 45;
			break;
		case 2:
			flamePerPixel = 30;
		default:
			break;
		}
		if ( _flameCount % flamePerPixel == 0 ) {
			float xDiff = prePos[ _ePosIndex ].x -ePos.x;
			if ( xDiff < 0 ) {
				_enemy->MoveLeftPixel( 1 );
			} else if ( xDiff > 0 ) {
				_enemy->MoveRightPixel( 1 );
			} else {
				_enemy->MoveForwardPixel( 1 );
			}
			_sounder.Set3DPositionSoundMem( ePos, soundHandle2 );
		}
		//------------------------------------------------------------
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
		//����I����Ă�����s������-------------------------------------------------------------------
		int soundHandle3 = _sounder.GetSoundDataManager( ).GetSoundHandle( SoundData::PLAYER_ASIOTO );
		if ( !_sounder.CheckSoundMem( soundHandle3 ) ) {
			_player->ResetMovedCount( );
			_player->PlusAnswerCount( );

			UpdatePlayerPrePos( );		//�v���C���[�̍��W�������

			UpdateQFinished( );	//_questionnaire->_qFinished���X�V

			_questionnaire->SetSelectedSentence( 0 );
			_questionnaire->SetInput( false );
			_questionnaire->SetLevelRandomed( false );	//���ɓ�Փx��U�蕪������悤�ɂ���
			_questionnaire->SetAnswer( false );
			_questionnaire->SetChooseWayFlag( true );	//����I�ׂ�悤�ɂ���
		}
		//----------------------------------------------------------------------------------------------
	}
	if ( _questionnaire->GetNotAnswer( ) ) {	//�s��������
		_player->Freeze( ESCAPE_COUNT_MAX );
		//�y�i���e�B���I��������s������----------------------------------------
		if ( _player->GetFreezedCount( ) == ESCAPE_COUNT_MAX ) {
			_player->ResetFreezedCount( );

			UpdateQFinished( );	//_questionnaire->_qFinished���X�V

			_questionnaire->RandamQuestion( );	//���̃����_������
			_questionnaire->SetSelectedSentence( 0 );
			_questionnaire->SetInput( true );
			_questionnaire->SetNotAnswer( false );
		}
		//----------------------------------------------------------------------
	}
	//-----------------------------------------------------------------------------------------------------------
	
	////�f�o�b�N���[�h�\������-------------------------------------------------------------------�������Ńf�o�b�N���[�h�\���������s���ƃh�A�K�`���̎��Ƀf�o�b�N���[�h�\����������(�@ScreenFrip()�����ĂȂ��̂ɂȂ������邩�͓�(+_+)�@)
	//_debuger->Debug( _distance, _pPosIndex, _ePosIndex );
	////-----------------------------------------------------------------------------------------

	_inputChecker.UpdateDevice( );
}


//--�v���C���[�̍��W��_player->_prePos�ɓ����֐�
void GameMainManager::UpdatePlayerPrePos( ) {
	_player->SetPrePos( _pPosIndex, _player->GetPosition( ) );
	_pPosIndex = ( _pPosIndex + 1 ) % PRE_POS_MAX_INDEX;	//���l��0�`29�ŌJ��Ԃ�
}


//--�o�肵�����Ƀt���O�𗧂đS�Ă̖�肪�o���烊�Z�b�g����֐�
void GameMainManager::UpdateQFinished( ) {
	int exerciseBookNum = _questionnaire->GetExerciseBookNum( );
	int questionNum     = _questionnaire->GetQuestionNum( );
	_questionnaire->SetQFinished( exerciseBookNum, questionNum - 1, true );	//�o�����Ƀt���O�𗧂Ă�

	//�S�Ă̖�肪�o���烊�Z�b�g����---------------------------------------
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