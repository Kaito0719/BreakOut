// �w�b�_�t�@�C���̓ǂݍ��� ================================================
#include "PlayScene.h"
#include "SceneManager.h"
#include <fstream>
#include <sstream>
#include <string>

// <PlayScene�N���X> ****************************************************************

// �N���X�萔�̒�` ========================================================

const int PlayScene::STAGE_WIDTH = 8;
const int PlayScene::STAGE_HEIGHT = 16;
Scene* PlayScene::Create()
{
	PlayScene* scene = new PlayScene();

	return scene;
}


// �����o�֐��̒�` ========================================================
//------------------------------------------------------------------
//! @brief �f�t�H���g�R���X�g���N�^
//!
//! @param[in] �Ȃ�
//------------------------------------------------------------------
PlayScene::PlayScene()
	:Scene()
{
	m_num_blocks = 0;
	m_blocks = nullptr;
	m_ball = new Ball(320, 400);
	m_paddle = new Paddle();

}


//------------------------------------------------------------------
//! @brief �f�X�g���N�^
//------------------------------------------------------------------
PlayScene::~PlayScene()
{
	for (int i = 0; i < m_num_blocks; i++)
	{
		delete m_blocks[i];
	}
	delete[] m_blocks;
	delete m_ball;
	delete m_paddle;

}


//----------------------------------------------------------------------
//! @brief �^�C�g���̏���������
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void PlayScene::Initialize(void)
{
	m_count = 0;
	LoadStageData("Resources\\Data\\Stage-01.csv");
}



//----------------------------------------------------------------------
//! @brief �^�C�g���̍X�V����
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void PlayScene::Update(void)
{
	char key[256];
	GetHitKeyStateAll(key);
	// �V�[���J��
	if (m_count == 56 || key[KEY_INPUT_B] != 0)
	{
		SceneManager* scene_manager = SceneManager::GetInstance();
		scene_manager->RequestScene(SCENE_TITLE);

		m_count = 0;
	}
	
	m_paddle->Update();
	m_ball->Update();

	float ballRight = m_ball->m_position.x + m_ball->Ball::WIDTH / 2;
	float ballLeft = m_ball->m_position.x - m_ball->Ball::WIDTH / 2;
	float ballTop = m_ball->m_position.y - m_ball->Ball::HEIGHT / 2;
	float ballBottom = m_ball->m_position.y + m_ball->Ball::HEIGHT / 2;

	float paddleRight = m_paddle->m_position.x + m_paddle->Paddle::WIDTH / 2;
	float paddleLeft = m_paddle->m_position.x - m_paddle->Paddle::WIDTH / 2;
	float paddleTop = m_paddle->m_position.y - m_paddle->Paddle::HEIGHT / 2;
	float paddleBottom = m_paddle->m_position.y + m_paddle->Paddle::HEIGHT / 2;

	bool collisionFlag = false;

	if (paddleRight >= ballLeft&&
		paddleLeft <= ballRight&&
		paddleTop <= ballBottom&&
		paddleBottom >= ballTop)
	{
		collisionFlag = true;
	}

	if (collisionFlag == true)
	{
		if (ballBottom >= paddleTop&&
			ballTop <= paddleBottom&&
			ballRight >= paddleRight&&
			m_ball->m_velocity.x < 0)
		{
			m_ball->m_velocity.x *= -1;
		}
		else
			if (ballBottom >= paddleTop&&
				ballTop <= paddleBottom&&
				ballLeft <= paddleLeft&&
				m_ball->m_velocity.x > 0)
			{
				m_ball->m_velocity.x *= -1;
			}

		if (ballLeft <= paddleRight&&
			ballRight >= paddleLeft&&
			ballTop <= paddleTop&&
			m_ball->m_velocity.y > 0)
		{
			m_ball->m_velocity.y *= -1;
		}
		else
			if (ballLeft <= paddleRight&&
				ballRight >= paddleLeft&&
				ballBottom >= paddleBottom&&
				m_ball->m_velocity.y < 0)
			{
				m_ball->m_velocity.y *= -1;
			}
	}

	bool deleteFlag = false;
	for (int i = 0; i < m_num_blocks; i++)
	{
		if (m_blocks[i] == nullptr)
		{
			continue;
		}
		deleteFlag = false;

		float blockRight = m_blocks[i]->m_position.x + m_blocks[i]->Block::WIDTH / 2;
		float blockLeft = m_blocks[i]->m_position.x - m_blocks[i]->Block::WIDTH / 2;
		float blockTop = m_blocks[i]->m_position.y - m_blocks[i]->Block::HEIGHT / 2;
		float blockBottom = m_blocks[i]->m_position.y + m_blocks[i]->Block::HEIGHT / 2;

		collisionFlag = false;

		if (blockRight >= ballLeft&&
			blockLeft <= ballRight&&
			blockTop <= ballBottom&&
			blockBottom >= ballTop)
		{
			collisionFlag = true;
		}

		if (collisionFlag == true)
		{
			if (ballBottom >= blockTop&&
				ballTop <= blockBottom&&
				ballRight >= blockRight&&
				m_ball->m_velocity.x < 0)
			{
				m_ball->m_velocity.x *= -1;
				deleteFlag = true;
			}
			else
				if (ballBottom >= blockTop&&
					ballTop <= blockBottom&&
					ballLeft <= blockLeft&&
					m_ball->m_velocity.x > 0)
				{
					m_ball->m_velocity.x *= -1;
					deleteFlag = true;
				}

			if (ballLeft <= blockRight&&
				ballRight >= blockLeft&&
				ballTop <= blockTop&&
				m_ball->m_velocity.y > 0)
			{
				m_ball->m_velocity.y *= -1;
				deleteFlag = true;
			}
			else
				if (ballLeft <= blockRight&&
					ballRight >= blockLeft&&
					ballBottom >= blockBottom&&
					m_ball->m_velocity.y < 0)
				{
					m_ball->m_velocity.y *= -1;
					deleteFlag = true;
				}
		}
		if (deleteFlag == true)
		{
			m_count++;
			delete m_blocks[i];
			m_blocks[i] = nullptr;
		}
	}
}


