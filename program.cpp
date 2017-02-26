#include <SDL2/SDL.h>
#include "game.h"

const int ERR_OUT = 1;

int main(int argc, char** argv) {
  if(SDL_Init(SDL_INIT_VIDEO) < 0) {
    printf("Could not be initilized SDL: %s", SDL_GetError());
    return ERR_OUT;
  }

  Game* g = new Game("Cnake");

  bool running = true;
  while(running) {
    g->draw();
    running = g->update();
  }

  return 0;
}
