// Support Code written by Michael D. Shah
// Updated by Seth Cooper
// Last Updated: Spring 2020
// Please do not redistribute without asking permission.

#include "SDLGraphicsProgram.hpp"

// I recommend a map for filling in the resource manager
#include <map>
#include <string>
#include <iterator>

// Try toggling this number!
#define CHARACTERS 50


// Just a cheap little class to demonstrate loading characters.
class GameCharacter{
public:

  GameCharacter(){
  }


  ~GameCharacter(){
  }

  // The frame represents which one, linearly, you want.
  void init(int x, int y, int frame, SDL_Renderer* ren){
    xPos = x;
    yPos = y;
    currentFrame = frame % LastFrame;
    texture = ResourceManager::getInstance().loadTexture("./res/sprite.bmp", ren);
  }


  void update(){
    // The part of the image that we want to render
    currentFrame ++;

    if(currentFrame>=LastFrame){
      currentFrame=0;
    }

   
    int column = currentFrame % 7;
    int row = currentFrame / 7;


       

    // Here I am selecting which frame I want to draw
    // from our sprite sheet. Think of this as just
    // using a mouse to draw a rectangle around the
    // sprite that we want to draw.
    Src.x = column *75;
    Src.y = row * 87;
    Src.w = 75;
    Src.h = 87;

    // Where we want the rectangle to be rendered at.
    // This is an actual 'quad' that will draw our
    // source image on top of.	
    Dest.x = xPos;
    Dest.y = yPos;
    Dest.w = 128;
    Dest.h = 128;
  }

  void render(SDL_Renderer* ren){
    SDL_RenderCopy(ren, texture, &Src, &Dest);
  }


private:
  int xPos, yPos;
  unsigned int currentFrame{0};
  unsigned int LastFrame{27};
  SDL_Texture *texture;

  SDL_Rect Src;
  SDL_Rect Dest;
};


// Global array to create our characters
GameCharacter characters[CHARACTERS];


// Initialization function
// Returns a true or false value based on successful completion of setup.
// Takes in dimensions of window.
SDLGraphicsProgram::SDLGraphicsProgram(int w, int h):screenHeight(h),screenWidth(w){
  // Initialize random number generation.
  srand(time(NULL));



  // Initialization flag
  bool success = true;
  // String to hold any errors that occur.
  std::stringstream errorStream;
  // The window we'll be rendering to
  gWindow = NULL;
  // Render flag

  // Initialize SDL
  if(SDL_Init(SDL_INIT_EVERYTHING)< 0){
    errorStream << "SDL could not initialize! SDL Error: " << SDL_GetError() << "\n";
    success = false;
  }
  else{
    //Create window
    gWindow = SDL_CreateWindow( "Lab", 100, 100, screenWidth, screenHeight, SDL_WINDOW_SHOWN );

    // Check if Window did not create.
    if( gWindow == NULL ){
      errorStream << "Window could not be created! SDL Error: " << SDL_GetError() << "\n";
      success = false;
    }

    //Create a Renderer to draw on
    gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
    // Check if Renderer did not create.
    if( gRenderer == NULL ){
      errorStream << "Renderer could not be created! SDL Error: " << SDL_GetError() << "\n";
      success = false;
    }
  }

  // Setup our characters
  // Remember, this can only be done after SDL has been
  // successfully initialized!
  // Here I am just building a little grid of characters
  int sum = 0;
  unsigned int yColumn = 0;
  constexpr int offset = 128;
  for(int i=0; i < CHARACTERS; ++i){
    sum += offset;
    if (sum > screenWidth){
      yColumn+=offset;
      sum =0;
    }
    characters[i].init(sum, yColumn, i, getSDLRenderer());
  }

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
SDLGraphicsProgram::~SDLGraphicsProgram(){
  // Destroy Renderer
  SDL_DestroyRenderer(gRenderer);
  //Destroy window
  SDL_DestroyWindow( gWindow );
  // Point gWindow to NULL to ensure it points to nothing.
  gRenderer = NULL;
  gWindow = NULL;
  //Quit SDL subsystems
  SDL_Quit();
}



// Update OpenGL
void SDLGraphicsProgram::update()
{
  for(int i =0; i < CHARACTERS; i++){
    characters[i].update();
  }
}


// Render
// The render function gets called once per loop
void SDLGraphicsProgram::render(){

  SDL_SetRenderDrawColor(gRenderer, 0x22,0x22,0x22,0xFF);
  SDL_RenderClear(gRenderer);  
    
  for(int i =0; i < CHARACTERS; i++){
    characters[i].render(getSDLRenderer());
  }

  SDL_RenderPresent(gRenderer);
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
  while(!quit){
    //Handle events on queue
    while(SDL_PollEvent( &e ) != 0){
      // User posts an event to quit
      // An example is hitting the "x" in the corner of the window.
      if(e.type == SDL_QUIT){
	      quit = true;
      }		
    }

    // If you have time, implement your frame capping code here
    // Otherwise, this is a cheap hack for this lab.
    SDL_Delay(16);

    // Update our scene
    update();
    // Render using OpenGL
    render();
    //Update screen of our specified window
  }

  //Disable text input
  SDL_StopTextInput();
}

// Get Pointer to Window
SDL_Window* SDLGraphicsProgram::getSDLWindow(){
  return gWindow;
}

// Get Pointer to Renderer
SDL_Renderer* SDLGraphicsProgram::getSDLRenderer(){
  return gRenderer;
}
