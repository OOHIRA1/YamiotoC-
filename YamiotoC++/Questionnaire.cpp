#include "Questionnaire.h"
#include <time.h>

//----------------------------------------------------
//--コンストラクタ・デストラクタ
Questionnaire::Questionnaire( InputChecker* inputChecker, Sounder* sounder ) {
	_inputChecker = inputChecker;
	_sounder = sounder;
	_questionNum = 1;
	_exerciseBooksNum = EASY;

	_answer = false;
	_notAnswer = false;
	_input = false;
	_chooseWayFlag = true;
	for ( int i = 0; i < DIFFICULTYMAX; i++ ) {
		for ( int j = 0; j < QUESTION_MAX; j++ ) {
			_qFinished[ i ][ j ] = false;
		}
	}

	_fontHandle  = CreateFontToHandle( "ＭＳ 明朝", 20, 5 );
	_fontHandle2 = CreateFontToHandle( "ＭＳ 明朝", 20, 3 );

	_selectedSentence = 0;
	
	_way = NOT_CHOOSE_WAY;
	for ( int i = 0; i < WAY_MAX; i++ ) {
		_level[ i ] = -1;
	}
	_levelRandamed = false;
}


Questionnaire::~Questionnaire( ) {
}
//----------------------------------------------------
//----------------------------------------------------


//----------------------------------------------------
//--ゲッター
int Questionnaire::GetQuestionNum( ) {
	return _questionNum;
}


Difficulty Questionnaire::GetExerciseBookNum( ) {
	return _exerciseBooksNum;
}


bool Questionnaire::GetAnswer( ) {
	return _answer;
}


bool Questionnaire::GetNotAnswer( ) {
	return _notAnswer;
}


bool Questionnaire::GetInput( ) {
	return _input;
}


bool Questionnaire::GetChooseWayFlag( ) {
	return _chooseWayFlag;
}


bool* Questionnaire::GetQFinished( int difficulty ) {
	return _qFinished[ difficulty ];
}


Way Questionnaire::GetWay( ) {
	return _way;
}
//----------------------------------------------------
//----------------------------------------------------


//----------------------------------------------------
//--セッター
void Questionnaire::SetAnswer( bool x ) {
	_answer = x;
}


void Questionnaire::SetNotAnswer( bool x ) {
	_notAnswer = x;
}


void Questionnaire::SetInput( bool x ) {
	_input = x;
}


void Questionnaire::SetChooseWayFlag( bool x ) {
	_chooseWayFlag = x;
}


void Questionnaire::SetQFinished( int exerciseBookNum, int questionNum, bool x ) {
	_qFinished[ exerciseBookNum ][ questionNum ] = x;
}


void Questionnaire::SetSelectedSentence( int x ) {
	_selectedSentence = x;
}


void Questionnaire::SetLevelRandomed( bool x ) {
	_levelRandamed = x;
}
//----------------------------------------------------
//----------------------------------------------------


//--カーソルを表示する関数(ジョイパット対応)
void Questionnaire::CursorDisplay( ) {
	DxLib::DrawCircle( CURSOR_POS_X, CURSOR_POS_Y + ( CHOICES_STATEMENT_SEPARATE * _selectedSentence ), CORSOR_RADIUS, 0xffffff, true );
	if ( _inputChecker->GetJoypad( DOWN ) == 1 && _selectedSentence < 3 ) {	//一番下に来たらそれ以上進まない //選択肢が４つあるので4 - 1 = 3
		_selectedSentence++;
	}
	if ( _inputChecker->GetJoypad( UP ) == 1 && _selectedSentence > 0 ) {	//一番上に来たらそれ以上進まない
		_selectedSentence--;
	}
}


//--難易度_difficultyの問題番号_questionNumを表示する関数
void Questionnaire::Question( ) {
		q_load qData = _questionManager.GetQuestionData( _exerciseBooksNum );

		//問題表示処理---------------------------------------------------------------------------------------------------------------------------------------------------------------------
		for ( int i = 0; i < 3; i++ ) {		//問題文表示
			DxLib::DrawStringToHandle( QUESTION_POS_X, QUESTION_POS_Y + ( QUESTION_STATEMENT_SEPARATE * i ), qData.questionStatement[ i + ( _questionNum - 1 ) * 3 ], 0xffffff, _fontHandle );
		}
		for ( int i = 0; i < 4; i++ ) {		//選択肢表示
			DxLib::DrawStringToHandle( CHOICES_POS_X, CHOICES_POS_Y + ( CHOICES_STATEMENT_SEPARATE * i ), qData.choices[ i + ( _questionNum - 1 ) * 4 ], 0xffffff, _fontHandle2 );
		}
		//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

		//正解・不正解時の色変更・音を鳴らす処理------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		if ( _inputChecker->GetKey( KEY_INPUT_RETURN ) == 1 || _inputChecker->GetJoypad( INPUT_2 ) == 1 ) {
			int color;	//選択肢の色
			if ( _selectedSentence == qData.answerNum[ _questionNum - 1 ] ) {	//正解時
				color = GetColor( 0, 255, 0 );
				_answer = true;
				_input = false;
			} else {	//不正解時
				color = GetColor( 255, 0, 0 );
				_notAnswer = true;
				_input = false;
			}
			DxLib::DrawStringToHandle( CHOICES_POS_X, CHOICES_POS_Y + ( CHOICES_STATEMENT_SEPARATE * _selectedSentence ), qData.choices[ _selectedSentence + ( _questionNum - 1 ) * 4 ], color, _fontHandle2 );
			if ( _answer ) SoundSeikai( );
			if ( _notAnswer ) SoundHazure( );
		}
		//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
}


