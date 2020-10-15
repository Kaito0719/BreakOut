// �w�b�_�t�@�C���̓ǂݍ��� ================================================
#include "Ball.h"
#include "PlayScene.h"
#include "GameMain.h"

// <Ball�N���X> ***************************************************************

// �N���X�萔�̒�` ========================================================

const int Ball::WIDTH;
const int Ball::HEIGHT;

const ColorCode Ball::COLORS[8] =
{
	COLOR_BLACK,    // �_�~�[
	COLOR_RED,
	COLOR_GREEN,
	COLOR_BLUE,
	COLOR_AQUA,
	COLOR_FUCHSIA,
	COLOR_YELLOW,
	COLOR_WHITE
};

//------------------------------------------------------------------
//! @brief �R���X�g���N�^
//!
//! @param[in] px   �{�[���̏���X���W
//! @param[in] py   �{�[���̏���Y���W
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
//! @brief �f�X�g���N�^
//------------------------------------------------------------------
Ball::~Ball()
{

}



//----------------------------------------------------------------------
//! @brief �X�V����
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
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
//! @brief �`�揈��
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void Ball::Render()
{
	int x1 = static_cast<int>(m_position.x - WIDTH / 2);
	int y1 = static_cast<int>(m_position.y - HEIGHT / 2);
	int x2 = static_cast<int>(m_position.x + WIDTH / 2);
	int y2 = static_cast<int>(m_position.y + HEIGHT / 2);

	DrawBox(x1, y1, x2, y2, m_color, TRUE);

}

