#pragma once

#include <DXLib.h>
#include "GameStartManager.h"
#include "GameMainManager.h"
#include "GameResultManager.h"

enum GameStatus {	//�V�[��
	GAME_START,
	GAME_MAIN,
	GAME_RESULT
};


//==�V�[���S��(�Q�[���S��)���Ǘ�����N���X
class GameManager{
	GameStartManager* _gameStartManager;
	GameMainManager* _gameMainManager;
	GameResultManager* _gameResultManager;
	GameStatus _gameStatus;						//���݂̃V�[����\���ϐ�
public:
	//----------------------------------
	//�R���X�g���N�^�E�f�X�g���N�^
	GameManager( );
	~GameManager( );
	//----------------------------------
	//----------------------------------


	//-----------------------------------
	//--�Q�b�^�[
	//-----------------------------------
	//-----------------------------------


	//-----------------------------------
	//--�Z�b�^�[
	//-----------------------------------
	//-----------------------------------


	void Main( );						//--���C���֐�
};

