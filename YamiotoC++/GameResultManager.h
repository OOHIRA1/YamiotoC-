#pragma once

#include <DXLib.h>
#include "InputChecker.h"

//==GameResult�V�[�����Ǘ�����N���X
class GameResultManager{
	InputChecker _inputChecker;
	bool _sceneChangeFlag;			//�V�[���J�ڂ��邩�ǂ����̃t���O
public:
	//--------------------------------------------
	//--�R���X�g���N�^�E�f�X�g���N�^
	GameResultManager( );
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


	void Main( );								//���C���֐�
};

