#pragma once

#include <DXLib.h>

//==�����Ǘ�����N���X
class Sounder {
public:
	//-------------------------------
	//�R���X�g���N�^�E�f�X�g���N�^
	Sounder( );
	~Sounder( );
	//-------------------------------
	//-------------------------------

	void PlaySoundMem( int soundHandle , int playType , int topPositionFlag );		//--����炷�֐�
	void StopSoundMem( int soundHandle );											//--�����~�߂�֐�
	void CheckSoundMem( int soundHandle );											//--�������Ă��邩�m�F����֐�
	void ChangeVolumeSoundMem( int volumePal, int soundHandle );					//--���ʂ�ς���֐�
	void Set3DPositionSoundMem( VECTOR position, int soundHandle );					//--���f�[�^�̂R�c�T�E���h�p�̍Đ��ʒu��ݒ肷��֐�
	void SetPlayerPosAndDir( VECTOR listenerPosition, VECTOR listenerDirection );	//--�R�c�T�E���h�̃��X�i�[�̈ʒu�ƃ��X�i�[�̑O���ʒu��ݒ肷��
	void Set3DRadiusSoundMem( float radius, int soundHandle );						//--���f�[�^�̂R�c�T�E���h�p�̉����������鋗����ݒ肷��֐�
	void Set3DSoundOneMetre( float distance );										//--�R�c��Ԃ̂P���[�g���ɑ������鋗����ݒ肷��
};

