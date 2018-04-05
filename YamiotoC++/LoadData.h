#pragma once

#ifndef __LOAD_DATA
#define __LOAD_DATA



#include <DXLib.h>
#include <stdio.h>

//定数============================================================================================
const int QUESTION_MAX = 20;								//最大問題数(一つの問題集の中の)
const int QUESTION_ELEMENT = 256;							//問題文の一行の最大文字数
const int CHOICES_ELEMENT = 100;							//選択肢の一行の最大文字数

enum SoundData {	//音データ
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

enum ResourceData {	//画像データ
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

enum Difficulty {	//問題の難易度
	EASY,
	BASIC,
	HARD,
	DIFFICULTYMAX
};
//=================================================================================================


//int soundHandle[ SOUND_DATA_MAX ];		//音データののハンドル
//int resourceHandle[ RESOURCE_DATA_MAX ];	//画像データのハンドル

struct q_load {
	FILE* fp;																//ファイル型ポインタ
	char num[ 10 ];															//テキストファイルを見やすくするために書いた問題番号
	char questionStatement[ 3 * QUESTION_MAX ][ QUESTION_ELEMENT ];			//問題文
	char choices[ 4 * QUESTION_MAX ][ CHOICES_ELEMENT ];					//選択肢
	int answerNum[ QUESTION_MAX ];											//正解番号
};
//struct question question[ DIFFICULTYMAX ];										//問題に関する構造体


//関数原型宣言======================================================================
void LoadSound( );		//--音データを読み込む関数
void LoadResource( );	//画像データを読み込む関数
void LoadQuestion( );	//問題データを読み込む関数
//==================================================================================


//--音データを読み込む関数
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


//--画像データを読み込む関数
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


//--問題データを読み込む関数
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

		//　'/'を取り除く処理------------------------------------------------------------------------------------
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
