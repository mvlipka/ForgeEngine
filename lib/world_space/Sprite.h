#ifndef FORGEENGINE_SPRITE_H
#define FORGEENGINE_SPRITE_H


#include "GameObject.h"
#include "Renderable.h"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"



class Sprite : Renderable {
private:
    sf::Sprite *sprite;
public:
    explicit Sprite(sf::Texture *texture);

    void Draw() override;
};


#endif //FORGEENGINE_SPRITE_H
