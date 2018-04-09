#pragma once

#include <DxLib.h>
#include "InputChecker.h"
#include "Sounder.h"
#include "Drawer.h"
#include "Player.h"
#include "Enemy.h"
#include "Questionnaire.h"
#include "Debuger.h"

const int CLEAR = 10;										//�K�v����

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
	int _bright;						//--aka.png�̖��邳
	bool _brighting;					//--aka.png�����邭�Ȃ��Ă��邩�ǂ����̃t���O
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


	void Main( );							//--���C���֐�
	void UpdatePlayerPrePos( );				//--�v���C���[�̍��W��_player->_prePos�ɓ����֐�
	void UpdateQFinished( );				//--�o�肵�����Ƀt���O�𗧂đS�Ă̖�肪�o���烊�Z�b�g����֐�
	void DrawDgreeOfRisk( );				//--�댯�x��\������֐�(�G�l�~�[���߂Â��Ɖ�ʂ��Ԃ��Ȃ�)
};

