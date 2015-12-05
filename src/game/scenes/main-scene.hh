#pragma once

#include "../../engine/scene.hh"
#include <SFML/Graphics.hpp>

namespace Scenes
{
    class MainScene : public E::Scene
    {
    public:
        MainScene(sf::RenderWindow& window);
        void update(sf::RenderWindow& window, sf::Time& dt);
    };
}
