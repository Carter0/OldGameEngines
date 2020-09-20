/*
 * TimedExplode.cpp
 *
 *  Created on: Apr 6, 2020
 *      Author: jaked
 */


#include "emberetta/components/TimedExplode.hpp"

using namespace EmberettaObjects;

TimedExplode::TimedExplode(GameObject & gameObject, int delay):
	GenericComponent(gameObject) {
	start = SDL_GetTicks();
	total = delay;
}


void TimedExplode::update(Level & level) {
	if (!m_exploded && (SDL_GetTicks() - start > total)) {
		int pelletX = gameObject().x() + gameObject().w()/2;
		int pelletY = gameObject().y() + gameObject().h()/2;
		level.addObject(std::make_shared<EnemyPellet>(pelletX, pelletY, PELLET_SPEED,-PELLET_SPEED));
		level.addObject(std::make_shared<EnemyPellet>(pelletX, pelletY, -PELLET_SPEED,PELLET_SPEED));
		level.addObject(std::make_shared<EnemyPellet>(pelletX, pelletY, PELLET_SPEED,PELLET_SPEED));
		level.addObject(std::make_shared<EnemyPellet>(pelletX, pelletY, -PELLET_SPEED,-PELLET_SPEED));

		level.addObject(std::make_shared<EnemyPellet>(pelletX, pelletY, 0,PELLET_SPEED));
		level.addObject(std::make_shared<EnemyPellet>(pelletX, pelletY, PELLET_SPEED,0));
		level.addObject(std::make_shared<EnemyPellet>(pelletX, pelletY, 0,-PELLET_SPEED));
		level.addObject(std::make_shared<EnemyPellet>(pelletX, pelletY, -PELLET_SPEED,0));

		level.addObject(std::make_shared<BombDeleter>(gameObject().x() + 1 ,gameObject().y() + gameObject().h() ,0,0));
		m_exploded = true;
	}
}



