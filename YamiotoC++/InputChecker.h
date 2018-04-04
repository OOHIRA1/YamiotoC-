#pragma once

#include <DXLib.h>

const int KEY_MAX = 256;
enum Joypad {	//ジョイパット
	DOWN,
	LEFT,
	RIGHT,
	UP,
	INPUT_1,
	INPUT_2,
	INPUT_3,
	INPUT_4,
	JOYPADMAX
};


//==キー・パット入力を管理するクラス
class InputChecker{
	int _key[ KEY_MAX ];		//キーの押されているフレーム数を格納する変数
	int _joypad[ JOYPADMAX ];	//パットの押されているフレーム数を格納する変数
public:
	//---------------------------------
	//コンストラクタ・デストラクタ
	InputChecker( );
	~InputChecker( );
	//---------------------------------
	//---------------------------------

	//---------------------------------
	//ゲッター
	int GetKey( int key );
	//---------------------------------
	//---------------------------------

	void UpdateKey( );			//--キーボードを操作したかどうかを確認する関数
	void UpdateJoypad( );		//--ジョイパット操作をしたかどうかを確認する関数
	void UpdateDevice( );		//--キーボードまたはジョイパットを操作したか確認する関数
private:

};

