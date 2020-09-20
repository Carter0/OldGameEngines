#ifndef BASE_PATROL_COMPONENT
#define BASE_PATROL_COMPONENT

#include "base/GenericComponent.hpp"

//! \brief A component that causes its game object to patrol back and forth.
class PatrolComponent: public GenericComponent {
public:

  PatrolComponent(GameObject & gameObject, float toX, float toY, float speed);
  
  virtual void update(Level & level);

private:

  bool mForward;
  int mStep;

  int mSteps;
  float mDx;
  float mDy; 
  // TODO: add variables
  
};

#endif
