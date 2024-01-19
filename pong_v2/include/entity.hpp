#pragma once

#include <SDL2/SDL.h>

class Entity
{
public:
  Entity(){}
  virtual ~Entity(){}

  virtual void handle_input(SDL_Event& input) = 0;
  virtual void update(double delta_time) = 0;
  virtual void draw(SDL_Renderer* p_renderer) = 0;
};
