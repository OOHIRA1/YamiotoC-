#include "ImageManager.h"


//-------------------------------------------------
//コンストラクタ・デストラクタ
ImageManager::ImageManager( ) {
	LoadResource( );
}


ImageManager::~ImageManager( ) {
}
//-------------------------------------------------
//-------------------------------------------------


//--画像データを読み込む関数
void ImageManager::LoadResource(  ) {
	_resourceHandle[ GAME_OVER_IMAGE	] = LoadGraph( "Resource/gameover.png" );
	_resourceHandle[ HIKARI_IMAGE		] = LoadGraph( "Resource/hikari.png" );
	_resourceHandle[ GAME_CLEAR_TEXT	] = LoadGraph( "Resource/GAME-CLEAR-.png" );
	_resourceHandle[ AKA_IMAGE			] = LoadGraph( "Resource/aka.png" );
	_resourceHandle[ CURSOR_IMAGE		] = LoadGraph( "Resource/cursor.png" );
	_resourceHandle[ GAME_OVER_TEXT		] = LoadGraph( "Resource/GAME-OVER-.png" );
	_resourceHandle[ PUSH_BUTTON_TEXT	] = LoadGraph( "Resource/PUSH-BUTTON.png" );
	_resourceHandle[ YAMIOTO_TEXT		] = LoadGraph( "Resource/yamioto.png" );
}
