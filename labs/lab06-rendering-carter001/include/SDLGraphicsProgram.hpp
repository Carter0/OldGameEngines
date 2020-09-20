// Support Code written by Michael D. Shah
// Updated by Seth Cooper
// Last Updated: Spring 2020
// Please do not redistribute without asking permission.

#ifndef SDL_GRAPHICS_PROGRAM_HPP
#define SDL_GRAPHICS_PROGRAM_HPP

// ==================== Libraries ==================
// Depending on the operating system we use
// The paths to SDL are actually different.
// The #define statement should be passed in
// when compiling using the -D argument.
// This gives an example of how a programmer
// may support multiple platforms with different
// dependencies.
//
#include <SDL.h>

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include <time.h>

// OpenGL extensions
#include <glad/glad.h>

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
  void render();
  // loop that runs forever
  void loop();

private:
  // Screen dimension constants
  int screenHeight;
  int screenWidth;

  // The window we'll be rendering to
  SDL_Window* gWindow = nullptr;
  
  // GL context
  SDL_GLContext gGLContext = nullptr;
  GLsizei gElementCount = 0;
  GLuint gVertexBufferID = 0;
  GLuint gIndexBufferID = 0;
  GLuint gShaderProgramID = 0;
};

#endif
