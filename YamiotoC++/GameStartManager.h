#pragma once

#include <DXLib.h>
#include "InputChecker.h"
#include "Sounder.h"
#include "Drawer.h"
//#include "LoadData.h"

//==GameStart�V�[�����Ǘ�����N���X
class GameStartManager {
	InputChecker _inputChecker;
	Sounder _sounder;
	Drawer _drawer;
	bool _changeSceneFlag;		//�V�[���J�ڂ��邩�ǂ����̃t���O
	bool _sounded;				//������񂾂��Ȃ炷���߂̕ϐ�
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

