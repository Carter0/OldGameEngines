/*
 * EmberettaStates.hpp
 *
 *  Created on: Apr 6, 2020
 *      Author: jaked
 */

#ifndef INCLUDE_EMBERETTA_BEHAVIORS_EMBERETTASTATES_HPP_
#define INCLUDE_EMBERETTA_BEHAVIORS_EMBERETTASTATES_HPP_

#include "base/StateComponent.hpp"
#include "emberetta/objects/PlayerShip.hpp"
#include "emberetta/objects/EnemyShip.hpp"
#include "emberetta/objects/EnemyBullet.hpp"
#include <SDL.h>


//! \brief Just Vibin'
class IdleState: public StateComponent::State {
public:

	IdleState(){};
	virtual void update(GameObject & gameObject, Level & level) override;

};

//! \brief Just Firing
class FireState: public StateComponent::State {
public:

	FireState(EnemyShip * ship, Uint32 frequency);
	virtual void update(GameObject & gameObject, Level & level) override;

private:
	EnemyShip * m_ship;
	Uint32 m_lastFired;
	Uint32 m_frequency;
};

/**
 * Enemy will move back and forth
 */
class BounceState: public StateComponent::State {
public:

	BounceState(float speedX, float speedY);
	virtual void update(GameObject & gameObject, Level & level) override;

private:

	float m_speedX, m_speedY;

};

/**
 * Enemy will move to a point, then start to circle around it
 */
class CircleState: public StateComponent::State {
public:

	CircleState(float angularSpeed, float speed, float radius, float centerX, float centerY);
	virtual void update(GameObject & gameObject, Level & level) override;

private:
	float m_speed;
	float m_angleSpeed;
	float m_radius;
	float m_centerX;
	float m_centerY;
	float m_angle {0};

};


#endif /* INCLUDE_EMBERETTA_BEHAVIORS_EMBERETTASTATES_HPP_ */
