#include "game.h"
#include "settings.h"

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------

    Game game(settings::screenWidth,
              settings::screenHeight,
              settings::fps,
              "Tetris");

    while (!game.CloseGame())
    {
        game.Tick();
    }

    return 0;
}
