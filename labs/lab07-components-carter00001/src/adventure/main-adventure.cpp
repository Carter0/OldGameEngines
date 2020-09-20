// Support Code written by Michael D. Shah
// Updated by Seth Cooper
// Last Updated: Spring 2020
// Please do not redistribute without asking permission.

#include "base/InputManager.hpp"
#include "base/GameObject.hpp"
#include "base/Level.hpp"
#include "base/GenericComponent.hpp"
#include "base/PatrolComponent.hpp"
#include "base/RemoveOnCollideComponent.hpp"
#include "base/RectRenderComponent.hpp"
#include "base/SDLGraphicsProgram.hpp"
#include <memory>



static const int TAG_PLAYER = 1;
static const int TAG_GOAL   = 2;
static const int TAG_BLOCK  = 3;
static const int TAG_ENEMY = 4;
// TODO: add tag for enemy


//! \brief Input controller for the adventure game.
class AdvInputComponent: public GenericComponent {
public:

  AdvInputComponent(GameObject & gameObject, float speed):
    GenericComponent(gameObject),
    mSpeed(speed)
  {
  }
  
  virtual void update(Level & level) override
  {
    bool left = InputManager::getInstance().isKeyDown(SDLK_LEFT);
    bool right = InputManager::getInstance().isKeyDown(SDLK_RIGHT);
    bool up = InputManager::getInstance().isKeyDown(SDLK_UP);
    bool down = InputManager::getInstance().isKeyDown(SDLK_DOWN);

    std::shared_ptr<PhysicsComponent> pc = gameObject().physicsComponent();
    
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

//! \brief Player controller for the adventure game.
class AdvPlayer: public GameObject {
public:
  AdvPlayer(float x, float y):
    GameObject(x, y, SIZE, SIZE, TAG_PLAYER)
  {
    addGenericCompenent(std::make_shared<AdvInputComponent>(*this, 10.0f));
    addGenericCompenent(std::make_shared<RemoveOnCollideComponent>(*this, TAG_GOAL));
    setPhysicsCompenent(std::make_shared<PhysicsComponent>(*this, false));
    setRenderCompenent(std::make_shared<RectRenderComponent>(*this, 0x00, 0xff, 0xaa));
  }
};

//! \brief Goal for the adventure game.
class AdvGoal: public GameObject {
public:
  AdvGoal(float x, float y):
    GameObject(x, y, SIZE, SIZE, TAG_GOAL)
  {
    addGenericCompenent(std::make_shared<PatrolComponent>(*this, x + SIZE, y, 4.0f));
    setPhysicsCompenent(std::make_shared<PhysicsComponent>(*this, false));
    setRenderCompenent(std::make_shared<RectRenderComponent>(*this, 0xff, 0xff, 0x00));
  }
};

//! \brief Block for the adventure game.
class AdvBlock: public GameObject {
public:
  AdvBlock(float x, float y):
    GameObject(x, y, SIZE, SIZE, TAG_BLOCK)
  {
    setPhysicsCompenent(std::make_shared<PhysicsComponent>(*this, true));
    setRenderCompenent(std::make_shared<RectRenderComponent>(*this, 0x99, 0x99, 0x99));
  }
};

//! \brief Enemy Object for the adventure game.
class AdvEnemy: public GameObject {
public:
  AdvEnemy(float x, float y):
    GameObject(x, y, SIZE, SIZE, TAG_ENEMY)
  {
    addGenericCompenent(std::make_shared<PatrolComponent>(*this, x + SIZE, y, 4.0f));
    setPhysicsCompenent(std::make_shared<PhysicsComponent>(*this, false));
    setRenderCompenent(std::make_shared<RectRenderComponent>(*this, 0xff, 0xdd, 0x00));
    addGenericCompenent(std::make_shared<RemoveOnCollideComponent>(*this, TAG_PLAYER));
  }
};



int main(int argc, char** argv) {
  std::shared_ptr<Level> level = std::make_shared<Level>(20 * SIZE, 20 * SIZE);

  level->addObject(std::make_shared<AdvPlayer>(2 * SIZE, 2 * SIZE));
  level->addObject(std::make_shared<AdvGoal>(18 * SIZE, 18 * SIZE));
  level->addObject(std::make_shared<AdvEnemy>(18 * SIZE, 10 * SIZE));


  for (int ii = 0; ii < 10; ++ ii) {
    level->addObject(std::make_shared<AdvBlock>((14 - ii) * SIZE, (ii + 5) * SIZE));
  }
  
  SDLGraphicsProgram mySDLGraphicsProgram(level);

  mySDLGraphicsProgram.loop();

  return 0;
}
