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
        , event_handler_{EventHandler()}
    {
    }

    sf::RenderWindow& Engine::window_get() const
    {
        return window_;
    }

    EventHandler& Engine::event_handler_get()
    {
        return event_handler_;
    }

    void Engine::draw() const
    {
        ::sf::CircleShape shape(100.f);
        shape.setFillColor(Color::Orange());
        window_get().draw(shape);
    }

    void Engine::run()
    {
        while (window_.isOpen())
        {
            event_handler_.handle(window_get());

            window_.clear();
            draw();
            window_.display();
        }
    }
}
