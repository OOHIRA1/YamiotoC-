#pragma once

//#include <DXLib.h>
#include "InputChecker.h"
#include "Drawer.h"
#include "Sounder.h"
#include "Player.h"
#include "WindowInformation.h"

const int GAME_OVER_WAIT_FLAME = 120;

//==GameResultシーンを管理するクラス
class GameResultManager{
	InputChecker _inputChecker;
	Drawer _drawer;
	Sounder/**/ _sounder;
	Player* _player;
	bool _sceneChangeFlag;					//シーン遷移するかどうかのフラグ
	bool _BGMsounded;						//BGMを一回だけならすための変数
	bool _pushed;							//ボタンを押したかどうかのフラグ
	int _gameOverWaitCount;					//ゲームオーバーの間をつくるための変数
	struct TwoPointPicture _enemyImage;		//エネミーの画像
public:
	//--------------------------------------------
	//--コンストラクタ・デストラクタ
	GameResultManager( /*Sounder* sounder,*/ Player* player );
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


	void Main( );								//--メイン関数
	void DrawPushButton( );						//--PushButtonを表示する関数
};

