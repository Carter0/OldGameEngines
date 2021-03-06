#include "PhysicsManager.hpp"
#include "GameObject.hpp"

PhysicsManager &
PhysicsManager::getInstance()
{
  static PhysicsManager * instance = new PhysicsManager();
  return *instance;
}

void
PhysicsManager::startUp()
{
  mWorld = new b2World(b2Vec2(0.0f, 0.0f));
}

void
PhysicsManager::shutDown()
{
  delete mWorld;
  mWorld = nullptr;
}

void
PhysicsManager::step()
{
  const float timeStep = 1.0f / 60.0f;
  const int velocityIterations = 6;
  const int positionIterations = 2;

  mWorld->Step(timeStep, velocityIterations, positionIterations);

  b2Contact * contact = mWorld->GetContactList();
  while (contact) {
    // Sometimes objects that are really close get included in the contacts,
    // so we add this methodjjj
    if (contact->IsTouching()){
      // B and A are the two objects colliding
      // need to cast from void* to gameobject
      GameObject * objA = static_cast<GameObject *>(contact->GetFixtureA()->GetBody()->GetUserData());
      GameObject * objB = static_cast<GameObject *>(contact->GetFixtureA()->GetBody()->GetUserData());

      // shared_from_this basically makes a shared pointer bec
      // ause collision takes it
      objA->collision(objB->shared_from_this());
      objB->collision(objA->shared_from_this());
    }
    contact = contact->GetNext();
  }
}


class QueryCallBackHelper: public b2QueryCallback {
public:
  QueryCallBackHelper(std::vector<std::shared_ptr<GameObject>> & objects):
    mObjects(objects)
  {
  }

  bool ReportFixture(b2Fixture* fixture)
  {
    GameObject * obj = static_cast<GameObject *>(fixture->GetBody()->GetUserData());
    mObjects.push_back(obj->shared_from_this());
    return true;
  }
private:
  std::vector<std::shared_ptr<GameObject>> & mObjects;

};
  
bool
PhysicsManager::getCollisions(float rx, float ry, float rw, float rh, std::vector<std::shared_ptr<GameObject>> & objects) const
{
  objects.clear();
  QueryCallBackHelper qcb(objects);

  // Represents an axis alligned bounding box.
  // Which is something that cannot rotate in respect to the world.
  b2AABB aabb;
  aabb.lowerBound = b2Vec2(rx * GAME_TO_PHYSICS_SCALE, ry * GAME_TO_PHYSICS_SCALE);
  aabb.upperBound = b2Vec2((rx + rw) * GAME_TO_PHYSICS_SCALE, (ry + rh) * GAME_TO_PHYSICS_SCALE);

  mWorld->QueryAABB(&qcb, aabb);

  return !objects.empty();
}
