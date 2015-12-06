#pragma once

#include "../../engine/scene.hh"
#include "../../engine/engine.hh"
#include <SFML/Graphics.hpp>

namespace Scenes
{

    enum CurrentRetryMenuE {
        Retry,
        RQuit
    };

    class RetryMenuScene : public E::Scene
    {
    public:
        RetryMenuScene(E::Engine& engine, sf::RenderWindow& window);

        void handle_events(E::Engine& engine,
                sf::RenderWindow& window, sf::Time& dt);
    private:
        CurrentRetryMenuE cur_menu_;
    };

}
