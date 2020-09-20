#ifndef BASE_PATROL_COMPONENT
#define BASE_PATROL_COMPONENT

#include "base/GenericComponent.hpp"
#include "TinyMath.hpp"
#include <vector>

//! \brief A component that causes its game object to patrol back and forth.
class PatrolComponent: public GenericComponent {
public:

	  PatrolComponent(GameObject & gameObject, float toX, float toY, float speed);
	  PatrolComponent(GameObject & gameObject, Vector2D dest, float speed);
	  PatrolComponent(GameObject & gameObject, std::vector<Vector2D> route, float speed);
  
  virtual void update(Level & level);

private:
  int m_step { 0 };
  std::vector<Vector2D> m_route;
  float m_speed;
  
};

#endif
