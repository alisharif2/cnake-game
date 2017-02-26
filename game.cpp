#include "game.h"

Game::Game(const char* title) {
  mainWindow = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
  if(mainWindow == NULL) {
    printf("Window could not be created: %s", SDL_GetError());
    SDL_Quit();
  }
  screenSurface = SDL_GetWindowSurface(mainWindow);
  running = true;
  player = new Cnake();
}

Game::~Game() {
  SDL_DestroyWindow(mainWindow);
  SDL_Quit();
}

bool Game::update() {
  while(SDL_PollEvent(&e) > 0) {
    if(e.type == SDL_QUIT) running = false;
  }

  player->updateNodes();

  return running;
}

void Game::draw() {
  SDL_UpdateWindowSurface(mainWindow);
}
