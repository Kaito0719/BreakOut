// �w�b�_�t�@�C���̓ǂݍ��� ================================================
#include "TitleScene.h"

#include "SceneManager.h"



Scene* TitleScene::Create()
{
	TitleScene* scene = new TitleScene();

	return scene;
}


// �����o�֐��̒�` ========================================================
//------------------------------------------------------------------
//! @brief �f�t�H���g�R���X�g���N�^
//!
//! @param[in] �Ȃ�
//------------------------------------------------------------------
TitleScene::TitleScene()
	:Scene()
{


}


//------------------------------------------------------------------
//! @brief �f�X�g���N�^
//------------------------------------------------------------------
TitleScene::~TitleScene()
{


}


//----------------------------------------------------------------------
//! @brief �^�C�g���̏���������
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void TitleScene::Initialize(void)
{
	title.sprite.texture = LoadGraph("Resources\\Textures\\SimpleBlocks.png");
	title.sprite.x = 0;
	title.sprite.y = 0;
	title.sprite.width = 350;
	title.sprite.height = 168;
	title.pos.x = SCREEN_CENTER_X;
	title.pos.y = SCREEN_CENTER_Y - 40;
}



//----------------------------------------------------------------------
//! @brief �^�C�g���̍X�V����
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void TitleScene::Update(void)
{
	char key[256];
	GetHitKeyStateAll(key);
	if (key[KEY_INPUT_RETURN] != 0)
	{
		SceneManager* scene_manager = SceneManager::GetInstance();
		scene_manager->RequestScene(SCENE_PLAY);
	}
}


//----------------------------------------------------------------------
//! @brief �^�C�g���̕`�揈��
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void TitleScene::Render(void)
{
	DrawRectRotaGraph(title.pos.x, title.pos.y, title.sprite.x, title.sprite.y,
		title.sprite.width, title.sprite.height, 1.6, 0.0, title.sprite.texture, TRUE);
	DrawFormatString(250, 360, COLOR_WHITE,
		"Press [Enter] key");
}


//----------------------------------------------------------------------
//! @brief �^�C�g���̏I������
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void TitleScene::Finalize(void)
{


}
