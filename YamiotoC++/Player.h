#pragma once

#include <DXLib.h>

const int PRE_POS_MAX_INDEX = 30;							//�z��pre_pos�̗v�f��

//==�v���C���[���Ǘ�����N���X
class Player {
	VECTOR _position;
	VECTOR _direction;
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
};

