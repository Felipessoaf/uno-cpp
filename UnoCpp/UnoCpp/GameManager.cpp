#include "GameManager.h"

#include <chrono>
#include <memory>
#include <random>
#include <algorithm>
#include <random>

#include "BoardController.h"
#include "ConsoleIO.h"
#include "GameConstants.h"

void GameManager::Setup()
{
    Board = std::make_shared<BoardController>();
    CreatePlayers();
    Board->Setup(Players);

    StartGame();
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
    PrintRoundInfo();

    Player& currentPlayer = Players->at(currentPlayerIndex);
    if (!currentPlayer.PlayTurn())
    {
        currentPlayer.BuyCard(amountOfCardsToBuy);
        amountOfCardsToBuy = 1;
    }
    else
    {
        if (currentPlayer.GetAmountOfCards() == 1 && !currentPlayer.HasShoutedUno())
        {
            currentPlayer.BuyCard(GameConstants::UNO_SHOUT_BUY);
        }
    }

    if (currentPlayer.GetAmountOfCards() == 0)
    {
        EndGame();
    }
    else
    {    
        SetNextPlayer();
        StartCurrentPlayerTurn();
    }
}

void GameManager::PrintRoundInfo() const
{
    ConsoleIO::Clear();

    ConsoleIO::LogMessage("Order:\n");
    for (int i = 0; i < Players->size(); i++)
    {
        ConsoleIO::LogMessage(Players->at(i).Name + (i == currentPlayerIndex ? "<----\n" : "\n"));
#ifdef _DEBUG
        Players->at(i).Print();
#endif
    }
    
    ConsoleIO::LogMessage("\n");
    
#ifndef _DEBUG
    Players->at(currentPlayer).Print();
#endif
    ConsoleIO::LogMessage("Pile card:\n");
    Board->PrintDiscardTop();
}

void GameManager::SetNextPlayer()
{
    const int maxIndex = playerAmount - 1;
    currentPlayerIndex += amountOfPlayersToSkip * direction;
    currentPlayerIndex %= maxIndex + 1;
    
    if (currentPlayerIndex < 0)
    {
        currentPlayerIndex = maxIndex + 1 + currentPlayerIndex;
    }
    
    amountOfPlayersToSkip = 1;
}

void GameManager::AddSkipPlayerAmount(int skipAmount)
{
    amountOfPlayersToSkip += skipAmount;
}

void GameManager::AddBuyCardsAmount(int buyAmount)
{
    amountOfCardsToBuy += buyAmount;
}

void GameManager::ToggleDirection()
{
    direction *= -1;
}

void GameManager::EndGame() const
{
    ConsoleIO::GetInput<std::string>("Game Over");
}
