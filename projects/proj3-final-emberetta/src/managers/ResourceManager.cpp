#include "managers/ResourceManager.hpp"
#include "platformance/ObjectTypes.hpp"
#include "breakout/ObjectTypes.hpp"

#include "emberetta/ObjectTypes.hpp"
#include "emberetta/objects/EnemyShip.hpp"
#include "errno.h"
#include <unistd.h>

int ResourceManager::startUp(std::string resAffix, std::shared_ptr<SDL_Renderer> rend) {
	m_resAffix = resAffix;
	renderer = rend;
	return 0;
}

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
	std::string fullPath = getResourcePath(m_resAffix + "textures/") + path;
	// Lookup the texture to see if it is in the map.
	// Returns an iterator to the texture if it is found,
	// map::end otherwise.
	auto texture = textures.find(fullPath);

	if (texture == textures.end()) {
		SDL_Log("Allocated memory for a texture.");
		std::shared_ptr < SDL_Texture > newTexture = create_shared(IMG_LoadTexture(renderer.get(), fullPath.c_str()));
		if (newTexture == nullptr)
			std::cout << "LoadTexture: " << SDL_GetError() << std::endl;
		textures.insert(make_pair(fullPath, newTexture));
		return newTexture;
	}
	return texture->second;
}

std::shared_ptr<TTF_Font> ResourceManager::loadFont(const std::string &path) {
	std::string fullPath = getResourcePath(m_resAffix + "fonts") + path;
	//std::cout << fullPath << std::endl;
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

void ResourceManager::loadLevel(Platformance * level, unsigned int number) {
	std::fstream fin;    //File pointer
	std::stringstream ss;
	ss << number << ".lvl";
	std::string path = getResourcePath(m_resAffix + "levels/");

	fin.open(path + ss.str());//Open an existing file

	std::string line, word, music;

	std::cout << errno << std::endl;
	if (fin.is_open()) {
		std::cout << ss.str() << " open" << std::endl;
		while (getline(fin, line)) {
			std::stringstream s(line);
			std::vector<int> values;
			while (getline(s, word, ' ')) {
				// If we reach end of line comments, go to the next line
				if (word == "//") {
					break;
				}
				// Assuming everything before // is an int
				values.push_back(std::stoi(word)); //add all the column data of a row to a vector
				if (values[0] == TAG_BACKGROUND_MUSIC) {
					getline(s, music, ' ');
					level->setMusic(music);
				}
			}
			switch (values[0]) {
			case TAG_LEVEL_SIZE:
				level->setLevelSize(Vector2D(values[1],values[2]));
				break;
			case TAG_BACKGROUND_MUSIC:
				break;
			case TAG_BACKGROUND:
				level->addObject(std::make_shared<Background>(values[1], values[2]));
				break;
			case PlatformanceObjects::TAG_PLAYER:
				level->addObject(std::make_shared<Player>(values[1], values[2], values[3], values[4]));
				break;
			case PlatformanceObjects::TAG_GOAL:
				level->addObject(std::make_shared<Goal>(values[1], values[2], values[3], values[4], values[5]));
				break;
			case PlatformanceObjects::TAG_BRICK:
			{
				//std::cout << "Loading block" << std::endl;
				int x = values[1];
				int y = values[2];
				int w = values[3];
				int h = values[4];
				if (values.size() == 5) {
					level->addObject(std::make_shared<Brick>(x, y, w, h));
				} else {
					for (int i = 0; i < values[5]; i++) {
						level->addObject(std::make_shared<Brick>(x, y, w, h));
						x += w;
					}
				}
			}
			break;
			case PlatformanceObjects::TAG_ENEMY:
				//std::cout << "Loading Enemies" << std::endl;
				level->addObject(std::make_shared<Enemy>(values[1], values[2], values[3], values[4]));
				break;
			case PlatformanceObjects::TAG_COIN:
			{
				//std::cout << "Loading coin" << std::endl;
				int x = values[1];
				int y = values[2];
				int w = values[3];
				int h = values[4];
				if (values.size() == 5) {
					level->addObject(std::make_shared<Coin>(x, y, w, h));
				} else {
					for (int i = 0; i < values[5]; i++) {
						level->addObject(std::make_shared<Coin>(x, y, w, h));
						x += w;
					}
				}
			}
			break;
			case PlatformanceObjects::TAG_GAMECONTROLLER:
				//std::cout << "Loading GameController" << std::endl;
				break;
			default:
				std::cout << "Invalid type: " << values[0] << std::endl;
				break;
			}
			// Clear the last set
			values.clear();
		}

		level->addObject(std::make_shared<GameController>(0,0,0,0,level));
		fin.close();
	}
}

// TODO: I, Carter, duplicated code. There might be some way to reuse code so we don't have to duplicate it.
void ResourceManager::loadLevel(Breakout *level, unsigned int number) {

	std::fstream fin;    //File pointer
	std::stringstream ss;
	ss << number << ".lvl";
	std::string path = getResourcePath(m_resAffix + "levels/");

	fin.open(path + ss.str());//Open an existing file

	std::string line, word, music;

	std::cout << errno << std::endl;
	if (fin.is_open()) {
		std::cout << ss.str() << " open" << std::endl;
		while (getline(fin, line)) {
			std::stringstream s(line);
			std::vector<int> values;
			while (getline(s, word, ' ')) {
				// If we reach end of line comments, go to the next line
				if (word == "//") {
					break;
				}
				// Assuming everything before // is an int
				values.push_back(std::stoi(word)); //add all the column data of a row to a vector
				if (values[0] == TAG_BACKGROUND_MUSIC) {
					getline(s, music, ' ');
					level->setMusic(music);
				}
			}
			switch (values[0]) {
			case TAG_LEVEL_SIZE:
				level->setLevelSize(Vector2D(values[1],values[2]));
				break;
			case TAG_BACKGROUND_MUSIC:
				//std::cout << "Loading music " << music << std::endl;
				break;
			case TAG_BACKGROUND:
				level->addObject(std::make_shared<Background>(values[1], values[2]));
				//std::cout << "Loading background" << std::endl;
				break;
			case BreakoutObjects::TAG_PADDLE:
				//std::cout << "Loading paddle" << std::endl;
				level->addObject(std::make_shared<Paddle>(values[1], values[2], values[3], values[4]));
				break;
			case BreakoutObjects::TAG_BLOCK:
				//std::cout << "Loading block" << std::endl;
				level->addObject(std::make_shared<Block>(values[1], values[2], values[3], values[4]));
				break;
			case BreakoutObjects::TAG_BALL:
				//std::cout << "Loading ball" << std::endl;
				level->addObject(std::make_shared<Ball>(values[1], values[2], values[3], values[4]));
				break;	
			case BreakoutObjects::TAG_WALL:
				//std::cout << "Loading wall" << std::endl;
				level->addObject(std::make_shared<Wall>(values[1], values[2], values[3], values[4]));
				break;								
			default:
				std::cout << "Invalid type: " << values[0] << std::endl;
				break;
			}
			
			// Clear the last set
			values.clear();
		}
		//std::cout << "End of method " << std::endl;
		level->addObject(std::make_shared<Score>(0,0,0,0,level));
		level->addObject(std::make_shared<Lives>(0,0,0,0,level));
		fin.close();

	}	
}

// TODO: I, Jake, also duplicated code. There might be some way to reuse code so we don't have to duplicate it.
void ResourceManager::loadLevel(Emberetta *level, unsigned int number) {

	std::fstream fin;    //File pointer
	std::stringstream ss;
	ss << number << ".lvl";
	std::string path = getResourcePath(m_resAffix + "levels/");

	fin.open(path + ss.str());//Open an existing file

	std::string line, word, music;

	std::cout << errno << std::endl;
	if (fin.is_open()) {
		std::cout << ss.str() << " open" << std::endl;
		while (getline(fin, line)) {
			std::stringstream s(line);
			std::vector<int> values;
			while (getline(s, word, ' ')) {
				// If we reach end of line comments, go to the next line
				if (word == "//") {
					break;
				}
				// Assuming everything before // is an int
				values.push_back(std::stoi(word)); //add all the column data of a row to a vector
				if (values[0] == TAG_BACKGROUND_MUSIC) {
					getline(s, music, ' ');
					level->setMusic(music);
				}
			}
			switch (values[0]) {
			case TAG_LEVEL_SIZE:
				level->setLevelSize(Vector2D(values[1],values[2]));
				break;
			case TAG_BACKGROUND_MUSIC:
				std::cout << "Loading music " << music << std::endl;
				break;
			case TAG_BACKGROUND:
				level->addObject(std::make_shared<EmberettaBackground>(values[1], values[2]));
				//std::cout << "Loading background" << std::endl;
				break;
			case EmberettaObjects::TAG_SPAWNER:
				level->addObject(std::make_shared<Spawner>(values[1], values[2], values[3], values[4], values[5], values[6]));
				break;
			case EmberettaObjects::TAG_RANDOMSPAWNER:
				level->addObject(std::make_shared<RandomSpawner>(values[1], values[2], values[3], values[4]));
				break;
			case EmberettaObjects::TAG_PLAYERSHIP:
				//std::cout << "Loading paddle" << std::endl;
				level->addObject(std::make_shared<PlayerShip>(values[1], values[2]));
				break;
			case EmberettaObjects::TAG_ENEMYSHIP:
				//std::cout << "Loading block" << std::endl;
				level->addObject(std::make_shared<EnemyShip>(values[1], values[2]));
				break;
			case EmberettaObjects::TAG_ENEMYFIGHTER:
				//std::cout << "Loading block" << std::endl;
				level->addObject(std::make_shared<EnemyFighter>(values[1], values[2]));
				break;
			case EmberettaObjects::TAG_ENEMYBOMBER:
				//std::cout << "Loading block" << std::endl;
				level->addObject(std::make_shared<EnemyBomber>(values[1], values[2]));
				break;
			case EmberettaObjects::TAG_ENEMYINTERCEPTOR:
				//std::cout << "Loading block" << std::endl;
				level->addObject(std::make_shared<EnemyInterceptor>(values[1], values[2]));
				break;
			default:
				std::cout << "Invalid type: " << values[0] << std::endl;
				break;
			}

			// Clear the last set
			values.clear();
		}
		//std::cout << "End of method " << std::endl;
		level->addObject(std::make_shared<EmbScore>(0,0,0,0,level));
		level->addObject(std::make_shared<EmbLives>(0,0,0,0,level));
		fin.close();

	}
}

std::shared_ptr<Mix_Chunk> ResourceManager::loadSound(const std::string& path) {
	std::string fullPath = getResourcePath(m_resAffix + "sounds") + path;
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
	std::string fullPath = getResourcePath(m_resAffix + "sounds") + path;
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
	std::cout << getResourcePath(m_resAffix + "locale") << std::endl;
	inFile.open(getResourcePath(m_resAffix + "locale") + path);
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
