#pragma once

#include "../../engine/game-object.hh"
#include "../../engine/scene.hh"
#include <SFML/Graphics.hpp>

namespace Objects
{
    class Menu : public E::GameObject
    {
    public:
        Menu(E::Scene& scene, sf::RenderWindow& window);
    };
}
