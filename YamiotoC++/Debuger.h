#pragma once

#include <DxLib.h>
#include "Drawer.h"
#include "Player.h"
#include "Enemy.h"
#include "Questionnaire.h"

//==デバックモードを管理するクラス
class Debuger: public Drawer {
	Player* _player;
	Enemy* _enemy;
	Questionnaire* _questionnaire;
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


	void Debug( int distance, int pPosIndex, int ePosIndex );										//--デバックモードを表示する関数
};

