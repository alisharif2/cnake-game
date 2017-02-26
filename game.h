#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include "cnake.h"

class Game {
  private:
    const int SCREEN_HEIGHT = 480;
    const int SCREEN_WIDTH  = 640;
    bool running = false;
    SDL_Window* mainWindow = NULL;
    SDL_Surface* screenSurface = NULL;
    SDL_Event e;
    Cnake* player;
  public:
    Game(const char*);
    ~Game();
    bool update();
    void draw();
};

#endif
