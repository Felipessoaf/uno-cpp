#include "GameManager.h"

#include "BoardController.h"

void GameManager::Setup()
{
    //TODO: Create players
    
    Board = std::make_shared<BoardController>();
    Board->Setup(Players);

    StartGame();
}

void GameManager::ShufflePlayers()
{
}

void GameManager::StartGame()
{
    ShufflePlayers();
}

void GameManager::StartPlayerTurn()
{
}
