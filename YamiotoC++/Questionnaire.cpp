#include "Questionnaire.h"
#include <time.h>

//----------------------------------------------------
//--�R���X�g���N�^�E�f�X�g���N�^
Questionnaire::Questionnaire( InputChecker* inputChecker ) {
	_inputChecker = inputChecker;
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

	_fontHandle  = CreateFontToHandle( "�l�r ����", 20, 5 );
	_fontHandle2 = CreateFontToHandle( "�l�r ����", 20, 3 );

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
//--�Q�b�^�[
//----------------------------------------------------
//----------------------------------------------------


//----------------------------------------------------
//--�Z�b�^�[
//----------------------------------------------------
//----------------------------------------------------


//--���C���֐�
void Questionnaire::Main( ) {

	//���I������-----------------------------------------------------------------------------------
	if ( _chooseWayFlag ) {
		ChooseWay( );
		//���I����ɖ��������_���ɑI��
		//(�܂����I�����ChooseWay�֐����Ă΂Ȃ����Ƃ�1�t���[���݂̂̏����ɂ���)-----------------
		if ( !_chooseWayFlag ) {
			RandamQuestion( );
		}
		//---------------------------------------------------------------------------------------
	}
	//----------------------------------------------------------------------------------------------

	//����\�����鏈��----------------------------------------------
	if ( _input ) {
		Question( );
		CursorDisplay( );
	}
	//----------------------------------------------------------------

	//���̓�Փx�\��------------------------------------------------
	if ( !_chooseWayFlag && !_answer && !_notAnswer ) {
		DisplayLevel( );
	}
	//----------------------------------------------------------------
}


//--�J�[�\����\������֐�(�W���C�p�b�g�Ή�)
void Questionnaire::CursorDisplay( ) {
	DrawCircle( CURSOR_POS_X, CURSOR_POS_Y + ( CHOICES_STATEMENT_SEPARATE * _selectedSentence ), CORSOR_RADIUS, 0xffffff, true );
	if ( _inputChecker->GetJoypad( DOWN ) == 1 && _selectedSentence < 3 ) {	//��ԉ��ɗ����炻��ȏ�i�܂Ȃ� //�I�������S����̂�4 - 1 = 3
		_selectedSentence++;
	}
	if ( _inputChecker->GetJoypad( UP ) == 1 && _selectedSentence > 0 ) {	//��ԏ�ɗ����炻��ȏ�i�܂Ȃ�
		_selectedSentence--;
	}
}


//--��Փx_difficulty�̖��ԍ�_questionNum��\������֐�
void Questionnaire::Question( ) {
		q_load qData = _questionManager.GetQuestionData( _exerciseBooksNum );

		//���\������---------------------------------------------------------------------------------------------------------------------------------------------------------------------
		for ( int i = 0; i < 3; i++ ) {		//��蕶�\��
			DrawStringToHandle( QUESTION_POS_X, QUESTION_POS_Y + ( QUESTION_STATEMENT_SEPARATE * i ), qData.questionStatement[ i + ( _questionNum - 1 ) * 3 ], 0xffffff, _fontHandle );
		}
		for ( int i = 0; i < 4; i++ ) {		//�I�����\��
			DrawStringToHandle( CHOICES_POS_X, CHOICES_POS_Y + ( CHOICES_STATEMENT_SEPARATE * i ), qData.choices[ i + ( _questionNum - 1 ) * 4 ], 0xffffff, _fontHandle2 );
		}
		//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

		//�����E�s�������̐F�ύX����------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		if ( _inputChecker->GetKey( KEY_INPUT_RETURN ) == 1 || _inputChecker->GetJoypad( INPUT_2 ) == 1 ) {
			int color;	//�I�����̐F
			if ( _selectedSentence == qData.answerNum[ _questionNum - 1 ] ) {	//������
				color = GetColor( 0, 255, 0 );
				_answer = true;
				_input = false;
			} else {	//�s������
				color = GetColor( 255, 0, 0 );
				_notAnswer = true;
				_input = false;
			}
			DrawStringToHandle( CHOICES_POS_X, CHOICES_POS_Y + ( CHOICES_STATEMENT_SEPARATE * _selectedSentence ), qData.choices[ _selectedSentence + ( _questionNum - 1 ) * 4 ], color, _fontHandle2 );
		}
		//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
}


//--���������_��������֐�(���̏d���h�~)
void Questionnaire::RandamQuestion( ) {
	srand( ( unsigned int )time( NULL ) );
	do {
		_questionNum = rand( ) % QUESTION_MAX + 1;
	} while( _qFinished[ _exerciseBooksNum ][ _questionNum - 1 ] );
}


//--���I��������֐�
void Questionnaire::ChooseWay( ) {
	//���ꂼ��̓��ɓ�Փx��U�蕪���鏈��------------------------------------------------------------------
	if ( !_levelRandamed  ) {
		bool a[ DIFFICULTYMAX ] = { false, false, false };	//��Փx��U�蕪�����ǂ����`�F�b�N���Ă����ϐ�
		int count = 0;
		srand( ( unsigned int )time( NULL ) );

		while ( 1 ) {
			int difficulty = rand( ) % WAY_MAX;
			_level[ count ] = difficulty;
			if ( !a[ difficulty ] ) {	//��Փxdifficulty�͐U�蕪�������`�F�b�N
				a[ difficulty ] = true;
				count++;
			}
			for ( int i = 0; i < WAY_MAX; i++ ) {	//�S�Ă̓�Փx��U�蕪�������`�F�b�N
				if ( a[ i ] == false ) break;
				if ( i == WAY_MAX - 1 ) _levelRandamed = true;
			}
			if ( _levelRandamed ) break;
		}
	}
	//------------------------------------------------------------------------------------------------------

	//���I����ʂ̕\��---------------------------------------------------------------------------------------------------------
	DrawStringToHandle( QUESTION_POS_X, QUESTION_POS_Y, "����I�����Ă��������B\n", 0xffffff, _fontHandle );
	DrawStringToHandle( SCREEN_WIDTH_CENTER, SCREEN_HEIGHT_CENTER, "���F���@�@��F���@�@�E�F��", 0xffffff, _fontHandle2 );
	//-------------------------------------------------------------------------------------------------------------------------

	//�L�[�E�p�b�g���͎�t-----------------------------------------------------------------
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
	else if ( _inputChecker->GetJoypad( LEFT ) ) { 
		_exerciseBooksNum = ( Difficulty )_level[ 2 ];
		_way = RIGHT_WAY;
		_chooseWayFlag = false;
	}
	//--------------------------------------------------------------------------------------
}


//--���̓�Փx��\������֐�
void Questionnaire::DisplayLevel( ) {
	char* string;	//��Փx��\�����镶����ւ̃|�C���^
	switch( _exerciseBooksNum ) {
	case EASY:
		string = "��Փx�F��";
		break;
	case BASIC:
		string = "��Փx�F����";
		break;
	case HARD:
		string = "��Փx�F������";
		break;
	default:
		break;
	}
	DrawStringToHandle( QUESTION_POS_X, QUESTION_POS_Y - 25, string, 0xffffff, _fontHandle );
}