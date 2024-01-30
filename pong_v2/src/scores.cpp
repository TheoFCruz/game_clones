#include "scores.hpp"

Scores::Scores(std::string font_path):
  m_right_score(0),
  m_left_score(0),
  m_right_text(NULL),
  m_left_text(NULL)
{
  // TODO: create the textures and open the font
}

// TODO: update the textures
void Scores::score_left()
{
  m_left_score++;
}

void Scores::score_right()
{
  m_right_score++;
}

void Scores::draw(SDL_Renderer& renderer)
{
  // TODO: implement this methods
}
