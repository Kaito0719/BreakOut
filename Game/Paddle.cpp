// �w�b�_�t�@�C���̓ǂݍ��� ================================================
#include "Paddle.h"
#include "PlayScene.h"
#include "GameMain.h"
#include <GameLibrary\GameLib.h>

// <Ball�N���X> ***************************************************************

// �N���X�萔�̒�` ========================================================

const int Paddle::WIDTH = 70;
const int Paddle::HEIGHT = 10;

//------------------------------------------------------------------
//! @brief �R���X�g���N�^
//------------------------------------------------------------------
Paddle::Paddle()
{
	m_position.x = 320;
	m_position.y = 450;
	m_velocity.x = 0;
	m_velocity.y = 0;
}



//------------------------------------------------------------------
//! @brief �f�X�g���N�^
//------------------------------------------------------------------
Paddle::~Paddle()
{

}



//----------------------------------------------------------------------
//! @brief �X�V����
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void Paddle::Update()
{
	if((GetJoypadInputState(DX_INPUT_KEY_PAD1) & PAD_INPUT_LEFT) != 0)
	{
		m_velocity.x = -8;
	}
	else if((GetJoypadInputState(DX_INPUT_KEY_PAD1) & PAD_INPUT_RIGHT) != 0)
	{
		m_velocity.x = 8;
	}
	else
	{
		m_velocity.x = 0;
	}

	m_position.x += m_velocity.x;
	m_position.y += m_velocity.y;

	if (m_position.x - WIDTH / 2 < SCREEN_LEFT)
	{
		m_position.x = SCREEN_LEFT + WIDTH / 2;
	}
	else if (m_position.x + WIDTH / 2 > SCREEN_RIGHT)
	{
		m_position.x = SCREEN_RIGHT - WIDTH / 2;
	}
}



//----------------------------------------------------------------------
//! @brief �`�揈��
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void Paddle::Render()
{
	int x1 = static_cast<int>(m_position.x - WIDTH / 2);
	int y1 = static_cast<int>(m_position.y - HEIGHT / 2);
	int x2 = static_cast<int>(m_position.x + WIDTH / 2);
	int y2 = static_cast<int>(m_position.y + HEIGHT / 2);

	DrawBox(x1, y1, x2, y2, COLOR_WHITE, TRUE);

}
