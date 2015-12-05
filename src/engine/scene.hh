#pragma once

#include "object.hh"
#include "engine.hh"
#include <map>
#include <string>
#include <SFML/Graphics.hpp>

namespace E
{

    class Engine;
    class Scene
    {
    public:
        Scene(Engine& engine, sf::RenderWindow& window);
        virtual ~Scene();

        void object_add(std::string key, Object obj);
        Object& object_get(std::string key);
        virtual void handle_events(Engine& engine,
                sf::RenderWindow& window, sf::Time& dt);
        virtual void update(Engine& engine,
                sf::RenderWindow& window, sf::Time& dt);
        virtual void draw(sf::RenderWindow& window) const;
    private:
        std::map<std::string, Object> objects_;
    };

}
