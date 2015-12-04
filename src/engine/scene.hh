#pragma once

#include "event-handler.hh"
#include "object.hh"
#include <map>
#include <string>
#include <SFML/Graphics.hpp>

namespace E
{

    class Scene
    {
    public:
        Scene();

        EventHandler& event_handler_get();
        void object_add(std::string key, Object obj);
        Object& object_get(std::string key);
        void update(sf::RenderWindow& window);
        void draw(sf::RenderWindow& window) const;
    private:
        EventHandler event_handler_;
        std::map<std::string, Object> objects_;
    };

}
