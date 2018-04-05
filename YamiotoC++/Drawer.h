#pragma once

#include <DxLib.h>

//==��ʕ\�����Ǘ�����N���X
class Drawer {
	int _bright;	//��ʂ̖��邳
	int _alpha;		//��ʏ�ɂ���摜�̃A���t�@�l
public:
	//--------------------------------------------
	//�R���X�g���N�^�E�f�X�g���N�^
	Drawer( );
	~Drawer( );
	//---------------------------------------------
	//--------------------------------------------

	void DrawGraph( int x, int y, int grHandle, int transFlag );							//--�������ɓǂ݂��񂾃O���t�B�b�N�̕`�悷��֐�
	void FlashGraph( int x, int y, int grHandle );											//--�摜��_�ł����
	void FadeOut( );																		//--�t�F�[�h�A�E�g����֐�
	void DrawFormatString( int x, int y, unsigned int color, char *formatString );			//--�����t���������`�悷��֐�(DxLib::DrawFormatString���ėp����)
	void DrawCircle( int x, int y, int r, unsigned int color, int fillFlag );				//--�~�̕`�������֐�

};

