#pragma once

#include <DXLib.h>
#include "InputChecker.h"
#include "Sounder.h"
#include "Drawer.h"
#include "Questionnaire.h"

//==GameMainシーンを管理するクラス
class GameMainManager {
	InputChecker _inputChecker;
	Sounder _sounder;
	Drawer _drawer;
	Questionnaire* _questionnaire;
	bool _sceneChangeFlag;			//シーン遷移するかどうかのフラグ
public:
	//---------------------------------------
	//コンストラクタ・デストラクタ
	GameMainManager( );
	~GameMainManager( );
	//---------------------------------------
	//---------------------------------------


	//---------------------------------------
	//--ゲッター
	bool GetSceneChangeFlag( );
	//---------------------------------------
	//---------------------------------------


	//---------------------------------------
	//--セッター
	void SetSceneChangeFlag( bool x );
	//---------------------------------------
	//---------------------------------------


	void Main( );							//メイン関数
};

