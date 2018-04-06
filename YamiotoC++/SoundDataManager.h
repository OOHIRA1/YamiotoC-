#pragma once

#include <DXLib.h>

enum SoundData {	//音データ
	ENEMY_VOICE,
	PLAYER_ASIOTO,
	DOOR,
	DOOR_GATYA,
	SEIKAI,
	MATIGAI,
	GAME_CLEAR,
	GAME_OVER,
	GAME_START_BGM,
	GAME_MAIN_BGM,
	GAME_START_SE,
	SOUND_DATA_MAX
};

//==音データを管理するクラス
class SoundDataManager {
	int _soundHandle[ SOUND_DATA_MAX ];		//音データののハンドル
public:
	//---------------------------------
	//コンストラクタ・デストラクタ
	SoundDataManager( );
	~SoundDataManager( );
	//----------------------------------
	//----------------------------------

	
	//--------------------------------------
	//--ゲッター
	int GetSoundHandle( SoundData soundData );
	//--------------------------------------
	//--------------------------------------


	//---------------------------------
	//--セッター
	//---------------------------------
	//---------------------------------

	void LoadSound( );		//--音データを読み込む関数
};

