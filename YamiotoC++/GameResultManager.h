#pragma once

#include "WindowInformation.h"
#include "SceneManager.h"
#include "Player.h"

const int GAME_OVER_WAIT_FLAME = 120;

//==GameResultシーンを管理するクラス
class GameResultManager : public SceneManager {
	Player* _player;
	bool _BGMsounded;						//BGMを一回だけならすための変数
	bool _pushed;							//ボタンを押したかどうかのフラグ
	int _gameOverWaitCount;					//ゲームオーバーの間をつくるための変数
	struct TwoPointsPicture _enemyImage;		//エネミーの画像
public:
	//--------------------------------------------
	//--コンストラクタ・デストラクタ
	GameResultManager( Drawer* drawer, InputChecker* inputChecker, Sounder* sounder, Player* player );
	~GameResultManager( );
	//--------------------------------------------
	//--------------------------------------------


	//--------------------------------------------
	//--ゲッター
	//--------------------------------------------
	//--------------------------------------------


	//--------------------------------------------
	//--セッター
	//--------------------------------------------
	//--------------------------------------------


	void Main( );								//--メイン関数
private:
	void DrawPushButton( );						//--PushButtonを表示する関数
};

