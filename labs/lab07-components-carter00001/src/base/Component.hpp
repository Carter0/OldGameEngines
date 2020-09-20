#ifndef BASE_COMPONENT
#define BASE_COMPONENT

class GameObject;

//! \brief Base class for all components. Keeps track of the game object.
class Component {
public:
  
  Component(GameObject & gameObject);
  virtual ~Component();
  
protected:

  inline GameObject & gameObject() { return mGameObject; }
  inline const GameObject & gameObject() const { return mGameObject; }
  
private:

  Component(const Component &) = delete;
  void operator=(Component const&) = delete;
  
  GameObject & mGameObject;

};

#endif
