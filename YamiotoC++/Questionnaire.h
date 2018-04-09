#pragma once

#include "Drawer.h"
#include "QuestionManager.h"
#include "WindowInformation.h"
#include "InputChecker.h"
#include "Sounder.h"

const int QUESTION_POS_X              = SCREEN_WIDTH_CENTER - 400;		//��蕶�̈�s�ڂ�x���W
const int QUESTION_POS_Y              = SCREEN_HEIGHT_CENTER - 200;		//��蕶�̈�s�ڂ�y���W
const int CHOICES_POS_X               = SCREEN_WIDTH_CENTER - 150;		//�I�����̈�ڂ�x���W
const int CHOICES_POS_Y               = SCREEN_HEIGHT_CENTER - 100;		//�I�����̈�ڂ�y���W
const int CURSOR_POS_X                = CHOICES_POS_X - 20;				//�J�[�\���̏���x���W
const int CURSOR_POS_Y                = CHOICES_POS_Y + 11;				//�J�[�\���̏���y���W
const int CHOICES_STATEMENT_SEPARATE  = 50;								//�I�����̊Ԋu(�J�[�\���̈ړ�����)
const int QUESTION_STATEMENT_SEPARATE = 22;								//��蕶�̊Ԋu
const int CORSOR_RADIUS				  = 5;								//�J�[�\���̔��a

enum Way {		//��
	NOT_CHOOSE_WAY = -1,
	STRAIGHT_WAY,
	RIGHT_WAY,
	LEFT_WAY,
	WAY_MAX
};


//==���o����Ǘ�����N���X
class Questionnaire: public Drawer {
	QuestionManager _questionManager;
	InputChecker* _inputChecker;
	Sounder* _sounder;
	int _questionNum;						//�o�肷����ԍ�
	Difficulty _exerciseBooksNum;			//�o�肷����W�̔ԍ�
	
	bool _answer;							//�����������ǂ����̃t���O
	bool _notAnswer;						//�s�������ǂ����̃t���O
	bool _input;							//���͂��󂯕t���邩�ǂ����̃t���O
	bool _chooseWayFlag;					//����I��ł��邩�ǂ����t���O
	bool _qFinished[ DIFFICULTYMAX ][ QUESTION_MAX ];	//���W�i��Փx�j�̐��Ɩ�萔 //��肪�o�����ǂ����𔻒肷��ϐ�
	
	int _fontHandle;						//��蕶�t�H���g�n���h��
	int _fontHandle2;						//�I�����t�H���g�n���h��
	
	int _selectedSentence;					//�J�[�\���̈ʒu
	
	Way _way;								//�I�񂾓�
	int _level[ WAY_MAX ];					//���I�����̓�Փx
	bool _levelRandamed;					//���I�����Ɋe���Ƀ����_���œ�Փx������U�������ǂ����̃t���O
public:
	//----------------------------------------------------
	//--�R���X�g���N�^�E�f�X�g���N�^
	Questionnaire( InputChecker* inputChecker, Sounder* sounder );
	~Questionnaire( );
	//----------------------------------------------------
	//----------------------------------------------------


	//----------------------------------------------------
	//--�Q�b�^�[
	bool GetAnswer( );
	bool GetNotAnswer( );
	bool GetChooseWayFlag( );
	//----------------------------------------------------
	//----------------------------------------------------


	//----------------------------------------------------
	//--�Z�b�^�[
	void SetInput( bool x );
	//----------------------------------------------------
	//----------------------------------------------------


	void Main( );												//���C���֐�
	void CursorDisplay( );										//--�J�[�\����\������֐�(�W���C�p�b�g�Ή�)
	void Question( );											//--��Փx_exerciseBooksNum�̖��ԍ�_questionNum��\������֐�
	void RandamQuestion( );										//--���������_��������֐�(���̏d���h�~)
	void ChooseWay();											//--����I������֐�
	void DisplayLevel( );										//--���̓�Փx��\������֐�
	void SoundSeikai( );										//--��������炷�֐�
	void SoundHazure( );										//--�n�Y������炷�֐�
};

