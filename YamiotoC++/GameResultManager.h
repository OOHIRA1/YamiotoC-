#pragma once

#include "WindowInformation.h"
#include "SceneManager.h"
#include "Player.h"

const int GAME_OVER_WAIT_FLAME = 120;

//==GameResult�V�[�����Ǘ�����N���X
class GameResultManager : public SceneManager {
	Player* _player;
	bool _BGMsounded;						//BGM����񂾂��Ȃ炷���߂̕ϐ�
	bool _pushed;							//�{�^�������������ǂ����̃t���O
	int _gameOverWaitCount;					//�Q�[���I�[�o�[�̊Ԃ����邽�߂̕ϐ�
	struct TwoPointsPicture _enemyImage;		//�G�l�~�[�̉摜
public:
	//--------------------------------------------
	//--�R���X�g���N�^�E�f�X�g���N�^
	GameResultManager( Drawer* drawer, InputChecker* inputChecker, Sounder* sounder, Player* player );
	~GameResultManager( );
	//--------------------------------------------
	//--------------------------------------------


	//--------------------------------------------
	//--�Q�b�^�[
	//--------------------------------------------
	//--------------------------------------------


	//--------------------------------------------
	//--�Z�b�^�[
	//--------------------------------------------
	//--------------------------------------------


	void Main( );								//--���C���֐�
private:
	void DrawPushButton( );						//--PushButton��\������֐�
};

