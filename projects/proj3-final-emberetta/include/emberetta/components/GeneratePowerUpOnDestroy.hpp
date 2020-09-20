/*
 * GeneratePowerUpOnCollide.hpp
 *
 *  Created on: Apr 11, 2020
 *      Author: jaked
 */

#ifndef INCLUDE_EMBERETTA_COMPONENTS_GENERATEPOWERUPONDESTROY_HPP_
#define INCLUDE_EMBERETTA_COMPONENTS_GENERATEPOWERUPONDESTROY_HPP_

#include "emberetta/ObjectTypes.hpp"
#include "base/GenericComponent.hpp"
#include "base/GameObject.hpp"
#include "base/Level.hpp"
#include "emberetta/objects/PowerUp.hpp"


class GeneratePowerUpOnDestroy : public GenericComponent {
public:
	GeneratePowerUpOnDestroy(GameObject & gameObject, float chance);
	virtual void onDestroy(Level & level) override;
private:
	float m_chance {.10};
};



#endif /* INCLUDE_EMBERETTA_COMPONENTS_GENERATEPOWERUPONDESTROY_HPP_ */
