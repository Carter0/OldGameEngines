// Support Code written by Michael D. Shah
// Updated by Seth Cooper
// Last Updated: Spring 2020
// Please do not redistribute without asking permission.
#pragma once
#ifndef SDL_GRAPHICS_PROGRAM_HPP
#define SDL_GRAPHICS_PROGRAM_HPP

#include <SDL.h>
#include <SDL_mixer.h>

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include <time.h>

#include <ctime>
#include <ratio>
#include <chrono>
#include <cmath>


#include "FrameRate.hpp"
#include "Breakout.hpp"
#include "ResourceManager.hpp"
#include "LocaleManager.hpp"
#include "StringMap.hpp"
#include "AudioManager.hpp"
#include "Util.hpp"


// This class sets up a full graphics program
class SDLGraphicsProgram {
public:

  // Constructor
  SDLGraphicsProgram(int w, int h);
  // Destructor
  ~SDLGraphicsProgram();
  // Per frame update
  void update();
  // Renders shapes to the screen
  void render();
  // loop that runs forever
  void loop();
  // Get Pointer to Window
  std::shared_ptr<SDL_Window> getSDLWindow();
  // Get Pointer to Renderer
  std::shared_ptr<SDL_Renderer> getSDLRenderer();

private:
  // Screen dimension constants
  int screenWidth;
  int screenHeight;
  // The window we'll be rendering to
  std::shared_ptr<SDL_Window> gWindow;
  // SDL Renderer
  std::shared_ptr<SDL_Renderer> gRenderer;
  FrameRate frameRate;
};

#endif
