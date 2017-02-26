#include "game.h"

Game::Game(const char* title) {
  mainWindow = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
  if(mainWindow == NULL) {
    printf("Window could not be created: %s", SDL_GetError());
    SDL_Quit();
  }

  gRenderer = SDL_CreateRenderer(mainWindow, -1, SDL_RENDERER_ACCELERATED);
  if(gRenderer == NULL) {
    printf("Renderer could not be created: %s", SDL_GetError());
    SDL_DestroyWindow(mainWindow);
    SDL_Quit();
  }
  else {
    SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
  }

  screenSurface = SDL_GetWindowSurface(mainWindow);

  running = true;
  player = new Cnake();
}

Game::~Game() {
  SDL_DestroyWindow(mainWindow);
  SDL_FreeSurface(screenSurface);
  SDL_DestroyRenderer(gRenderer);
  SDL_Quit();
}

bool Game::update() {
  while(SDL_PollEvent(&e) > 0) {
    if(e.type == SDL_QUIT) running = false;
    else if(e.type == SDL_KEYDOWN) {
      switch(e.key.keysym.sym) {
        case SDLK_UP:
          player->head->d = NORTH;
          break;
        case SDLK_DOWN:
          player->head->d = SOUTH;
          break;
        case SDLK_LEFT:
          player->head->d = WEST;
          break;
        case SDLK_RIGHT:
          player->head->d = EAST;
          break;
      }
    }
  }

  player->updateNodes();

  return running;
}

void Game::draw() {
  SDL_RenderClear(gRenderer);
  // TODO place drawing logic here
  SDL_RenderPresent(gRenderer);
}
