#pragma once

#include <DXLib.h>

const int FIRST_DISTANCE    = 80;							//player��enemey�̏�������(player�̏��������W)
const int PRE_POS_MAX_INDEX = 30;							//�z��pre_pos�̗v�f��
const int ESCAPE_COUNT_MAX  = 200;							//��������ő�t���[����
const int FREEZE_COUNT_MAX  = ESCAPE_COUNT_MAX;				//�d������ő�t���[����


//==�v���C���[���Ǘ�����N���X
class Player {
	VECTOR _position;						//�v���C���[�̍��W
	VECTOR _direction;						//�v���C���[�̌����Ă������
	VECTOR _prePos[ PRE_POS_MAX_INDEX ];	//�v���C���[���������W�i���I�����̍��W�j���L������z��
	int _answerCount;						//����	//�ŏ���answer��ture�ŏ������邽��-1�ŏ����������I�������O
	int _notAnswerCount;					//�s����
	int _escapeCount;						//�v���C���[����������t���[�������i�[����ϐ�
	int _freezeCount;						//�v���C���[���d������t���[�������i�[����ϐ�
public:
	//-------------------------------
	//�R���X�g���N�^�E�f�X�g���N�^
	Player( );
	~Player( );
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
};
