// Support Code written by Michael D. Shah
// Updated by Seth Cooper
// Last Updated: Spring 2020
// Please do not redistribute without asking permission.

#include "base/SDLGraphicsProgram.hpp"
#include "managers/InputManager.hpp"
#include "managers/ResourceManager.hpp"
#include "managers/LocaleManager.hpp"
#include <iostream>
#include <sstream>
#include <time.h>
#include "Util.hpp"
#include <SDL_ttf.h>


// Initialization function
SDLGraphicsProgram::SDLGraphicsProgram(std::shared_ptr<Level> level, int levelNumber): mLevel(level) {
  // Initialize random number generation.
  srand(time(nullptr));


  // Initialization flag
  bool success = true;
  // String to hold any errors that occur.
  std::stringstream errorStream;
  // The window we'll be rendering to
  mWindow = nullptr;

  // Initialize SDL
  if(SDL_Init(SDL_INIT_EVERYTHING)< 0){
    errorStream << "SDL could not initialize! SDL Error: " << SDL_GetError() << "\n";
    success = false;
  } else {
    //Create window
    mWindow = create_shared(SDL_CreateWindow( "Lab", 100, 100, mLevel->w(), mLevel->h(), SDL_WINDOW_SHOWN ));

    // Check if Window did not create.
    if( mWindow == nullptr ){
      errorStream << "Window could not be created! SDL Error: " << SDL_GetError() << "\n";
      success = false;
    }

    //Create a Renderer to draw on
    mRenderer = create_shared(SDL_CreateRenderer(mWindow.get(), -1, SDL_RENDERER_ACCELERATED));
    if ( mRenderer == nullptr ){
      errorStream << "Renderer could not be created! SDL Error: " << SDL_GetError() << "\n";
      success = false;
    }
  }

   	
  if(TTF_Init()==-1) {
    printf("TTF_Init: %s\n", TTF_GetError());
    exit(2);
  }

  ResourceManager::getInstance().startUp(level->getResAffix(), mRenderer);
  LocaleManager::getInstance().startUp();
  InputManager::getInstance().startUp();
  AudioManager::getInstance().startUp();
  mLevel->loadLevel(levelNumber);

  // If initialization did not work, then print out a list of errors in the constructor.
  if(!success){
    errorStream << "Failed to initialize!\n";
    std::string errors=errorStream.str();
    std::cout << errors << "\n";
  }else{
    std::cout << "No SDL errors Detected in during init\n\n";
  }
}

// Proper shutdown and destroy initialized objects
SDLGraphicsProgram::~SDLGraphicsProgram() {
	InputManager::getInstance().shutDown();

	//Quit SDL subsystems
	SDL_Quit();
}

// Update OpenGL
void SDLGraphicsProgram::update() {
	mLevel->update();
}

// Render
// The render function gets called once per loop
void SDLGraphicsProgram::render() {

	SDL_SetRenderDrawColor(mRenderer.get(), 0x22, 0x22, 0x22, 0xFF);
	SDL_RenderClear(mRenderer.get());
	mLevel->render(mRenderer.get());
	SDL_RenderPresent(mRenderer.get());
}

//Loops forever!
void SDLGraphicsProgram::loop() {
	// Main loop flag
	// If this is quit = 'true' then the program terminates.
	bool quit = false;
	// Event handler that handles various events in SDL
	// that are related to input and output
	SDL_Event e;

	// While application is running
	while (!quit) {
		InputManager::getInstance().resetForFrame();

		//Handle events on queue
		while (SDL_PollEvent(&e) != 0) {
			if (e.type == SDL_QUIT) {
				quit = true;
			}
			InputManager::getInstance().handleEvent(e);
		}

		if (InputManager::getInstance().isKeyPressed(SDLK_q)) {
			quit = true;
		}

		// update
		update();

		// render
		render();

		// Reduce framerate
		SDL_Delay(16);
	}
}
