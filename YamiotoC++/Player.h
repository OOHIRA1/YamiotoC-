#pragma once

#include <DxLib.h>
#include "Sounder.h"

const int FIRST_DISTANCE    = 80;							//playerとenemeyの初期距離(playerの初期ｚ座標)
const int PRE_POS_MAX_INDEX = 30;							//配列pre_posの要素数
const int ESCAPE_COUNT_MAX  = 200;							//逃げられる最大フレーム数
const int FREEZE_COUNT_MAX  = ESCAPE_COUNT_MAX;				//硬直する最大フレーム数
const int FLAME_PER_PIXEL     = 20;							//1ピクセル進むのにかかるフレーム数


//==プレイヤーを管理するクラス
class Player {
	VECTOR _position;						//プレイヤーの座標
	VECTOR _direction;						//プレイヤーの向いている方向
	VECTOR _prePos[ PRE_POS_MAX_INDEX ];	//プレイヤーがいた座標（道選択時の座標）を記憶する配列
	int _answerCount;						//正解数	//最初にanswerをtureで処理するため-1で初期化※道選択実装前
	int _notAnswerCount;					//不正解数
	int _movedCount;						//プレイヤーが逃げたフレーム数を格納する変数
	int _freezedCount;						//プレイヤーが硬直したフレーム数を格納する変数
	Sounder* _sounder;
public:
	//-------------------------------
	//コンストラクタ・デストラクタ
	Player( Sounder* sounder );
	~Player( );
	//-------------------------------
	//-------------------------------


	//---------------------------------------------------
	//--ゲッター
	VECTOR GetPlayerPosition( );
	int GetAnswerCount( );
	int GetNotAnswerCount( );
	int GetMovedCount( );
	VECTOR* GetPrePos( );
	//---------------------------------------------------
	//---------------------------------------------------


	//---------------------------------------------------
	//--セッター
	void SetPrePos( int index, VECTOR position );
	//---------------------------------------------------
	//---------------------------------------------------
	//---------------------------------------------------


	void MoveForwardPixel( int pixel );					//--playerが前方にpixelピクセル移動する関数
	void MoveLeftPixel   ( int pixel );					//--playerが左　にpixelピクセル移動する関数
	void MoveRightPixel  ( int pixel );					//--playerが右　にpixelピクセル移動する関数
	void MoveForward( int escapeCount, int flamePerPixel );					//--playerが前方にescapeCountフレームの間１ピクセル当たりflamePerPixelフレームで移動する関数
	void MoveLeft   ( int escapeCount, int flamePerPixel );					//--playerが左　にescapeCountフレームの間１ピクセル当たりflamePerPixelフレームで移動する関数
	void MoveRight  ( int escapeCount, int flamePerPixel );					//--playerが右　にescapeCountフレームの間１ピクセル当たりflamePerPixelフレームで移動する関数
	void SoundASIOTO( );													//--足音を鳴らす関数(ループ再生)
	void StopASIOTO( );														//--足音を止める関数
	void StopASIOTOAndLookForward( );										//--足音を止め、正面を向く関数
	void KnockDoor( );														//--ドアをガチャガチャする関数
	void OpenDoor( );														//--ドアを開ける関数
	void PlusAnswerCount( );												//--_answerCountを一つ増やす関数
	void PlusNotAnswerCount( );												//--_notAnswerCountを一つ増やす関数
	void ResetMovedCount( );												//--_movedCountをリセットする(0にする)関数
	void ResetFreezedCount( );												//--_freezedCountをリセットする(0にする)関数
};

