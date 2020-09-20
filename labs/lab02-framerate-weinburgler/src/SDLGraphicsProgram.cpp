// Support Code written by Michael D. Shah
// Updated by Seth Cooper
// Last Updated: Spring 2020
// Please do not redistribute without asking permission.

#include "SDLGraphicsProgram.hpp"
#include "res_path.hpp"



// Try toggling this number!
#define BLOCKS 500



template<typename T, typename... Args>
void cleanup(T *t, Args&&... args){
        //Cleanup the first item in the list
        cleanup(t);
        //Recurse to clean up the remaining arguments
        cleanup(std::forward<Args>(args)...);
}
template<>
inline void cleanup<SDL_Window>(SDL_Window *win){
        if (!win){
                return;
        }
        SDL_DestroyWindow(win);
}
template<>
inline void cleanup<SDL_Renderer>(SDL_Renderer *ren){
        if (!ren){
                return;
        }
        SDL_DestroyRenderer(ren);
}
template<>
inline void cleanup<SDL_Texture>(SDL_Texture *tex){
        if (!tex){
                return;
        }
        SDL_DestroyTexture(tex);
}
template<>
inline void cleanup<SDL_Surface>(SDL_Surface *surf){
        if (!surf){
                return;
        }
        SDL_FreeSurface(surf);
}








// Just a cheap little class to give a visual effect that stresses the system.
// This should also be useful for helping you get started with your breakout code!
// Move this to its own .hpp and .cpp files for best practice!
class Rectangle{
public:
  Rectangle(){
    // Empty constructor! We have complete control!
  }

  // Okay, but do not forget to call this!
  void init(int screenWidth, int screenHeight){
    x = rand()%screenWidth;
    y = rand()%screenHeight;
    w = rand()%100;
    h = rand()%100;
    speed = changeSpeed(); 
  }

  // Arguments here are a little redundant--do we need them?
  // (Perhaps if the screen resizes? Hmm!)
  void update(int screenWidth, int screenHeight){
    if(up){
      y+=speed;
      if(y>screenHeight){
	      up = !up;
      }
    }

    if(!up){
      y-=speed;
      if(y<0){
	      up = !up;
      }
    }
    if(left){
      x+=speed;
      if(x>screenWidth){
	      left = !left;
      }
    }

    if(!left){
      x-=speed;
      if(x<0){
	      left = !left;
      }
    }
  }

  // Okay, render our rectangles!
  void render(SDL_Renderer* gRenderer){
    SDL_Rect fillRect = {x,y,w,h};
    SDL_SetRenderDrawColor(gRenderer, randR, randG, randB, 0xFF);
    SDL_RenderDrawRect(gRenderer, &fillRect); 
  }

private:
     
  int x{100};
  int y{100};
  int w{100};
  int h{100};
  int speed;
  bool up{true};
  bool left{true};
  int randR = rand() % 255;
  int randG = rand() % 255;
  int randB = rand() % 255;

  int changeSpeed() {
    if (randR > 100) {
      speed += 3;
    } else if (randG > 100) {
      speed += 2;
    } else if (randB > 100) {
      speed += 1;
    }
    return speed + 1;
  }

};


/**
* Render the message we want to display to a texture for drawing
* @param message The message we want to display
* @param fontFile The font we want to use to render the text
* @param color The color we want the text to be
* @param fontSize The size we want the font to be
* @param renderer The renderer to load the texture in
* @return An SDL_Texture containing the rendered message, or nullptr if something went wrong
*/
SDL_Texture* renderText(const std::string &message, const std::string &fontFile,
        SDL_Color color, int fontSize, SDL_Renderer *renderer)
{
  //Open the font
  TTF_Font *font = TTF_OpenFont(fontFile.c_str(), fontSize);
  if (font == nullptr){
    std::cout << "TTF_OpenFont" << std::endl;
    std::cout << fontFile << std::endl;
    return nullptr;
  }
  //We need to first render to a surface as that's what TTF_RenderText
  //returns, then load that surface into a texture
  SDL_Surface *surf = TTF_RenderText_Blended(font, message.c_str(), color);
  if (surf == nullptr){
    TTF_CloseFont(font);
    std::cout << "Could not render to surface" << std::endl;
    return nullptr;
  }
  SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surf);
  if (texture == nullptr){
    std::cout << "CreateTexture" << std::endl;
  }
  //Clean up the surface and font
  SDL_FreeSurface(surf);
  TTF_CloseFont(font);
  return texture;
}

/**
* Draw an SDL_Texture to an SDL_Renderer at position x, y, with some desired
* width and height
* @param tex The source texture we want to draw
* @param ren The renderer we want to draw to
* @param x The x coordinate to draw to
* @param y The y coordinate to draw to
* @param w The width of the texture to draw
* @param h The height of the texture to draw
*/
void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y, int w, int h){
  //Setup the destination rectangle to be at the position we want
  SDL_Rect dst;
  dst.x = x;
  dst.y = y;
  dst.w = w;
  dst.h = h;
  SDL_RenderCopy(ren, tex, NULL, &dst);
}


