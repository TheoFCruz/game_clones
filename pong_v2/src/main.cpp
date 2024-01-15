#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL_events.h>

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
      if (event.type == SDL_KEYDOWN || event.type == SDL_KEYUP) game.handle_input(event);
    }

    game.update();
    game.draw();
  }
}
