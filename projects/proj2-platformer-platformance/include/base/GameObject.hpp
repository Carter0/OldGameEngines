#ifndef BASE_GAME_OBJECT
#define BASE_GAME_OBJECT

#include "base/GenericComponent.hpp"
#include "base/PhysicsComponent.hpp"
#include "base/RenderComponent.hpp"
#include "TinyMath.hpp"
#include <SDL.h>
#include <memory>
#include <vector>

class Level;

//! \brief Represents an object in the game.  Has some essential
//! properties (position and size), a tag (identifying the general
//! category of object), and a collection of components, including any
//! number of generic components and optionally a physics component
//! and a render component.
class GameObject {
public:

  GameObject(float x, float y, float w, float h, int tag);

  virtual ~GameObject() = 0;

  /**
   * @return the tag type of the GameObject
   */
  inline int tag() const { return mTag; }
    
  /**
   * Sets the x value of the GameObject
   */
  inline void setX(float x) { mX = x; }

  /**
   * Sets the y value of the GameObject
   */
  inline void setY(float y) { mY = y; }

  /**
   * Sets the height value of the GameObject
   */
  inline void setW(float w) { mW = w; }

  /**
   * Sets the width value of the GameObject
   */
  inline void setH(float h) { mH = h; }

  /**
   * @return the x coordnate of the top-left of the gameobject
   */
  inline float x() const { return mX; }

  /**
   * @return the y coordnate of the top-left of the gameobject
   */
  inline float y() const { return mY; }

  /**
   * @return the width of the top-left of the gameobject
   */
  inline float w() const { return mW; }

  /**
    * @return the height of the top-left of the gameobject
    */
  inline float h() const { return mH; }

  /**
   * @return A 2D vector with the current camera offset
   */
  inline static Vector2D getCameraOffset() { return m_cameraOffset; }

  /**
   * Sets the camera offset of all gameobjects
   * @param offset the Camera Offset
   */
  inline static void setCameraOffset(Vector2D offset) { m_cameraOffset = offset; }


  inline void addGenericCompenent(std::shared_ptr<GenericComponent> comp) { mGenericComponents.push_back(comp); }
  inline void setPhysicsCompenent(std::shared_ptr<PhysicsComponent> comp) { mPhysicsComponent = comp; }
  inline void setRenderCompenent(std::shared_ptr<RenderComponent> comp) { mRenderComponent = comp; }
  
  inline std::vector<std::shared_ptr<GenericComponent>> genericComponents() { return mGenericComponents; }
  inline std::shared_ptr<PhysicsComponent> physicsComponent() { return mPhysicsComponent; }
  inline std::shared_ptr<PhysicsComponent> physicsComponent() const { return mPhysicsComponent; }
  inline std::shared_ptr<RenderComponent> renderComponent() { return mRenderComponent; }
  
  void update(Level & level); //!< Update the object.
  void collision(Level & level, std::shared_ptr<GameObject> obj); //!< Handle collisions with another object.
  void step(Level & level); //!< Do the physics step for the object.
  void render(SDL_Renderer * renderer); //!< Render the object.
  
  bool isColliding(const GameObject & obj) const; //!< Determine if this object is colliding with another.
  bool isColliding(float px, float py) const; //!< Determine if this object is colliding with a point.

  virtual std::string typeCheck() { return "GameObject"; };
  virtual std::ostream& print(std::ostream &out) { return out; };//!< A virtual function that will be overridden by all the GameObject-children.

private:

  GameObject(const GameObject &) = delete;
  void operator=(GameObject const&) = delete;

  float mX, mY, mW, mH;
  int mTag;
  
  std::vector<std::shared_ptr<GenericComponent>> mGenericComponents;
  std::shared_ptr<PhysicsComponent> mPhysicsComponent;
  std::shared_ptr<RenderComponent> mRenderComponent;

  static Vector2D m_cameraOffset;

};

#endif
