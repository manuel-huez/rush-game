#pragma once

#include "scene.hh"
#include "object.hh"
#include <map>
#include <string>
#include <SFML/Graphics.hpp>

namespace E
{

    class Scene;
    class GameObject
    {
    public:
        GameObject(Scene& scene, sf::RenderWindow& window);
        GameObject();
        ~GameObject();

        void object_add(std::string key, Object obj);
        Object& object_get(std::string key);

        virtual void update(Scene& scene, sf::RenderWindow& window,
                sf::Time& dt);
        virtual void draw(sf::RenderWindow& window);
    private:
        std::map<std::string, Object> objects_;
    };

}
