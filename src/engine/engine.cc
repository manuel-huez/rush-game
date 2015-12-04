#include "engine.hh"
#include "event-handler.hh"
#include "color.hh"
#include <string>
#include <SFML/Graphics.hpp>

namespace Engine
{
    Engine::Engine(int width, int height, std::string title)
        : width_{width}
        , height_{height}
        , window_{sf::RenderWindow(sf::VideoMode(width, height), title)}
        , event_handler_{EventHandler(*this)}
    {}

    sf::RenderWindow& window_get() const
    {
        return window_;
    }

    EventHandler& event_handler_get() const
    {
        return event_handler_;
    }

    void Engine::draw(sf::RenderWindow window) const
    {
        sf::CircleShape shape(100.f);
        shape.setFillColor(Color::Orange);
        window.draw(shape);
    }

    void Engine::run()
    {
        while (window_.isOpen())
        {
            event_handler_.handle();

            window_.clear();
            draw(window_);
            window_.display();
        }
    }
}
