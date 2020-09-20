// Support Code written by Michael D. Shah
// Updated by Seth Cooper
// Last Updated: Spring 2020
// Please do not redistribute without asking permission.

#include "SDLGraphicsProgram.hpp"


// Initialization function
// Returns a true or false value based on successful completion of setup.
// Takes in dimensions of window.
SDLGraphicsProgram::SDLGraphicsProgram(int w, int h):
				  screenWidth(w),
				  screenHeight(h),
				  gWindow(nullptr),
				  gRenderer(nullptr),
				  frameRate("FreeSans.ttf")
{
	// Initialize random number generation.
	srand(time(nullptr));

	// Initialization flag
	bool success = true;
	// String to hold any errors that occur.
	std::stringstream errorStream;

	// The window we'll be rendering to
	gWindow = nullptr;
	// Render flag

	// Initialize SDL
	if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO)< 0){
		errorStream << "SDL could not initialize! SDL Error: " << SDL_GetError() << "\n";
		success = false;
	}
	else{

		//Create window
		gWindow = create_shared(SDL_CreateWindow( "Breakout",
				SDL_WINDOWPOS_UNDEFINED,
				SDL_WINDOWPOS_UNDEFINED,
				screenWidth,
				screenHeight,
				SDL_WINDOW_SHOWN ));

		// Check if Window did not create.
		if( gWindow == nullptr ){
			errorStream << "Window could not be created! SDL Error: " << SDL_GetError() << "\n";
			success = false;
		}


		//Create a Renderer to draw on
		gRenderer = create_shared(SDL_CreateRenderer(gWindow.get(), -1, SDL_RENDERER_ACCELERATED));
		// Check if Renderer did not create.
		if( gRenderer == nullptr ){
			errorStream << "Renderer could not be created! SDL Error: " << SDL_GetError() << "\n";
			success = false;
		}

		// Start the audio manager
		if (AudioManager::getInstance().startUp() != 0) {
			errorStream << "AudioManager could not be started!\n" ;
			success = false;
		}
		if ((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) != IMG_INIT_PNG){
			errorStream << "PNG could not be started!\n" ;
			success = false;
		}
	}

	// If initialization did not work, then print out a list of errors in the constructor.
	if(!success){
		errorStream << "Failed to initialize!\n";
		std::string errors=errorStream.str();
		std::cout << errors << "\n";
	}else{
		std::cout << "No SDL, or OpenGL, errors Detected\n\n";
	}

	//initialize the resource manager.
	ResourceManager::getInstance().startUp(gRenderer);

	LocaleManager::getInstance().startUp();

	Breakout::getInstance().setFont("FreeSans.ttf");
	//Initialize the Breakout GameObject.
}

// Proper shutdown and destroy initialized objects
SDLGraphicsProgram::~SDLGraphicsProgram(){
	// Window and Renderer will delete themselves
	// Free memory in the resourcemanager
	ResourceManager::getInstance().shutDown();

	LocaleManager::getInstance().shutDown();

	//Quit SDL subsystems
	SDL_Quit();
}



// Update OpenGL
void SDLGraphicsProgram::update()
{
	SDL_SetRenderDrawColor(gRenderer.get(), 0x22,0x22,0x22,0xFF);
	SDL_RenderClear(gRenderer.get());
	frameRate.update(screenWidth, screenHeight, gRenderer);
	Breakout::getInstance().update();
}


// Render
// The render function gets called once per loop
void SDLGraphicsProgram::render() {
	frameRate.render(gRenderer);
	Breakout::getInstance().render(gRenderer);
	SDL_RenderPresent(gRenderer.get());
}

//Loops forever!
void SDLGraphicsProgram::loop(){
	// Main loop flag
	// If this is quit = 'true' then the program terminates.
	bool quit = false;

	// Event handler that handles various events in SDL
	// that are related to input and output
	SDL_Event e;
	// Enable text input
	SDL_StartTextInput();
	// While application is running
	Breakout::getInstance().start();
	while(!quit){
		frameRate.addTime();
		//Handle events on queue
		while(SDL_PollEvent( &e ) != 0){
			// User posts an event to quit
			// An example is hitting the "x" in the corner of the window.
			if (e.type == SDL_QUIT)
				quit = true;

			// Detect keydown events
			if (e.type == SDL_KEYDOWN) {
				// Detect which key was pressed and only do something 
				// if either the left or right arrow keys were pressed.
				switch( e.key.keysym.sym ){
					case SDLK_LEFT:
						Breakout::getInstance().keyInput("left", true);
						break;
					case SDLK_RIGHT:
						Breakout::getInstance().keyInput("right", true);
						break;
					case SDLK_f:
						break;
					case SDLK_q:
						quit = true;
						break;
					case SDLK_k:
						LocaleManager::getInstance().startUp(SPANISH_LOCALE);
						break;
					case SDLK_l:
						LocaleManager::getInstance().startUp(ENGLISH_LOCALE);
						break;					
					default:
						break;
				}
			}

			if (e.type == SDL_KEYUP) {
				switch( e.key.keysym.sym ){
					case SDLK_LEFT:
						Breakout::getInstance().keyInput("left", false);
						break;
					case SDLK_RIGHT:
						Breakout::getInstance().keyInput("right", false);
						break;
					default:
						break;
				}
			}
		
		}
		// Update our scene
		update();
		render();
		int delay = 1000.0/60 - frameRate.sinceLast();
		if (Breakout::getInstance().getEndCondition() != 0) {
			delay = 5000;
			if (Breakout::getInstance().getEndCondition() == 1) {
				if (Breakout::getInstance().getLevel() != MAXLEVEL) {
					Breakout::getInstance().setLevel(Breakout::getInstance().getLevel() + 1);
					Breakout::getInstance().createBasicLevel(Breakout::getInstance().getLevel());
					update();
					render();
				} else {
					quit = true;
				}
			} else if (Breakout::getInstance().getEndCondition() == 2) {
				quit = true;
			}
		}
		SDL_Delay(delay > 0 ? delay : 0);
	}
	//Disable text input
	SDL_StopTextInput();
}

// Get Pointer to Window
std::shared_ptr<SDL_Window> SDLGraphicsProgram::getSDLWindow(){
	return gWindow;
}

// Get Pointer to Renderer
std::shared_ptr<SDL_Renderer> SDLGraphicsProgram::getSDLRenderer(){
	return gRenderer;
}