/**
* Draw an SDL_Texture to an SDL_Renderer at position x, y, preserving
* the texture's width and height
* @param tex The source texture we want to draw
* @param ren The renderer we want to draw to
* @param x The x coordinate to draw to
* @param y The y coordinate to draw to
*/
void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y){
    int w, h;
    SDL_QueryTexture(tex, NULL, NULL, &w, &h);
    renderTexture(tex, ren, x, y, w, h);
}


// Create our list of rectangles!
Rectangle r[BLOCKS];


// Initialization function
// Returns a true or false value based on successful completion of setup.
// Takes in dimensions of window.
SDLGraphicsProgram::SDLGraphicsProgram(int w, int h):
  screenWidth(w),
  screenHeight(h),
  gWindow(nullptr),
  gRenderer(nullptr)
{
  // Initialize random number generation.
  srand(time(nullptr));
  // Setup blocks
  for(int i=0; i < BLOCKS; ++i){
    r[i].init(screenWidth, screenHeight);
  }


  // Initialization flag
  bool success = true;
  // String to hold any errors that occur.
  std::stringstream errorStream;

  // The window we'll be rendering to
  gWindow = nullptr;
  // Render flag

  // Initialize SDL
  if(SDL_Init(SDL_INIT_VIDEO)< 0){
    errorStream << "SDL could not initialize! SDL Error: " << SDL_GetError() << "\n";
    success = false;
  } else {
    //Create window
    gWindow = SDL_CreateWindow( "Lab", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth, screenHeight, SDL_WINDOW_SHOWN );

    // Check if Window did not create.
    if( gWindow == nullptr ){
      errorStream << "Window could not be created! SDL Error: " << SDL_GetError() << "\n";
      success = false;
    }

    //Create a Renderer to draw on
    gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
    // Check if Renderer did not create.
    if( gRenderer == nullptr ){
      errorStream << "Renderer could not be created! SDL Error: " << SDL_GetError() << "\n";
      success = false;
    }
  }

  //Initializes sdl image first. Avoids delay later.
  if ((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) != IMG_INIT_PNG){
    errorStream << "IMG_Init" << "\n";
    SDL_Quit();
  }

  //Initializes sdl fonts.
  if (TTF_Init() != 0){
    errorStream << "TTF_Init" << "\n";
    SDL_Quit();
  }

  // If initialization did not work, then print out a list of errors in the constructor.
  if(!success){
    errorStream << "Failed to initialize!\n";
    std::string errors=errorStream.str();
    std::cout << errors << "\n";
  }else{
    std::cout << "No SDL, or OpenGL, errors Detected\n\n";
  }
}




// Proper shutdown and destroy initialized objects
SDLGraphicsProgram::~SDLGraphicsProgram(){
  // Destroy Renderer
  SDL_DestroyRenderer(gRenderer);
  //Destroy window
  SDL_DestroyWindow( gWindow );
  // Point gWindow to NULL to ensure it points to nothing.
  gRenderer = nullptr;
  gWindow = nullptr;
  //Quit SDL subsystems
  SDL_Quit();
}



// Update OpenGL
void SDLGraphicsProgram::update()
{
  // Nothing yet!
  SDL_SetRenderDrawColor(gRenderer, 0x22,0x22,0x22,0xFF);
  SDL_RenderClear(gRenderer);  
  for(int i=0; i < BLOCKS; i++){
    r[i].update(screenWidth, screenHeight);
  }
}


// Render
// The render function gets called once per loop
void SDLGraphicsProgram::render(const float avgFPS){

  //Set text to be rendered
  timeText.str("");
  timeText << "Average Frames Per Second " << avgFPS;


  SDL_Texture *text = renderText(timeText.str(), getResourcePath() + "sample.ttf",
      textColor, 32, gRenderer);
   if (text == nullptr) { 
    cleanup(gRenderer, gWindow);
    TTF_Quit();
    SDL_Quit();
  }

  int iW2, iH2;
  SDL_QueryTexture(text, NULL, NULL, &iW2, &iH2);
  int x2 = screenWidth / 5 - iW2 / 2;
  int y2 = screenHeight / 7 - iH2 / 2;
  renderTexture(text, gRenderer, x2, y2);

  for(int i =0; i < BLOCKS; i++){
    r[i].render(gRenderer);
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

  //Start counting frames per second
  int countedFrames = 0;
  Uint32 start = SDL_GetTicks();

  Uint32 frameStart = 0;
  const int SCREEN_FPS = 60;
  const int SCREEN_TICKS_PER_FRAME = 1000 / SCREEN_FPS;

  while(!quit){

    frameStart = SDL_GetTicks();

    //Calculate and correct fps
    float avgFPS = countedFrames / ( (SDL_GetTicks() - start) / 1000.f );
    if( avgFPS > 2000000 )
    {
        avgFPS = 0;
    }


    //Handle events on queue
    while(SDL_PollEvent( &e ) != 0){
      // User posts an event to quit
      // An example is hitting the "x" in the corner of the window.
      if(e.type == SDL_QUIT){
	      quit = true;
      }		
    }
    // Update our scene
    update();
    render(avgFPS);
    ++countedFrames;

    //If frame finished early
    int frameTicks = SDL_GetTicks() - frameStart;
    if( frameTicks < SCREEN_TICKS_PER_FRAME )
    {
        //Wait remaining time
        SDL_Delay( SCREEN_TICKS_PER_FRAME - frameTicks );
    }
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
