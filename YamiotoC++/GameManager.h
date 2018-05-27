#pragma once

#include "Drawer.h"
#include "InputChecker.h"
#include "Sounder.h"
#include "GameStartManager.h"
#include "GameMainManager.h"
#include "GameResultManager.h"

enum GameStatus {	//シーン
	GAME_START,
	GAME_MAIN,
	GAME_RESULT
};


//==シーン全体(ゲーム全体)を管理するクラス
class GameManager{
	Drawer _drawer;								//ここでDrawer, InputChecker, Sounderを宣言して参照を各シーンに渡すようにする
	InputChecker _inputChecker;
	Sounder _sounder;
	SceneManager* _sceneManager;
	GameStatus _gameStatus;						//現在のシーンを表す変数
public:
	//----------------------------------
	//コンストラクタ・デストラクタ
	GameManager( );
	~GameManager( );
	//----------------------------------
	//----------------------------------


	//-----------------------------------
	//--ゲッター
	InputChecker* GetInputChecker( );
	//-----------------------------------
	//-----------------------------------


	//-----------------------------------
	//--セッター
	//-----------------------------------
	//-----------------------------------


	void Main( );						//--メイン関数
};

