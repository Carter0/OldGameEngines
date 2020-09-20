#ifndef BASE_LOAD_LEVEL_COMPONENT
#define BASE_LOAD_LEVEL_COMPONENT

#include "base/GenericComponent.hpp"
#include "TinyMath.hpp"
#include <vector>

//! \brief A component that loads another level on collision
class LoadLevel: public GenericComponent {
public:

    LoadLevel(GameObject & gameObject, int level, int tag);
    virtual void collision(Level & level, std::shared_ptr<GameObject> obj) override;

private:
    int m_level;
    int mTag;
};

#endif
