#pragma once

#include <DxLib.h>
#include "Drawer.h"
#include "Player.h"
#include "Enemy.h"
#include "Questionnaire.h"

//==�f�o�b�N���[�h���Ǘ�����N���X
class Debuger: public Drawer {
	Player* _player;
	Enemy* _enemy;
	Questionnaire* _questionnaire;
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


	void Debug( int distance, int pPosIndex, int ePosIndex );										//--�f�o�b�N���[�h��\������֐�
};

