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

  screenSurface = SDL_GetWindowSurface(mainWindow);

  std::srand(std::time(0));

  running = true;
  food = new Node(NORTH, 3, 3);
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
          player->turn(NORTH);
          break;
        case SDLK_DOWN:
          player->turn(SOUTH);
          break;
        case SDLK_LEFT:
          player->turn(WEST);
          break;
        case SDLK_RIGHT:
          player->turn(EAST);
          break;
      }
    }
  }

  player->updateNodes();

  // Simple collision detection with food
  if(food->xPos == player->head->xPos && food->yPos == player->head->yPos) {
    placeFood();
    player->grow();
  }

  if(player->isBite()) running = false;

  SDL_Delay(100);

  return running;
}

void Game::drawTile(int xPos, int yPos) {
  SDL_Rect fillRect = {xPos*size, yPos*size, size, size};
  SDL_RenderFillRect( gRenderer, &fillRect );
}

void Game::placeFood() {
  food->xPos = std::rand() % (SCREEN_WIDTH/size);
  food->yPos = std::rand() % (SCREEN_HEIGHT/size);
}

void Game::draw() {
  SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0x00);
  SDL_RenderClear(gRenderer);
  // TODO place drawing logic here

  SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

  // Food drawing logic
  drawTile(food->xPos, food->yPos);

  // Player drawing logic
  // TODO move inside cnake class
  Node* currentNode = player->head;
  while(true) {
    if(currentNode == NULL) break;
    drawTile(currentNode->xPos, currentNode->yPos);
    currentNode = currentNode->child;
  }

  SDL_RenderPresent(gRenderer);
}

