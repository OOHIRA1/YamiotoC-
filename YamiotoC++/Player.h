#pragma once

#include <DxLib.h>
#include "Sounder.h"

const int FIRST_DISTANCE    = 80;							//player��enemey�̏�������(player�̏��������W)
const int PRE_POS_MAX_INDEX = 30;							//�z��pre_pos�̗v�f��
const int ESCAPE_COUNT_MAX  = 200;							//��������ő�t���[����
const int FREEZE_COUNT_MAX  = ESCAPE_COUNT_MAX;				//�d������ő�t���[����
const int FLAME_PER_PIXEL     = 20;							//1�s�N�Z���i�ނ̂ɂ�����t���[����


//==�v���C���[���Ǘ�����N���X
class Player {
	VECTOR _position;						//�v���C���[�̍��W
	VECTOR _direction;						//�v���C���[�̌����Ă������
	VECTOR _prePos[ PRE_POS_MAX_INDEX ];	//�v���C���[���������W�i���I�����̍��W�j���L������z��
	int _answerCount;						//����	//�ŏ���answer��ture�ŏ������邽��-1�ŏ����������I�������O
	int _notAnswerCount;					//�s����
	int _movedCount;						//�v���C���[���������t���[�������i�[����ϐ�
	int _freezedCount;						//�v���C���[���d�������t���[�������i�[����ϐ�
	Sounder* _sounder;
public:
	//-------------------------------
	//�R���X�g���N�^�E�f�X�g���N�^
	Player( Sounder* sounder );
	~Player( );
	//-------------------------------
	//-------------------------------


	//---------------------------------------------------
	//--�Q�b�^�[
	VECTOR GetPlayerPosition( );
	int GetAnswerCount( );
	int GetNotAnswerCount( );
	int GetMovedCount( );
	VECTOR* GetPrePos( );
	//---------------------------------------------------
	//---------------------------------------------------


	//---------------------------------------------------
	//--�Z�b�^�[
	void SetPrePos( int index, VECTOR position );
	//---------------------------------------------------
	//---------------------------------------------------
	//---------------------------------------------------


	void MoveForwardPixel( int pixel );					//--player���O����pixel�s�N�Z���ړ�����֐�
	void MoveLeftPixel   ( int pixel );					//--player�����@��pixel�s�N�Z���ړ�����֐�
	void MoveRightPixel  ( int pixel );					//--player���E�@��pixel�s�N�Z���ړ�����֐�
	void MoveForward( int escapeCount, int flamePerPixel );					//--player���O����escapeCount�t���[���̊ԂP�s�N�Z��������flamePerPixel�t���[���ňړ�����֐�
	void MoveLeft   ( int escapeCount, int flamePerPixel );					//--player�����@��escapeCount�t���[���̊ԂP�s�N�Z��������flamePerPixel�t���[���ňړ�����֐�
	void MoveRight  ( int escapeCount, int flamePerPixel );					//--player���E�@��escapeCount�t���[���̊ԂP�s�N�Z��������flamePerPixel�t���[���ňړ�����֐�
	void SoundASIOTO( );													//--������炷�֐�(���[�v�Đ�)
	void StopASIOTO( );														//--�������~�߂�֐�
	void StopASIOTOAndLookForward( );										//--�������~�߁A���ʂ������֐�
	void KnockDoor( );														//--�h�A���K�`���K�`������֐�
	void OpenDoor( );														//--�h�A���J����֐�
	void PlusAnswerCount( );												//--_answerCount������₷�֐�
	void PlusNotAnswerCount( );												//--_notAnswerCount������₷�֐�
	void ResetMovedCount( );												//--_movedCount�����Z�b�g����(0�ɂ���)�֐�
	void ResetFreezedCount( );												//--_freezedCount�����Z�b�g����(0�ɂ���)�֐�
};

