#include "Debuger.h"
#include "WindowInformation.h"
#include "GameMainManager.h"
#include <time.h>

//----------------------------------------------------------------------------------
//--コンストラクタ・デストラクタ
Debuger::Debuger( Player* player = NULL, Enemy* enemy = NULL, Questionnaire* questionnaire = NULL ) {
	_player = player;
	_enemy  = enemy;
	_questionnaire = questionnaire;

	time_t timer;
	struct tm localTime;
	time( &timer );
	localtime_s( &localTime,  &timer );
	_fpsCounter.start = localTime.tm_sec;
	_fpsCounter.flame = 0;
	_fpsCounter.save  = 0;
}


Debuger::~Debuger( ) {
}
//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------


//----------------------------------------------------------------------------------
//--ゲッター
//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------


//----------------------------------------------------------------------------------
//--セッター
//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------


//--デバックモードを表示する関数
void Debuger::DebugMainScene( int distance, int pPosIndex, int ePosIndex ) {
	if ( _player == NULL || _enemy == NULL || _questionnaire == NULL ) return;	//GameMainScene以外では何もしない

	//プレイヤーとエネミーの位置・座標を描画----------------------------------------------------------------------------------------
	VECTOR pPos = _player->GetPosition( );
	VECTOR ePos = _enemy->GetPosition( );
	float Px = SCREEN_WIDTH * ( float )0.5 + pPos.x - 8;
	float Ex = SCREEN_WIDTH * ( float )0.5 + ePos.x - 8;
	DxLib::DrawBoxAA( Px, ( SCREEN_HEIGHT - ( pPos.z + 8 ) ), Px + 16, ( SCREEN_HEIGHT - ( pPos.z - 8 ) ), 0x0000ff, TRUE );
	DxLib::DrawBoxAA( Ex, ( SCREEN_HEIGHT - ( ePos.z + 8 ) ), Ex + 16, ( SCREEN_HEIGHT - ( ePos.z - 8 ) ), 0xffffff, TRUE );
	DxLib::DrawFormatString( 500,  0, 0xffffff, "プレイヤー座標 : ( %5.1f, %5.1f, %5.1f )", pPos.x, pPos.y, pPos.z );
	DxLib::DrawFormatString( 500, 20, 0xffffff, "エネミー　座標 : ( %5.1f, %5.1f, %5.1f )", ePos.x, ePos.y, ePos.z );
	//------------------------------------------------------------------------------------------------------------------------

	//残り距離を描画--------------------------------------------------------------
	DxLib::DrawFormatString( 0, 0, 0xffffff, "エネミーとの距離：%d", distance );
	//----------------------------------------------------------------------------

	//正解数 / 最大正解数を描画------------------------------------------------------------------------------------
	DxLib::DrawFormatString( 0, 20, 0xffffff, "正解数 / 最大正解数：%d / %d", _player->GetAnswerCount( ), CLEAR );
	//-------------------------------------------------------------------------------------------------------------

	//_questionnaire->_qFinishedを描画---------------------------------------------------------------------------------
	for ( int i = 0; i < Difficulty::DIFFICULTYMAX; i++ ) {

		for ( int j = 0; j < QUESTION_MAX; j++ ) {
			bool* qFinished = _questionnaire->GetQFinished( i );
			int color = 0xffffff;
			if ( qFinished[ j ] ) color = 0xffff00;
			
			DrawFormatString( 0 + ( i * 20 ), ( j * 20 ) + 40, color, "%d", qFinished[ j ] );
		}

	}
	//-------------------------------------------------------------------------------------------------

	//fpsを描画---------------------------
	DebugFPS( );
	//------------------------------------

	//_player->_prePos配列を描画-------------------------------------------------------------------------------------------------------------------------------------
	for ( int i = 0; i < PRE_POS_MAX_INDEX; i++ ) {
		int color = 0xffffff;
		if ( i == pPosIndex - 1 ) {
			color = 0x0000ff;
		}
		if ( i == ePosIndex ) {
			color = 0xff0000;
		}
		VECTOR* playerPrePos = _player->GetPrePos( );
		DxLib::DrawFormatString( 50, 40 + ( i * 20 ), color, "( %5.1f, %5.1f, %5.1f )", playerPrePos[ i ].x, playerPrePos[ i ].y, playerPrePos[ i ].z );
	}
	//----------------------------------------------------------------------------------------------------------------------------------------------------

}


//--FPSを表示する関数
void Debuger::DebugFPS( ) {
	//fpsを描画-------------------------------------------------------------
	time_t timer;
	struct tm localTime;
	time( &timer );
	localtime_s( &localTime,  &timer );
	if ( _fpsCounter.start != localTime.tm_sec ) {
		short int dif = localTime.tm_sec - _fpsCounter.start;
		if ( dif < 0 ) {
			dif += 60;
		}
		_fpsCounter.start = localTime.tm_sec;
		_fpsCounter.save = _fpsCounter.flame / ( float )dif;
		_fpsCounter.flame = 0;
	}
	DrawFormatString( 1000, 0, 0xffffff, "fps : %f", _fpsCounter.save );
	_fpsCounter.flame++;
	//-----------------------------------------------------------------------
}
