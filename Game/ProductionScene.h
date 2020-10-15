//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   ProductionScene.h
//!
//! @brief  �V�[���̒��ۃN���X�̃w�b�_�t�@�C��
//!
//! @date   2018/11/15
//!
//! @author
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// ���d�C���N���[�h�̖h�~ ==================================================
#pragma once

// �w�b�_�t�@�C���̓ǂݍ��� ================================================
#include "Scene.h"
#include "GameMain.h"

// �N���X�̒�` ============================================================

// <�^�C�g���V�[��> ----------------------------------------------------------
class ProductionScene : public Scene
{
	// �ÓI�����o�֐��̐錾
public:
	static Scene* Create();

private:
	GameObject logo;
	int m_count;

	// �����o�֐��̐錾
public:
	// �R���X�g���N�^
	ProductionScene();

	//�h����Ŏ��R�ɐݒ肵�Ă悢
public:
	// �f�X�g���N�^
	virtual ~ProductionScene();

public:
	// �h����Ő錾����K�v������ = 0
	// ����
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Finalize() override;
};
