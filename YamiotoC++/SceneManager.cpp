#include "SceneManager.h"


//--------------------------------------------------
//�R���X�g���N�^�E�f�X�g���N�^
SceneManager::SceneManager( Drawer* drawer, InputChecker* inputChecker, Sounder* sounder ) {
	_drawer = drawer;
	_inputChecker = inputChecker;
	_sounder = sounder;
	_sceneChangeFlag = false;
}


SceneManager::~SceneManager( ) {
}
//--------------------------------------------------
//--------------------------------------------------