/*
 * Util.hpp
 *
 *  Created on: Feb 11, 2020
 *      Author: Jake Dec
 */

#ifndef INCLUDE_UTIL_HPP_
#define INCLUDE_UTIL_HPP_

#include <memory>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <iostream>
#include "TinyMath.hpp"

/**
 * Handle freeing memory from shared pointers
 */
static inline void SDL_DelResource(SDL_Window   *r) { SDL_DestroyWindow(r);   }
static inline void SDL_DelResource(SDL_Renderer *r) { SDL_DestroyRenderer(r); }
static inline void SDL_DelResource(SDL_Texture  *r) { SDL_DestroyTexture(r);  }
static inline void SDL_DelResource(SDL_Surface  *r) { SDL_FreeSurface(r);     }
static inline void SDL_DelResource(Mix_Music  *r) { Mix_FreeMusic(r);  }
static inline void SDL_DelResource(Mix_Chunk  *r) { Mix_FreeChunk(r);     }
static inline void SDL_DelResource(TTF_Font  *r) { TTF_CloseFont(r);     }



/**
 * Template for handling SDL resources that create a shared pointer with appropriate destruction method.
 * https://blog.galowicz.de/2016/02/21/automatic_resource_release_with_sdl/
 */
template <typename T>
std::shared_ptr<T> create_shared(T *t) {
    return std::shared_ptr<T>(t, [](T *t) { SDL_DelResource(t); });
}

inline std::string getResourcePath(const std::string &subDir){
	//We need to choose the path separator properly based on which
	//platform we're running on, since Windows uses a different
	//separator than most systems
#ifdef _WIN32
	const char PATH_SEP = '\\';
#else
	const char PATH_SEP = '/';
#endif
	//This will hold the base resource path: Lessons/res/
	//We give it static lifetime so that we'll only need to call
	//SDL_GetBasePath once to get the executable path
	static std::string baseRes;
	if (baseRes.empty()){
		//SDL_GetBasePath will return NULL if something went wrong in retrieving the path
		char *basePath = SDL_GetBasePath();
		if (basePath){
			baseRes = basePath;
			SDL_free(basePath);
		}
		else {
			std::cerr << "Error getting resource path: " << SDL_GetError() << std::endl;
			return "";
		}
		//We replace the last bin/ with res/ to get the the resource path
		size_t pos = baseRes.rfind("bin");
		baseRes = baseRes.substr(0, pos) + "res" + PATH_SEP;
	}
	//If we want a specific subdirectory path in the resource directory
	//append it to the base path. This would be something like Lessons/res/Lesson0
	return subDir.empty() ? baseRes : baseRes + subDir + PATH_SEP;
}


#endif /* INCLUDE_UTIL_HPP_ */
