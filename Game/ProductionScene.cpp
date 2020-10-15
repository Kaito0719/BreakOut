// ヘッダファイルの読み込み ================================================
#include "ProductionScene.h"
#include "GameMain.h"
#include "SceneManager.h"



Scene* ProductionScene::Create()
{
	ProductionScene* scene = new ProductionScene();

	return scene;
}


// メンバ関数の定義 ========================================================
//------------------------------------------------------------------
//! @brief デフォルトコンストラクタ
//!
//! @param[in] なし
//------------------------------------------------------------------
ProductionScene::ProductionScene()
	:Scene()
{


}


//------------------------------------------------------------------
//! @brief デストラクタ
//------------------------------------------------------------------
ProductionScene::~ProductionScene()
{


}


//----------------------------------------------------------------------
//! @brief タイトルの初期化処理
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void ProductionScene::Initialize(void)
{
	m_count = 0;
	logo.sprite.texture = LoadGraph("Resources\\Textures\\logo_mano.png");
	logo.sprite.x = 0;
	logo.sprite.y = 0;
	logo.sprite.width = 640;
	logo.sprite.height = 480;
	logo.pos.x = SCREEN_CENTER_X;
	logo.pos.y = SCREEN_CENTER_Y;
}



//----------------------------------------------------------------------
//! @brief タイトルの更新処理
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void ProductionScene::Update(void)
{
	m_count++;
	char key[256];
	GetHitKeyStateAll(key);
	if (m_count > 120 || key[KEY_INPUT_SPACE] != 0)
	{
		SceneManager* scene_manager = SceneManager::GetInstance();
		scene_manager->RequestScene(SCENE_TITLE);

		m_count = 0;
	}
}


//----------------------------------------------------------------------
//! @brief タイトルの描画処理
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void ProductionScene::Render(void)
{
	DrawRectRotaGraph(logo.pos.x, logo.pos.y, logo.sprite.x, logo.sprite.y,
		logo.sprite.width, logo.sprite.height, 1.0, 0.0, logo.sprite.texture, TRUE);
}


//----------------------------------------------------------------------
//! @brief タイトルの終了処理
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void ProductionScene::Finalize(void)
{


}
