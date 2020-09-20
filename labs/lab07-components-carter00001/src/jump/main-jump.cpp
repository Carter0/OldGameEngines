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


//! \brief Input controller for the jump game.
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
    
    std::shared_ptr<PhysicsComponent> pc = gameObject().physicsComponent();
    
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
      if (level.getCollisions(gameObject().x() + 0.0f * gameObject().w(), gameObject().y() + gameObject().h() + 2.0f, objects)) {
	for (auto obj: objects) {
	  if (obj->tag() == TAG_BLOCK) {
	    onGround = true;
	  }
	}
      }
      if (level.getCollisions(gameObject().x() + 1.0f * gameObject().w(), gameObject().y() + gameObject().h() + 2.0f, objects)) {
	for (auto obj: objects) {
	  if (obj->tag() == TAG_BLOCK) {
	    onGround = true;
	  }
	}
      }
      if (onGround) {
	pc->setVy(-mJump);
	return;
      }
    }
  
    pc->setVy(std::min(pc->vy() + mGravity, mJump));
  }

private:

  float mSpeed;
  float mJump;
  float mGravity;

};



const float SIZE = 40.0f;


//! \brief The Player for the jump game.
class JmpPlayer: public GameObject {
public:
  JmpPlayer(float x, float y):
    GameObject(x, y, SIZE, SIZE, TAG_PLAYER)
  {
    addGenericCompenent(std::make_shared<JmpInputComponent>(*this, 10.0f, 20.0f, 1.0f));
    addGenericCompenent(std::make_shared<RemoveOnCollideComponent>(*this, TAG_GOAL));
    setPhysicsCompenent(std::make_shared<PhysicsComponent>(*this, false));
    setRenderCompenent(std::make_shared<RectRenderComponent>(*this, 0x00, 0xff, 0x00));
  }
};

//! \brief The Goal for the jump game.
class JmpGoal: public GameObject {
public:
  JmpGoal(float x, float y):
    GameObject(x, y, SIZE, SIZE, TAG_GOAL)
  {
    addGenericCompenent(std::make_shared<PatrolComponent>(*this, x + SIZE, y, 4.0f));
    setPhysicsCompenent(std::make_shared<PhysicsComponent>(*this, false));
    setRenderCompenent(std::make_shared<RectRenderComponent>(*this, 0xff, 0x99, 0x00));
  }
};

//! \brief The blocks that the player can jump on. 
class JmpBlock: public GameObject {
public:
  JmpBlock(float x, float y):
    GameObject(x, y, SIZE, SIZE, TAG_BLOCK)
  {
    setPhysicsCompenent(std::make_shared<PhysicsComponent>(*this, true));
    setRenderCompenent(std::make_shared<RectRenderComponent>(*this, 0x99, 0x99, 0x99));
  }
};

//! \brief Enemy Object for the jump game.
class JmpEnemy: public GameObject {
public:
  JmpEnemy(float x, float y):
    GameObject(x, y, SIZE, SIZE, TAG_ENEMY)
  {
    setPhysicsCompenent(std::make_shared<PhysicsComponent>(*this, false));
    setRenderCompenent(std::make_shared<RectRenderComponent>(*this, 0xff, 0xff, 0x00));
    addGenericCompenent(std::make_shared<RemoveOnCollideComponent>(*this, TAG_PLAYER));
    addGenericCompenent(std::make_shared<PatrolComponent>(*this, x + SIZE, y, 2.0f));
  }
};


int main(int argc, char** argv) {
  std::shared_ptr<Level> level = std::make_shared<Level>(20 * SIZE, 20 * SIZE);

  level->addObject(std::make_shared<JmpPlayer>(2 * SIZE, 16 * SIZE));
  level->addObject(std::make_shared<JmpGoal>(18 * SIZE, 2 * SIZE));
  level->addObject(std::make_shared<JmpEnemy>(18 * SIZE, 18 * SIZE));

  for (int ii = 0; ii < 5; ++ ii) {
    level->addObject(std::make_shared<JmpBlock>((2 * ii + 5) * SIZE, (15 - 2 * ii) * SIZE));
  }
  for (int ii = 0; ii < 20; ++ ii) {
    level->addObject(std::make_shared<JmpBlock>(ii * SIZE, 19 * SIZE));
  }
  
  SDLGraphicsProgram mySDLGraphicsProgram(level);

  mySDLGraphicsProgram.loop();

  return 0;
}
