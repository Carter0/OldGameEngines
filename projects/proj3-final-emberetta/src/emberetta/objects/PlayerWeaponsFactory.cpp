/*
 * PlayerWeaponFactory.cpp
 *
 *  Created on: Apr 3, 2020
 *      Author: jaked
 */

#include "emberetta/objects/PlayerWeaponsFactory.hpp"
#include "emberetta/objects/FriendlyBullet.hpp"
#include <iostream>

std::vector<std::shared_ptr<GameObject>> PlayerWeaponsFactory::fireWeapon(float x, float y) {
	std::vector<std::shared_ptr<GameObject>> projectiles;
	Uint32 current = SDL_GetTicks();
	switch (type) {
	case 0:
		switch (level) {
		case 1:
			if (current - m_last < 500) {
				return projectiles;
			}
			projectiles.push_back(std::make_shared<FriendlyBullet>(x,y,-10));
			break;
		case 2:
			if (current - m_last < 333) {
				return projectiles;
			}
			projectiles.push_back(std::make_shared<FriendlyBullet>(x,y,-10));
			break;
		case 3:
			if (current - m_last < 333) {
				return projectiles;
			}
			projectiles.push_back(std::make_shared<FriendlyBullet>(x-4,y,-10));
			projectiles.push_back(std::make_shared<FriendlyBullet>(x+4,y,-10));
			break;
		case 4:
			if (current - m_last < 200) {
				return projectiles;
			}
			projectiles.push_back(std::make_shared<FriendlyBullet>(x-4,y,-10));
			projectiles.push_back(std::make_shared<FriendlyBullet>(x+4,y,-10));
			break;
		case 5:
			if (current - m_last < 150) {
				return projectiles;
			}
			projectiles.push_back(std::make_shared<FriendlyBullet>(x-8,y,-10));
			projectiles.push_back(std::make_shared<FriendlyBullet>(x,y,-10));
			projectiles.push_back(std::make_shared<FriendlyBullet>(x+8,y,-10));
			break;
		}
		break;
		case 1:
			switch (level) {
			case 1:
				if (current - m_last < 500) {
					return projectiles;
				}
				projectiles.push_back(std::make_shared<FriendlyLaser>(x,y,0,-10));
				break;
			case 2:
				if (current - m_last < 500) {
					return projectiles;
				}
				projectiles.push_back(std::make_shared<FriendlyLaser>(x,y,0,-10));
				projectiles.push_back(std::make_shared<FriendlyLaser>(x,y,0,-10));
				break;
			case 3:
				if (current - m_last < 500) {
					return projectiles;
				}
				projectiles.push_back(std::make_shared<FriendlyLaser>(x,y,0,-10));
				projectiles.push_back(std::make_shared<FriendlyLaser>(x,y,0,-10));
				projectiles.push_back(std::make_shared<FriendlyLaser>(x,y,0,-10));
				break;
			case 4:
				if (current - m_last < 500) {
					return projectiles;
				}
				projectiles.push_back(std::make_shared<FriendlyLaser>(x,y,0,-10));
				projectiles.push_back(std::make_shared<FriendlyLaser>(x,y,0,-10));
				projectiles.push_back(std::make_shared<FriendlyLaser>(x,y,0,-10));
				projectiles.push_back(std::make_shared<FriendlyLaser>(x,y,0,-10));
				break;
			case 5:
				if (current - m_last < 500) {
					return projectiles;
				}
				projectiles.push_back(std::make_shared<FriendlyLaser>(x,y,0,-10));
				projectiles.push_back(std::make_shared<FriendlyLaser>(x,y,0,-10));
				projectiles.push_back(std::make_shared<FriendlyLaser>(x,y,0,-10));
				projectiles.push_back(std::make_shared<FriendlyLaser>(x,y,0,-10));
				projectiles.push_back(std::make_shared<FriendlyLaser>(x,y,0,-10));
				break;
			}
			break;
		case 2:
			switch (level) {
			case 1:
				if (current - m_last < 500) {
					return projectiles;
				}
				projectiles.push_back(std::make_shared<FriendlyBulletTwo>(x+6,y,0,-10));
				projectiles.push_back(std::make_shared<FriendlyBulletTwo>(x-6,y,0,-10));
				break;
			case 2:
				if (current - m_last < 500) {
					return projectiles;
				}
				projectiles.push_back(std::make_shared<FriendlyBulletTwo>(x,y,1,-10));
				projectiles.push_back(std::make_shared<FriendlyBulletTwo>(x,y,0,-10));
				projectiles.push_back(std::make_shared<FriendlyBulletTwo>(x,y,-1,-10));
				break;
			case 3:
				if (current - m_last < 500) {
					return projectiles;
				}
				projectiles.push_back(std::make_shared<FriendlyBulletTwo>(x,y,1,-10));
				projectiles.push_back(std::make_shared<FriendlyBulletTwo>(x+6,y,0,-10));
				projectiles.push_back(std::make_shared<FriendlyBulletTwo>(x-6,y,0,-10));
				projectiles.push_back(std::make_shared<FriendlyBulletTwo>(x,y,-1,-10));
				break;
			case 4:
				if (current - m_last < 500) {
					return projectiles;
				}
				projectiles.push_back(std::make_shared<FriendlyBulletTwo>(x,y,1,-10));
				projectiles.push_back(std::make_shared<FriendlyBulletTwo>(x,y,0,-10));
				projectiles.push_back(std::make_shared<FriendlyBulletTwo>(x,y,-1,-10));
				projectiles.push_back(std::make_shared<FriendlyBulletTwo>(x,y,2,-10));
				projectiles.push_back(std::make_shared<FriendlyBulletTwo>(x,y,-2,-10));
				break;
			case 5:
				if (current - m_last < 500) {
					return projectiles;
				}
				projectiles.push_back(std::make_shared<FriendlyBulletTwo>(x,y,1,-10));
				projectiles.push_back(std::make_shared<FriendlyBulletTwo>(x+8,y,0,-10));
				projectiles.push_back(std::make_shared<FriendlyBulletTwo>(x-8,y,0,-10));
				projectiles.push_back(std::make_shared<FriendlyBulletTwo>(x,y,-1,-10));
				projectiles.push_back(std::make_shared<FriendlyBulletTwo>(x,y,2,-10));
				projectiles.push_back(std::make_shared<FriendlyBulletTwo>(x,y,-2,-10));
				break;
			}
			break;
	default:
		std::cout << "Unreachable" << std::endl;
	}
	if (projectiles.size() > 0)
		m_last = current;

	return projectiles;
}

