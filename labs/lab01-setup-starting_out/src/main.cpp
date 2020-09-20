// code derived from TwinklebearDev SDL 2.0 Tutorial
// https://www.willusher.io/pages/sdl2/

#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "res_path.hpp"

/*
 * Recurse through the list of arguments to clean up, cleaning up
 * the first one in the list each iteration.
 */
template<typename T, typename... Args>
void cleanup(T *t, Args&&... args){
	//Cleanup the first item in the list
	cleanup(t);
	//Recurse to clean up the remaining arguments
	cleanup(std::forward<Args>(args)...);
}
/*
 * These specializations serve to free the passed argument and also provide the
 * base cases for the recursive call above, eg. when args is only a single item
 * one of the specializations below will be called by
 * cleanup(std::forward<Args>(args)...), ending the recursion
 * We also make it safe to pass nullptrs to handle situations where we
 * don't want to bother finding out which values failed to load (and thus are null)
 * but rather just want to clean everything up and let cleanup sort it out
 */
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



//Constants
const int SCREEN_WIDTH  = 640;
const int SCREEN_HEIGHT = 480;
const int TILE_SIZE = 40;


/**
* Log an SDL error with some error message to the output stream of our choice
* @param os The output stream to write the message to
* @param msg The error message to write, format will be msg error: SDL_GetError()
*/
void logSDLError(std::ostream &os, const std::string &msg){
	os << msg << " error: " << SDL_GetError() << std::endl;
}


/**
* Loads an image into a texture on the rendering device
* @param file The image file to load
* @param ren The renderer to load the texture onto
* @return the loaded texture, or nullptr if something went wrong.
*/
SDL_Texture* loadTexture(const std::string &file, SDL_Renderer *ren){
	SDL_Texture *texture = IMG_LoadTexture(ren, file.c_str());
	if (texture == nullptr){
		logSDLError(std::cout, "LoadTexture");
	}
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
		logSDLError(std::cout, "TTF_OpenFont");
		return nullptr;
	}	
	//We need to first render to a surface as that's what TTF_RenderText
	//returns, then load that surface into a texture
	SDL_Surface *surf = TTF_RenderText_Blended(font, message.c_str(), color);
	if (surf == nullptr){
		TTF_CloseFont(font);
		logSDLError(std::cout, "TTF_RenderText");
		return nullptr;
	}
	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surf);
	if (texture == nullptr){
		logSDLError(std::cout, "CreateTexture");
	}
	//Clean up the surface and font
	SDL_FreeSurface(surf);
	TTF_CloseFont(font);
	return texture;
}

int main(int argc, char **argv){
  
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
    logSDLError(std::cout, "SDL_Init");
    return 1;
  }

  //Initializes sdl image first. Avoids delay later.
  if ((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) != IMG_INIT_PNG){
    logSDLError(std::cout, "IMG_Init");
    SDL_Quit();
    return 1;
  }

  //Initializes sdl fonts.
  if (TTF_Init() != 0){
    logSDLError(std::cout, "TTF_Init");
    SDL_Quit();
    return 1;
  }

  SDL_Window *window = SDL_CreateWindow("Lesson 2", 100, 100, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
  if (window == nullptr){
    logSDLError(std::cout, "CreateWindow");
    SDL_Quit();
    return 1;
  }

  SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (renderer == nullptr){
    logSDLError(std::cout, "CreateRenderer");
    cleanup(window);
    SDL_Quit();
    return 1;
  }

  SDL_Texture *background = loadTexture(getResourcePath() + "background.png", renderer);
  SDL_Texture *image = loadTexture(getResourcePath() + "image.png", renderer);
  if (image == nullptr || background == nullptr){
    cleanup(background, image, renderer, window);
    SDL_Quit();
    return 1;
  }

  SDL_Event e;
  bool quit = false;
  unsigned int counter = 0;
  unsigned int sizeCounter = 0;
  SDL_Rect dst;
  while (!quit){
    //Read user input & handle it
    //Render our scene

    //e is an SDL_Event variable we've declared before entering the main loop
    while (SDL_PollEvent(&e)){
      //If user closes the window
      if (e.type == SDL_QUIT){
        quit = true;
      }
      //If user presses any key
      if (e.type == SDL_KEYDOWN){
        quit = true;
      }
      //If user clicks the mouse
      if (e.type == SDL_MOUSEBUTTONDOWN){
        quit = true;
      }
    }

    //Render the scene
    SDL_RenderClear(renderer);

  
    //Determine how many tiles we'll need to fill the screen
    int xTiles = SCREEN_WIDTH / TILE_SIZE;
    int yTiles = SCREEN_HEIGHT / TILE_SIZE;

    //Draw the tiles by calculating their positions
    for (int i = 0; i < xTiles * yTiles; ++i){
      int x = i % xTiles;
      int y = i / xTiles;
      renderTexture(background, renderer, x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE,
        TILE_SIZE);
    }

    //render foreground image.
    //Animate the foreground image based on counters above.
    int iW, iH;
    SDL_QueryTexture(image, NULL, NULL, &iW, &iH);
    int y = SCREEN_HEIGHT / 2 - iH / 2;
    counter++;
    sizeCounter += 20;
    std::cout << "The counter is ";
    std::cout << sizeCounter << std::endl;
    dst.x = counter;
    dst.y = y;
    dst.w = iW + sizeCounter;
    dst.h = iH;
    SDL_RenderCopy(renderer, image, NULL, &dst);


    //render the font
    //We'll render the string "TTF fonts are cool!" in white
    //Color is in RGBA format
    SDL_Color color = { 255, 255, 255, 255 };
    SDL_Texture *image = renderText("TTF fonts are cool!", getResourcePath() + "sample.ttf",
      color, 64, renderer);
    if (image == nullptr){
      cleanup(renderer, window);
      TTF_Quit();
      SDL_Quit();
      return 1;
    }

    //Get the texture w/h so we can center it in the screen
    int iW2, iH2;
    SDL_QueryTexture(image, NULL, NULL, &iW2, &iH2);
    int x2 = SCREEN_WIDTH / 2 - iW2 / 2;
    int y2 = SCREEN_HEIGHT / 2 - iH2 / 2;
    renderTexture(image, renderer, x2, y2);
    
    SDL_RenderPresent(renderer);
    SDL_Delay(500);
  }



  cleanup(background, image, renderer, window);
  SDL_Quit();
  return 0;
}
