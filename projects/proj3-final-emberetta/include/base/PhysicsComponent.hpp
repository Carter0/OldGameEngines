#ifndef BASE_PHYSICS_COMPONENT
#define BASE_PHYSICS_COMPONENT

#include "base/Component.hpp"
#include <iostream>
#include <memory>

class Level;

//! \brief A component for handling simple physics. Has a velocity and
//! a solid property.  Solid objects prevent non-solid objects from
//! moving through them, and non-solid objects can collide with each
//! other.
class PhysicsComponent: public Component {
public:

  PhysicsComponent(GameObject & gameObject, bool solid);
  PhysicsComponent(GameObject &gameObject, bool solid, float xSpeed, float ySpeed);

  inline bool isSolid() const { return mSolid; }
  
  inline float vx() const { return mVx; }
  inline float vy() const { return mVy; }
  inline void setVx(float vx) { mVx = vx;}
  inline void setVy(float vy) { mVy = vy;}
  
  bool hitLeft(float x, float y, float w, float h);
  bool hitRight(float x, float y, float w, float h);
  bool hitFloor(float x, float y, float w, float h);
  bool hitCeiling(float x, float y, float w, float h);

  virtual void step(Level & level); //!< Step the physics.

private:

  bool mSolid;
  float mVx, mVy;

};

#endif
