#pragma once
#ifndef BASE_LOSE_LIFE_COMPONENT
#define BASE_LOSE_LIFE_COMPONENT

#include "base/GenericComponent.hpp"

//! \brief A component that loses a life from the player on collision
class LoseLifeComponent: public GenericComponent {
public:

    LoseLifeComponent(GameObject & gameObject, int tag);
    virtual void collision(Level & level, std::shared_ptr<GameObject> obj) override;

private:
    int mTag;
};

#endif
