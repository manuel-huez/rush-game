#pragma once

#include "../../engine/scene.hh"
#include "../../engine/engine.hh"
#include <SFML/Graphics.hpp>

namespace Scenes
{

    enum CurrentMenuE {
        Play,
        Quit
    };

    class MenuScene : public E::Scene
    {
    public:
        MenuScene(E::Engine& engine, sf::RenderWindow& window);

        void handle_events(E::Engine& engine,
                sf::RenderWindow& window, sf::Time& dt);
        void update(E::Engine& engine,
                sf::RenderWindow& window, sf::Time& dt);
    private:
        CurrentMenuE cur_menu_;
    };

}
