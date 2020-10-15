// ヘッダファイルの読み込み ================================================
#include "TitleScene.h"

#include "SceneManager.h"



Scene* TitleScene::Create()
{
	TitleScene* scene = new TitleScene();

	return scene;
}


// メンバ関数の定義 ========================================================
//------------------------------------------------------------------
//! @brief デフォルトコンストラクタ
//!
//! @param[in] なし
//------------------------------------------------------------------
TitleScene::TitleScene()
	:Scene()
{


}


//------------------------------------------------------------------
//! @brief デストラクタ
//------------------------------------------------------------------
TitleScene::~TitleScene()
{


}


//----------------------------------------------------------------------
//! @brief タイトルの初期化処理
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void TitleScene::Initialize(void)
{
	title.sprite.texture = LoadGraph("Resources\\Textures\\SimpleBlocks.png");
	title.sprite.x = 0;
	title.sprite.y = 0;
	title.sprite.width = 350;
	title.sprite.height = 168;
	title.pos.x = SCREEN_CENTER_X;
	title.pos.y = SCREEN_CENTER_Y - 40;
}



//----------------------------------------------------------------------
//! @brief タイトルの更新処理
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void TitleScene::Update(void)
{
	char key[256];
	GetHitKeyStateAll(key);
	if (key[KEY_INPUT_RETURN] != 0)
	{
		SceneManager* scene_manager = SceneManager::GetInstance();
		scene_manager->RequestScene(SCENE_PLAY);
	}
}


//----------------------------------------------------------------------
//! @brief タイトルの描画処理
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void TitleScene::Render(void)
{
	DrawRectRotaGraph(title.pos.x, title.pos.y, title.sprite.x, title.sprite.y,
		title.sprite.width, title.sprite.height, 1.6, 0.0, title.sprite.texture, TRUE);
	DrawFormatString(250, 360, COLOR_WHITE,
		"Press [Enter] key");
}


//----------------------------------------------------------------------
//! @brief タイトルの終了処理
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void TitleScene::Finalize(void)
{


}
