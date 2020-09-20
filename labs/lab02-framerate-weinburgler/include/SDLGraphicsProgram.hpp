// Support Code written by Michael D. Shah
// Updated by Seth Cooper
// Last Updated: Spring 2020
// Please do not redistribute without asking permission.

#ifndef SDL_GRAPHICS_PROGRAM_HPP
#define SDL_GRAPHICS_PROGRAM_HPP

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include <time.h>



// This class sets up a full graphics program
class SDLGraphicsProgram{
public:

  // Constructor
  SDLGraphicsProgram(int w, int h);
  // Desctructor
  ~SDLGraphicsProgram();
  // Per frame update
  void update();
  // Renders shapes to the screen
  void render(const float avgFPS);
  // loop that runs forever
  void loop();
  // Get Pointer to Window
  SDL_Window* getSDLWindow();
  // Get Pointer to Renderer
  SDL_Renderer* getSDLRenderer();

private:
  // Screen dimension constants
  int screenWidth;
  int screenHeight;
  // The window we'll be rendering to
  SDL_Window* gWindow;
  // SDL Renderer
  SDL_Renderer* gRenderer;
  //In memory text stream
  std::stringstream timeText;
  //Set text color as black
  SDL_Color textColor = { 0, 0, 0, 255 };
};

#endif
