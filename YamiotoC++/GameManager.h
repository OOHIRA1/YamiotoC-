#pragma once

#include <DXLib.h>
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
	//-----------------------------------
	//-----------------------------------


	//-----------------------------------
	//--セッター
	//-----------------------------------
	//-----------------------------------


	void Main( );						//--メイン関数
};

