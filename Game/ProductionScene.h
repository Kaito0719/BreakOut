//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   ProductionScene.h
//!
//! @brief  シーンの抽象クラスのヘッダファイル
//!
//! @date   2018/11/15
//!
//! @author
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// 多重インクルードの防止 ==================================================
#pragma once

// ヘッダファイルの読み込み ================================================
#include "Scene.h"
#include "GameMain.h"

// クラスの定義 ============================================================

// <タイトルシーン> ----------------------------------------------------------
class ProductionScene : public Scene
{
	// 静的メンバ関数の宣言
public:
	static Scene* Create();

private:
	GameObject logo;
	int m_count;

	// メンバ関数の宣言
public:
	// コンストラクタ
	ProductionScene();

	//派生先で自由に設定してよい
public:
	// デストラクタ
	virtual ~ProductionScene();

public:
	// 派生先で宣言する必要がある = 0
	// 操作
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Finalize() override;
};
