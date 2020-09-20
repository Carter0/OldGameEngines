/*
 * EnemyShip.hpp
 *
 *  Created on: Apr 3, 2020
 *      Author: jaked
 */

#ifndef INCLUDE_EMBERETTA_OBJECTS_ENEMYSHIP_HPP_
#define INCLUDE_EMBERETTA_OBJECTS_ENEMYSHIP_HPP_

#include "base/GameObject.hpp"
#include "emberetta/ObjectTypes.hpp"
#include "TinyMath.hpp"
#include <iostream>

/**
 * Represents a generic enemy ship in emberetta
 */
class EnemyShip : public GameObject {
public:
	EnemyShip(float x, float y);
	/**
	 * Constructor for subtypes of enemy ships
	 */
	EnemyShip(float x, float y, float w, float h, int subType);
	std::ostream& print(std::ostream &out) override;
	virtual std::vector<std::shared_ptr<EnemyBullet>> fire();
protected:
	int shipTag;
	Vector2D shipShize;
};

/**
 * Represents a generic enemy ship in emberetta
 */
class EnemyFighter : public EnemyShip {
public:
	EnemyFighter(float x, float y);
	virtual std::vector<std::shared_ptr<EnemyBullet>> fire() override;
private:
	static const int shipType = EmberettaObjects::TAG_ENEMYFIGHTER;
	static const int shipW = 60;
	static const int shipH = 30;

};

/**
 * Represents a generic enemy ship in emberetta
 */
class EnemyBomber : public EnemyShip {
public:
	EnemyBomber(float x, float y);
	virtual std::vector<std::shared_ptr<EnemyBullet>> fire() override;
private:
	static const int shipType = EmberettaObjects::TAG_ENEMYBOMBER;
	static const int shipW = 60;
	static const int shipH = 60;

};

/**
 * Represents a generic enemy ship in emberetta
 */
class EnemyInterceptor : public EnemyShip {
public:
	EnemyInterceptor(float x, float y);
	virtual std::vector<std::shared_ptr<EnemyBullet>> fire() override;
private:
	static const int shipType = EmberettaObjects::TAG_ENEMYINTERCEPTOR;
	static const int shipW = 30;
	static const int shipH = 30;

};
#endif /* INCLUDE_EMBERETTA_OBJECTS_ENEMYSHIP_HPP_ */
