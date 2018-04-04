#include "Sounder.h"


//---------------------------------------
//コンストラクタ・デストラクタ
Sounder::Sounder( ) {
}


Sounder::~Sounder( ) {
}
//---------------------------------------
//---------------------------------------


//--音を鳴らす関数
void Sounder::PlaySoundMem( int soundHandle , int playType , int topPositionFlag ) {
	DxLib::PlaySoundMem( soundHandle, playType, topPositionFlag );
}


//--音を止める関数
void Sounder::StopSoundMem( int soundHandle ) {
	DxLib::StopSoundMem( soundHandle );
}


//--音が鳴っているか確認する関数
void Sounder::CheckSoundMem( int soundHandle ) {
	DxLib::CheckSoundMem( soundHandle );
}


//--音量を変える関数
void Sounder::ChangeVolumeSoundMem( int volumePal, int soundHandle ) {
	DxLib::ChangeVolumeSoundMem( volumePal, soundHandle );
}


//--音データの３Ｄサウンド用の再生位置を設定する関数
void Sounder::Set3DPositionSoundMem( VECTOR position, int soundHandle ) {
	DxLib::Set3DPositionSoundMem( position, soundHandle );
}


//--３Ｄサウンドのリスナーの位置とリスナーの前方位置を設定する
void Sounder::SetPlayerPosAndDir( VECTOR listenerPosition, VECTOR listenerDirection ) {
	DxLib::Set3DSoundListenerPosAndFrontPos_UpVecY( listenerPosition, VAdd( listenerPosition, listenerDirection ) );
}


//--音データの３Ｄサウンド用の音が聞こえる距離を設定する関数
void Sounder::Set3DRadiusSoundMem( float radius, int soundHandle ) {
	DxLib::Set3DRadiusSoundMem( radius, soundHandle );
}


//--３Ｄ空間の１メートルに相当する距離を設定する
void Sounder::Set3DSoundOneMetre( float  distance ) {
	DxLib::Set3DSoundOneMetre( distance );
}