// ���d�C���N���[�h�̖h�~ ==================================================
#pragma once


// �N���X�̒�` ============================================================
// <�{�[��> ----------------------------------------------------------
class Ball
{
public:
	// �N���X�萔�̐錾
	static const int WIDTH = 10;
	static const int HEIGHT = 10;
	static const ColorCode COLORS[8];


	// �f�[�^�����o�̐錾
	Vector2D  m_velocity;
private:
	
	ColorCode m_color;
public:
	Point2D   m_position;

	// �����o�֐��̐錾
public:
	// �R���X�g���N�^
	Ball(int pointx, int pointy);

	// �f�X�g���N�^
	~Ball();

public:
	// ����
	void Update(void);
	void Render(void);

};