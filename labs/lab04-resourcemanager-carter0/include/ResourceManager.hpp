#ifndef RESOURCE_MANAGER_HPP
#define RESOURCE_MANAGER_HPP

#include <string>
#include <SDL.h>
#include <map>


/**
 * A class for managing game resources.  Allows access to resources
 * and makes sure there is only one copy of each resource loaded at a
 * time.
 */
class ResourceManager {
private:

  ResourceManager(){}  // Private Singleton
  ResourceManager(ResourceManager const&) = delete; // Avoid copy constructor.
  void operator=(ResourceManager const&) = delete; // Don't allow copy assignment.
  ResourceManager(ResourceManager const&&) = delete; // Avoid move constructor.
  void operator=(ResourceManager const&&) = delete; // Don't allow move assignment.

  /**
  * The collection that will hold our resource.
  * It will be from the string path to the SDL_texture.
  */ 
  std::map<std::string, SDL_Texture*> textures;
public:
  
  /**
  * Returns the texture for the render function to use.
  */
  static ResourceManager& getInstance()
  {
    static ResourceManager inst;
    return inst;
  }
  
  /**
  * Equivalent to a constructor.
  */
  int startUp();
  
  /**
  * Equivalent to a destructor.
  * Will go through the map and free the SDL textures allocated.
  */
  int shutDown();

  /**
  * Lookup the texture to see if it was already allocated in the map.
  * If it was, find the resource and return it, otherwise, allocate a new resurce and add it to the map.
  */
  SDL_Texture * loadTexture(const std::string& path, SDL_Renderer* renderer);  
};

#endif
