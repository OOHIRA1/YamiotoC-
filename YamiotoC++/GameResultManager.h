#pragma once

//#include <DXLib.h>
#include "Drawer.h"
#include "InputChecker.h"
#include "Sounder.h"
#include "Player.h"
#include "WindowInformation.h"

const int GAME_OVER_WAIT_FLAME = 120;

//==GameResult�V�[�����Ǘ�����N���X
class GameResultManager{
	Drawer* _drawer;
	InputChecker* _inputChecker;
	Sounder* _sounder;
	Player* _player;
	bool _sceneChangeFlag;					//�V�[���J�ڂ��邩�ǂ����̃t���O
	bool _BGMsounded;						//BGM����񂾂��Ȃ炷���߂̕ϐ�
	bool _pushed;							//�{�^�������������ǂ����̃t���O
	int _gameOverWaitCount;					//�Q�[���I�[�o�[�̊Ԃ����邽�߂̕ϐ�
	struct TwoPointPicture _enemyImage;		//�G�l�~�[�̉摜
	int f = 10;
public:
	//--------------------------------------------
	//--�R���X�g���N�^�E�f�X�g���N�^
	GameResultManager( Drawer* drawer, InputChecker* inputChecker, Sounder* sounder, Player* player );
	~GameResultManager( );
	//--------------------------------------------
	//--------------------------------------------


	//--------------------------------------------
	//--�Q�b�^�[
	bool GetSceneChangeFlag( );
	//--------------------------------------------
	//--------------------------------------------


	//--------------------------------------------
	//--�Z�b�^�[
	void SetSceneChangeFlag( bool x );
	//--------------------------------------------
	//--------------------------------------------


	void Main( );								//--���C���֐�
	void DrawPushButton( );						//--PushButton��\������֐�
};

