#pragma once

#include "../../engine/game-object.hh"
#include "../../engine/scene.hh"
#include <SFML/Graphics.hpp>

namespace Objects
{
    class Background : public E::GameObject
    {
    public:
        Background(E::Scene& scene, sf::RenderWindow& window);
    };
}
