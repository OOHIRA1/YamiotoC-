#include "InputChecker.h"


//---------------------------------
//�R���X�g���N�^�E�f�X�g���N�^
InputChecker::InputChecker( ){
}


InputChecker::~InputChecker( ){
}
//---------------------------------
//---------------------------------

//--------------------------------------------------
//�Q�b�^�[
int InputChecker::GetKey( int key ) {
	return _key[ key ];
}
//-------------------------------------------------
//-------------------------------------------------


//--�L�[�{�[�h�𑀍삵�����ǂ������m�F����֐�
void InputChecker::UpdateKey( ) {
	char key_c[ KEY_MAX ];		//�L�[�������ꂽ���ǂ������m�F����ϐ�

	GetHitKeyStateAll( key_c );

	for ( int i = 0; i < KEY_MAX; i++ ) {
		if ( key_c[ i ] == 1 ) {
			++_key[ i ];
		} else {
			_key[ i ] = 0;
		}
	}
}


//--�W���C�p�b�g������������ǂ������m�F����֐�
void InputChecker::UpdateJoypad( ) {
	int pad_c[ JOYPADMAX ] = {	//�p�b�g�������ꂽ���ǂ������m�F����ϐ�
		PAD_INPUT_DOWN, 
		PAD_INPUT_LEFT, 
		PAD_INPUT_RIGHT, 
		PAD_INPUT_UP, 
		PAD_INPUT_1,
		PAD_INPUT_2,
		PAD_INPUT_3,
		PAD_INPUT_4 
	};

	for ( int i = 0; i < JOYPADMAX; i++ ) {
		if ( GetJoypadInputState( DX_INPUT_KEY_PAD1 ) & pad_c[ i ] ) {
			++_joypad[ i ];
		} else {
			_joypad[ i ] = 0;
		}
	}
}


//--�L�[�{�[�h�܂��̓W���C�p�b�g�𑀍삵�����m�F����֐�
void InputChecker::UpdateDevice( ) {
	UpdateKey( );
	UpdateJoypad( );
}
