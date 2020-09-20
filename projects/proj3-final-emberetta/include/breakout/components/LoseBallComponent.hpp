#pragma once

#include "base/GenericComponent.hpp"
#include "breakout/Breakout.hpp"
#include "base/GameObject.hpp"
#include "base/Level.hpp"

//! \brief Component for what happens when the ball falls off the screen.
class LoseBallComponent: public GenericComponent {
public:
	LoseBallComponent(GameObject & gameObject);

	virtual void update(Level & level) override;
};
