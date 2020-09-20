/*
 * EmberettaState.cpp
 *
 *  Created on: Apr 6, 2020
 *      Author: jaked
 */

#include "emberetta/behaviors/EmberettaStates.hpp"
#include <math.h>

// move the gameObject toward x,y at speed
// return true if reached
static
bool
moveToward(GameObject & gameObject, float x, float y, float speed)
{
	const float epsilon = 0.01;

	float dX = x - gameObject.x();
	float dY = y - gameObject.y();
	const float len = sqrtf(dX * dX + dY * dY);
	if (len < epsilon) {
		return true;
	} else {
		const float scale = std::min(len, speed);
		dX = dX / len * scale;
		dY = dY / len * scale;

		gameObject.setX(gameObject.x() + dX);
		gameObject.setY(gameObject.y() + dY);

		return (speed >= len - epsilon);
	}
}

void IdleState::update(GameObject & gameObject, Level & level){}


FireState::FireState(EnemyShip * ship, Uint32 frequency):
		m_ship(ship),
		m_frequency(frequency) {
	m_lastFired = SDL_GetTicks();
}


void FireState::update(GameObject & gameObject, Level & level) {
	if (SDL_GetTicks() - m_lastFired > m_frequency) {
		std::vector<std::shared_ptr<EnemyBullet>> bullets = m_ship->fire();
		for (std::shared_ptr<EnemyBullet> bullet : bullets) {
			level.addObject(bullet);
		}
		m_lastFired = SDL_GetTicks();
	}
}

BounceState::BounceState(float speedX, float speedY): m_speedX(speedX), m_speedY(speedY) {}
void BounceState::update(GameObject & gameObject, Level & level) {

	if (gameObject.x() - 5 < 0 || gameObject.x() + gameObject.w() + 5 > level.getLevelSize().x ) {
		m_speedX = -m_speedX;
	}
	gameObject.physicsComponent()->setVx(m_speedX);
	gameObject.physicsComponent()->setVy(m_speedY);
}

CircleState::CircleState(float angularSpeed, float speed, float radius, float centerX, float centerY):
			m_speed(speed),
			m_angleSpeed(angularSpeed),
			m_radius(radius),
			m_centerX(centerX),
			m_centerY(centerY){}

void CircleState::update(GameObject & gameObject, Level & level) {
	float xTarget = m_centerX + cos(m_angle)*m_radius;
	float yTarget = m_centerY + sin(m_angle)*m_radius;
	moveToward(gameObject, xTarget, yTarget, m_speed);
	m_angle += m_angleSpeed;
}
