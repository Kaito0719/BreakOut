// ���d�C���N���[�h�̖h�~ =================================================
#pragma once


// �N���X�̒�` ============================================================
// <�p�h��> ----------------------------------------------------------
class Paddle
{
public:
	// �N���X�萔�̐錾
	static const int WIDTH;
	static const int HEIGHT;


	// �f�[�^�����o�̐錾
	Vector2D  m_velocity;
	private:
		
	public:
		Point2D   m_position;

	// �����o�֐��̐錾
	public:
		// �R���X�g���N�^
		Paddle();

		// �f�X�g���N�^
		~Paddle();

	public:
		// ����
		void Update(void);
		void Render(void);

};