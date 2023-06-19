#include "game.h"
#include <raylib.h>
#include <assert.h>

Game::Game(int width, int height, int fps, std::string title)
    : board({200, 200}, {10, 20}, 15, 5)
{
    assert(!GetWindowHandle()); // triggers when window is already open
    SetTargetFPS(fps);
    InitWindow(width, height, title.c_str());

    // fill board with cells
    for (int iY = 0; iY < 20; iY++)
    {
        for (int iX = 0; iX < 10; iX++)
        {
            board.SetCell({iX, iY}, RED);
        }
    }
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
}

void Game::Draw()
{
    ClearBackground(BLACK);
    board.Draw();
}
