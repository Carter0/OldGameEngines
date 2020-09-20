// Support Code written by Michael D. Shah
// Updated by Seth Cooper
// Last Updated: Spring 2020
// Please do not redistribute without asking permission.

#include "base/InputManager.hpp"
#include "base/GameObject.hpp"
#include "base/Level.hpp"
#include "base/GenericComponent.hpp"
#include "base/RemoveOnCollideComponent.hpp"
#include "base/RectRenderComponent.hpp"
#include "base/PhysicsComponent.hpp"
#include "base/PhysicsManager.hpp"
#include "base/SDLGraphicsProgram.hpp"
#include <memory>



static const int TAG_PLAYER = 1;
static const int TAG_GOAL   = 2;
static const int TAG_BLOCK  = 3;



class AdvInputComponent: public GenericComponent {
public:

  AdvInputComponent(GameObject & gameObject, float speed):
    GenericComponent(gameObject),
    mSpeed(speed)
  {
  }
  
  virtual void update(Level & level) override
  {
    GameObject & gameObject = getGameObject();
    std::shared_ptr<PhysicsComponent> pc = gameObject.physicsComponent();

    bool left = InputManager::getInstance().isKeyDown(SDLK_LEFT);
    bool right = InputManager::getInstance().isKeyDown(SDLK_RIGHT);
    bool up = InputManager::getInstance().isKeyDown(SDLK_UP);
    bool down = InputManager::getInstance().isKeyDown(SDLK_DOWN);

    if (left && !right) {
      pc->setVx(-mSpeed);
    } else if (!left && right) {
      pc->setVx(mSpeed);
    } else {
      pc->setVx(0.0f);
    }

    if (up && !down) {
      pc->setVy(-mSpeed);
    } else if (!up && down) {
      pc->setVy(mSpeed);
    } else {
      pc->setVy(0.0f);
    }
  }

private:

  float mSpeed;

};



const float SIZE = 40.0f;

class AdvPlayer: public GameObject {
public:
  AdvPlayer(Level & level, float x, float y):
    GameObject(level, x, y, SIZE, SIZE, TAG_PLAYER)
  {
    addGenericCompenent(std::make_shared<AdvInputComponent>(*this, 500.0f));
    addGenericCompenent(std::make_shared<RemoveOnCollideComponent>(*this, TAG_GOAL));
    setPhysicsCompenent(std::make_shared<PhysicsComponent>(*this, PhysicsComponent::Type::DYNAMIC_SOLID));
    setRenderCompenent(std::make_shared<RectRenderComponent>(*this, 0x00, 0xff, 0xaa));
  }
};

class AdvGoal: public GameObject {
public:
  AdvGoal(Level & level, float x, float y):
    GameObject(level, x, y, SIZE, SIZE, TAG_GOAL)
  {
    setPhysicsCompenent(std::make_shared<PhysicsComponent>(*this, PhysicsComponent::Type::STATIC_SENSOR));
    setRenderCompenent(std::make_shared<RectRenderComponent>(*this, 0xff, 0xff, 0x00));
  }
};

class AdvBlock: public GameObject {
public:
  AdvBlock(Level & level, float x, float y):
    GameObject(level, x, y, SIZE, SIZE, TAG_BLOCK)
  {
    setPhysicsCompenent(std::make_shared<PhysicsComponent>(*this, PhysicsComponent::Type::STATIC_SOLID));
    setRenderCompenent(std::make_shared<RectRenderComponent>(*this, 0x99, 0x99, 0x99));
  }
};



class AdvLevel: public Level {
public:
  AdvLevel():
    Level(20 * SIZE, 20 * SIZE)
  {
  }

  void initialize() override
  {
    addObject(std::make_shared<AdvPlayer>(*this, 2 * SIZE, 2 * SIZE));
    addObject(std::make_shared<AdvGoal>(*this, 18 * SIZE, 18 * SIZE));
    for (int ii = 0; ii < 10; ++ ii) {
      addObject(std::make_shared<AdvBlock>(*this, (14 - ii) * SIZE, (ii + 5) * SIZE));
    }
  }
};



int main(int argc, char** argv) {
  SDLGraphicsProgram mySDLGraphicsProgram(std::make_shared<AdvLevel>());

  mySDLGraphicsProgram.loop();

  return 0;
}
