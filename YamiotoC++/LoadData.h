#pragma once

#ifndef __LOAD_DATA
#define __LOAD_DATA



#include <DXLib.h>
#include <stdio.h>

//�萔============================================================================================
const int QUESTION_MAX = 20;								//�ő��萔(��̖��W�̒���)
const int QUESTION_ELEMENT = 256;							//��蕶�̈�s�̍ő啶����
const int CHOICES_ELEMENT = 100;							//�I�����̈�s�̍ő啶����

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

enum Difficulty {	//���̓�Փx
	EASY,
	BASIC,
	HARD,
	DIFFICULTYMAX
};
//=================================================================================================


//int soundHandle[ SOUND_DATA_MAX ];		//���f�[�^�̂̃n���h��
//int resourceHandle[ RESOURCE_DATA_MAX ];	//�摜�f�[�^�̃n���h��

struct q_load {
	FILE* fp;																//�t�@�C���^�|�C���^
	char num[ 10 ];															//�e�L�X�g�t�@�C�������₷�����邽�߂ɏ��������ԍ�
	char questionStatement[ 3 * QUESTION_MAX ][ QUESTION_ELEMENT ];			//��蕶
	char choices[ 4 * QUESTION_MAX ][ CHOICES_ELEMENT ];					//�I����
	int answerNum[ QUESTION_MAX ];											//����ԍ�
};
//struct question question[ DIFFICULTYMAX ];										//���Ɋւ���\����


//�֐����^�錾======================================================================
void LoadSound( );		//--���f�[�^��ǂݍ��ފ֐�
void LoadResource( );	//�摜�f�[�^��ǂݍ��ފ֐�
void LoadQuestion( );	//���f�[�^��ǂݍ��ފ֐�
//==================================================================================


//--���f�[�^��ǂݍ��ފ֐�
void LoadSound( int *soundHandle ) {
	SetCreate3DSoundFlag( TRUE );
	soundHandle[ ENEMY_VOICE    ] = LoadSoundMem( "Sound/EnemyVoice.wav" );
	SetCreate3DSoundFlag( FALSE );

	soundHandle[ PLAYER_ASIOTO  ] = LoadSoundMem( "Sound/PlayerAsioto.wav" );
	soundHandle[ DOOR           ] = LoadSoundMem( "Sound/Door.wav" );
	soundHandle[ DOOR_GATYA     ] = LoadSoundMem( "Sound/GatyaGatya.wav" );
	soundHandle[ SEIKAI         ] = LoadSoundMem( "Sound/Seikai.wav" );
	soundHandle[ MATIGAI        ] = LoadSoundMem( "Sound/Matigai.wav" );
	soundHandle[ GAME_CLEAR     ] = LoadSoundMem( "Sound/GameClear.wav" );
	soundHandle[ GAME_OVER      ] = LoadSoundMem( "Sound/GameOver.wav" );
	soundHandle[ GAME_START_BGM ] = LoadSoundMem( "Sound/GameStart.wav" );
	soundHandle[ GAME_MAIN_BGM  ] = LoadSoundMem( "Sound/GameMain.wav" );
	soundHandle[ GAME_START_SE  ] = LoadSoundMem( "Sound/GameStartSE.wav" );
} 


//--�摜�f�[�^��ǂݍ��ފ֐�
void LoadResource( int *resourceHandle ) {
	resourceHandle[ GAME_OVER_IMAGE		] = LoadGraph( "Resource/gameover.png" );
	resourceHandle[ HIKARI_IMAGE		] = LoadGraph( "Resource/hikari.png" );
	resourceHandle[ GAME_CLEAR_TEXT		] = LoadGraph( "Resource/GAME-CLEAR-.png" );
	resourceHandle[ AKA_IMAGE			] = LoadGraph( "Resource/aka.png" );
	resourceHandle[ CURSOR_IMAGE		] = LoadGraph( "Resource/cursor.png" );
	resourceHandle[ GAME_OVER_TEXT		] = LoadGraph( "Resource/GAME-OVER-.png" );
	resourceHandle[ PUSH_BUTTON_TEXT	] = LoadGraph( "Resource/PUSH-BUTTON.png" );
	resourceHandle[ YAMIOTO_TEXT		] = LoadGraph( "Resource/yamioto.png" );
}


//--���f�[�^��ǂݍ��ފ֐�
void LoadQuestion( struct q_load *question[3] ) {
	fopen_s( &question[ 0 ]->fp, "QuestionEasy.txt", "r" );
	fopen_s( &question[ 1 ]->fp, "QuestionBasic.txt", "r" );
	fopen_s( &question[ 2 ]->fp, "QuestionHard.txt", "r" );
	
	for ( int i = 0; i < DIFFICULTYMAX; i++ ) {
		if ( question[ i ]->fp == NULL ) {
			DxLib_End( );
		} else {
			int x = 0;
			int y = 0;
			int z = 0;
			
			while( fscanf_s( question[ i ]->fp, "%s %s %s %s %s %s %s %s %d", 
					question[ i ]->num, 10,
					question[ i ]->questionStatement[ x     ], QUESTION_ELEMENT, 
					question[ i ]->questionStatement[ x + 1 ], QUESTION_ELEMENT, 
					question[ i ]->questionStatement[ x + 2 ], QUESTION_ELEMENT, 
					question[ i ]->choices[ y     ], CHOICES_ELEMENT, 
					question[ i ]->choices[ y + 1 ], CHOICES_ELEMENT, 
					question[ i ]->choices[ y + 2 ], CHOICES_ELEMENT, 
					question[ i ]->choices[ y + 3 ], CHOICES_ELEMENT, 
					&question[ i ]->answerNum[ z ] ) == 9 ) {
				x += 3;
				y += 4;
				z += 1;
			}
		}
		fclose( question[ i ]->fp );

		//�@'/'����菜������------------------------------------------------------------------------------------
		for ( int j = 0; j < 3 * QUESTION_MAX; j++ ) {
			if ( question[ i ]->questionStatement[ j ][ 0 ] == '/' ) {
				question[ i ]->questionStatement[ j ][ 0 ] = ' ';
				if ( question[ i ]->questionStatement[ j ][ 1 ] != '\0' ) {
					for ( int k = 0; k < QUESTION_ELEMENT - 1; k++ ) {
						question[ i ]->questionStatement[ j ][ k ] = question[ i ]->questionStatement[ j ][ k + 1 ];
					}
					question[ i ]->questionStatement[ j ][ QUESTION_ELEMENT - 1 ] = '\0';
				}
			}
		}
		//---------------------------------------------------------------------------------------------------------
	}
}

#endif // !__LOAD_DATA
