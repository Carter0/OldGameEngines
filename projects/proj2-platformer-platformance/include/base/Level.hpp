#pragma once

#include "base/GameObject.hpp"
#include "managers/AudioManager.hpp"
#include <SDL_ttf.h>
#include <map>
#include <memory>
#include <SDL.h>


//! \brief A level in the game.  Essentially mannages a collection of game
//! objects, and does some collision detection.
class Level {
public:
	Level(int w, int h);

	inline int w() const { return mW; }
	inline int h() const { return mH; }

	void addObject(std::shared_ptr<GameObject> object); //!< Set an object to be added.
	void removeObject(std::shared_ptr<GameObject> object); //!< Set an object to be removed.
	void incrementScore(const int score); //! < Add to the players score. 

	inline std::vector<std::shared_ptr<GameObject>> objects() const { return mObjects; }


	bool getCollisions(const GameObject & obj, std::vector<std::shared_ptr<GameObject>> & objects) const; //!< Get objects colliding with a given object.
	bool getCollisions(float px, float py, std::vector<std::shared_ptr<GameObject>> & objects) const; //!< Get objects colliding with a given point.

	virtual void update(); //!< Update the objects in the level.
	virtual void render(SDL_Renderer * renderer); //!< Render the level.
	inline void setLevelSize(Vector2D size) { m_levelSize = size; }
	inline Vector2D getLevelSize() { return m_levelSize; };

	inline void setProperty(std::string tag, int value) { mProperties[tag] = value; }
	inline int getProperty(std::string tag) {
		if (mProperties.find(tag) == mProperties.end()) {
			return -1;
		} else {
			return mProperties[tag];
		}
	}

	void setMusic(std::string newMusic);
	inline std::string getMusic() { return m_music; }

	virtual void loadLevel(int level = 1) {m_level = level;};
	inline int getLevel() { return m_level; }
	inline void setLevel(int level) { m_level = level; }

	std::string print(std::ostream& out);

protected:

	Level(const Level &) = delete;
	void operator=(Level const&) = delete;

	int mW, mH;

	Vector2D m_levelSize;
	std::vector<std::shared_ptr<GameObject>> mObjects;
	std::vector<std::shared_ptr<GameObject>> mObjectsToAdd;
	std::vector<std::shared_ptr<GameObject>> mObjectsToRemove;

	std::map<std::string, int> mProperties;
	std::string m_music {""};
	int m_level {1};
	int m_max_level {3};

public:
	unsigned int m_score;
};
