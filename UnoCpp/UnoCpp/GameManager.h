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
    void SetNextPlayer();
    
    std::shared_ptr<std::vector<Player>> Players;
    std::shared_ptr<BoardController> Board;

    int currentPlayer = 0;
    int playerAmount = -1;
};
