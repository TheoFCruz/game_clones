#include <SDL_render.h>
#include <iostream>

#include "consts.hpp"
#include "game.hpp"
#include "ball.hpp"
#include "paddle.hpp"

Game::Game():
  m_window(NULL),
  m_renderer(NULL)
{}

Game::~Game()
{
  for (Entity* entity : m_entities) delete entity; 

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

  //Creates the window
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

  // Creates the renderer
  m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
  if (m_renderer == NULL)
  {
    std::cout << "Unable to create renderer. Error: " << SDL_GetError() << std::endl;
    return false;
  }

  // Makes renderer adapt to resizing
  SDL_RenderSetLogicalSize(m_renderer, SCREEN_WIDTH, SCREEN_HEIGHT);

  // Creates the game's entities
  m_entities.push_back(new Ball());
  m_entities.push_back(new Paddle());

  return true;
}

void Game::handle_input(SDL_Event& input)
{
  for (Entity* entity : m_entities) entity->handle_input(input);
}

void Game::update(double delta_time)
{
  for (Entity* entity : m_entities) entity->update(delta_time);
}

void Game::draw()
{
  SDL_SetRenderDrawColor(m_renderer, 0x00, 0x00, 0x00, 0xFF);
  SDL_RenderClear(m_renderer);

  SDL_SetRenderDrawColor(m_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
  for (Entity* entity : m_entities) entity->draw(m_renderer);
  
  SDL_RenderPresent(m_renderer);
}
