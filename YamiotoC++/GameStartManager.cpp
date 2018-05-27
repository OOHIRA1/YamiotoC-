#include "GameStartManager.h"
#include "WindowInformation.h"


//--------------------------------------------
//�R���X�g���N�^�E�f�X�g���N�^
GameStartManager::GameStartManager( Drawer* drawer, InputChecker* inputChecker, Sounder* sounder ) :SceneManager( drawer, inputChecker, sounder ){
	_BGMsounded = false;
	_pushed = false;
}


GameStartManager::~GameStartManager( ) {
	_drawer->SetAlpha( 255 );	//�t�F�[�h�A�E�g��̃A���t�@�l�����ɖ߂�
	_drawer->SetDrawBlendMode( DX_BLENDMODE_ALPHA, _drawer->GetAlpha( ) );
}
//---------------------------------------------
//--------------------------------------------


//--------------------------------------------
//--�Q�b�^�[
//--------------------------------------------
//--------------------------------------------


//--------------------------------------------
//--�Z�b�^�[
//--------------------------------------------
//--------------------------------------------

//--���C���֐�
void GameStartManager::Main( ) {
	if ( GetSceneChangeFlag( ) ) return;	//�V�[���J�ڃt���O�������Ă��鎞�͏��������Ȃ�

	//�X�^�[�g��ʂ�BGM�𗬂�����---------------------------------------------------
	int soundHandle = _sounder->GetSoundDataManager( ).GetSoundHandle( GAME_START_BGM );
	if ( !_BGMsounded ) {
		_sounder->ChangeVolumeSoundMem( soundHandle, 100 );
		_sounder->PlaySoundMem( soundHandle, DX_PLAYTYPE_LOOP, TRUE );
		_BGMsounded = true;
	}
	//------------------------------------------------------------------------------

	//�^�C�g���\��------------------------------------------------------------------
	int grHandle  = _drawer->GetImageManager( ).GetResourceHandle( YAMIOTO_TEXT );
	int grHandle2 = _drawer->GetImageManager( ).GetResourceHandle( PUSH_BUTTON_TEXT );
	_drawer->DrawGraph( SCREEN_WIDTH_CENTER - 148, SCREEN_HEIGHT_CENTER - 100, grHandle, TRUE );
	if ( !_pushed ) {
		_drawer->FlashGraph( SCREEN_WIDTH_CENTER - 80, SCREEN_HEIGHT_CENTER + 100, grHandle2 );
	}
	//------------------------------------------------------------------------------

	//�L�[��t----------------------------------------------------------------------
	//_inputChecker->UpdateDevice( );	//main.cpp�ōs���Ă���̂ł��Ȃ��Ă悢

	int soundHandle2 = _sounder->GetSoundDataManager( ).GetSoundHandle( GAME_START_SE );
	if ( _inputChecker->GetKey( KEY_INPUT_RETURN ) == 1 ||
		_inputChecker->GetJoypad( INPUT_1 ) == 1        ||
		_inputChecker->GetJoypad( INPUT_2 ) == 1        ||
		_inputChecker->GetJoypad( INPUT_3 ) == 1        ||
		_inputChecker->GetJoypad( INPUT_4 ) == 1
		) {
		_sounder->StopSoundMem( soundHandle );
		_sounder->ChangeVolumeSoundMem( 80, soundHandle2 );
		_sounder->PlaySoundMem( soundHandle2 , DX_PLAYTYPE_BACK, TRUE );
		_pushed = true;
	}
	//------------------------------------------------------------------------------

	//�L�[���͌�̏���--------------------------------------------------------------
	if ( _pushed ) {
		_drawer->FadeOut( );

		if ( _drawer->GetAlpha( ) <= 0 ) {
			_sounder->StopSoundMem( soundHandle2 );
			SetSceneChangeFlag( true );
		}
	}
	//------------------------------------------------------------------------------
}