/*
 * TimedExplode.hpp
 *
 *  Created on: Apr 6, 2020
 *      Author: jaked
 */

#ifndef INCLUDE_EMBERETTA_COMPONENTS_TIMEDEXPLODE_HPP_
#define INCLUDE_EMBERETTA_COMPONENTS_TIMEDEXPLODE_HPP_


#include "emberetta/ObjectTypes.hpp"
#include "base/GenericComponent.hpp"
#include "base/GameObject.hpp"
#include "base/Level.hpp"
#include "emberetta/objects/EnemyBullet.hpp"


class TimedExplode : public GenericComponent {
public:
	TimedExplode(GameObject & gameObject, int delay);
	virtual void update(Level & level) override;
private:
	Uint32 start;
	Uint32 total;
	bool m_exploded{false};
};

#endif /* INCLUDE_EMBERETTA_COMPONENTS_TIMEDEXPLODE_HPP_ */
