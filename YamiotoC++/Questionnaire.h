#pragma once

#include "Drawer.h"
#include "QuestionManager.h"
#include "WindowInformation.h"
#include "InputChecker.h"
#include "Sounder.h"

const int QUESTION_POS_X              = SCREEN_WIDTH_CENTER - 400;		//問題文の一行目のx座標
const int QUESTION_POS_Y              = SCREEN_HEIGHT_CENTER - 200;		//問題文の一行目のy座標
const int CHOICES_POS_X               = SCREEN_WIDTH_CENTER - 150;		//選択肢の一個目のx座標
const int CHOICES_POS_Y               = SCREEN_HEIGHT_CENTER - 100;		//選択肢の一個目のy座標
const int CURSOR_POS_X                = CHOICES_POS_X - 20;				//カーソルの初期x座標
const int CURSOR_POS_Y                = CHOICES_POS_Y + 11;				//カーソルの初期y座標
const int CHOICES_STATEMENT_SEPARATE  = 50;								//選択肢の間隔(カーソルの移動距離)
const int QUESTION_STATEMENT_SEPARATE = 22;								//問題文の間隔
const int CORSOR_RADIUS				  = 5;								//カーソルの半径

enum Way {		//道
	NOT_CHOOSE_WAY = -1,
	STRAIGHT_WAY,
	RIGHT_WAY,
	LEFT_WAY,
	WAY_MAX
};


//==問題出題を管理するクラス
class Questionnaire: public Drawer {
	QuestionManager _questionManager;
	InputChecker* _inputChecker;
	Sounder* _sounder;
	int _questionNum;						//出題する問題番号
	Difficulty _exerciseBooksNum;			//出題する問題集の番号
	
	bool _answer;							//正解したかどうかのフラグ
	bool _notAnswer;						//不正解かどうかのフラグ
	bool _input;							//入力を受け付けるかどうかのフラグ
	bool _chooseWayFlag;					//道を選んでいるかどうかフラグ
	bool _qFinished[ DIFFICULTYMAX ][ QUESTION_MAX ];	//問題集（難易度）の数と問題数 //問題が出たかどうかを判定する変数
	
	int _fontHandle;						//問題文フォントハンドル
	int _fontHandle2;						//選択肢フォントハンドル
	
	int _selectedSentence;					//カーソルの位置
	
	Way _way;								//選んだ道
	int _level[ WAY_MAX ];					//道選択時の難易度
	bool _levelRandamed;					//道選択時に各道にランダムで難易度を割り振ったかどうかのフラグ
public:
	//----------------------------------------------------
	//--コンストラクタ・デストラクタ
	Questionnaire( InputChecker* inputChecker, Sounder* sounder );
	~Questionnaire( );
	//----------------------------------------------------
	//----------------------------------------------------


	//----------------------------------------------------
	//--ゲッター
	bool GetAnswer( );
	bool GetNotAnswer( );
	bool GetChooseWayFlag( );
	//----------------------------------------------------
	//----------------------------------------------------


	//----------------------------------------------------
	//--セッター
	void SetInput( bool x );
	//----------------------------------------------------
	//----------------------------------------------------


	void Main( );												//メイン関数
	void CursorDisplay( );										//--カーソルを表示する関数(ジョイパット対応)
	void Question( );											//--難易度_exerciseBooksNumの問題番号_questionNumを表示する関数
	void RandamQuestion( );										//--問題をランダム化する関数(問題の重複防止)
	void ChooseWay();											//--道を選択する関数
	void DisplayLevel( );										//--問題の難易度を表示する関数
	void SoundSeikai( );										//--正解音を鳴らす関数
	void SoundHazure( );										//--ハズレ音を鳴らす関数
};

