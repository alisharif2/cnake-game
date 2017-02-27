#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include "cnake.h"

class Game {
  private:
    const int SCREEN_HEIGHT = 480;
    const int SCREEN_WIDTH  = 640;
    const int size = 8;
    bool running = false;
    SDL_Window* mainWindow = NULL;
    SDL_Surface* screenSurface = NULL;
    SDL_Renderer* gRenderer = NULL;
    SDL_Event e;
    Cnake* player;
    void drawTile(int, int);
  public:
    Game(const char*);
    ~Game();
    bool update();
    void draw();
};

#endif
