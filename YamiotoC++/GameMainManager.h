#pragma once

#include <DXLib.h>
#include "InputChecker.h"
#include "Sounder.h"
#include "Drawer.h"
#include "Player.h"
#include "Enemy.h"
#include "Questionnaire.h"
#include "Debuger.h"

//==GameMain�V�[�����Ǘ�����N���X
class GameMainManager {
	InputChecker _inputChecker;
	Sounder _sounder;
	Drawer _drawer;
	Player* _player;
	Enemy* _enemy;
	Questionnaire* _questionnaire;
	Debuger* _debuger;
	bool _sceneChangeFlag;			//�V�[���J�ڂ��邩�ǂ����̃t���O
	bool _debug;					//�f�o�b�N���[�h��\�����邩�ǂ����̃t���O
	int _flameCount;				//�t���[����
	int _distance;					//�v���C���[�ƃG�l�~�[�̋���
	int _pPosIndex;					//player�������_player->_prePos�̓Y���ԍ�
	int _ePosIndex;					//enemy �����Ă�_player->_prePos�̓Y���ԍ�
public:
	//---------------------------------------
	//�R���X�g���N�^�E�f�X�g���N�^
	GameMainManager( );
	~GameMainManager( );
	//---------------------------------------
	//---------------------------------------


	//---------------------------------------
	//--�Q�b�^�[
	bool GetSceneChangeFlag( );
	int GetDistance( );
	//---------------------------------------
	//---------------------------------------


	//---------------------------------------
	//--�Z�b�^�[
	void SetSceneChangeFlag( bool x );
	//---------------------------------------
	//---------------------------------------


	void Main( );							//���C���֐�
};

