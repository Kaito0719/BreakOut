//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GameLibSystem.cpp
//!
//! @brief  システム関連の機能のソースファイル
//!
//! @date   2018/10/20
//!
//! @author S.Takaki
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// ヘッダファイルの読み込み ================================================
#include "GameLibSystem.h"

#include <DxLib.h>




// 関数の定義 ==============================================================

//----------------------------------------------------------------------
//! @brief ゲームの終了
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void ExitGame(void)
{
	PostQuitMessage(0);
}
