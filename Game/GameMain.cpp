//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GameMain.cpp
//!
//! @brief  ゲーム関連のソースファイル
//!
//! @date   日付
//!
//! @author 制作者名
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// ヘッダファイルの読み込み ================================================
#include "GameMain.h"
#include "SceneManager.h"

#include "ProductionScene.h"
#include "TitleScene.h"
#include "PlayScene.h"
#include "Scene.h"

// メンバ関数の定義 ========================================================
//------------------------------------------------------------------
//! @brief デフォルトコンストラクタ
//!
//! @param[in] なし
//------------------------------------------------------------------
Game::Game()
{
	
}



//------------------------------------------------------------------
//! @brief デストラクタ
//------------------------------------------------------------------
Game::~Game()
{
	
}



//----------------------------------------------------------------------
//! @brief ゲームの初期化処理
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void Game::Initialize(void)
{
	// シーンの設定
	SceneManager* scene_manager = SceneManager::GetInstance();


	scene_manager->AddScene(SCENE_TITLE, TitleScene::Create);
	scene_manager->AddScene(SCENE_PRODUCTION, ProductionScene::Create);
	scene_manager->AddScene(SCENE_PLAY, PlayScene::Create);
	scene_manager->SetStartScene(SCENE_PRODUCTION);
}



//----------------------------------------------------------------------
//! @brief ゲームの更新処理
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void Game::Update(void)
{
	SceneManager* scene_manager = SceneManager::GetInstance();
	scene_manager->UpdateActiveScene();
}



//----------------------------------------------------------------------
//! @brief ゲームの描画処理
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void Game::Render(void)
{
	SceneManager* scene_manager = SceneManager::GetInstance();
	scene_manager->RenderActiveScene();
}




//----------------------------------------------------------------------
//! @brief ゲームの終了処理
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void Game::Finalize(void)
{

}



