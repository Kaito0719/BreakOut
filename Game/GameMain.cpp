//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GameMain.cpp
//!
//! @brief  �Q�[���֘A�̃\�[�X�t�@�C��
//!
//! @date   ���t
//!
//! @author ����Җ�
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// �w�b�_�t�@�C���̓ǂݍ��� ================================================
#include "GameMain.h"
#include "SceneManager.h"

#include "ProductionScene.h"
#include "TitleScene.h"
#include "PlayScene.h"
#include "Scene.h"

// �����o�֐��̒�` ========================================================
//------------------------------------------------------------------
//! @brief �f�t�H���g�R���X�g���N�^
//!
//! @param[in] �Ȃ�
//------------------------------------------------------------------
Game::Game()
{
	
}



//------------------------------------------------------------------
//! @brief �f�X�g���N�^
//------------------------------------------------------------------
Game::~Game()
{
	
}



//----------------------------------------------------------------------
//! @brief �Q�[���̏���������
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void Game::Initialize(void)
{
	// �V�[���̐ݒ�
	SceneManager* scene_manager = SceneManager::GetInstance();


	scene_manager->AddScene(SCENE_TITLE, TitleScene::Create);
	scene_manager->AddScene(SCENE_PRODUCTION, ProductionScene::Create);
	scene_manager->AddScene(SCENE_PLAY, PlayScene::Create);
	scene_manager->SetStartScene(SCENE_PRODUCTION);
}



//----------------------------------------------------------------------
//! @brief �Q�[���̍X�V����
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void Game::Update(void)
{
	SceneManager* scene_manager = SceneManager::GetInstance();
	scene_manager->UpdateActiveScene();
}



//----------------------------------------------------------------------
//! @brief �Q�[���̕`�揈��
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void Game::Render(void)
{
	SceneManager* scene_manager = SceneManager::GetInstance();
	scene_manager->RenderActiveScene();
}




//----------------------------------------------------------------------
//! @brief �Q�[���̏I������
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void Game::Finalize(void)
{

}



