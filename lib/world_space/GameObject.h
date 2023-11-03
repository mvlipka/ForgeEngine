#ifndef FORGEENGINE_GAMEOBJECT_H
#define FORGEENGINE_GAMEOBJECT_H

class Vector2D;

class GameObject {
public:
    GameObject(float x, float y);

    ~GameObject();

    Vector2D *Position;

    void SetPosition(int x, int y);
};

#endif //FORGEENGINE_GAMEOBJECT_H
