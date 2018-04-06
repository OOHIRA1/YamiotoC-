#pragma once

#include <DXLib.h>

enum SoundData {	//���f�[�^
	ENEMY_VOICE,
	PLAYER_ASIOTO,
	DOOR,
	DOOR_GATYA,
	SEIKAI,
	MATIGAI,
	GAME_CLEAR,
	GAME_OVER,
	GAME_START_BGM,
	GAME_MAIN_BGM,
	GAME_START_SE,
	SOUND_DATA_MAX
};

//==���f�[�^���Ǘ�����N���X
class SoundDataManager {
	int _soundHandle[ SOUND_DATA_MAX ];		//���f�[�^�̂̃n���h��
public:
	//---------------------------------
	//�R���X�g���N�^�E�f�X�g���N�^
	SoundDataManager( );
	~SoundDataManager( );
	//----------------------------------
	//----------------------------------

	
	//--------------------------------------
	//--�Q�b�^�[
	int GetSoundHandle( SoundData soundData );
	//--------------------------------------
	//--------------------------------------


	//---------------------------------
	//--�Z�b�^�[
	//---------------------------------
	//---------------------------------

	void LoadSound( );		//--���f�[�^��ǂݍ��ފ֐�
};

