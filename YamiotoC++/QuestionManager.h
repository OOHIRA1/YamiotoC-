#pragma once

#include <DXLib.h>
#include <stdio.h>

const int QUESTION_MAX = 20;								//�ő��萔(��̖��W�̒���)
const int QUESTION_ELEMENT = 256;							//��蕶�̈�s�̍ő啶����
const int CHOICES_ELEMENT = 100;							//�I�����̈�s�̍ő啶����

enum Difficulty {	//���̓�Փx
	EASY,
	BASIC,
	HARD,
	DIFFICULTYMAX
};

struct q_load {
	FILE* fp;																//�t�@�C���^�|�C���^
	char num[ 10 ];															//�e�L�X�g�t�@�C�������₷�����邽�߂ɏ��������ԍ�
	char questionStatement[ 3 * QUESTION_MAX ][ QUESTION_ELEMENT ];			//��蕶
	char choices[ 4 * QUESTION_MAX ][ CHOICES_ELEMENT ];					//�I����
	int answerNum[ QUESTION_MAX ];											//����ԍ�
};

//==���f�[�^���Ǘ�����N���X
class QuestionManager {
	q_load _questionData[ DIFFICULTYMAX ];		//���Ɋւ���\����
public:
	//--------------------------------------
	//�R���X�g���N�^�E�f�X�g���N�^
	QuestionManager( );
	~QuestionManager( );
	//--------------------------------------
	//--------------------------------------

	void LoadQuestion( );	//���f�[�^��ǂݍ��ފ֐�
};

