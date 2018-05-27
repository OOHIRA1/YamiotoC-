#pragma once

#include "Drawer.h"
#include "InputChecker.h"
#include "Sounder.h"

//==シーンを管理するクラス(各シーンの凡化により作成)
class SceneManager {
protected:	//派生クラスでも扱えるようにprotected
	Drawer* _drawer;
	InputChecker* _inputChecker;
	Sounder* _sounder;
	bool _sceneChangeFlag;			//シーン遷移するかどうかのフラグ
public:
	//--------------------------------
	//コンストラクタ・デストラクタ
	SceneManager( Drawer* drawer, InputChecker* inputChecker, Sounder* sounder );
	virtual ~SceneManager( );	//派生クラスのデストラクタが使えるように仮想デストラクタにしている
	//--------------------------------
	//--------------------------------
	
	//--------------------------------------------
	//--ゲッター
	bool GetSceneChangeFlag( ) const{
		return _sceneChangeFlag;
	}
	//--------------------------------------------
	//--------------------------------------------


	//--------------------------------------------
	//--セッター
	void SetSceneChangeFlag( bool x ) {
		_sceneChangeFlag = x;
	}
	//--------------------------------------------
	//--------------------------------------------

	virtual void Main( ) = 0;		//--メイン関数
};

