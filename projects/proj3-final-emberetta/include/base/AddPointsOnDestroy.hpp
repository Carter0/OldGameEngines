#ifndef BASE_ADD_POINTS_DESTROY_COMPONENT
#define BASE_ADD_POINTS_DESTROY_COMPONENT

#include "base/GenericComponent.hpp"

//! \brief A component that adds to the score of the level on collision.
class AddPointsOnDestroy: public GenericComponent {
public:

	/**
	 * Creates the Component
	 * @param gameObject the associated gameobject
	 * @param tag the tag type that will add to the score
	 */
	AddPointsOnDestroy(GameObject & gameObject, unsigned int scoreToAdd);
  
  virtual void onDestroy(Level & level) override;

private:
  unsigned int mScoreToAdd;
  
};

#endif
