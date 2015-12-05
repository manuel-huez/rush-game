#pragma once

#include "../../engine/scene.hh"
#include "../../engine/engine.hh"
#include <SFML/Graphics.hpp>

namespace Scenes
{
    class MainScene : public E::Scene
    {
    public:
        MainScene(E::Engine& engine, sf::RenderWindow& window);
        void update(E::Engine& engine,
                sf::RenderWindow& window, sf::Time& dt);
    };
}
