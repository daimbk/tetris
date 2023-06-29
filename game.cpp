#include <assert.h>
#include "game.h"
#include <raylib.h>
#include "settings.h"

Game::Game(int width, int height, int fps, std::string title)
    : board(settings::boardPosition,
            settings::boardWidthHeight,
            settings::cellSize,
            settings::padding),
      tetromino(board)
{
    assert(!GetWindowHandle()); // triggers when window is already open
    SetTargetFPS(fps);
    InitWindow(width, height, title.c_str());
}

Game::~Game() noexcept
{
    assert(GetWindowHandle()); // triggers when window is already closed
    CloseWindow();
}

bool Game::CloseGame() const
{
    return WindowShouldClose();
}

void Game::Tick()
{
    BeginDrawing();
    Update();
    Draw();
    EndDrawing();
}

void Game::Update()
{
    if (IsKeyPressed(KEY_E))
    {
        tetromino.RotateClockwise();
    }

    if (IsKeyPressed(KEY_Q))
    {
        tetromino.RotateCounterClockwise();
    }
}

void Game::Draw()
{
    ClearBackground(BLACK);
    board.Draw();
    tetromino.Draw();
}
