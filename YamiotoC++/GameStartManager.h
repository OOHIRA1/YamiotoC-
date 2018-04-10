#pragma once

#include <DXLib.h>
#include "InputChecker.h"
#include "Sounder.h"
#include "Drawer.h"


//==GameStart�V�[�����Ǘ�����N���X
class GameStartManager {
	InputChecker _inputChecker;
	Sounder _sounder;
	Drawer _drawer;
	bool _sceneChangeFlag;			//�V�[���J�ڂ��邩�ǂ����̃t���O
	bool _BGMsounded;				//BGM����񂾂��Ȃ炷���߂̕ϐ�
	bool _pushed;					//�{�^�������������ǂ����̃t���O
public:
	//-------------------------------
	//�R���X�g���N�^�E�f�X�g���N�^
	GameStartManager( );
	~GameStartManager( );
	//-------------------------------
	//-------------------------------


	//--------------------------------------------
	//�Q�b�^�[
	 bool GetSceneChangeFlag( );
	//--------------------------------------------
	//--------------------------------------------


	 //--------------------------------------------
	 //�Z�b�^�[
	 void SetSceneChangeFlag( bool x );
	 //--------------------------------------------
	 //--------------------------------------------


	 void Main( );		//--���C���֐�
};

