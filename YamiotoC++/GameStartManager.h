#pragma once

#include <DXLib.h>
#include "Drawer.h"
#include "InputChecker.h"
#include "Sounder.h"


//==GameStartシーンを管理するクラス
class GameStartManager {
	Drawer* _drawer;
	InputChecker* _inputChecker;
	Sounder* _sounder;
	bool _sceneChangeFlag;			//シーン遷移するかどうかのフラグ
	bool _BGMsounded;				//BGMを一回だけならすための変数
	bool _pushed;					//ボタンを押したかどうかのフラグ
	int f = 10;
public:
	//-------------------------------
	//コンストラクタ・デストラクタ
	GameStartManager( Drawer* drawer, InputChecker* inputChecker, Sounder* sounder );
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

