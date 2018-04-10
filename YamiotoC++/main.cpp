#include <DXLib.h>
#include "WindowInformation.h"
#include "GameManager.h"

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdshow ) {
	SetWindowText( "�ŉ�" );
	Sounder::Set3DSoundOneMetre( 0.2f );
	ChangeWindowMode( TRUE );
	SetAlwaysRunFlag( TRUE );							//�ʂ̃E�B���h�E�ɐ؂�ւ��Ă��������p�������֐�
	SetWindowSize( SCREEN_WIDTH, SCREEN_HEIGHT );
	SetGraphMode( SCREEN_WIDTH, SCREEN_HEIGHT, 32 );	//�摜�̉𑜓x��ݒ肷��֐�
	SetEnableXAudioFlag( TRUE );						//�T�E���h�̍Đ���XAudio2���g�p���邩�ǂ�����ݒ肷��
	if ( DxLib_Init( ) == -1 ) {
		return -1;
	}

	GameManager gameManager;

	while( 1 ) {
		if ( ScreenFlip( ) != 0 || ProcessMessage( ) != 0 || ClearDrawScreen( ) != 0 ) {
			break;
		}

		gameManager.Main( );
		gameManager.GetInputChecker( )->UpdateDevice( );	//�L�[�E�p�b�g���͎�t
		if ( gameManager.GetInputChecker( )->GetKey( KEY_INPUT_ESCAPE ) > 1 ) {		//escape�L�[���������狭���I��
			break;
		}
	}

	DxLib_End( );
	return 0;
}