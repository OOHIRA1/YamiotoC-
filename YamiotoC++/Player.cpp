#include "Player.h"


//-------------------------------
//�R���X�g���N�^�E�f�X�g���N�^
Player::Player( Sounder* sounder ){
	_position = VGet( 0, 0, ( float )FIRST_DISTANCE );
	_direction = VGet( 0, 0, 1 );

	for ( int i = 0; i < PRE_POS_MAX_INDEX; i++ ) {
		_prePos[ i ] = VGet( 0, 0, 0 );
	}
	_prePos[ 0 ] = _position;		//�ŏ��̍��W��_prePos[ 0 ]�ɑ��

	_answerCount    = 0;
	_notAnswerCount = 0;
	_movedCount = 0;
	_freezedCount = 0;
	_sounder = sounder;
	_sounder->SetPlayerPosAndDir( _position, _direction );
}


Player::~Player( ){
}
//-------------------------------
//-------------------------------


//---------------------------------------------------
//--�Q�b�^�[
VECTOR Player::GetPlayerPosition( ) {
	return _position;
}


int Player::GetAnswerCount( ) {
	return _answerCount;
}


int Player::GetNotAnswerCount( ) {
	return _notAnswerCount;
}
//---------------------------------------------------
//---------------------------------------------------


//---------------------------------------------------
//--�Z�b�^�[
//---------------------------------------------------

//---------------------------------------------------
//---------------------------------------------------


//--player���O��(z����)��pixel�s�N�Z���ړ�����֐�
void Player::MoveForwardPixel( int pixel ) {
	_position.z += pixel;
}


//--player�����@��pixel�s�N�Z���ړ�����֐�
void Player::MoveLeftPixel( int pixel ) {
	_position.x -= pixel;
}


//--player���E�@��pixel�s�N�Z���ړ�����֐�
void Player::MoveRightPixel( int pixel ) {
	_position.x += pixel;
}


//--player���O����escapeCount�t���[���̊ԂP�s�N�Z��������flamePerPixel�t���[���ňړ�����֐�
void Player::MoveForward( int escapeCount, int flamePerPixel ) {
	if ( _movedCount >= escapeCount ) {
		StopASIOTO( );
		_direction = VGet( 0, 0, 1 );
		_sounder->SetPlayerPosAndDir( _position, _direction );
		return;	//����escapeCount�t���[�������Ă�����߂�
	}

	_movedCount++;
	if ( _movedCount == 1 ) {
		_direction = VGet( 0, 0, 1 );
		SoundASIOTO( );
	}
	if ( _movedCount % flamePerPixel == 0 ) MoveForwardPixel( 1 );
	_sounder->SetPlayerPosAndDir( _position, _direction );
}


//--player������escapeCount�t���[���̊ԂP�s�N�Z��������flamePerPixel�t���[���ňړ�����֐�
void Player::MoveLeft( int escapeCount, int flamePerPixel ) {
	if ( _movedCount >= escapeCount ) {
		StopASIOTO( );
		_direction = VGet( 0, 0, 1 );
		_sounder->SetPlayerPosAndDir( _position, _direction );
		return;	//����escapeCount�t���[�������Ă�����߂�
	}

	_movedCount++;
	if ( _movedCount == 1 ) {
		_direction = VGet( -1, 0, 0 );
		SoundASIOTO( );
	}
	if ( _movedCount % flamePerPixel == 0 ) MoveLeftPixel( 1 );
	_sounder->SetPlayerPosAndDir( _position, _direction );
}


//--player���E��escapeCount�t���[���̊ԂP�s�N�Z��������flamePerPixel�t���[���ňړ�����֐�
void Player::MoveRight( int escapeCount, int flamePerPixel ) {
	if ( _movedCount >= escapeCount ) {
		StopASIOTO( );
		_direction = VGet( 0, 0, 1 );
		_sounder->SetPlayerPosAndDir( _position, _direction );
		return;	//����escapeCount�t���[�������Ă�����߂�
	}

	_movedCount++;
	if ( _movedCount == 1 ) {
		_direction = VGet( 1, 0, 0 );
		SoundASIOTO( );
	}
	if ( _movedCount % flamePerPixel == 0 ) MoveRightPixel( 1 );
	_sounder->SetPlayerPosAndDir( _position, _direction );
}


//--������炷�֐�(���[�v�Đ�)
void Player::SoundASIOTO( ) {
	int soundHandle = _sounder->GetSoundDataManager( ).GetSoundHandle( SoundData::PLAYER_ASIOTO );
		_sounder->ChangeVolumeSoundMem( 100, soundHandle );
		_sounder->PlaySoundMem( soundHandle, DX_PLAYTYPE_LOOP, TRUE );
}


//--�������~�߂�֐�
void Player::StopASIOTO( ) {
	int soundHandle = _sounder->GetSoundDataManager( ).GetSoundHandle( SoundData::PLAYER_ASIOTO );
	if ( _sounder->CheckSoundMem( soundHandle ) ) {
		_sounder->StopSoundMem( soundHandle );
	}
}
//--�h�A���K�`���K�`������֐�
void Player::KnockDoor( ) {
	int soundHandle = _sounder->GetSoundDataManager( ).GetSoundHandle( SoundData::DOOR_GATYA );
	_sounder->ChangeVolumeSoundMem( 100, soundHandle );
	_sounder->PlaySoundMem( soundHandle, DX_PLAYTYPE_NORMAL , TRUE);
}


//--�h�A���J����֐�
void Player::OpenDoor( ) {
	int soundHandle = _sounder->GetSoundDataManager( ).GetSoundHandle( SoundData::DOOR );
	_sounder->ChangeVolumeSoundMem( 100, soundHandle );
	_sounder->PlaySoundMem( soundHandle, DX_PLAYTYPE_NORMAL, TRUE );
}


//--_answerCount������₷�֐�
void Player::ResetMovedCount( ) {
	_movedCount = 0;
}


//--_notAnswerCount������₷�֐�
void Player::ResetFreezedCount( ) {
	_freezedCount = 0;
}