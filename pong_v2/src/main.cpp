#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "game.hpp"

int main(int argc, char** argv)
{
  Game game;
  
  game.init();
  
  SDL_Event event;
  bool running = true;
  while (running)
  {
    while (SDL_PollEvent(&event))
    {
      if (event.type == SDL_QUIT) running = false;
    }

    game.update();
    game.draw();
  }
}
