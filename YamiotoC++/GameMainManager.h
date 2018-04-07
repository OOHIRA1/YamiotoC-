#pragma once

#include <DXLib.h>
#include "InputChecker.h"

//==GameMainシーンを管理するクラス
class GameMainManager {
	InputChecker _inputChecker;
	bool _sceneChangeFlag;			//シーン遷移するかどうかのフラグ
public:
	//---------------------------------------
	//コンストラクタ・デストラクタ
	GameMainManager( );
	~GameMainManager( );
	//---------------------------------------
	//---------------------------------------


	//---------------------------------------
	//--ゲッター
	bool GetSceneChangeFlag( );
	//---------------------------------------
	//---------------------------------------


	//---------------------------------------
	//--セッター
	void SetSceneChangeFlag( bool x );
	//---------------------------------------
	//---------------------------------------


	void Main( );							//メイン関数
};

