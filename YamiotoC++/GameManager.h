#pragma once

#include "GameStartManager.h"
#include "GameMainManager.h"
#include "GameResultManager.h"
#include "Drawer.h"
#include "InputChecker.h"
#include "Sounder.h"

enum GameStatus {	//�V�[��
	GAME_START,
	GAME_MAIN,
	GAME_RESULT
};


//==�V�[���S��(�Q�[���S��)���Ǘ�����N���X
class GameManager{
	Drawer _drawer;
	InputChecker _inputChecker;
	Sounder _sounder;
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
	InputChecker* GetInputChecker( );
	//-----------------------------------
	//-----------------------------------


	//-----------------------------------
	//--�Z�b�^�[
	//-----------------------------------
	//-----------------------------------


	void Main( );						//--���C���֐�
};

