#pragma once

#include <DXLib.h>

enum ResourceData {	//�摜�f�[�^
	GAME_OVER_IMAGE,
	HIKARI_IMAGE,
	GAME_CLEAR_TEXT,
	AKA_IMAGE,
	CURSOR_IMAGE,
	GAME_OVER_TEXT,
	PUSH_BUTTON_TEXT,
	YAMIOTO_TEXT,
	RESOURCE_DATA_MAX
};

//==�摜�f�[�^���Ǘ�����N���X
class ImageManager {
	int _resourceHandle[ RESOURCE_DATA_MAX ];	//�摜�f�[�^�̃n���h��
public:
	//------------------------------
	//�R���X�g���N�^�E�f�X�g���N�^
	ImageManager( );
	~ImageManager( );
	//-------------------------------
	//-------------------------------

	void LoadResource( );	//�摜�f�[�^��ǂݍ��ފ֐�
};

