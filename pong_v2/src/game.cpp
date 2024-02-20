#include <iostream>

#include "game.hpp"

Game::Game():
  m_window(NULL),
  m_renderer(NULL),
  m_ball(),
  m_left_paddle(Paddle_Type::LEFT),
  m_right_paddle(Paddle_Type::RIGHT),
  m_scores(*this)
{}

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

  // Inits scores
  m_scores.init("res/8-BIT WONDER.ttf");

  return true;
}

void Game::handle_input(SDL_Event& input)
{
  m_left_paddle.handle_input(input);
  m_right_paddle.handle_input(input);
}

void Game::update(double delta_time)
{
  m_ball.update(delta_time);
  m_left_paddle.update(delta_time);
  m_right_paddle.update(delta_time);
  
  check_collisions();
}

void Game::draw()
{
  SDL_SetRenderDrawColor(m_renderer, 0x00, 0x00, 0x00, 0xFF);
  SDL_RenderClear(m_renderer);

  SDL_SetRenderDrawColor(m_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
  m_ball.draw(m_renderer);
  m_left_paddle.draw(m_renderer);
  m_right_paddle.draw(m_renderer);
  m_scores.draw(m_renderer);
  
  SDL_RenderPresent(m_renderer);
}

void Game::close()
{
  SDL_DestroyRenderer(m_renderer);
  SDL_DestroyWindow(m_window);

  TTF_Quit();
  SDL_Quit();
}

void Game::check_collisions()
{
  SDL_FRect& ball_rect = m_ball.get_rect();
  SDL_FRect& l_paddle_rect = m_left_paddle.get_rect();
  SDL_FRect& r_paddle_rect = m_right_paddle.get_rect();

  // Ball paddle collision
  if (SDL_HasIntersectionF(&ball_rect, &l_paddle_rect)) 
  {
    m_ball.on_paddle_collision(m_left_paddle);
  }
  else if (SDL_HasIntersectionF(&ball_rect, &r_paddle_rect))
  {
    m_ball.on_paddle_collision(m_right_paddle);
  }

  // Ball wall collision
  if (ball_rect.y < 0) m_ball.vertical_bounce(Wall_Type::TOP);
  else if (ball_rect.y > SCREEN_HEIGHT - BALL_SIDE) m_ball.vertical_bounce(Wall_Type::BOTTOM);
  else if (ball_rect.x < 0) right_score();
  else if (ball_rect.x > SCREEN_WIDTH - BALL_SIDE) left_score();
}

void Game::left_score()
{
  m_ball.reset(Paddle_Type::LEFT);
  m_scores.score_left();
}

void Game::right_score()
{
  m_ball.reset(Paddle_Type::RIGHT);
  m_scores.score_right();
}
