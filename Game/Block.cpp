// ヘッダファイルの読み込み ================================================
#include "Block.h"




// <Blockクラス> ***************************************************************

// クラス定数の定義 ========================================================
const int Block::WIDTH = 80;
const int Block::HEIGHT = 20;

const ColorCode Block::COLORS[8] =
{
	COLOR_BLACK,    // ダミー
	COLOR_RED,
	COLOR_GREEN,
	COLOR_BLUE,
	COLOR_AQUA,
	COLOR_FUCHSIA,
	COLOR_YELLOW,
	COLOR_WHITE
};



//------------------------------------------------------------------
//! @brief コンストラクタ
//!
//! @param[in] column 配置する列番号
//! @param[in] row    配置する行番号
//! @param[in] type   ブロックタイプ
//------------------------------------------------------------------
Block::Block(int column, int row, int type)
{
	m_position.x = static_cast<float>(column * WIDTH + WIDTH / 2);
	m_position.y = static_cast<float>(row    * HEIGHT + HEIGHT / 2);

	m_color = Block::COLORS[type];
}



//------------------------------------------------------------------
//! @brief デストラクタ
//------------------------------------------------------------------
Block::~Block()
{

}



//----------------------------------------------------------------------
//! @brief 描画処理
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void Block::Render()
{
	int x1 = static_cast<int>(m_position.x - WIDTH  / 2);
	int y1 = static_cast<int>(m_position.y - HEIGHT / 2);
	int x2 = static_cast<int>(m_position.x + WIDTH  / 2);
	int y2 = static_cast<int>(m_position.y + HEIGHT / 2);

	DrawBox(x1, y1, x2, y2, m_color, TRUE);
	DrawBox(x1, y1, x2, y2, COLOR_BLACK, FALSE);
}
