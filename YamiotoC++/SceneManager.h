#pragma once

#include "Drawer.h"
#include "InputChecker.h"
#include "Sounder.h"

//==�V�[�����Ǘ�����N���X(�e�V�[���̖}���ɂ��쐬)
class SceneManager {
protected:	//�h���N���X�ł�������悤��protected
	Drawer* _drawer;
	InputChecker* _inputChecker;
	Sounder* _sounder;
	bool _sceneChangeFlag;			//�V�[���J�ڂ��邩�ǂ����̃t���O
public:
	//--------------------------------
	//�R���X�g���N�^�E�f�X�g���N�^
	SceneManager( Drawer* drawer, InputChecker* inputChecker, Sounder* sounder );
	virtual ~SceneManager( );	//�h���N���X�̃f�X�g���N�^���g����悤�ɉ��z�f�X�g���N�^�ɂ��Ă���
	//--------------------------------
	//--------------------------------
	
	//--------------------------------------------
	//--�Q�b�^�[
	bool GetSceneChangeFlag( ) const{
		return _sceneChangeFlag;
	}
	//--------------------------------------------
	//--------------------------------------------


	//--------------------------------------------
	//--�Z�b�^�[
	void SetSceneChangeFlag( bool x ) {
		_sceneChangeFlag = x;
	}
	//--------------------------------------------
	//--------------------------------------------

	virtual void Main( ) = 0;		//--���C���֐�
};

