#pragma once

#include "engine.hh"
#include "game-object.hh"
#include <map>
#include <string>
#include <SFML/Graphics.hpp>

namespace E
{

    class Engine;
    class GameObject;
    class Scene
    {
    public:
        Scene(Engine& engine, sf::RenderWindow& window);
        virtual ~Scene();

        void gobject_add(std::string key, GameObject obj);
        GameObject& gobject_get(std::string key);
        virtual void handle_events(Engine& engine,
                sf::RenderWindow& window, sf::Time& dt);
        virtual void update(Engine& engine,
                sf::RenderWindow& window, sf::Time& dt);
        virtual void draw(sf::RenderWindow& window) const;
    private:
        std::map<std::string, GameObject> gobjects_;
    };

}
