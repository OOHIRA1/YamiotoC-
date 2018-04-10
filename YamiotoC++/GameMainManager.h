#pragma once

#include "Drawer.h"
#include "InputChecker.h"
#include "Sounder.h"
#include "Player.h"
#include "Enemy.h"
#include "Questionnaire.h"
#include "Debuger.h"
#include "WindowInformation.h"

const int FULL_SCREEN_FLAME = ESCAPE_COUNT_MAX - 50;					//�E�o���̌��摜���S��ʂɕ\�������t���[����
const int RATE_X = SCREEN_WIDTH_CENTER / FULL_SCREEN_FLAME;				//�E�o���̌��摜�̊g�呝����x
const int RATE_Y = SCREEN_HEIGHT_CENTER / FULL_SCREEN_FLAME;			//�E�o���̌��摜�̊g�呝����y


//==GameMain�V�[�����Ǘ�����N���X
class GameMainManager {
	Drawer* _drawer;
	InputChecker* _inputChecker;
	Sounder* _sounder;
	Player* _player;
	Enemy* _enemy;
	Questionnaire* _questionnaire;
	Debuger* _debuger;
	bool _sceneChangeFlag;					//�V�[���J�ڂ��邩�ǂ����̃t���O
	bool _debug;							//�f�o�b�N���[�h��\�����邩�ǂ����̃t���O
	int _flameCount;						//�t���[����
	int _distance;							//�v���C���[�ƃG�l�~�[�̋���
	int _pPosIndex;							//player�������_player->_prePos�̓Y���ԍ�
	int _ePosIndex;							//enemy �����Ă�_player->_prePos�̓Y���ԍ�
	int _bright;							//--aka.png�̖��邳
	bool _brighting;						//--aka.png�����邭�Ȃ��Ă��邩�ǂ����̃t���O
	struct TwoPointsPicture _lightImage;		//�E�o���̌��摜
public:
	//---------------------------------------
	//�R���X�g���N�^�E�f�X�g���N�^
	GameMainManager( Drawer* drawer, InputChecker* inputChecker, Sounder* sounder );
	~GameMainManager( );
	//---------------------------------------
	//---------------------------------------


	//---------------------------------------
	//--�Q�b�^�[
	Player* GetPlayer( );
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
private:
	void UpdatePlayerPrePos( );				//--�v���C���[�̍��W��_player->_prePos�ɓ����֐�
	void UpdateQFinished( );				//--�o�肵�����Ƀt���O�𗧂đS�Ă̖�肪�o���烊�Z�b�g����֐�
	void DrawDgreeOfRisk( );				//--�댯�x��\������֐�(�G�l�~�[���߂Â��Ɖ�ʂ��Ԃ��Ȃ�)
	void StopSound( );						//--GameMain�V�[���ŗ���Ă��鉹(BGM�E�G�l�~�[�̉̐��E����)���~����֐�
};

