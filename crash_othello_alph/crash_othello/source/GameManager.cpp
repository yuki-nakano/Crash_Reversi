#include "GameManager.h"

GameManager* GameManager::gameManager = nullptr;

GameManager::GameManager()
{
}

void GameManager::CreateInstance()
{
	if (gameManager == nullptr)
	{
		gameManager = new GameManager();
	}
}

void GameManager::DeleteInstance()
{
	delete gameManager;
	gameManager = nullptr;
}
