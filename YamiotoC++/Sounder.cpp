#include "Sounder.h"


//---------------------------------------
//�R���X�g���N�^�E�f�X�g���N�^
Sounder::Sounder( ) {
}


Sounder::~Sounder( ) {
}
//---------------------------------------
//---------------------------------------


//--����炷�֐�
void Sounder::PlaySoundMem( int soundHandle , int playType , int topPositionFlag ) {
	DxLib::PlaySoundMem( soundHandle, playType, topPositionFlag );
}


//--�����~�߂�֐�
void Sounder::StopSoundMem( int soundHandle ) {
	DxLib::StopSoundMem( soundHandle );
}


//--�������Ă��邩�m�F����֐�
void Sounder::CheckSoundMem( int soundHandle ) {
	DxLib::CheckSoundMem( soundHandle );
}


//--���ʂ�ς���֐�
void Sounder::ChangeVolumeSoundMem( int volumePal, int soundHandle ) {
	DxLib::ChangeVolumeSoundMem( volumePal, soundHandle );
}


//--���f�[�^�̂R�c�T�E���h�p�̍Đ��ʒu��ݒ肷��֐�
void Sounder::Set3DPositionSoundMem( VECTOR position, int soundHandle ) {
	DxLib::Set3DPositionSoundMem( position, soundHandle );
}


//--�R�c�T�E���h�̃��X�i�[�̈ʒu�ƃ��X�i�[�̑O���ʒu��ݒ肷��
void Sounder::SetPlayerPosAndDir( VECTOR listenerPosition, VECTOR listenerDirection ) {
	DxLib::Set3DSoundListenerPosAndFrontPos_UpVecY( listenerPosition, VAdd( listenerPosition, listenerDirection ) );
}


//--���f�[�^�̂R�c�T�E���h�p�̉����������鋗����ݒ肷��֐�
void Sounder::Set3DRadiusSoundMem( float radius, int soundHandle ) {
	DxLib::Set3DRadiusSoundMem( radius, soundHandle );
}


//--�R�c��Ԃ̂P���[�g���ɑ������鋗����ݒ肷��
void Sounder::Set3DSoundOneMetre( float  distance ) {
	DxLib::Set3DSoundOneMetre( distance );
}