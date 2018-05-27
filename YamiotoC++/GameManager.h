#pragma once

#include "Drawer.h"
#include "InputChecker.h"
#include "Sounder.h"
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
	Drawer _drawer;								//������Drawer, InputChecker, Sounder��錾���ĎQ�Ƃ��e�V�[���ɓn���悤�ɂ���
	InputChecker _inputChecker;
	Sounder _sounder;
	SceneManager* _sceneManager;
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

