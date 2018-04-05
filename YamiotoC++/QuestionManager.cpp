#include "QuestionManager.h"


//------------------------------------------------
//コンストラクタ・デストラクタ
QuestionManager::QuestionManager( ) {
}


QuestionManager::~QuestionManager( ) {
}
//------------------------------------------------
//------------------------------------------------


//--問題データを読み込む関数
void QuestionManager::LoadQuestion(  ) {
	fopen_s( &_questionData[ 0 ].fp, "QuestionEasy.txt", "r" );
	fopen_s( &_questionData[ 1 ].fp, "QuestionBasic.txt", "r" );
	fopen_s( &_questionData[ 2 ].fp, "QuestionHard.txt", "r" );
	
	for ( int i = 0; i < DIFFICULTYMAX; i++ ) {
		if ( _questionData[ i ].fp == NULL ) {
			DxLib_End( );
		} else {
			int x = 0;
			int y = 0;
			int z = 0;
			
			while( fscanf_s( _questionData[ i ].fp, "%s %s %s %s %s %s %s %s %d", 
					_questionData[ i ].num, 10,
					_questionData[ i ].questionStatement[ x     ], QUESTION_ELEMENT, 
					_questionData[ i ].questionStatement[ x + 1 ], QUESTION_ELEMENT, 
					_questionData[ i ].questionStatement[ x + 2 ], QUESTION_ELEMENT, 
					_questionData[ i ].choices[ y     ], CHOICES_ELEMENT, 
					_questionData[ i ].choices[ y + 1 ], CHOICES_ELEMENT, 
					_questionData[ i ].choices[ y + 2 ], CHOICES_ELEMENT, 
					_questionData[ i ].choices[ y + 3 ], CHOICES_ELEMENT, 
					&_questionData[ i ].answerNum[ z ] ) == 9 ) {
				x += 3;
				y += 4;
				z += 1;
			}
		}
		fclose( _questionData[ i ].fp );

		//　'/'を取り除く処理------------------------------------------------------------------------------------
		for ( int j = 0; j < 3 * QUESTION_MAX; j++ ) {
			if ( _questionData[ i ].questionStatement[ j ][ 0 ] == '/' ) {
				_questionData[ i ].questionStatement[ j ][ 0 ] = ' ';
				if ( _questionData[ i ].questionStatement[ j ][ 1 ] != '\0' ) {
					for ( int k = 0; k < QUESTION_ELEMENT - 1; k++ ) {
						_questionData[ i ].questionStatement[ j ][ k ] = _questionData[ i ].questionStatement[ j ][ k + 1 ];
					}
					_questionData[ i ].questionStatement[ j ][ QUESTION_ELEMENT - 1 ] = '\0';
				}
			}
		}
		//---------------------------------------------------------------------------------------------------------
	}
}