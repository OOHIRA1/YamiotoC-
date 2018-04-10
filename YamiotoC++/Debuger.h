#pragma once

#include <DxLib.h>
#include "Player.h"
#include "Enemy.h"
#include "Questionnaire.h"

struct Fps {
	short int start;	//�v���J�n�����i�b�j
	short int flame;	//�v���J�n��������̃t���[����
	float save;			//fps
};


//==�f�o�b�N���[�h���Ǘ�����N���X
class Debuger {
	Player* _player;
	Enemy* _enemy;
	Questionnaire* _questionnaire;
	struct Fps _fpsCounter;				//fps�\���p�\����
public:
	//------------------------------------------------
	//--�R���X�g���N�^�E�f�X�g���N�^
	Debuger( Player* player, Enemy* enemy, Questionnaire* questionnaire );
	~Debuger( );
	//------------------------------------------------
	//------------------------------------------------


	//------------------------------------------------
	//--�Q�b�^�[
	//------------------------------------------------
	//------------------------------------------------


	//------------------------------------------------
	//--�Z�b�^�[
	//------------------------------------------------
	//------------------------------------------------


	void DebugMainScene( int distance, int pPosIndex, int ePosIndex );								//--�f�o�b�N���[�h��\������֐�(GameMainScene�̂ݎg�p�\)
	void DebugFPS( );																				//--FPS��\������֐�
};

