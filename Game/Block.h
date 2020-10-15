// ���d�C���N���[�h�̖h�~ ==================================================
#pragma once


// �N���X�̒�` ============================================================
// <�u���b�N> ----------------------------------------------------------
class Block
{
public:
	// �N���X�萔�̐錾
	static const int WIDTH;
	static const int HEIGHT;
	static const ColorCode COLORS[8];


	// �f�[�^�����o�̐錾
	private:
		ColorCode m_color;
	public:
		Point2D   m_position;


	// �����o�֐��̐錾
	public:
		// �R���X�g���N�^
		Block(int x, int y, int type);

		// �f�X�g���N�^
		~Block();

	public:
		// ����
		void Render(void);
};