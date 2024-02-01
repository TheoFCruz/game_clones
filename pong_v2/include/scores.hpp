#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include <string>

class Game;

class Scores
{
public:
  /**
   * @brief Scores constructor
   */
  Scores(Game& game);

  /**
   * @brief Scores destructor
   */
  ~Scores();

  /**
   * @brief Initializes the textures
   */
  void init(std::string font_path);

  /**
   * @brief Draws the score on the screen
   */
  void draw(SDL_Renderer* renderer);

  /**
  * @brief Triggered when left player scores
  */
  void score_left(); 

  /**
  * @brief Triggered when left player scores
  */
  void score_right(); 
  
private:
  Game& m_game;

  unsigned int m_left_score;
  unsigned int m_right_score;

  SDL_Texture* m_right_text;
  SDL_Texture* m_left_text;

  SDL_Rect m_right_rect;
  SDL_Rect m_left_rect;

  TTF_Font* m_font;
  SDL_Color white{0xff, 0xff, 0xff};
};
