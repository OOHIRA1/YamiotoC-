#pragma once

#include <DXLib.h>

const int KEY_MAX = 256;
enum Joypad {	//�W���C�p�b�g
	DOWN,
	LEFT,
	RIGHT,
	UP,
	INPUT_1,
	INPUT_2,
	INPUT_3,
	INPUT_4,
	JOYPADMAX
};


//==�L�[�E�p�b�g���͂��Ǘ�����N���X
class InputChecker{
	int _key[ KEY_MAX ];		//�L�[�̉�����Ă���t���[�������i�[����ϐ�
	int _joypad[ JOYPADMAX ];	//�p�b�g�̉�����Ă���t���[�������i�[����ϐ�
public:
	//---------------------------------
	//�R���X�g���N�^�E�f�X�g���N�^
	InputChecker( );
	~InputChecker( );
	//---------------------------------
	//---------------------------------

	//---------------------------------
	//�Q�b�^�[
	int GetKey( int key );
	//---------------------------------
	//---------------------------------

	void UpdateKey( );			//--�L�[�{�[�h�𑀍삵�����ǂ������m�F����֐�
	void UpdateJoypad( );		//--�W���C�p�b�g������������ǂ������m�F����֐�
	void UpdateDevice( );		//--�L�[�{�[�h�܂��̓W���C�p�b�g�𑀍삵�����m�F����֐�
private:

};

