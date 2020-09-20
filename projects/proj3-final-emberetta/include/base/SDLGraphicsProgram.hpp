// Support Code written by Michael D. Shah
// Updated by Seth Cooper
// Last Updated: Spring 2020
// Please do not redistribute without asking permission.

#ifndef BASE_SDL_GRAPHICS_PROGRAM_HPP
#define BASE_SDL_GRAPHICS_PROGRAM_HPP

#include "base/Level.hpp"
#include <memory.h>
#include <SDL.h>

//! \brief This class sets up a full graphics program.
class SDLGraphicsProgram {
public:

  // Constructor
  SDLGraphicsProgram(std::shared_ptr<Level> level, int levelNumber = 1);

  // Destructor
  ~SDLGraphicsProgram();

  // Per frame update
  void update();

  // Renders shapes to the screen
  void render();

  // loop that runs forever
  void loop();

private:

  // the current level
  std::shared_ptr<Level> mLevel;
  
  // The window we'll be rendering to
  std::shared_ptr<SDL_Window> mWindow;

  // SDL Renderer
  std::shared_ptr<SDL_Renderer> mRenderer;

};

#endif
