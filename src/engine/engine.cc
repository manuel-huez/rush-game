#include "engine.hh"
#include "color.hh"
#include <string>
#include <memory>
#include <SFML/Graphics.hpp>

namespace E
{
    Engine::Engine(const unsigned width, const unsigned height,
            sf::RenderWindow& window)
        : width_{width}
        , height_{height}
        , window_{window}
        , scene_{nullptr}
        , clock_{sf::Clock()}
    {}

    sf::RenderWindow& Engine::window_get() const
    {
        return window_;
    }

    void Engine::scene_set(std::shared_ptr<Scene> scene)
    {
        scene_ = scene;
    }

    Scene& Engine::scene_get()
    {
        return *scene_;
    }

    void Engine::run()
    {
        sf::Time dt = clock_.restart();

        scene_get().handle_events(*this, window_get(), dt);
        scene_get().update(*this, window_get(), dt);

        window_.clear();
        scene_get().draw(window_get());
        window_.display();
    }
}
