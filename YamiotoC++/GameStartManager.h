#pragma once

#include <DXLib.h>
#include "Drawer.h"
#include "InputChecker.h"
#include "Sounder.h"


//==GameStart�V�[�����Ǘ�����N���X
class GameStartManager {
	Drawer* _drawer;
	InputChecker* _inputChecker;
	Sounder* _sounder;
	bool _sceneChangeFlag;			//�V�[���J�ڂ��邩�ǂ����̃t���O
	bool _BGMsounded;				//BGM����񂾂��Ȃ炷���߂̕ϐ�
	bool _pushed;					//�{�^�������������ǂ����̃t���O
	int f = 10;
public:
	//-------------------------------
	//�R���X�g���N�^�E�f�X�g���N�^
	GameStartManager( Drawer* drawer, InputChecker* inputChecker, Sounder* sounder );
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

