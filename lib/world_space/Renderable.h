#ifndef FORGEENGINE_RENDERABLE_H
#define FORGEENGINE_RENDERABLE_H

#include "GameObject.h"

class Renderable : GameObject {
public:
    Renderable(float x, float y);
    virtual void Draw();
};


#endif //FORGEENGINE_RENDERABLE_H
