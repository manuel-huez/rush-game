#pragma once

#include "../../engine/scene.hh"
#include <SFML/Graphics.hpp>

namespace Scenes
{

    class MenuScene : public E::Scene
    {
    public:
        MenuScene(sf::RenderWindow& window);

        void update(sf::RenderWindow& window, sf::Time& dt);
    };

}
