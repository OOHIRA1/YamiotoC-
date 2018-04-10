#pragma once

#include <DxLib.h>
#include "Player.h"
#include "Enemy.h"
#include "Questionnaire.h"

struct Fps {
	short int start;	//計測開始時刻（秒）
	short int flame;	//計測開始時刻からのフレーム数
	float save;			//fps
};


//==デバックモードを管理するクラス
class Debuger {
	Player* _player;
	Enemy* _enemy;
	Questionnaire* _questionnaire;
	struct Fps _fpsCounter;				//fps表示用構造体
public:
	//------------------------------------------------
	//--コンストラクタ・デストラクタ
	Debuger( Player* player, Enemy* enemy, Questionnaire* questionnaire );
	~Debuger( );
	//------------------------------------------------
	//------------------------------------------------


	//------------------------------------------------
	//--ゲッター
	//------------------------------------------------
	//------------------------------------------------


	//------------------------------------------------
	//--セッター
	//------------------------------------------------
	//------------------------------------------------


	void DebugMainScene( int distance, int pPosIndex, int ePosIndex );								//--デバックモードを表示する関数(GameMainSceneのみ使用可能)
	void DebugFPS( );																				//--FPSを表示する関数
};

