#include "Drawer.h"


//--------------------------------------------
//�R���X�g���N�^�E�f�X�g���N�^
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
//--�Q�b�^�[
ImageManager Drawer::GetImageManager( ) {
	return _imageManager;
}


int Drawer::GetAlpha( ){
	return _alpha;
}
//---------------------------------------------
//---------------------------------------------


//---------------------------------------------
//--�Z�b�^�[
void Drawer::SetAlpha( int x ) {
	_alpha = x;
}
//---------------------------------------------
//---------------------------------------------



//--//�������ɓǂ݂��񂾃O���t�B�b�N�̕`��
void Drawer::DrawGraph( int x, int y, int grHandle, int transFlag ) {
	DxLib::DrawGraph( x, y, grHandle, transFlag );
}


//--�摜��_�ł���֐�
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


//--�t�F�[�h�A�E�g����֐�
void Drawer::FadeOut( ) {
	if ( _alpha > 0 ) _alpha -= 2;
	if ( _alpha < 0 ) _alpha = 0;
	SetDrawBlendMode( DX_BLENDMODE_ALPHA, _alpha );
}


//--�����t���������`�悷��֐�(DxLib::DrawFormatString���ėp����)
void Drawer::DrawFormatString( int x, int y, unsigned int color, char *formatString ) {
	DxLib::DrawFormatString( x, y, color, (const TCHAR*)*formatString );
}


//--�~�̕`�������֐�
void Drawer::DrawCircle( int x, int y, int r, unsigned int color, int fillFlag ) {
	DxLib::DrawCircle( x, y, r, color, fillFlag );
}


//--�`��̍ۂ̃u�����h���[�h���Z�b�g����֐�
void Drawer::SetDrawBlendMode( int blendMode, int pal ) {
	DxLib::SetDrawBlendMode( blendMode, pal );
}