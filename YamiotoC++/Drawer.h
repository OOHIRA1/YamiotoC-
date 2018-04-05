#pragma once

#include <DxLib.h>

//==画面表示を管理するクラス
class Drawer {
	int _bright;	//画面の明るさ
	int _alpha;		//画面上にある画像のアルファ値
public:
	//--------------------------------------------
	//コンストラクタ・デストラクタ
	Drawer( );
	~Drawer( );
	//---------------------------------------------
	//--------------------------------------------

	void DrawGraph( int x, int y, int grHandle, int transFlag );							//--メモリに読みこんだグラフィックの描画する関数
	void FlashGraph( int x, int y, int grHandle );											//--画像を点滅する関
	void FadeOut( );																		//--フェードアウトする関数
	void DrawFormatString( int x, int y, unsigned int color, char *formatString );			//--書式付き文字列を描画する関数(DxLib::DrawFormatStringより汎用性低)
	void DrawCircle( int x, int y, int r, unsigned int color, int fillFlag );				//--円の描画をする関数

};

