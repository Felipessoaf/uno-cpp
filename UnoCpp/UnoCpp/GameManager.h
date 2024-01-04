#pragma once
#include <memory>
#include <vector>

class Player;
class BoardController;

class GameManager
{
public:
    void Setup();
    void CreatePlayers();

private:
    void StartGame();
    void ShufflePlayers();
    void StartCurrentPlayerTurn();
    void PrintRoundInfo() const;
    void SetNextPlayer();
    void AddSkipPlayerAmount(int skipAmount);
    void AddBuyCardsAmount(int buyAmount);
    void ToggleDirection();
    void EndGame() const;

    std::shared_ptr<std::vector<Player>> Players;
    std::shared_ptr<BoardController> Board;

    int currentPlayerIndex {0};
    int playerAmount {-1};
    int amountOfPlayersToSkip {1};
    int amountOfCardsToBuy {1};
    int direction {1};
};
