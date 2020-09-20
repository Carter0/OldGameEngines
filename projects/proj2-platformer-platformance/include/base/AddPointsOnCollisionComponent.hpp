#ifndef BASE_ADD_POINTS_COMPONENT
#define BASE_ADD_POINTS_COMPONENT

#include "base/GenericComponent.hpp"

//! \brief A component that adds to the score of the level on collision.
class AddPointsOnCollisionComponent: public GenericComponent {
public:

	/**
	 * Creates the Component
	 * @param gameObject the associated gameobject
	 * @param tag the tag type that will add to the score
	 */
  AddPointsOnCollisionComponent(GameObject & gameObject, int tag);
  
  virtual void collision(Level & level, std::shared_ptr<GameObject> obj) override;

private:

  int mTag;
  
};

#endif
