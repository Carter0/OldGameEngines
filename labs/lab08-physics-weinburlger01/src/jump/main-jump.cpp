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



class JmpInputComponent: public GenericComponent {
public:

  JmpInputComponent(GameObject & gameObject, float speed, float jump, float gravity):
    GenericComponent(gameObject),
    mSpeed(speed),
    mJump(jump),
    mGravity(gravity)
  {
  }
  
  virtual void update(Level & level) override
  {
    bool left = InputManager::getInstance().isKeyDown(SDLK_LEFT);
    bool right = InputManager::getInstance().isKeyDown(SDLK_RIGHT);
    bool jump = InputManager::getInstance().isKeyPressed(SDLK_UP);
    
    GameObject & gameObject = getGameObject();
    std::shared_ptr<PhysicsComponent> pc = gameObject.physicsComponent();

    pc->addFy(mGravity);

    if (left && !right) {
      pc->setVx(-mSpeed);
    } else if (!left && right) {
      pc->setVx(mSpeed);
    } else {
      pc->setVx(0.0f);
    }

    if (jump) {
      bool onGround = false;

      std::vector<std::shared_ptr<GameObject>> objects;
      if (PhysicsManager::getInstance().getCollisions(gameObject.x() + 1, gameObject.y() + gameObject.h(), gameObject.w() - 2, 2.0f, objects)) {
	for (auto obj: objects) {
	  if (obj->tag() == TAG_BLOCK) {
	    onGround = true;
	  }
	}
      }

      if (onGround) {
	pc->setVy(-mJump);
      }
    }
  }

private:

  float mSpeed;
  float mJump;
  float mGravity;

};



const float SIZE = 40.0f;

class JmpPlayer: public GameObject {
public:
  JmpPlayer(Level & level, float x, float y):
    GameObject(level, x, y, SIZE, SIZE, TAG_PLAYER)
  {
    addGenericCompenent(std::make_shared<JmpInputComponent>(*this, 500.0f, 5000.0f, 50000.0f));
    addGenericCompenent(std::make_shared<RemoveOnCollideComponent>(*this, TAG_GOAL));
    setPhysicsCompenent(std::make_shared<PhysicsComponent>(*this, PhysicsComponent::Type::DYNAMIC_SOLID));
    setRenderCompenent(std::make_shared<RectRenderComponent>(*this, 0x00, 0xff, 0x00));
  }
};

class JmpGoal: public GameObject {
public:
  JmpGoal(Level & level, float x, float y):
    GameObject(level, x, y, SIZE, SIZE, TAG_GOAL)
  {
    setPhysicsCompenent(std::make_shared<PhysicsComponent>(*this, PhysicsComponent::Type::STATIC_SENSOR));
    setRenderCompenent(std::make_shared<RectRenderComponent>(*this, 0xff, 0x99, 0x00));
  }
};

class JmpBlock: public GameObject {
public:
  JmpBlock(Level & level, float x, float y):
    GameObject(level, x, y, SIZE, SIZE, TAG_BLOCK)
  {
    setPhysicsCompenent(std::make_shared<PhysicsComponent>(*this, PhysicsComponent::Type::STATIC_SOLID));
    setRenderCompenent(std::make_shared<RectRenderComponent>(*this, 0x99, 0x99, 0x99));
  }
};



class JmpLevel: public Level {
public:
  JmpLevel():
    Level(20 * SIZE, 20 * SIZE)
  {
  }

  void initialize() override
  {
    addObject(std::make_shared<JmpPlayer>(*this, 2 * SIZE, 15 * SIZE));
    addObject(std::make_shared<JmpGoal>(*this, 18 * SIZE, 2 * SIZE));
    for (int ii = 0; ii < 5; ++ ii) {
      addObject(std::make_shared<JmpBlock>(*this, (2 * ii + 5) * SIZE, (15 - 2 * ii) * SIZE));
    }
    for (int ii = 0; ii < 20; ++ ii) {
      addObject(std::make_shared<JmpBlock>(*this, ii * SIZE, 19 * SIZE));
    }
  }
};



int main(int argc, char** argv) {
  SDLGraphicsProgram mySDLGraphicsProgram(std::make_shared<JmpLevel>());

  mySDLGraphicsProgram.loop();

  return 0;
}
