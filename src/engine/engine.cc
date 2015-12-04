#include "engine.hh"
#include "event-handler.hh"
#include "color.hh"
#include <string>
#include <SFML/Graphics.hpp>

namespace E
{
    Engine::Engine(const unsigned width, const unsigned height,
            sf::RenderWindow& window)
        : width_{width}
        , height_{height}
        , window_{window}
        , scene_{Scene()}
    {
    }

    sf::RenderWindow& Engine::window_get() const
    {
        return window_;
    }

    void Engine::scene_set(Scene& scene)
    {
        scene_ = scene;
    }

    Scene& Engine::scene_get()
    {
        return scene_;
    }

    EventHandler& Engine::event_handler_get()
    {
        return scene_.event_handler_get();
    }

    void Engine::run()
    {
        while (window_.isOpen())
        {
            scene_get().update(window_get());

            window_.clear();
            scene_get().draw(window_get());
            window_.display();
        }
    }
}
