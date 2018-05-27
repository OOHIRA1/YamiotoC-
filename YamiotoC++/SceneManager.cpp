#include "SceneManager.h"


//--------------------------------------------------
//コンストラクタ・デストラクタ
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