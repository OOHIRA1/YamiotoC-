#pragma once

#include <DXLib.h>
#include "InputChecker.h"
#include "Sounder.h"
#include "Drawer.h"
#include "Player.h"
#include "Enemy.h"
#include "Questionnaire.h"
#include "Debuger.h"

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


	void Main( );							//メイン関数
};

