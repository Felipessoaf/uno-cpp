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
    void StartGame() const;
    void ShufflePlayers() const;
    void StartPlayerTurn();
    
    std::shared_ptr<std::vector<Player>> Players;
    std::shared_ptr<BoardController> Board;
};
