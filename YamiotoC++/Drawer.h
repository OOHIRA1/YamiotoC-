#pragma once

#include <DxLib.h>
#include "ImageManager.h"

//==��ʕ\�����Ǘ�����N���X
class Drawer {
	ImageManager _imageManager;
	int _bright;					//��ʂ̖��邳
	bool _brighting;				//��ʂ𖾂邭���Ă��邩�ǂ����̃t���O
	int _alpha;						//��ʏ�ɂ���摜�̃A���t�@�l
public:
	//--------------------------------------------
	//�R���X�g���N�^�E�f�X�g���N�^
	Drawer( );
	~Drawer( );
	//---------------------------------------------
	//--------------------------------------------


	//---------------------------------------------
	//--�Q�b�^�[
	ImageManager GetImageManager( );
	int GetAlpha( );
	//---------------------------------------------
	//---------------------------------------------


	//---------------------------------------------
	//--�Z�b�^�[
	void SetAlpha( int x );
	//---------------------------------------------
	//---------------------------------------------


	void DrawGraph( int x, int y, int grHandle, int transFlag );												//--�������ɓǂ݂��񂾃O���t�B�b�N�̕`�悷��֐�
	void FlashGraph( int x, int y, int grHandle );																//--�摜��_�ł����
	void FadeOut( );																							//--�t�F�[�h�A�E�g����֐�
	void DrawString( int x , int y , const TCHAR* string , unsigned int color );								//--�������`�悷��֐�
	void DrawCircle( int x, int y, int r, unsigned int color, int fillFlag );									//--�~�̕`�������֐�
	void SetDrawBlendMode( int blendMode , int pal );															//--�`��̍ۂ̃u�����h���[�h���Z�b�g����֐�
	void DrawStringToHandle( int x , int y , const TCHAR* string , unsigned int color , int fontHandle );		//--�w��̃t�H���g�f�[�^�ŕ������`�悷��֐�
	int CreateFontToHandle( const TCHAR* fontName , int size , int thick ) ;									//--�V�����t�H���g�f�[�^���쐬����֐�
	void SetDrawBright( int redBright, int greenBright, int blueBright );										//--�`��P�x���Z�b�g
};

