#pragma once
#include <memory>
#include <vector>

class Player;
class BoardController;

class GameManager
{
public:
    void Setup();
    
private:
    void ShufflePlayers();
    void StartGame();
    void StartPlayerTurn();
    
    std::shared_ptr<std::vector<Player>> Players;
    std::shared_ptr<BoardController> Board;
};
