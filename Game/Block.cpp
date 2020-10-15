// �w�b�_�t�@�C���̓ǂݍ��� ================================================
#include "Block.h"




// <Block�N���X> ***************************************************************

// �N���X�萔�̒�` ========================================================
const int Block::WIDTH = 80;
const int Block::HEIGHT = 20;

const ColorCode Block::COLORS[8] =
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
//! @param[in] column �z�u�����ԍ�
//! @param[in] row    �z�u����s�ԍ�
//! @param[in] type   �u���b�N�^�C�v
//------------------------------------------------------------------
Block::Block(int column, int row, int type)
{
	m_position.x = static_cast<float>(column * WIDTH + WIDTH / 2);
	m_position.y = static_cast<float>(row    * HEIGHT + HEIGHT / 2);

	m_color = Block::COLORS[type];
}



//------------------------------------------------------------------
//! @brief �f�X�g���N�^
//------------------------------------------------------------------
Block::~Block()
{

}



//----------------------------------------------------------------------
//! @brief �`�揈��
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
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
