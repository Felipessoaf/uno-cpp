#pragma once
#include <memory>
#include <vector>

class Player;
class BoardController;

class GameManager
{
public:
    std::shared_ptr<std::vector<Player>> Players;
    std::shared_ptr<BoardController> Board;

    void Setup();
    void ShufflePlayers();
    void StartGame();
    void StartPlayerTurn();
};
