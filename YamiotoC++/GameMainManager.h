#pragma once

#include "Drawer.h"
#include "InputChecker.h"
#include "Sounder.h"
#include "Player.h"
#include "Enemy.h"
#include "Questionnaire.h"
#include "Debuger.h"
#include "WindowInformation.h"

const int FULL_SCREEN_FLAME = ESCAPE_COUNT_MAX - 50;					//脱出時の光画像が全画面に表示されるフレーム数
const int RATE_X = SCREEN_WIDTH_CENTER / FULL_SCREEN_FLAME;				//脱出時の光画像の拡大増加数x
const int RATE_Y = SCREEN_HEIGHT_CENTER / FULL_SCREEN_FLAME;			//脱出時の光画像の拡大増加数y


//==GameMainシーンを管理するクラス
class GameMainManager {
	Drawer* _drawer;
	InputChecker* _inputChecker;
	Sounder* _sounder;
	Player* _player;
	Enemy* _enemy;
	Questionnaire* _questionnaire;
	Debuger* _debuger;
	bool _sceneChangeFlag;					//シーン遷移するかどうかのフラグ
	bool _debug;							//デバックモードを表示するかどうかのフラグ
	int _flameCount;						//フレーム数
	int _distance;							//プレイヤーとエネミーの距離
	int _pPosIndex;							//playerが入れる_player->_prePosの添字番号
	int _ePosIndex;							//enemy が見てる_player->_prePosの添字番号
	int _bright;							//--aka.pngの明るさ
	bool _brighting;						//--aka.pngが明るくなっているかどうかのフラグ
	struct TwoPointsPicture _lightImage;		//脱出時の光画像
public:
	//---------------------------------------
	//コンストラクタ・デストラクタ
	GameMainManager( Drawer* drawer, InputChecker* inputChecker, Sounder* sounder );
	~GameMainManager( );
	//---------------------------------------
	//---------------------------------------


	//---------------------------------------
	//--ゲッター
	Player* GetPlayer( );
	bool GetSceneChangeFlag( );
	int GetDistance( );
	//---------------------------------------
	//---------------------------------------


	//---------------------------------------
	//--セッター
	void SetSceneChangeFlag( bool x );
	//---------------------------------------
	//---------------------------------------


	void Main( );							//--メイン関数
private:
	void UpdatePlayerPrePos( );				//--プレイヤーの座標を_player->_prePosに入れる関数
	void UpdateQFinished( );				//--出題した問題にフラグを立て全ての問題が出たらリセットする関数
	void DrawDgreeOfRisk( );				//--危険度を表示する関数(エネミーが近づくと画面が赤くなる)
	void StopSound( );						//--GameMainシーンで流れている音(BGM・エネミーの歌声・足音)を停止する関数
};

