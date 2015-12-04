#include "event-handler.hh"
#include <SFML/Graphics.hpp>

namespace E
{
    void EventHandler::handle(sf::RenderWindow& window)
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }
}
