#include "Player.h"


//-------------------------------
//�R���X�g���N�^�E�f�X�g���N�^
Player::Player( ){
	_position = VGet( 0, 0, ( float )FIRST_DISTANCE );
	_position = VGet( 0, 0, 1 );

	for ( int i = 0; i < PRE_POS_MAX_INDEX; i++ ) {
		_prePos[ i ] = VGet( 0, 0, 0 );
	}
	_prePos[ 0 ] = _position;		//�ŏ��̍��W��_prePos[ 0 ]�ɑ��

	_answerCount    = 0;
	_notAnswerCount = 0;
	_escapeCount = 0;
	_freezeCount = 0;
}


Player::~Player( ){
}
//-------------------------------
//-------------------------------


//---------------------------------------------------
//--�Q�b�^�[

//---------------------------------------------------
//---------------------------------------------------


//---------------------------------------------------
//--�Z�b�^�[
//---------------------------------------------------

//---------------------------------------------------
//---------------------------------------------------