#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include <string>

class Scores
{
public:
  /**
   * @brief Scores constructor
   */
  Scores(std::string font_path);

  /**
   * @brief Draws the score on the screen
   */
  void draw(SDL_Renderer& renderer);

  /**
  * @brief Triggered when left player scores
  */
  void score_left(); 

  /**
  * @brief Triggered when left player scores
  */
  void score_right(); 
  
private:
  unsigned int m_left_score;
  unsigned int m_right_score;

  SDL_Texture* m_right_text;
  SDL_Texture* m_left_text;

  TTF_Font* m_font;
};
