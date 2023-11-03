#include "GameObject.h"
#include "Vector2D.h"

GameObject::GameObject(float x, float y) {
    this->Position = new Vector2D(x, y);
}

GameObject::~GameObject() {
    delete this->Position;
}

void GameObject::SetPosition(int x, int y) {
    delete this->Position;
    this->Position = new Vector2D(x, y);
}

extern "C" {

__declspec(dllexport) void *gameobject_new(float x, float y) {
    return new GameObject(x, y);
}

__declspec(dllexport) void gameobject_destroy(void *gameObject) {
    if (gameObject == nullptr) {
        std::cerr << "Error calling destroy_gameobject gameObject null" << std::endl;
        return;
    }

    delete static_cast<GameObject *>(gameObject);
}

__declspec(dllexport) void gameobject_set_position(void *gameObject, int x, int y) {
    if (gameObject == nullptr) {
        std::cerr << "Error calling set_position_gameobject gameObject null" << std::endl;
        return;
    }

    static_cast<GameObject *>(gameObject)->SetPosition(x, y);
}

}