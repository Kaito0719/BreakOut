// �w�b�_�t�@�C���̓ǂݍ��� ================================================
#include "ProductionScene.h"
#include "GameMain.h"
#include "SceneManager.h"



Scene* ProductionScene::Create()
{
	ProductionScene* scene = new ProductionScene();

	return scene;
}


// �����o�֐��̒�` ========================================================
//------------------------------------------------------------------
//! @brief �f�t�H���g�R���X�g���N�^
//!
//! @param[in] �Ȃ�
//------------------------------------------------------------------
ProductionScene::ProductionScene()
	:Scene()
{


}


//------------------------------------------------------------------
//! @brief �f�X�g���N�^
//------------------------------------------------------------------
ProductionScene::~ProductionScene()
{


}


//----------------------------------------------------------------------
//! @brief �^�C�g���̏���������
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void ProductionScene::Initialize(void)
{
	m_count = 0;
	logo.sprite.texture = LoadGraph("Resources\\Textures\\logo_mano.png");
	logo.sprite.x = 0;
	logo.sprite.y = 0;
	logo.sprite.width = 640;
	logo.sprite.height = 480;
	logo.pos.x = SCREEN_CENTER_X;
	logo.pos.y = SCREEN_CENTER_Y;
}



//----------------------------------------------------------------------
//! @brief �^�C�g���̍X�V����
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void ProductionScene::Update(void)
{
	m_count++;
	char key[256];
	GetHitKeyStateAll(key);
	if (m_count > 120 || key[KEY_INPUT_SPACE] != 0)
	{
		SceneManager* scene_manager = SceneManager::GetInstance();
		scene_manager->RequestScene(SCENE_TITLE);

		m_count = 0;
	}
}


//----------------------------------------------------------------------
//! @brief �^�C�g���̕`�揈��
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void ProductionScene::Render(void)
{
	DrawRectRotaGraph(logo.pos.x, logo.pos.y, logo.sprite.x, logo.sprite.y,
		logo.sprite.width, logo.sprite.height, 1.0, 0.0, logo.sprite.texture, TRUE);
}


//----------------------------------------------------------------------
//! @brief �^�C�g���̏I������
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void ProductionScene::Finalize(void)
{


}
