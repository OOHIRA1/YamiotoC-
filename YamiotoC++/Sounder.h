#pragma once

#include <DXLib.h>

//==音を管理するクラス
class Sounder {
public:
	//-------------------------------
	//コンストラクタ・デストラクタ
	Sounder( );
	~Sounder( );
	//-------------------------------
	//-------------------------------

	void PlaySoundMem( int soundHandle , int playType , int topPositionFlag );		//--音を鳴らす関数
	void StopSoundMem( int soundHandle );											//--音を止める関数
	void CheckSoundMem( int soundHandle );											//--音が鳴っているか確認する関数
	void ChangeVolumeSoundMem( int volumePal, int soundHandle );					//--音量を変える関数
	void Set3DPositionSoundMem( VECTOR position, int soundHandle );					//--音データの３Ｄサウンド用の再生位置を設定する関数
	void SetPlayerPosAndDir( VECTOR listenerPosition, VECTOR listenerDirection );	//--３Ｄサウンドのリスナーの位置とリスナーの前方位置を設定する
	void Set3DRadiusSoundMem( float radius, int soundHandle );						//--音データの３Ｄサウンド用の音が聞こえる距離を設定する関数
	void Set3DSoundOneMetre( float distance );										//--３Ｄ空間の１メートルに相当する距離を設定する
};

