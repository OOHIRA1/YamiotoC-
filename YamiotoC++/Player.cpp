#include "Player.h"


//-------------------------------
//コンストラクタ・デストラクタ
Player::Player( Sounder* sounder ){
	_position = VGet( 0, 0, ( float )FIRST_DISTANCE );
	_direction = VGet( 0, 0, 1 );

	for ( int i = 0; i < PRE_POS_MAX_INDEX; i++ ) {
		_prePos[ i ] = VGet( 0, 0, 0 );
	}
	_prePos[ 0 ] = _position;		//最初の座標を_prePos[ 0 ]に代入

	_answerCount    = 0;
	_notAnswerCount = 0;
	_movedCount = 0;
	_freezedCount = 0;
	_sounder = sounder;
	_sounder->SetPlayerPosAndDir( _position, _direction );
}


Player::~Player( ){
}
//-------------------------------
//-------------------------------


//---------------------------------------------------
//--ゲッター
VECTOR Player::GetPosition( ) {
	return _position;
}


int Player::GetAnswerCount( ) {
	return _answerCount;
}


int Player::GetNotAnswerCount( ) {
	return _notAnswerCount;
}


int Player::GetMovedCount( ) {
	return _movedCount;
}


VECTOR* Player::GetPrePos( ) {
	return _prePos;
}
//---------------------------------------------------
//---------------------------------------------------


//---------------------------------------------------
//--セッター
void Player::SetPrePos( int index, VECTOR position ) {
	_prePos[ index ] = position;
}
//---------------------------------------------------

//---------------------------------------------------
//---------------------------------------------------


//--playerが前方(z方向)にpixelピクセル移動する関数
void Player::MoveForwardPixel( int pixel ) {
	_position.z += pixel;
	_sounder->SetPlayerPosAndDir( _position, _direction );
}


//--playerが左　にpixelピクセル移動する関数
void Player::MoveLeftPixel( int pixel ) {
	_position.x -= pixel;
	_sounder->SetPlayerPosAndDir( _position, _direction );
}


//--playerが右　にpixelピクセル移動する関数
void Player::MoveRightPixel( int pixel ) {
	_position.x += pixel;
	_sounder->SetPlayerPosAndDir( _position, _direction );
}


//--playerが前方にescapeCountフレームの間１ピクセル当たりflamePerPixelフレームで移動する関数
void Player::MoveForward( int escapeCount, int flamePerPixel ) {
	if ( _movedCount >= escapeCount ) {
		StopASIOTOAndLookForward( );
		return;	//既にescapeCountフレーム動いていたら戻る
	}

	_movedCount++;
	if ( _movedCount == 1 ) {
		_direction = VGet( 0, 0, 1 );
		SoundASIOTO( );
	}
	if ( _movedCount % flamePerPixel == 0 ) MoveForwardPixel( 1 );
}


//--playerが左にescapeCountフレームの間１ピクセル当たりflamePerPixelフレームで移動する関数
void Player::MoveLeft( int escapeCount, int flamePerPixel ) {
	if ( _movedCount >= escapeCount ) {
		StopASIOTOAndLookForward( );
		return;	//既にescapeCountフレーム動いていたら戻る
	}

	_movedCount++;
	if ( _movedCount == 1 ) {
		_direction = VGet( -1, 0, 0 );
		SoundASIOTO( );
	}
	if ( _movedCount % flamePerPixel == 0 ) MoveLeftPixel( 1 );
}


//--playerが右にescapeCountフレームの間１ピクセル当たりflamePerPixelフレームで移動する関数
void Player::MoveRight( int escapeCount, int flamePerPixel ) {
	if ( _movedCount >= escapeCount ) {
		StopASIOTOAndLookForward( );
		return;	//既にescapeCountフレーム動いていたら戻る
	}

	_movedCount++;
	if ( _movedCount == 1 ) {
		_direction = VGet( 1, 0, 0 );
		SoundASIOTO( );
	}
	if ( _movedCount % flamePerPixel == 0 ) MoveRightPixel( 1 );
}


//--足音を鳴らす関数(ループ再生)
void Player::SoundASIOTO( ) {
	int soundHandle = _sounder->GetSoundDataManager( ).GetSoundHandle( SoundData::PLAYER_ASIOTO );
		_sounder->ChangeVolumeSoundMem( 100, soundHandle );
		_sounder->PlaySoundMem( soundHandle, DX_PLAYTYPE_LOOP, TRUE );
}


//--足音を止める関数
void Player::StopASIOTO( ) {
	int soundHandle = _sounder->GetSoundDataManager( ).GetSoundHandle( SoundData::PLAYER_ASIOTO );
	if ( _sounder->CheckSoundMem( soundHandle ) ) {
		_sounder->StopSoundMem( soundHandle );
	}
}


//--足音を止め、正面を向く関数
void Player::StopASIOTOAndLookForward( ) {
	StopASIOTO( );
	_direction = VGet( 0, 0, 1 );
	_sounder->SetPlayerPosAndDir( _position, _direction );
}


//--ドアをガチャガチャする関数
void Player::KnockDoor( ) {
	int soundHandle = _sounder->GetSoundDataManager( ).GetSoundHandle( SoundData::DOOR_GATYA );
	_sounder->ChangeVolumeSoundMem( 100, soundHandle );
	_sounder->PlaySoundMem( soundHandle, DX_PLAYTYPE_NORMAL , TRUE);
}


//--ドアを開ける関数
void Player::OpenDoor( ) {
	int soundHandle = _sounder->GetSoundDataManager( ).GetSoundHandle( SoundData::DOOR );
	_sounder->ChangeVolumeSoundMem( 100, soundHandle );
	_sounder->PlaySoundMem( soundHandle, DX_PLAYTYPE_NORMAL, TRUE );
}


//--_answerCountを一つ増やす関数
void Player::PlusAnswerCount( ) {
	_answerCount++;
}


//--_notAnswerCountを一つ増やす関数
void Player::PlusNotAnswerCount( ) {
	_notAnswerCount++;
}


//--_answerCountを一つ増やす関数
void Player::ResetMovedCount( ) {
	_movedCount = 0;
}


//--_notAnswerCountを一つ増やす関数
void Player::ResetFreezedCount( ) {
	_freezedCount = 0;
}