//--問題をランダム化する関数(問題の重複防止)
void Questionnaire::RandamQuestion( ) {
	srand( ( unsigned int )time( NULL ) );
	do {
		_questionNum = rand( ) % QUESTION_MAX + 1;
	} while( _qFinished[ _exerciseBooksNum ][ _questionNum - 1 ] );
}


//--道選択をする関数
void Questionnaire::ChooseWay( ) {
	//それぞれの道に難易度を振り分ける処理------------------------------------------------------------------
	if ( !_levelRandamed  ) {
		bool a[ DIFFICULTYMAX ] = { false, false, false };	//難易度を振り分けたどうかチェックしておく変数
		int count = 0;
		srand( ( unsigned int )time( NULL ) );

		while ( 1 ) {
			int difficulty = rand( ) % DIFFICULTYMAX;
			_level[ count ] = difficulty;
			if ( !a[ difficulty ] ) {	//難易度difficultyは振り分けたかチェック
				a[ difficulty ] = true;
				count++;
			}
			for ( int i = 0; i < DIFFICULTYMAX; i++ ) {	//全ての難易度を振り分けたかチェック
				if ( a[ i ] == false ) break;
				if ( i == DIFFICULTYMAX - 1 ) _levelRandamed = true;
			}
			if ( _levelRandamed ) break;
		}
	}
	//------------------------------------------------------------------------------------------------------

	//道選択画面の表示---------------------------------------------------------------------------------------------------------
	DxLib::DrawStringToHandle( QUESTION_POS_X, QUESTION_POS_Y, "道を選択してください。\n", 0xffffff, _fontHandle );
	DxLib::DrawStringToHandle( SCREEN_WIDTH_CENTER, SCREEN_HEIGHT_CENTER, "左：←　　上：↑　　右：→", 0xffffff, _fontHandle2 );
	//-------------------------------------------------------------------------------------------------------------------------

	//キー・パット入力受付-----------------------------------------------------------------
	if ( _inputChecker->GetJoypad( UP ) ) {
		_exerciseBooksNum = ( Difficulty )_level[ 0 ];
		_way = STRAIGHT_WAY;
		_chooseWayFlag = false;
	}
	else if ( _inputChecker->GetJoypad( LEFT ) ) {
		_exerciseBooksNum = ( Difficulty )_level[ 1 ];
		_way = LEFT_WAY;
		_chooseWayFlag = false;
	}
	else if ( _inputChecker->GetJoypad( RIGHT ) ) { 
		_exerciseBooksNum = ( Difficulty )_level[ 2 ];
		_way = RIGHT_WAY;
		_chooseWayFlag = false;
	}
	//--------------------------------------------------------------------------------------
}


//--問題の難易度を表示する関数
void Questionnaire::DisplayLevel( ) {
	char* string;	//難易度を表示する文字列へのポインタ
	switch( _exerciseBooksNum ) {
	case EASY:
		string = "難易度：☆";
		break;
	case BASIC:
		string = "難易度：☆☆";
		break;
	case HARD:
		string = "難易度：☆☆☆";
		break;
	default:
		break;
	}
	DxLib::DrawStringToHandle( QUESTION_POS_X, QUESTION_POS_Y - 25, string, 0xffffff, _fontHandle );
}


//--正解音を鳴らす関数
void Questionnaire::SoundSeikai( ) {
	int soundHandle = _sounder->GetSoundDataManager( ).GetSoundHandle( SoundData::SEIKAI );
	_sounder->ChangeVolumeSoundMem( 100, soundHandle );
	_sounder->PlaySoundMem( soundHandle, DX_PLAYTYPE_NORMAL, TRUE );
}


//--ハズレ音を鳴らす関数
void Questionnaire::SoundHazure( ) {
	int soundHandle = _sounder->GetSoundDataManager( ).GetSoundHandle( SoundData::MATIGAI );
	_sounder->ChangeVolumeSoundMem( 100, soundHandle );
	_sounder->PlaySoundMem( soundHandle, DX_PLAYTYPE_NORMAL, TRUE );
}