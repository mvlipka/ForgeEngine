#include "Sprite.h"


Sprite::Sprite(sf::Texture *texture) : Renderable(0, 0) {
    Renderable(0, 0);
    this->sprite = new sf::Sprite(*texture);
}

void Sprite::Draw() {
    Renderable::Draw();
}
