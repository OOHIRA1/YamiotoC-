#pragma once

#include <DxLib.h>
#include "InputChecker.h"
#include "Sounder.h"
#include "Drawer.h"
#include "Player.h"
#include "Enemy.h"
#include "Questionnaire.h"
#include "Debuger.h"

const int CLEAR = 10;										//必要正解数

//==GameMainシーンを管理するクラス
class GameMainManager {
	InputChecker _inputChecker;
	Sounder _sounder;
	Drawer _drawer;
	Player* _player;
	Enemy* _enemy;
	Questionnaire* _questionnaire;
	Debuger* _debuger;
	bool _sceneChangeFlag;			//シーン遷移するかどうかのフラグ
	bool _debug;					//デバックモードを表示するかどうかのフラグ
	int _flameCount;				//フレーム数
	int _distance;					//プレイヤーとエネミーの距離
	int _pPosIndex;					//playerが入れる_player->_prePosの添字番号
	int _ePosIndex;					//enemy が見てる_player->_prePosの添字番号
	int _bright;						//--aka.pngの明るさ
	bool _brighting;					//--aka.pngが明るくなっているかどうかのフラグ
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
	int GetDistance( );
	//---------------------------------------
	//---------------------------------------


	//---------------------------------------
	//--セッター
	void SetSceneChangeFlag( bool x );
	//---------------------------------------
	//---------------------------------------


	void Main( );							//--メイン関数
	void UpdatePlayerPrePos( );				//--プレイヤーの座標を_player->_prePosに入れる関数
	void UpdateQFinished( );				//--出題した問題にフラグを立て全ての問題が出たらリセットする関数
	void DrawDgreeOfRisk( );				//--危険度を表示する関数(エネミーが近づくと画面が赤くなる)
};

