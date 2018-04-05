#include <DXLib.h>
#include "InputChecker.h"
#include "Sounder.h"
#include "GameStartManager.h"

const int SCREEN_WIDTH			= 1280;					//�E�B���h�E�̉���
const int SCREEN_HEIGHT		    = 720;					//�E�B���h�E�̏c��
const int SCREEN_WIDTH_CENTER	= 1280 / 2;				//�E�B���h�E���Sx���W
const int SCREEN_HEIGHT_CENTER  = 720 / 2;				//�E�B���h�E���Sy���W

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdshow ) {
	SetWindowText( "�ŉ�" );
	Sounder sounder;
	sounder.Set3DSoundOneMetre( 0.2f );
	ChangeWindowMode( TRUE );
	SetAlwaysRunFlag( TRUE );							//�ʂ̃E�B���h�E�ɐ؂�ւ��Ă��������p�������֐�
	SetWindowSize( SCREEN_WIDTH, SCREEN_HEIGHT );
	SetGraphMode( SCREEN_WIDTH, SCREEN_HEIGHT, 32 );	//�摜�̉𑜓x��ݒ肷��֐�
	SetEnableXAudioFlag( TRUE );						//�T�E���h�̍Đ���XAudio2���g�p���邩�ǂ�����ݒ肷��
	if ( DxLib_Init( ) == -1 ) {
		return -1;
	}


	InputChecker inputChecker;
	GameStartManager start;


	while( 1 ) {
		if ( ScreenFlip( ) != 0 || ProcessMessage( ) != 0 || ClearDrawScreen( ) != 0 ) {
			break;
		}
		start.Main();
		inputChecker.UpdateDevice( );	//�L�[�E�p�b�g���͎�t
		if ( inputChecker.GetKey( KEY_INPUT_ESCAPE ) > 1 ) {	//escape�L�[���������狭���I��
			break;
		}
	}

	DxLib_End( );
	return 0;
}