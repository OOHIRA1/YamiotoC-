#include "GameMainManager.h"
#include <math.h>


//---------------------------------------
//--�R���X�g���N�^�E�f�X�g���N�^
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

	VECTOR pPos = _player->GetPlayerPosition( );
	VECTOR ePos = _enemy->GetEnemyPosition( );
	_distance = ( int )( ( pPos.z - ePos.z ) + fabs( pPos.x - ePos.x ) );	//�v���C���[�ƃG�l�~�[�̋����̌v�Z

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
		_sounder.ChangeVolumeSoundMem( soundHandle2, 255 );
		_sounder.PlaySoundMem( soundHandle2, DX_PLAYTYPE_LOOP, TRUE );
	}
	//���҂̏���-----------------------------------------------------------------------------
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
	//�f�o�b�N���[�h�\������-------------------------------------------------------------------
	_debuger->Debug( _distance );
	//-----------------------------------------------------------------------------------------

	_inputChecker.UpdateDevice( );
	if ( _inputChecker.GetKey( KEY_INPUT_A ) ) {
		_player->MoveForward( 200, 20 );
	} else {
		_player->ResetMovedCount( );
	}
	if ( _inputChecker.GetKey( KEY_INPUT_B ) ) _player->KnockDoor();	//�e�X�g
	//if ( _inputChecker.GetKey( KEY_INPUT_RETURN ) == 1 ) SetSceneChangeFlag( true );

	DrawString( 0,100,"MainScene", 0xff0000 );	//�e�X�g�p
}