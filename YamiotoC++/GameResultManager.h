#pragma once

#include <DXLib.h>
#include "InputChecker.h"

//==GameResultシーンを管理するクラス
class GameResultManager{
	InputChecker _inputChecker;
	bool _sceneChangeFlag;			//シーン遷移するかどうかのフラグ
public:
	//--------------------------------------------
	//--コンストラクタ・デストラクタ
	GameResultManager( );
	~GameResultManager( );
	//--------------------------------------------
	//--------------------------------------------


	//--------------------------------------------
	//--ゲッター
	bool GetSceneChangeFlag( );
	//--------------------------------------------
	//--------------------------------------------


	//--------------------------------------------
	//--セッター
	void SetSceneChangeFlag( bool x );
	//--------------------------------------------
	//--------------------------------------------


	void Main( );								//メイン関数
};

