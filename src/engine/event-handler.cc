#include "event-handler.hh"
#include "engine.hh"

namespace Engine
{
    EventHandler::EventHandler(Engine& engine)
        : engine_{engine}
    {}

    void EventHandler::handle()
    {
        sf::Event event;
        auto window = engine_.window_get();
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }
}
