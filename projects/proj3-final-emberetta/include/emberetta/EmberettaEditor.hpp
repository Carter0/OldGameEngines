#pragma once

#include "Emberetta.hpp"
#include "managers/ResourceManager.hpp"
#include <algorithm>

//! \brief A class representing one instance of the game
class EmberettaEditor: public Emberetta {
public:
	EmberettaEditor(int w, int h);
	virtual ~EmberettaEditor() { };
	virtual void update() override;
	virtual void render(SDL_Renderer *renderer) override;
	void clear();
	virtual void loadLevel(int level = 1) override;
	void alterValues(float &x, float &y, float &w, float &h);
	//void renderEditor(SDL_Renderer* renderer);

protected:
	SDL_Renderer* mRenderer;
	bool blocking = false, unblocking = false;
	bool m_stopped = true;

};
