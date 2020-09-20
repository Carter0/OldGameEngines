#include "base/PatrolComponent.hpp"
#include "base/GameObject.hpp"


//! \brief A component which will make a GameObject patrol a specified area.
PatrolComponent::PatrolComponent(GameObject & gameObject, float toX, float toY, float speed): 
	PatrolComponent(gameObject, Vector2D(toX, toY), speed) {}

PatrolComponent::PatrolComponent(GameObject & gameObject, Vector2D goal, float speed):
	GenericComponent(gameObject),
	m_speed(speed)
{
	m_route.push_back(Vector2D(gameObject.x(), gameObject.y()));
	m_route.push_back(goal);
}


PatrolComponent::PatrolComponent(GameObject & gameObject, std::vector<Vector2D> route, float speed):
	GenericComponent(gameObject),
	m_route(route),
	m_speed(speed)
{
	m_route.push_back(Vector2D(gameObject.x(), gameObject.y()));
}

void PatrolComponent::update(Level & level)
{
	// If we reached the goal, advance to the next step
	if (abs(m_route[m_step].x - gameObject().x()) < m_speed &&
	   abs(m_route[m_step].y - gameObject().y()) < m_speed) {
		m_step = (m_step + 1) % m_route.size();
	}

	// Else update the position towards the goal
	if (abs(m_route[m_step].x - gameObject().x()) < m_speed) {
		gameObject().setX(m_route[m_step].x);
	} else {
		float newX = gameObject().x() + (m_route[m_step].x < gameObject().x() ? -m_speed : m_speed);
		gameObject().setX(newX);
	}

	// Else update the position towards the goal
	if (abs(m_route[m_step].y - gameObject().y()) < m_speed) {
		gameObject().setY(m_route[m_step].y);
	} else {
		float newY = gameObject().y() + (m_route[m_step].y < gameObject().y() ? -m_speed : m_speed);
		gameObject().setY(newY);
	}
}
