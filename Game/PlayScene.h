//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   PlayScene.h
//!
//! @brief  �V�[���̒��ۃN���X�̃w�b�_�t�@�C��
//!
//! @date   2018/11/15
//!
//! @author
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// ���d�C���N���[�h�̖h�~ ==================================================
#pragma once

#include "Block.h"
#include "Ball.h"
#include "Paddle.h"
// �w�b�_�t�@�C���̓ǂݍ��� ================================================
#include "Scene.h"

// �N���X�̐錾 ============================================================
class Block;
class Ball;
class Paddle;
// �N���X�̒�` ============================================================

// <�^�C�g���V�[��> ----------------------------------------------------------
class PlayScene : public Scene
{// �N���X�萔�̐錾
private:
	static const int STAGE_WIDTH;
	static const int STAGE_HEIGHT;

	// �ÓI�����o�֐��̐錾
public:
	static Scene* Create();

	// �f�[�^�����o�̐錾
private:
	int m_count;
	int     m_num_blocks;
	Block** m_blocks;
	Ball*   m_ball;
	Paddle* m_paddle;

	// �����o�֐��̐錾
public:
	// �R���X�g���N�^
	PlayScene();

	//�h����Ŏ��R�ɐݒ肵�Ă悢
public:
	// �f�X�g���N�^
	virtual ~PlayScene();

public:
	// �h����Ő錾����K�v������ = 0
	// ����
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Finalize() override;

	bool LoadStageData(const char* filename);
};