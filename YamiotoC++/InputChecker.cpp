#include "InputChecker.h"


//---------------------------------
//コンストラクタ・デストラクタ
InputChecker::InputChecker( ){
}


InputChecker::~InputChecker( ){
}
//---------------------------------
//---------------------------------

//--------------------------------------------------
//ゲッター
int InputChecker::GetKey( int key ) {
	return _key[ key ];
}
//-------------------------------------------------
//-------------------------------------------------


//--キーボードを操作したかどうかを確認する関数
void InputChecker::UpdateKey( ) {
	char key_c[ KEY_MAX ];		//キーが押されたかどうかを確認する変数

	GetHitKeyStateAll( key_c );

	for ( int i = 0; i < KEY_MAX; i++ ) {
		if ( key_c[ i ] == 1 ) {
			++_key[ i ];
		} else {
			_key[ i ] = 0;
		}
	}
}


//--ジョイパット操作をしたかどうかを確認する関数
void InputChecker::UpdateJoypad( ) {
	int pad_c[ JOYPADMAX ] = {	//パットが押されたかどうかを確認する変数
		PAD_INPUT_DOWN, 
		PAD_INPUT_LEFT, 
		PAD_INPUT_RIGHT, 
		PAD_INPUT_UP, 
		PAD_INPUT_1,
		PAD_INPUT_2,
		PAD_INPUT_3,
		PAD_INPUT_4 
	};

	for ( int i = 0; i < JOYPADMAX; i++ ) {
		if ( GetJoypadInputState( DX_INPUT_KEY_PAD1 ) & pad_c[ i ] ) {
			++_joypad[ i ];
		} else {
			_joypad[ i ] = 0;
		}
	}
}


//--キーボードまたはジョイパットを操作したか確認する関数
void InputChecker::UpdateDevice( ) {
	UpdateKey( );
	UpdateJoypad( );
}
