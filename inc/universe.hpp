
#include "SDL2/SDL.h"

class Universe {
public:
  // todo: need to read more about the default but hey it wroks for now (last
  // famous words) https://howardhinnant.github.io/classdecl.html and read
  // about  rules of three/five/zero
  Universe(const int height, const int width);

private:
  // todo: SDL function requires address of raw pointer, see if there is way to
  // use smart pointers (seems like I need to create and pass some sort deleter)
  SDL_Window *window;
  SDL_Renderer *renderer;

  void Run();
};
