#include "scores.hpp"

#include "game.hpp"
#include "consts.hpp"
#include <SDL_render.h>
#include <SDL_surface.h>

Scores::Scores(Game& game):
  m_game(game),
  m_right_score(0),
  m_left_score(0),
  m_right_text(NULL),
  m_left_text(NULL),
  m_font(NULL)
{
  m_left_rect.x = 0; 
  m_left_rect.y = 20; 
  m_left_rect.w = 0; 
  m_left_rect.h = 0; 

  m_right_rect.x = 0; 
  m_right_rect.y = 20; 
  m_right_rect.w = 0; 
  m_right_rect.h = 0; 
}

void Scores::init(std::string font_path)
{
  m_font = TTF_OpenFont(font_path.c_str(), FONT_SIZE);

  SDL_Surface* temp_surface = TTF_RenderText_Solid(m_font, "0", white);
  m_right_text = SDL_CreateTextureFromSurface(m_game.get_renderer(), temp_surface);
  m_left_text = SDL_CreateTextureFromSurface(m_game.get_renderer(), temp_surface);
  SDL_FreeSurface(temp_surface);
}

Scores::~Scores()
{
  SDL_DestroyTexture(m_right_text);
  SDL_DestroyTexture(m_left_text);

  TTF_CloseFont(m_font);
}

void Scores::score_left()
{
  m_left_score++;

  std::string score_str = std::to_string(m_left_score);

  SDL_Surface* temp_surface = TTF_RenderText_Solid(m_font, score_str.c_str(), white);
  m_left_text = SDL_CreateTextureFromSurface(m_game.get_renderer(), temp_surface);
  SDL_FreeSurface(temp_surface);
}

void Scores::score_right()
{
  m_right_score++;

  std::string score_str = std::to_string(m_right_score);

  SDL_Surface* temp_surface = TTF_RenderText_Solid(m_font, score_str.c_str(), white);
  m_right_text = SDL_CreateTextureFromSurface(m_game.get_renderer(), temp_surface);
  SDL_FreeSurface(temp_surface);
}

void Scores::draw(SDL_Renderer* renderer)
{
  SDL_QueryTexture(m_left_text, NULL, NULL, &m_left_rect.w, &m_left_rect.h);
  SDL_QueryTexture(m_right_text, NULL, NULL, &m_right_rect.w, &m_right_rect.h);

  m_left_rect.x = SCREEN_WIDTH/2 - m_left_rect.w - 20;
  m_right_rect.x = SCREEN_WIDTH/2 + 20;

  SDL_RenderCopy(renderer, m_left_text, NULL, &m_left_rect);
  SDL_RenderCopy(renderer, m_right_text, NULL, &m_right_rect);
}
