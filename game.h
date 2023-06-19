#pragma once
#include <string>
#include "board.h"

class Game
{
private:
    void Draw();
    void Update();

    Board board;

public:
    // constructor
    Game(int width, int height, int fps, std::string title);
    Game(const Game &other) = delete;            // delete copy constructor
    Game &operator=(const Game &other) = delete; // delete copy assignment operator

    // destructor
    ~Game() noexcept;

    bool CloseGame() const;

    void Tick();
};
