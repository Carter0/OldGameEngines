#include "ResourceManager.hpp"
#include <iostream>

int ResourceManager::startUp(std::shared_ptr<SDL_Renderer> rend) {
	renderer = rend;
	return 0;
}

int ResourceManager::shutDown() {
	textures.clear();
	fonts.clear();
	sounds.clear();
	musics.clear();
	return 0;
}

std::shared_ptr<SDL_Texture> ResourceManager::loadTexture(const std::string &path) {
	std::string fullPath = getResourcePath("textures") + path;
	// Lookup the texture to see if it is in the map.
	// Returns an iterator to the texture if it is found,
	// map::end otherwise.
	auto texture = textures.find(fullPath);

	if (texture == textures.end()) {
		SDL_Log("Allocated memory for a texture.");
		std::shared_ptr < SDL_Texture > newTexture = create_shared(IMG_LoadTexture(renderer.get(), fullPath.c_str()));
		textures.insert(make_pair(fullPath, newTexture));
		return newTexture;
	}
	return texture->second;
}

std::shared_ptr<TTF_Font> ResourceManager::loadFont(const std::string &path) {
	std::string fullPath = getResourcePath(".") + path;
	// Lookup the font to see if it is in the font map.
	// Returns an iterator to the font if it is found,
	// map::end otherwise.
	auto font = fonts.find(fullPath);

	if (font == fonts.end()) {
		SDL_Log("Allocated memory for a font.");
		std::shared_ptr < TTF_Font > font = create_shared(TTF_OpenFont(fullPath.c_str(), 48));
		fonts.insert(make_pair(fullPath, font));
		return font;
	}

	return font->second;
}

void ResourceManager::loadLevel(std::vector<Brick> &bricks, unsigned int level) {
	std::fstream fin;    //File pointer
	std::stringstream ss;
	ss << level;
	fin.open("./res/levels/" + ss.str() + ".lvl");    //Open an existing file

	std::vector<int> row;    //Read the Data from the file as int Vector
	std::string line, word;
	int i = 0;

	if (fin.is_open()) {
		while (getline(fin, line)) {
			std::stringstream s(line);
			while (getline(s, word, ',')) {
				row.push_back(std::stoi(word)); //add all the column data of a row to a vector
			}
			bricks.push_back(Brick(BoundingBox(row[i], row[i + 1], row[i + 2],row[i + 3]), 1));
			i += 4;
		}
		fin.close();
	}
}

std::shared_ptr<Mix_Chunk> ResourceManager::loadSound(const std::string& path) {
	std::string fullPath = getResourcePath(".") + path;
	// Lookup the sound to see if it is in the sound map.
	// Returns an iterator to the font if it is found,
	// map::end otherwise.
	auto sound = sounds.find(fullPath);

	if (sound == sounds.end()) {
		SDL_Log("Allocated memory for a sound.");
		std::shared_ptr<Mix_Chunk> theSound = create_shared(Mix_LoadWAV(fullPath.c_str()));
		sounds.insert(make_pair(fullPath, theSound));
		return theSound;
	}

	return sound->second;
}

std::shared_ptr<Mix_Music> ResourceManager::loadMusic(const std::string& path) {
	std::string fullPath = getResourcePath(".") + path;
	// Lookup the music to see if it is in the music map.
	// Returns an iterator to the font if it is found,
	// map::end otherwise.
	auto music = musics.find(fullPath);

	if (music == musics.end()) {
		SDL_Log("Allocated memory for a music.");
		std::shared_ptr<Mix_Music> newMusic = create_shared(Mix_LoadMUS(fullPath.c_str()));
		musics.insert(make_pair(fullPath, newMusic));
		return newMusic;
	}
	return music->second;
}

std::vector<std::string> ResourceManager::loadLocale(std::string path) {
	std::ifstream inFile;
	inFile.open(getResourcePath("locale") + path);
	std::vector<std::string> gameText;

	
	
	if (!inFile) {
    	std::cout << "Unable to open locale file" << std::endl;
    	exit(1); 
	}
	
	std::string line;
	while (std::getline(inFile, line))
	{
    	gameText.push_back(line);
	}

	return gameText;
}
