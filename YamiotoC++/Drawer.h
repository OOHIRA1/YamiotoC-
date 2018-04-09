#pragma once

#include <DxLib.h>
#include "ImageManager.h"

struct TwoPointPicture {	//2点で表示する画像に使う構造体
	int leftUp_x;
	int leftUp_y;
	int rightDown_x;
	int rightDown_y;
};

//==画面表示を管理するクラス
class Drawer {
	ImageManager _imageManager;
	int _bright;					//画面の明るさ
	bool _brighting;				//画面を明るくしているかどうかのフラグ
	int _alpha;						//画面上にある画像のアルファ値
public:
	//--------------------------------------------
	//コンストラクタ・デストラクタ
	Drawer( );
	~Drawer( );
	//---------------------------------------------
	//--------------------------------------------


	//---------------------------------------------
	//--ゲッター
	ImageManager GetImageManager( );
	int GetAlpha( );
	//---------------------------------------------
	//---------------------------------------------


	//---------------------------------------------
	//--セッター
	void SetAlpha( int x );
	//---------------------------------------------
	//---------------------------------------------


	void DrawGraph( int x, int y, int grHandle, int transFlag );															//--メモリに読みこんだグラフィックの描画する関数
	void FlashGraph( int x, int y, int grHandle );																			//--画像を点滅する関
	void FadeOut( );																										//--フェードアウトする関数
	void DrawString( int x , int y , const TCHAR* string , unsigned int color );											//--文字列を描画する関数
	void DrawCircle( int x, int y, int r, unsigned int color, int fillFlag );												//--円の描画をする関数
	void SetDrawBlendMode( int blendMode , int pal );																		//--描画の際のブレンドモードをセットする関数
	void DrawStringToHandle( int x , int y , const TCHAR* string , unsigned int color , int fontHandle );					//--指定のフォントデータで文字列を描画する関数
	int CreateFontToHandle( const TCHAR* fontName , int size , int thick ) ;												//--新しいフォントデータを作成する関数
	void SetDrawBright( int redBright, int greenBright, int blueBright );													//--描画輝度をセット
	void DrawExtendGraph( int x1, int y1, int x2, int y2, int grHandle , int transFlag ) ;									//--メモリに読みこんだグラフィックの拡大縮小描画する関数
//	void DrawModiGraph( int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, int GrHandle , int TransFlag );		//--メモリに読みこんだグラフィックの自由変形描画する関数
};
