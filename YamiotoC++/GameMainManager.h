#pragma once

#include <DXLib.h>
#include "InputChecker.h"
#include "Sounder.h"
#include "Drawer.h"
#include "Questionnaire.h"

//==GameMain�V�[�����Ǘ�����N���X
class GameMainManager {
	InputChecker _inputChecker;
	Sounder _sounder;
	Drawer _drawer;
	Questionnaire* _questionnaire;
	bool _sceneChangeFlag;			//�V�[���J�ڂ��邩�ǂ����̃t���O
public:
	//---------------------------------------
	//�R���X�g���N�^�E�f�X�g���N�^
	GameMainManager( );
	~GameMainManager( );
	//---------------------------------------
	//---------------------------------------


	//---------------------------------------
	//--�Q�b�^�[
	bool GetSceneChangeFlag( );
	//---------------------------------------
	//---------------------------------------


	//---------------------------------------
	//--�Z�b�^�[
	void SetSceneChangeFlag( bool x );
	//---------------------------------------
	//---------------------------------------


	void Main( );							//���C���֐�
};

