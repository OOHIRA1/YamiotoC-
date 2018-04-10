#pragma once

#include <DXLib.h>
#include "InputChecker.h"
#include "Sounder.h"
#include "Drawer.h"


//==GameStartシーンを管理するクラス
class GameStartManager {
	InputChecker _inputChecker;
	Sounder _sounder;
	Drawer _drawer;
	bool _sceneChangeFlag;			//シーン遷移するかどうかのフラグ
	bool _BGMsounded;				//BGMを一回だけならすための変数
	bool _pushed;					//ボタンを押したかどうかのフラグ
public:
	//-------------------------------
	//コンストラクタ・デストラクタ
	GameStartManager( );
	~GameStartManager( );
	//-------------------------------
	//-------------------------------


	//--------------------------------------------
	//ゲッター
	 bool GetSceneChangeFlag( );
	//--------------------------------------------
	//--------------------------------------------


	 //--------------------------------------------
	 //セッター
	 void SetSceneChangeFlag( bool x );
	 //--------------------------------------------
	 //--------------------------------------------


	 void Main( );		//--メイン関数
};

