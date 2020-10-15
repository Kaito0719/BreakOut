// ヘッダファイルの読み込み ================================================
#include "Ball.h"
#include "PlayScene.h"
#include "GameMain.h"

// <Ballクラス> ***************************************************************

// クラス定数の定義 ========================================================

const int Ball::WIDTH;
const int Ball::HEIGHT;

const ColorCode Ball::COLORS[8] =
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
//! @param[in] px   ボールの初期X座標
//! @param[in] py   ボールの初期Y座標
//------------------------------------------------------------------
Ball::Ball(int px, int py)
{
	m_position.x = px;
	m_position.y = py;
	m_velocity.x = 5;
	m_velocity.y = 5;
	m_color = Ball::COLORS[7];
}



//------------------------------------------------------------------
//! @brief デストラクタ
//------------------------------------------------------------------
Ball::~Ball()
{

}



//----------------------------------------------------------------------
//! @brief 更新処理
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void Ball::Update()
{
	m_position.x += m_velocity.x;
	m_position.y += m_velocity.y;

	if (m_position.x - WIDTH / 2 < SCREEN_LEFT)
	{
		m_velocity.x = -m_velocity.x;
		m_position.x = SCREEN_LEFT + WIDTH / 2;
	}
	else if (m_position.x + WIDTH / 2 > SCREEN_RIGHT)
		
	{
		m_velocity.x = -m_velocity.x;
		m_position.x = SCREEN_RIGHT - WIDTH / 2;
	}

	if (m_position.y - HEIGHT / 2 < SCREEN_TOP)
	{
		m_velocity.y = -m_velocity.y;
		m_position.y = SCREEN_TOP + HEIGHT / 2;
	}
	else if (m_position.y + HEIGHT / 2 > SCREEN_BOTTOM)
	{
		m_velocity.y = -m_velocity.y;
		m_position.y = SCREEN_BOTTOM - HEIGHT / 2;
	}
}



//----------------------------------------------------------------------
//! @brief 描画処理
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void Ball::Render()
{
	int x1 = static_cast<int>(m_position.x - WIDTH / 2);
	int y1 = static_cast<int>(m_position.y - HEIGHT / 2);
	int x2 = static_cast<int>(m_position.x + WIDTH / 2);
	int y2 = static_cast<int>(m_position.y + HEIGHT / 2);

	DrawBox(x1, y1, x2, y2, m_color, TRUE);

}

