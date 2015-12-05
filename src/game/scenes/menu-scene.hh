#pragma once

#include "../../engine/scene.hh"
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
        MenuScene(sf::RenderWindow& window);

        void handle_events(sf::RenderWindow& window, sf::Time& dt);
        void update(sf::RenderWindow& window, sf::Time& dt);
    private:
        CurrentMenuE cur_menu_;
    };

}
