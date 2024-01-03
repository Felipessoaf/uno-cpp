#include "GameManager.h"

#include <chrono>
#include <memory>
#include <random>
#include <algorithm>
#include <random>

#include "BoardController.h"
#include "ConsoleIO.h"

void GameManager::Setup()
{
    Board = std::make_shared<BoardController>();
    CreatePlayers();
    Board->Setup(Players);

    StartGame();
    
// #ifdef _DEBUG
//     ConsoleIO::LogMessage("Init Players\n");
//     for (const Player& player : *Players)
//     {
//         ConsoleIO::LogMessage(player.Name + "\n");
//     }
//     ConsoleIO::LogMessage("End Players");
// #endif
}

void GameManager::CreatePlayers()
{
    do
    {
        playerAmount = ConsoleIO::GetInput<int>("How many players will be playing? (min - 2; max - 10)\n");
    }
    while (playerAmount < 2 || playerAmount > 10);

    Players = std::make_shared<std::vector<Player>>();
    for (int i = 0; i < playerAmount; ++i)
    {
        auto playerName = ConsoleIO::GetInput<std::string>("Enter player " + std::to_string(i) + " name: \n");
        Players->emplace_back(Player{std::move(playerName), Board});
    }
}

void GameManager::StartGame()
{
    ShufflePlayers();
    Board->FlipCard();
    StartCurrentPlayerTurn();
}

void GameManager::ShufflePlayers()
{
    const unsigned seed = static_cast<unsigned>(std::chrono::system_clock::now().time_since_epoch().count());
    auto rng = std::default_random_engine {seed};
    std::ranges::shuffle(*Players, rng);
}

void GameManager::StartCurrentPlayerTurn()
{
    system("cls");
    Players->at(currentPlayer).Print();
    ConsoleIO::LogMessage("Pile card:\n");
    Board->PrintDiscardTop();
    Players->at(currentPlayer).PlayTurn();
    SetNextPlayer();
}

void GameManager::SetNextPlayer()
{
    currentPlayer++;
    if(currentPlayer >= playerAmount)
    {
        currentPlayer = 0;
    }
}