//----------------------------------------------------------------------
//! @brief �^�C�g���̕`�揈��
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void PlayScene::Render(void)
{
	for (int i = 0; i < m_num_blocks; i++)
	{
		if (m_blocks[i] != nullptr)
		{
			m_blocks[i]->Render();
		}
	}
	m_paddle->Render();
	m_ball->Render();

}


//----------------------------------------------------------------------
//! @brief �^�C�g���̏I������
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void PlayScene::Finalize(void)
{


}


//----------------------------------------------------------------------
//! @brief �X�e�[�W�f�[�^�̓ǂݍ���
//!
//! @param[in] filename �t�@�C����
//!
//! @retval true  �ǂݍ��݂ɐ��������ꍇ
//! @retval false �ǂݍ��݂Ɏ��s�����ꍇ
//----------------------------------------------------------------------
bool PlayScene::LoadStageData(const char* filename)
{
	// �t�@�C���̃I�[�v��
	std::ifstream ifs(filename);
	if (!ifs.is_open())
	{
		return false;
	}


	// 1�s�p�o�b�t�@
	std::string line;


	// �u���b�N���̓ǂݍ���
	getline(ifs, line);
	std::istringstream header(line);
	header.ignore(strlen("�u���b�N��") + 1);
	header >> m_num_blocks;
	m_blocks = new Block*[m_num_blocks];
	for (int i = 0; i < m_num_blocks; i++)
	{
		m_blocks[i] = nullptr;
	}


	// �X�e�[�W�f�[�^�̓ǂݍ���
	int n = 0;
	int y = 0;
	while (getline(ifs, line))
	{
		std::istringstream data(line);
		std::string field;
		int x = 0;
		while (getline(data, field, ','))
		{
			int type = atoi(field.c_str());
			if (type != 0)
			{
				m_blocks[n] = new Block(x, y, type);
				n++;
			}
			x++;
		}
		y++;
	}

	return true;
}
