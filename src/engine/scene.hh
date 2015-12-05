#pragma once

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
        virtual ~Scene();

        void object_add(std::string key, Object obj);
        Object& object_get(std::string key);
        virtual void handle_events(sf::RenderWindow& window, sf::Time& dt);
        virtual void update(sf::RenderWindow& window, sf::Time& dt);
        virtual void draw(sf::RenderWindow& window) const;
    private:
        std::map<std::string, Object> objects_;
    };

}
