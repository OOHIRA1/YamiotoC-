#pragma once

#include <DXLib.h>
#include <stdio.h>

const int QUESTION_MAX = 20;								//最大問題数(一つの問題集の中の)
const int QUESTION_ELEMENT = 256;							//問題文の一行の最大文字数
const int CHOICES_ELEMENT = 100;							//選択肢の一行の最大文字数

enum Difficulty {	//問題の難易度
	EASY,
	BASIC,
	HARD,
	DIFFICULTYMAX
};

struct q_load {
	FILE* fp;																//ファイル型ポインタ
	char num[ 10 ];															//テキストファイルを見やすくするために書いた問題番号
	char questionStatement[ 3 * QUESTION_MAX ][ QUESTION_ELEMENT ];			//問題文
	char choices[ 4 * QUESTION_MAX ][ CHOICES_ELEMENT ];					//選択肢
	int answerNum[ QUESTION_MAX ];											//正解番号
};

//==問題データを管理するクラス
class QuestionManager {
	q_load _questionData[ DIFFICULTYMAX ];		//問題に関する構造体
public:
	//--------------------------------------
	//コンストラクタ・デストラクタ
	QuestionManager( );
	~QuestionManager( );
	//--------------------------------------
	//--------------------------------------

	void LoadQuestion( );	//問題データを読み込む関数
};

