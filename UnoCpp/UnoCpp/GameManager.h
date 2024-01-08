#pragma once
#include <memory>
#include <vector>

#include "ICardEffectHandler.h"

class Player;
class BoardController;

class GameManager : public ICardEffectHandler
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
    void AddSkipPlayerAmount(int skipAmount) override;
    void AddBuyCardsAmount(int buyAmount) override;
    void ToggleDirection() override;
    bool SwitchHand(int playerIndex) override;
    void EndGame() const;

    std::shared_ptr<std::vector<Player>> Players;
    std::shared_ptr<BoardController> Board;

    int currentPlayerIndex {0};
    int playerAmount {-1};
    int amountOfPlayersToSkip {1};
    int amountOfCardsToBuy {0};
    int direction {1};
};
