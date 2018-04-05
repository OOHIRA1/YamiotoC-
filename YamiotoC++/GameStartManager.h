#pragma once

#include <DXLib.h>
#include "InputChecker.h"
#include "Sounder.h"
#include "Drawer.h"
//#include "LoadData.h"

//==GameStartシーンを管理するクラス
class GameStartManager {
	InputChecker _inputChecker;
	Sounder _sounder;
	Drawer _drawer;
	bool _changeSceneFlag;		//シーン遷移するかどうかのフラグ
	bool _sounded;				//音を一回だけならすための変数
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

