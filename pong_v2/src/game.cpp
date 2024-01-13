#include <iostream>

#include "game.hpp"

Game::Game():
  m_window(NULL),
  m_renderer(NULL)
{}

Game::~Game()
{
  SDL_DestroyRenderer(m_renderer);
  SDL_DestroyWindow(m_window);

  TTF_Quit();
  SDL_Quit();
}

bool Game::init()
{
  // Initializes SDL and SDL_ttf
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
  {
    std::cout << "Unable to init SDL. Error: " << SDL_GetError() << std::endl;
    return false;
  }

  if (TTF_Init() != 0)
  {
    std::cout << "Unable to init SDL_ttf. Error: " << TTF_GetError() << std::endl;
    return false;
  }

  //Creates the window and the renderer
  m_window = SDL_CreateWindow("Pong",
                              SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED,
                              SCREEN_WIDTH,
                              SCREEN_HEIGHT,
                              SDL_WINDOW_RESIZABLE);
  if (m_window == NULL)
  {
    std::cout << "Unable to create window. Error: " << SDL_GetError() << std::endl;
    return false;
  }

  m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
  if (m_renderer == NULL)
  {
    std::cout << "Unable to create renderer. Error: " << SDL_GetError() << std::endl;
    return false;
  }

  return true;
}
