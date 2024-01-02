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
    CreatePlayers();
    
    Board = std::make_shared<BoardController>();
    Board->Setup(Players);

    StartGame();
    
#ifdef _DEBUG
    ConsoleIO::LogMessage("Init Players\n");
    for (const Player& player : *Players)
    {
        ConsoleIO::LogMessage(player.Name + "\n");
    }
    ConsoleIO::LogMessage("End Players");
#endif
}

void GameManager::CreatePlayers()
{
    const int numPlayers = ConsoleIO::GetInput<int>("How many players will be playing? (min - 2; max - 10)\n");
    if (numPlayers < 2 || numPlayers > 10)
    {
        ConsoleIO::LogMessage("Invalid number of players\n");
        CreatePlayers();
        return;        
    }

    Players = std::make_shared<std::vector<Player>>();
    for (int i = 0; i < numPlayers; ++i)
    {
        auto playerName = ConsoleIO::GetInput<std::string>("Enter player " + std::to_string(i) + " name: \n");
        Players->emplace_back(Player{std::move(playerName)});   
    }
}

void GameManager::StartGame() const
{
    ShufflePlayers();
}

void GameManager::ShufflePlayers() const
{
    const unsigned seed = static_cast<unsigned>(std::chrono::system_clock::now().time_since_epoch().count());
    auto rng = std::default_random_engine {seed};
    std::ranges::shuffle(*Players, rng);
}

void GameManager::StartPlayerTurn()
{
    // Players
}
