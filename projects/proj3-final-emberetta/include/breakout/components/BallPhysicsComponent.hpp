#pragma once
#ifndef BALL_PHYSICS_COMPONENT
#define BALL_PHYSICS_COMPONENT

#include "base/PhysicsComponent.hpp"


//! \brief A component for handling how the ball moves and collides throughout breakout.
class BallPhysicsComponent: public PhysicsComponent {
public:
  BallPhysicsComponent(GameObject & gameObject, bool solid, float xSpeed, float ySpeed);
  virtual void step(Level & level) override;

};

#endif
