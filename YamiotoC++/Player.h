#pragma once

#include <DXLib.h>

const int PRE_POS_MAX_INDEX = 30;							//配列pre_posの要素数

//==プレイヤーを管理するクラス
class Player {
	VECTOR _position;
	VECTOR _direction;
	VECTOR _prePos[ PRE_POS_MAX_INDEX ];	//プレイヤーがいた座標（道選択時の座標）を記憶する配列
	int _answerCount;						//正解数	//最初にanswerをtureで処理するため-1で初期化※道選択実装前
	int _notAnswerCount;					//不正解数
	int _escapeCount;						//プレイヤーが逃げられるフレーム数を格納する変数
	int _freezeCount;						//プレイヤーが硬直するフレーム数を格納する変数
public:
	//-------------------------------
	//コンストラクタ・デストラクタ
	Player( );
	~Player( );
	//-------------------------------
	//-------------------------------
};

