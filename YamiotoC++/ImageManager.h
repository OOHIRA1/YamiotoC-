#pragma once

#include <DXLib.h>

enum ResourceData {	//画像データ
	GAME_OVER_IMAGE,
	HIKARI_IMAGE,
	GAME_CLEAR_TEXT,
	AKA_IMAGE,
	CURSOR_IMAGE,
	GAME_OVER_TEXT,
	PUSH_BUTTON_TEXT,
	YAMIOTO_TEXT,
	RESOURCE_DATA_MAX
};

//==画像データを管理するクラス
class ImageManager {
	int _resourceHandle[ RESOURCE_DATA_MAX ];	//画像データのハンドル
public:
	//------------------------------
	//コンストラクタ・デストラクタ
	ImageManager( );
	~ImageManager( );
	//-------------------------------
	//-------------------------------

	void LoadResource( );	//画像データを読み込む関数
};

