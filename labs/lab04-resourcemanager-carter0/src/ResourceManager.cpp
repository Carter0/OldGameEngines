#include "ResourceManager.hpp"

int ResourceManager::startUp() {
    return 0;
}


int ResourceManager::shutDown() {
    //Go into the map and free all the textures.
    for (auto it = textures.begin(); it!=textures.end(); it++)
        SDL_DestroyTexture(it->second);
    return 0;
}

SDL_Texture * ResourceManager::loadTexture(const std::string& path, SDL_Renderer* renderer) {   

    // Lookup the texture to see if it is in the map.
    // Returns an iterator to the texture if it is found,
    // map::end otherwise.
    auto texture = textures.find(path);

    if (texture == textures.end()) {
        SDL_Log("Allocated memory for the game character texture.");
        SDL_Surface * spriteSheet = SDL_LoadBMP(path.c_str());
        SDL_Texture * newTexture = SDL_CreateTextureFromSurface(renderer, spriteSheet);
        textures.insert(make_pair(path, newTexture));
        SDL_FreeSurface(spriteSheet);
        return newTexture;
    }

    return texture->second;
}
