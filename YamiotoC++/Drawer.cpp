#include "Drawer.h"


//--------------------------------------------
//コンストラクタ・デストラクタ
Drawer::Drawer( ) {
	_bright = 255;
	_brighting = false;
	_alpha = 255;
}


Drawer::~Drawer( ) {
}
//---------------------------------------------
//--------------------------------------------


//---------------------------------------------
//--ゲッター
ImageManager Drawer::GetImageManager( ) {
	return _imageManager;
}


int Drawer::GetAlpha( ){
	return _alpha;
}
//---------------------------------------------
//---------------------------------------------


//---------------------------------------------
//--セッター
void Drawer::SetAlpha( int x ) {
	_alpha = x;
}
//---------------------------------------------
//---------------------------------------------



//--//メモリに読みこんだグラフィックの描画
void Drawer::DrawGraph( int x, int y, int grHandle, int transFlag ) {
	DxLib::DrawGraph( x, y, grHandle, transFlag );
}


//--画像を点滅する関数
void Drawer::FlashGraph( int x, int y, int grHandle ) {
	if ( _brighting ) {
		_bright += 3;
	} else {
		_bright -= 3;
	}
	if ( _bright <= 0   ) _brighting = true;
	if ( _bright >= 255 ) _brighting = false;
	SetDrawBlendMode( DX_BLENDMODE_ALPHA, _bright );
	DrawGraph( x, y, grHandle, TRUE );
	SetDrawBlendMode( DX_BLENDMODE_ALPHA, 255 );
}


//--フェードアウトする関数
void Drawer::FadeOut( ) {
	if ( _alpha > 0 ) _alpha -= 2;
	if ( _alpha < 0 ) _alpha = 0;
	SetDrawBlendMode( DX_BLENDMODE_ALPHA, _alpha );
}


//--書式付き文字列を描画する関数(DxLib::DrawFormatStringより汎用性低)
void Drawer::DrawFormatString( int x, int y, unsigned int color, char *formatString ) {
	DxLib::DrawFormatString( x, y, color, (const TCHAR*)*formatString );
}


//--円の描画をする関数
void Drawer::DrawCircle( int x, int y, int r, unsigned int color, int fillFlag ) {
	DxLib::DrawCircle( x, y, r, color, fillFlag );
}


//--描画の際のブレンドモードをセットする関数
void Drawer::SetDrawBlendMode( int blendMode, int pal ) {
	DxLib::SetDrawBlendMode( blendMode, pal );
}