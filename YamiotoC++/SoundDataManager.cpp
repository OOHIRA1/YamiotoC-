#include "SoundDataManager.h"


//-------------------------------------------------
//�R���X�g���N�^�E�f�X�g���N�^
SoundDataManager::SoundDataManager( ) {
	LoadSound( );
}


SoundDataManager::~SoundDataManager( ) {
}
//--------------------------------------------------
//--------------------------------------------------


//---------------------------------------------------
//--�Q�b�^�[
int SoundDataManager::GetSoundHandle( SoundData soundData ) {
	return _soundHandle[ soundData ];
}
//---------------------------------------------------
//---------------------------------------------------


//----------------------------------------------------
//--�Z�b�^�[
//----------------------------------------------------
//----------------------------------------------------

//--���f�[�^��ǂݍ��ފ֐�
void SoundDataManager::LoadSound( ) {
	SetCreate3DSoundFlag( TRUE );
	_soundHandle[ ENEMY_VOICE    ] = LoadSoundMem( "Sound/EnemyVoice.wav" );
	SetCreate3DSoundFlag( FALSE );

	_soundHandle[ PLAYER_ASIOTO  ] = LoadSoundMem( "Sound/PlayerAsioto.wav" );
	_soundHandle[ DOOR           ] = LoadSoundMem( "Sound/Door.wav" );
	_soundHandle[ DOOR_GATYA     ] = LoadSoundMem( "Sound/GatyaGatya.wav" );
	_soundHandle[ SEIKAI         ] = LoadSoundMem( "Sound/Seikai.wav" );
	_soundHandle[ MATIGAI        ] = LoadSoundMem( "Sound/Matigai.wav" );
	_soundHandle[ GAME_CLEAR     ] = LoadSoundMem( "Sound/GameClear.wav" );
	_soundHandle[ GAME_OVER      ] = LoadSoundMem( "Sound/GameOver.wav" );
	_soundHandle[ GAME_START_BGM ] = LoadSoundMem( "Sound/GameStart.wav" );
	_soundHandle[ GAME_MAIN_BGM  ] = LoadSoundMem( "Sound/GameMain.wav" );
	_soundHandle[ GAME_START_SE  ] = LoadSoundMem( "Sound/GameStartSE.wav" );
}