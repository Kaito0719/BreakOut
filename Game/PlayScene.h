//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   PlayScene.h
//!
//! @brief  シーンの抽象クラスのヘッダファイル
//!
//! @date   2018/11/15
//!
//! @author
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// 多重インクルードの防止 ==================================================
#pragma once

#include "Block.h"
#include "Ball.h"
#include "Paddle.h"
// ヘッダファイルの読み込み ================================================
#include "Scene.h"

// クラスの宣言 ============================================================
class Block;
class Ball;
class Paddle;
// クラスの定義 ============================================================

// <タイトルシーン> ----------------------------------------------------------
class PlayScene : public Scene
{// クラス定数の宣言
private:
	static const int STAGE_WIDTH;
	static const int STAGE_HEIGHT;

	// 静的メンバ関数の宣言
public:
	static Scene* Create();

	// データメンバの宣言
private:
	int m_count;
	int     m_num_blocks;
	Block** m_blocks;
	Ball*   m_ball;
	Paddle* m_paddle;

	// メンバ関数の宣言
public:
	// コンストラクタ
	PlayScene();

	//派生先で自由に設定してよい
public:
	// デストラクタ
	virtual ~PlayScene();

public:
	// 派生先で宣言する必要がある = 0
	// 操作
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Finalize() override;

	bool LoadStageData(const char* filename);
};