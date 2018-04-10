#pragma once

#include "GameStartManager.h"
#include "GameMainManager.h"
#include "GameResultManager.h"
#include "Drawer.h"
#include "InputChecker.h"
#include "Sounder.h"

enum GameStatus {	//シーン
	GAME_START,
	GAME_MAIN,
	GAME_RESULT
};


//==シーン全体(ゲーム全体)を管理するクラス
class GameManager{
	Drawer _drawer;
	InputChecker _inputChecker;
	Sounder _sounder;
	GameStartManager* _gameStartManager;
	GameMainManager* _gameMainManager;
	GameResultManager* _gameResultManager;
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

