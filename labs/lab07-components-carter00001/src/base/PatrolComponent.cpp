#include "base/PatrolComponent.hpp"
#include "base/GameObject.hpp"

PatrolComponent::PatrolComponent(GameObject & gameObject, float toX, float toY, float speed):
  GenericComponent(gameObject)
{
  mForward = true;
  mStep = 0;

  mDx = toX - gameObject.x();
  mDy = toY - gameObject.y();

  float len = sqrtf(mDx * mDx + mDy * mDy);

  mDx = mDx / len * speed;
  mDy = mDy / len * speed;

  mSteps = len / speed;
}

void
PatrolComponent::update(Level & level)
{
  gameObject().setX(gameObject().x() + mDx * (mForward ? 1 : -1));  
  gameObject().setY(gameObject().y() + mDy * (mForward ? 1 : -1));

  mStep ++;
  if (mStep > mSteps) {
    mStep = 0;
    mForward = !mForward;
  }
}
